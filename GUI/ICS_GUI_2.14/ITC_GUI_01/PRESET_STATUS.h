#pragma once
#include "afxwin.h"
#include "stdemace.h"
#include "BIT_FIELD.h"

// CPRESET_STATUS ��ȭ �����Դϴ�.

class CPRESET_STATUS : public CDialogEx
{
	DECLARE_DYNAMIC(CPRESET_STATUS)

public:
	CPRESET_STATUS(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPRESET_STATUS();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PRESET_STATUS };

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
    CStatic m_TEXT_ARC1_GroupSelect;
    CStatic m_TEXT_ARC1_Freq01;
    CStatic m_TEXT_ARC1_Freq02;
    CStatic m_TEXT_ARC1_Freq03;
    CStatic m_TEXT_ARC1_Freq04;
    CStatic m_TEXT_ARC1_Freq05;
    CStatic m_TEXT_ARC1_Freq06;
    CStatic m_TEXT_ARC1_Freq07;
    CStatic m_TEXT_ARC1_Freq08;
    CStatic m_TEXT_ARC1_Freq09;
    CStatic m_TEXT_ARC1_Freq10;
    CStatic m_TEXT_ARC1_FreqMng01;
    CStatic m_TEXT_ARC1_FreqMng02;
    CStatic m_TEXT_ARC1_FreqMng03;
    CStatic m_TEXT_ARC1_FreqMng04;
    CStatic m_TEXT_ARC1_FreqMng05;
    CStatic m_TEXT_ARC1_FreqMng06;
    CStatic m_TEXT_ARC1_FreqMng07;
    CStatic m_TEXT_ARC1_FreqMng08;
    CStatic m_TEXT_ARC1_FreqMng09;
    CStatic m_TEXT_ARC1_FreqMng10;
};
