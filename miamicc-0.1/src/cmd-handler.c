
#include <stdio.h>
#include "ccutil.h"
#include <string.h>
#include "interfacecodes.h"
#include "api_linfunctions.h"

extern BYTE abyCommandPacket[], abyResponsePacket[];

bool initCommandTable( void )
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_initCommandTable;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_initCommandTable;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool enableCommandHandler( void )
{
    abyCommandPacket[PAL_BYTE] = DDAPI_PAL_enableCommandHandler;
    abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_enableCommandHandler;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool disableCommandHandler( void )
{
    abyCommandPacket[PAL_BYTE] = DDAPI_PAL_disableCommandHandler;
    abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_disableCommandHandler;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool addCommandTableEntry(struct command * commandEntry)
{
 	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_addCommandTableEntry;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_addCommandTableEntry;
    abyCommandPacket[2] = (BYTE)(commandEntry->commandID & 0xff);
    abyCommandPacket[3] =(BYTE)(commandEntry->param & 0xff);
    abyCommandPacket[4] = (BYTE)(commandEntry->msRepeatTime & 0xff);
    abyCommandPacket[5] = (BYTE)(commandEntry->msRepeatTime >>8);
    abyCommandPacket[6] = (BYTE)commandEntry->checkReturnValue;
    abyCommandPacket[7] = (BYTE)commandEntry->toggleMode;
    abyCommandPacket[8] = (BYTE)commandEntry->comparisonType;
    abyCommandPacket[9] =(BYTE)(commandEntry->value1 & 0xff);
    abyCommandPacket[10] = (BYTE)(commandEntry->value1 >> 8);
    abyCommandPacket[11] = (BYTE)(commandEntry->value2 & 0xff);
    abyCommandPacket[12] = (BYTE)(commandEntry->value2 >> 8);

//    fprintf(stdout, "packet = %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\r\n",
//        abyCommandPacket[0], abyCommandPacket[1], abyCommandPacket[2], abyCommandPacket[3], 
//        abyCommandPacket[4], abyCommandPacket[5], abyCommandPacket[6], abyCommandPacket[7], 
//        abyCommandPacket[8], abyCommandPacket[9], abyCommandPacket[10], abyCommandPacket[11], 
//        abyCommandPacket[12] );

    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

