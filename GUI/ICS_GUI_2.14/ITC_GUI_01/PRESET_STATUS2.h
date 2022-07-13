#pragma once
#include "afxwin.h"
#include "stdemace.h"
#include "BIT_FIELD.h"

// CPRESET_STATUS2 ��ȭ �����Դϴ�.

class CPRESET_STATUS2 : public CDialogEx
{
	DECLARE_DYNAMIC(CPRESET_STATUS2)

public:
	CPRESET_STATUS2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPRESET_STATUS2();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PRESET_STATUS2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnClose();
    afx_msg void OnTimer(UINT_PTR nIDEvent);

    U16BIT wBuffer_PRESET[32];
    CStatic m_TEXT_ARC2_GroupSelect;
    CStatic m_TEXT_ARC2_Freq01;
    CStatic m_TEXT_ARC2_Freq02;
    CStatic m_TEXT_ARC2_Freq03;
    CStatic m_TEXT_ARC2_Freq04;
    CStatic m_TEXT_ARC2_Freq05;
    CStatic m_TEXT_ARC2_Freq06;
    CStatic m_TEXT_ARC2_Freq07;
    CStatic m_TEXT_ARC2_Freq08;
    CStatic m_TEXT_ARC2_Freq09;
    CStatic m_TEXT_ARC2_Freq10;
    CStatic m_TEXT_ARC2_FreqMng01;
    CStatic m_TEXT_ARC2_FreqMng02;
    CStatic m_TEXT_ARC2_FreqMng03;
    CStatic m_TEXT_ARC2_FreqMng04;
    CStatic m_TEXT_ARC2_FreqMng05;
    CStatic m_TEXT_ARC2_FreqMng06;
    CStatic m_TEXT_ARC2_FreqMng07;
    CStatic m_TEXT_ARC2_FreqMng08;
    CStatic m_TEXT_ARC2_FreqMng09;
    CStatic m_TEXT_ARC2_FreqMng10;
};
