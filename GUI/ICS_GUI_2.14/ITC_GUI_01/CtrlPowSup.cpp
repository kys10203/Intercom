// CtrlPowSup.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "CtrlPowSup.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CCtrlPowSup ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCtrlPowSup, CDialogEx)

CCtrlPowSup::CCtrlPowSup(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCtrlPowSup::IDD, pParent)
{

	EnableAutomation();

}

CCtrlPowSup::~CCtrlPowSup()
{
}

void CCtrlPowSup::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CDialogEx::OnFinalRelease();
}

void CCtrlPowSup::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT_VOLTAGE, m_Edit_Voltage);
    DDX_Control(pDX, IDC_EDIT_CURRENT, m_Edit_Current);
    DDX_Control(pDX, IDC_BTN_POW_ONOFF, m_BTN_PowOnOff);
}


BEGIN_MESSAGE_MAP(CCtrlPowSup, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_SET_POWER_OPTION, &CCtrlPowSup::OnBnClickedBtnSetPowerOption)
    ON_BN_CLICKED(IDC_BTN_POW_ONOFF, &CCtrlPowSup::OnBnClickedBtnPowOnoff)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCtrlPowSup, CDialogEx)
END_DISPATCH_MAP()

// ����: IID_ICtrlPowSup�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {FF4A1FF5-E9D8-41D2-823D-5BA83B84FD14}
static const IID IID_ICtrlPowSup =
{ 0xFF4A1FF5, 0xE9D8, 0x41D2, { 0x82, 0x3D, 0x5B, 0xA8, 0x3B, 0x84, 0xFD, 0x14 } };

BEGIN_INTERFACE_MAP(CCtrlPowSup, CDialogEx)
	INTERFACE_PART(CCtrlPowSup, IID_ICtrlPowSup, Dispatch)
END_INTERFACE_MAP()


// CCtrlPowSup �޽��� ó�����Դϴ�.


void CCtrlPowSup::OnBnClickedBtnSetPowerOption()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Create();

    if( ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Connect(IpAddr, nPort) == FALSE )
    {
        AfxMessageBox(_T("ERROR : Failed to connect PowerSupply"));
        ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Close();

        return;
    }

    GetDlgItemText( IDC_EDIT_VOLTAGE, volt );
    GetDlgItemText( IDC_EDIT_CURRENT, curr );

    ((CITC_GUI_01Dlg *)GetParent())->volt = volt;
        ((CITC_GUI_01Dlg *)GetParent())->curr = curr;

    str_volt = _T("volt ") + volt + _T("\n");
    str_curr = _T("curr ") + curr + _T("\n");

    CStringA voltA(str_volt);
    CStringA currA(str_curr);

    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Send(voltA, voltA.GetLength() * 2);
    Sleep(150);
    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Send(currA, currA.GetLength() * 2);

    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Close();
}


BOOL CCtrlPowSup::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    if(((CITC_GUI_01Dlg *)GetParent())->b_PowerSupp == FALSE)
        m_BTN_PowOnOff.SetWindowTextW(L"�������ޱ� ON");
    else
        m_BTN_PowOnOff.SetWindowTextW(L"�������ޱ� OFF");

    SetDlgItemText( IDC_EDIT_VOLTAGE, ((CITC_GUI_01Dlg *)GetParent())->volt );
    SetDlgItemText( IDC_EDIT_CURRENT, ((CITC_GUI_01Dlg *)GetParent())->curr );

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CCtrlPowSup::OnBnClickedBtnPowOnoff()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Create();

    if( ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Connect(IpAddr, nPort) == FALSE )
    {
        AfxMessageBox(_T("ERROR : Failed to connect PowerSupply"));
        ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Close();

        return;
    }

    if(((CITC_GUI_01Dlg *)GetParent())->b_PowerSupp == FALSE)
    {
        outp = _T("outp 1\n");
        m_BTN_PowOnOff.SetWindowTextW(L"�������ޱ� OFF");
        ((CITC_GUI_01Dlg *)GetParent())->b_PowerSupp = TRUE;
    }
    else
    {
        outp = _T("outp 0\n");
        m_BTN_PowOnOff.SetWindowTextW(L"�������ޱ� ON");
        ((CITC_GUI_01Dlg *)GetParent())->b_PowerSupp = FALSE;
    }

    CStringA outpA(outp);

    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Send(outpA, outpA.GetLength() * 2);
    Sleep(100);

    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Close();
}
