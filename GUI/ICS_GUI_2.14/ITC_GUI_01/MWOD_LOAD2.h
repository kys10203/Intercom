#pragma once
#include "BIT_FIELD.h"
#include "afxwin.h"

// CMWOD_LOAD2 대화 상자입니다.

class CMWOD_LOAD2 : public CDialogEx
{
	DECLARE_DYNAMIC(CMWOD_LOAD2)

public:
	CMWOD_LOAD2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMWOD_LOAD2();

	virtual void OnFinalRelease();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MWOD_LOAD2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    CEdit m_WOD01_2;
    CEdit m_WOD02_2;
    CEdit m_WOD03_2;
    CEdit m_WOD04_2;
    CEdit m_WOD05_2;
    CEdit m_WOD06_2;
    CEdit m_WODD_2;

    WORD MSG_MWOD_Load[BUFSIZE];

    UNION_WOD_SEGMENT un_WOD_SEGMENT1;
    UNION_WOD_SEGMENT un_WOD_SEGMENT2;
    UNION_WOD_SEGMENT un_WOD_SEGMENT3;
    UNION_WOD_SEGMENT un_WOD_SEGMENT4;
    UNION_WOD_SEGMENT un_WOD_SEGMENT5;
    UNION_WOD_SEGMENT un_WOD_SEGMENT6;
    UNION_WOD_DAY un_WOD_DAY;
    afx_msg void OnBnClickedBtnMwodDataLoad2();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnClose();
    U16BIT MWODEditToDouble(CEdit* EditAddr, UNION_WOD_SEGMENT* p_WOD_SEGMENT);
    virtual BOOL OnInitDialog();
    void DpPrevSet(void);
    CString NumToString(U16BIT Hundreds, U16BIT Tens, U16BIT Ones, U16BIT Tenths, U16BIT Hundredths);
    void CheckPresentARC2Setting(void);
    U8BIT GetTODDay(CEdit* EditBox);
};
