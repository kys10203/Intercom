
// ITC_GUI_01.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CITC_GUI_01App:
// �� Ŭ������ ������ ���ؼ��� ITC_GUI_01.cpp�� �����Ͻʽÿ�.
//

class CITC_GUI_01App : public CWinApp
{
public:
	CITC_GUI_01App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CITC_GUI_01App theApp;