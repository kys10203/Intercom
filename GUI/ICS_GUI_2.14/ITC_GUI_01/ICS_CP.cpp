// ICS_CP.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "ICS_CP.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"


// CICS_CP ��ȭ �����Դϴ�.

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
    // �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
    // OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
    // �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
    // �߰��Ͻʽÿ�.

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

// ����: IID_IICS_CP�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {92F4EE27-6C21-4324-9128-76FF0519ADF2}
static const IID IID_IICS_CP =
{ 0x92F4EE27, 0x6C21, 0x4324, { 0x91, 0x28, 0x76, 0xFF, 0x5, 0x19, 0xAD, 0xF2 } };

BEGIN_INTERFACE_MAP(CICS_CP, CDialogEx)
    INTERFACE_PART(CICS_CP, IID_IICS_CP, Dispatch)
END_INTERFACE_MAP()


// CICS_CP �޽��� ó�����Դϴ�.


void CICS_CP::OnBnClickedBtnSetDist()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

    m_combo_comsec_if.AddString(_T("�̿���"));
    m_combo_comsec_if.AddString(_T("COM2 ����"));
    m_combo_comsec_if.AddString(_T("COM3 ����"));

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
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
    DestroyWindow();
    CDialogEx::OnClose();
}


void CICS_CP::OnBnClickedBtnSetIcs()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    p_CVOICE_MESSAGE = new CVOICE_MESSAGE;
    p_CVOICE_MESSAGE->Create(IDD_VOICE_MESSAGE);
    p_CVOICE_MESSAGE->ShowWindow(SW_SHOW);
}


void CICS_CP::OnBnClickedBtnIbit()  // BIT Initiate
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    un_ICS_CONTROL1.st_ICS_CONTROL1.BITInitiate = 0x1;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[0] = un_ICS_CONTROL1.w_ICS_CONTROL1;

    aceBCDataBlkWrite(DevNum, DBLK31, ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT, 16, 0);
    SetTimer(IBIT, 160, NULL);
}


void CICS_CP::OnBnClickedBtnWarningReset()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    un_ICS_CONTROL2.st_ICS_CONTROL2.ClearCurrentVoiceWarning = 0x1;
    ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT[1] = un_ICS_CONTROL2.w_ICS_CONTROL2;

    aceBCDataBlkWrite(DevNum, DBLK31, ((CITC_GUI_01Dlg *)GetParent())->MSG_AIU_BC2RT, 16, 0);
    SetTimer(WARNIG_RST, 160, NULL);
}


void CICS_CP::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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