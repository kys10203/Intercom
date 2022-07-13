#pragma once
#include "BIT_FIELD.h"
#include "afxwin.h"

// CMWOD_LOAD 대화 상자입니다.

class CMWOD_LOAD : public CDialogEx
{
	DECLARE_DYNAMIC(CMWOD_LOAD)

public:
	CMWOD_LOAD(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMWOD_LOAD();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MWOD_LOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    afx_msg void OnBnClickedBtnMwodDataLoad();
    U16BIT MWODEditToDouble(CEdit* EditAddr, UNION_WOD_SEGMENT* p_UNION_WOD_SEGMENT);
    CEdit m_WOD01;
    CEdit m_WOD02;
    CEdit m_WOD03;
    CEdit m_WOD04;
    CEdit m_WOD05;
    CEdit m_WOD06;
    CEdit m_WODD;

    WORD MSG_MWOD_Load[BUFSIZE];

    UNION_WOD_SEGMENT un_WOD_SEGMENT1;
    UNION_WOD_SEGMENT un_WOD_SEGMENT2;
    UNION_WOD_SEGMENT un_WOD_SEGMENT3;
    UNION_WOD_SEGMENT un_WOD_SEGMENT4;
    UNION_WOD_SEGMENT un_WOD_SEGMENT5;
    UNION_WOD_SEGMENT un_WOD_SEGMENT6;
    UNION_WOD_DAY un_WOD_DAY;
    virtual BOOL OnInitDialog();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnClose();
    void DpPrevSet(void);
    CString NumToString(U16BIT Hundreds, U16BIT Tens, U16BIT Ones, U16BIT Tenths, U16BIT Hundredths);
    void CheckPresentARC1Setting(void);
    U8BIT GetTODDay(CEdit* EditBox);
};
