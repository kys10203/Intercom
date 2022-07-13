#pragma once
#include "afxwin.h"
#include "stdemace.h"

#include "BIT_FIELD.h"

// CMWOD_LOAD_STATUS2 대화 상자입니다.

class CMWOD_LOAD_STATUS2 : public CDialogEx
{
	DECLARE_DYNAMIC(CMWOD_LOAD_STATUS2)

public:
	CMWOD_LOAD_STATUS2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMWOD_LOAD_STATUS2();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MWOD_LOAD_STATUS2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnClose();
    U16BIT wBuffer_MWOD[32];
    CStatic m_LED_ARC2_VALID_RANGE;
    CStatic m_TEXT_ARC2_MWOD1;
    CStatic m_TEXT_ARC2_MWOD2;
    CStatic m_TEXT_ARC2_MWOD3;
    CStatic m_TEXT_ARC2_MWOD4;
    CStatic m_TEXT_ARC2_MWOD5;
    CStatic m_TEXT_ARC2_MWOD6;
    virtual BOOL OnInitDialog();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
