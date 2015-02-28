#include "ccutil.h"
#include <malloc.h>
#include <stdio.h>


extern BYTE abyCommandPacket[], abyResponsePacket[];



bool getCodeVersion( int * majorReleaseNo, int * minorReleaseNo )
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getCodeVersion;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_getCodeVersion;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
		if (abyResponsePacket[PAL_BYTE] == PTCM_PAL_getCodeVersion
			&& abyResponsePacket[OPCODE_BYTE] == PTCM_RETCODE_getCodeVersion)
        {
            *majorReleaseNo = (int)abyResponsePacket[2];
            *minorReleaseNo = (int)abyResponsePacket[3];
            return true;
        }
    }
    return false;
}

