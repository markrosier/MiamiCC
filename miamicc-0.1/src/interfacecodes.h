#ifndef _inc_interfacecodes
#define _inc_interfacecodes
// ---------------------------------------------------------------------
// Module Name: INTERFACECODES.H
// Module Type: Include File
//
// Purpose:     This file contains Command/Response Codes Which Are
//		common to both Firmware and PC Interface
//					
// ---------------------------------------------------------------------

// --------------
// Constants
// --------------

#ifndef BAUD_19200
#define BAUDRATE                        115200
#else
#define BAUDRATE                        19200
#endif

// ---
// Packet Structure Constants
// ---
#define MAX_PACKET_SIZE                 14
#define MAX_EXTENDED_PACKET_SIZE        256
#define MAX_DDAPI_PACKET_SIZE           11
#define MAX_PTCM_PACKET_SIZE						14
#define PAL_BYTE												0x00
#define OPCODE_BYTE											0x01
#define EXTENDED_PACKET_LENGTH_BYTE     0x02
#define PACKET_TIMEOUT 									1000

// ---
// Packet Source
// ---
#define PTCM_PACKET_ID 									0x50
#define DDAPI_PACKET_ID 								0xA0

#define EXTENDED_PACKET_ID              0x00

// ---
// Protocol Application Link Byte, (PAL)
// This is equal to the Packet Sourcer or'd with the length of the packet.
// Note that the packet length can never exceed 15 bytes, (i.e. lower four
// bits of the PAL indicates the length of the packet).
// ---

// Commands from DD Application Programmers Interface to the PTCM Firmware

// ---
// DDAPI PAL's 
// ---

//  Request Functions from Host to Controller PacketID (A0) + PacketLength
// First Byte of Packet
#define DDAPI_PAL_active                              DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getCodeVersion                      DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_enterBootLoader                     DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getLINProductID                     DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getLINProductSN                     DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_assignFrameIDRange                  DDAPI_PACKET_ID + 0x08
#define DDAPI_PAL_assignNAD                           DDAPI_PACKET_ID + 0x08
#define DDAPI_PAL_conditionalChangeNAD                DDAPI_PACKET_ID + 0x08
#define DDAPI_PAL_dataDump                            DDAPI_PACKET_ID + 0x08
#define DDAPI_PAL_saveConfiguration                   DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setSpaceHeaterMode                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getSpaceHeaterBurnerStatus          DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getSpaceHeaterErrorStatus           DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_setSpaceHeaterPowerLED              DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setWaterHeaterMode                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getWaterHeaterBurnerStatus          DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getWaterHeaterErrorStatus           DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_setWaterHeaterPowerLED              DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setPDUPowerSource                   DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getIgnitionSignal                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_get230VPresentSignal                DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getLeisureBatteryVoltage            DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getVehicleBatteryVoltage            DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getLoadCurrent                      DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_setFridgetoSystemRelay              DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setOutput1                          DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setOutput2                          DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setOutput3                          DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getOutputOverloadState              DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getPositiveInput1                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getPositiveInput2                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getNegativeInput1                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getADCInput1                        DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getADCInput2                        DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_setHexnode1Output1                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode1Output2                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode1Output3                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode1Output4                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode1Output5                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode1Output6                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getHexnode1OutputOverloadStatus     DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode1Input1                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode1Input2                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode1Input3                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode1Input4                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode1ADCInput5                DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode1ADCInput6                DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_setHexnode2Output1                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode2Output2                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode2Output3                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode2Output4                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode2Output5                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode2Output6                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getHexnode2OutputOverloadStatus     DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode2Input1                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode2Input2                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode2Input3                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode2Input4                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode2ADCInput5                DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode2ADCInput6                DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_setHexnode3Output1                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode3Output2                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode3Output3                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode3Output4                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode3Output5                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode3Output6                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getHexnode3OutputOverloadStatus     DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode3Input1                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode3Input2                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode3Input3                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode3Input4                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode3ADCInput5                DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode3ADCInput6                DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_setHexnode4Output1                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode4Output2                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode4Output3                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode4Output4                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode4Output5                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_setHexnode4Output6                  DDAPI_PACKET_ID + 0x03
#define DDAPI_PAL_getHexnode4OutputOverloadStatus     DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode4Input1                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode4Input2                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode4Input3                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode4Input4                   DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode4ADCInput5                DDAPI_PACKET_ID + 0x02
#define DDAPI_PAL_getHexnode4ADCInput6                DDAPI_PACKET_ID + 0x02

// ---
// DDAPI Opcodes (2nd Byte of Packet)
// ---
#define DDAPI_OPCODE_active                           0x00
#define DDAPI_OPCODE_getCodeVersion                   0x01
#define DDAPI_OPCODE_enterBootLoader                  0x02
#define DDAPI_OPCODE_getLINProductID                  0x03
#define DDAPI_OPCODE_getLINProductSN                  0x04
#define DDAPI_OPCODE_assignFrameIDRange               0x05
#define DDAPI_OPCODE_assignNAD                        0x06
#define DDAPI_OPCODE_conditionalChangeNAD             0x07
#define DDAPI_OPCODE_dataDump                         0x08
#define DDAPI_OPCODE_saveConfiguration                0x09
#define DDAPI_OPCODE_setSpaceHeaterMode               0x10
#define DDAPI_OPCODE_getSpaceHeaterBurnerStatus       0x11
#define DDAPI_OPCODE_getSpaceHeaterErrorStatus        0x12
#define DDAPI_OPCODE_setSpaceHeaterPowerLED           0x13
#define DDAPI_OPCODE_setWaterHeaterMode               0x20
#define DDAPI_OPCODE_getWaterHeaterBurnerStatus	      0x21
#define DDAPI_OPCODE_getWaterHeaterErrorStatus	      0x22
#define DDAPI_OPCODE_setWaterHeaterPowerLED           0x23
#define DDAPI_OPCODE_setPDUPowerSource                0x30
#define DDAPI_OPCODE_getIgnitionSignal              	0x31
#define DDAPI_OPCODE_get230VPresentSignal             0x32
#define DDAPI_OPCODE_getLeisureBatteryVoltage         0x33
#define DDAPI_OPCODE_getVehicleBatteryVoltage         0x34
#define DDAPI_OPCODE_getLoadCurrent                   0x35
#define DDAPI_OPCODE_setFridgetoSystemRelay           0x36
#define DDAPI_OPCODE_setOutput1                       0x37
#define DDAPI_OPCODE_setOutput2                       0x38
#define DDAPI_OPCODE_setOutput3                       0x39
#define DDAPI_OPCODE_getOutputOverloadState           0x3a
#define DDAPI_OPCODE_getPositiveInput1                0x3b
#define DDAPI_OPCODE_getPositiveInput2                0x3c
#define DDAPI_OPCODE_getNegativeInput1                0x3d
#define DDAPI_OPCODE_getADCInput1                     0x3e
#define DDAPI_OPCODE_getADCInput2                     0x3f
#define DDAPI_OPCODE_setHexnode1Output1               0x40
#define DDAPI_OPCODE_setHexnode1Output2               0x41
#define DDAPI_OPCODE_setHexnode1Output3               0x42
#define DDAPI_OPCODE_setHexnode1Output4               0x43
#define DDAPI_OPCODE_setHexnode1Output5               0x44
#define DDAPI_OPCODE_setHexnode1Output6               0x45
#define DDAPI_OPCODE_getHexnode1OutputOverloadStatus  0x46
#define DDAPI_OPCODE_getHexnode1Input1                0x47
#define DDAPI_OPCODE_getHexnode1Input2                0x48
#define DDAPI_OPCODE_getHexnode1Input3                0x49
#define DDAPI_OPCODE_getHexnode1Input4                0x4a
#define DDAPI_OPCODE_getHexnode1ADCInput5             0x4b
#define DDAPI_OPCODE_getHexnode1ADCInput6             0x4c
#define DDAPI_OPCODE_setHexnode2Output1               0x60
#define DDAPI_OPCODE_setHexnode2Output2               0x61
#define DDAPI_OPCODE_setHexnode2Output3               0x62
#define DDAPI_OPCODE_setHexnode2Output4               0x63
#define DDAPI_OPCODE_setHexnode2Output5               0x64
#define DDAPI_OPCODE_setHexnode2Output6               0x65
#define DDAPI_OPCODE_getHexnode2OutputOverloadStatus  0x66
#define DDAPI_OPCODE_getHexnode2Input1                0x67
#define DDAPI_OPCODE_getHexnode2Input2                0x68
#define DDAPI_OPCODE_getHexnode2Input3                0x69
#define DDAPI_OPCODE_getHexnode2Input4                0x6a
#define DDAPI_OPCODE_getHexnode2ADCInput5             0x6b
#define DDAPI_OPCODE_getHexnode2ADCInput6             0x6c
#define DDAPI_OPCODE_setHexnode3Output1               0x80
#define DDAPI_OPCODE_setHexnode3Output2               0x81
#define DDAPI_OPCODE_setHexnode3Output3               0x82
#define DDAPI_OPCODE_setHexnode3Output4               0x83
#define DDAPI_OPCODE_setHexnode3Output5               0x84
#define DDAPI_OPCODE_setHexnode3Output6               0x85
#define DDAPI_OPCODE_getHexnode3OutputOverloadStatus  0x86
#define DDAPI_OPCODE_getHexnode3Input1                0x87
#define DDAPI_OPCODE_getHexnode3Input2                0x88
#define DDAPI_OPCODE_getHexnode3Input3                0x89
#define DDAPI_OPCODE_getHexnode3Input4                0x8a
#define DDAPI_OPCODE_getHexnode3ADCInput5             0x8b
#define DDAPI_OPCODE_getHexnode3ADCInput6             0x8c
#define DDAPI_OPCODE_setHexnode4Output1               0xa0
#define DDAPI_OPCODE_setHexnode4Output2               0xa1
#define DDAPI_OPCODE_setHexnode4Output3               0xa2
#define DDAPI_OPCODE_setHexnode4Output4               0xa3
#define DDAPI_OPCODE_setHexnode4Output5               0xa4
#define DDAPI_OPCODE_setHexnode4Output6               0xa5
#define DDAPI_OPCODE_getHexnode4OutputOverloadStatus  0xa6
#define DDAPI_OPCODE_getHexnode4Input1                0xa7
#define DDAPI_OPCODE_getHexnode4Input2                0xa8
#define DDAPI_OPCODE_getHexnode4Input3                0xa9
#define DDAPI_OPCODE_getHexnode4Input4                0xaa
#define DDAPI_OPCODE_getHexnode4ADCInput5             0xab
#define DDAPI_OPCODE_getHexnode4ADCInput6             0xac


// ---
// PTCM PAL's  (PTCM is a historic term but actually means Controller)
// ---

// response packet lengths

#define ACK_PACKET_LENGTH                                  0x02
#define NAK_PACKET_LENGTH                                  0x02

#define active_PACKET_LENGTH                               0x02
#define getCodeVersion_PACKET_LENGTH                       0x04
#define getLINProductID_PACKET_LENGTH                      0x07
#define getLINProductSN_PACKET_LENGTH                      0x06
#define dataDump_PACKET_LENGTH                             0x08
#define getSpaceHeaterBurnerStatus_PACKET_LENGTH           0x03
#define getSpaceHeaterErrorStatus_PACKET_LENGTH            0x03
#define getWaterHeaterBurnerStatus_PACKET_LENGTH           0x03
#define getWaterHeaterErrorStatus_PACKET_LENGTH            0x03
#define getIgnitionSignal_PACKET_LENGTH                    0x03
#define get230VPresentSignal_PACKET_LENGTH                 0x03
#define getLeisureBatteryVoltage_PACKET_LENGTH             0x03
#define getVehicleBatteryVoltage_PACKET_LENGTH             0x03
#define getLoadCurrent_PACKET_LENGTH                       0x03
#define getOutputOverloadState_PACKET_LENGTH               0x05
#define getPositiveInput1_PACKET_LENGTH                    0x03
#define getPositiveInput2_PACKET_LENGTH                    0x03
#define getNegativeInput1_PACKET_LENGTH                    0x03
#define getADCInput1_PACKET_LENGTH                         0x04
#define getADCInput2_PACKET_LENGTH                         0x04
#define getHexnode1OutputOverloadStatus_PACKET_LENGTH      0x08
#define getHexnode1Input1_PACKET_LENGTH                    0x03
#define getHexnode1Input2_PACKET_LENGTH                    0x03
#define getHexnode1Input3_PACKET_LENGTH                    0x03
#define getHexnode1Input4_PACKET_LENGTH                    0x03
#define getHexnode1ADCInput5_PACKET_LENGTH                 0x04
#define getHexnode1ADCInput6_PACKET_LENGTH                 0x04
#define getHexnode2OutputOverloadStatus_PACKET_LENGTH      0x08
#define getHexnode2Input1_PACKET_LENGTH                    0x03
#define getHexnode2Input2_PACKET_LENGTH                    0x03
#define getHexnode2Input3_PACKET_LENGTH                    0x03
#define getHexnode2Input4_PACKET_LENGTH                    0x03
#define getHexnode2ADCInput5_PACKET_LENGTH                 0x04
#define getHexnode2ADCInput6_PACKET_LENGTH                 0x04
#define getHexnode3OutputOverloadStatus_PACKET_LENGTH      0x08
#define getHexnode3Input1_PACKET_LENGTH                    0x03
#define getHexnode3Input2_PACKET_LENGTH                    0x03
#define getHexnode3Input3_PACKET_LENGTH                    0x03
#define getHexnode3Input4_PACKET_LENGTH                    0x03
#define getHexnode3ADCInput5_PACKET_LENGTH                 0x04
#define getHexnode3ADCInput6_PACKET_LENGTH                 0x04
#define getHexnode4OutputOverloadStatus_PACKET_LENGTH      0x08
#define getHexnode4Input1_PACKET_LENGTH                    0x03
#define getHexnode4Input2_PACKET_LENGTH                    0x03
#define getHexnode4Input3_PACKET_LENGTH                    0x03
#define getHexnode4Input4_PACKET_LENGTH                    0x03
#define getHexnode4ADCInput5_PACKET_LENGTH                 0x04
#define getHexnode4ADCInput6_PACKET_LENGTH                 0x04




//  Responses from Controller to Host PacketID (50) + PacketLength
//  First Byte

#define PTCM_PAL_ACK                                  PTCM_PACKET_ID + ACK_PACKET_LENGTH
#define PTCM_PAL_NAK                                  PTCM_PACKET_ID + NAK_PACKET_LENGTH

#define PTCM_PAL_active                               PTCM_PACKET_ID + active_PACKET_LENGTH
#define PTCM_PAL_getCodeVersion                       PTCM_PACKET_ID + getCodeVersion_PACKET_LENGTH
#define PTCM_PAL_getLINProductID                      PTCM_PACKET_ID + getLINProductID_PACKET_LENGTH
#define PTCM_PAL_getLINProductSN                      PTCM_PACKET_ID + getLINProductSN_PACKET_LENGTH
#define PTCM_PAL_dataDump                             PTCM_PACKET_ID + dataDump_PACKET_LENGTH
#define PTCM_PAL_getSpaceHeaterBurnerStatus           PTCM_PACKET_ID + getSpaceHeaterBurnerStatus_PACKET_LENGTH
#define PTCM_PAL_getSpaceHeaterErrorStatus            PTCM_PACKET_ID + getSpaceHeaterErrorStatus_PACKET_LENGTH
#define PTCM_PAL_getWaterHeaterBurnerStatus           PTCM_PACKET_ID + getWaterHeaterBurnerStatus_PACKET_LENGTH
#define PTCM_PAL_getWaterHeaterErrorStatus            PTCM_PACKET_ID + getWaterHeaterErrorStatus_PACKET_LENGTH
#define PTCM_PAL_getIgnitionSignal                    PTCM_PACKET_ID + getIgnitionSignal_PACKET_LENGTH
#define PTCM_PAL_get230VPresentSignal                 PTCM_PACKET_ID + get230VPresentSignal_PACKET_LENGTH
#define PTCM_PAL_getLeisureBatteryVoltage             PTCM_PACKET_ID + getLeisureBatteryVoltage_PACKET_LENGTH
#define PTCM_PAL_getVehicleBatteryVoltage             PTCM_PACKET_ID + getVehicleBatteryVoltage_PACKET_LENGTH
#define PTCM_PAL_getLoadCurrent                       PTCM_PACKET_ID + getLoadCurrent_PACKET_LENGTH
#define PTCM_PAL_getOutputOverloadState               PTCM_PACKET_ID + getOutputOverloadState_PACKET_LENGTH
#define PTCM_PAL_getPositiveInput1                    PTCM_PACKET_ID + getPositiveInput1_PACKET_LENGTH
#define PTCM_PAL_getPositiveInput2                    PTCM_PACKET_ID + getPositiveInput2_PACKET_LENGTH
#define PTCM_PAL_getNegativeInput1                    PTCM_PACKET_ID + getNegativeInput1_PACKET_LENGTH
#define PTCM_PAL_getADCInput1                         PTCM_PACKET_ID + getADCInput1_PACKET_LENGTH
#define PTCM_PAL_getADCInput2                         PTCM_PACKET_ID + getADCInput2_PACKET_LENGTH
#define PTCM_PAL_getHexnode1OutputOverloadStatus      PTCM_PACKET_ID + getHexnode1OutputOverloadStatus_PACKET_LENGTH
#define PTCM_PAL_getHexnode1Input1                    PTCM_PACKET_ID + getHexnode1Input1_PACKET_LENGTH
#define PTCM_PAL_getHexnode1Input2                    PTCM_PACKET_ID + getHexnode1Input2_PACKET_LENGTH
#define PTCM_PAL_getHexnode1Input3                    PTCM_PACKET_ID + getHexnode1Input3_PACKET_LENGTH
#define PTCM_PAL_getHexnode1Input4                    PTCM_PACKET_ID + getHexnode1Input4_PACKET_LENGTH
#define PTCM_PAL_getHexnode1ADCInput5                 PTCM_PACKET_ID + getHexnode1ADCInput5_PACKET_LENGTH
#define PTCM_PAL_getHexnode1ADCInput6                 PTCM_PACKET_ID + getHexnode1ADCInput6_PACKET_LENGTH
#define PTCM_PAL_getHexnode2OutputOverloadStatus      PTCM_PACKET_ID + getHexnode2OutputOverloadStatus_PACKET_LENGTH
#define PTCM_PAL_getHexnode2Input1                    PTCM_PACKET_ID + getHexnode2Input1_PACKET_LENGTH
#define PTCM_PAL_getHexnode2Input2                    PTCM_PACKET_ID + getHexnode2Input2_PACKET_LENGTH
#define PTCM_PAL_getHexnode2Input3                    PTCM_PACKET_ID + getHexnode2Input3_PACKET_LENGTH
#define PTCM_PAL_getHexnode2Input4                    PTCM_PACKET_ID + getHexnode2Input4_PACKET_LENGTH
#define PTCM_PAL_getHexnode2ADCInput5                 PTCM_PACKET_ID + getHexnode2ADCInput5_PACKET_LENGTH
#define PTCM_PAL_getHexnode2ADCInput6                 PTCM_PACKET_ID + getHexnode2ADCInput6_PACKET_LENGTH
#define PTCM_PAL_getHexnode3OutputOverloadStatus      PTCM_PACKET_ID + getHexnode3OutputOverloadStatus_PACKET_LENGTH
#define PTCM_PAL_getHexnode3Input1                    PTCM_PACKET_ID + getHexnode3Input1_PACKET_LENGTH
#define PTCM_PAL_getHexnode3Input2                    PTCM_PACKET_ID + getHexnode3Input2_PACKET_LENGTH
#define PTCM_PAL_getHexnode3Input3                    PTCM_PACKET_ID + getHexnode3Input3_PACKET_LENGTH
#define PTCM_PAL_getHexnode3Input4                    PTCM_PACKET_ID + getHexnode3Input4_PACKET_LENGTH
#define PTCM_PAL_getHexnode3ADCInput5                 PTCM_PACKET_ID + getHexnode3ADCInput5_PACKET_LENGTH
#define PTCM_PAL_getHexnode3ADCInput6                 PTCM_PACKET_ID + getHexnode3ADCInput6_PACKET_LENGTH
#define PTCM_PAL_getHexnode4OutputOverloadStatus      PTCM_PACKET_ID + getHexnode4OutputOverloadStatus_PACKET_LENGTH
#define PTCM_PAL_getHexnode4Input1                    PTCM_PACKET_ID + getHexnode4Input1_PACKET_LENGTH
#define PTCM_PAL_getHexnode4Input2                    PTCM_PACKET_ID + getHexnode4Input2_PACKET_LENGTH
#define PTCM_PAL_getHexnode4Input3                    PTCM_PACKET_ID + getHexnode4Input3_PACKET_LENGTH
#define PTCM_PAL_getHexnode4Input4                    PTCM_PACKET_ID + getHexnode4Input4_PACKET_LENGTH
#define PTCM_PAL_getHexnode4ADCInput5                 PTCM_PACKET_ID + getHexnode4ADCInput5_PACKET_LENGTH
#define PTCM_PAL_getHexnode4ADCInput6                 PTCM_PACKET_ID + getHexnode4ADCInput6_PACKET_LENGTH

// ---
// PTCM RETCODES defines the function it is responding to (2nd Byte of Packet)
// ---
#define PTCM_RETCODE_ACK                              0xfe
#define PTCM_RETCODE_NAK                              0xff

#define PTCM_RETCODE_active                           0x00
#define PTCM_RETCODE_getCodeVersion                   0x01
#define PTCM_RETCODE_getLINProductID                  0x03
#define PTCM_RETCODE_getLINProductSN                  0x04
#define PTCM_RETCODE_dataDump                         0x08
#define PTCM_RETCODE_getSpaceHeaterBurnerStatus       0x11
#define PTCM_RETCODE_getSpaceHeaterErrorStatus        0x12
#define PTCM_RETCODE_getWaterHeaterBurnerStatus       0x22
#define PTCM_RETCODE_getWaterHeaterErrorStatus        0x23
#define PTCM_RETCODE_getIgnitionSignal                0x31
#define PTCM_RETCODE_get230VPresentSignal             0x32
#define PTCM_RETCODE_getLeisureBatteryVoltage         0x33
#define PTCM_RETCODE_getVehicleBatteryVoltage         0x34
#define PTCM_RETCODE_getLoadCurrent                   0x35
#define PTCM_RETCODE_getOutputOverloadState           0x3a
#define PTCM_RETCODE_getPositiveInput1                0x3b
#define PTCM_RETCODE_getPositiveInput2                0x3c
#define PTCM_RETCODE_getNegativeInput1                0x3d
#define PTCM_RETCODE_getADCInput1                     0x3e
#define PTCM_RETCODE_getADCInput2                     0x3f
#define PTCM_RETCODE_getHexnode1OutputOverloadStatus  0x46
#define PTCM_RETCODE_getHexnode1Input1                0x47
#define PTCM_RETCODE_getHexnode1Input2                0x48
#define PTCM_RETCODE_getHexnode1Input3                0x49
#define PTCM_RETCODE_getHexnode1Input4                0x4a
#define PTCM_RETCODE_getHexnode1ADCInput5             0x4b
#define PTCM_RETCODE_getHexnode1ADCInput6             0x4c
#define PTCM_RETCODE_getHexnode2OutputOverloadStatus  0x66
#define PTCM_RETCODE_getHexnode2Input1                0x67
#define PTCM_RETCODE_getHexnode2Input2                0x68
#define PTCM_RETCODE_getHexnode2Input3                0x69
#define PTCM_RETCODE_getHexnode2Input4                0x6a
#define PTCM_RETCODE_getHexnode2ADCInput5             0x6b
#define PTCM_RETCODE_getHexnode2ADCInput6             0x6c
#define PTCM_RETCODE_getHexnode3OutputOverloadStatus  0x86
#define PTCM_RETCODE_getHexnode3Input1                0x87
#define PTCM_RETCODE_getHexnode3Input2                0x88
#define PTCM_RETCODE_getHexnode3Input3                0x89
#define PTCM_RETCODE_getHexnode3Input4                0x8a
#define PTCM_RETCODE_getHexnode3ADCInput5             0x8b
#define PTCM_RETCODE_getHexnode3ADCInput6             0x8c
#define PTCM_RETCODE_getHexnode4OutputOverloadStatus  0xa6
#define PTCM_RETCODE_getHexnode4Input1                0xa7
#define PTCM_RETCODE_getHexnode4Input2                0xa8
#define PTCM_RETCODE_getHexnode4Input3                0xa9
#define PTCM_RETCODE_getHexnode4Input4                0xaa
#define PTCM_RETCODE_getHexnode4ADCInput5             0xab
#define PTCM_RETCODE_getHexnode4ADCInput6             0xac

#endif