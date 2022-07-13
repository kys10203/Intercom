#pragma once
#include "stdemace.h"
#include "BIT_FIELD.h"
#include "afxwin.h"


// CFAULT_DATA 대화 상자입니다.

class CFAULT_DATA : public CDialogEx
{
	DECLARE_DYNAMIC(CFAULT_DATA)

public:
	CFAULT_DATA(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFAULT_DATA();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FAULT_DATA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    CStatic m_LED_F01;
    CStatic m_LED_F02;
    CStatic m_LED_F03;
    CStatic m_LED_F04;
    CStatic m_LED_F05;
    CStatic m_LED_F06;
    CStatic m_LED_F07;
    CStatic m_LED_F08;
    CStatic m_LED_F09;
    CStatic m_LED_F10;
    CStatic m_LED_F11;
    CStatic m_LED_F12;
    CStatic m_LED_F13;
    CStatic m_LED_F14;
    CStatic m_LED_F15;
    CStatic m_LED_F16;
    CStatic m_LED_F17;
    CStatic m_LED_F18;
    CStatic m_LED_F19;
    CStatic m_LED_F20;
    CStatic m_LED_F21;
    CStatic m_LED_F22;
    CStatic m_LED_F23;
    CStatic m_LED_F24;
    CStatic m_LED_F25;
    CStatic m_LED_F26;
    CStatic m_LED_F27;
    CStatic m_LED_F28;
    CStatic m_LED_F29;
    CStatic m_LED_F30;
    CStatic m_LED_F31;
    CStatic m_LED_F32;
    afx_msg void OnClose();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
