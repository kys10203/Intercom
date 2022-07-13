// MWOD_LOAD_STATUS.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "MWOD_LOAD_STATUS.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"


// CMWOD_LOAD_STATUS 대화 상자입니다.

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
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

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

// 참고: IID_IMWOD_LOAD_STATUS에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {E7A4D5E4-58DF-4B65-8FAA-A50CA84B3FB8}
static const IID IID_IMWOD_LOAD_STATUS =
{ 0xE7A4D5E4, 0x58DF, 0x4B65, { 0x8F, 0xAA, 0xA5, 0xC, 0xA8, 0x4B, 0x3F, 0xB8 } };

BEGIN_INTERFACE_MAP(CMWOD_LOAD_STATUS, CDialogEx)
	INTERFACE_PART(CMWOD_LOAD_STATUS, IID_IMWOD_LOAD_STATUS, Dispatch)
END_INTERFACE_MAP()


// CMWOD_LOAD_STATUS 메시지 처리기입니다.


BOOL CMWOD_LOAD_STATUS::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // m_MWODValidRange = ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_LOAD_STATUS_ARC1.st_MWOD_LOAD_STATUS.ValidRange;
    SetTimer(MWOD_STATUS, 300, NULL);

    return TRUE;
}


void CMWOD_LOAD_STATUS::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    KillTimer(MWOD_STATUS);
    DestroyWindow();
    CDialogEx::OnClose();
}


void CMWOD_LOAD_STATUS::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
