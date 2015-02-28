#ifndef inc_ccutil_api
#define inc_ccutil_api



#ifndef WIN32
#define DLLDDAPI
typedef unsigned int WORD;
typedef unsigned char BYTE;
typedef BYTE BOOL;
#define BYTEFAR BYTE
#define WORDFAR WORD
#define INTFAR int
#else
#include <windows.h>
#endif

typedef BYTE bool;

#define true 1
#define false 0


/*
#define TRUE 1
#define FALSE 0
*/

#define NO_OF_RETRYS 0

#define TWOBYTESTOINT(a,b) (int)((((int)a) <<8) + ((int)b));

#include "interfacecodes.h"
#include "general.h"
#include "version.h"
#include "api_linfunctions.h"


typedef enum 
{
    NoError,            /**< No error detected                                                                     */
    DeviceNotOpen,      /**< The device is not opened                                                              */
    DeviceNotWriteable, /**< The device is not writable                                                            */
    WrongSendPacket,    /**< The packet sent had a wrong header code                                               */
    TimeOut,            /**< Will waiting for an reply from the Display Watch board, the timeout have been reached */
    WrongChecksum,      /**< The packet received from the Display Watch board had a wrong checksum                 */   
    ErrNAK              /**< The Display watch board reply with an NAK message                                     */
} ErrorCode;

/**
 * get the last code error
 * \return 
 *   code error
 */
ErrorCode getLastError( void );

/**
 * open the serial port
 * \param deviceName to be open such as "/dev/ttyS0"
 * \return \ref false if the device can not be open
 */

/**
 * open the serial port
 * \param deviceName to be open such as "/dev/ttyS0"
 *    or "COM1" in windows
 * \return \ref false if the device can not be open
 */
bool openPort( char * deviceName, char * baudRate );

/**
 * close the serial port previously open with \ref openPort
 */
void closePort( void );

bool sendMessage(BYTE * pbyCommandPacket, BYTE * pbyResponsePacket );
bool isAck(BYTE * abyResponsePacket);
bool isNak(BYTE * abyResponsePacket);
char * getDevice(char * baudRate);

#endif
