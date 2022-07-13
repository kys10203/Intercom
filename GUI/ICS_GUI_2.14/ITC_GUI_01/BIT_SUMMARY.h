#pragma once
#include "stdemace.h"
#include "BIT_FIELD.h"
#include "afxwin.h"

// CBIT_SUMMARY 대화 상자입니다.

class CBIT_SUMMARY : public CDialogEx
{
	DECLARE_DYNAMIC(CBIT_SUMMARY)

public:
	CBIT_SUMMARY(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBIT_SUMMARY();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BIT_SUMMARY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnClose();
    CStatic m_TEXT_ARC1_LatestBIT;
    CStatic m_TEXT_ARC1_FirstModule;
    CStatic m_TEXT_ARC1_SecModule;
    CStatic m_TEXT_ARC1_TrdModule;
    CStatic m_LED_ARC1_IBIT_Result;
    CStatic m_LED_ARC1_PowRegFault;
    CStatic m_LED_ARC1_HighVSWR;
    CStatic m_LED_ARC1_LowRF;
    CStatic m_LED_ARC1_HighTemp;
    CStatic m_LED_ARC1_LowBattery;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
