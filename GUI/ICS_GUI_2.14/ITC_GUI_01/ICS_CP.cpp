// ICS_CP.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "ICS_CP.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"


// CICS_CP 대화 상자입니다.

IMPLEMENT_DYNAMIC(CICS_CP, CDialogEx)

    CICS_CP::CICS_CP(CWnd* pParent /*=NULL*/)
    : CDialogEx(CICS_CP::IDD, pParent)
    , f_SET_DIS(FALSE)
    , wResult(0)
{

    EnableAutomation();

}

CICS_CP::~CICS_CP()
{
}

void CICS_CP::OnFinalRelease()
{
    // 자동화 개체에 대한 마지막 참조가 해제되면
    // OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
    // 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
    // 추가하십시오.

    CDialogEx::OnFinalRelease();
}

void CICS_CP::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_SEL_ICP1, m_combo_sel_icp1);
    DDX_Control(pDX, IDC_COMBO_SEL_ICP2, m_combo_sel_icp2);
    DDX_Control(pDX, IDC_COMBO_COMSEC_IF, m_combo_comsec_if);
    DDX_Control(pDX, IDC_CHECK_WOW, m_check_WOW);
}


BEGIN_MESSAGE_MAP(CICS_CP, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_SET_DIST, &CICS_CP::OnBnClickedBtnSetDist)
    ON_BN_CLICKED(IDC_BTN_SET_ICS, &CICS_CP::OnBnClickedBtnSetIcs)
    ON_MESSAGE(UWM_ICS_DIS, &CICS_CP::OnUwmIcsDis)
    ON_BN_CLICKED(IDC_BTN_IBIT, &CICS_CP::OnBnClickedBtnIbit)
    ON_WM_TIMER()
    ON_MESSAGE(UWM_DP_ICS_DIS, &CICS_CP::OnUwmDpIcsDis)
    ON_WM_CLOSE()
    ON_BN_CLICKED(IDC_BTN_VMU, &CICS_CP::OnBnClickedBtnVmu)
    ON_BN_CLICKED(IDC_BTN_WARNING_RESET, &CICS_CP::OnBnClickedBtnWarningReset)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CICS_CP, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IICS_CP에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {92F4EE27-6C21-4324-9128-76FF0519ADF2}
static const IID IID_IICS_CP =
{ 0x92F4EE27, 0x6C21, 0x4324, { 0x91, 0x28, 0x76, 0xFF, 0x5, 0x19, 0xAD, 0xF2 } };

BEGIN_INTERFACE_MAP(CICS_CP, CDialogEx)
    INTERFACE_PART(CICS_CP, IID_IICS_CP, Dispatch)
END_INTERFACE_MAP()


// CICS_CP 메시지 처리기입니다.


void CICS_CP::OnBnClickedBtnSetDist()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    // m_CITC_SET_DIS.DoModal();
    p_CITC_SET_DIS = new CITC_SET_DIS;
    f_SET_DIS = p_CITC_SET_DIS->Create(IDD_ITC_SET_DIS);
    p_CITC_SET_DIS->ShowWindow(SW_SHOW);
}


BOOL CICS_CP::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    m_combo_sel_icp1.AddString(_T("COM1"));
    m_combo_sel_icp1.AddString(_T("COM2"));
    m_combo_sel_icp1.AddString(_T("COM3"));
    m_combo_sel_icp1.AddString(_T("COM4"));

    m_combo_sel_icp2.AddString(_T("COM1"));
    m_combo_sel_icp2.AddString(_T("COM2"));
    m_combo_sel_icp2.AddString(_T("COM3"));
    m_combo_sel_icp2.AddString(_T("COM4"));

    m_combo_comsec_if.AddString(_T("미연동"));
    m_combo_comsec_if.AddString(_T("COM2 연동"));
    m_combo_comsec_if.AddString(_T("COM3 연동"));

    un_ICS_CONTROL1.w_ICS_CONTROL1 = 0x0000;
    un_ICS_CONTROL2.w_ICS_CONTROL2 = 0x0000;
    un_ICS_CONTROL3.w_ICS_CONTROL3 = 0x0000;
    un_ICS_CONTROL4.w_ICS_CONTROL4 = 0x0000;

    un_VOICE_WARNING_MESSAGE1.w_VOICE_WARNING_MESSAGE1 = 0x0800;
    un_VOICE_WARNING_MESSAGE2.w_VOICE_WARNING_MESSAGE2 = 0x0842;
    un_VOICE_WARNING_MESSAGE3.w_VOICE_WARNING_MESSAGE3 = 0x0842;
    un_VOICE_WARNING_MESSAGE4.w_VOICE_WARNING_MESSAGE4 = 0x0842;
    un_VOICE_WARNING_MESSAGE5.w_VOICE_WARNING_MESSAGE5 = 0x0842;
    un_VOICE_WARNING_MESSAGE6.w_VOICE_WARNING_MESSAGE6 = 0x0842;
    un_VOICE_WARNING_MESSAGE7.w_VOICE_WARNING_MESSAGE7 = 0x0842;
    un_VOICE_WARNING_MESSAGE8.w_VOICE_WARNING_MESSAGE8 = 0x0842;
    un_VOICE_WARNING_MESSAGE9.w_VOICE_WARNING_MESSAGE9 = 0x0000;

    ComsecMsg[0] = 0xD3;
    ComsecMsg[1] = 0x08;
    ComsecMsg[2] = 0x33;
    ComsecMsg[3] = 0x01;
    ComsecMsg[4] = 0x04;
    ComsecMsg[5] = 0x02;
    ComsecMsg[6] = 0x01;
    ComsecMsg[7] = 0x04;
    ComsecMsg[8] = 0x01;
    ComsecMsg[9] = 0x02;
    ComsecMsg[10] = 0x3F;
    ComsecMsg[11] = 0x01;
    ComsecMsg[12] = 0x7F;

    ComsecMsg2[0] = 0xD3;
    ComsecMsg2[1] = 0x08;
    ComsecMsg2[2] = 0x33;
    ComsecMsg2[3] = 0x01;
    ComsecMsg2[4] = 0x04;
    ComsecMsg2[5] = 0x02;
    ComsecMsg2[6] = 0x01;
    ComsecMsg2[7] = 0x04;
    ComsecMsg2[8] = 0x01;
    ComsecMsg2[9] = 0x02;
    ComsecMsg2[10] = 0x3F;
    ComsecMsg2[11] = 0x00;
    ComsecMsg2[12] = 0x7F;

    m_combo_sel_icp1.SetCurSel( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForPilot );
    m_combo_sel_icp2.SetCurSel( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForCopilot );
    m_combo_comsec_if.SetCurSel( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ICS_CONTROL4.st_ICS_CONTROL4.ComSecInterfaceControl );
    m_check_WOW.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ICS_CONTROL1.st_ICS_CONTROL1.WeightOnWheelState );

    // SetTimer(999, 1000, NULL);
    //CString str;
    //str.Format(L"> %02x  %02x  %02x  %02x", ReadMsg[10], ReadMsg[11], ReadMsg[12], ReadMsg[13]);
    //AfxMessageBox(str);

    return TRUE;  // return TRUE unless you set the focus to a control

}


afx_msg LRESULT CICS_CP::OnUwmIcsDis(WPARAM wParam, LPARAM lParam)
{
    // memcpy(WriteMsg, m_CITC_SET_DIS.WriteMsg, sizeof(m_CITC_SET_DIS.WriteMsg));
    // ((CITC_GUI_01Dlg *)AfxGetMainWnd())->AddEventString(_T("> OnBnClickedBtnSetDist"));

    // send(((CITC_GUI_01Dlg *)GetParent())->mh_socket, WriteMsg, 26, 0); 

    return 0;
}


afx_msg LRESULT CICS_CP::OnUwmDpIcsDis(WPARAM wParam, LPARAM lParam)
{
    if(f_SET_DIS)
        ::SendMessage(p_CITC_SET_DIS->m_hWnd, UWM_DP_ICS_DIS, NULL, NULL);
    memcpy(ReadMsg, ((CITC_GUI_01Dlg *)GetParent())->RecvMsg, sizeof(((CITC_GUI_01Dlg *)GetParent())->RecvMsg));
    return 0;
}


void CICS_CP::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    DestroyWindow();
    CDialogEx::OnClose();
}


void CICS_CP::OnBnClickedBtnSetIcs()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    //::SendMessage(((CITC_GUI_01Dlg*)GetParent())->m_hWnd, UWM_ICS_DIS, NULL, NULL);
    CheckICSSetting();

    if(m_combo_comsec_if.GetCurSel() == 0)
    {
        un_ICS_CONTROL4.st_ICS_CONTROL4.ComSecInterfaceControl = 0x0;
    }
    else if(m_combo_comsec_if.GetCurSel() == 1)
    {
        un_ICS_CONTROL4.st_ICS_CONTROL4.ComSecInterfaceControl = 0x1;
    }
    else if(m_combo_comsec_if.GetCurSel() == 2)
    {
        un_ICS_CONTROL4.st_ICS_CONTROL4.ComSecInterfaceControl = 0x2;
    }

    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[0] = un_ICS_CONTROL1.w_ICS_CONTROL1;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[1] = un_ICS_CONTROL2.w_ICS_CONTROL2;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[2] = un_ICS_CONTROL3.w_ICS_CONTROL3;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[3] = un_ICS_CONTROL4.w_ICS_CONTROL4;

    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ICS_CONTROL1.w_ICS_CONTROL1 = un_ICS_CONTROL1.w_ICS_CONTROL1;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ICS_CONTROL4.w_ICS_CONTROL4 = un_ICS_CONTROL4.w_ICS_CONTROL4;

    aceBCDataBlkWrite(DevNum, DBLK31, ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT, 16, 0);
}


void CICS_CP::CheckICSSetting(void)
{

    switch(m_combo_sel_icp1.GetCurSel())
    {
    case 0:
        un_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForPilot = 0x0;
        break;
    case 1:
        un_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForPilot = 0x1;
        break;
    case 2:
        un_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForPilot = 0x2;
        break;
    case 3:
        un_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForPilot = 0x3;
        break;
    }

    switch(m_combo_sel_icp2.GetCurSel())
    {
    case 0:
        un_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForCopilot = 0x0;
        break;
    case 1:
        un_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForCopilot = 0x1;
        break;
    case 2:
        un_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForCopilot = 0x2;
        break;
    case 3:
        un_ICS_CONTROL1.st_ICS_CONTROL1.SelectedRadioForCopilot = 0x3;
        break;
    }

    un_ICS_CONTROL1.st_ICS_CONTROL1.WeightOnWheelState = m_check_WOW.GetCheck();
}


void CICS_CP::OnBnClickedBtnVmu()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_CVOICE_MESSAGE = new CVOICE_MESSAGE;
    p_CVOICE_MESSAGE->Create(IDD_VOICE_MESSAGE);
    p_CVOICE_MESSAGE->ShowWindow(SW_SHOW);
}


void CICS_CP::OnBnClickedBtnIbit()  // BIT Initiate
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    un_ICS_CONTROL1.st_ICS_CONTROL1.BITInitiate = 0x1;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[0] = un_ICS_CONTROL1.w_ICS_CONTROL1;

    aceBCDataBlkWrite(DevNum, DBLK31, ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT, 16, 0);
    SetTimer(IBIT, 160, NULL);
}


void CICS_CP::OnBnClickedBtnWarningReset()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    un_ICS_CONTROL2.st_ICS_CONTROL2.ClearCurrentVoiceWarning = 0x1;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[1] = un_ICS_CONTROL2.w_ICS_CONTROL2;

    aceBCDataBlkWrite(DevNum, DBLK31, ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT, 16, 0);
    SetTimer(WARNIG_RST, 160, NULL);
}


void CICS_CP::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    // memcpy(ReadMsg, ((CITC_GUI_01Dlg *)GetParent())->RecvMsg, sizeof(((CITC_GUI_01Dlg *)GetParent())->RecvMsg));
    switch(nIDEvent)
    {
    case IBIT:
        un_ICS_CONTROL1.st_ICS_CONTROL1.BITInitiate = 0x0;
        ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[0] = un_ICS_CONTROL1.w_ICS_CONTROL1;
        aceBCDataBlkWrite(DevNum, DBLK31, ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT, 16, 0);
        KillTimer(IBIT);
        break;

    case WARNIG_RST:
        un_ICS_CONTROL2.st_ICS_CONTROL2.ClearCurrentVoiceWarning = 0x0;
        ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[1] = un_ICS_CONTROL2.w_ICS_CONTROL2;
        aceBCDataBlkWrite(DevNum, DBLK31, ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT, 16, 0);
        KillTimer(WARNIG_RST);
        break;
    }
    CDialogEx::OnTimer(nIDEvent);
}