#define BUFSIZE 256
#define UWM_ICS_DIS (WM_USER+1)
#define UWM_DP_ICS_DIS (WM_USER+2)
#define UWM_RDY_ICS_DIS (WM_USER+3)

#pragma once
#include "afxwin.h"

class CISC_CP;
// CITC_SET_DIS 대화 상자입니다.

class CITC_SET_DIS : public CDialogEx
{
	DECLARE_DYNAMIC(CITC_SET_DIS)

public:
	CITC_SET_DIS(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CITC_SET_DIS();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ITC_SET_DIS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    afx_msg void OnBnClickedBtnSetDis();
    CButton m_CHECK_REMOTE_ON;
    CButton m_CHECK_COMSEC_X;
    CButton m_CHECK_SPARE_DIN1;
    CButton m_CHECK_SPARE_DIN2;
    CButton m_CHECK_SPARE_DIN3;
    CButton m_CHECK_SPARE_DIN4;
    CButton m_CHECK_WOW;
    CButton m_CHECK_FUEL_LOW_WARN;
    CButton m_CHECK_LWR_WARN;
    CButton m_CHECK_RWR_WARN;

    CButton m_CHECK_MWR_WARN_1;
    CButton m_CHECK_MWR_WARN_2;
    CButton m_CHECK_MWR_WARN_3;
    CButton m_CHECK_MAINT_MODE;
    CButton m_CHECK_RALT_LOW_ALT_WARN;

    CButton m_CHECK_BARO_LOW_ALT_WARN;
    CButton m_CHECK_FIRE_WARN;
    CButton m_CHECK_ENG_OUT_WARN;
    CButton m_CHECK_NR_LOW_WARN;
    CButton m_CHECK_CAUT;

    CButton m_CHECK_WARN_RST;

    UINT8 WriteDiscrete(CButton* p_CButton);
    CHAR WriteMsg[BUFSIZE];
    CHAR ReadMsg[BUFSIZE];
    CHAR ComsecMsg[BUFSIZE];
    CHAR ComsecMsg2[BUFSIZE];
    virtual void OnCancel();

    virtual BOOL OnInitDialog();
    void ChangeIcon(CStatic* m_Icon, unsigned char flag);

    CStatic m_LED_AIU_RDY;
    CStatic m_LED_AIU_COM1_PTT;
    CStatic m_LED_AIU_COM2_PTT;
    CStatic m_LED_AIU_COM3_PTT;
    CStatic m_LED_AIU_COM4_PTT;
    CStatic m_LED_AIU_COM5_PTT;
    CStatic m_LED_AIU_COM2_X_EN;
    CStatic m_LED_AIU_COM3_X_EN;
    CStatic m_LED_AIU_COMSEC_PTT;
    CStatic m_LED_AIU_SPARE_DOUT1;
    CStatic m_LED_AIU_SPARE_DOUT2;
    CStatic m_LED_AIU_SPARE_DOUT3;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
    afx_msg LRESULT OnUwmIcsDis(WPARAM wParam, LPARAM lParam);
public:
    BOOL b_ITC_SET_DIS;
protected:
    afx_msg LRESULT OnUwmDpIcsDis(WPARAM wParam, LPARAM lParam);
public:
    CStatic m_STATIC_COMSEC_AIU_PTT;
    CStatic m_STATIC_COM1_AIU_SQL;
    CStatic m_STATIC_COM2_AIU_SQL;
    CStatic m_STATIC_COM3_AIU_SQL;
    CStatic m_STATIC_COM4_AIU_SQL;
    CStatic m_STATIC_COM5_AIU_SQL;
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnClose();
    // CICS_CP* p_CICS_CP;
};
