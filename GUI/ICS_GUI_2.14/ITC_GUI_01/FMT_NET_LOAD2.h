#pragma once
#include "bit_field.h"
#include "afxwin.h"


// CFMT_NET_LOAD2 대화 상자입니다.

class CFMT_NET_LOAD2 : public CDialogEx
{
	DECLARE_DYNAMIC(CFMT_NET_LOAD2)

public:
	CFMT_NET_LOAD2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFMT_NET_LOAD2();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FMT_NET_LOAD2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnClose();
    CEdit m_Edit_Arc2_FMT_Freq01;
    CEdit m_Edit_Arc2_FMT_Freq02;
    CEdit m_Edit_Arc2_FMT_Freq03;
    CEdit m_Edit_Arc2_FMT_Freq04;
    CEdit m_Edit_Arc2_FMT_Freq05;
    CEdit m_Edit_Arc2_FMT_Freq06;
    CEdit m_Edit_Arc2_FMT_Freq07;
    CEdit m_Edit_Arc2_FMT_Freq08;
    CEdit m_Edit_Arc2_FMT_Freq09;
    CEdit m_Edit_Arc2_FMT_Freq10;
    CEdit m_Edit_Arc2_FMT_Freq11;
    CEdit m_Edit_Arc2_FMT_Freq12;
    CEdit m_Edit_Arc2_FMT_Freq13;
    CEdit m_Edit_Arc2_FMT_Freq14;
    CEdit m_Edit_Arc2_FMT_Freq15;
    CEdit m_Edit_Arc2_FMT_Freq16;

    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY01;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY02;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY03;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY04;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY05;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY06;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY07;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY08;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY09;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY10;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY11;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY12;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY13;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY14;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY15;
    UNION_FMT_NET_FREQUENCY un_FMT_NET_FREQUENCY16;
    afx_msg void OnBnClickedBtnArc2FmtDataLoad();
    virtual BOOL OnInitDialog();
    U16BIT MSG_FMT_NET_FREQUENCY[BUFSIZE];
    void FMT_NET_Freq_Init(CEdit* p_Edit, UNION_FMT_NET_FREQUENCY* p_UNION_FMT_NET_FREQUENCY);
    CString NumToCString(UNION_FMT_NET_FREQUENCY* p_UNION_FMT_NET_FREQUENCY);
};
