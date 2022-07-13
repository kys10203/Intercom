// FMT_NET_LOAD2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "FMT_NET_LOAD2.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CFMT_NET_LOAD2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFMT_NET_LOAD2, CDialogEx)

CFMT_NET_LOAD2::CFMT_NET_LOAD2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFMT_NET_LOAD2::IDD, pParent)
{

	EnableAutomation();

}

CFMT_NET_LOAD2::~CFMT_NET_LOAD2()
{
}

void CFMT_NET_LOAD2::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CFMT_NET_LOAD2::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ01, m_Edit_Arc2_FMT_Freq01);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ02, m_Edit_Arc2_FMT_Freq02);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ03, m_Edit_Arc2_FMT_Freq03);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ04, m_Edit_Arc2_FMT_Freq04);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ05, m_Edit_Arc2_FMT_Freq05);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ06, m_Edit_Arc2_FMT_Freq06);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ07, m_Edit_Arc2_FMT_Freq07);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ08, m_Edit_Arc2_FMT_Freq08);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ09, m_Edit_Arc2_FMT_Freq09);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ10, m_Edit_Arc2_FMT_Freq10);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ11, m_Edit_Arc2_FMT_Freq11);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ12, m_Edit_Arc2_FMT_Freq12);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ13, m_Edit_Arc2_FMT_Freq13);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ14, m_Edit_Arc2_FMT_Freq14);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ15, m_Edit_Arc2_FMT_Freq15);
    DDX_Control(pDX, IDC_EDIT_ARC2_FMT_N_FREQ16, m_Edit_Arc2_FMT_Freq16);
}


BEGIN_MESSAGE_MAP(CFMT_NET_LOAD2, CDialogEx)
    ON_WM_CLOSE()
    ON_BN_CLICKED(IDC_BTN_ARC2_FMT_DATA_LOAD, &CFMT_NET_LOAD2::OnBnClickedBtnArc2FmtDataLoad)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFMT_NET_LOAD2, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IFMT_NET_LOAD2에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {98AB4848-660F-487E-873F-64D4FE97A393}
static const IID IID_IFMT_NET_LOAD2 =
{ 0x98AB4848, 0x660F, 0x487E, { 0x87, 0x3F, 0x64, 0xD4, 0xFE, 0x97, 0xA3, 0x93 } };

BEGIN_INTERFACE_MAP(CFMT_NET_LOAD2, CDialogEx)
	INTERFACE_PART(CFMT_NET_LOAD2, IID_IFMT_NET_LOAD2, Dispatch)
END_INTERFACE_MAP()


// CFMT_NET_LOAD2 메시지 처리기입니다.


BOOL CFMT_NET_LOAD2::PreTranslateMessage(MSG* pMsg)
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


void CFMT_NET_LOAD2::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    DestroyWindow();
    CDialogEx::OnClose();
}


void CFMT_NET_LOAD2::OnBnClickedBtnArc2FmtDataLoad()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq01, &un_FMT_NET_FREQUENCY01);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq02, &un_FMT_NET_FREQUENCY02);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq03, &un_FMT_NET_FREQUENCY03);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq04, &un_FMT_NET_FREQUENCY04);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq05, &un_FMT_NET_FREQUENCY05);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq06, &un_FMT_NET_FREQUENCY06);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq07, &un_FMT_NET_FREQUENCY07);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq08, &un_FMT_NET_FREQUENCY08);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq09, &un_FMT_NET_FREQUENCY09);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq10, &un_FMT_NET_FREQUENCY10);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq11, &un_FMT_NET_FREQUENCY11);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq12, &un_FMT_NET_FREQUENCY12);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq13, &un_FMT_NET_FREQUENCY13);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq14, &un_FMT_NET_FREQUENCY14);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq15, &un_FMT_NET_FREQUENCY15);
    FMT_NET_Freq_Init(&m_Edit_Arc2_FMT_Freq16, &un_FMT_NET_FREQUENCY16);

    MSG_FMT_NET_FREQUENCY[0] = un_FMT_NET_FREQUENCY01.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[1] = un_FMT_NET_FREQUENCY02.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[2] = un_FMT_NET_FREQUENCY03.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[3] = un_FMT_NET_FREQUENCY04.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[4] = un_FMT_NET_FREQUENCY05.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[5] = un_FMT_NET_FREQUENCY06.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[6] = un_FMT_NET_FREQUENCY07.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[7] = un_FMT_NET_FREQUENCY08.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[8] = un_FMT_NET_FREQUENCY09.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[9] = un_FMT_NET_FREQUENCY10.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[10] = un_FMT_NET_FREQUENCY11.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[11] = un_FMT_NET_FREQUENCY12.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[12] = un_FMT_NET_FREQUENCY13.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[13] = un_FMT_NET_FREQUENCY14.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[14] = un_FMT_NET_FREQUENCY15.w_FMT_NET_FREQUENCY;
    MSG_FMT_NET_FREQUENCY[15] = un_FMT_NET_FREQUENCY16.w_FMT_NET_FREQUENCY;

    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY01.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY01.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY02.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY02.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY03.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY03.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY04.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY04.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY05.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY05.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY06.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY06.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY07.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY07.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY08.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY08.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY09.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY09.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY10.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY10.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY11.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY11.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY12.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY12.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY13.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY13.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY14.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY14.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY15.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY15.w_FMT_NET_FREQUENCY;
    ((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY16.w_FMT_NET_FREQUENCY = un_FMT_NET_FREQUENCY16.w_FMT_NET_FREQUENCY;

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG25,               /* Message ID to create             */
        DBLK25,              /* Data Block ID                    */
        RT2_ADDR,                  /* RT address                       */
        03,                  /* RT subaddress                    */ // subaddress : 03 (FMT Net Load)
        16,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_FMT_NET_FREQUENCY);          /* Data words for the async message */


    // aceBCStart(DevNum, MJR, -1);
    aceBCDataBlkWrite(DevNum, DBLK25, MSG_FMT_NET_FREQUENCY, 16, 0);
    aceBCSendAsyncMsgHP(DevNum, MSG25, wFrmTime);

    ::SendMessage(((CITC_GUI_01Dlg *)GetParent())->m_hWnd, UWM_SAVE_ARC2_FMT, NULL, NULL);
}


BOOL CFMT_NET_LOAD2::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ01, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY01) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ02, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY02) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ03, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY03) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ04, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY04) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ05, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY05) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ06, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY06) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ07, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY07) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ08, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY08) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ09, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY09) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ10, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY10) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ11, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY11) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ12, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY12) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ13, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY13) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ14, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY14) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ15, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY15) ));
    SetDlgItemTextW(IDC_EDIT_ARC2_FMT_N_FREQ16, NumToCString( &(((CITC_GUI_01Dlg *)GetParent())->un_prev_ARC2_FMT_NET_FREQUENCY16) ));

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CFMT_NET_LOAD2::FMT_NET_Freq_Init(CEdit* p_Edit, UNION_FMT_NET_FREQUENCY* p_UNION_FMT_NET_FREQUENCY)
{
    CString str;
    U16BIT m_HundredthDigit;
    p_Edit->GetWindowTextW(str);

    float m_FMT_NET_FREQUENCY = _tstof(str);
    U32BIT u32_Freq = (U32BIT)(m_FMT_NET_FREQUENCY*1000);

    if((225000<=u32_Freq) & (u32_Freq<=399975))
    {
        p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredsDigit = (u32_Freq / 100000);
        u32_Freq = u32_Freq - (p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredsDigit * 100000);
        p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TensDigit = (u32_Freq / 10000);
        u32_Freq = u32_Freq - (p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TensDigit * 10000);
        p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.OnesDigit = (u32_Freq / 1000);
        u32_Freq = u32_Freq - (p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.OnesDigit * 1000);
        p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TenthsDigit = (u32_Freq / 100);
        u32_Freq = u32_Freq - (p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TenthsDigit * 100);

        m_HundredthDigit= (u32_Freq / 10);
        switch (m_HundredthDigit)
        {
        case 0:
            p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredthsDigit = 0;
            break;
        case 2:
            p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredthsDigit = 1;
            break;
        case 5:
            p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredthsDigit = 2;
            break;
        case 7:
            p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredthsDigit = 3;
            break;
        }
    }
}


CString CFMT_NET_LOAD2::NumToCString(UNION_FMT_NET_FREQUENCY* p_UNION_FMT_NET_FREQUENCY)
{
    CString str;

    switch( p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredthsDigit )
    {
    case 0x0:
        str.Format(_T("%X%X%X.%X00"), p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredsDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TensDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.OnesDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TenthsDigit );
        break;
        case 0x1:
            str.Format(_T("%X%X%X.%X25"), p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredsDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TensDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.OnesDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TenthsDigit );
        break;
        case 0x2:
            str.Format(_T("%X%X%X.%X50"), p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredsDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TensDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.OnesDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TenthsDigit );
        break;
        case 0x3:
            str.Format(_T("%X%X%X.%X75"), p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.HundredsDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TensDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.OnesDigit
            , p_UNION_FMT_NET_FREQUENCY->st_FMT_NET_FREQUENCY.TenthsDigit );
        break;
    }

    return str;
}
