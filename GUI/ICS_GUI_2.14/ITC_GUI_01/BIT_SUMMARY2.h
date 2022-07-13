#pragma once
#include "stdemace.h"
#include "BIT_FIELD.h"
#include "afxwin.h"

// CBIT_SUMMARY2 ��ȭ �����Դϴ�.

class CBIT_SUMMARY2 : public CDialogEx
{
	DECLARE_DYNAMIC(CBIT_SUMMARY2)

public:
	CBIT_SUMMARY2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBIT_SUMMARY2();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BIT_SUMMARY2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnClose();
    CStatic m_TEXT_ARC2_LatestBIT;
    CStatic m_TEXT_ARC2_FirstModule;
    CStatic m_TEXT_ARC2_SecModule;
    CStatic m_TEXT_ARC2_TrdModule;
    CStatic m_LED_ARC2_IBIT_Result;
    CStatic m_LED_ARC2_PowRegFault;
    CStatic m_LED_ARC2_HighVSWR;
    CStatic m_LED_ARC2_LowRF;
    CStatic m_LED_ARC2_HighTemp;
    CStatic m_LED_ARC2_LowBattery;
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
