#pragma once


// CSET_ETHERNET 대화 상자입니다.

class CSET_ETHERNET : public CDialogEx
{
	DECLARE_DYNAMIC(CSET_ETHERNET)

public:
	CSET_ETHERNET(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSET_ETHERNET();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SET_ETHERNET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
