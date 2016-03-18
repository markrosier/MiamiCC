#include <stdio.h>
#include <string.h>
#ifndef WIN32
#include <unistd.h>
#include <termios.h>
#include <semaphore.h>
#include <signal.h>
#include <linux/serial.h>
#else
#include "comport.h"
#endif
#include "ccutil.h"
#include "general.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "interfacecodes.h"


#ifndef WIN32
static sem_t *sem;
#endif


//#define DEBUG_PACKET 1


volatile int STOP=false;

BYTE abyCommandPacket[MAX_EXTENDED_PACKET_SIZE], abyResponsePacket[MAX_EXTENDED_PACKET_SIZE];

ErrorCode errorCode = NoError;

#ifndef WIN32
int fd;
#else
HANDLE fd;
#endif

#ifndef WIN32
struct termios oldtio,newtio;
static char * semName;
int iWaitTime=-1;

/* Driver-specific ioctls: */
#define TIOCMBIS	0x5416
#define TIOCMBIC	0x5417
#define TIOCM_DTR	0x002
#define TIOCM_RTS	0x004
#define TIOCMGET	0x5415
#define TIOCMSET	0x5418

#endif



ErrorCode getLastError( void )
{
    return errorCode;
}

void setLastError( ErrorCode e )
{
    errorCode = e;
}

void printError( char * str )
{
    switch (errorCode)
    {
        case NoError:
            fprintf(stderr, "No Error:%s", str);
            break;
        case ErrNAK:
            fprintf(stderr, "Nak Error:%s", str);
            break;
        default:
            fprintf(stderr, "Unknown Error:%s", str);
            break;
    }
}

BYTE GetChecksum(BYTE *TransmitBuff, BYTE Range)
{
    BYTE Index;
    BYTE Summation = 0;
    //BYTE Range = TransmitBuff[PAL_BYTE] & 0xF; we can't use the first Byte as sometime the "official" length is longer
	for (Index = 0; Index < Range; Index ++)
	{
		Summation += ~( TransmitBuff[Index] ) + 1;
	}
	return (Summation);
}

void printPacket( BYTE *transmitBuff )
{
    BYTE Index;
    BYTE Range = (transmitBuff[PAL_BYTE] & 0x0F);
    fprintf(stderr,"length = %d\n",Range);
	for (Index = 0; Index <= Range; Index ++)
	{
		fprintf(stderr," 0x%02X",transmitBuff[Index]);
	}
    fprintf(stderr,"\n");
}

bool isAck(BYTE * abyResponsePacket)
{
    if(abyResponsePacket[PAL_BYTE]==PTCM_PAL_ACK
        && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_ACK)
    {
        return true;
    }
    return false;
}

bool isNak(BYTE * abyResponsePacket)
{
    if(abyResponsePacket[PAL_BYTE]==PTCM_PAL_NAK
        && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_NAK)
    {
        return true;
    }
    return false;
}

bool openPort(char * deviceName, char * baudRate)
{
#ifndef WIN32
	struct termios newtio;

     fd = open(deviceName, O_RDWR | O_NOCTTY); //| O_NDELAY);

  if (fd == -1)
    {
        fprintf(stderr, "openPort: Unable to open \"%s\".\n",deviceName);
        return false;
    }

	tcgetattr(fd,&oldtio);
    bzero(&newtio, sizeof(newtio));
	if (strncmp(baudRate, "19200", 4)==0)
	{
		cfsetispeed(&newtio, B19200); //input speed
		cfsetospeed(&newtio, B19200); //output speed
	}
	else
	{
		cfsetispeed(&newtio, B115200); //input speed
		cfsetospeed(&newtio, B115200); //output speed
	}
    newtio.c_cflag |= (CLOCAL | CREAD);
    newtio.c_cflag &= ~PARENB; //no parity
    newtio.c_cflag &= ~CSTOPB; //1bitstop
    newtio.c_cflag &= ~CSIZE; /* Mask the character size bits */
    newtio.c_cflag |= CS8;    /* Select 8 data bits */

    newtio.c_cc[VTIME]    = 10;   //mr was 10
    newtio.c_cc[VMIN]     = 0;

    newtio.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); //raw mode


    tcsetattr(fd,TCSANOW,&newtio);

    tcflush(fd, TCOFLUSH);
    tcflush(fd, TCIFLUSH);
#else
	{
		char tempDeviceName[13];
		strcpy(tempDeviceName, "\\\\.\\");
		strcat(tempDeviceName, deviceName);
		if (strncmp(baudRate, "19200", 4)==0)
		{
			fd = comOpen(tempDeviceName, 19200, 'N', 8, 1, 'N');
		}
		else
		{
			fd = comOpen(tempDeviceName, 115200, 'N', 8, 1, 'N');
		}
		if (fd == INVALID_HANDLE_VALUE )
		return false;
	}
#endif
    return true;
}

void closePort()
{
#ifndef WIN32
 //   sem_close(sem);
//    sem_unlink(semName);
    if (fd == -1)
    {
        tcsetattr(fd,TCSANOW,&oldtio);
        close(fd);
    }
#else
	CloseHandle(fd);
#endif
}


bool sendPacket(BYTE * pbyCommandPacket)
{

    size_t nbytes, bytes_write;
    BYTE Index, length;

    nbytes = sizeof(BYTE);
    if((pbyCommandPacket[PAL_BYTE] & 0xF0)==PTCM_PACKET_ID || ((pbyCommandPacket[PAL_BYTE] & 0xF0)==DDAPI_PACKET_ID))
    {
        length = (pbyCommandPacket[PAL_BYTE] & 0x0f);
		if (length == 0)
		{
			//Extended Packet
			length = pbyCommandPacket[EXTENDED_PACKET_LENGTH_BYTE];
		}
        pbyCommandPacket[length]=GetChecksum(pbyCommandPacket,length);
 #ifdef DEBUG_PACKET
        fprintf(stderr, "Sending packet: ");
        printPacket(pbyCommandPacket);
#endif
#ifndef WIN32
// Control the RTS Line for RS485
	int controlbits;

	if (iWaitTime != 0)
	{
		// Set the RTS line High
		ioctl(fd, TIOCMGET, &controlbits);
		controlbits|=TIOCM_RTS;
		ioctl(fd, TIOCMSET, &controlbits);
	}

#endif


        for ( Index = 0; Index <= length; Index ++)
        {
	#ifndef WIN32
           	bytes_write = write(fd, &pbyCommandPacket[Index], nbytes);
	#else
		bytes_write = comSend(fd, &pbyCommandPacket[Index], nbytes);
	#endif
		if(bytes_write != nbytes)
		{
			errorCode = DeviceNotWriteable;
			fprintf(stderr,"\nproblem with writing to serial port");
			return false;
		}
        }
	#ifndef WIN32
 	if (iWaitTime != 0)
	{
		if (iWaitTime== -1)
			tcdrain(fd);
		else
			usleep(iWaitTime);
		// rtslow
		ioctl(fd, TIOCMGET, &controlbits);
		controlbits&=~TIOCM_RTS;
		ioctl(fd, TIOCMSET, &controlbits);
	}
	#endif
   }
    else
    {
        printPacket(pbyCommandPacket);
        fprintf(stderr, "wrong packet header\n");
        errorCode = WrongSendPacket;
        return false;
    }
    return true;
}

bool receivePacket(BYTE * pbyResponsePacket)
{
    int res;
    BYTE receivebyte;

    int i=0;
    int expectedLength;
#ifndef WIN32
    expectedLength=-1;
	while ((res = read(fd, &receivebyte,1)) != -1)
    {
        if (res != 1)
        {
#else
    unsigned long   rdB;
    expectedLength=-1;
	while ((res = ReadFile(fd, &receivebyte, 1, &rdB, NULL)))
    {
        if (rdB != 1)
        {
#endif
//            fprintf (stderr, "timeout\n");
            errorCode = TimeOut;
            return false;
        }
#ifdef DEBUG_PACKET
        fprintf(stderr, "%d -> 0x%02X\n",i,receivebyte);
#endif
        if(expectedLength==-1)
        {

            if((receivebyte & 0xF0) == PTCM_PACKET_ID )
            {
                expectedLength = (((int)receivebyte) & 0x0F);
                if(expectedLength >= 2 && expectedLength <= MAX_PTCM_PACKET_SIZE)
                {
                    pbyResponsePacket[PAL_BYTE] = receivebyte;
                    i=1;
                }
                else if ( expectedLength == 0) // Extended Packet
				{
                    pbyResponsePacket[PAL_BYTE] = receivebyte;
                    i=1;
					expectedLength = 2;
				}
				else
				{
	                fprintf(stderr, "Invalid Short Packet Length = %02d\n",receivebyte);
	                expectedLength = -1;

				}
			}
            else
            {
#ifdef DEBUG_PACKET
                fprintf(stderr, "discard byte 0x%02X\n",receivebyte);
#endif
                expectedLength = -1;
            }
        }
        else
        {
            if(i <= expectedLength)
            {
				if (i == 2  && ((pbyResponsePacket[PAL_BYTE] & 0xF) == 0)) // Extended Packet
				{
					expectedLength = receivebyte;
#ifdef DEBUG_PACKET
	                fprintf(stderr, "Extended Packet Length = %d\n ",receivebyte);
#endif
				}

                pbyResponsePacket[i] = receivebyte;
                if ( i == expectedLength )
                {
                    BYTE cs = GetChecksum(pbyResponsePacket,expectedLength);
                    if (cs == receivebyte)
                    {
                        return true;
                    }
                    else
                    {
                        errorCode = WrongChecksum;
                        return false;
                    }
                }
                i++;
            }
        }
    }
    return true;
}


bool sendMessage(BYTE * pbyCommandPacket, BYTE * pbyResponsePacket )
{
    int try = 3;

    // Clear the error flag
    errorCode = NoError;
#ifndef WIN32
    if (fd == -1)
#else
	if (fd == INVALID_HANDLE_VALUE)
#endif
    {
        errorCode = DeviceNotOpen;
//        fprintf(stderr, "Device not open");
        return false;
    }

    while (try>0)
    {
        //reset the error code
        errorCode = NoError;

        if (sendPacket(pbyCommandPacket))
        {
            if (receivePacket(pbyResponsePacket))
            {
                return true;
            }
			else
			{
				try --;
			}
        }
        else
            break;
    }
    fprintf (stderr, "timeout\n");
	return false;
}

char deviceName[255];

char * getDevice( char * baudRate)
{
#ifndef WIN32
    int iPort=1;
    while (iPort<4)
    {
        sprintf(deviceName,"/dev/ttymxc%d",iPort);
        if (openPort(deviceName, baudRate) == true)
        {
//            if (checkPNPString()==true)
            {
                closePort();
                return deviceName;
            }
        }
        closePort();
        iPort++;
    }
#endif
    iPort=0;
    while (iPort<100)
    {
#ifndef WIN32
		sprintf(deviceName,"/dev/ttyS%d",iPort);
#else
		sprintf(deviceName,"COM%d",iPort);
#endif
 		printf("Trying to open %s\n", deviceName);
        if ( openPort(deviceName, baudRate))
       {
//            if (checkPNPString()==true)
            {
                closePort( );
                return deviceName;
            }
        }
        closePort( );
        iPort++;
    }
#ifndef WIN32
    iPort=0;
    while (iPort<20)
    {
		sprintf(deviceName,"/dev/ttyUSB%d",iPort);
        if (openPort(deviceName, baudRate) == true)
        {
//            if (checkPNPString()==true)
            {
                closePort();
                return deviceName;
            }
        }
        closePort();
        iPort++;
    }
#endif
	return NULL;
}



/*******************************************************************************
 *                           END OF FILE                                       *
 *******************************************************************************/

