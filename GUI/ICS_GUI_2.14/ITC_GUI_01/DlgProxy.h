
// DlgProxy.h: ��� ����
//

#pragma once

class CITC_GUI_01Dlg;


// CITC_GUI_01DlgAutoProxy ��� ���

class CITC_GUI_01DlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CITC_GUI_01DlgAutoProxy)

	CITC_GUI_01DlgAutoProxy();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.

// Ư���Դϴ�.
public:
	CITC_GUI_01Dlg* m_pDialog;

// �۾��Դϴ�.
public:

// �������Դϴ�.
	public:
	virtual void OnFinalRelease();

// �����Դϴ�.
protected:
	virtual ~CITC_GUI_01DlgAutoProxy();

	// ������ �޽��� �� �Լ�

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CITC_GUI_01DlgAutoProxy)

	// ������ OLE ����ġ �� �Լ�

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

