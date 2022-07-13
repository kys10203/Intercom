#pragma once
#include "afxwin.h"
#define IpAddr _T("192.168.0.110")
#define nPort 5025
// CCtrlPowSup 대화 상자입니다.

class CCtrlPowSup : public CDialogEx
{
	DECLARE_DYNAMIC(CCtrlPowSup)

public:
	CCtrlPowSup(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCtrlPowSup();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CTRLPOWSUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    afx_msg void OnBnClickedBtnSetPowerOption();

    CString volt;
    CString curr;
    CString outp;
    CString str_volt;
    CString str_curr;

    virtual BOOL OnInitDialog();
    CEdit m_Edit_Voltage;
    CEdit m_Edit_Current;

    afx_msg void OnBnClickedBtnPowOnoff();
    CButton m_BTN_PowOnOff;
};
