// VOICE_MESSAGE.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "VOICE_MESSAGE.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"
#include "ICS_CP.h"


// CVOICE_MESSAGE 대화 상자입니다.

IMPLEMENT_DYNAMIC(CVOICE_MESSAGE, CDialogEx)

CVOICE_MESSAGE::CVOICE_MESSAGE(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVOICE_MESSAGE::IDD, pParent)
{

	EnableAutomation();

}

CVOICE_MESSAGE::~CVOICE_MESSAGE()
{
}

void CVOICE_MESSAGE::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CVOICE_MESSAGE::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_MWR_THREAT, m_combo_mwr_threat);
    DDX_Control(pDX, IDC_COMBO_RWR_GUN_Launch, m_combo_rwr_gun_launch);
    DDX_Control(pDX, IDC_COMBO_RWR_GUN_TRACK, m_combo_rwr_gun_track);
    DDX_Control(pDX, IDC_COMBO_LWR_BEAM, m_combo_lwr_beam);
    DDX_Control(pDX, IDC_COMBO_LWR_DESIGNATION, m_combo_lwr_designation);
    DDX_Control(pDX, IDC_COMBO_LWR_RANGE, m_combo_lwr_range);
    DDX_Control(pDX, IDC_COMBO_RWR_HELI_LAUNCH, m_combo_rwr_heli_launch);
    DDX_Control(pDX, IDC_COMBO_RWR_FWING_LAUNCH, m_combo_rwr_fwing_launch);
    DDX_Control(pDX, IDC_COMBO_RWR_RADAR_LAUNCH, m_combo_rwr_radar_launch);
    DDX_Control(pDX, IDC_COMBO_RWR_HELI_LOCKON, m_combo_rwr_heli_lockon);
    DDX_Control(pDX, IDC_COMBO_RWR_FWING_LOCKON, m_combo_rwr_fwing_lockon);
    DDX_Control(pDX, IDC_COMBO_RWR_RADAR_LOCKON, m_combo_rwr_radar_lockon);
    DDX_Control(pDX, IDC_COMBO_RWR_HELI_TRACK, m_combo_rwr_heli_track);
    DDX_Control(pDX, IDC_COMBO_RWR_FWING_TRACK, m_combo_rwr_fwing_track);
    DDX_Control(pDX, IDC_COMBO_RWR_RADAR_TRACK, m_combo_rwr_radar_track);
    DDX_Control(pDX, IDC_COMBO_RWR_RADAR_UNKNOWN, m_combo_rwr_radar_unknown);
    DDX_Control(pDX, IDC_COMBO_RWR_GUN_SEARCH, m_combo_rwr_gun_search);
    DDX_Control(pDX, IDC_COMBO_RWR_HELI_SEARCH, m_combo_rwr_heli_search);
    DDX_Control(pDX, IDC_COMBO_RWR_FWING_SEARCH, m_combo_rwr_fwing_search);
    DDX_Control(pDX, IDC_COMBO_RWR_RADAR_SEARCH, m_combo_rwr_radar_search);
    DDX_Control(pDX, IDC_COMBO_RWR_RADAR, m_combo_rwr_radar);
    DDX_Control(pDX, IDC_CHK_LOW_ALTITUDE_RALT, m_LowAltitudeRALT);
    DDX_Control(pDX, IDC_CHK_LOW_ALTITUDE_BARO, m_LowAltitudeBaro);
    DDX_Control(pDX, IDC_CHK_NO1_ENG_FIRE, m_No1EngFire);
    DDX_Control(pDX, IDC_CHK_NO2_ENG_FIRE, m_No2EngFire);
    DDX_Control(pDX, IDC_CHK_APU_FIRE, m_APUFire);
    DDX_Control(pDX, IDC_CHK_MGB_FIRE, m_MGBFire);
    DDX_Control(pDX, IDC_CHK_NO1_ENG_OUT, m_No1EngOut);
    DDX_Control(pDX, IDC_CHK_NO2_ENG_OUT, m_No2EngOut);
    DDX_Control(pDX, IDC_CHK_LOW_RPM, m_LowRPM);
    DDX_Control(pDX, IDC_CHK_DISPENSE_RDY, m_DispenseReady);
    DDX_Control(pDX, IDC_CHK_MWR_THREAT, m_MWRThreat);
    DDX_Control(pDX, IDC_CHK_RWR_GUN_LAUNCH, m_RWRGunLaunch);
    DDX_Control(pDX, IDC_CHK_RWR_GUN_TRACK, m_RWRGunTrack);
    DDX_Control(pDX, IDC_CHK_LWR_LASER_BEAM, m_LWRLaserBeam);
    DDX_Control(pDX, IDC_CHK_LWR_LASER_DESIGNATION, m_LWRLaserDesignation);
    DDX_Control(pDX, IDC_CHK_LWR_LASER_RANGE, m_LWRLaserRange);
    DDX_Control(pDX, IDC_CHK_LWR_LASER_UNKNOWN, m_LWRLaserUnknown);
    DDX_Control(pDX, IDC_CHK_RWR_HELI_LAUNCH, m_RWRHeliLaunch);
    DDX_Control(pDX, IDC_CHK_RWR_FIXED_WING_LAUNCH, m_RWRFixedWingLaunch);
    DDX_Control(pDX, IDC_CHK_RWR_RADAR_LAUNCH, m_RWRRadarLaunch);
    DDX_Control(pDX, IDC_CHK_RWR_HELI_LOCKON, m_RWRHeliLockOn);
    DDX_Control(pDX, IDC_CHK_RWR_FIXED_WING_LOCKON, m_RWRFixedWingLockOn);
    DDX_Control(pDX, IDC_CHK_RWR_RADAR_LOCKON, m_RWRRadarLockOn);
    DDX_Control(pDX, IDC_CHK_RWR_RWR_HELI_TRACK, m_RWRHeliTrack);
    DDX_Control(pDX, IDC_CHK_RWR_FIXED_WING_TRACK, m_RWRFixedWingTrack);
    DDX_Control(pDX, IDC_CHK_RWR_RADAR_TRACK, m_RWRRadarTrack);
    DDX_Control(pDX, IDC_CHK_RWR_RADAR_UNKNOWN, m_RWR_RadarUnknown);
    DDX_Control(pDX, IDC_CHK_RWR_GUN_SEARCH, m_RWRGunSearch);
    DDX_Control(pDX, IDC_CHK_RWR_HELI_SEARCH, m_RWRHeliSearch);
    DDX_Control(pDX, IDC_CHK_RWR_FIXED_WING_SEARCH, m_RWRFixedWingSearch);
    DDX_Control(pDX, IDC_CHK_RWR_RADAR_SEARCH, m_RWRRadarSearch);
    DDX_Control(pDX, IDC_CHK_RWR_RADAR, m_RWRRadar);
    DDX_Control(pDX, IDC_CHK_FLARE_OUT, m_FlareOut);
    DDX_Control(pDX, IDC_CHK_CHAFF_OUT, m_ChaffOut);
    DDX_Control(pDX, IDC_CHK_OTHER1_OUT, m_Other1Out);
    DDX_Control(pDX, IDC_CHK_OTHER2_OUT, m_Other2Out);
    DDX_Control(pDX, IDC_CHK_FLARE_LOW, m_FlareLow);
    DDX_Control(pDX, IDC_CHK_CHAFF_LOW, m_ChaffLow);
    DDX_Control(pDX, IDC_CHK_OTHER1_LOW, m_Other1Low);
    DDX_Control(pDX, IDC_CHK_OTHER2_LOW, m_Other2Low);
    DDX_Control(pDX, IDC_CHK_AIR_SPEED, m_AirSpeed);
    DDX_Control(pDX, IDC_CHK_CAUTION, m_Caution);
    DDX_Control(pDX, IDC_CHK_RTN_FUEL_WARN, m_RtnFuelWarning);
    DDX_Control(pDX, IDC_CHK_MISSION_FUEL_WARN, m_MissionFuelWarning);
    DDX_Control(pDX, IDC_CHK_STALL, m_Stall);
    DDX_Control(pDX, IDC_COMBO_RWR_GUN_LOCKON, m_combo_rwr_gun_lockon);
    DDX_Control(pDX, IDC_CHK_RWR_GUN_LOCKON, m_RWRGunLockOn);
}


BEGIN_MESSAGE_MAP(CVOICE_MESSAGE, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_SET_VM, &CVOICE_MESSAGE::OnBnClickedBtnSetVm)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CVOICE_MESSAGE, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IVOICE_MESSAGE에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {8BA951F5-0BB7-4E28-92F5-13F25D2B9F61}
static const IID IID_IVOICE_MESSAGE =
{ 0x8BA951F5, 0xBB7, 0x4E28, { 0x92, 0xF5, 0x13, 0xF2, 0x5D, 0x2B, 0x9F, 0x61 } };

BEGIN_INTERFACE_MAP(CVOICE_MESSAGE, CDialogEx)
	INTERFACE_PART(CVOICE_MESSAGE, IID_IVOICE_MESSAGE, Dispatch)
END_INTERFACE_MAP()


// CVOICE_MESSAGE 메시지 처리기입니다.


void CVOICE_MESSAGE::SetComboDirection(CComboBox* pCombo)
{
    pCombo->AddString(_T("1 o'clock"));
    pCombo->AddString(_T("2 o'clock"));
    pCombo->AddString(_T("3 o'clock"));
    pCombo->AddString(_T("4 o'clock"));
    pCombo->AddString(_T("5 o'clock"));
    pCombo->AddString(_T("6 o'clock"));
    pCombo->AddString(_T("7 o'clock"));
    pCombo->AddString(_T("8 o'clock"));
    pCombo->AddString(_T("9 o'clock"));
    pCombo->AddString(_T("10 o'clock"));
    pCombo->AddString(_T("11 o'clock"));
    pCombo->AddString(_T("12 o'clock"));

}


BOOL CVOICE_MESSAGE::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetComboDirection(&m_combo_mwr_threat);
    SetComboDirection(&m_combo_rwr_gun_launch);
    SetComboDirection(&m_combo_rwr_gun_lockon);
    SetComboDirection(&m_combo_rwr_gun_track);
    SetComboDirection(&m_combo_lwr_beam);
    SetComboDirection(&m_combo_lwr_designation);
    SetComboDirection(&m_combo_lwr_range);
    SetComboDirection(&m_combo_rwr_heli_launch);
    SetComboDirection(&m_combo_rwr_fwing_launch);
    SetComboDirection(&m_combo_rwr_radar_launch);
    SetComboDirection(&m_combo_rwr_heli_lockon);
    SetComboDirection(&m_combo_rwr_fwing_lockon);
    SetComboDirection(&m_combo_rwr_radar_lockon);
    SetComboDirection(&m_combo_rwr_heli_track);
    SetComboDirection(&m_combo_rwr_fwing_track);
    SetComboDirection(&m_combo_rwr_radar_track);
    SetComboDirection(&m_combo_rwr_radar_unknown);
    SetComboDirection(&m_combo_rwr_gun_search);
    SetComboDirection(&m_combo_rwr_heli_search);
    SetComboDirection(&m_combo_rwr_fwing_search);
    SetComboDirection(&m_combo_rwr_radar_search);
    SetComboDirection(&m_combo_rwr_radar);

    SetVMCheck();

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CVOICE_MESSAGE::OnBnClickedBtnSetVm()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    // ((CITC_GUI_01Dlg *)GetParent())->test = (_T("A"));
    GetVMCheck();

    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[7] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.w_VOICE_WARNING_MESSAGE1;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[8] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.w_VOICE_WARNING_MESSAGE2;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[9] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.w_VOICE_WARNING_MESSAGE3;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[10] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.w_VOICE_WARNING_MESSAGE4;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[11] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.w_VOICE_WARNING_MESSAGE5;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[12] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.w_VOICE_WARNING_MESSAGE6;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[13] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.w_VOICE_WARNING_MESSAGE7;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[14] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.w_VOICE_WARNING_MESSAGE8;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[15] = ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.w_VOICE_WARNING_MESSAGE9;

    aceBCDataBlkWrite(DevNum, DBLK31, ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT, 16, 0);
}


BOOL CVOICE_MESSAGE::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if(pMsg->message == WM_KEYDOWN)
    {
        if(pMsg->wParam == VK_ESCAPE)
            return TRUE;
        else if(pMsg->wParam == VK_RETURN)
            return TRUE;
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}


void CVOICE_MESSAGE::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    DestroyWindow();
    CDialogEx::OnClose();
}


void CVOICE_MESSAGE::GetVMCheck(void)
{
    // 1
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.LowAttitudeRALT = m_LowAltitudeRALT.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.LowAttitudeBaro = m_LowAltitudeBaro.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.No1EngineFire = m_No1EngFire.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.No2EngineFire = m_No2EngFire.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.APUFire = m_APUFire.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.MGBFire = m_MGBFire.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.No1EngineOut = m_No1EngOut.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.No2EngineOut = m_No2EngOut.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.LowRPM = m_LowRPM.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.DispenseReady = m_DispenseReady.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.MWRThreat = m_MWRThreat.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.MWRDirection = m_combo_mwr_threat.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.Reserved = 0x0;
    // 2
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRGunLaunch = m_RWRGunLaunch.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRDirection1 = m_combo_rwr_gun_launch.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRGunLockOn = m_RWRGunLockOn.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRDirection2 = m_combo_rwr_gun_lockon.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRGunTrack = m_RWRGunTrack.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRDirection3 = m_combo_rwr_gun_track.GetCurSel() + 1;

    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRLaserBeam = m_LWRLaserBeam.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRDirection1 = m_combo_lwr_beam.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRLaserDesignation = m_LWRLaserDesignation.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRDirection2 = m_combo_lwr_designation.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRLaserRange = m_LWRLaserRange.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRDirection3 = m_combo_lwr_range.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRLaserUnknown = m_LWRLaserUnknown.GetCheck();

    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRHelicopterLaunch = m_RWRHeliLaunch.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRDirection1 = m_combo_rwr_heli_launch.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRFixedWingLaunch = m_RWRFixedWingLaunch.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRDirection2 = m_combo_rwr_fwing_launch.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRRadarLaunch = m_RWRRadarLaunch.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRDirection3 = m_combo_rwr_radar_launch.GetCurSel() + 1;

    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRHelicopterLockOn = m_RWRHeliLockOn.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRDirection1 = m_combo_rwr_heli_lockon.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRFixedWingLockOn = m_RWRFixedWingLockOn.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRDirection2 = m_combo_rwr_fwing_lockon.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRRadarLockOn = m_RWRRadarLockOn.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRDirection3 = m_combo_rwr_radar_lockon.GetCurSel() + 1;

    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRHelicopterTrack = m_RWRHeliTrack.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRDirection1 = m_combo_rwr_heli_track.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRFixedWingTrack = m_RWRFixedWingTrack.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRDirection2 = m_combo_rwr_fwing_track.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRRadarTrack = m_RWRRadarTrack.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRDirection3 = m_combo_rwr_radar_track.GetCurSel() + 1;

    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRRadarUnknown = m_RWR_RadarUnknown.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRDirection1 = m_combo_rwr_radar_unknown.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRGunSerach = m_RWRGunSearch.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRDirection2 = m_combo_rwr_gun_search.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRHelicopterSearch = m_RWRHeliSearch.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRDirection3 = m_combo_rwr_heli_search.GetCurSel() + 1;

    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRFixedWingSearch = m_RWRFixedWingSearch.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRDirection1 = m_combo_rwr_fwing_search.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRRadarSearch = m_RWRRadarSearch.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRDirection2 = m_combo_rwr_radar_search.GetCurSel() + 1;
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRRadar = m_RWRRadar.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRDirection3 = m_combo_rwr_radar.GetCurSel() + 1;

    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.FlareOut = m_FlareOut.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.ChaffOut = m_ChaffOut.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Other1Out = m_Other1Out.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Other2Out = m_Other2Out.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.FlareLow = m_FlareLow.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.ChaffLow = m_ChaffLow.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Other1Low = m_Other1Low.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Other2Low = m_Other2Low.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.AirSpeed = m_AirSpeed.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.CautionCWP = m_Caution.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.ReturnFuelWarning = m_RtnFuelWarning.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.MissionFuelWarning = m_MissionFuelWarning.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Stall = m_Stall.GetCheck();
}



void CVOICE_MESSAGE::SetVMCheck(void)
{
    // 1
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.LowAttitudeRALT == 0x1 )
        m_LowAltitudeRALT.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.LowAttitudeBaro == 0x1 )
        m_LowAltitudeBaro.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.No1EngineFire == 0x1 )
        m_No1EngFire.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.No2EngineFire == 0x1 )
        m_No2EngFire.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.APUFire == 0x1 )
        m_APUFire.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.MGBFire == 0x1 )
        m_MGBFire.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.No1EngineOut == 0x1 )
        m_No1EngOut.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.No2EngineOut == 0x1 )
        m_No2EngOut.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.LowRPM == 0x1 )
        m_LowRPM.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.DispenseReady == 0x1 )
        m_DispenseReady.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.MWRThreat == 0x1 )
        m_MWRThreat.SetCheck(1);

    m_combo_mwr_threat.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE1.st_VOICE_WARNING_MESSAGE1.MWRDirection - 1);

    // 2
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRGunLaunch == 0x1 )
        m_RWRGunLaunch.SetCheck(1);
    m_combo_rwr_gun_launch.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRDirection1 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRGunLockOn == 0x1 )
        m_RWRGunLockOn.SetCheck(1);
    m_combo_rwr_gun_lockon.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRDirection2 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRGunTrack == 0x1 )
        m_RWRGunTrack.SetCheck(1);
    m_combo_rwr_gun_track.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE2.st_VOICE_WARNING_MESSAGE2.RWRDirection3 - 1);

    // 3
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRLaserBeam == 0x1 )
        m_LWRLaserBeam.SetCheck(1);
    m_combo_lwr_beam.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRDirection1 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRLaserDesignation == 0x1 )
        m_LWRLaserDesignation.SetCheck(1);
    m_combo_lwr_designation.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRDirection2 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRLaserRange == 0x1 )
        m_LWRLaserRange.SetCheck(1);
    m_combo_lwr_range.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRDirection3 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE3.st_VOICE_WARNING_MESSAGE3.LWRLaserUnknown == 0x1 )
        m_LWRLaserUnknown.SetCheck(1);

    // 4
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRHelicopterLaunch == 0x1 )
        m_RWRHeliLaunch.SetCheck(1);
    m_combo_rwr_heli_launch.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRDirection1 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRFixedWingLaunch == 0x1 )
        m_RWRFixedWingLaunch.SetCheck(1);
    m_combo_rwr_fwing_launch.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRDirection2 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRRadarLaunch == 0x1 )
        m_RWRRadarLaunch.SetCheck(1);
    m_combo_rwr_radar_launch.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE4.st_VOICE_WARNING_MESSAGE4.RWRDirection3 - 1);

    // 5
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRHelicopterLockOn == 0x1 )
        m_RWRHeliLockOn.SetCheck(1);
    m_combo_rwr_heli_lockon.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRDirection1 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRFixedWingLockOn == 0x1 )
        m_RWRFixedWingLockOn.SetCheck(1);
    m_combo_rwr_fwing_lockon.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRDirection2 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRRadarLockOn == 0x1 )
        m_RWRRadarLockOn.SetCheck(1);
    m_combo_rwr_radar_lockon.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE5.st_VOICE_WARNING_MESSAGE5.RWRDirection3 - 1);

    // 6
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRHelicopterTrack == 0x1 )
        m_RWRHeliTrack.SetCheck(1);
    m_combo_rwr_heli_track.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRDirection1 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRFixedWingTrack == 0x1 )
        m_RWRFixedWingTrack.SetCheck(1);
    m_combo_rwr_fwing_track.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRDirection2 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRRadarTrack == 0x1 )
        m_RWRRadarTrack.SetCheck(1);
    m_combo_rwr_radar_track.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE6.st_VOICE_WARNING_MESSAGE6.RWRDirection3 - 1);

    // 7
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRRadarUnknown == 0x1 )
        m_RWR_RadarUnknown.SetCheck(1);
    m_combo_rwr_radar_unknown.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRDirection1 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRGunSerach == 0x1 )
        m_RWRGunSearch.SetCheck(1);
    m_combo_rwr_gun_search.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRDirection2 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRHelicopterSearch == 0x1 )
        m_RWRHeliSearch.SetCheck(1);
    m_combo_rwr_heli_search.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE7.st_VOICE_WARNING_MESSAGE7.RWRDirection3 - 1);

    // 8
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRFixedWingSearch == 0x1 )
        m_RWRFixedWingSearch.SetCheck(1);
    m_combo_rwr_fwing_search.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRDirection1 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRRadarSearch == 0x1 )
        m_RWRRadarSearch.SetCheck(1);
    m_combo_rwr_radar_search.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRDirection2 - 1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRRadar == 0x1 )
        m_RWRRadar.SetCheck(1);
    m_combo_rwr_radar.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE8.st_VOICE_WARNING_MESSAGE8.RWRDirection3 - 1);

    // 9
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.FlareOut == 0x1 )
        m_FlareOut.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.ChaffOut == 0x1 )
        m_ChaffOut.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Other1Out == 0x1 )
        m_Other1Out.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Other2Out == 0x1 )
        m_Other2Out.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.FlareLow == 0x1 )
        m_FlareLow.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.ChaffLow == 0x1 )
        m_ChaffLow.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Other1Low == 0x1 )
        m_Other1Low.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Other2Low == 0x1 )
        m_Other2Low.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.AirSpeed == 0x1 )
        m_AirSpeed.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.CautionCWP == 0x1 )
        m_Caution.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.ReturnFuelWarning == 0x1 )
        m_RtnFuelWarning.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.MissionFuelWarning == 0x1 )
        m_MissionFuelWarning.SetCheck(1);
    if( ((CITC_GUI_01Dlg *)GetParent())->un_VOICE_WARNING_MESSAGE9.st_VOICE_WARNING_MESSAGE9.Stall == 0x1 )
        m_Stall.SetCheck(1);

}
