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
typedef bool(*boolFunctionWord)(WORD);
typedef bool(*boolFunctionPInt)(int *);
typedef bool(*boolFunctionPIntPInt)(int *, int *);
typedef bool(*boolFunctionIntPInt)(int, int *);
typedef bool(*boolFunctionPWord)(WORD *);
typedef bool(*boolFunctionPStringInt)(char *, int);
typedef bool(*boolFunctionPStringPInt)(char *, int *);

enum {
    boolFunctionVoidType,
    boolFunctionIntType,
    boolFunctionWordType,
    boolFunctionPIntType,
    boolFunctionPIntPIntType,
    boolFunctionIntPIntType,
    boolFunctionPWordType,
	boolFunctionPStringIntType,
	boolFunctionPStringPIntType,
	getLINProductIDType,
	getLINProductSNType,
	assignFrameIDRangeType
};

typedef struct translation_s
{
    char *functionName;
    char *options[12];
} translation_t;

static translation_t translationList[] =
        {
 /*           {"getBacklightState", {"Off", "Under current on", "On", "Over current on", "Critical failure off", "Unknown" ,"Unknown","Unknown","Unknown","Unknown","Unknown","Unknown"}},
            {"getFansState", {"Off", "Under current on", "On", "Over current on", "Critical failure off", "Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown"}},
            {"getDisplayState", {"Off", "Under current on", "On", "Over current on", "Critical failure off", "Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown"}},
            {"getSystemBoardState", {"Off", "Under current on", "On", "Over current on", "Critical failure off", "Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown"}},
			{"getNumberOfSystemResets", {"System started", "Watchdog timeout", "Over temperature", "Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown", "Unknown", "Unknown"}},
			{"get3GSMSState", {"Idle","Start","CentreNo AT","CentreNoOK","StorageLocation AT","StorageLocation OK","SelectMode AT","SelectMode OK","ReceiveMode AT","ReceiveMode OK","SMS READY","TimeOut"}},
			{"get3GModemState", {"Idle","Start Modem","Wait for START","Wait for CPIN","Wait for SMS Done","Wait for PB Done","Modem Ready","Timeout","Restart","Unknown","Unknown","Unknown"}},
			{"getShutterState", {"Down", "Up","Unknown" ,"Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown"}},
			{"getShutterCommandState", {"Automatic", "Remote", "Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown,Unknown"}},
			{"getShockAlarmState", {"NormalState", "AlarmState", "Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown","Unknown"}},
*/
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
//			printf( "Matched %s %s\ Index = %d\n",functionName, translationList[i].functionName, index );
//			printf( "%s\n", translationList[i].options[index]);

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
            //BackLight
/*            {"setBacklightOn", &setBacklightOn, boolFunctionVoidType, "Turn on the backlight.", NULL, ""},
            {"setBacklightOff", &setBacklightOff, boolFunctionVoidType, "Turn off the backlight.", NULL, ""},
            {"setAutomaticBrightnessControlOn", &setAutomaticBrightnessControlOn, boolFunctionVoidType, "Turn on the Automatic Brightness Control.", NULL, ""},
            {"setAutomaticBrightnessControlOff", &setAutomaticBrightnessControlOff, boolFunctionVoidType, "Turn off the Automatic Brightness Control.", NULL, ""},
            {"enableBacklightOnAlarm", &enableBacklightOnAlarm, boolFunctionVoidType, "Enable the backlight on alarm.", NULL, ""},
            {"disableBacklightOnAlarm", &disableBacklightOnAlarm, boolFunctionVoidType, "Disable the backlight on alarm.", NULL, ""},
            {"enableBacklightOffAlarm", &enableBacklightOffAlarm, boolFunctionVoidType, "Enable the backlight off alarm.", NULL, ""},
            {"disableBacklightOffAlarm", &disableBacklightOffAlarm, boolFunctionVoidType, "Disable the backlight Off alarm.", NULL, ""},
            {"enableBacklightDimAlarm", &enableBacklightDimAlarm, boolFunctionVoidType, "Enable the backlight Dim alarm.", NULL, ""},
            {"disableBacklightDimAlarm", &disableBacklightDimAlarm, boolFunctionVoidType, "Disable the backlight Dim alarm.", NULL, ""},
            {"enableBacklightBrightAlarm", &enableBacklightBrightAlarm, boolFunctionVoidType, "Enable the backlight Bright alarm.", NULL, ""},
            {"disableBacklightBrightAlarm", &disableBacklightBrightAlarm, boolFunctionVoidType, "Disable the backlight Bright alarm.", NULL, ""},
            {"setBrightnessLevel", &setBrightnessLevel, boolFunctionIntType, "Set the brightness level for the backlight.", NULL, "  Usage: --setBrightnessLevel=<value>"},
            {"setBacklightOnAlarm", &setBacklightOnAlarm, boolFunctionTimeType, "Set the time for the backlight on alarm.", NULL, "  Usage: --setBacklightOnAlarm=<hh:mm:ss>"},
            {"setBacklightOffAlarm", &setBacklightOffAlarm, boolFunctionTimeType, "Set the time for the backlight off alarm.", NULL, "  Usage: --setBacklightOffAlarm=<hh:mm:ss>"},
            {"setBacklightDimAlarm", &setBacklightDimAlarm, boolFunctionTimeType, "Set the time for the backlight dim alarm.", NULL, "  Usage: --setBacklightDimAlarm=<hh:mm:ss>"},
            {"setBacklightBrightAlarm", &setBacklightBrightAlarm, boolFunctionTimeType, "Set the time for the backlight bright alarm.", NULL, "  Usage: --setBacklightBrightAlarm=<hh:mm:ss>"},
            {"getBrightnessLevel", &getBrightnessLevel, boolFunctionPIntType, "Get the brightness level for the backlight.", "Brightness Level", ""},
            {"getBacklightState", &getBacklightState, boolFunctionPIntType, "Get the current state of the backlight.", "Backlight State", ""},
            {"getAutomaticBrightnessControlState", &getAutomaticBrightnessControlState, boolFunctionPIntType, "Get the current state of the AutomaticBrightnessControl.", "AutomaticBrightnessControl State", ""},
            {"getBacklightCurrent", &getBacklightCurrent, boolFunctionPIntType, "Get the current used by the backlight.", "Backlight Current", ""},
            {"getBacklightOnAlarm", &getBacklightOnAlarm, boolFunctionPTimeType, "Get the time when the backlight should be turned on.", "Backlight On Alarm", ""},
            {"getBacklightOffAlarm", &getBacklightOffAlarm, boolFunctionPTimeType, "Get the time when the backlight should be turned off.", "Backlight Off Alarm", ""},
            {"getBacklightDimAlarm", &getBacklightDimAlarm, boolFunctionPTimeType, "Get the time when the backlight should be dimmed.", "Backlight Dim Alarm", ""},
            {"setAutoCenteringDelay", &setAutoCenteringDelay, boolFunctionIntType, "Set the delay before the Video Controller AutoAdjust.", NULL, "  Usage: --setAutoCenteringDelay=<value>"},
            {"getAutoCenteringDelay", &getAutoCenteringDelay, boolFunctionPIntType, "Gets the Delay setting for the AutoAdjust.", "AutoAdjust Delay Time", ""},
            {"setVideoActivityBacklightControlOn", &setVideoActivityBacklightControlOn, boolFunctionVoidType, "Turn the Video Activity Backlight Control on.", NULL, ""},
            {"setVideoActivityBacklightControlOff", &setVideoActivityBacklightControlOff, boolFunctionVoidType, "Turn the Video Activity Backlight Control off.", NULL, ""},
            //Display
            {"setDisplayOn", &setDisplayOn, boolFunctionVoidType, "Turn the display on.", NULL, ""},
            {"setDisplayOff", &setDisplayOff, boolFunctionVoidType, "Turn the display off.", NULL, ""},
            {"getDisplayCurrent", &getDisplayCurrent, boolFunctionPIntType, "Get the current usage.", "Display Current", ""},
            {"getDisplayState", &getDisplayState, boolFunctionPIntType, "Get the state of the display.", "Display State", ""},
            //Light
            {"setLightLevelChangeLimit", &setLightLevelChangeLimit, boolFunctionWordType, "Set the Light level change limit.", NULL, "  Usage: --setLightLevelChangeLimit=<value>"},
            {"getLightLevel", &getLightLevel, boolFunctionPWordType, "Get the Light level.", "Light Level", ""},
            {"getTimeSinceLastLightLevelChange", &getTimeSinceLastLightLevelChange, boolFunctionPWordType, "Get the time since the last change.", "Time Since Last Light Level Change", ""},
            //Fans control
            {"setFansOff", &setFansOff, boolFunctionVoidType, "Turn the fans on.", NULL, ""},
            {"setFansOn", &setFansOn, boolFunctionVoidType, "Turn the fans off.", NULL, ""},
            {"setFanSpeed", &setFanSpeedSetting, boolFunctionIntType, "Set the fan speed.", NULL, "  Usage: --setFanSpeed=<value>"},
            {"getFanSpeed", &getFanSpeed, boolFunctionIntPIntType, "Get the fan speed.", "Fan Speed", "  Usage: --getFanSpeed=<fan>"},
            {"getFanSpeedSetting", &getFanSpeedSetting, boolFunctionPIntType, "Get the fan speed setting.", "Fan Speed Setting", ""},
            {"getFansState", &getFansState, boolFunctionPIntType, "Get the fans state.", "Fans State", ""},
            //{"setFanSpeedSetting", &setFanSpeedSetting, boolFunctionIntType},
            //System
            {"setSystemBoardOn", &setSystemBoardOn, boolFunctionVoidType, "Turn the system board on.", NULL, ""},
            {"setSystemBoardOff", &setSystemBoardOff, boolFunctionVoidType, "Turn the system board off.", NULL, ""},
            {"setRTCTime", &setRTCTime, boolFunctionTimeType, "Set the time on the DisplayWatch board.", NULL, "  Usage: --setRTCTime=<hh:mm:ss>"},
            {"setRTCDate", &setRTCDate, boolFunctionDateType, "Set the date on the DisplayWatch board.", NULL, "  Usage: --setRTCTime=<dd/mm/yyyy>"},
            {"getRTCDate", &getRTCDate, boolFunctionPDateType, "Get the date on the DisplayWatch board.", "RTC Date", ""},
            {"getRTCTime", &getRTCTime, boolFunctionPTimeType, "Get the time on the DisplayWatch board.", "RTC Time", ""},
            {"getSystemBoardCurrent", &getSystemBoardCurrent, boolFunctionPIntType, "Get the system board current.", "System Board Current", ""},
            {"getSystemBoardState", &getSystemBoardState, boolFunctionPIntType, "Get the system board state.", "System Board State", ""},
            //Watchdog
            {"kickExternalWatchdog", &kickExternalWatchdog, boolFunctionVoidType, "Kick the watchdog.", NULL, ""},
            {"stopExternalWatchdog", &stopExternalWatchdog, boolFunctionVoidType, "Stop the watchdog.", NULL, ""},
            {"startExternalWatchdog", &startExternalWatchdog, boolFunctionWordType, "Start the watch dog.", NULL, "  Usage: --startExternalWatchdog=<value in seconds>"},
            {"getLastSystemReset", &getLastSystemReset, boolFunctionPTimePDateType, "Get the last time the system board have been reset.", "Last System Reset", ""},
            {"getNumberOfSystemResets", &getNumberOfSystemResets, boolFunctionPIntPResetCauseType, "Get the number of resets as well as the cause.", "Number Of System Resets", ""},
*/            //DisplayWatch Code Version
			{ "getCodeVersion", &getCodeVersion, boolFunctionPIntPIntType, "Get the code version.", "Code Version", "" },
			{ "getLINProductID", &getLINProductID, getLINProductIDType, "Get the LIN Product ID", "Lin Product ID", "  Usage: --getLINProductID=<nodeAddress>, range 0-63" },
			{ "getLINProductSN", &getLINProductSN, getLINProductSNType, "Get the LIN Product SN", "Lin Product SN", "  Usage: --getLINProductSN=<nodeAddress>, range 0-63" },
			{ "assignFrameIDRange", &assignFrameIDRange, assignFrameIDRangeType, "assign Frame ID Range", "Frame ID Range", "  Usage: --assignFrameIDRange= XX XX XX XX XX XX" },
/*            //Sensors
            {"getTemperature", &getTemperature, boolFunctionIntPIntType, "Get the temperature from a sensor.", "Temperature", "  Usage: --getTemperature=<sensor>"},
	    // Set to programming (firmware update mode
            {"startISP", &startISP, boolFunctionIntType, "Sets the board into Firmware Update Mode", NULL, "  Usage --startISP=<no of seconds before restarting>"},
			// 3G Modem
			{"reset3GModem", &reset3GModem, boolFunctionVoidType, "resets the 3G modem", NULL, ""},
			{"reset3GSMS", &reset3GSMS, boolFunctionVoidType, "resets the 3G SMS State Machine", NULL, ""},
            {"get3GModemState", &get3GModemState, boolFunctionPIntType, "Get the 3G Modem state.", "Modem State", ""},
            {"get3GSMSState", &get3GSMSState, boolFunctionPIntType, "Get the 3G Modem SMS state.", "SMS State", ""},
			{"set3GSMSMessageCentreNo", &set3GSMSMessageCentreNo, boolFunctionPStringIntType, "Set the SMS Message Centre Access Phone Number", NULL, "Usage: --set3GSMSMessageCentreNumber=<STRING>"},
			{"get3GSMSMessageCentreNo", &get3GSMSMessageCentreNo, boolFunctionPStringPIntType, "Get the SMS Message Centre Access Phone Number", NULL, "Usage: --get3GSMSMessageCentreNumber"},
			// IO
            {"getIOState", &getIOState, boolFunctionPIntType, "getIOState", NULL, ""},
			//Shutter
			{"setShutterUp", &setShutterUp, boolFunctionVoidType, "Open the shutter.", NULL, ""},
			{"setShutterDown", &setShutterDown, boolFunctionVoidType, "Close the shutter.", NULL, ""},
 			{"setShutterAutomatic", &setShutterAutomatic, boolFunctionVoidType, "Operate the shutter based on the Video Signal being present.", NULL, ""},
			{"setShutterRemote", &setShutterRemote, boolFunctionVoidType, "Operate the shutter through remote commands.", NULL, ""},
            {"setShutterMainsOnTime", &setShutterMainsOnTime, boolFunctionIntType, "Set the period before the mains is disconnected from the shutter after performing an up or down command.", NULL, "  Usage: --setShutterMainsOnTime=<value>"},
            {"getShutterState", &getShutterState, boolFunctionPIntType, "Get the Shutter state.", "Shutter State", ""},
            {"getShutterCommandState", &getShutterCommandState, boolFunctionPIntType, "Get the 3G Modem SMS state.", "SMS State", ""},
			// Shock
            {"setShockSensorRange", &setShockSensorRange, boolFunctionIntType, "set the sensor range sensitivity to either 2G, 4G or 8G (default).",NULL, "  Usage: --setShockSensorRange=<value>, allowed values = 2, 4 or 8"},
            {"getShockSensorRange", &getShockSensorRange, boolFunctionPIntType, "set the sensor range sensitivity, it will be 2G, 4G or 8G .", "Shock Sensor Range", ""},
            {"setShockDuration", &setShockDuration, boolFunctionIntType, "set the sensor set the shock sensing  period duration.", NULL, "  Usage: --setShockDuration=<value>, range 0-255"},
            {"getShockDuration", &getShockDuration, boolFunctionPIntType, "get the sensor set the shock sensing  period duration.", "Shock Sensor Duration", ""},
            {"setShockThresholdLevel", &setShockThresholdLevel, boolFunctionIntType, "set the sensor set the shock sensing threshold level.", NULL, "  Usage: --setShockThresholdLevel=<value>, range 0-127"},
            {"getShockThresholdLevel", &getShockThresholdLevel, boolFunctionPIntType, "get the sensor set the shock sensing  threshold level.", "Shock Sensor Threshold", ""},
            {"getShockAlarmState", &getShockAlarmState, boolFunctionPIntType, "to get an alarm raised when any shock exceeding the set duration and threshold occurs.", "Shock Alarm State", ""},
            {"getTimeSinceLastShockAlarm", &getTimeSinceLastShockAlarm, boolFunctionPWordType, "Get the time since the last shock occured.", "Time Since Last shock alarm", ""},
			{"resetShockAlarm", &resetShockAlarm, boolFunctionVoidType, "resets the shock alarm", NULL, ""},
			{"setShockShutdownOn", &setShockShutdownOn, boolFunctionVoidType, "Allows the Unit to shutdown if it receives a shock", NULL, ""},
			{"setShockShutdownOff", &setShockShutdownOff, boolFunctionVoidType, "Stops the Unit from shutting shutdown if it receives a shock", NULL, ""},
            {"setShockShutdownPeriod", &setShockShutdownPeriod, boolFunctionIntType, "set how many seconds the unit stays off for after receiveing a shock.", NULL, "  Usage: --setShockShutdownPeriod=<value>, range 0-65535"},
            {"getShockShutdownPeriod", &getShockShutdownPeriod, boolFunctionPIntType, "get the number of seconds that has been set for the unit to stay off after a shock.", "Shock Shut down Period = Seconds", ""},

            {"getCCCodeVersion", &getCCCodeVersion, boolFunctionPIntPIntType, "Get the code version of the CC1110.", "CC1110 Code Version", ""},
			{"setTX125kHzState", &setTX125kHzState, boolFunctionIntType, "set 125Khz frequency, 0 = 126.214kHz, 1 = 123.810kHz, 2 = 125kHz",NULL, "  Usage: --setTX125kHzState=<value>, allowed values = 0, 1 or 2"},
			{"setTX125kHzOn", &setTX125kHzOn, boolFunctionVoidType, "Turns on the 125kHz Generator", NULL, ""},
			{"setTX125kHzOff", &setTX125kHzOff, boolFunctionVoidType, "Turns off the 125kHz Generator", NULL, ""},
			{"setXYZSequence", &setXYZSequence, boolFunctionIntType, "set XYZ sequence, 0=ALL Off, 1=Z On, 2=Y on, 4=X on, 3=YZ sequence, 5=XZ sequence, 6=XY sequence, 7 = xyz sequence", NULL, "  Usage: --setXYZSequence=<value>, allowed values = 0 to 7"},
			{"setXYZSequenceRate", &setXYZSequenceRate, boolFunctionIntType, "set the number of millisconds between XYZ sequence changes",NULL, "  Usage: --setXYZSequenceRate=<value>, allowed values = 0-255 milliseconds"},
			{"setTX125kHzGain", &setTX125kHzGain, boolFunctionIntType, "set the gain level on the 125kHz signal",NULL, "  Usage: --setTX125kHzGain=<value>, allowed values = 0-128"},
            {"getTX125kHzGain", &getTX125kHzGain, boolFunctionPIntType, "get the gain level on the 125kHz signal.", "Gain Level", ""},
			{"setRXDetectionOn", &setRXDetectionOn, boolFunctionVoidType, "Turns on the Receiver Detector Circuit", NULL, ""},
			{"setRXLimiterOn", &setRXLimiterOn, boolFunctionVoidType, "Turns on the Receiver Limiter Circuit", NULL, ""},
			{"setRXSW1On", &setRXSW1On, boolFunctionVoidType, "Turns on the power to receiver circuit", NULL, ""},
			{"setRXSW1Off", &setRXSW1Off, boolFunctionVoidType, "Turns off the power to the receiver circuit", NULL, ""},
			{"setRadioOff", &setRadioOff, boolFunctionVoidType, "Sets the 868Mhz Radio into the idle state", NULL, ""},
			{"setRadioOn", &setRadioOn, boolFunctionVoidType, "Sets the 868Mhz Radio into the transmitting state", NULL, ""},
			{"setRFChannel", &setRFChannel, boolFunctionIntType, "set the 25kHz channel Number on the 868Mhz band Radio",NULL, "  Usage: --setRFChannel=<value>, allowed values = 0-31"},
	 		{"setTagID", &setTagID, boolFunctionIntType, "set the Tags Identification Number",NULL, "  Usage: --setTagID=<value>, allowed values = 0-2047"},
            {"getTagID", &getTagID, boolFunctionPIntType, "get the identification mumber of the Tag.", "Tag Identification No", ""},
          	{"getRegistrationEvent", &getRegistrationEvent, boolSpecialGetRegistrationType, "gets Tag ID, Registration Type, BattteryStateOK ", "Tag Registration Event", ""},
*/
           {NULL, NULL,0}
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
					"/dev/ttyS0"
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
					"/dev/ttyS0"
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
            fprintf(stderr,"call %s(%s)\n",functionName,parameters);
        }
        else if (sscanf(argv[argc], "--%s", functionName)==1)
        {
            fprintf(stderr,"call %s()\n",functionName);
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
/*                    case boolFunctionPIntPResetCauseType:
                        {
                            int param1;
                            ResetCause param2;
                            isOk = (*((boolFunctionPIntPResetCause)thingy->functionPointer))(&param1, &param2) && isOk;

							if (!isOk)
								break;

							if (param1 == 101)
                            {
                                fprintf(stdout, "%d%s", -1, separator);
                                break;
                            }
                            if (strcmp(outputMode, "NUMERIC") == 0)
                            {
                                char * translation = translate(functionName, param1);
                                if ((translation != NULL) && (strcmp(separator, ",") == 0))
                                   fprintf(stdout, "%d%s\"%s\"%s", param1, separator, translation, separator);
                                else
                                   fprintf(stdout, "%d%s%d%s", param1, separator, param2, separator);
                            }
                            else if ((strcmp(outputMode, "TEXT") == 0) && (strcmp(separator, ",") == 0))
                            {
                                char * translation = translate(functionName, param1);
                                if (translation != NULL)
                                    fprintf(stdout, "%d%s\"%s\"%s", param1, separator, translation, separator);
                                else
                                    fprintf(stdout, "%d%s", param1, separator);
                            }
                            else
                            {
                                char * translation = translate(functionName, param1);
                                if (translation != NULL)
                                    fprintf(stdout, "%s => %d\nLast cause of reset => %s\n", thingy->textual, param1, translation);
                                else
                                    fprintf(stdout, "%s => %d\n%s => %d\n", thingy->textual, param1, thingy->textual, param2);
                            }
                        }
                        break;
  */					case boolFunctionPStringIntType:
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
												   BYTE byteString[6] = { 1,2 ,3 ,4 ,5 ,6 };
//						char p[20];
//						int i; 
						bool err = false;

/*						stncpy( p, parameters, 12);

						for (i = 0; i < 6; i ++)
						{
							p = parameters + (2*i);
							if (sscanf_s( p, "%d", &byteString[i], 2) != 1)
							{
								err = true;
								break;
							}
						}
	*/					
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
