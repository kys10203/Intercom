// MWOD_LOAD2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "MWOD_LOAD2.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"
#include "SET_ARC2.h"

// CMWOD_LOAD2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMWOD_LOAD2, CDialogEx)

CMWOD_LOAD2::CMWOD_LOAD2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMWOD_LOAD2::IDD, pParent)
{

	EnableAutomation();

}

CMWOD_LOAD2::~CMWOD_LOAD2()
{
}

void CMWOD_LOAD2::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CDialogEx::OnFinalRelease();
}

void CMWOD_LOAD2::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_WOD01_2, m_WOD01_2);
    DDX_Control(pDX, IDC_WOD02_2, m_WOD02_2);
    DDX_Control(pDX, IDC_WOD03_2, m_WOD03_2);
    DDX_Control(pDX, IDC_WOD04_2, m_WOD04_2);
    DDX_Control(pDX, IDC_WOD05_2, m_WOD05_2);
    DDX_Control(pDX, IDC_WOD06_2, m_WOD06_2);
    DDX_Control(pDX, IDC_WODD_2, m_WODD_2);
}


BEGIN_MESSAGE_MAP(CMWOD_LOAD2, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_MWOD_DATA_LOAD_2, &CMWOD_LOAD2::OnBnClickedBtnMwodDataLoad2)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMWOD_LOAD2, CDialogEx)
END_DISPATCH_MAP()

// ����: IID_IMWOD_LOAD2�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {46698E4B-8797-47B4-883C-3E43AA31478F}
static const IID IID_IMWOD_LOAD2 =
{ 0x46698E4B, 0x8797, 0x47B4, { 0x88, 0x3C, 0x3E, 0x43, 0xAA, 0x31, 0x47, 0x8F } };

BEGIN_INTERFACE_MAP(CMWOD_LOAD2, CDialogEx)
	INTERFACE_PART(CMWOD_LOAD2, IID_IMWOD_LOAD2, Dispatch)
END_INTERFACE_MAP()


// CMWOD_LOAD2 �޽��� ó�����Դϴ�.


void CMWOD_LOAD2::OnBnClickedBtnMwodDataLoad2()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

    MWODEditToDouble(&m_WOD01_2, &un_WOD_SEGMENT1);
    MWODEditToDouble(&m_WOD02_2, &un_WOD_SEGMENT2);
    MWODEditToDouble(&m_WOD03_2, &un_WOD_SEGMENT3);
    MWODEditToDouble(&m_WOD04_2, &un_WOD_SEGMENT4);
    MWODEditToDouble(&m_WOD05_2, &un_WOD_SEGMENT5);
    MWODEditToDouble(&m_WOD06_2, &un_WOD_SEGMENT6);

    CString s_WODD;
    m_WODD_2.GetWindowTextW(s_WODD);
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
        AfxMessageBox(_T("������ ������ϴ�.(WOD_DAY)"));
        return;
    }

    MSG_MWOD_Load[0] = un_WOD_SEGMENT1.w_WOD_SEGMENT;
    MSG_MWOD_Load[1] = un_WOD_SEGMENT2.w_WOD_SEGMENT;
    MSG_MWOD_Load[2] = un_WOD_SEGMENT3.w_WOD_SEGMENT;
    MSG_MWOD_Load[3] = un_WOD_SEGMENT4.w_WOD_SEGMENT;
    MSG_MWOD_Load[4] = un_WOD_SEGMENT5.w_WOD_SEGMENT;
    MSG_MWOD_Load[5] = un_WOD_SEGMENT6.w_WOD_SEGMENT;
    MSG_MWOD_Load[6] = un_WOD_DAY.w_WOD_DAY;

    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT1.w_WOD_SEGMENT = un_WOD_SEGMENT1.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT2.w_WOD_SEGMENT = un_WOD_SEGMENT2.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT3.w_WOD_SEGMENT = un_WOD_SEGMENT3.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT4.w_WOD_SEGMENT = un_WOD_SEGMENT4.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT5.w_WOD_SEGMENT = un_WOD_SEGMENT5.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT6.w_WOD_SEGMENT = un_WOD_SEGMENT6.w_WOD_SEGMENT;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_DAY.w_WOD_DAY = un_WOD_DAY.w_WOD_DAY;

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG24,               /* Message ID to create             */
        DBLK24,              /* Data Block ID                    */
        RT2_ADDR,                  /* RT address                       */
        02,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_MWOD_Load);          /* Data words for the async message */

    aceBCDataBlkWrite(DevNum, DBLK24, MSG_MWOD_Load, 7, 0);
    aceBCSendAsyncMsgHP(DevNum, MSG24, wFrmTime);

    ::SendMessage(((CITC_GUI_01Dlg *)GetParent())->m_hWnd, UWM_SAVE_ARC2_MWOD, NULL, NULL);
}


BOOL CMWOD_LOAD2::PreTranslateMessage(MSG* pMsg)
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


void CMWOD_LOAD2::OnClose()
{
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
    DestroyWindow();
    CDialogEx::OnClose();
}


U16BIT CMWOD_LOAD2::MWODEditToDouble(CEdit* EditAddr, UNION_WOD_SEGMENT* p_WOD_SEGMENT)
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
        // ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("������ ������ϴ�.(MWOD Segment)"));
        // AfxMessageBox(_T("������ ������ϴ�.(MWOD Segment)"));
        return -1;
    }
}


BOOL CMWOD_LOAD2::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    DpPrevSet();

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CMWOD_LOAD2::DpPrevSet(void)
{
     CString str;

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT1.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT1.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT1.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT1.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT1.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD01_2, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT2.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT2.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT2.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT2.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT2.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD02_2, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT3.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT3.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT3.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT3.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT3.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD03_2, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT4.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT4.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT4.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT4.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT4.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD04_2, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT5.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT5.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT5.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT5.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT5.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD05_2, str);

    str = NumToString( ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT6.st_WOD_SEGMENT.HundredsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT6.st_WOD_SEGMENT.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT6.st_WOD_SEGMENT.OnesDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT6.st_WOD_SEGMENT.TenthsDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_SEGMENT6.st_WOD_SEGMENT.HundredthsDigit );
    SetDlgItemTextW(IDC_WOD06_2, str);

    str.Format(_T("3%X%X"), ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_DAY.st_WOD_DAY.TensDigit
        , ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_WOD_DAY.st_WOD_DAY.OnesDigit );
    SetDlgItemTextW(IDC_WODD_2, str);

}


CString CMWOD_LOAD2::NumToString(U16BIT Hundreds, U16BIT Tens, U16BIT Ones, U16BIT Tenths, U16BIT Hundredths)
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


void CMWOD_LOAD2::CheckPresentARC2Setting(void)
{
    CString str = NULL;

    if(1 == ((CSET_ARC2 *)GetParent())->m_combo_arc2_mode.GetCurSel()) // ������ ���
    {
        ((CSET_ARC2 *)GetParent())->m_edit_arc2_channel.GetWindowTextW(str);
        ((CSET_ARC2 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.ChannelNumber = (U16BIT)(_ttoi(str)); // GUI (Preset Mode ��, Channel Number �Է�(01~99))
        ((CSET_ARC2 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x1; // Preset Mode���� ��� ���� �� : �Է��� Channel Number �� Memory Managemet=0001(Tune Channel) ����(Subaddr 01)
    }
    else if(0 == ((CSET_ARC2 *)GetParent())->m_combo_arc2_mode.GetCurSel()) // �Ŵ��� ���
    {
        GetDlgItemText(IDC_EDIT_ARC2_FREQ, str);
        ((CSET_ARC2 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x4; // Manual Mode���� ��� ���� �� : �Է��� Frequency �� Memory Managemet=0100(Tune Direct) ����(Subaddr 01)

        float m_Freq = _tstof(str);
        U32BIT u32_Freq = (U32BIT)(m_Freq*1000);

        if((0<u32_Freq) & (u32_Freq<1000))
        {
            ((CSET_ARC2 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.HundredsDigit = (u32_Freq / 100000);
            u32_Freq = u32_Freq - (((CSET_ARC2 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.HundredsDigit * 100000);
            ((CSET_ARC2 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.TensDigit = (u32_Freq / 10000);
            u32_Freq = u32_Freq - (((CSET_ARC2 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.TensDigit * 10000);
            ((CSET_ARC2 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.OnesDigit = (u32_Freq / 1000);
            u32_Freq = u32_Freq - (((CSET_ARC2 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.OnesDigit * 1000);
            ((CSET_ARC2 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.TenthsDigit = (u32_Freq / 100);
            u32_Freq = u32_Freq - (((CSET_ARC2 *)GetParent())->un_COARSE_FREQUENCY.st_FREQUENCY.TenthsDigit * 100);

            ((CSET_ARC2 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit = (u32_Freq / 10);
            u32_Freq = u32_Freq - (((CSET_ARC2 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit * 10);
            ((CSET_ARC2 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit = (u32_Freq/ 1);
        }
        else
        {
            ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("���ļ��� ���� ������ ������ϴ�"));
        }

        if(((CSET_ARC2 *)GetParent())->m_check_arc2_zeroize.GetCheck())
        {
            ((CSET_ARC2 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0xF;
        }

        /* 0000 = FIXED FREQ, 0001 = HQ ACTIVE
        Others = Reserved */
        if(((CSET_ARC2 *)GetParent())->m_combo_arc2_freq1_manage.GetCurSel())
            ((CSET_ARC2 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement = 0x1;
        else
            ((CSET_ARC2 *)GetParent())->un_FINE_FREQUENCY_AND_AJ.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement = 0x0;
    }

    switch(((CSET_ARC2 *)GetParent())->m_combo_arc2_modulation.GetCurSel())
    {
    case 0:
        ((CSET_ARC2 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x0;
        break;
    case 1:
        ((CSET_ARC2 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x1;
        break;
    case 2:
        ((CSET_ARC2 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x2;
        break;
    case 3:
        ((CSET_ARC2 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.Modulation = 0x3;
        break;
    }

    /* BIT[13] ADF
    0 = Disable, 1 = Enable */
    ((CSET_ARC2 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.ADF = ((CSET_ARC2 *)GetParent())->m_check_arc2_adf.GetCheck();

    /* BIT[12] X-Mode
    0 = Disable, 1 = Enable */
    ((CSET_ARC2 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.XMode = ((CSET_ARC2 *)GetParent())->m_check_arc2_XMode.GetCheck();

    switch(((CSET_ARC2 *)GetParent())->m_combo_arc2_op_mode.GetCurSel())
    {
    case 0:
        ((CSET_ARC2 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.GuardReceiver = 0x0;   // T/R Mode : Gurad Receiver(BC-RT, SA01, W02, b04)=0(Disable) ����
        break;
    case 1:
        ((CSET_ARC2 *)GetParent())->un_MODE_AND_GUARD.st_MODE_AND_GUARD.GuardReceiver = 0x1;   // T/R+G Mode : Guard Receiver(BC-RT, SA01, W02, b04)=1(Enable) ����
        break;
    case 2:
        ((CSET_ARC2 *)GetParent())->un_PRESET_SELECT.st_PRESET_SELECT.MemoryManagement = 0x7; // G Mode : Memory Management(BC-RT, SA01, W01, b08-11)=0111(Guard) ����
        break;
    }

    ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.CompressorOption = ((CSET_ARC2 *)GetParent())->m_check_arc2_compressor.GetCheck();

    if(((CSET_ARC2 *)GetParent())->m_check_arc2_MainSquelch.GetCheck())
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.MainSquelch = 0x0;
    else
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.MainSquelch = 0x1;

    ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.GuardSquelch = ((CSET_ARC2 *)GetParent())->m_check_arc2_GuardSquelch.GetCheck();

    ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.ToneKey = ((CSET_ARC2 *)GetParent())->m_check_arc2_ToneKey.GetCheck();

    /* 00 = High Power, 01 = Medium Power
    10 = Low Power, 11 = Reserved */
    switch(((CSET_ARC2 *)GetParent())->m_combo_arc2_rf_power.GetCurSel())
    {
    case 0:
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x0;
        break;
    case 1:
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x1;
        break;
    case 2:
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x2;
        break;
    case 3:
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x3;
        break;
    }

    switch(((CSET_ARC2 *)GetParent())->m_combo_arc2_rf_power.GetCurSel())
    {
    case 0:
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x0;
        break;
    case 1:
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x1;
        break;
    case 2:
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x2;
        break;
    case 3:
        ((CSET_ARC2 *)GetParent())->un_OPTIONS.st_OPTIONS.RFPower = 0x3;
        break;
    }

    switch(((CSET_ARC2 *)GetParent())->m_combo_arc2_tod_manage.GetCurSel())
    {
    case 0:
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x0;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)/10;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)%10;
        break;
    case 1:
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x1;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)/10;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)%10;
        break;
    case 2:
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x2;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)/10;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)%10;
        break;
    case 3:
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x5;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)/10;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)%10;
        break;
    case 4:
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x6;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)/10;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)%10;
        break;
    case 5:
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0x8;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)/10;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)%10;
        break;
    case 6:
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0xA;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)/10;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)%10;
        break;
    case 7:
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.TODManagement = 0xB;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayTensDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)/10;
        ((CSET_ARC2 *)GetParent())->un_TOD_MANAGEMENT.st_TOD_MANAGEMENT.DayOnesDigit = GetTODDay(&((CSET_ARC2 *)GetParent())->m_edit_arc2_todday)%10;
        break;
    }

    ((CSET_ARC2 *)GetParent())->un_BIT_CONTROL.st_BIT_CONTROL.InitiateIBIT = ((CSET_ARC2 *)GetParent())->m_check_arc2_ibit.GetCheck();
}


U8BIT CMWOD_LOAD2::GetTODDay(CEdit* EditBox)
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
