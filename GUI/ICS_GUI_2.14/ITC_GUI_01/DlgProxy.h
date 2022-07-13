
// DlgProxy.h: 헤더 파일
//

#pragma once

class CITC_GUI_01Dlg;


// CITC_GUI_01DlgAutoProxy 명령 대상

class CITC_GUI_01DlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CITC_GUI_01DlgAutoProxy)

	CITC_GUI_01DlgAutoProxy();           // 동적 만들기에 사용되는 protected 생성자입니다.

// 특성입니다.
public:
	CITC_GUI_01Dlg* m_pDialog;

// 작업입니다.
public:

// 재정의입니다.
	public:
	virtual void OnFinalRelease();

// 구현입니다.
protected:
	virtual ~CITC_GUI_01DlgAutoProxy();

	// 생성된 메시지 맵 함수

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CITC_GUI_01DlgAutoProxy)

	// 생성된 OLE 디스패치 맵 함수

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

