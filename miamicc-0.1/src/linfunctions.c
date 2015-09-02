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
	return true;
}

bool getSpaceHeaterBurnerStatus(BYTE * spaceHeaterBurnerStatus)
{

	return true;
}

bool getSpaceHeaterErrorStatus(BYTE * spaceHeaterBurnerStatus)
{

	return true;
}

bool setSpaceHeaterPowerLED(BYTE spaceHeaterPowerLED)
{
	return true;
}

bool setWaterHeaterMode(BYTE spaceHeaterPowerLED)
{
	return true;
}

bool getWaterHeaterBurnerStatus(BYTE * waterHeaterBurnerStatus)
{

	return true;
}

bool getWaterHeaterErrorStatus(BYTE * waterHeaterBurnerStatus)
{

	return true;
}

bool setWaterHeaterPowerLED(BYTE spaceHeaterPowerLED)
{
	return true;
}

bool setPDUPowerSource(BYTE PDUPowerSource)
{
	return true;
}

bool getIgnitionSignal(BYTE * ignitionSignal)
{

	return true;
}

bool get230VPresentSignal(BYTE * _230VPresentSignal)
{

	return true;
}

bool getLeisureBatteryVoltage(unsigned * leisureBatteryVoltage)
{

	return true;
}

bool getVehicleBatteryVoltage(unsigned * vehicleBatteryVoltage)
{
	return true;
}

bool getLoadCurrent(unsigned * loadCurrent)
{
	return true;
}

bool setFridgetoSystemRelay(BYTE fridgetoSystemRelay)
{
	return true;
}

bool setOutput1(BYTE outputValue)
{
	return true;
}

bool setOutput2(BYTE outputValue)
{
	return true;
}

bool setOutput3(BYTE outputValue)
{
	return true;
}

bool getOutputOverloadState(BYTE * overloadStatus)
{
	return true;
}

bool getPositiveInput1(BYTE * inputValue)
{
	return true;
}

bool getPositiveInput2(BYTE * inputValue)
{
	return true;
}

bool getNegativeInput1(BYTE * inputValue)
{
	return true;
}

bool getADCInput1(unsigned * inputValue)
{
	return true;
}

bool getADCInput2(unsigned * inputValue)
{
	return true;
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
			memcpy(overloadStatus, &abyResponsePacket[2], getHexnode1OutputOverloadStatus_PACKET_LENGTH - 2);
			return true;
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
            *inputValue = (int)abyResponsePacket[2];
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
            *inputValue = (int)abyResponsePacket[2];
            return true;
        }
    }
    return false;
}

bool setHexnode2Output1(BYTE outputValue)
{
	return true;
}

bool setHexnode2Output2(BYTE outputValue)
{
	return true;
}

bool setHexnode2Output3(BYTE outputValue)
{
	return true;
}

bool setHexnode2Output4(BYTE outputValue)
{
	return true;
}

bool setHexnode2Output5(BYTE outputValue)
{
	return true;
}

bool setHexnode2Output6(BYTE outputValue)
{
	return true;
}

bool getHexnode2OutputOverloadStatus(BYTE * overloadStatus)
{
	return true;
}

bool getHexnode2Input1(BYTE * inputValue)
{
	return true;
}

bool getHexnode2Input2(BYTE * inputValue)
{
	return true;
}

bool getHexnode2Input3(BYTE * inputValue)
{
	return true;
}

bool getHexnode2Input4(BYTE * inputValue)
{
	return true;
}

bool getHexnode2ADCInput5(unsigned * inputValue)
{
	return true;
}

bool getHexnode2ADCInput6(unsigned * inputValue)
{
	return true;
}

bool setHexnode3Output1(BYTE outputValue)
{
	return true;
}

bool setHexnode3Output2(BYTE outputValue)
{
	return true;
}

bool setHexnode3Output3(BYTE outputValue)
{
	return true;
}

bool setHexnode3Output4(BYTE outputValue)
{
	return true;
}

bool setHexnode3Output5(BYTE outputValue)
{
	return true;
}

bool setHexnode3Output6(BYTE outputValue)
{
	return true;
}

bool getHexnode3OutputOverloadStatus(BYTE * overloadStatus)
{
	return true;
}

bool getHexnode3Input1(BYTE * inputValue)
{
	return true;
}

bool getHexnode3Input2(BYTE * inputValue)
{
	return true;
}

bool getHexnode3Input3(BYTE * inputValue)
{
	return true;
}

bool getHexnode3Input4(BYTE * inputValue)
{
	return true;
}

bool getHexnode3ADCInput5(unsigned * inputValue)
{
	return true;
}

bool getHexnode3ADCInput6(unsigned * inputValue)
{
	return true;
}

bool setHexnode4Output1(BYTE outputValue)
{
	return true;
}

bool setHexnode4Output2(BYTE outputValue)
{
	return true;
}

bool setHexnode4Output3(BYTE outputValue)
{
	return true;
}

bool setHexnode4Output4(BYTE outputValue)
{
	return true;
}

bool setHexnode4Output5(BYTE outputValue)
{
	return true;
}

bool setHexnode4Output6(BYTE outputValue)
{
	return true;
}

bool getHexnode4OutputOverloadStatus(BYTE * overloadStatus)
{
	return true;
}

bool getHexnode4Input1(BYTE * inputValue)
{
	return true;
}

bool getHexnode4Input2(BYTE * inputValue)
{
	return true;
}

bool getHexnode4Input3(BYTE * inputValue)
{
	return true;
}

bool getHexnode4Input4(BYTE * inputValue)
{
	return true;
}

bool getHexnode4ADCInput5(unsigned * inputValue)
{
	return true;
}

bool getHexnode4ADCInput6(unsigned * inputValue)
{
	return true;
}
