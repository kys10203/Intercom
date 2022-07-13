// SET_ARC2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "SET_ARC2.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CSET_ARC2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSET_ARC2, CDialogEx)

    CSET_ARC2::CSET_ARC2(CWnd* pParent /*=NULL*/)
    : CDialogEx(CSET_ARC2::IDD, pParent)
{

    EnableAutomation();

}

CSET_ARC2::~CSET_ARC2()
{
}

void CSET_ARC2::OnFinalRelease()
{
    // 자동화 개체에 대한 마지막 참조가 해제되면
    // OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
    // 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
    // 추가하십시오.

    CDialogEx::OnFinalRelease();
}

void CSET_ARC2::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_ARC2_RF_POWER, m_combo_arc2_rf_power);
    DDX_Control(pDX, IDC_COMBO_ARC2_TOD_MANAGE, m_combo_arc2_tod_manage);
    DDX_Control(pDX, IDC_COMBO_ARC2_MODE, m_combo_arc2_mode);
    DDX_Control(pDX, IDC_COMBO_ARC2_OP_MODE, m_combo_arc2_op_mode);
    DDX_Control(pDX, IDC_COMBO_ARC2_FREQ_MANAGE, m_combo_arc2_freq1_manage);
    DDX_Control(pDX, IDC_IDC_COMBO_ARC2_MODULATIONCOMBO4, m_combo_arc2_modulation);
    DDX_Control(pDX, IDC_CHECK_ARC2_ZEROIZE, m_check_arc2_zeroize);
    DDX_Control(pDX, IDC_CHECK_ARC2_ADF, m_check_arc2_adf);
    DDX_Control(pDX, IDC_CHECK_ARC2_COMPRESSOR, m_check_arc2_compressor);
    DDX_Control(pDX, IDC_CHECK_ARC2_GUARD_SQ, m_check_arc2_GuardSquelch);
    DDX_Control(pDX, IDC_CHECK_ARC2_XMODE, m_check_arc2_XMode);
    DDX_Control(pDX, IDC_CHECK_ARC2_MAINSQUELCH, m_check_arc2_MainSquelch);
    DDX_Control(pDX, IDC_CHECK_ARC2_TONEKEY, m_check_arc2_ToneKey);
    DDX_Control(pDX, IDC_CHECK_ARC2_IBIT, m_check_arc2_ibit);
    DDX_Control(pDX, IDC_CHECK_ARC2_RTON, m_check_arc2_rton);
    DDX_Control(pDX, IDC_CHECK_ARC2_XMODE_EN, m_check_arc2_xmode_en);
    DDX_Control(pDX, IDC_CHECK_ARC2_PTT, m_check_arc2_ptt);
    DDX_Control(pDX, IDC_ICON_ARC2_READY_DISCRETE, m_ICON_ARC2_READY_DISCRETE);
    DDX_Control(pDX, IDC_ICON_ARC2_MAIN_SQ_BROKEN, m_ICON_ARC2_MAIN_SQ_BROKEN);
    DDX_Control(pDX, IDC_TEXT_ARC2_XMODE, m_TEXT_ARC2_XMODE);
    DDX_Control(pDX, IDC_TEXT_ARC2_PTT, m_TEXT_ARC2_PTT);
    DDX_Control(pDX, IDC_EDIT_ARC2_FREQ, m_edit_arc2_freq);
    DDX_Control(pDX, IDC_EDIT_ARC2_CHANNEL, m_edit_arc2_channel);
    DDX_Control(pDX, IDC_EDIT_ARC2_TODDAY, m_edit_arc2_todday);
}


BEGIN_MESSAGE_MAP(CSET_ARC2, CDialogEx)
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_BUTTOIDC_BTN_ARC2_MWOD_LOAD, &CSET_ARC2::OnBnClickedButton9)
    ON_BN_CLICKED(IDC_BUTTIDC_BTN_ARC2_FMT_LOAD, &CSET_ARC2::OnBnClickedButton10)
    ON_BN_CLICKED(IDC_BTN_ARC2_PRESET_LOAD, &CSET_ARC2::OnBnClickedButton11)
    ON_BN_CLICKED(IDC_BTN_SEND_ARC2, &CSET_ARC2::OnBnClickedBtnSendArc2)
    ON_MESSAGE(UWM_DP_ICS_DIS, &CSET_ARC2::OnUwmDpIcsDis)
    ON_BN_CLICKED(IDC_BTN_ARC2_DISCRETE_SEND, &CSET_ARC2::OnBnClickedBtnArc2DiscreteSend)
    ON_CBN_SELCHANGE(IDC_COMBO_ARC2_MODE, &CSET_ARC2::OnCbnSelchangeComboArc2Mode)
    ON_WM_CLOSE()
    ON_MESSAGE(UWM_RTON_ENABLE, &CSET_ARC2::OnUwmRtonEnable)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSET_ARC2, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_ISET_ARC2에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {07B58DA5-557C-4270-BC24-7F301C0B81BC}
static const IID IID_ISET_ARC2 =
{ 0x7B58DA5, 0x557C, 0x4270, { 0xBC, 0x24, 0x7F, 0x30, 0x1C, 0xB, 0x81, 0xBC } };

BEGIN_INTERFACE_MAP(CSET_ARC2, CDialogEx)
    INTERFACE_PART(CSET_ARC2, IID_ISET_ARC2, Dispatch)
END_INTERFACE_MAP()


// CSET_ARC2 메시지 처리기입니다.


BOOL CSET_ARC2::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    m_combo_arc2_rf_power.AddString(_T("High Power"));
    m_combo_arc2_rf_power.AddString(_T("Medium Power"));
    m_combo_arc2_rf_power.AddString(_T("Low Power"));

    m_combo_arc2_tod_manage.AddString(_T("Normal"));
    m_combo_arc2_tod_manage.AddString(_T("TOD Accept"));
    m_combo_arc2_tod_manage.AddString(_T("TOD Xmit"));
    m_combo_arc2_tod_manage.AddString(_T("GPS TOD"));
    m_combo_arc2_tod_manage.AddString(_T("TOD Send"));
    m_combo_arc2_tod_manage.AddString(_T("Day Set"));
    m_combo_arc2_tod_manage.AddString(_T("Emer. Clock St"));
    m_combo_arc2_tod_manage.AddString(_T("Emer. w/Day"));

    m_combo_arc2_mode.AddString(_T("Manual"));
    m_combo_arc2_mode.AddString(_T("Preset"));

    m_combo_arc2_op_mode.AddString(_T("T/R"));
    m_combo_arc2_op_mode.AddString(_T("T/R+G"));
    m_combo_arc2_op_mode.AddString(_T("G"));

    m_combo_arc2_freq1_manage.AddString(_T("Fixed"));
    m_combo_arc2_freq1_manage.AddString(_T("Active"));

    m_combo_arc2_modulation.AddString(_T("Default"));
    m_combo_arc2_modulation.AddString(_T("AM"));
    m_combo_arc2_modulation.AddString(_T("FM"));

    //un_PRESET_SELECT.w_PRESET_SELECT = 0x0000;
    //un_MODE_AND_GUARD.w_MODE_AND_GUARD = 0x4800;
    //un_MARITIME_CHANNEL.w_MARITIME_CHANNEL = 0x0000;
    //un_COARSE_FREQUENCY.w_FREQUENCY = 0x0000;
    //un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    //un_OPTIONS.w_OPTIONS = 0x00C0;
    //un_RESERVED_CONTROL.w_RESERVED_CONTROL = 0x0000;

    //un_TOD_MANAGEMENT.w_TOD_MANAGEMENT = 0x0000;
    //un_TOD_RESERVED.w_RESERVED = 0x0000;

    //un_BIT_CONTROL.w_BIT_CONTROL = 0x0000;

    DpPrevSet();

    //if((((CITC_GUI_01Dlg *)GetParent())->ARC2_Index == 2) | (((CITC_GUI_01Dlg *)GetParent())->ARC2_Index == 3))
    //    GetDlgItem(IDC_CHECK_ARC2_RTON)->EnableWindow(TRUE);
    //else
    //    GetDlgItem(IDC_CHECK_ARC2_RTON)->EnableWindow(FALSE);

    return TRUE;  // return TRUE unless you set the focus to a control
}


HBRUSH CSET_ARC2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    UINT nID = pWnd -> GetDlgCtrlID();

    switch(nID)
    {
    case IDC_STATIC_SET_ARC2:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    }

    return hbr;
}


void CSET_ARC2::OnBnClickedButton9()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_CMWOD_LOAD = new CMWOD_LOAD2;
    p_CMWOD_LOAD->Create(IDD_MWOD_LOAD2);
    p_CMWOD_LOAD->ShowWindow(SW_SHOW);

    //if( IDOK == m_CMWOD_LOAD.DoModal())
    //{
    //}
}


void CSET_ARC2::OnBnClickedButton10()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_CFMT_NET_LOAD = new CFMT_NET_LOAD2;
    p_CFMT_NET_LOAD->Create(IDD_FMT_NET_LOAD2);
    p_CFMT_NET_LOAD->ShowWindow(SW_SHOW);

    //if( IDOK == m_CFMT_NET_LOAD.DoModal())
    //{
    //}
}


void CSET_ARC2::OnBnClickedButton11()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_CPRESET_LOAD = new CPRESET_LOAD2;
    p_CPRESET_LOAD->Create(IDD_PRESET_LOAD2);
    p_CPRESET_LOAD->ShowWindow(SW_SHOW);

    //if( IDOK == m_CPRESET_LOAD.DoModal())
    //{
    //}
}


void CSET_ARC2::OnBnClickedBtnSendArc2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


    CheckARC2Setting();

    MSG_Function_Control[0] = un_PRESET_SELECT.w_PRESET_SELECT;
    MSG_Function_Control[1] = un_MODE_AND_GUARD.w_MODE_AND_GUARD;
    MSG_Function_Control[2] = un_MARITIME_CHANNEL.w_MARITIME_CHANNEL;
    MSG_Function_Control[3] = un_COARSE_FREQUENCY.w_FREQUENCY;
    MSG_Function_Control[4] = un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ;
    MSG_Function_Control[5] = un_OPTIONS.w_OPTIONS;
    MSG_Function_Control[6] = un_RESERVED_CONTROL.w_RESERVED_CONTROL;;

    MSG_TOD_Management[0] = un_TOD_MANAGEMENT.w_TOD_MANAGEMENT;
    MSG_TOD_Management[1] = un_TOD_RESERVED.w_RESERVED;

    MSG_BIT_Control[0] = un_BIT_CONTROL.w_BIT_CONTROL;

    CString str;
    str.Format(L"SET_ICS2 > %04X %04X %04X %04X %04X %04X %04X\r\n"
        , MSG_Function_Control[0], MSG_Function_Control[1], MSG_Function_Control[2], MSG_Function_Control[3], MSG_Function_Control[4]
    , MSG_Function_Control[5], MSG_Function_Control[6]);
    int n_Length = ((CITC_GUI_01Dlg *)GetParent())->m_EditLog.GetWindowTextLengthW();
    ((CITC_GUI_01Dlg *)GetParent())->m_EditLog.SetSel(n_Length, n_Length);
    ((CITC_GUI_01Dlg *)GetParent())->m_EditLog.ReplaceSel(str);

    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_prev_ARC2_PRESET_SELECT.w_PRESET_SELECT = un_PRESET_SELECT.w_PRESET_SELECT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_MODE_AND_GUARD.w_MODE_AND_GUARD = un_MODE_AND_GUARD.w_MODE_AND_GUARD;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_MARITIME_CHANNEL.w_MARITIME_CHANNEL = un_MARITIME_CHANNEL.w_MARITIME_CHANNEL;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_COARSE_FREQUENCY.w_FREQUENCY = un_COARSE_FREQUENCY.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ = un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_OPTIONS.w_OPTIONS = un_OPTIONS.w_OPTIONS;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_RESERVED_CONTROL.w_RESERVED_CONTROL = un_RESERVED_CONTROL.w_RESERVED_CONTROL;;

    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_TOD_MANAGEMENT.w_TOD_MANAGEMENT = un_TOD_MANAGEMENT.w_TOD_MANAGEMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_TOD_RESERVED.w_RESERVED = un_TOD_RESERVED.w_RESERVED;

    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_BIT_CONTROL.w_BIT_CONTROL = un_BIT_CONTROL.w_BIT_CONTROL;

    // send하기 전에 메시지 만들어놓음
    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG21,               /* Message ID to create             */
        DBLK21,              /* Data Block ID                    */
        RT2_ADDR,                  /* RT address                       */
        01,                  /* RT subaddress                    */ // subaddress : 01 (Function Control)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_Function_Control);          /* Data words for the async message */

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG22,               /* Message ID to create             */
        DBLK22,              /* Data Block ID                    */
        RT2_ADDR,                  /* RT address                       */
        05,                  /* RT subaddress                    */ // subaddress : 05 (TOD Management)
        2,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_TOD_Management);          /* Data words for the async message */

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG23,               /* Message ID to create             */
        DBLK23,              /* Data Block ID                    */
        RT2_ADDR,                  /* RT address                       */
        29,                  /* RT subaddress                    */ // subaddress : 05 (TOD Management)
        1,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_BIT_Control);          /* Data words for the async message */

    // aceBCStart(DevNum, MJR, -1);

    aceBCDataBlkWrite(DevNum, DBLK21, MSG_Function_Control, 7, 0);
    aceBCDataBlkWrite(DevNum, DBLK22, MSG_TOD_Management, 2, 0);
    aceBCDataBlkWrite(DevNum, DBLK23, MSG_BIT_Control, 1, 0);

    // 실제로 Async 메시지를 보내는 부분
    wResult = aceBCSendAsyncMsgHP(DevNum, MSG21, wFrmTime);
    if(wResult < 0)
        ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("aceBCSendAsyncMsgHP 에러!\r\n"));
    else
        ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("aceBCSendAsyncMsgHP 성공!\r\n"));

    wResult = aceBCSendAsyncMsgHP(DevNum, MSG22, wFrmTime);
    if(wResult < 0)
        ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("aceBCSendAsyncMsgHP 에러!\r\n"));
    else
        ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("aceBCSendAsyncMsgHP 성공!\r\n"));

    wResult = aceBCSendAsyncMsgHP(DevNum, MSG23, wFrmTime);
    if(wResult < 0)
        ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("aceBCSendAsyncMsgHP 에러!\r\n"));
    else
        ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("aceBCSendAsyncMsgHP 성공!\r\n"));
}


void CSET_ARC2::CheckARC2Setting(void)
{

    CString str = NULL;

    if(1 == m_combo_arc2_mode.GetCurSel()) // 프리셋 모드
    {
        m_edit_arc2_channel.GetWindowTextW(str);
        un_PRESET_SELECT.st_PRESET_SELECT.ChannelNumber = (U16BIT)(_ttoi(str)); // GUI (Preset Mode 시, Channel Number 입력(01~99))
        un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x1; // Preset Mode에서 명령 전송 시 : 입력한 Channel Number 및 Memory Managemet=0001(Tune Channel) 전송(Subaddr 01)
    }
    else if(0 == m_combo_arc2_mode.GetCurSel()) // 매뉴얼 모드
    {
        GetDlgItemText(IDC_EDIT_ARC2_FREQ, str);
        un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x4; // Manual Mode에서 명령 전송 시 : 입력한 Frequency 및 Memory Managemet=0100(Tune Direct) 전송(Subaddr 01)

        float m_Freq = _tstof(str);
        U32BIT u32_Freq = (U32BIT)(m_Freq*1000);
        //CString str;
        //str.Format(_T("%d"), u32_Freq);
        //AfxMessageBox(str);

        if((0<u32_Freq) & (u32_Freq<1000000))
        {
            un_COARSE_FREQUENCY.st_FREQUENCY.HundredsDigit = (u32_Freq / 100000);
            u32_Freq = u32_Freq - (un_COARSE_FREQUENCY.st_FREQUENCY.HundredsDigit * 100000);
            un_COARSE_FREQUENCY.st_FREQUENCY.TensDigit = (u32_Freq / 10000);
            u32_Freq = u32_Freq - (un_COARSE_FREQUENCY.st_FREQUENCY.TensDigit * 10000);
            un_COARSE_FREQUENCY.st_FREQUENCY.OnesDigit = (u32_Freq / 1000);
            u32_Freq = u32_Freq - (un_COARSE_FREQUENCY.st_FREQUENCY.OnesDigit * 1000);
            un_COARSE_FREQUENCY.st_FREQUENCY.TenthsDigit = (u32_Freq / 100);
            u32_Freq = u32_Freq - (un_COARSE_FREQUENCY.st_FREQUENCY.TenthsDigit * 100);

            un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit = (u32_Freq / 10);
            u32_Freq = u32_Freq - (un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit * 10);
            un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit = (u32_Freq/ 1);
        }
        else
        {
            ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("주파수가 기준 범위를 벗어났습니다"));
        }
        // s_COARSE_FREQUENCY.

        if(m_check_arc2_zeroize.GetCheck())
        {
            un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0xF;
        }

        /* 0000 = FIXED FREQ, 0001 = HQ ACTIVE
        Others = Reserved */
        if(m_combo_arc2_freq1_manage.GetCurSel())
            un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement = 0x1;
        else
            un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement = 0x0;
    }

    /* BIT[15:14] Modulation
    00 = Default, 01 = AM
    10 = FM, 11 = Reserved */
    switch(m_combo_arc2_modulation.GetCurSel())
    {
    case 0:
        un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x0;
        break;
    case 1:
        un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x1;
        break;
    case 2:
        un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x2;
        break;
    case 3:
        un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x3;
        break;
    }

    /* BIT[13] ADF
    0 = Disable, 1 = Enable */
    un_MODE_AND_GUARD.st_MODE_AND_GUARD.ADF = m_check_arc2_adf.GetCheck();

    /* BIT[12] X-Mode
    0 = Disable, 1 = Enable */
    // un_MODE_AND_GUARD.st_MODE_AND_GUARD.XMode = m_check_arc2_XMode.GetCheck();

    switch(m_combo_arc2_op_mode.GetCurSel())
    {
    case 0:
        un_MODE_AND_GUARD.st_MODE_AND_GUARD.GuardReceiver = 0x0;   // T/R Mode : Gurad Receiver(BC-RT, SA01, W02, b04)=0(Disable) 전송
        break;
    case 1:
        un_MODE_AND_GUARD.st_MODE_AND_GUARD.GuardReceiver = 0x1;   // T/R+G Mode : Guard Receiver(BC-RT, SA01, W02, b04)=1(Enable) 전송
        break;
    case 2:
        un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x7; // G Mode : Memory Management(BC-RT, SA01, W01, b08-11)=0111(Guard) 전송
        break;
    }

    un_OPTIONS.st_OPTIONS.CompressorOption = m_check_arc2_compressor.GetCheck();

    if(m_check_arc2_MainSquelch.GetCheck())
        un_OPTIONS.st_OPTIONS.MainSquelch = 0x0;
    else
        un_OPTIONS.st_OPTIONS.MainSquelch = 0x1;

    if(m_check_arc2_GuardSquelch.GetCheck())
        un_OPTIONS.st_OPTIONS.GuardSquelch = 0x0;
    else
        un_OPTIONS.st_OPTIONS.GuardSquelch = 0x1;

    // un_OPTIONS.st_OPTIONS.GuardSquelch = m_check_arc2_GuardSquelch.GetCheck();

    un_OPTIONS.st_OPTIONS.ToneKey = m_check_arc2_ToneKey.GetCheck();

    /* 00 = High Power, 01 = Medium Power
    10 = Low Power, 11 = Reserved */
    switch(m_combo_arc2_rf_power.GetCurSel())
    {
    case 0:
        un_OPTIONS.st_OPTIONS.RFPower = 0x0;
        break;
    case 1:
        un_OPTIONS.st_OPTIONS.RFPower = 0x1;
        break;
    case 2:
        un_OPTIONS.st_OPTIONS.RFPower = 0x2;
        break;
    case 3:
        un_OPTIONS.st_OPTIONS.RFPower = 0x3;
        break;
    }

    switch(m_combo_arc2_rf_power.GetCurSel())
    {
    case 0:
        un_OPTIONS.st_OPTIONS.RFPower = 0x0;
        break;
    case 1:
        un_OPTIONS.st_OPTIONS.RFPower = 0x1;
        break;
    case 2:
        un_OPTIONS.st_OPTIONS.RFPower = 0x2;
        break;
    case 3:
        un_OPTIONS.st_OPTIONS.RFPower = 0x3;
        break;
    }

    switch(m_combo_arc2_tod_manage.GetCurSel())
    {
    case 0:
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x0;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&m_edit_arc2_todday)/10;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&m_edit_arc2_todday)%10;
        break;
    case 1:
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x1;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&m_edit_arc2_todday)/10;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&m_edit_arc2_todday)%10;
        break;
    case 2:
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x2;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&m_edit_arc2_todday)/10;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&m_edit_arc2_todday)%10;
        break;
    case 3:
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x5;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&m_edit_arc2_todday)/10;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&m_edit_arc2_todday)%10;
        break;
    case 4:
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x6;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&m_edit_arc2_todday)/10;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&m_edit_arc2_todday)%10;
        break;
    case 5:
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x8;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&m_edit_arc2_todday)/10;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&m_edit_arc2_todday)%10;
        break;
    case 6:
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0xA;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&m_edit_arc2_todday)/10;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&m_edit_arc2_todday)%10;
        break;
    case 7:
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0xB;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&m_edit_arc2_todday)/10;
        un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&m_edit_arc2_todday)%10;
        break;
    }

    un_BIT_CONTROL.st_BIT_CONTROL.InitiateIBIT = m_check_arc2_ibit.GetCheck();

}


U8BIT CSET_ARC2::GetTODDay(CEdit* EditBox)
{
    CString str;
    U8BIT tmp = 0;

    EditBox->GetWindowTextW(str);
    tmp = (U8BIT)(_ttoi(str));
    if(1 <= tmp && tmp <= 31)
        return tmp;
    else
        return 0;
}


void CSET_ARC2::OnBnClickedBtnArc2DiscreteSend()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    /* 무전기2 Discrete */
    WriteMsg[0] = 0xD3;
    WriteMsg[1] = 0x03;
    WriteMsg[2] = 0x66;
    WriteMsg[3] = 0x02;
    WriteMsg[4] = m_check_arc2_rton.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->ARC2_Discrete[0] = WriteMsg[4];
    WriteMsg[5] = m_check_arc2_xmode_en.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->ARC2_Discrete[1] = WriteMsg[5];
    WriteMsg[6] = m_check_arc2_ptt.GetCheck();
    ((CITC_GUI_01Dlg *)GetParent())->ARC2_Discrete[2] = WriteMsg[6];
    WriteMsg[7] = 0x7F;
    send(((CITC_GUI_01Dlg *)GetParent())->mh_socket, WriteMsg, 8, 0); 
}


void CSET_ARC2::OnCbnSelchangeComboArc2Mode()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    switch(m_combo_arc2_mode.GetCurSel())
    {
    case 0: // 매뉴얼
        GetDlgItem(IDC_EDIT_ARC2_FREQ)->EnableWindow(TRUE);
        GetDlgItem(IDC_COMBO_ARC2_FREQ_MANAGE)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_ARC2_CHANNEL)->EnableWindow(FALSE);
        break;
    case 1: // 프리셋
        GetDlgItem(IDC_EDIT_ARC2_CHANNEL)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_ARC2_FREQ)->EnableWindow(FALSE);
        GetDlgItem(IDC_COMBO_ARC2_FREQ_MANAGE)->EnableWindow(FALSE);
        break;
    }
}


BOOL CSET_ARC2::PreTranslateMessage(MSG* pMsg)
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


afx_msg LRESULT CSET_ARC2::OnUwmDpIcsDis(WPARAM wParam, LPARAM lParam)
{
    if(((CITC_GUI_01Dlg *)GetParent())->RecvMsg[23] == 1)
    {
        m_TEXT_ARC2_XMODE.SetWindowTextW(_T("Disabled"));
    }
    else
    {
        m_TEXT_ARC2_XMODE.SetWindowTextW(_T("Enabled"));
    }

    if(((CITC_GUI_01Dlg *)GetParent())->RecvMsg[25] == 1)
    {
        m_TEXT_ARC2_PTT.SetWindowTextW(_T("ON"));
    }
    else
    {
        m_TEXT_ARC2_PTT.SetWindowTextW(_T("OFF"));
    }

    if(((CITC_GUI_01Dlg *)GetParent())->RecvMsg[27] == 1)
    {
        ((CITC_GUI_01Dlg *)GetParent())->ChangeIcon(&m_ICON_ARC2_READY_DISCRETE, 1);
    }
    else
    {
        ((CITC_GUI_01Dlg *)GetParent())->ChangeIcon(&m_ICON_ARC2_READY_DISCRETE, 2);
    }

    if(((CITC_GUI_01Dlg *)GetParent())->RecvMsg[29] == 1)
    {
        ((CITC_GUI_01Dlg *)GetParent())->ChangeIcon(&m_ICON_ARC2_MAIN_SQ_BROKEN, 2);
    }
    else
    {
        ((CITC_GUI_01Dlg *)GetParent())->ChangeIcon(&m_ICON_ARC2_MAIN_SQ_BROKEN, 1);
    }

    return 0;
}


void CSET_ARC2::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    DestroyWindow();
    CDialogEx::OnClose();
}


void CSET_ARC2::DpPrevSet(void)
{
    CString str;

    str.Format(_T("%d"), ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_prev_ARC2_PRESET_SELECT.st_PRESET_SELECT.ChannelNumber);
    // m_edit_arc2_channel.SetWindowTextW(str);
    SetDlgItemTextW(IDC_EDIT_ARC2_CHANNEL, str);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_prev_ARC2_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement == 0x7 )
        m_combo_arc2_op_mode.SetCurSel(2);
    else if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_prev_ARC2_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement == 0x4 )
        m_combo_arc2_mode.SetCurSel(0);
    else if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_prev_ARC2_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement == 0x1 )
        m_combo_arc2_mode.SetCurSel(1);
    else if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_prev_ARC2_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement == 0xF )
        m_check_arc2_zeroize.SetCheck(1);

    switch( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation )
    {
    case 0x0:
        m_combo_arc2_modulation.SetCurSel(0);
        break;
    case 0x1:
        m_combo_arc2_modulation.SetCurSel(1);
        break;
    case 0x2:
        m_combo_arc2_modulation.SetCurSel(2);
        break;
    }

    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_MODE_AND_GUARD.st_MODE_AND_GUARD.ADF )
        m_check_arc2_adf.SetCheck(1);

    //if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_MODE_AND_GUARD.st_MODE_AND_GUARD.XMode )
    //    m_check_arc2_XMode.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_MODE_AND_GUARD.st_MODE_AND_GUARD.GuardReceiver == 0x1 )
    {
        m_check_arc2_GuardSquelch.SetCheck(1);
        m_combo_arc2_op_mode.SetCurSel(1);
    }
    else if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_MODE_AND_GUARD.st_MODE_AND_GUARD.GuardReceiver == 0x0 )
        m_combo_arc2_op_mode.SetCurSel(0);

    /* COARSE_FREQUENCY, FINE_FREQUENCY_AND_AJ */
    str = ((CITC_GUI_01Dlg *)GetParent())->NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_COARSE_FREQUENCY.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_COARSE_FREQUENCY.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_COARSE_FREQUENCY.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_COARSE_FREQUENCY.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit);
    SetDlgItemTextW(IDC_EDIT_ARC2_FREQ, str);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0 )
        m_combo_arc2_freq1_manage.SetCurSel(0);
    else if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1 )
        m_combo_arc2_freq1_manage.SetCurSel(1);

    /* OPTIONS */
    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_OPTIONS.st_OPTIONS.CompressorOption )
        m_check_arc2_compressor.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_OPTIONS.st_OPTIONS.MainSquelch == 0x0 )
        m_check_arc2_MainSquelch.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_OPTIONS.st_OPTIONS.GuardSquelch )
        m_check_arc2_GuardSquelch.SetCheck(0);
    else
        m_check_arc2_GuardSquelch.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_OPTIONS.st_OPTIONS.ToneKey )
        m_check_arc2_ToneKey.SetCheck(1);

    if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_OPTIONS.st_OPTIONS.RFPower == 0x0 )
        m_combo_arc2_rf_power.SetCurSel(0);
    else if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_OPTIONS.st_OPTIONS.RFPower == 0x1 )
        m_combo_arc2_rf_power.SetCurSel(1);
    else if( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_OPTIONS.st_OPTIONS.RFPower == 0x2 )
        m_combo_arc2_rf_power.SetCurSel(2);

    switch( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement )
    {
    case 0x0:
        m_combo_arc2_tod_manage.SetCurSel(0);
        break;
    case 0x1:
        m_combo_arc2_tod_manage.SetCurSel(1);
        break;
    case 0x2:
        m_combo_arc2_tod_manage.SetCurSel(2);
        break;
    case 0x5:
        m_combo_arc2_tod_manage.SetCurSel(3);
        break;
    case 0x6:
        m_combo_arc2_tod_manage.SetCurSel(4);
        break;
    case 0x8:
        m_combo_arc2_tod_manage.SetCurSel(5);
        break;
    case 0xA:
        m_combo_arc2_tod_manage.SetCurSel(6);
        break;
    case 0xB:
        m_combo_arc2_tod_manage.SetCurSel(7);
        break;
    }

    str.Format(_T("%d%d"), ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit, ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit);
    SetDlgItemTextW(IDC_EDIT_ARC2_TODDAY, str);

    /* Discrete */
    m_check_arc2_rton.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ARC2_Discrete[0] );
    // m_check_arc2_xmode_en.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ARC2_Discrete[1] );
    m_check_arc2_ptt.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ARC2_Discrete[2] );
}


afx_msg LRESULT CSET_ARC2::OnUwmRtonEnable(WPARAM wParam, LPARAM lParam)
{
    if((((CITC_GUI_01Dlg *)GetParent())->ARC2_Index == 2) | (((CITC_GUI_01Dlg *)GetParent())->ARC2_Index == 3))
        GetDlgItem(IDC_CHECK_ARC2_RTON)->EnableWindow(TRUE);
    else
        GetDlgItem(IDC_CHECK_ARC2_RTON)->EnableWindow(FALSE);

    return 0;
}
