// SET_ETHERNET.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "SET_ETHERNET.h"
#include "afxdialogex.h"


// CSET_ETHERNET ��ȭ �����Դϴ�.

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
    // �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
    // OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
    // �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
    // �߰��Ͻʽÿ�.

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

// ����: IID_ISET_ETHERNET�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {4EBAF9A3-D8CA-4A87-A7EF-D99B1767E15E}
static const IID IID_ISET_ETHERNET =
{ 0x4EBAF9A3, 0xD8CA, 0x4A87, { 0xA7, 0xEF, 0xD9, 0x9B, 0x17, 0x67, 0xE1, 0x5E } };

BEGIN_INTERFACE_MAP(CSET_ETHERNET, CDialogEx)
    INTERFACE_PART(CSET_ETHERNET, IID_ISET_ETHERNET, Dispatch)
END_INTERFACE_MAP()


// CSET_ETHERNET �޽��� ó�����Դϴ�.


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
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    GetDlgItemText(IDC_IP_ADDRESS, m_str_setting_ip);
    GetDlgItemText(IDC_EDIT_PORT, m_str_setting_port);

    CDialog::OnOK();
}


BOOL CSET_ETHERNET::PreTranslateMessage(MSG* pMsg)
{
    // TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    if(pMsg->message == WM_KEYDOWN)
    {
        if(pMsg->wParam == VK_ESCAPE)
            return TRUE;
        else if(pMsg->wParam == VK_RETURN)
            return TRUE;
    }

    return CDialogEx::PreTranslateMessage(pMsg);
}
