// MWOD_LOAD_STATUS2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "MWOD_LOAD_STATUS2.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"


// CMWOD_LOAD_STATUS2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMWOD_LOAD_STATUS2, CDialogEx)

CMWOD_LOAD_STATUS2::CMWOD_LOAD_STATUS2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMWOD_LOAD_STATUS2::IDD, pParent)
{

}

CMWOD_LOAD_STATUS2::~CMWOD_LOAD_STATUS2()
{
}

void CMWOD_LOAD_STATUS2::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LED_ARC2_VALID_RANGE, m_LED_ARC2_VALID_RANGE);
    DDX_Control(pDX, IDC_TEXT_ARC2_MWOD1, m_TEXT_ARC2_MWOD1);
    DDX_Control(pDX, IDC_TEXT_ARC2_MWOD2, m_TEXT_ARC2_MWOD2);
    DDX_Control(pDX, IDC_TEXT_ARC2_MWOD3, m_TEXT_ARC2_MWOD3);
    DDX_Control(pDX, IDC_TEXT_ARC2_MWOD4, m_TEXT_ARC2_MWOD4);
    DDX_Control(pDX, IDC_TEXT_ARC2_MWOD5, m_TEXT_ARC2_MWOD5);
    DDX_Control(pDX, IDC_TEXT_ARC2_MWOD6, m_TEXT_ARC2_MWOD6);
}


BEGIN_MESSAGE_MAP(CMWOD_LOAD_STATUS2, CDialogEx)
    ON_WM_CLOSE()
    ON_WM_TIMER()
END_MESSAGE_MAP()


// CMWOD_LOAD_STATUS2 메시지 처리기입니다.


void CMWOD_LOAD_STATUS2::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    KillTimer(MWOD_STATUS_2);
    DestroyWindow();
    CDialogEx::OnClose();
}


BOOL CMWOD_LOAD_STATUS2::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetTimer(MWOD_STATUS_2, 300, NULL);

    return TRUE;
}


void CMWOD_LOAD_STATUS2::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    aceBCDataBlkRead(DevNum, DBLK44, wBuffer_MWOD, 4, 0);


    ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_LOAD_STATUS_ARC2.w_MWOD_LOAD_STATUS = wBuffer_MWOD[0];
    ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC2.w_MWOD_A_AND_B_DAY = wBuffer_MWOD[1];
    ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC2.w_MWOD_A_AND_B_DAY = wBuffer_MWOD[2];
    ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC2.w_MWOD_A_AND_B_DAY = wBuffer_MWOD[3];

    if(((CITC_GUI_01Dlg *)GetParent())->un_MWOD_LOAD_STATUS_ARC2.st_MWOD_LOAD_STATUS.ValidRange == 0x0)
    {
        ((CITC_GUI_01Dlg *)GetParent())->ChangeIcon(&m_LED_ARC2_VALID_RANGE, 1);
    }
    else if(((CITC_GUI_01Dlg *)GetParent())->un_MWOD_LOAD_STATUS_ARC2.st_MWOD_LOAD_STATUS.ValidRange == 0x1)
    {
        ((CITC_GUI_01Dlg *)GetParent())->ChangeIcon(&m_LED_ARC2_VALID_RANGE, 0);
    }

    CString str_MWOD_Day;
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODADay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODADay1);
    m_TEXT_ARC2_MWOD1.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODBDay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_1_AND_2_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODBDay1);
    m_TEXT_ARC2_MWOD2.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODADay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODADay1);
    m_TEXT_ARC2_MWOD3.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODBDay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_3_AND_4_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODBDay1);
    m_TEXT_ARC2_MWOD4.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODADay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODADay1);
    m_TEXT_ARC2_MWOD5.SetWindowTextW(str_MWOD_Day);
    str_MWOD_Day.Format(_T("%d%d"),  ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODBDay10, ((CITC_GUI_01Dlg *)GetParent())->un_MWOD_5_AND_6_DAY_ARC2.st_MWOD_A_AND_B_DAY.MWODBDay1);
    m_TEXT_ARC2_MWOD6.SetWindowTextW(str_MWOD_Day);

    CDialogEx::OnTimer(nIDEvent);
}
