#include <stdio.h>
#include "ccutil.h"
#include <string.h>
#include <stdlib.h>
#ifndef WIN32
#include <unistd.h>
#include <signal.h>
#endif
#include <time.h>

static int returnValue = 0;
#ifndef WIN32
/**** SIGNAL HANDLER ****/
void sigfunc()
{
    printf("ctrl-c detected!!!");
    returnValue = -1;
}
/**** END ****/
#endif

typedef bool(*boolFunctionVoid)(void);
typedef bool(*boolFunctionInt)(int);
typedef bool(*boolFunctionByte)(BYTE);
typedef bool(*boolFunctionPByte)(BYTE *);
typedef bool(*boolFunctionWord)(WORD);
typedef bool(*boolFunctionPInt)(int *);
typedef bool(*boolFunctionPIntPInt)(int *, int *);
typedef bool(*boolFunctionIntPInt)(int, int *);
typedef bool(*boolFunctionPWord)(WORD *);
typedef bool(*boolFunctionPStringInt)(char *, int);
typedef bool(*boolFunctionPStringPInt)(char *, int *);
typedef bool(*boolFunctionPCmdEntry)(struct command *);

enum {
    boolFunctionVoidType,
    boolFunctionIntType,
    boolFunctionByteType,
    boolFunctionPByteType,
    boolFunctionWordType,
    boolFunctionPIntType,
    boolFunctionPIntPIntType,
    boolFunctionIntPIntType,
    boolFunctionPWordType,
	boolFunctionPStringIntType,
	boolFunctionPStringPIntType,
	getLINProductIDType,
	getLINProductSNType,
	assignFrameIDRangeType,
    overloadStatusType,
    boolFunctionPCmdEntryType};

typedef struct translation_s
{
    char *functionName;
    char *options[12];
} translation_t;

static translation_t translationList[] =
        {
 			{NULL, {NULL}}
        };

char * translate(char * functionName, int index)
{
    void * result = NULL;
    int i = 0;
    while (result == NULL)
    {
		if (translationList[i].functionName == NULL)
            break;
        else if (strcmp(functionName, translationList[i].functionName)==0)
		{
            result = translationList[i].options[index];
		}
        i++;
    }
    return result;
}

typedef struct dwSet_s
{
    char *functionName;
    void *functionPointer;
    int type;
    char *functionDescription;
    const char *textual;
    char *usage;
} dwSet_t;

static dwSet_t functionList[] =
        {
			{ "getCodeVersion", &getCodeVersion, boolFunctionPIntPIntType, "Get the code version.", "Code Version", "" },
			{ "getLINProductID", &getLINProductID, getLINProductIDType, "Get the LIN Product ID", "Lin Product ID", "  Usage: --getLINProductID=<nodeAddress>, range 0-63" },
			{ "getLINProductSN", &getLINProductSN, getLINProductSNType, "Get the LIN Product SN", "Lin Product SN", "  Usage: --getLINProductSN=<nodeAddress>, range 0-63" },
			{ "assignFrameIDRange", &assignFrameIDRange, assignFrameIDRangeType, "assign Frame ID Range", "Frame ID Range", "  Usage: --assignFrameIDRange= XX XX XX XX XX XX" },
            { "setSpaceHeaterEnable", &setSpaceHeaterEnable, boolFunctionByteType, "Enable Space Heater", NULL, "Usage: --setSpaceHeaterEnable=1 to enable =0 to disable"},
            { "setSpaceHeaterMode", &setSpaceHeaterMode, boolFunctionByteType, "set SpaceHeater Mode", NULL, "Usage: --setSpaceHeaterMode=X range 0-8"},
            { "getSpaceHeaterBurnerStatus", &getSpaceHeaterBurnerStatus, boolFunctionPByteType, "Get State of Space Heater Burner", "Space Heater Burner Status", ""},
            { "getSpaceHeaterErrorCode", &getSpaceHeaterErrorCode, boolFunctionPByteType, "Get Error State of Space Heater Burner", "Space Heater Error Code", ""},
            { "setSpaceHeaterPowerLED", &setSpaceHeaterPowerLED, boolFunctionByteType, "set SpaceHeater Power LED", NULL, "Usage: --setSpaceHeaterPowerLED=X, 1=ON 0=OFF"},
            { "clearSpaceHeaterError", &clearSpaceHeaterError, boolFunctionVoidType, "Clear Space Heater error", NULL, "Usage: --clearSpaceHeaterError"},
            { "setWaterHeaterEnable", &setWaterHeaterEnable, boolFunctionByteType, "Enable Water Heater", NULL, "Usage: --setWaterHeaterEnable=1 to enable =0 to disable"},
            { "setWaterHeaterMode", &setWaterHeaterMode, boolFunctionByteType, "set WaterHeater Mode", NULL, "Usage: --setWaterHeaterMode=X range 0-8"},
            { "getWaterHeaterBurnerStatus", &getWaterHeaterBurnerStatus, boolFunctionPByteType, "Get State of Water Heater Burner", "Water Heater Burner Status", ""},
            { "getWaterHeaterErrorCode", &getWaterHeaterErrorCode, boolFunctionPByteType, "Get Error State of Water Heater Burner", "Water Heater Error Code", ""},
            { "setWaterHeaterPowerLED", &setWaterHeaterPowerLED, boolFunctionByteType, "set WaterHeater Power LED", NULL, "Usage: --setWaterHeaterPowerLED=X, 1=ON 0=OFF"},
            { "clearWaterHeaterError", &clearWaterHeaterError, boolFunctionVoidType, "Clear Water Heater error", NULL, "Usage: --clearWaterHeaterError"},
            { "setLIN100PDUEnable", &setLIN100PDUEnable, boolFunctionByteType, "Enable LIN100PDU", NULL, "Usage: --setLIN100PDUEnable=1 to enable =0 to disable"},
            { "setPDUPowerSource", &setPDUPowerSource, boolFunctionByteType, "set PDU Power Source", NULL, "Usage: --setPDUPowerSource=0 Leisure 1, Vehicle, 2 = Both"},
            { "getIgnitionSignal", &getIgnitionSignal, boolFunctionPByteType, "Get Ignition Signal", "Ignition signal", ""},
            { "get230VPresentSignal", &get230VPresentSignal, boolFunctionPByteType, "Get 230V Present Signal", "230V Present signal", ""},
            { "getLeisureBatteryVoltage", &getLeisureBatteryVoltage, boolFunctionPByteType, "Get voltage of the Leisure Battery", "Leisure Battery Voltage", ""},
            { "getVehicleBatteryVoltage", &getVehicleBatteryVoltage, boolFunctionPIntType, "Get voltage of the Vehicle Battery", "Vehicle Battery Voltage", ""},
            { "getLoadCurrent", &getLoadCurrent, boolFunctionPIntType, "Get then Load Current", "Load Current", ""},
            { "setFridgetoSystemRelay", &setFridgetoSystemRelay, boolFunctionByteType, "set Fridge to System Relay", NULL, "Usage: --setFridgetoSystemRelay=0 is Off, 1 = On"},
            { "setOutput1", &setOutput1, boolFunctionByteType, "Set LIN100PDU Output 1", NULL, "Usage: --setOutput1=<XX>, range 0-255"},
            { "setOutput2", &setOutput2, boolFunctionByteType, "Set LIN100PDU Output 2", NULL, "Usage: --setOutput2=<XX>, range 0-255"},
            { "setOutput3", &setOutput3, boolFunctionByteType, "Set LIN100PDU Output 3", NULL, "Usage: --setOutput3=<XX>, range 0-255"},
            { "getOutputOverloadState", &getOutputOverloadState, boolFunctionPByteType, "LIN100PDU Output Overload status", NULL, "Usage: --getOutputOverloadState"},
            { "getPositiveInput1", &getPositiveInput1, boolFunctionPByteType, "Get Digital State of LIN100PDU Positive Input 1", "Positive Input 1", ""},
            { "getPositiveInput2", &getPositiveInput2, boolFunctionPByteType, "Get Digital State of LIN100PDU Positive Input 2", "Positive Input 2", ""},
            { "getNegativeInput1", &getNegativeInput1, boolFunctionPByteType, "Get Digital State of LIN100PDU Negative Input 1", "Negative Input 1", ""},
            { "getADCInput1", &getADCInput1, boolFunctionPIntType, "Get 10 bit ADC Value of LIN100PDU ADC Input 1", "ADC Input 1", ""},
            { "getADCInput2", &getADCInput2, boolFunctionPIntType, "Get 10 bit ADC Value of LIN100PDU ADC Input 2", "ADC Input 2", ""},
            { "setHexnode1Enable", &setHexnode1Enable, boolFunctionByteType, "Enable Hexnode 1", NULL, "Usage: --setHexnode1Enable=1 to enable =0 to disable"},
            { "setHexnode1Output1", &setHexnode1Output1, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode1Output1=<XX>, range 0-255"},
            { "setHexnode1Output2", &setHexnode1Output2, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode1Output2=<XX>, range 0-255"},
            { "setHexnode1Output3", &setHexnode1Output3, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode1Output3=<XX>, range 0-255"},
            { "setHexnode1Output4", &setHexnode1Output4, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode1Output4=<XX>, range 0-255"},
            { "setHexnode1Output5", &setHexnode1Output5, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode1Output5=<XX>, range 0-255"},
            { "setHexnode1Output6", &setHexnode1Output6, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode1Output6=<XX>, range 0-255"},
            { "getHexnode1OutputOverloadStatus", &getHexnode1OutputOverloadStatus, boolFunctionPByteType, "Hexnode Overload status", NULL, "Usage: --getHexnode1OverloadStatus"},
            { "getHexnode1Input1", &getHexnode1Input1, boolFunctionPByteType, "Get State of Hexnode 1 Input 1", "Hexnode 1 Input 1", ""},
            { "getHexnode1Input2", &getHexnode1Input1, boolFunctionPByteType, "Get State of Hexnode 1 Input 2", "Hexnode 1 Input 2", ""},
            { "getHexnode1Input3", &getHexnode1Input1, boolFunctionPByteType, "Get State of Hexnode 1 Input 3", "Hexnode 1 Input 3", ""},
            { "getHexnode1Input4", &getHexnode1Input1, boolFunctionPByteType, "Get State of Hexnode 1 Input 4", "Hexnode 1 Input 4", ""},
            { "getHexnode1ADCInput5", &getHexnode1ADCInput5, boolFunctionPIntType, "Get 10 bit ADC Value of Hexnode 1 Input 5", "Hexnode 1 ADC Input 5", ""},
            { "getHexnode1ADCInput6", &getHexnode1ADCInput6, boolFunctionPIntType, "Get 10 bit ADC Value of Hexnode 1 Input 6", "Hexnode 1 ADC Input 6", ""},
            { "setHexnode2Enable", &setHexnode2Enable, boolFunctionByteType, "Enable Hexnode 2", NULL, "Usage: --setHexnode2Enable=1 to enable =0 to disable"},
            { "setHexnode2Output1", &setHexnode2Output1, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode2Output1=<XX>, range 0-255"},
            { "setHexnode2Output2", &setHexnode2Output2, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode2Output2=<XX>, range 0-255"},
            { "setHexnode2Output3", &setHexnode2Output3, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode2Output3=<XX>, range 0-255"},
            { "setHexnode2Output4", &setHexnode2Output4, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode2Output4=<XX>, range 0-255"},
            { "setHexnode2Output5", &setHexnode2Output5, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode2Output5=<XX>, range 0-255"},
            { "setHexnode2Output6", &setHexnode2Output6, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode2Output6=<XX>, range 0-255"},
            { "getHexnode2OutputOverloadStatus", &getHexnode2OutputOverloadStatus, boolFunctionPByteType, "Hexnode Overload status", NULL, "Usage: --getHexnode2OverloadStatus"},
            { "getHexnode2Input1", &getHexnode2Input1, boolFunctionPByteType, "Get State of Hexnode 2 Input 1", "Hexnode 2 Input 1", ""},
            { "getHexnode2Input2", &getHexnode2Input1, boolFunctionPByteType, "Get State of Hexnode 2 Input 2", "Hexnode 2 Input 2", ""},
            { "getHexnode2Input3", &getHexnode2Input1, boolFunctionPByteType, "Get State of Hexnode 2 Input 3", "Hexnode 2 Input 3", ""},
            { "getHexnode2Input4", &getHexnode2Input1, boolFunctionPByteType, "Get State of Hexnode 2 Input 4", "Hexnode 2 Input 4", ""},
            { "getHexnode2ADCInput5", &getHexnode2ADCInput5, boolFunctionPIntType, "Get 10 bit ADC Value of Hexnode 2 Input 5", "Hexnode 2 ADC Input 5", ""},
            { "getHexnode2ADCInput6", &getHexnode2ADCInput6, boolFunctionPIntType, "Get 10 bit ADC Value of Hexnode 2 Input 6", "Hexnode 2 ADC Input 6", ""},
            { "setHexnode3Enable", &setHexnode3Enable, boolFunctionByteType, "Enable Hexnode 3", NULL, "Usage: --setHexnode3Enable=1 to enable =0 to disable"},
            { "setHexnode3Output1", &setHexnode3Output1, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode3Output1=<XX>, range 0-255"},
            { "setHexnode3Output2", &setHexnode3Output2, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode3Output2=<XX>, range 0-255"},
            { "setHexnode3Output3", &setHexnode3Output3, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode3Output3=<XX>, range 0-255"},
            { "setHexnode3Output4", &setHexnode3Output4, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode3Output4=<XX>, range 0-255"},
            { "setHexnode3Output5", &setHexnode3Output5, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode3Output5=<XX>, range 0-255"},
            { "setHexnode3Output6", &setHexnode3Output6, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode3Output6=<XX>, range 0-255"},
            { "getHexnode3OutputOverloadStatus", &getHexnode3OutputOverloadStatus, boolFunctionPByteType, "Hexnode Overload status", NULL, "Usage: --getHexnode3OverloadStatus"},
            { "getHexnode3Input1", &getHexnode3Input1, boolFunctionPByteType, "Get State of Hexnode 3 Input 1", "Hexnode 3 Input 1", ""},
            { "getHexnode3Input2", &getHexnode3Input1, boolFunctionPByteType, "Get State of Hexnode 3 Input 2", "Hexnode 3 Input 2", ""},
            { "getHexnode3Input3", &getHexnode3Input1, boolFunctionPByteType, "Get State of Hexnode 3 Input 3", "Hexnode 3 Input 3", ""},
            { "getHexnode3Input4", &getHexnode3Input1, boolFunctionPByteType, "Get State of Hexnode 3 Input 4", "Hexnode 3 Input 4", ""},
            { "getHexnode3ADCInput5", &getHexnode3ADCInput5, boolFunctionPIntType, "Get 10 bit ADC Value of Hexnode 3 Input 5", "Hexnode 3 ADC Input 5", ""},
            { "getHexnode3ADCInput6", &getHexnode3ADCInput6, boolFunctionPIntType, "Get 10 bit ADC Value of Hexnode 3 Input 6", "Hexnode 3 ADC Input 6", ""},
            { "setHexnode4Enable", &setHexnode4Enable, boolFunctionByteType, "Enable Hexnode 4", NULL, "Usage: --setHexnode4Enable=1 to enable =0 to disable"},
            { "setHexnode4Output1", &setHexnode4Output1, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode4Output1=<XX>, range 0-255"},
            { "setHexnode4Output2", &setHexnode4Output2, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode4Output2=<XX>, range 0-255"},
            { "setHexnode4Output3", &setHexnode4Output3, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode4Output3=<XX>, range 0-255"},
            { "setHexnode4Output4", &setHexnode4Output4, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode4Output4=<XX>, range 0-255"},
            { "setHexnode4Output5", &setHexnode4Output5, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode4Output5=<XX>, range 0-255"},
            { "setHexnode4Output6", &setHexnode4Output6, boolFunctionByteType, "Set Hexnode Output", NULL, "Usage: --setHexnode4Output6=<XX>, range 0-255"},
            { "getHexnode4OutputOverloadStatus", &getHexnode4OutputOverloadStatus, boolFunctionPByteType, "Hexnode Overload status", NULL, "Usage: --getHexnode4OverloadStatus"},
            { "getHexnode4Input1", &getHexnode4Input1, boolFunctionPByteType, "Get State of Hexnode 4 Input 1", "Hexnode 4 Input 1", ""},
            { "getHexnode4Input2", &getHexnode4Input1, boolFunctionPByteType, "Get State of Hexnode 4 Input 2", "Hexnode 4 Input 2", ""},
            { "getHexnode4Input3", &getHexnode4Input1, boolFunctionPByteType, "Get State of Hexnode 4 Input 3", "Hexnode 4 Input 3", ""},
            { "getHexnode4Input4", &getHexnode4Input1, boolFunctionPByteType, "Get State of Hexnode 4 Input 4", "Hexnode 4 Input 4", ""},
            { "getHexnode4ADCInput5", &getHexnode4ADCInput5, boolFunctionPIntType, "Get 10 bit ADC Value of Hexnode 4 Input 5", "Hexnode 4 ADC Input 5", ""},
            { "getHexnode4ADCInput6", &getHexnode4ADCInput6, boolFunctionPIntType, "Get 10 bit ADC Value of Hexnode 4 Input 6", "Hexnode 4 ADC Input 6", ""},
            { "setLIN50PDUEnable", &setLIN50PDUEnable, boolFunctionByteType, "Enable LIN50PDU 4", NULL, "Usage: --setLIN50PDUEnable=1 to enable =0 to disable"},
            { "setLIN50PDUPowerSource", &setLIN50PDUPowerSource, boolFunctionByteType, "set LIN50PDU Power Source", NULL, "Usage: --setLIN50PDUPowerSource=0 Leisure 1, Vehicle"},
            { "setLIN50PDUMaster", &setLIN50PDUMaster, boolFunctionByteType, "set LIN50PDU Master Switch", NULL, "Usage: --setLIN50PDUMaster=0 off 1, on"},
            { "setLIN50PDULights", &setLIN50PDULights, boolFunctionByteType, "set LIN50PDU Lights Switch", NULL, "Usage: --setLIN50PDULights=0 off 1, on"},
            { "setLIN50PDUAwning", &setLIN50PDUAwning, boolFunctionByteType, "set LIN50PDU Awning Lights Switch", NULL, "Usage: --setLIN50PDUAwning=0 off 1, on"},
            { "setLIN50PDUPumpMode", &setLIN50PDUPumpMode, boolFunctionByteType, "set LIN50PDU Pump MOde", NULL, "Usage: --setLIN50PDUPumpMode=0 off, 1 External Pump On, 2 Internal Pump ON, 3 Fill internal from external"},
            { "getLIN50PDULoadCurrent", &getLIN50PDULoadCurrent, boolFunctionPIntType, "Get then Load Current", "Load Current", ""},
            { "getLIN50PDUSolarCurrent", &getLIN50PDUSolarCurrent, boolFunctionPIntType, "Get then Solar Load Current", "Solar Current", ""},
            { "getLIN50PDULeisureBatteryCurrent", &getLIN50PDULeisureBatteryCurrent, boolFunctionPIntType, "Get then Leisure Battery Current", "Leisure Battery Current", ""},
            { "getLIN50PDUVehicleBatteryCurrent", &getLIN50PDUVehicleBatteryCurrent, boolFunctionPIntType, "Get then Vehicle Battery Current", "Vehicle Battery Current", ""},
            { "getLIN50PDUMainsCurrent", &getLIN50PDUMainsCurrent, boolFunctionPIntType, "Get then Mains Current", "Mains Current", ""},
            { "getLIN50PDUFuseState", &getLIN50PDUFuseState, boolFunctionPIntType, "LIN50PDU Fuse status", NULL, "Usage: --getLIN50PDUFuseState"},
            { "getLIN50PDUOutputOverloadState", &getLIN50PDUOutputOverloadState, boolFunctionPByteType, "LIN50PDU Output Overload status", NULL, "Usage: --getLIN50PDUOutputOverloadState"},
            { "getLIN50PDULeisureBatteryVoltage", &getLIN50PDULeisureBatteryVoltage, boolFunctionPIntType, "Get the Leisure Battery Voltage", "Leisure Battery Voltage", ""},
            { "getLIN50PDUVehicleBatteryVoltage", &getLIN50PDUVehicleBatteryVoltage, boolFunctionPIntType, "Get the Vehicle Battery Voltage", "Vehicle Battery Voltage", ""},
            { "getLIN50PDUWaterLevel", &getLIN50PDUWaterLevel, boolFunctionPIntType, "Get the Water Level", "Water Level", ""},
            { "getLIN50PDUWasteLevel", &getLIN50PDUWasteLevel, boolFunctionPIntType, "Get the Waste Level", "Waste Level", ""},
            { "getLIN50PDUInternalTemperature", &getLIN50PDUInternalTemperature, boolFunctionPByteType, "Get the Internal Temperature", "Internal Temperature", ""},
            { "getLIN50PDUExternalTemperature", &getLIN50PDUExternalTemperature, boolFunctionPByteType, "Get the External Temperature", "External Temperature", ""},
            { "getLIN50PDUMainsSignal", &getLIN50PDUMainsSignal, boolFunctionPByteType, "Get whether mains is connected", "Mains Signal", ""},
            { "getLIN50PDUIgnitionSignal", &getLIN50PDUIgnitionSignal, boolFunctionPByteType, "Get whether ignition is on or off", "Ignition Signal", ""},
            { "getLIN50PDUPumpFeedback", &getLIN50PDUPumpFeedback, boolFunctionPByteType, "Get whether the pump is on or off", "Pump", ""},
            { "initCommandTable", &initCommandTable, boolFunctionVoidType, "initalise Command Table", NULL, "Usage: --initCommandTable"},
            { "enableCommandHandler", &enableCommandHandler, boolFunctionVoidType, "Enable Command Handler", NULL, "Usage: --enableCommandHandler"},
            { "disableCommandHandler", &disableCommandHandler, boolFunctionVoidType, "Disable Command Handler", NULL, "Usage: --disableCommandHandler"},
            { "addCommandTableEntry", &addCommandTableEntry, boolFunctionPCmdEntryType, "add an entry to the Command Table", NULL, "Usage: --addCommandTableEntry= Param1,Param2,...,Param8 (all in Decimal)"},
            {  NULL, NULL,0}
        };


dwSet_t * getFunction(char * functionName)
{
    void * result=NULL;
    int i=0;
    while (result==NULL)
    {
        if (functionList[i].functionName==NULL)
            break;
        else if (strcmp(functionName, functionList[i].functionName)==0)
            result = (void * )&functionList[i];
        i++;
    }

    if (result == NULL)
        fprintf(stderr, "unknown function \"%s\"\n", functionName);

    return result;
}

int main(int argc, char *argv[])
{
#ifndef WIN32
	struct sigaction setmask;

    sigemptyset( &setmask.sa_mask );
    setmask.sa_handler = sigfunc;
    setmask.sa_flags   = 0;

    sigaction( SIGHUP,  &setmask, (struct sigaction *) NULL );
    sigaction( SIGINT,  &setmask, (struct sigaction *) NULL );
    sigaction( SIGTERM,  &setmask, (struct sigaction *) NULL );
#endif

	char * deviceName = NULL;
	char * baudRate="115200";
	char * outputMode = "TEXT";
    const char *separator = "\n";
    int argsNumber = 0;

    int argc2 = argc;
    int argc3 = argc;
    bool isOk = true;
    argc=1;

    while (--argc2)
    {
        if (strncmp(argv[argc2],"--device=",9)==0)
        {
            deviceName=argv[argc2]+9;
        }
		else if (strncmp(argv[argc2],"--baud=",7)==0)
		{
			baudRate=argv[argc2]+7;
		}
        else if (strncmp(argv[argc2],"--help",6)==0)
        {
            int i;
            int len = sizeof(functionList)/sizeof(functionList[0]);
			printf("\ncc Version %02d.%02d\n\n", MAJOR_RELEASE_NO, MINOR_RELEASE_NO);
            printf("Usage: cc [--device=<devicename>]  [--baud=<baudrate>] [--<setFunction>]\n");
            printf("Example: cc [--device=%s]  --setBacklightOn\n",
			#ifndef WIN32
					"/dev/ttymxc1"
			#else
					"COM1"
			#endif
					);
            printf("The values shown in this example are the default values\n");
            printf("-----------------------------------\n");
            printf("Settings Parameters:\n");
            printf("-----------------------------------\n");

            for (i = 0; i < len; i++)
            {
                if (functionList[i].functionName == NULL)
                    break;
                printf("--%s\n", functionList[i].functionName);
            }

            return -1;
        }
        else if (strncmp(argv[argc2],"--longhelp",10)==0)
        {
            int i;
            int len = sizeof(functionList)/sizeof(functionList[0]);
			printf("\ncc Version %02d.%02d\n\n", MAJOR_RELEASE_NO, MINOR_RELEASE_NO);
            printf("Usage: cc [--device=<devicename>] [--<setFunction>]\n");
            printf("Example: cc [--device=%s] [--baud=115200]\n",
			#ifndef WIN32
					"/dev/ttymxc1"
			#else
					"COM1"
			#endif
					);
            printf("The values shown in this example are the default values\n");
			printf("Supported Baud Rate 19200 and 115200(default)\n");
            printf("-----------------------------------\n");
            printf("Settings Parameters:\n");
            printf("-----------------------------------\n");

            for (i = 0; i < len; i++)
            {
                if (functionList[i].functionName == NULL)
                    break;
                printf("--%s\n  %s\n%s\n\n", functionList[i].functionName, functionList[i].functionDescription, functionList[i].usage);
            }

            printf("--output-mode=[NUMERIC|TEXT]\n\n");
            printf("--csv\n");

            return -1;
        }
        else if (strncmp(argv[argc2], "--output-mode=", 14)==0)
        {
            outputMode = argv[argc2]+14;
        }
        else if (strncmp(argv[argc2], "--csv", 5)==0)
        {
            separator = ",";
        }
        else
        {
            argsNumber++;
        }
    }

	if ( (strncmp( baudRate, "19200", 5 ) != 0) && (strncmp( baudRate, "115200", 6 ) != 0) )
	{
            fprintf(stderr, "Baudrate %s not supported\n", baudRate);
            return -1;
	}


	if (deviceName==NULL)
    {
        deviceName = getDevice(baudRate);
        if (deviceName==NULL)
        {
            fprintf(stderr, "device not found\n");
            return -1;
        }
        else
            fprintf(stderr, "%s\n",deviceName);
    }



	// print settings
//	printf("Serial port: %s\n",deviceName);
    if (openPort(deviceName, baudRate) == false) return -1;
    while (argc  < argc3)
    {
        char functionName[255];
        char parameters[255];

             if (strncmp(argv[argc],"--device=",9)==0)
            {
                argc++;
                continue;
            }
             if (strncmp(argv[argc],"--baud=",7)==0)
            {
                argc++;
                continue;
            }

       if (sscanf(argv[argc], "--%[^=]=%s", functionName, parameters)==2)
        {
//            fprintf(stderr,"call %s(%s)\n",functionName,parameters);
        }
        else if (sscanf(argv[argc], "--%s", functionName)==1)
        {
 //           fprintf(stderr,"call %s()\n",functionName);
            parameters[0]='\0';
        }
        else
        {
            fprintf(stderr,"Ignore argument %s\n",argv[argc]);
            continue;
        }

		{
            //get pointer according to name in array
            dwSet_t * thingy = getFunction(functionName);
            if (thingy != NULL)
            {
                switch (thingy->type)
                {
                    case boolFunctionVoidType:
                        (*((boolFunctionVoid)thingy->functionPointer))();
                        break;
                    case boolFunctionByteType:
                        {
                            int param1;
                            if (sscanf(parameters, "%d", &param1)==1)
                                isOk = (*((boolFunctionByte)thingy->functionPointer))(param1) && isOk;
                            else
                                fprintf(stderr,"Error param boolFunctionByteType\n");
                        }
                        break;
                    case boolFunctionIntType:
                        {
                            int param1;
                            if (sscanf(parameters, "%d", &param1)==1)
                                isOk = (*((boolFunctionInt)thingy->functionPointer))(param1) && isOk;
                            else
                                fprintf(stderr,"Error param boolFunctionIntType\n");
                        }
                        break;
                    case boolFunctionWordType:
                        {
                            int param1;
                            if (sscanf(parameters, "%d", &param1)==1)
                                isOk = (*((boolFunctionWord)thingy->functionPointer))(param1) && isOk;
                            else
                                fprintf(stderr,"Error param boolFunctionWordType\n");
                        }
                        break;
                    case boolFunctionPByteType:
                        {
                            BYTE param1;
                            isOk = (*((boolFunctionPByte)thingy->functionPointer))(&param1) && isOk;

                            if (isOk)
                            {
                                if (param1 == 101)
                                {
                                    fprintf(stdout, "%d%s", -1, separator);
                                    break;
                                }
                                if (strcmp(outputMode, "NUMERIC") == 0)
                                {
                                    char * translation = translate(functionName, param1);
                                    if ((translation != NULL) && (strcmp(separator, ",") == 0))
                                        fprintf(stdout, "\"%s\"%s", translation, separator);
                                    else
                                        fprintf(stdout, "%d%s", param1, separator);
                                }
                                else if ((strcmp(outputMode, "TEXT") == 0) && (strcmp(separator, ",") == 0))
                                {
                                    char * translation = translate(functionName, param1);
                                    if (translation != NULL)
                                        fprintf(stdout, "\"%s\"%s", translation, separator);
                                    else
                                        fprintf(stdout, "%d%s", param1, separator);
                                }
                                else
                                {
                                    char * translation = translate(functionName, param1);
                                    if ((translation != NULL) && (strcmp(separator, ",") == 0))
                                        fprintf(stdout, "%s%s", translation, separator);
                                    else
                                        fprintf(stdout, "%s => %d%s", thingy->textual, param1, separator);
                                }
                            }
                        }
                        break;

                    case boolFunctionPIntType:
                        {
                            int param1;
                            isOk = (*((boolFunctionPInt)thingy->functionPointer))(&param1) && isOk;

                            if (isOk)
							{
								if (param1 == 101)
								{
									fprintf(stdout, "%d%s", -1, separator);
									break;
								}
								if (strcmp(outputMode, "NUMERIC") == 0)
								{
									char * translation = translate(functionName, param1);
									if ((translation != NULL) && (strcmp(separator, ",") == 0))
										fprintf(stdout, "\"%s\"%s", translation, separator);
									else
										fprintf(stdout, "%d%s", param1, separator);
								}
								else if ((strcmp(outputMode, "TEXT") == 0) && (strcmp(separator, ",") == 0))
								{
									char * translation = translate(functionName, param1);
									if (translation != NULL)
										fprintf(stdout, "\"%s\"%s", translation, separator);
									else
										fprintf(stdout, "%d%s", param1, separator);
								}
								else
								{
									char * translation = translate(functionName, param1);
									if ((translation != NULL) && (strcmp(separator, ",") == 0))
										fprintf(stdout, "%s%s", translation, separator);
									else
										fprintf(stdout, "%s => %d%s", thingy->textual, param1, separator);
								}
                            }
                        }
                        break;
                     case boolFunctionPIntPIntType:
                        {
                            int param1;
                            int param2;
                            isOk = (*((boolFunctionPIntPInt)thingy->functionPointer))(&param1, &param2) && isOk;

							if (!isOk)
								break;

                            if (param1 == 101)
                            {
                                fprintf(stdout, "%d%s", -1, separator);
                                break;
                            }
                            else if (strcmp(outputMode, "NUMERIC") == 0)
                                fprintf(stdout, "%d.%02d%s", param1, param2, separator);
                            else if ((strcmp(outputMode, "TEXT") == 0) && (strcmp(separator, ",") == 0))
                                fprintf(stdout, "%d.%02d%s", param1, param2, separator);
                            else
                                fprintf(stdout, "%s => %d.%02d\n", thingy->textual, param1, param2);
                        }
                        break;
                    case boolFunctionIntPIntType:
                        {
                            int param1;
                            int param2;
                            if (sscanf(parameters, "%d", &param1)==1)
                            {
                                isOk = (*((boolFunctionIntPInt)thingy->functionPointer))(param1, &param2) && isOk;

								if (!isOk)
									break;
                                if (param2 == 101)
                                {
                                    fprintf(stdout, "%d%s", -1, separator);
                                    break;
                                }
                                else if (strcmp(outputMode, "NUMERIC") == 0)
                                    fprintf(stdout, "%d%s", param2, separator);
                                else if ((strcmp(outputMode, "TEXT") == 0) && (strcmp(separator, ",") == 0))
                                    fprintf(stdout, "%d%s", param2, separator);
                                else
                                    fprintf(stdout, "%s => %d\n", thingy->textual, param2);
                            }
                        }
                        break;
                     case boolFunctionPWordType:
                        {
                            WORD param1;
                            isOk = (*((boolFunctionPWord)thingy->functionPointer))(&param1) && isOk;

							if (!isOk)
								break;

							if (param1 == 101)
                            {
                                fprintf(stdout, "%d%s", -1, separator);
                                break;
                            }
                            else if (strcmp(outputMode, "NUMERIC") == 0)
                                fprintf(stdout, "%d%s", param1, separator);
                            else if ((strcmp(outputMode, "TEXT") == 0) && (strcmp(separator, ",") == 0))
                                fprintf(stdout, "%d%s", param1, separator);
                            else
                                fprintf(stdout, "%s => %d\n", thingy->textual, param1);
                        }
                        break;
					case boolFunctionPStringIntType:
                            if ((*((boolFunctionPStringInt)thingy->functionPointer))(parameters, strlen(parameters)))
									fprintf(stdout, "OK\n");
						    else
						        isOk=false;

						break;
					case boolFunctionPStringPIntType:
						{
							char ResponseString[256];
							int Len;
							if ((*((boolFunctionPStringPInt)thingy->functionPointer))(ResponseString, &Len))
								fprintf(stdout, "%s\n", ResponseString);
						    else
						        isOk=false;

						}
						break;
					case getLINProductIDType:
					{
						BYTE LINProductID[5];
						int param1;
						if (sscanf(parameters, "%d", &param1) == 1)
						{
							if (getLINProductID( param1, &LINProductID[0]))
							{
								fprintf(stdout, "ProductID = %02x, %02x, %02x, %02x %02x\n", LINProductID[0], LINProductID[1], LINProductID[2], LINProductID[3], LINProductID[4]);
								isOk = true;
							}
							else
								isOk = false;
						}
						else
							isOk = false;
					}
					break;
					case getLINProductSNType:
					{
						BYTE LINProductSN[4];
						int param1;
						if (sscanf(parameters, "%d", &param1) == 1)
						{
							if (getLINProductSN(param1, &LINProductSN[0]))
							{
								fprintf(stdout, "ProductSN = %02x, %02x, %02x, %02x\n", LINProductSN[0], LINProductSN[1], LINProductSN[2], LINProductSN[3] );
								isOk = true;
							}
							else
								isOk = false;
						}
						else
							isOk = false;
					}
					break;
					
					case assignFrameIDRangeType:
					{
					    BYTE byteString[6] = { 1, 2 ,3 ,4 ,5 ,6 };
    					bool err = false;

						if (! err)
						{
							if (assignFrameIDRange(byteString))
							{
								fprintf(stdout, "Frame Assigned\n" );
								isOk = true;
							}
							else
								isOk = false;
						}
						else
							isOk = false;
					}
					break;

                    case overloadStatusType:
                    {
                        BYTE overloadStatus[6];
                        if (getHexnode1OutputOverloadStatus(&overloadStatus[0]))
                            {
                                fprintf(stdout, "Overload status = %02x, %02x, %02x, %02x, %02x, %02x\n", 
                                    overloadStatus[0], overloadStatus[1], overloadStatus[2] ,overloadStatus[3], overloadStatus[4], overloadStatus[5] );
                                isOk = true;
                            }
                            else
                                isOk = false;

                    }
                    break;

                    case boolFunctionPCmdEntryType:
                    {
                            int param1, param2, param3, param4, param5, param6, param7, param8;
//                            fprintf (stdout, "parameters = %s\r\n", parameters);
                            if (sscanf(parameters, "%d\,%d\,%d\,%d\,%d\,%d\,%d\,%d", &param1, &param2, &param3, &param4, &param5, &param6, &param7, &param8)==8)
                            {
                                struct command commandTableEntry;
                                commandTableEntry.commandID =           (int)param1;
                                commandTableEntry.param =               (int)param2;
                                commandTableEntry.msRepeatTime =        (unsigned)param3;
                                commandTableEntry.checkReturnValue =    (bool)param4;
                                commandTableEntry.toggleMode =          (BYTE)param5;
                                commandTableEntry.comparisonType =      (BYTE)param6;
                                commandTableEntry.value1 =              (int)param7;
                                commandTableEntry.value2 =              (int)param8;

//                                fprintf(stdout, "commandID=%02x,param=%d,msRepeatTime=%d,checkReturnValue=%d,toggleMode=%d,comparisonType=%d,value1=%d,value2=%d\r\n",
//                                    param1,param2,param3,param4,param5,param6,param7,param8);

                                isOk = (*((boolFunctionPCmdEntry)thingy->functionPointer))(&commandTableEntry) && isOk;
                            }
                            else
                                fprintf(stderr,"Error param boolFunctionPCmdEntryType\n");
                    }
                    break;
					default:
                        fprintf(stderr, "unknown type\n");
                }
            }
		}
        argc++;

    }

    if (strcmp(separator, ",") == 0)
    {
        fprintf(stdout, "\b%s\n", " ");
    }
    closePort();

    if (!isOk)
	{
		fprintf(stderr, "error\n");
        return -1;
	}
    return returnValue;
}
