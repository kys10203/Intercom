// MWOD_LOAD_STATUS.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "MWOD_LOAD_STATUS.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"


// CMWOD_LOAD_STATUS ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMWOD_LOAD_STATUS, CDialogEx)

CMWOD_LOAD_STATUS::CMWOD_LOAD_STATUS(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMWOD_LOAD_STATUS::IDD, pParent)
{

	EnableAutomation();

}

CMWOD_LOAD_STATUS::~CMWOD_LOAD_STATUS()
{
}

void CMWOD_LOAD_STATUS::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CDialogEx::OnFinalRelease();
}

void CMWOD_LOAD_STATUS::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LED_ARC1_VALID_RANGE, m_LED_ARC1_VALID_RANGE);
    DDX_Control(pDX, IDC_TEXT_ARC1_MWOD1, m_TEXT_ARC1_MWOD1);
    DDX_Control(pDX, IDC_TEXT_ARC1_MWOD2, m_TEXT_ARC1_MWOD2);
    DDX_Control(pDX, IDC_TEXT_ARC1_MWOD3, m_TEXT_ARC1_MWOD3);
    DDX_Control(pDX, IDC_TEXT_ARC1_MWOD4, m_TEXT_ARC1_MWOD4);
    DDX_Control(pDX, IDC_TEXT_ARC1_MWOD5, m_TEXT_ARC1_MWOD5);
    DDX_Control(pDX, IDC_TEXT_ARC1_MWOD6, m_TEXT_ARC1_MWOD6);
}


BEGIN_MESSAGE_MAP(CMWOD_LOAD_STATUS, CDialogEx)
    ON_WM_CLOSE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMWOD_LOAD_STATUS, CDialogEx)
END_DISPATCH_MAP()

// ����: IID_IMWOD_LOAD_STATUS�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {E7A4D5E4-58DF-4B65-8FAA-A50CA84B3FB8}
static const IID IID_IMWOD_LOAD_STATUS =
{ 0xE7A4D5E4, 0x58DF, 0x4B65, { 0x8F, 0xAA, 0xA5, 0xC, 0xA8, 0x4B, 0x3F, 0xB8 } };

BEGIN_INTERFACE_MAP(CMWOD_LOAD_STATUS, CDialogEx)
	INTERFACE_PART(CMWOD_LOAD_STATUS, IID_IMWOD_LOAD_STATUS, Dispatch)
END_INTERFACE_MAP()


// CMWOD_LOAD_STATUS �޽��� ó�����Դϴ�.


BOOL CMWOD_LOAD_STATUS::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // m_MWODValidRange = ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_LOAD_STATUS_ARC1.st_MWOD_LOAD_STATUS.ValidRange;
    SetTimer(MWOD_STATUS, 300, NULL);

    return TRUE;
}


void CMWOD_LOAD_STATUS::OnClose()
{
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
    KillTimer(MWOD_STATUS);
    DestroyWindow();
    CDialogEx::OnClose();
}


void CMWOD_LOAD_STATUS::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
    aceBCDataBlkRead(DevNum, DBLK4, wBuffer_MWOD, 4, 0);

    ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_LOAD_STATUS_ARC1.w_MWOD_LOAD_STATUS = wBuffer_MWOD[0];
    ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC1.w_MWOD_A_AND_B_DAY = wBuffer_MWOD[1];
    ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC1.w_MWOD_A_AND_B_DAY = wBuffer_MWOD[2];
    ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC1.w_MWOD_A_AND_B_DAY = wBuffer_MWOD[3];

    if(((CITC_GUI_01Dlg *)GetParent())->un_MWOD_LOAD_STATUS_ARC1.st_MWOD_LOAD_STATUS.ValidRange == 0x0)
    {
        ((CITC_GUI_01Dlg *)GetParent())->ChangeIcon(&m_LED_ARC1_VALID_RANGE, 1);
    }
    else if(((CITC_GUI_01Dlg *)GetParent())->un_MWOD_LOAD_STATUS_ARC1.st_MWOD_LOAD_STATUS.ValidRange == 0x1)
    {
        ((CITC_GUI_01Dlg *)GetParent())->ChangeIcon(&m_LED_ARC1_VALID_RANGE, 0);
    }

    CString str_MWOD_Day;
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODADay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODADay1);
    m_TEXT_ARC1_MWOD1.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODBDay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODBDay1);
    m_TEXT_ARC1_MWOD2.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODADay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODADay1);
    m_TEXT_ARC1_MWOD3.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODBDay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODBDay1);
    m_TEXT_ARC1_MWOD4.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODADay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODADay1);
    m_TEXT_ARC1_MWOD5.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODBDay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC1.st_MWOD_A_AND_B_DAY.MWODBDay1);
    m_TEXT_ARC1_MWOD6.SetWindowTextW(str_MWOD_Day);

    CDialogEx::OnTimer(nIDEvent);
}
