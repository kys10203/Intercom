#define UWM_ICS_DIS (WM_USER+1)
#define UWM_DP_ICS_DIS (WM_USER+2)

#pragma once
#include "voice_message.h"
#include "itc_set_dis.h"
#include "afxwin.h"
#include "BIT_FIELD.h"


// CICS_CP 대화 상자입니다.

class CICS_CP : public CDialogEx
{
	DECLARE_DYNAMIC(CICS_CP)

public:
	CICS_CP(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CICS_CP();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ICS_CP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    afx_msg void OnBnClickedBtnSetDist();

    CVOICE_MESSAGE m_CVOICE_MESSAGE;
    CITC_SET_DIS m_CITC_SET_DIS;

    CVOICE_MESSAGE* p_CVOICE_MESSAGE;
    CITC_SET_DIS* p_CITC_SET_DIS;

    CHAR WriteMsg[BUFSIZE];
    UCHAR ReadMsg[BUFSIZE];
    CHAR ComsecMsg[BUFSIZE];
    CHAR ComsecMsg2[BUFSIZE];

    afx_msg void OnBnClickedBtnSetIcs();
    virtual BOOL OnInitDialog();
    CComboBox m_combo_sel_icp1;
    CComboBox m_combo_sel_icp2;
    CComboBox m_combo_comsec_if;
protected:
    afx_msg LRESULT OnUwmIcsDis(WPARAM wParam, LPARAM lParam);
public:
    afx_msg void OnBnClickedBtnIbit();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
    afx_msg LRESULT OnUwmDpIcsDis(WPARAM wParam, LPARAM lParam);
public:
    afx_msg void OnClose();
    BOOL f_SET_DIS;

    UNION_ICS_CONTROL1 un_ICS_CONTROL1;
    UNION_ICS_CONTROL2 un_ICS_CONTROL2;
    UNION_ICS_CONTROL3 un_ICS_CONTROL3;
    UNION_ICS_CONTROL4 un_ICS_CONTROL4;

    UNION_VOICE_WARNING_MESSAGE1 un_VOICE_WARNING_MESSAGE1;
    UNION_VOICE_WARNING_MESSAGE2 un_VOICE_WARNING_MESSAGE2;
    UNION_VOICE_WARNING_MESSAGE3 un_VOICE_WARNING_MESSAGE3;
    UNION_VOICE_WARNING_MESSAGE4 un_VOICE_WARNING_MESSAGE4;
    UNION_VOICE_WARNING_MESSAGE5 un_VOICE_WARNING_MESSAGE5;
    UNION_VOICE_WARNING_MESSAGE6 un_VOICE_WARNING_MESSAGE6;
    UNION_VOICE_WARNING_MESSAGE7 un_VOICE_WARNING_MESSAGE7;
    UNION_VOICE_WARNING_MESSAGE8 un_VOICE_WARNING_MESSAGE8;
    UNION_VOICE_WARNING_MESSAGE9 un_VOICE_WARNING_MESSAGE9;

    WORD MSG_ICS_Control[MAX_WORD];
    WORD MSG_VOICE_WARNING[MAX_WORD];
    void CheckICSSetting(void);
    int wResult;
    CButton m_check_WOW;
    afx_msg void OnBnClickedBtnVmu();
    afx_msg void OnBnClickedBtnWarningReset();
};
