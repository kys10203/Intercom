
// DlgProxy.cpp : 구현 파일
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
	
	// 자동화 개체가 활성화되어 있는 동안 계속 응용 프로그램을 실행하기 위해 
	//	생성자에서 AfxOleLockApp를 호출합니다.
	AfxOleLockApp();

	// 응용 프로그램의 주 창 포인터를 통해 대화 상자에 대한
	//  액세스를 가져옵니다. 프록시의 내부 포인터를 설정하여
	//  대화 상자를 가리키고 대화 상자의 후방 포인터를 이 프록시로
	//  설정합니다.
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
	// 모든 개체가 OLE 자동화로 만들어졌을 때 응용 프로그램을 종료하기 위해
	// 	소멸자가 AfxOleUnlockApp를 호출합니다.
	//  이러한 호출로 주 대화 상자가 삭제될 수 있습니다.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CITC_GUI_01DlgAutoProxy::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CITC_GUI_01DlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CITC_GUI_01DlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 참고: IID_IITC_GUI_01에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다.
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {6B05AC16-D1C7-4DCE-B56C-4EC1E6ACA41B}
static const IID IID_IITC_GUI_01 =
{ 0x6B05AC16, 0xD1C7, 0x4DCE, { 0xB5, 0x6C, 0x4E, 0xC1, 0xE6, 0xAC, 0xA4, 0x1B } };

BEGIN_INTERFACE_MAP(CITC_GUI_01DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CITC_GUI_01DlgAutoProxy, IID_IITC_GUI_01, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 매크로가 이 프로젝트의 StdAfx.h에 정의됩니다.
// {429EBE3E-3D76-4298-9B50-EBA4C47632DA}
IMPLEMENT_OLECREATE2(CITC_GUI_01DlgAutoProxy, "ITC_GUI_01.Application", 0x429ebe3e, 0x3d76, 0x4298, 0x9b, 0x50, 0xeb, 0xa4, 0xc4, 0x76, 0x32, 0xda)


// CITC_GUI_01DlgAutoProxy 메시지 처리기
