
// DlgProxy.cpp : ���� ����
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "DlgProxy.h"
#include "ITC_GUI_01Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CITC_GUI_01DlgAutoProxy

IMPLEMENT_DYNCREATE(CITC_GUI_01DlgAutoProxy, CCmdTarget)

CITC_GUI_01DlgAutoProxy::CITC_GUI_01DlgAutoProxy()
{
	EnableAutomation();
	
	// �ڵ�ȭ ��ü�� Ȱ��ȭ�Ǿ� �ִ� ���� ��� ���� ���α׷��� �����ϱ� ���� 
	//	�����ڿ��� AfxOleLockApp�� ȣ���մϴ�.
	AfxOleLockApp();

	// ���� ���α׷��� �� â �����͸� ���� ��ȭ ���ڿ� ����
	//  �׼����� �����ɴϴ�. ���Ͻ��� ���� �����͸� �����Ͽ�
	//  ��ȭ ���ڸ� ����Ű�� ��ȭ ������ �Ĺ� �����͸� �� ���Ͻ÷�
	//  �����մϴ�.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CITC_GUI_01Dlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CITC_GUI_01Dlg)))
		{
			m_pDialog = reinterpret_cast<CITC_GUI_01Dlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CITC_GUI_01DlgAutoProxy::~CITC_GUI_01DlgAutoProxy()
{
	// ��� ��ü�� OLE �ڵ�ȭ�� ��������� �� ���� ���α׷��� �����ϱ� ����
	// 	�Ҹ��ڰ� AfxOleUnlockApp�� ȣ���մϴ�.
	//  �̷��� ȣ��� �� ��ȭ ���ڰ� ������ �� �ֽ��ϴ�.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CITC_GUI_01DlgAutoProxy::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CITC_GUI_01DlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CITC_GUI_01DlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ����: IID_IITC_GUI_01�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�.
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {6B05AC16-D1C7-4DCE-B56C-4EC1E6ACA41B}
static const IID IID_IITC_GUI_01 =
{ 0x6B05AC16, 0xD1C7, 0x4DCE, { 0xB5, 0x6C, 0x4E, 0xC1, 0xE6, 0xAC, 0xA4, 0x1B } };

BEGIN_INTERFACE_MAP(CITC_GUI_01DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CITC_GUI_01DlgAutoProxy, IID_IITC_GUI_01, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ��ũ�ΰ� �� ������Ʈ�� StdAfx.h�� ���ǵ˴ϴ�.
// {429EBE3E-3D76-4298-9B50-EBA4C47632DA}
IMPLEMENT_OLECREATE2(CITC_GUI_01DlgAutoProxy, "ITC_GUI_01.Application", 0x429ebe3e, 0x3d76, 0x4298, 0x9b, 0x50, 0xeb, 0xa4, 0xc4, 0x76, 0x32, 0xda)


// CITC_GUI_01DlgAutoProxy �޽��� ó����
