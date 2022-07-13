#pragma once
#include "afxwin.h"
#define IpAddr _T("192.168.0.110")
#define nPort 5025
// CCtrlPowSup ��ȭ �����Դϴ�.

class CCtrlPowSup : public CDialogEx
{
	DECLARE_DYNAMIC(CCtrlPowSup)

public:
	CCtrlPowSup(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCtrlPowSup();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CTRLPOWSUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
