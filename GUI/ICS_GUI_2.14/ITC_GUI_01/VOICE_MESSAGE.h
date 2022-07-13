#define UWM_ICS_DIS (WM_USER+1)

#pragma once
#include "afxwin.h"


// CVOICE_MESSAGE 대화 상자입니다.

class CVOICE_MESSAGE : public CDialogEx
{
	DECLARE_DYNAMIC(CVOICE_MESSAGE)

public:
	CVOICE_MESSAGE(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CVOICE_MESSAGE();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_VOICE_MESSAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    void SetComboDirection(CComboBox* pCombo);
    virtual BOOL OnInitDialog();
    CComboBox m_combo_mwr_threat;
    CComboBox m_combo_rwr_gun_launch;
    CComboBox m_combo_rwr_gun_lockon;
    CComboBox m_combo_rwr_gun_track;
    CComboBox m_combo_lwr_beam;
    CComboBox m_combo_lwr_designation;
    CComboBox m_combo_lwr_range;
    CComboBox m_combo_rwr_heli_launch;
    CComboBox m_combo_rwr_fwing_launch;
    CComboBox m_combo_rwr_radar_launch;
    CComboBox m_combo_rwr_heli_lockon;
    CComboBox m_combo_rwr_fwing_lockon;
    CComboBox m_combo_rwr_radar_lockon;
    CComboBox m_combo_rwr_heli_track;
    CComboBox m_combo_rwr_fwing_track;
    CComboBox m_combo_rwr_radar_track;
    CComboBox m_combo_rwr_radar_unknown;
    CComboBox m_combo_rwr_gun_search;
    CComboBox m_combo_rwr_heli_search;
    CComboBox m_combo_rwr_fwing_search;
    CComboBox m_combo_rwr_radar_search;
    CComboBox m_combo_rwr_radar;
    afx_msg void OnBnClickedBtnSetVm();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnClose();
    CButton m_LowAltitudeRALT;
    CButton m_LowAltitudeBaro;
    CButton m_No1EngFire;
    CButton m_No2EngFire;
    CButton m_APUFire;
    CButton m_MGBFire;
    CButton m_No1EngOut;
    CButton m_No2EngOut;
    CButton m_LowRPM;
    CButton m_DispenseReady;
    CButton m_MWRThreat;
    CButton m_RWRGunLaunch;
    CButton m_RWRGunLockOn;
    CButton m_RWRGunTrack;
    CButton m_LWRLaserBeam;
    CButton m_LWRLaserDesignation;
    CButton m_LWRLaserRange;
    CButton m_LWRLaserUnknown;
    CButton m_RWRHeliLaunch;
    CButton m_RWRFixedWingLaunch;
    CButton m_RWRRadarLaunch;
    CButton m_RWRHeliLockOn;
    CButton m_RWRFixedWingLockOn;
    CButton m_RWRRadarLockOn;
    CButton m_RWRHeliTrack;
    CButton m_RWRFixedWingTrack;
    void GetVMCheck(void);
    void GetVMSetting(CButton* p_CButton);
    CButton m_RWRRadarTrack;
    CButton m_RWR_RadarUnknown;
    CButton m_RWRGunSearch;
    CButton m_RWRHeliSearch;
    CButton m_RWRFixedWingSearch;
    CButton m_RWRRadarSearch;
    CButton m_RWRRadar;
    CButton m_FlareOut;
    CButton m_ChaffOut;
    CButton m_Other1Out;
    CButton m_Other2Out;
    CButton m_FlareLow;
    CButton m_ChaffLow;
    CButton m_Other1Low;
    CButton m_Other2Low;
    CButton m_AirSpeed;
    CButton m_Caution;
    CButton m_RtnFuelWarning;
    CButton m_MissionFuelWarning;
    CButton m_Stall;
    void SetVMCheck(void);
};
