/* 
 * File:   api_linfunctions.h
 * Author: mark rosier Iota Electronics
 *
 * Created on 11 December 2014, 16:22
 */

#ifndef API_LINFUNCTIONS_H
#define	API_LINFUNCTIONS_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include "system.h"

bool getLINProductID( BYTE NAD, BYTE * returnString );
bool getLINProductSN( BYTE NAD, BYTE * returnString );
bool assignFrameIDRange( BYTE * inputString );
bool assignNAD( BYTE * inputString );
bool conditionalChangeNAD( BYTE * inputString );
bool dataDump( BYTE * inputData, BYTE * outputData );
bool saveConfiguration ( BYTE NodeAddress );
bool setSpaceHeaterMode ( BYTE spaceHeaterMode );
bool getSpaceHeaterBurnerStatus ( BYTE * spaceHeaterBurnerStatus);
bool getSpaceHeaterErrorStatus ( BYTE * spaceHeaterBurnerStatus);
bool setSpaceHeaterPowerLED ( BYTE spaceHeaterPowerLED );
bool setWaterHeaterMode ( BYTE spaceHeaterPowerLED );
bool getWaterHeaterBurnerStatus ( BYTE * waterHeaterBurnerStatus);
bool getWaterHeaterErrorStatus( BYTE * waterHeaterBurnerStatus);
bool setWaterHeaterPowerLED ( BYTE spaceHeaterPowerLED );
bool setPDUPowerSource ( BYTE PDUPowerSource );
bool getIgnitionSignal ( BYTE * ignitionSignal);
bool get230VPresentSignal ( BYTE * _230VPresentSignal );
bool getLeisureBatteryVoltage ( unsigned * leisureBatteryVoltage );
bool getVehicleBatteryVoltage ( unsigned * vehicleBatteryVoltage );
bool getLoadCurrent ( unsigned * loadCurrent );
bool setFridgetoSystemRelay ( BYTE fridgetoSystemRelay );
bool setOutput1 ( BYTE outputValue );
bool setOutput2 ( BYTE outputValue );
bool setOutput3 ( BYTE outputValue );
bool getOutputOverloadState ( BYTE * overloadStatus );
bool getPositiveInput1 ( BYTE * inputValue);
bool getPositiveInput2 ( BYTE * inputValue);
bool getNegativeInput1 ( BYTE * inputValue);
bool getADCInput1 ( unsigned * inputValue);
bool getADCInput2 ( unsigned * inputValue);
bool setHexnode1Output1 ( BYTE outputValue );
bool setHexnode1Output2 ( BYTE outputValue );
bool setHexnode1Output3 ( BYTE outputValue );
bool setHexnode1Output4 ( BYTE outputValue );
bool setHexnode1Output5 ( BYTE outputValue );
bool setHexnode1Output6 ( BYTE outputValue );
bool getHexnode1OutputOverloadStatus ( BYTE * overloadStatus );
bool getHexnode1Input1 ( BYTE * inputValue);
bool getHexnode1Input2 ( BYTE * inputValue);
bool getHexnode1Input3 ( BYTE * inputValue);
bool getHexnode1Input4 ( BYTE * inputValue);
bool getHexnode1ADCInput5 ( unsigned * inputValue);
bool getHexnode1ADCInput6 ( unsigned * inputValue);
bool setHexnode2Output1 ( BYTE outputValue );
bool setHexnode2Output2 ( BYTE outputValue );
bool setHexnode2Output3 ( BYTE outputValue );
bool setHexnode2Output4 ( BYTE outputValue );
bool setHexnode2Output5 ( BYTE outputValue );
bool setHexnode2Output6 ( BYTE outputValue );
bool getHexnode2OutputOverloadStatus ( BYTE * overloadStatus );
bool getHexnode2Input1 ( BYTE * inputValue);
bool getHexnode2Input2 ( BYTE * inputValue);
bool getHexnode2Input3 ( BYTE * inputValue);
bool getHexnode2Input4 ( BYTE * inputValue);
bool getHexnode2ADCInput5 ( unsigned * inputValue);
bool getHexnode2ADCInput6 ( unsigned * inputValue);
bool setHexnode3Output1 ( BYTE outputValue );
bool setHexnode3Output2 ( BYTE outputValue );
bool setHexnode3Output3 ( BYTE outputValue );
bool setHexnode3Output4 ( BYTE outputValue );
bool setHexnode3Output5 ( BYTE outputValue );
bool setHexnode3Output6 ( BYTE outputValue );
bool getHexnode3OutputOverloadStatus ( BYTE * overloadStatus );
bool getHexnode3Input1 ( BYTE * inputValue);
bool getHexnode3Input2 ( BYTE * inputValue);
bool getHexnode3Input3 ( BYTE * inputValue);
bool getHexnode3Input4 ( BYTE * inputValue);
bool getHexnode3ADCInput5 ( unsigned * inputValue);
bool getHexnode3ADCInput6 ( unsigned * inputValue);
bool setHexnode4Output1 ( BYTE outputValue );
bool setHexnode4Output2 ( BYTE outputValue );
bool setHexnode4Output3 ( BYTE outputValue );
bool setHexnode4Output4 ( BYTE outputValue );
bool setHexnode4Output5 ( BYTE outputValue );
bool setHexnode4Output6 ( BYTE outputValue );
bool getHexnode4OutputOverloadStatus ( BYTE * overloadStatus );
bool getHexnode4Input1 ( BYTE * inputValue);
bool getHexnode4Input2 ( BYTE * inputValue);
bool getHexnode4Input3 ( BYTE * inputValue);
bool getHexnode4Input4 ( BYTE * inputValue);
bool getHexnode4ADCInput5 ( unsigned * inputValue);
bool getHexnode4ADCInput6 ( unsigned * inputValue);




#ifdef	__cplusplus
}
#endif

#endif	/* API_LINFUNCTIONS_H */

