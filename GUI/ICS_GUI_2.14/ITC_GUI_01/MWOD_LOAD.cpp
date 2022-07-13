// MWOD_LOAD.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "MWOD_LOAD.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"
#include "SET_ARC1.h"

// CMWOD_LOAD 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMWOD_LOAD, CDialogEx)

    CMWOD_LOAD::CMWOD_LOAD(CWnd* pParent /*=NULL*/)
    : CDialogEx(CMWOD_LOAD::IDD, pParent)
{

    EnableAutomation();

}

CMWOD_LOAD::~CMWOD_LOAD()
{
}

void CMWOD_LOAD::OnFinalRelease()
{
    // 자동화 개체에 대한 마지막 참조가 해제되면
    // OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
    // 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
    // 추가하십시오.

    CDialogEx::OnFinalRelease();
}

void CMWOD_LOAD::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_WOD01, m_WOD01);
    DDX_Control(pDX, IDC_WOD02, m_WOD02);
    DDX_Control(pDX, IDC_WOD03, m_WOD03);
    DDX_Control(pDX, IDC_WOD04, m_WOD04);
    DDX_Control(pDX, IDC_WOD05, m_WOD05);
    DDX_Control(pDX, IDC_WOD06, m_WOD06);
    DDX_Control(pDX, IDC_WODD, m_WODD);
}


BEGIN_MESSAGE_MAP(CMWOD_LOAD, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_MWOD_DATA_LOAD, &CMWOD_LOAD::OnBnClickedBtnMwodDataLoad)
    ON_WM_TIMER()
    ON_WM_CLOSE()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMWOD_LOAD, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IMWOD_LOAD에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {D908D661-DE11-4CA1-AD04-9486E33C61EE}
static const IID IID_IMWOD_LOAD =
{ 0xD908D661, 0xDE11, 0x4CA1, { 0xAD, 0x4, 0x94, 0x86, 0xE3, 0x3C, 0x61, 0xEE } };

BEGIN_INTERFACE_MAP(CMWOD_LOAD, CDialogEx)
    INTERFACE_PART(CMWOD_LOAD, IID_IMWOD_LOAD, Dispatch)
END_INTERFACE_MAP()


// CMWOD_LOAD 메시지 처리기입니다.


void CMWOD_LOAD::OnBnClickedBtnMwodDataLoad()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

    MWODEditToDouble(&m_WOD01, &un_WOD_SEGMENT1);
    MWODEditToDouble(&m_WOD02, &un_WOD_SEGMENT2);
    MWODEditToDouble(&m_WOD03, &un_WOD_SEGMENT3);
    MWODEditToDouble(&m_WOD04, &un_WOD_SEGMENT4);
    MWODEditToDouble(&m_WOD05, &un_WOD_SEGMENT5);
    MWODEditToDouble(&m_WOD06, &un_WOD_SEGMENT6);

    CString s_WODD;
    m_WODD.GetWindowTextW(s_WODD);
    // AfxMessageBox(s_WODD);

    U16BIT m_WOD_DAY = _ttoi(s_WODD);

    if((301<=m_WOD_DAY) & (m_WOD_DAY<=331))
    {
        un_WOD_DAY.st_WOD_DAY.HundredsDigit = m_WOD_DAY / 100;
        m_WOD_DAY = m_WOD_DAY - (un_WOD_DAY.st_WOD_DAY.HundredsDigit * 100);

        un_WOD_DAY.st_WOD_DAY.TensDigit = m_WOD_DAY / 10;
        m_WOD_DAY = m_WOD_DAY - (un_WOD_DAY.st_WOD_DAY.TensDigit * 10);

        un_WOD_DAY.st_WOD_DAY.OnesDigit = m_WOD_DAY / 1;
        m_WOD_DAY = m_WOD_DAY - (un_WOD_DAY.st_WOD_DAY.OnesDigit * 1);

        un_WOD_DAY.st_WOD_DAY.TenthsDigit = 0;
        un_WOD_DAY.st_WOD_DAY.HundredthsDigit = 0;
    }
    else
    {
        AfxMessageBox(_T("범위를 벗어났습니다.(WOD_DAY)"));
        return;
    }

    MSG_MWOD_Load[0] = un_WOD_SEGMENT1.w_WOD_SEGMENT;
    MSG_MWOD_Load[1] = un_WOD_SEGMENT2.w_WOD_SEGMENT;
    MSG_MWOD_Load[2] = un_WOD_SEGMENT3.w_WOD_SEGMENT;
    MSG_MWOD_Load[3] = un_WOD_SEGMENT4.w_WOD_SEGMENT;
    MSG_MWOD_Load[4] = un_WOD_SEGMENT5.w_WOD_SEGMENT;
    MSG_MWOD_Load[5] = un_WOD_SEGMENT6.w_WOD_SEGMENT;
    MSG_MWOD_Load[6] = un_WOD_DAY.w_WOD_DAY;

    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT1.w_WOD_SEGMENT = un_WOD_SEGMENT1.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT2.w_WOD_SEGMENT = un_WOD_SEGMENT2.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT3.w_WOD_SEGMENT = un_WOD_SEGMENT3.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT4.w_WOD_SEGMENT = un_WOD_SEGMENT4.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT5.w_WOD_SEGMENT = un_WOD_SEGMENT5.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT6.w_WOD_SEGMENT = un_WOD_SEGMENT6.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_DAY.w_WOD_DAY = un_WOD_DAY.w_WOD_DAY;

    //aceBCAsyncMsgCreateBCtoRT(
    //    DevNum,             /* Device number                    */
    //    MSG17,               /* Message ID to create             */
    //    DBLK17,              /* Data Block ID                    */
    //    RT1_ADDR,                  /* RT address                       */
    //    01,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
    //    7,                  /* Word Count                       */
    //    0,                  /* Devault Message Timer            */
    //    ACE_BCCTRL_CHL_A,   /* use chl A options                */
    //    ((CSET_ARC1 *)GetParent())->MSG_Function_Control);          /* Data words for the async message */

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG14,               /* Message ID to create             */
        DBLK14,              /* Data Block ID                    */
        RT1_ADDR,                  /* RT address                       */
        02,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_MWOD_Load);          /* Data words for the async message */

    aceBCDataBlkWrite(DevNum, DBLK14, MSG_MWOD_Load, 7, 0);

    int wResult = aceBCSendAsyncMsgHP(DevNum, MSG14, wFrmTime);

    if(wResult < 0)
        ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("aceBCSendAsyncMsgHP 에러!\r\n"));
    else
        ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("aceBCSendAsyncMsgHP 성공!\r\n"));

    ::SendMessage(((CITC_GUI_01Dlg *)GetParent())->m_hWnd, UWM_SAVE_ARC1_MWOD, NULL, NULL);
}


U16BIT CMWOD_LOAD::MWODEditToDouble(CEdit* EditAddr, UNION_WOD_SEGMENT* p_WOD_SEGMENT)
{
    CString str;
    EditAddr->GetWindowTextW(str);
    
    float m_MWODSegment = _tstof(str);
    U32BIT u32_Freq = (U32BIT)(m_MWODSegment*1000);
    U16BIT m_HundredthDigit;
    if((0<u32_Freq) & (u32_Freq<=399975))
    {
        p_WOD_SEGMENT->st_WOD_SEGMENT.HundredsDigit = (u32_Freq / 100000);
        u32_Freq = u32_Freq - (p_WOD_SEGMENT->st_WOD_SEGMENT.HundredsDigit * 100000);
        p_WOD_SEGMENT->st_WOD_SEGMENT.TensDigit = (u32_Freq / 10000);
        u32_Freq = u32_Freq - (p_WOD_SEGMENT->st_WOD_SEGMENT.TensDigit * 10000);
        p_WOD_SEGMENT->st_WOD_SEGMENT.OnesDigit = (u32_Freq / 1000);
        u32_Freq = u32_Freq - (p_WOD_SEGMENT->st_WOD_SEGMENT.OnesDigit * 1000);
        p_WOD_SEGMENT->st_WOD_SEGMENT.TenthsDigit = (u32_Freq / 100);
        u32_Freq = u32_Freq - (p_WOD_SEGMENT->st_WOD_SEGMENT.TenthsDigit * 100);

        m_HundredthDigit= (u32_Freq / 10);
        switch (m_HundredthDigit)
        {
        case 0:
            p_WOD_SEGMENT->st_WOD_SEGMENT.HundredthsDigit = 0;
            break;
        case 2:
            p_WOD_SEGMENT->st_WOD_SEGMENT.HundredthsDigit = 1;
            break;
        case 5:
            p_WOD_SEGMENT->st_WOD_SEGMENT.HundredthsDigit = 2;
            break;
        case 7:
            p_WOD_SEGMENT->st_WOD_SEGMENT.HundredthsDigit = 3;
            break;
        }

        //p_WOD_SEGMENT->st_WOD_SEGMENT.HundredthsDigit = (U16BIT)(m_MWODSegment / 0.01);
        //m_MWODSegment = m_MWODSegment - (p_WOD_SEGMENT->st_WOD_SEGMENT.HundredthsDigit * 0.01);

        // WORD * tmp = reinterpret_cast<WORD *>(&p_WOD_SEGMENT);

        return 1;
    }
    else
    {
        // ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("범위를 벗어났습니다.(MWOD Segment)"));
        // AfxMessageBox(_T("범위를 벗어났습니다.(MWOD Segment)"));
        return -1;
    }

}


BOOL CMWOD_LOAD::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    DpPrevSet();

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CMWOD_LOAD::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    if( ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.WODData == 0 )
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.WODData = 1;
    else if( ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.WODData == 1 )
    {
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.WODData = 0;
        KillTimer(MWOD_LOAD);
    }

    ((CSET_ARC1 *)GetParent())->MSG_Function_Control[5] = ((CSET_ARC1 *)GetParent())->un_OPTIONS.w_OPTIONS;

    CString str;
    str.Format(L"> 수신 : %04X %04X %04X %04X %04X %04X %04X\r\n"
        , ((CSET_ARC1 *)GetParent())->MSG_Function_Control[0], ((CSET_ARC1 *)GetParent())->MSG_Function_Control[1], ((CSET_ARC1 *)GetParent())->MSG_Function_Control[2], ((CSET_ARC1 *)GetParent())->MSG_Function_Control[3], ((CSET_ARC1 *)GetParent())->MSG_Function_Control[4]
    , ((CSET_ARC1 *)GetParent())->MSG_Function_Control[5], ((CSET_ARC1 *)GetParent())->MSG_Function_Control[6]);

    int n_Length = ((CITC_GUI_01Dlg *)GetParent())->m_EditLog.GetWindowTextLengthW();
    ((CITC_GUI_01Dlg *)GetParent())->m_EditLog.SetSel(n_Length, n_Length);
    ((CITC_GUI_01Dlg *)GetParent())->m_EditLog.ReplaceSel(str);

    //aceBCDataBlkWrite(DevNum, DBLK17, ((CSET_ARC1 *)GetParent())->MSG_Function_Control, 7, 0);

    //aceBCSendAsyncMsgHP(DevNum, MSG17, wFrmTime);

    CDialogEx::OnTimer(nIDEvent);
}


BOOL CMWOD_LOAD::PreTranslateMessage(MSG* pMsg)
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


void CMWOD_LOAD::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    DestroyWindow();
    CDialogEx::OnClose();
}


void CMWOD_LOAD::DpPrevSet(void)
{
    CString str;

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT1.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT1.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT1.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT1.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT1.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD01, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT2.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT2.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT2.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT2.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT2.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD02, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT3.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT3.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT3.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT3.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT3.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD03, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT4.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT4.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT4.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT4.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT4.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD04, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT5.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT5.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT5.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT5.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT5.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD05, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT6.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT6.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT6.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT6.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_SEGMENT6.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD06, str);

    str.Format(_T("3%X%X"), ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_DAY.st_WOD_DAY.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_WOD_DAY.st_WOD_DAY.OnesDigit );
    SetDlgItemTextW(IDC_WODD, str);

}


CString CMWOD_LOAD::NumToString(U16BIT Hundreds, U16BIT Tens, U16BIT Ones, U16BIT Tenths, U16BIT Hundredths)
{
    CString str;

    switch(Hundreds)
    {
    case 0x0:
        str.Format(_T("%X%X%X.%X00"), Hundreds, Tens, Ones, Tenths);
        break;
    case 0x1:
        str.Format(_T("%X%X%X.%X25"), Hundreds, Tens, Ones, Tenths);
        break;
    case 0x2:
        str.Format(_T("%X%X%X.%X50"), Hundreds, Tens, Ones, Tenths);
        break;
    case 0x3:
        str.Format(_T("%X%X%X.%X75"), Hundreds, Tens, Ones, Tenths);
        break;
    }

    return str;
}


void CMWOD_LOAD::CheckPresentARC1Setting(void)
{
    CString str = NULL;

    if(1 == ((CSET_ARC1 *)GetParent())->m_combo_arc1_mode.GetCurSel()) // 프리셋 모드
    {

        ((CSET_ARC1 *)GetParent())->m_edit_arc1_channel.GetWindowTextW(str);
        ((CSET_ARC1 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.ChannelNumber = (U16BIT)(_ttoi(str)); // GUI (Preset Mode 시, Channel Number 입력(01~99))
        ((CSET_ARC1 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x1; // Preset Mode에서 명령 전송 시 : 입력한 Channel Number 및 Memory Managemet=0001(Tune Channel) 전송(Subaddr 01)
    }
    else if(0 == ((CSET_ARC1 *)GetParent())->m_combo_arc1_mode.GetCurSel()) // 매뉴얼 모드
    {
        GetDlgItemText(IDC_EDIT_ARC1_FREQ, str);
        ((CSET_ARC1 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x4; // Manual Mode에서 명령 전송 시 : 입력한 Frequency 및 Memory Managemet=0100(Tune Direct) 전송(Subaddr 01)

        float m_Freq = _tstof(str);
        U32BIT u32_Freq = (U32BIT)(m_Freq*1000);

        if((0<u32_Freq) & (u32_Freq<1000))
        {
            ((CSET_ARC1 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.HundredsDigit = (u32_Freq / 100000);
            u32_Freq = u32_Freq - (((CSET_ARC1 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.HundredsDigit * 100000);
            ((CSET_ARC1 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.TensDigit = (u32_Freq / 10000);
            u32_Freq = u32_Freq - (((CSET_ARC1 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.TensDigit * 10000);
            ((CSET_ARC1 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.OnesDigit = (u32_Freq / 1000);
            u32_Freq = u32_Freq - (((CSET_ARC1 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.OnesDigit * 1000);
            ((CSET_ARC1 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.TenthsDigit = (u32_Freq / 100);
            u32_Freq = u32_Freq - (((CSET_ARC1 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.TenthsDigit * 100);

            ((CSET_ARC1 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit = (u32_Freq / 10);
            u32_Freq = u32_Freq - (((CSET_ARC1 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit * 10);
            ((CSET_ARC1 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit = (u32_Freq/ 1);
        }
        else
        {
            ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("주파수가 기준 범위를 벗어났습니다"));
        }

        if(((CSET_ARC1 *)GetParent())->m_check_arc1_zeroize.GetCheck())
        {
            ((CSET_ARC1 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0xF;
        }

        /* 0000 = FIXED FREQ, 0001 = HQ ACTIVE
        Others = Reserved */
        if(((CSET_ARC1 *)GetParent())->m_combo_arc1_freq1_manage.GetCurSel())
            ((CSET_ARC1 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement = 0x1;
        else
            ((CSET_ARC1 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement = 0x0;
    }

    switch(((CSET_ARC1 *)GetParent())->m_combo_arc1_modulation.GetCurSel())
    {
    case 0:
        ((CSET_ARC1 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x0;
        break;
    case 1:
        ((CSET_ARC1 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x1;
        break;
    case 2:
        ((CSET_ARC1 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x2;
        break;
    case 3:
        ((CSET_ARC1 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x3;
        break;
    }

    /* BIT[13] ADF
    0 = Disable, 1 = Enable */
    ((CSET_ARC1 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.ADF = ((CSET_ARC1 *)GetParent())->m_check_arc1_adf.GetCheck();

    /* BIT[12] X-Mode
    0 = Disable, 1 = Enable */
    ((CSET_ARC1 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.XMode = ((CSET_ARC1 *)GetParent())->m_check_arc1_XMode.GetCheck();

    switch(((CSET_ARC1 *)GetParent())->m_combo_arc1_op_mode.GetCurSel())
    {
    case 0:
        ((CSET_ARC1 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.GuardReceiver = 0x0;   // T/R Mode : Gurad Receiver(BC-RT, SA01, W02, b04)=0(Disable) 전송
        break;
    case 1:
        ((CSET_ARC1 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.GuardReceiver = 0x1;   // T/R+G Mode : Guard Receiver(BC-RT, SA01, W02, b04)=1(Enable) 전송
        break;
    case 2:
        ((CSET_ARC1 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x7; // G Mode : Memory Management(BC-RT, SA01, W01, b08-11)=0111(Guard) 전송
        break;
    }

    ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.CompressorOption = ((CSET_ARC1 *)GetParent())->m_check_arc1_compressor.GetCheck();

    if(((CSET_ARC1 *)GetParent())->m_check_arc1_MainSquelch.GetCheck())
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.MainSquelch = 0x0;
    else
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.MainSquelch = 0x1;

    ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.GuardSquelch = ((CSET_ARC1 *)GetParent())->m_check_arc1_GuardSquelch.GetCheck();

    ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.ToneKey = ((CSET_ARC1 *)GetParent())->m_check_arc1_ToneKey.GetCheck();

    /* 00 = High Power, 01 = Medium Power
    10 = Low Power, 11 = Reserved */
    switch(((CSET_ARC1 *)GetParent())->m_combo_arc1_rf_power.GetCurSel())
    {
    case 0:
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x0;
        break;
    case 1:
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x1;
        break;
    case 2:
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x2;
        break;
    case 3:
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x3;
        break;
    }

    switch(((CSET_ARC1 *)GetParent())->m_combo_arc1_rf_power.GetCurSel())
    {
    case 0:
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x0;
        break;
    case 1:
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x1;
        break;
    case 2:
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x2;
        break;
    case 3:
        ((CSET_ARC1 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x3;
        break;
    }

    switch(((CSET_ARC1 *)GetParent())->m_combo_arc1_tod_manage.GetCurSel())
    {
    case 0:
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x0;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)/10;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)%10;
        break;
    case 1:
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x1;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)/10;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)%10;
        break;
    case 2:
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x2;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)/10;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)%10;
        break;
    case 3:
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x5;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)/10;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)%10;
        break;
    case 4:
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x6;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)/10;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)%10;
        break;
    case 5:
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x8;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)/10;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)%10;
        break;
    case 6:
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0xA;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)/10;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)%10;
        break;
    case 7:
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0xB;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)/10;
        ((CSET_ARC1 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC1 *)GetParent())->m_edit_arc1_todday)%10;
        break;
    }

    ((CSET_ARC1 *)GetParent())->un_BIT_CONTROL.st_BIT_CONTROL.InitiateIBIT = ((CSET_ARC1 *)GetParent())->m_check_arc1_ibit.GetCheck();
}


U8BIT CMWOD_LOAD::GetTODDay(CEdit* EditBox)
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
