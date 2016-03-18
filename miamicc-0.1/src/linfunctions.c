#include "ccutil.h"
#include <string.h>
#include "interfacecodes.h"
#include "api_linfunctions.h"

extern BYTE abyCommandPacket[], abyResponsePacket[];

bool getLINProductID(BYTE NAD, BYTE * returnString)
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_getLINProductID;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_getLINProductID;
	abyCommandPacket[2] = NAD;
	if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
	{
		if (abyResponsePacket[PAL_BYTE] == PTCM_PAL_getLINProductID
			&& abyResponsePacket[OPCODE_BYTE] == PTCM_RETCODE_getLINProductID)
		{
			memcpy(returnString, &abyResponsePacket[2], getLINProductID_PACKET_LENGTH - 2);
			return true;
		}
	}
	return false;
}

bool getLINProductSN( BYTE NAD, BYTE * returnString)
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_getLINProductSN;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_getLINProductSN;
	abyCommandPacket[2] = NAD;
	if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
	{
		if (abyResponsePacket[PAL_BYTE] == PTCM_PAL_getLINProductSN
			&& abyResponsePacket[OPCODE_BYTE] == PTCM_RETCODE_getLINProductSN)
		{
			memcpy(returnString, &abyResponsePacket[2], getLINProductSN_PACKET_LENGTH - 2);
			return true;
		}
	}
	return false;
}

bool assignFrameIDRange(BYTE * inputString)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_assignFrameIDRange;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_assignFrameIDRange;
    memcpy ( & abyCommandPacket[2], inputString, 6 );
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool assignNAD(BYTE * inputString)
{
	return true;
}

bool conditionalChangeNAD(BYTE * inputString)
{
	return true;
}

bool dataDump(BYTE * inputData, BYTE * outputData)
{
	return true;
}

bool saveConfiguration(BYTE NodeAddress)
{
	return true;
}

bool setSpaceHeaterMode(BYTE spaceHeaterMode)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setSpaceHeaterMode;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setSpaceHeaterMode;
    abyCommandPacket[2]=(BYTE)spaceHeaterMode;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getSpaceHeaterBurnerStatus(BYTE * spaceHeaterBurnerStatus)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getSpaceHeaterBurnerStatus;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getSpaceHeaterBurnerStatus;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getSpaceHeaterBurnerStatus 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getSpaceHeaterBurnerStatus )
        {
            *spaceHeaterBurnerStatus = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getSpaceHeaterErrorCode(BYTE * spaceHeaterErrorCode)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getSpaceHeaterErrorCode;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getSpaceHeaterErrorCode;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getSpaceHeaterErrorCode 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getSpaceHeaterErrorCode )
        {
            *spaceHeaterErrorCode = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool setSpaceHeaterPowerLED(BYTE spaceHeaterPowerLED)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setSpaceHeaterPowerLED;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setSpaceHeaterPowerLED;
    abyCommandPacket[2]=(BYTE)spaceHeaterPowerLED;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setSpaceHeaterEnable(BYTE inputValue)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setSpaceHeaterEnable;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setSpaceHeaterEnable;
    abyCommandPacket[2]=(BYTE)inputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool clearSpaceHeaterError( void )
{
    abyCommandPacket[PAL_BYTE] = DDAPI_PAL_clearSpaceHeaterError;
    abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_clearSpaceHeaterError;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setWaterHeaterMode(BYTE waterHeaterMode)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setWaterHeaterMode;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setWaterHeaterMode;
    abyCommandPacket[2]=(BYTE)waterHeaterMode;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getWaterHeaterBurnerStatus(BYTE * waterHeaterBurnerStatus)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getWaterHeaterBurnerStatus;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getWaterHeaterBurnerStatus;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getWaterHeaterBurnerStatus 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getWaterHeaterBurnerStatus )
        {
            *waterHeaterBurnerStatus = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getWaterHeaterErrorCode(BYTE * waterHeaterErrorCode)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getWaterHeaterErrorCode;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getWaterHeaterErrorCode;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getWaterHeaterErrorCode 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getWaterHeaterErrorCode )
        {
            *waterHeaterErrorCode = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool setWaterHeaterPowerLED(BYTE waterHeaterPowerLED)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setWaterHeaterPowerLED;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setWaterHeaterPowerLED;
    abyCommandPacket[2]=(BYTE)waterHeaterPowerLED;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setWaterHeaterEnable(BYTE inputValue)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setWaterHeaterEnable;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setWaterHeaterEnable;
    abyCommandPacket[2]=(BYTE)inputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool clearWaterHeaterError( void )
{
    abyCommandPacket[PAL_BYTE] = DDAPI_PAL_clearWaterHeaterError;
    abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_clearWaterHeaterError;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}


bool setLIN100PDUEnable(BYTE inputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setLIN100PDUEnable;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setLIN100PDUEnable;
    abyCommandPacket[2]=(BYTE)inputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setPDUPowerSource(BYTE PDUPowerSource)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setPDUPowerSource;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setPDUPowerSource;
    abyCommandPacket[2]=(BYTE)PDUPowerSource;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getIgnitionSignal(BYTE * ignitionSignal)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getIgnitionSignal;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getIgnitionSignal;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getIgnitionSignal 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getIgnitionSignal )
        {
            *ignitionSignal = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool get230VPresentSignal(BYTE * _230VPresentSignal)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_get230VPresentSignal;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_get230VPresentSignal;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_get230VPresentSignal 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_get230VPresentSignal )
        {
            *_230VPresentSignal = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getLeisureBatteryVoltage(BYTE * leisureBatteryVoltage)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLeisureBatteryVoltage;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLeisureBatteryVoltage;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLeisureBatteryVoltage 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLeisureBatteryVoltage )
        {
            *leisureBatteryVoltage = (BYTE) abyResponsePacket[2] ;
            return true;
        }
    }
    return false;
}

bool getVehicleBatteryVoltage(unsigned * vehicleBatteryVoltage)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getVehicleBatteryVoltage;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getVehicleBatteryVoltage;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getVehicleBatteryVoltage 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getVehicleBatteryVoltage )
        {
            *vehicleBatteryVoltage = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLoadCurrent(unsigned * loadCurrent)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLoadCurrent;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLoadCurrent;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLoadCurrent 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLoadCurrent )
        {
            *loadCurrent = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool setFridgetoSystemRelay(BYTE fridgetoSystemRelay)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setFridgetoSystemRelay;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setFridgetoSystemRelay;
    abyCommandPacket[2]=(BYTE)fridgetoSystemRelay;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setOutput1(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setOutput1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setOutput1;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setOutput2(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setOutput2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setOutput2;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setOutput3(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setOutput3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setOutput3;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getOutputOverloadState(BYTE * overloadStatus)
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_getHexnode1OutputOverloadStatus;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_getHexnode1OutputOverloadStatus;
	if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
	{
		if (abyResponsePacket[PAL_BYTE] == PTCM_PAL_getHexnode1OutputOverloadStatus
			&& abyResponsePacket[OPCODE_BYTE] == PTCM_RETCODE_getHexnode1OutputOverloadStatus)
		{
			*overloadStatus = (BYTE) abyResponsePacket[2] ;
			return true;
		}
	}
	return false;
}

bool getPositiveInput1(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getPositiveInput1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getPositiveInput1;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getPositiveInput1
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getPositiveInput1 )
        {
            *inputValue = (BYTE) abyResponsePacket[2] ;
            return true;
        }
    }
    return false;
}

bool getPositiveInput2(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getPositiveInput2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getPositiveInput2;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getPositiveInput2
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getPositiveInput2 )
        {
            *inputValue = (BYTE) abyResponsePacket[2] ;
            return true;
        }
    }
    return false;
}

bool getNegativeInput1(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getNegativeInput1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getNegativeInput1;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getNegativeInput1 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getNegativeInput1 )
        {
            *inputValue = (BYTE) abyResponsePacket[2] ;
            return true;
        }
    }
    return false;
}

bool getADCInput1(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getADCInput1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getADCInput1;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getADCInput1 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getADCInput1 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getADCInput2(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getADCInput2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getADCInput2;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getADCInput2 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getADCInput2 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool setHexnode1Enable(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode1Enable;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode1Enable;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode1Output1(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode1Output1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode1Output1;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode1Output2(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode1Output2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode1Output2;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode1Output3(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode1Output3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode1Output3;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode1Output4(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode1Output4;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode1Output4;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode1Output5(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode1Output5;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode1Output5;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode1Output6(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode1Output6;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode1Output6;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getHexnode1OutputOverloadStatus(BYTE * overloadStatus)
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_getHexnode1OutputOverloadStatus;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_getHexnode1OutputOverloadStatus;
	if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
	{
		if (abyResponsePacket[PAL_BYTE] == PTCM_PAL_getHexnode1OutputOverloadStatus
			&& abyResponsePacket[OPCODE_BYTE] == PTCM_RETCODE_getHexnode1OutputOverloadStatus)
		{
			*overloadStatus = (BYTE) abyResponsePacket[2] ;
		}
	}
	return false;
}

bool getHexnode1Input1(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode1Input1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode1Input1;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode1Input1 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode1Input1 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode1Input2(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode1Input2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode1Input2;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode1Input2 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode1Input2 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode1Input3(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode1Input3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode1Input3;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode1Input3 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode1Input3 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode1Input4(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode1Input4;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode1Input4;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode1Input4 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode1Input4 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode1ADCInput5(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode1ADCInput5;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode1ADCInput5;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode1ADCInput5 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode1ADCInput5 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getHexnode1ADCInput6(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode1ADCInput6;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode1ADCInput6;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode1ADCInput6 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode1ADCInput6 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool setHexnode2Enable(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode2Enable;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode2Enable;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode2Output1(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode2Output1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode2Output1;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode2Output2(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode2Output2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode2Output2;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode2Output3(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode2Output3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode2Output3;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode2Output4(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode2Output4;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode2Output4;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode2Output5(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode2Output5;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode2Output5;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode2Output6(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode2Output6;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode2Output6;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getHexnode2OutputOverloadStatus(BYTE * overloadStatus)
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_getHexnode2OutputOverloadStatus;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_getHexnode2OutputOverloadStatus;
	if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
	{
		if (abyResponsePacket[PAL_BYTE] == PTCM_PAL_getHexnode2OutputOverloadStatus
			&& abyResponsePacket[OPCODE_BYTE] == PTCM_RETCODE_getHexnode2OutputOverloadStatus)
		{
			*overloadStatus = (BYTE) abyResponsePacket[2] ;
		}
	}
	return false;
}

bool getHexnode2Input1(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode2Input1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode2Input1;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode2Input1 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode2Input1 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode2Input2(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode2Input2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode2Input2;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode2Input2 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode2Input2 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode2Input3(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode2Input3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode2Input3;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode2Input3 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode2Input3 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode2Input4(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode2Input4;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode2Input4;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode2Input4 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode2Input4 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode2ADCInput5(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode2ADCInput5;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode2ADCInput5;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode2ADCInput5 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode2ADCInput5 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getHexnode2ADCInput6(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode2ADCInput6;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode2ADCInput6;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode2ADCInput6 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode2ADCInput6 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool setHexnode3Enable(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode3Enable;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode3Enable;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode3Output1(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode3Output1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode3Output1;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode3Output2(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode3Output2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode3Output2;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode3Output3(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode3Output3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode3Output3;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode3Output4(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode3Output4;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode3Output4;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode3Output5(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode3Output5;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode3Output5;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode3Output6(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode3Output6;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode3Output6;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getHexnode3OutputOverloadStatus(BYTE * overloadStatus)
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_getHexnode3OutputOverloadStatus;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_getHexnode3OutputOverloadStatus;
	if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
	{
		if (abyResponsePacket[PAL_BYTE] == PTCM_PAL_getHexnode3OutputOverloadStatus
			&& abyResponsePacket[OPCODE_BYTE] == PTCM_RETCODE_getHexnode3OutputOverloadStatus)
		{
			*overloadStatus = (BYTE) abyResponsePacket[2] ;
		}
	}
	return false;
}

bool getHexnode3Input1(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode3Input1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode3Input1;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode3Input1 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode3Input1 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode3Input2(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode3Input2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode3Input2;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode3Input2 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode3Input2 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode3Input3(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode3Input3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode3Input3;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode3Input3 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode3Input3 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode3Input4(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode3Input4;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode3Input4;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode3Input4 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode3Input4 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode3ADCInput5(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode3ADCInput5;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode3ADCInput5;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode3ADCInput5 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode3ADCInput5 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getHexnode3ADCInput6(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode3ADCInput6;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode3ADCInput6;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode3ADCInput6 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode3ADCInput6 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool setHexnode4Enable(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode4Enable;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode4Enable;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode4Output1(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode4Output1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode4Output1;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode4Output2(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode4Output2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode4Output2;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode4Output3(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode4Output3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode4Output3;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode4Output4(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode4Output4;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode4Output4;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode4Output5(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode4Output5;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode4Output5;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setHexnode4Output6(BYTE outputValue)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setHexnode4Output6;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setHexnode4Output6;
    abyCommandPacket[2]=(BYTE)outputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getHexnode4OutputOverloadStatus(BYTE * overloadStatus)
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_getHexnode4OutputOverloadStatus;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_getHexnode4OutputOverloadStatus;
	if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
	{
		if (abyResponsePacket[PAL_BYTE] == PTCM_PAL_getHexnode4OutputOverloadStatus
			&& abyResponsePacket[OPCODE_BYTE] == PTCM_RETCODE_getHexnode4OutputOverloadStatus)
		{
			*overloadStatus = (BYTE) abyResponsePacket[2] ;
		}
	}
	return false;
}

bool getHexnode4Input1(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode4Input1;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode4Input1;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode4Input1 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode4Input1 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode4Input2(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode4Input2;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode4Input2;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode4Input2 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode4Input2 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode4Input3(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode4Input3;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode4Input3;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode4Input3 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode4Input3 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode4Input4(BYTE * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode4Input4;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode4Input4;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode4Input4 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode4Input4 )
        {
            *inputValue = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getHexnode4ADCInput5(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode4ADCInput5;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode4ADCInput5;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode4ADCInput5 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode4ADCInput5 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getHexnode4ADCInput6(unsigned * inputValue)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getHexnode4ADCInput6;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getHexnode4ADCInput6;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getHexnode4ADCInput6 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getHexnode4ADCInput6 )
        {
            *inputValue = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool setLIN50PDUEnable(BYTE inputValue)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setLIN50PDUEnable;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setLIN50PDUEnable;
    abyCommandPacket[2]=(BYTE)inputValue;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setLIN50PDUPowerSource(BYTE PDUPowerSource)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setLIN50PDUPowerSource;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setLIN50PDUPowerSource;
    abyCommandPacket[2]=(BYTE)PDUPowerSource;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setLIN50PDUMaster(BYTE masterState)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setLIN50PDUMaster;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setLIN50PDUMaster;
    abyCommandPacket[2]=(BYTE)masterState;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setLIN50PDULights(BYTE lightsState)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setLIN50PDULights;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setLIN50PDULights;
    abyCommandPacket[2]=(BYTE)lightsState;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setLIN50PDUAwning(BYTE awningLightsState)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setLIN50PDUAwning;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setLIN50PDUAwning;
    abyCommandPacket[2]=(BYTE)awningLightsState;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool setLIN50PDUPumpMode(BYTE pumpMode)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_setLIN50PDUPumpMode;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_setLIN50PDUPumpMode;
    abyCommandPacket[2]=(BYTE) pumpMode;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool getLIN50PDULoadCurrent(unsigned * loadCurrent)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDULoadCurrent;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDULoadCurrent;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDULoadCurrent 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDULoadCurrent )
        {
            *loadCurrent = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUSolarCurrent(unsigned * current)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUSolarCurrent;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUSolarCurrent;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUSolarCurrent 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUSolarCurrent )
        {
            *current = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDULeisureBatteryCurrent(unsigned * current)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDULeisureBatteryCurrent;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDULeisureBatteryCurrent;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDULeisureBatteryCurrent 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDULeisureBatteryCurrent )
        {
            *current = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUVehicleBatteryCurrent(unsigned * current)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUVehicleBatteryCurrent;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUVehicleBatteryCurrent;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUVehicleBatteryCurrent 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUVehicleBatteryCurrent )
        {
            *current = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUMainsCurrent(unsigned * current)
{
   abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUMainsCurrent;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUMainsCurrent;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUMainsCurrent 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUMainsCurrent )
        {
            *current = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUFuseState(unsigned * fuseState)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUFuseState;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUFuseState;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUFuseState 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUFuseState )
        {
            *fuseState = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUOutputOverloadState(BYTE * overloadStatus)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUOutputOverloadState;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUOutputOverloadState;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUOutputOverloadState 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUOutputOverloadState )
        {
            *overloadStatus = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getLIN50PDULeisureBatteryVoltage(unsigned * voltage)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDULeisureBatteryVoltage;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDULeisureBatteryVoltage;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDULeisureBatteryVoltage 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDULeisureBatteryVoltage )
        {
            *voltage = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUVehicleBatteryVoltage(unsigned * voltage)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUVehicleBatteryVoltage;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUVehicleBatteryVoltage;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUVehicleBatteryVoltage 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUVehicleBatteryVoltage )
        {
            *voltage = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUWaterLevel(unsigned * level)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUWaterLevel;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUWaterLevel;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUWaterLevel 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUWaterLevel )
        {
            *level = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUWasteLevel(unsigned * level)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUWasteLevel;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUWasteLevel;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUWasteLevel 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUWasteLevel )
        {
            *level = TWOBYTESTOINT(abyResponsePacket[3], abyResponsePacket[2]) ;
            return true;
        }
    }
    return false;
}

bool getLIN50PDUInternalTemperature(BYTE * temperature)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUInternalTemperature;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUInternalTemperature;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUInternalTemperature 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUInternalTemperature )
        {
            *temperature = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getLIN50PDUExternalTemperature(BYTE * temperature)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUExternalTemperature;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUExternalTemperature;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUExternalTemperature 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUExternalTemperature )
        {
            *temperature = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getLIN50PDUMainsSignal(BYTE * signalState)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUMainsSignal;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUMainsSignal;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUMainsSignal 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUMainsSignal )
        {
            *signalState = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getLIN50PDUIgnitionSignal(BYTE * signalState)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUIgnitionSignal;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUIgnitionSignal;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUIgnitionSignal 
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUIgnitionSignal )
        {
            *signalState = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool getLIN50PDUPumpFeedback(BYTE * pumpState)
{
    abyCommandPacket[PAL_BYTE]=DDAPI_PAL_getLIN50PDUPumpFeedback;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_getLIN50PDUPumpFeedback;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        if (abyResponsePacket[PAL_BYTE]==PTCM_PAL_getLIN50PDUPumpFeedback
            && abyResponsePacket[OPCODE_BYTE]==PTCM_RETCODE_getLIN50PDUPumpFeedback)
        {
            *pumpState = (BYTE)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

