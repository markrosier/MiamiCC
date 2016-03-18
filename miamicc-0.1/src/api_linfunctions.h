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
    
// Common Structures    
    
struct command {
    int  commandID;
    int  param;
    unsigned  msRepeatTime;
    bool checkReturnValue;
    BYTE toggleMode;
    BYTE comparisonType;
    int  value1;
    int  value2;
// internal variables
    unsigned msTimeLeft;
    unsigned msToggleTimeLeft;
    BYTE currentToggleValue;
    struct command * nextCommand;
};    

bool getLINProductID( BYTE NAD, BYTE * returnString );
bool getLINProductSN( BYTE NAD, BYTE * returnString );
bool assignFrameIDRange( BYTE * inputString );
bool assignNAD( BYTE * inputString );
bool conditionalChangeNAD( BYTE * inputString );
bool dataDump( BYTE * inputData, BYTE * outputData );
bool saveConfiguration ( BYTE NodeAddress );
bool setSpaceHeaterEnable( BYTE spaceHeaterEnable );
bool setSpaceHeaterMode ( BYTE spaceHeaterMode );
bool getSpaceHeaterBurnerStatus ( BYTE * spaceHeaterStatus);
bool getSpaceHeaterErrorStatus ( BYTE * spaceHeaterErrorStatus);
bool setSpaceHeaterPowerLED ( BYTE spaceHeaterPowerLED );
bool getSpaceHeaterErrorCode ( BYTE * spaceHeaterErrorCode);
bool clearSpaceHeaterError ( void );
bool setWaterHeaterEnable( BYTE waterHeaterEnable );
bool setWaterHeaterMode ( BYTE spaceHeaterPowerLED );
bool getWaterHeaterBurnerStatus ( BYTE * waterHeaterBurnerStatus);
bool getWaterHeaterErrorStatus( BYTE * waterHeaterErrorStatus);
bool setWaterHeaterPowerLED ( BYTE spaceHeaterPowerLED );
bool getWaterHeaterErrorCode ( BYTE * waterHeaterErrorCode);
bool clearWaterHeaterError ( void );
bool setLIN100PDUEnable( BYTE LIN100PDUEnable );
bool setPDUPowerSource ( BYTE PDUPowerSource );
bool getIgnitionSignal ( BYTE * ignitionSignal);
bool get230VPresentSignal ( BYTE * _230VPresentSignal );
bool getLeisureBatteryVoltage ( BYTE * leisureBatteryVoltage );
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
bool setHexnode1Enable( BYTE hexnode1Enable );
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
bool setHexnode2Enable( BYTE hexnode2Enable );
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
bool setHexnode3Enable( BYTE hexnode3Enable );
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
bool setHexnode4Enable( BYTE hexnode4Enable );
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
bool setLIN50PDUEnable( BYTE LIN50PDUEnable );
bool setLIN50PDUPowerSource ( BYTE powerSource);
bool setLIN50PDUMaster ( BYTE master);
bool setLIN50PDULights ( BYTE lights);
bool setLIN50PDUAwning ( BYTE awning);
bool setLIN50PDUPumpMode ( BYTE pumpMode);
bool getLIN50PDULoadCurrent ( unsigned * current);
bool getLIN50PDUSolarCurrent ( unsigned * current);
bool getLIN50PDULeisureBatteryCurrent ( unsigned * current);
bool getLIN50PDUVehicleBatteryCurrent ( unsigned * current);
bool getLIN50PDUMainsCurrent ( unsigned * current);
bool getLIN50PDUFuseState ( unsigned * fuseState);
bool getLIN50PDUOutputOverloadState (BYTE * overloadState);
bool getLIN50PDULeisureBatteryVoltage ( unsigned * voltage);
bool getLIN50PDUVehicleBatteryVoltage ( unsigned * voltage);
bool getLIN50PDUWaterLevel ( unsigned * waterLevel);
bool getLIN50PDUWasteLevel ( unsigned * wasteLevel);
bool getLIN50PDUInternalTemperature ( BYTE * temperature);
bool getLIN50PDUExternalTemperature ( BYTE * temperature);
bool getLIN50PDUMainsSignal ( BYTE * mainsSignal);
bool getLIN50PDUIgnitionSignal ( BYTE * ignitionSignal);
bool getLIN50PDUPumpFeedback ( BYTE * pumpFeedback);
bool initCommandTable( void );
bool addCommandTableEntry( struct command * commandEntry );
bool enableCommandHandler( void );
bool disableCommandHandler( void );


#ifdef	__cplusplus
}
#endif

#endif	/* API_LINFUNCTIONS_H */

