#pragma once


// CSET_ETHERNET ��ȭ �����Դϴ�.

class CSET_ETHERNET : public CDialogEx
{
	DECLARE_DYNAMIC(CSET_ETHERNET)

public:
	CSET_ETHERNET(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSET_ETHERNET();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SET_ETHERNET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    CString m_str_setting_ip;
    CString m_str_setting_port;
    afx_msg void OnBnClickedBtnWrite();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
};
