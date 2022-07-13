#pragma once
#include "stdemace.h"

#define BUFSIZE 256
#define DevNum 8
#define ARC1_STATE 200
#define ARC2_STATE 201
#define RT1_ADDR 1
#define RT2_ADDR 2
#define AIU_ADDR 3
#define SET_ICS_DISCRETE 3000
#define TID_COMSEC_COM2 0x7701
#define TID_COMSEC_COM3 0x7702

#define MAX_WORD 64
#define TESTBUF 6

#define BC_BUS_A 1
#define BC_BUS_B 2

#define MWOD_LOAD 1002
#define MWOD_LOAD_2 1003
#define FMT_NET_LOAD 1004
#define FMT_NET_LOAD_2 1005
#define PRESET_LOAD 1006
#define PRESET_LOAD_2 1007

#define MWOD_STATUS 2002
#define MWOD_STATUS_2 2003
#define PRESET_STATUS 2004
#define PRESET_STATUS_2 2005
#define BIT_SUMMARY_STATUS 2006
#define BIT_SUMMARY_STATUS_2 2007
#define FAULT_DATA_STATUS 2008

#define IBIT 3001
#define WARNIG_RST 3002

class CBIT_FIELD
{
public:
    CBIT_FIELD(void);
    ~CBIT_FIELD(void);
};

/* Function Control */

struct PRESET_SELECT
{
    U16BIT Reserved : 4;
    U16BIT MemoryManagement : 4;
    U16BIT ChannelNumber : 8;
};

union UNION_PRESET_SELECT
{
    struct PRESET_SELECT st_PRESET_SELECT;
    WORD w_PRESET_SELECT;
};


struct MODE_AND_GUARD
{
    U16BIT Reserved3 : 9;
    U16BIT Reserved2 : 1;
    U16BIT Reserved1 : 1;
    U16BIT GuardReceiver : 1;
    U16BIT XMode : 1;
    U16BIT ADF : 1;
    U16BIT Modulation : 2;
};

union UNION_MODE_AND_GUARD
{
    struct MODE_AND_GUARD st_MODE_AND_GUARD;
    WORD w_MODE_AND_GUARD;
};


struct MARITIME_CHANNEL{
    U16BIT MaritimeChannel : 6;
    U16BIT ChannelSelect : 1;
    U16BIT Reserved : 8;
};

union UNION_MARITIME_CHANNEL
{
    struct MARITIME_CHANNEL st_MARITIME_CHANNEL;
    WORD w_MARITIME_CHANNEL;
};


struct FREQUENCY{
    U16BIT TenthsDigit : 4;
    U16BIT OnesDigit : 4;
    U16BIT TensDigit : 4;
    U16BIT HundredsDigit : 4;

};

union UNION_FREQUENCY
{
    struct FREQUENCY st_FREQUENCY;
    WORD w_FREQUENCY;
};


struct FINE_FREQUENCY_AND_AJ{
    U16BIT FrequncyManagement : 4;
    U16BIT Reserved : 4;
    U16BIT ThousandthsDigit : 4;
    U16BIT HundredthsDigit : 4;
};

union UNION_FINE_FREQUENCY_AND_AJ
{
    struct FINE_FREQUENCY_AND_AJ st_FINE_FREQUENCY_AND_AJ;
    WORD w_FINE_FREQUENCY_AND_AJ;
};


struct OPTIONS{
    U16BIT RFPower : 2;
    U16BIT Reserved4 : 3;
    U16BIT ToneKey : 1;
    U16BIT GuardSquelch : 1;
    U16BIT MainSquelch : 1;
    U16BIT Reserved3 : 2;
    U16BIT PresetData : 1;
    U16BIT Reserved2 : 1;
    U16BIT FMTData : 1;
    U16BIT WODData : 1;
    U16BIT Reserved1 : 1;
    U16BIT CompressorOption : 1;
};

union UNION_OPTIONS
{
    struct OPTIONS st_OPTIONS;
    WORD w_OPTIONS;
};


struct RESERVED_CONTROL{
    U16BIT Reserved : 16;
};

union UNION_RESERVED_CONTROL
{
    struct RESERVED_CONTROL st_RESERVED_CONTROL;
    WORD w_RESERVED_CONTROL;
};


/* MWOD Load */
struct WOD_SEGMENT{
    U16BIT HundredthsDigit : 2;
    U16BIT TenthsDigit : 4;
    U16BIT OnesDigit : 4;
    U16BIT TensDigit : 4;
    U16BIT HundredsDigit : 2;
};

union UNION_WOD_SEGMENT
{
    struct WOD_SEGMENT st_WOD_SEGMENT;
    WORD w_WOD_SEGMENT;
};


struct WOD_DAY{
    U16BIT HundredthsDigit : 2;
    U16BIT TenthsDigit : 4;
    U16BIT OnesDigit : 4;
    U16BIT TensDigit : 4;
    U16BIT HundredsDigit : 2;
};

union UNION_WOD_DAY
{
    struct WOD_DAY st_WOD_DAY;
    WORD w_WOD_DAY;
};


struct TEST{
    U16BIT E : 3;
    U16BIT D : 2;
    U16BIT C : 6;
    U16BIT B : 1;
    U16BIT A : 4;
};

union UNION_TEST
{
    struct TEST st_TEST;
    WORD w_TEST;
};


struct FMT_NET_FREQUENCY{
    U16BIT HundredthsDigit : 2;
    U16BIT TenthsDigit : 4;
    U16BIT OnesDigit : 4;
    U16BIT TensDigit : 4;
    U16BIT HundredsDigit : 2;
};

union UNION_FMT_NET_FREQUENCY
{
    struct FMT_NET_FREQUENCY st_FMT_NET_FREQUENCY;
    WORD w_FMT_NET_FREQUENCY;
};


struct TOD_MANAGEMENT{
    U16BIT DayOnesDigit : 4;
    U16BIT DayTensDigit : 2;
    U16BIT Reserved : 6;
    U16BIT TODManagement : 4;
};

union UNION_TOD_MANAGEMENT
{
    struct TOD_MANAGEMENT st_TOD_MANAGEMENT;
    WORD w_TOD_MANAGEMENT;
};


struct RESERVED{
    U16BIT Reserved : 16;
};

union UNION_RESERVED
{
    struct RESERVED st_RESERVED;
    WORD w_RESERVED;
};


struct PRESET_GROUP_SELECT{
    U16BIT Reserved : 12;
    U16BIT GroupSelect : 4;
};

union UNION_PRESET_GROUP_SELECT
{
    struct PRESET_GROUP_SELECT st_PRESET_GROUP_SELECT;
    WORD w_PRESET_GROUP_SELECT;
};


struct BIT_CONTROL{
    U16BIT Reserved : 15;
    U16BIT InitiateIBIT : 1;
};

union UNION_BIT_CONTROL
{
    struct BIT_CONTROL st_BIT_CONTROL;
    WORD w_BIT_CONTROL;
};


struct BIT_SUMMARY{
    U16BIT Reserved2 : 6;
    U16BIT LowBattery : 1;
    U16BIT HighTemperature : 1;
    U16BIT LowRFPower : 1;
    U16BIT HighVSWR : 1;
    U16BIT PowerRegulatorFault : 1;
    U16BIT InitiatedBITResult : 1;
    U16BIT Reserved1 : 1;
    U16BIT ControlData : 1;
    U16BIT LastestBIT : 2;
};

union UNION_BIT_SUMMARY{
    struct BIT_SUMMARY st_BIT_SUMMARY;
    WORD w_BIT_SUMMARY;
};


struct SOFTWARE_ID{
    U16BIT Reserved : 7;
    U16BIT CodeType : 1;
    U16BIT SoftwareRadioIdent : 8;
};

union UNION_SOFTWARE_ID
{
    struct SOFTWARE_ID st_SOFTWARE_ID;
    WORD w_SOFTWARE_ID;
};


struct SOFTWARE_VERSION{
    U16BIT SoftwareReversion : 8;
    U16BIT SoftwareVersion : 8;
};

union UNION_SOFTWARE_VERSION
{
    struct SOFTWARE_VERSION st_SOFTWARE_VERSION;
    WORD w_SOFTWARE_VERSION;
};


struct FAULT_LOCATION01{
    U16BIT SecondModule : 8;
    U16BIT FirstModule : 8;
};

union UNION_FAULT_LOCATION01
{
    struct FAULT_LOCATION01 st_FAULT_LOCATION01;
    WORD w_FAULT_LOCATION01;
};


struct FAULT_LOCATION02{
    U16BIT Reserved : 8;
    U16BIT ThirdModule : 8;
};

union UNION_FAULT_LOCATION02
{
    struct FAULT_LOCATION02 st_FAULT_LOCATION02;
    WORD w_FAULT_LOCATION01;
};

struct MWOD_LOAD_STATUS{
    U16BIT Reserved : 12;
    U16BIT ValidRange : 1;
    U16BIT DS102TRANSECParity : 1;
    U16BIT DS102PORT : 1;
};

union UNION_MWOD_LOAD_STATUS
{
    struct MWOD_LOAD_STATUS st_MWOD_LOAD_STATUS;
    WORD w_MWOD_LOAD_STATUS;
};


struct MWOD_A_AND_B_DAY{
    U16BIT MWODBDay1 : 4;
    U16BIT MWODBDay10 : 2;
    U16BIT Reserved2 : 2;
    U16BIT MWODADay1 : 4;
    U16BIT MWODADay10 : 2;
    U16BIT Reserved1 : 2;
};

union UNION_MWOD_A_AND_B_DAY
{
    struct MWOD_A_AND_B_DAY st_MWOD_A_AND_B_DAY;
    WORD w_MWOD_A_AND_B_DAY;
};


struct FMT_NET_LOAD_STATUS{
    U16BIT Reserved : 15;
    U16BIT FreqLimits : 1;
};

union UNION_FMT_NET_LOAD_STATUS
{
    struct FMT_NET_LOAD_STATUS st_FMT_NET_LOAD_STATUS;
    WORD w_FMT_NET_LOAD_STATUS;
};


struct ICS_CONTROL1{
    U16BIT Reserved10 : 1;
    U16BIT Reserved9 : 1;
    U16BIT Reserved8 : 1;
    U16BIT Reserved7 : 1;
    U16BIT Reserved6 : 1;
    U16BIT Reserved5 : 1;
    U16BIT Reserved4 : 1;
    U16BIT Reserved3 : 1;
    U16BIT Reserved2 : 1;
    U16BIT Reserved1 : 1;
    U16BIT WeightOnWheelState : 1;
    U16BIT SelectedRadioForCopilot : 2;
    U16BIT SelectedRadioForPilot : 2;
    U16BIT BITInitiate : 1;
};

union UNION_ICS_CONTROL1
{
    struct ICS_CONTROL1 st_ICS_CONTROL1;
    WORD w_ICS_CONTROL1;
};


struct ICS_CONTROL2{
    U16BIT Reserved15 : 1;
    U16BIT Reserved14 : 1;
    U16BIT Reserved13 : 1;
    U16BIT Reserved12 : 1;
    U16BIT Reserved11 : 1;
    U16BIT Reserved10 : 1;
    U16BIT Reserved9 : 1;
    U16BIT Reserved8 : 1;
    U16BIT Reserved7 : 1;
    U16BIT Reserved6 : 1;
    U16BIT Reserved5 : 1;
    U16BIT Reserved4 : 1;
    U16BIT Reserved3 : 1;
    U16BIT Reserved2 : 1;
    U16BIT Reserved1 : 1;
    U16BIT ClearCurrentVoiceWarning : 1;
};

union UNION_ICS_CONTROL2
{
    struct ICS_CONTROL2 st_ICS_CONTROL2;
    WORD w_ICS_CONTROL2;
};


struct ICS_CONTROL3{
    U16BIT Reserved17 : 1;
    U16BIT Reserved15 : 1;
    U16BIT Reserved14 : 1;
    U16BIT Reserved13 : 1;
    U16BIT Reserved12 : 1;
    U16BIT Reserved11 : 1;
    U16BIT Reserved10 : 1;
    U16BIT Reserved9 : 1;
    U16BIT Reserved8 : 1;
    U16BIT Reserved7 : 1;
    U16BIT Reserved6 : 1;
    U16BIT Reserved5 : 1;
    U16BIT Reserved4 : 1;
    U16BIT Reserved3 : 1;
    U16BIT Reserved2 : 1;
    U16BIT Reserved1 : 1;
};

union UNION_ICS_CONTROL3
{
    struct ICS_CONTROL3 st_ICS_CONTROL3;
    WORD w_ICS_CONTROL3;
};


struct ICS_CONTROL4{
    U16BIT Reserved14 : 1;
    U16BIT Reserved13 : 1;
    U16BIT Reserved12 : 1;
    U16BIT Reserved11 : 1;
    U16BIT Reserved10 : 1;
    U16BIT Reserved9 : 1;
    U16BIT Reserved8 : 1;
    U16BIT Reserved7 : 1;
    U16BIT Reserved6 : 1;
    U16BIT Reserved5 : 1;
    U16BIT Reserved4 : 1;
    U16BIT Reserved3 : 1;
    U16BIT Reserved2 : 1;
    U16BIT Reserved1 : 1;
    U16BIT ComSecInterfaceControl : 2;
};

union UNION_ICS_CONTROL4
{
    struct ICS_CONTROL4 st_ICS_CONTROL4;
    WORD w_ICS_CONTROL4;
};


struct VOICE_WARNING_MESSAGE1{
    U16BIT Reserved : 1;
    U16BIT MWRDirection : 4;
    U16BIT MWRThreat : 1;
    U16BIT DispenseReady : 1;
    U16BIT LowRPM : 1;
    U16BIT No2EngineOut : 1;
    U16BIT No1EngineOut : 1;
    U16BIT MGBFire : 1;
    U16BIT APUFire : 1;
    U16BIT No2EngineFire : 1;
    U16BIT No1EngineFire : 1;
    U16BIT LowAttitudeBaro : 1;
    U16BIT LowAttitudeRALT : 1;
};

union UNION_VOICE_WARNING_MESSAGE1
{
    struct VOICE_WARNING_MESSAGE1 st_VOICE_WARNING_MESSAGE1;
    WORD w_VOICE_WARNING_MESSAGE1;
};


struct VOICE_WARNING_MESSAGE2{
    U16BIT Reserved : 1;
    U16BIT RWRDirection3 : 4;
    U16BIT RWRGunTrack : 1;
    U16BIT RWRDirection2 : 4;
    U16BIT RWRGunLockOn : 1;
    U16BIT RWRDirection1 : 4;
    U16BIT RWRGunLaunch : 1;
};

union UNION_VOICE_WARNING_MESSAGE2
{
    struct VOICE_WARNING_MESSAGE2 st_VOICE_WARNING_MESSAGE2;
    WORD w_VOICE_WARNING_MESSAGE2;
};



struct VOICE_WARNING_MESSAGE3{
    U16BIT LWRLaserUnknown : 1;
    U16BIT LWRDirection3 : 4;
    U16BIT LWRLaserRange : 1;
    U16BIT LWRDirection2 : 4;
    U16BIT LWRLaserDesignation : 1;
    U16BIT LWRDirection1 : 4;
    U16BIT LWRLaserBeam : 1;
};

union UNION_VOICE_WARNING_MESSAGE3
{
    struct VOICE_WARNING_MESSAGE3 st_VOICE_WARNING_MESSAGE3;
    WORD w_VOICE_WARNING_MESSAGE3;
};


struct VOICE_WARNING_MESSAGE4{
    U16BIT Reserved : 1;
    U16BIT RWRDirection3 : 4;
    U16BIT RWRRadarLaunch : 1;
    U16BIT RWRDirection2 : 4;
    U16BIT RWRFixedWingLaunch : 1;
    U16BIT RWRDirection1 : 4;
    U16BIT RWRHelicopterLaunch : 1;
};

union UNION_VOICE_WARNING_MESSAGE4
{
    struct VOICE_WARNING_MESSAGE4 st_VOICE_WARNING_MESSAGE4;
    WORD w_VOICE_WARNING_MESSAGE4;
};


struct VOICE_WARNING_MESSAGE5{
    U16BIT Reserved : 1;
    U16BIT RWRDirection3 : 4;
    U16BIT RWRRadarLockOn : 1;
    U16BIT RWRDirection2 : 4;
    U16BIT RWRFixedWingLockOn : 1;
    U16BIT RWRDirection1 : 4;
    U16BIT RWRHelicopterLockOn : 1;
};

union UNION_VOICE_WARNING_MESSAGE5
{
    struct VOICE_WARNING_MESSAGE5 st_VOICE_WARNING_MESSAGE5;
    WORD w_VOICE_WARNING_MESSAGE5;
};


struct VOICE_WARNING_MESSAGE6{
    U16BIT Reserved : 1;
    U16BIT RWRDirection3 : 4;
    U16BIT RWRRadarTrack : 1;
    U16BIT RWRDirection2 : 4;
    U16BIT RWRFixedWingTrack : 1;
    U16BIT RWRDirection1 : 4;
    U16BIT RWRHelicopterTrack : 1;
};

union UNION_VOICE_WARNING_MESSAGE6
{
    struct VOICE_WARNING_MESSAGE6 st_VOICE_WARNING_MESSAGE6;
    WORD w_VOICE_WARNING_MESSAGE6;
};


struct VOICE_WARNING_MESSAGE7{
    U16BIT Reserved : 1;
    U16BIT RWRDirection3 : 4;
    U16BIT RWRHelicopterSearch : 1;
    U16BIT RWRDirection2 : 4;
    U16BIT RWRGunSerach : 1;
    U16BIT RWRDirection1 : 4;
    U16BIT RWRRadarUnknown : 1;
};

union UNION_VOICE_WARNING_MESSAGE7
{
    struct VOICE_WARNING_MESSAGE7 st_VOICE_WARNING_MESSAGE7;
    WORD w_VOICE_WARNING_MESSAGE7;
};


struct VOICE_WARNING_MESSAGE8{
    U16BIT Reserved : 1;
    U16BIT RWRDirection3 : 4;
    U16BIT RWRRadar : 1;
    U16BIT RWRDirection2 : 4;
    U16BIT RWRRadarSearch : 1;
    U16BIT RWRDirection1 : 4;
    U16BIT RWRFixedWingSearch : 1;
};

union UNION_VOICE_WARNING_MESSAGE8
{
    struct VOICE_WARNING_MESSAGE8 st_VOICE_WARNING_MESSAGE8;
    WORD w_VOICE_WARNING_MESSAGE8;
};


struct VOICE_WARNING_MESSAGE9{
    U16BIT Reserved3 : 1;
    U16BIT Reserved2 : 1;
    U16BIT Reserved1 : 1;
    U16BIT Stall : 1;
    U16BIT MissionFuelWarning : 1;
    U16BIT ReturnFuelWarning : 1;
    U16BIT CautionCWP : 1;
    U16BIT AirSpeed : 1;
    U16BIT Other2Low : 1;
    U16BIT Other1Low : 1;
    U16BIT ChaffLow : 1;
    U16BIT FlareLow : 1;
    U16BIT Other2Out : 1;
    U16BIT Other1Out : 1;
    U16BIT ChaffOut : 1;
    U16BIT FlareOut : 1;
};

union UNION_VOICE_WARNING_MESSAGE9
{
    struct VOICE_WARNING_MESSAGE9 st_VOICE_WARNING_MESSAGE9;
    WORD w_VOICE_WARNING_MESSAGE9;
};


struct AIU_FAULT_DATA{
    U16BIT FaultData15 : 1;
    U16BIT FaultData14 : 1;
    U16BIT FaultData13 : 1;
    U16BIT FaultData12 : 1;
    U16BIT FaultData11 : 1;
    U16BIT FaultData10 : 1;
    U16BIT FaultData9 : 1;
    U16BIT FaultData8 : 1;
    U16BIT FaultData7 : 1;
    U16BIT FaultData6 : 1;
    U16BIT FaultData5 : 1;
    U16BIT FaultData4 : 1;
    U16BIT FaultData3 : 1;
    U16BIT FaultData2 : 1;
    U16BIT FaultData1 : 1;
    U16BIT FaultData0 : 1;
};

union UNION_AIU_FAULT_DATA
{
    struct AIU_FAULT_DATA st_AIU_FAULT_DATA;
    WORD w_AIU_FAULT_DATA;
};


struct ICS_SW_ID{
    U16BIT SWIDCharacter2 : 7;
    U16BIT Reserved2 : 1;
    U16BIT SWIDCharacter1 : 7;
    U16BIT Reserved1 : 1;
};

union UNION_ICS_SW_ID
{
    struct ICS_SW_ID st_ICS_SW_ID;
    WORD w_ICS_SW_ID;
};


struct ICP_STATUS{
    U16BIT VMUMode : 2;
    U16BIT Reserved4 : 1;
    U16BIT SeletedRadioInRMT : 2;
    U16BIT Reserved3 : 1;
    U16BIT PTTStatus : 2;
    U16BIT Reserved2 : 1;
    U16BIT CommunicationMode : 3;
    U16BIT Reserved1 : 4;
};

union UNION_ICP_STATUS
{
    struct ICP_STATUS st_ICP_STATUS;
    WORD w_ICP_STATUS;
};


struct AIU_STATUS{
    U16BIT Reserved4 : 1;
    U16BIT Reserved3 : 1;
    U16BIT WeightOnWheelState : 1;
    U16BIT Reserved2 : 1;
    U16BIT CurrentVoiceWarning : 7;
    U16BIT Reserved1 : 4;
    U16BIT BITInProgress : 1;
};

union UNION_AIU_STATUS
{
    struct AIU_STATUS st_AIU_STATUS;
    WORD w_AIU_STATUS;
};


struct AIU_NO_NAME{
    U16BIT Reserved14 : 1;
    U16BIT Reserved13 : 1;
    U16BIT Reserved12 : 1;
    U16BIT Reserved11 : 1;
    U16BIT Reserved10 : 1;
    U16BIT Reserved9 : 1;
    U16BIT Reserved8 : 1;
    U16BIT Reserved7 : 1;
    U16BIT Reserved6 : 1;
    U16BIT Reserved5 : 1;
    U16BIT Reserved4 : 1;
    U16BIT Reserved3 : 1;
    U16BIT Reserved2 : 1;
    U16BIT COMSECInterfaceControl : 2;
    U16BIT Reserved1 : 1;
};

union UNION_AIU_NO_NAME
{
    struct AIU_NO_NAME st_AIU_NO_NAME;
    WORD w_AIU_NO_NAME;
};