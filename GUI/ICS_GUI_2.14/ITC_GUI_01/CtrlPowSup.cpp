// CtrlPowSup.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "CtrlPowSup.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CCtrlPowSup 대화 상자입니다.

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
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

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

// 참고: IID_ICtrlPowSup에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {FF4A1FF5-E9D8-41D2-823D-5BA83B84FD14}
static const IID IID_ICtrlPowSup =
{ 0xFF4A1FF5, 0xE9D8, 0x41D2, { 0x82, 0x3D, 0x5B, 0xA8, 0x3B, 0x84, 0xFD, 0x14 } };

BEGIN_INTERFACE_MAP(CCtrlPowSup, CDialogEx)
	INTERFACE_PART(CCtrlPowSup, IID_ICtrlPowSup, Dispatch)
END_INTERFACE_MAP()


// CCtrlPowSup 메시지 처리기입니다.


void CCtrlPowSup::OnBnClickedBtnSetPowerOption()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
        m_BTN_PowOnOff.SetWindowTextW(L"전원공급기 ON");
    else
        m_BTN_PowOnOff.SetWindowTextW(L"전원공급기 OFF");

    SetDlgItemText( IDC_EDIT_VOLTAGE, ((CITC_GUI_01Dlg *)GetParent())->volt );
    SetDlgItemText( IDC_EDIT_CURRENT, ((CITC_GUI_01Dlg *)GetParent())->curr );

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CCtrlPowSup::OnBnClickedBtnPowOnoff()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
        m_BTN_PowOnOff.SetWindowTextW(L"전원공급기 OFF");
        ((CITC_GUI_01Dlg *)GetParent())->b_PowerSupp = TRUE;
    }
    else
    {
        outp = _T("outp 0\n");
        m_BTN_PowOnOff.SetWindowTextW(L"전원공급기 ON");
        ((CITC_GUI_01Dlg *)GetParent())->b_PowerSupp = FALSE;
    }

    CStringA outpA(outp);

    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Send(outpA, outpA.GetLength() * 2);
    Sleep(100);

    ((CITC_GUI_01Dlg *)GetParent())->m_ClientSocket.Close();
}
