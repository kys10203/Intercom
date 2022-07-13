// SET_ETHERNET.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "SET_ETHERNET.h"
#include "afxdialogex.h"


// CSET_ETHERNET 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSET_ETHERNET, CDialogEx)

    CSET_ETHERNET::CSET_ETHERNET(CWnd* pParent /*=NULL*/)
    : CDialogEx(CSET_ETHERNET::IDD, pParent)
    , m_str_setting_ip(_T(""))
    , m_str_setting_port(_T(""))
{

    EnableAutomation();

}

CSET_ETHERNET::~CSET_ETHERNET()
{
}

void CSET_ETHERNET::OnFinalRelease()
{
    // 자동화 개체에 대한 마지막 참조가 해제되면
    // OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
    // 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
    // 추가하십시오.

    CDialogEx::OnFinalRelease();
}

void CSET_ETHERNET::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSET_ETHERNET, CDialogEx)
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_BTN_WRITE, &CSET_ETHERNET::OnBnClickedBtnWrite)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSET_ETHERNET, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ISET_ETHERNET에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {4EBAF9A3-D8CA-4A87-A7EF-D99B1767E15E}
static const IID IID_ISET_ETHERNET =
{ 0x4EBAF9A3, 0xD8CA, 0x4A87, { 0xA7, 0xEF, 0xD9, 0x9B, 0x17, 0x67, 0xE1, 0x5E } };

BEGIN_INTERFACE_MAP(CSET_ETHERNET, CDialogEx)
    INTERFACE_PART(CSET_ETHERNET, IID_ISET_ETHERNET, Dispatch)
END_INTERFACE_MAP()


// CSET_ETHERNET 메시지 처리기입니다.


BOOL CSET_ETHERNET::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetDlgItemText(IDC_IP_ADDRESS, m_str_setting_ip);
    SetDlgItemText(IDC_EDIT_PORT, m_str_setting_port);

    return TRUE;  // return TRUE unless you set the focus to a control
}


HBRUSH CSET_ETHERNET::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    UINT nID = pWnd -> GetDlgCtrlID();

    switch(nID)
    {
    case IDC_STATIC_SET_ETHERNET:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    case IDC_STATIC_SET_1553B:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    }

    return hbr;
}


void CSET_ETHERNET::OnBnClickedBtnWrite()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    GetDlgItemText(IDC_IP_ADDRESS, m_str_setting_ip);
    GetDlgItemText(IDC_EDIT_PORT, m_str_setting_port);

    CDialog::OnOK();
}


BOOL CSET_ETHERNET::PreTranslateMessage(MSG* pMsg)
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    if(pMsg->message == WM_KEYDOWN)
    {
        if(pMsg->wParam == VK_ESCAPE)
            return TRUE;
        else if(pMsg->wParam == VK_RETURN)
            return TRUE;
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}
