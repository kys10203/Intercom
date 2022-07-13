// PRESET_LOAD.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "PRESET_LOAD.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"


// CPRESET_LOAD 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPRESET_LOAD, CDialogEx)

    CPRESET_LOAD::CPRESET_LOAD(CWnd* pParent /*=NULL*/)
    : CDialogEx(CPRESET_LOAD::IDD, pParent)
{

}

CPRESET_LOAD::~CPRESET_LOAD()
{
}

void CPRESET_LOAD::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ01, m_Edit_ARC1_FREQ01);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ02, m_Edit_ARC1_FREQ02);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ03, m_Edit_ARC1_FREQ03);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ04, m_Edit_ARC1_FREQ04);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ05, m_Edit_ARC1_FREQ05);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ06, m_Edit_ARC1_FREQ06);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ07, m_Edit_ARC1_FREQ07);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ08, m_Edit_ARC1_FREQ08);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ09, m_Edit_ARC1_FREQ09);
    DDX_Control(pDX, IDC_PRESET_LOAD1_FREQ10, m_Edit_ARC1_FREQ10);
    DDX_Control(pDX, IDC_PRESET_LOAD1_GROUP_SELECT, m_Edit_ARC1_Group_Sel);
    DDX_Control(pDX, IDC_COMBO1_A1P, m_ARC1_ComboFM01);
    DDX_Control(pDX, IDC_COMBO7_A1P, m_ARC1_ComboFM02);
    DDX_Control(pDX, IDC_COMBO8_A1P, m_ARC1_ComboFM03);
    DDX_Control(pDX, IDC_COMBO9_A1P, m_ARC1_ComboFM04);
    DDX_Control(pDX, IDC_COMBO10_A1P, m_ARC1_ComboFM05);
    DDX_Control(pDX, IDC_COMBO11_A1P, m_ARC1_ComboFM06);
    DDX_Control(pDX, IDC_COMBO4_A1P, m_ARC1_ComboFM07);
    DDX_Control(pDX, IDC_COMBO12_A1P, m_ARC1_ComboFM08);
    DDX_Control(pDX, IDC_COMBO13_A1P, m_ARC1_ComboFM09);
    DDX_Control(pDX, IDC_COMBO14_A1P, m_ARC1_ComboFM10);
}


BEGIN_MESSAGE_MAP(CPRESET_LOAD, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &CPRESET_LOAD::OnBnClickedButton1)
    ON_WM_CLOSE()
END_MESSAGE_MAP()



void CPRESET_LOAD::OnBnClickedButton1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    CString str;

    m_Edit_ARC1_Group_Sel.GetWindowTextW(str);
    U16BIT m_Group_sel = (U16BIT)(_ttoi(str));

    if(m_Group_sel == 0)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect = 0x0;
    else if(m_Group_sel == 1)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x1;
    else if(m_Group_sel == 2)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x2;
    else if(m_Group_sel == 3)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x3;
    else if(m_Group_sel == 4)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x4;
    else if(m_Group_sel == 5)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x5;
    else if(m_Group_sel == 6)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x6;
    else if(m_Group_sel == 7)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x7;
    else if(m_Group_sel == 8)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x8;
    else if(m_Group_sel == 9)
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x9;
    else 
        un_PRESET_GROUP_SELECT.st_PRESET_GROUP_SELECT.GroupSelect  = 0x0;

    ReadCoarseFreq(&un_FREQUENCY01, &un_FREQ_MANAGE01, &m_Edit_ARC1_FREQ01);
    ReadCoarseFreq(&un_FREQUENCY02, &un_FREQ_MANAGE02, &m_Edit_ARC1_FREQ02);
    ReadCoarseFreq(&un_FREQUENCY03, &un_FREQ_MANAGE03, &m_Edit_ARC1_FREQ03);
    ReadCoarseFreq(&un_FREQUENCY04, &un_FREQ_MANAGE04, &m_Edit_ARC1_FREQ04);
    ReadCoarseFreq(&un_FREQUENCY05, &un_FREQ_MANAGE05, &m_Edit_ARC1_FREQ05);
    ReadCoarseFreq(&un_FREQUENCY06, &un_FREQ_MANAGE06, &m_Edit_ARC1_FREQ06);
    ReadCoarseFreq(&un_FREQUENCY07, &un_FREQ_MANAGE07, &m_Edit_ARC1_FREQ07);
    ReadCoarseFreq(&un_FREQUENCY08, &un_FREQ_MANAGE08, &m_Edit_ARC1_FREQ08);
    ReadCoarseFreq(&un_FREQUENCY09, &un_FREQ_MANAGE09, &m_Edit_ARC1_FREQ09);
    ReadCoarseFreq(&un_FREQUENCY10, &un_FREQ_MANAGE10, &m_Edit_ARC1_FREQ10);

    ReadFreqManagement(&un_FREQ_MANAGE01, &m_ARC1_ComboFM01);
    ReadFreqManagement(&un_FREQ_MANAGE02, &m_ARC1_ComboFM02);
    ReadFreqManagement(&un_FREQ_MANAGE03, &m_ARC1_ComboFM03);
    ReadFreqManagement(&un_FREQ_MANAGE04, &m_ARC1_ComboFM04);
    ReadFreqManagement(&un_FREQ_MANAGE05, &m_ARC1_ComboFM05);
    ReadFreqManagement(&un_FREQ_MANAGE06, &m_ARC1_ComboFM06);
    ReadFreqManagement(&un_FREQ_MANAGE07, &m_ARC1_ComboFM07);
    ReadFreqManagement(&un_FREQ_MANAGE08, &m_ARC1_ComboFM08);
    ReadFreqManagement(&un_FREQ_MANAGE09, &m_ARC1_ComboFM09);
    ReadFreqManagement(&un_FREQ_MANAGE10, &m_ARC1_ComboFM10);

    MSG_FREQUENCY[0] = un_PRESET_GROUP_SELECT.w_PRESET_GROUP_SELECT;
    MSG_FREQUENCY[1] = un_FREQUENCY01.w_FREQUENCY;
    MSG_FREQUENCY[2] = un_FREQ_MANAGE01.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[3] =  un_FREQUENCY02.w_FREQUENCY;
    MSG_FREQUENCY[4] = un_FREQ_MANAGE02.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[5] =  un_FREQUENCY03.w_FREQUENCY;
    MSG_FREQUENCY[6] = un_FREQ_MANAGE03.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[7] =  un_FREQUENCY04.w_FREQUENCY;
    MSG_FREQUENCY[8] = un_FREQ_MANAGE04.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[9] =  un_FREQUENCY05.w_FREQUENCY;
    MSG_FREQUENCY[10] = un_FREQ_MANAGE05.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[11] =  un_FREQUENCY06.w_FREQUENCY;
    MSG_FREQUENCY[12] = un_FREQ_MANAGE06.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[13] =  un_FREQUENCY07.w_FREQUENCY;
    MSG_FREQUENCY[14] = un_FREQ_MANAGE07.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[15] =  un_FREQUENCY08.w_FREQUENCY;
    MSG_FREQUENCY[16] = un_FREQ_MANAGE08.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[17] =  un_FREQUENCY09.w_FREQUENCY;
    MSG_FREQUENCY[18] = un_FREQ_MANAGE09.w_FINE_FREQUENCY_AND_AJ;
    MSG_FREQUENCY[19] =  un_FREQUENCY10.w_FREQUENCY;
    MSG_FREQUENCY[20] = un_FREQ_MANAGE10.w_FINE_FREQUENCY_AND_AJ;

    ((CITC_GUI_01Dlg *)GetParent())->prev_ARC1_PRESET_GROUP_SELECT = m_Group_sel;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_PRESET_GROUP_SELECT.w_PRESET_GROUP_SELECT = un_PRESET_GROUP_SELECT.w_PRESET_GROUP_SELECT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY01.w_FREQUENCY = un_FREQUENCY01.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE01.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY02.w_FREQUENCY = un_FREQUENCY02.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE02.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE02.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY03.w_FREQUENCY = un_FREQUENCY03.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE03.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE03.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY04.w_FREQUENCY = un_FREQUENCY04.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE04.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE04.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY05.w_FREQUENCY = un_FREQUENCY05.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE05.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE05.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY06.w_FREQUENCY = un_FREQUENCY06.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE06.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE06.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY07.w_FREQUENCY = un_FREQUENCY07.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE07.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE07.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY08.w_FREQUENCY = un_FREQUENCY08.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE08.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE08.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY09.w_FREQUENCY = un_FREQUENCY09.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE09.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE09.w_FINE_FREQUENCY_AND_AJ;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY10.w_FREQUENCY = un_FREQUENCY10.w_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE10.w_FINE_FREQUENCY_AND_AJ = un_FREQ_MANAGE10.w_FINE_FREQUENCY_AND_AJ;

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG16,               /* Message ID to create             */
        DBLK16,              /* Data Block ID                    */
        RT1_ADDR,                  /* RT address                       */
        07,                  /* RT subaddress                    */ // subaddress : 07 (Preset Load)
        21,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_FREQUENCY);          /* Data words for the async message */

    // aceBCStart(DevNum, MJR, -1);

    aceBCDataBlkWrite(DevNum, DBLK16, MSG_FREQUENCY, 21, 0);
    aceBCSendAsyncMsgHP(DevNum, MSG16, wFrmTime);

    ::SendMessage(((CITC_GUI_01Dlg *)GetParent())->m_hWnd, UWM_SAVE_ARC1_PRESET, NULL, NULL);
}


BOOL CPRESET_LOAD::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    m_ARC1_ComboFM01.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM01.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM02.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM02.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM03.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM03.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM04.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM04.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM05.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM05.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM06.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM06.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM07.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM07.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM08.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM08.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM09.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM09.AddString(_T("HQ ACTIVE"));
    m_ARC1_ComboFM10.AddString(_T("FIXED FREQ"));
    m_ARC1_ComboFM10.AddString(_T("HQ ACTIVE"));

    DpPrevSet();

    return TRUE;  // return TRUE unless you set the focus to a control

}


U16BIT CPRESET_LOAD::ReadCoarseFreq(UNION_FREQUENCY* p_FREQUENCY, UNION_FINE_FREQUENCY_AND_AJ* p_FINE_FREQUENCY_AND_AJ, CEdit* p_CEdit)
{
    CString str;
    float m_CEdit;

    p_CEdit->GetWindowTextW(str);
    m_CEdit = _tstof(str);
    U32BIT u32_Freq = (U32BIT)(m_CEdit*1000);

    if((30000 <= u32_Freq) & (u32_Freq <=399990))
    {
        p_FREQUENCY->st_FREQUENCY.HundredsDigit = (u32_Freq / 100000);
        u32_Freq = u32_Freq - (p_FREQUENCY->st_FREQUENCY.HundredsDigit * 100000);
        p_FREQUENCY->st_FREQUENCY.TensDigit = (u32_Freq / 10000);
        u32_Freq = u32_Freq - (p_FREQUENCY->st_FREQUENCY.TensDigit * 10000);
        p_FREQUENCY->st_FREQUENCY.OnesDigit = (u32_Freq / 1000);
        u32_Freq = u32_Freq - (p_FREQUENCY->st_FREQUENCY.OnesDigit * 1000);
        p_FREQUENCY->st_FREQUENCY.TenthsDigit = (u32_Freq / 100);
        u32_Freq = u32_Freq - (p_FREQUENCY->st_FREQUENCY.TenthsDigit * 100);

        p_FINE_FREQUENCY_AND_AJ->st_FINE_FREQUENCY_AND_AJ.HundredthsDigit = (u32_Freq / 10);
        u32_Freq = u32_Freq - (p_FINE_FREQUENCY_AND_AJ->st_FINE_FREQUENCY_AND_AJ.HundredthsDigit * 10);
        p_FINE_FREQUENCY_AND_AJ->st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit = (u32_Freq / 1);
        u32_Freq = u32_Freq - (p_FINE_FREQUENCY_AND_AJ->st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit * 1);

        // WORD * tmp = reinterpret_cast<WORD *>(&p_FREQUENCY);

        return 1;
    }
    else
    {
        return -1;
    }
}


U16BIT CPRESET_LOAD::ReadFreqManagement(UNION_FINE_FREQUENCY_AND_AJ* p_FINE_FREQUENCY_AND_AJ, CComboBox* p_Combo)
{
    U16BIT m_FreqMng;

    m_FreqMng = p_Combo->GetCurSel();

    p_FINE_FREQUENCY_AND_AJ->st_FINE_FREQUENCY_AND_AJ.FrequncyManagement = m_FreqMng;

    return 0;
}


BOOL CPRESET_LOAD::PreTranslateMessage(MSG* pMsg)
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


void CPRESET_LOAD::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    DestroyWindow();
    CDialogEx::OnClose();
}


void CPRESET_LOAD::DpPrevSet(void)
{
    CString str;

    str.Format(_T("%d"), ((CITC_GUI_01Dlg *)GetParent())->prev_ARC1_PRESET_GROUP_SELECT);
    SetDlgItemTextW(IDC_PRESET_LOAD1_GROUP_SELECT, str);

    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY01),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ01, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY02),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE02));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ02, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY03),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE03));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ03, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY04),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE04));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ04, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY05),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE05));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ05, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY06),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE06));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ06, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY07),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE07));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ07, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY08),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE08));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ08, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY09),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE09));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ09, str);
    str = NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY10),  &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE10));
    SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ10, str);

    m_ARC1_ComboFM01.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM02.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM03.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM04.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM05.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM06.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM07.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM08.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM09.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);
    m_ARC1_ComboFM10.SetCurSel(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQ_MANAGE01.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement);

    // SetDlgItemTextW(IDC_PRESET_LOAD1_FREQ01, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC1_FREQUENCY01) ));
}


CString CPRESET_LOAD::NumToCString(UNION_FREQUENCY* p_UNION_FREQUENCY, UNION_FINE_FREQUENCY_AND_AJ* p_UNION_FINE_FREQUENCY_AND_AJ)
{
    CString str;

    str.Format(_T("%X%X%X.%X%X%X"), p_UNION_FREQUENCY->st_FREQUENCY.HundredsDigit
        , p_UNION_FREQUENCY->st_FREQUENCY.TensDigit
        , p_UNION_FREQUENCY->st_FREQUENCY.OnesDigit
        , p_UNION_FREQUENCY->st_FREQUENCY.TenthsDigit
        , p_UNION_FINE_FREQUENCY_AND_AJ->st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , p_UNION_FINE_FREQUENCY_AND_AJ->st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );

    return str;
}
