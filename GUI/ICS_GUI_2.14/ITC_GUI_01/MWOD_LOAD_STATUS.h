#pragma once
#include "afxwin.h"
#include "stdemace.h"

#include "BIT_FIELD.h"

// CMWOD_LOAD_STATUS ��ȭ �����Դϴ�.

class CMWOD_LOAD_STATUS : public CDialogEx
{
	DECLARE_DYNAMIC(CMWOD_LOAD_STATUS)

public:
	CMWOD_LOAD_STATUS(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMWOD_LOAD_STATUS();

	virtual void OnFinalRelease();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MWOD_LOAD_STATUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

    
public:
    virtual BOOL OnInitDialog();
    U16BIT wBuffer_MWOD[32];
    U16BIT m_MWODValidRange;
    CStatic m_LED_ARC1_VALID_RANGE;
    CStatic m_TEXT_ARC1_MWOD1;
    CStatic m_TEXT_ARC1_MWOD2;
    CStatic m_TEXT_ARC1_MWOD3;
    CStatic m_TEXT_ARC1_MWOD4;
    CStatic m_TEXT_ARC1_MWOD5;
    CStatic m_TEXT_ARC1_MWOD6;
    afx_msg void OnClose();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
