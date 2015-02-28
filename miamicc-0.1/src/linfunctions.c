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

bool setHexnode1Output1(BYTE outputValue)
{
	return true;
}

bool setHexnode1Output2(BYTE outputValue)
{
	return true;
}

bool setHexnode1Output3(BYTE outputValue)
{
	return true;
}

bool setHexnode1Output4(BYTE outputValue)
{
	return true;
}

bool setHexnode1Output5(BYTE outputValue)
{
	return true;
}

bool setHexnode1Output6(BYTE outputValue)
{
	return true;
}

bool getHexnode1OutputOverloadStatus(BYTE * overloadStatus)
{
	return true;
}

bool getHexnode1Input1(BYTE * inputValue)
{
	return true;
}

bool getHexnode1Input2(BYTE * inputValue)
{
	return true;
}

bool getHexnode1Input3(BYTE * inputValue)
{
	return true;
}

bool getHexnode1Input4(BYTE * inputValue)
{
	return true;
}

bool getHexnode1ADCInput5(unsigned * inputValue)
{
	return true;
}

bool getHexnode1ADCInput6(unsigned * inputValue)
{
	return true;
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
