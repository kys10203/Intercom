
// ITC_GUI_01Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "ITC_GUI_01Dlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // 대화 상자 데이터입니다.
    enum { IDD = IDD_ABOUTBOX };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

    // 구현입니다.
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CITC_GUI_01Dlg 대화 상자


IMPLEMENT_DYNAMIC(CITC_GUI_01Dlg, CDialogEx);

CITC_GUI_01Dlg::CITC_GUI_01Dlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CITC_GUI_01Dlg::IDD, pParent)
    , m_str_ip(_T(""))
    , m_str_port(_T(""))
    , m_connect_flag(0)
    , MIC1_Left_Flag(FALSE)
    , MIC1_Right_Flag(FALSE)
    , MIC2_Left_Flag(FALSE)
    , MIC2_Right_Flag(FALSE)
    , TONE1_Left_Flag(FALSE)
    , TONE1_Right_Flag(FALSE)
    , TONE2_Left_Flag(FALSE)
    , TONE2_Right_Flag(FALSE)
    , SPK1_Left_Flag(FALSE)
    , SPK1_Right_Flag(FALSE)
    , SPK2_Left_Flag(FALSE)
    , SPK2_Right_Flag(FALSE)
    , b_ARC1_flag(FALSE)
    , b_ARC2_flag(FALSE)
    , StartCode(0xD3)
    , EndCode(0x7F)
    , MIC1(0x1101)
    , MIC2(0x1102)
    , TONE1(0x2201)
    , TONE2(0x2202)
    , SPK1(0x3301)
    , SPK2(0x3302)
    , ARC1(0x4401)
    , ARC2(0x4402)
    , prev_Codec_MIC1(0)
    , prev_Codec_MIC2(0)
    , prev_Codec_SPK1(0)
    , prev_Codec_SPK2(0)
    , prev_MIC1_Path(100)
    , prev_TONE1_Path(100)
    , prev_SPK1_Path(100)
    , prev_MIC2_Path(100)
    , prev_TONE2_Path(100)
    , prev_SPK2_Path(100)
    , prev_ARC1_Path(100)
    , prev_ARC2_Path(100)
    //,u32BusSelection(1)          /* Bus A */
    //,wDisplaySelection(0x0002)   /* Decoded */
    , ARC1_Index(0)
    , ARC2_Index(0)
    , f_ACK(FALSE)
    , b_BCState(FALSE)
    , b_PrevCOM2XMode(FALSE)
    , b_PrevCOM3XMode(FALSE)
    , f_ARC1_Dlg(FALSE)
    , f_ARC2_Dlg(FALSE)
    , f_ICS_SET(FALSE)
    , f_SET_DIS(FALSE)
    , test(_T(""))
    , MIC1_XAudio_A_Flag(FALSE)
    , MIC1_XAudio_B_Flag(FALSE)
    , MIC2_XAudio_A_Flag(FALSE)
    , MIC2_XAudio_B_Flag(FALSE)
    , SPK1_RAudio_A_Flag(FALSE)
    , SPK1_RAudio_B_Flag(FALSE)
    , SPK2_RAudio_A_Flag(FALSE)
    , SPK2_RAudio_B_Flag(FALSE)
    , ARC1_RT_ON(FALSE)
    , ARC2_RT_ON(FALSE)
    , ARC1_XMODE_EN(FALSE)
    , ARC2_XMODE_EN(FALSE)
    , ARC1_PTT(FALSE)
    , ARC2_PTT(FALSE)
    , b_PowerSupp(FALSE)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_pAutoProxy = NULL;
}

CITC_GUI_01Dlg::~CITC_GUI_01Dlg()
{
    // 이 대화 상자에 대한 자동화 프록시가 있을 경우 이 대화 상자에 대한
    //  후방 포인터를 NULL로 설정하여
    //  대화 상자가 삭제되었음을 알 수 있게 합니다.
    if (m_pAutoProxy != NULL)
        m_pAutoProxy->m_pDialog = NULL;
}

void CITC_GUI_01Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_MBTN_CONNECT, m_mbtn_connect);
    DDX_Control(pDX, IDC_MBTN_SET_ETHERNET, m_mbtn_set_ethernet);
    DDX_Control(pDX, IDC_MBTN_SET_1553B, m_mbtn_set_1553b);
    DDX_Control(pDX, IDC_MBTN_SET_ARC1, m_mbtn_set_arc1);
    DDX_Control(pDX, IDC_MBTN_SET_ARC2, m_mbtn_set_arc2);
    DDX_Control(pDX, IDC_MBTN_EXIT, m_mbtn_exit);
    DDX_Control(pDX, IDC_COMBO_MIC1, m_combo_MIC1);
    DDX_Control(pDX, IDC_COMBO_MIC2, m_combo_MIC2);
    DDX_Control(pDX, IDC_COMBO_TONE1, m_combo_Tone1);
    DDX_Control(pDX, IDC_COMBO_TONE2, m_combo_Tone2);
    DDX_Control(pDX, IDC_COMBO_TONE_TYPE1, m_combo_Tone_Type1);
    DDX_Control(pDX, IDC_COMBO_TONE_TYPE2, m_combo_Tone_Type2);
    DDX_Control(pDX, IDC_ICON_ETHERNET, m_icon_ethernet);
    DDX_Control(pDX, IDC_ICON_1553B, m_icon_1553b);
    DDX_Control(pDX, IDC_COMBO_SPK1, m_combo_SPK1);
    DDX_Control(pDX, IDC_COMBO_SPK2, m_combo_SPK2);
    DDX_Control(pDX, IDC_SLIDER_MIC1, m_slider_mic1);
    DDX_Control(pDX, IDC_SLIDER_MIC2, m_slider_mic2);
    DDX_Control(pDX, IDC_SLIDER_TONE1, m_slider_tone1);
    DDX_Control(pDX, IDC_SLIDER_TONE2, m_slider_tone2);
    DDX_Control(pDX, IDC_SLIDER_SPK1, m_slider_spk1);
    DDX_Control(pDX, IDC_SLIDER_SPK2, m_slider_spk2);
    DDX_Control(pDX, IDC_COMBO_ARC1, m_combo_ARC1);
    DDX_Control(pDX, IDC_COMBO_ARC2, m_combo_ARC2);
    DDX_Control(pDX, IDC_SLIDER_ARC1, m_slider_arc1);
    DDX_Control(pDX, IDC_SLIDER_ARC2, m_slider_arc2);
    DDX_Control(pDX, IDC_MBTN_POW_SUP, m_mbtn_pow_sup);
    DDX_Control(pDX, IDC_STATIC_ARC1_OPMODE, m_TEXT_ARC1_OPMODE);
    DDX_Control(pDX, IDC_STATIC_ARC1_MODE, m_TEXT_ARC1_MODE);
    DDX_Control(pDX, IDC_STATIC_ARC1_FREQ, m_TEXT_ARC1_FREQ);
    DDX_Control(pDX, IDC_STATIC_ARC1_FREQ_MNGMT, m_TEXT_ARC1_FREQ_MNGMT);
    DDX_Control(pDX, IDC_STATIC_ARC1_CHANNEL, m_TEXT_ARC1_CHANNEL);
    DDX_Control(pDX, IDC_STATIC_ARC1_MODULATION, m_TEXT_ARC1_MODULATION);
    DDX_Control(pDX, IDC_STATIC_ARC1_RFPOWER, m_TEXT_ARC1_RFPOWER);
    DDX_Control(pDX, IDC_STATIC_ARC1_TOD_STAT, m_TEXT_ARC1_TOD_STAT);
    DDX_Control(pDX, IDC_STATIC_ARC1_TOD_DAY, m_TEXT_ARC1_TOD_DAY);
    DDX_Control(pDX, IDC_STATIC_ARC1_SWID, m_TEXT_ARC1_SWID);
    DDX_Control(pDX, IDC_STATIC_ARC1_SWVER, m_TEXT_ARC1_SWVER);
    DDX_Control(pDX, IDC_STATIC_ARC1_ZEROIZE, m_LED_ARC1_ZEROIZE);
    DDX_Control(pDX, IDC_STATIC_ARC1_ADF, m_LED_ARC1_ADF);
    DDX_Control(pDX, IDC_STATIC_ARC1_COMPRESSOR, m_LED_ARC1_COMPRESSOR);
    DDX_Control(pDX, IDC_STATIC_ARC1_GUARD_SQUELCH, m_LED_ARC1_GUARD_SQUELCH);
    DDX_Control(pDX, IDC_STATIC_ARC1_XMODE, m_LED_ARC1_XMODE);
    DDX_Control(pDX, IDC_STATIC_ARC1_MAINSQUELCH, m_LED_ARC1_MAINSQUELCH);
    DDX_Control(pDX, IDC_STATIC_ARC1_TONEKEY, m_LED_ARC1_TONEKEY);
    DDX_Control(pDX, IDC_STATIC_ARC1_FMT_VALID, m_LED_ARC1_FMT_VALID);
    DDX_Control(pDX, IDC_STATIC_ARC1_CONTROL_DATA, m_LED_ARC1_CONTROL_DATA);
    DDX_Control(pDX, IDC_EDIT_LOG, m_EditLog);
    DDX_Control(pDX, IDC_STATIC_ARC2_OPMODE, m_TEXT_ARC2_OPMODE);
    DDX_Control(pDX, IDC_STATIC_ARC2_MODE, m_TEXT_ARC2_MODE);
    DDX_Control(pDX, IDC_STATIC_ARC2_FREQ, m_TEXT_ARC2_FREQ);
    DDX_Control(pDX, IDC_STATIC_ARC2_FREQ_MNGMT, m_TEXT_ARC2_FREQ_MNGMT);
    DDX_Control(pDX, IDC_STATIC_ARC2_CHANNEL, m_TEXT_ARC2_CHANNEL);
    DDX_Control(pDX, IDC_STATIC_ARC2_MODULATION, m_TEXT_ARC2_MODULATION);
    DDX_Control(pDX, IDC_STATIC_ARC2_RFPOWER, m_TEXT_ARC2_RFPOWER);
    DDX_Control(pDX, IDC_STATIC_ARC2_TOD_STAT, m_TEXT_ARC2_TOD_STAT);
    DDX_Control(pDX, IDC_STATIC_ARC2_TOD_DAY, m_TEXT_ARC2_TOD_DAY);
    DDX_Control(pDX, IDC_STATIC_ARC2_SWID, m_TEXT_ARC2_SWID);
    DDX_Control(pDX, IDC_STATIC_ARC2_SWVER, m_TEXT_ARC2_SWVER);
    DDX_Control(pDX, IDC_STATIC_ARC2_ZEROIZE, m_LED_ARC2_ZEROIZE);
    DDX_Control(pDX, IDC_STATIC_ARC2_ADF, m_LED_ARC2_ADF);
    DDX_Control(pDX, IDC_STATIC_ARC2_COMPRESSOR, m_LED_ARC2_COMPRESSOR);
    DDX_Control(pDX, IDC_STATIC_ARC2_GUARD_SQUELCH, m_LED_ARC2_GUARD_SQUELCH);
    DDX_Control(pDX, IDC_STATIC_ARC2_XMODE, m_LED_ARC2_XMODE);
    DDX_Control(pDX, IDC_STATIC_ARC2_MAINSQUELCH, m_LED_ARC2_MAINSQUELCH);
    DDX_Control(pDX, IDC_STATIC_ARC2_TONEKEY, m_LED_ARC2_TONEKEY);
    DDX_Control(pDX, IDC_STATIC_ARC2_FMT_VALID, m_LED_ARC2_FMT_VALID);
    DDX_Control(pDX, IDC_STATIC_ARC2_CONTROL_DATA, m_LED_ARC2_CONTROL_DATA);
    DDX_Control(pDX, IDC_MBTN_1553B, m_mbtn_1553B);
    DDX_Control(pDX, IDC_AIU_SW_ID, m_TEXT_AIU_SW_ID);
    DDX_Control(pDX, IDC_ICP1_COM_MODE, m_TEXT_ICP1ComMode);
    DDX_Control(pDX, IDC_ICP2_COM_MODE, m_TEXT_ICP2ComMode);
    DDX_Control(pDX, IDC_ICP1_RADIO_RMT, m_TEXT_ICP1RadioInRmt);
    DDX_Control(pDX, IDC_ICP2_RADIO_RMT, m_TEXT_ICP2RadioInRmt);
    DDX_Control(pDX, IDC_ICP1_VMU_MODE, m_TEXT_ICP1VMUMode);
    DDX_Control(pDX, IDC_ICP2_VMU_MODE, m_TEXT_ICP2VMUMode);
    DDX_Control(pDX, IDC_ICP1_ICS_PTT, m_LED_ICP1ICSPTT);
    DDX_Control(pDX, IDC_ICP2_ICS_PTT, m_LED_ICP2ICSPTT);
    DDX_Control(pDX, IDC_ICP1_SELECTED_PTT, m_LED_ICP1SelectedPTT);
    DDX_Control(pDX, IDC_ICP2_SELECTED_PTT, m_LED_ICP2SelectedPTT);
    DDX_Control(pDX, IDC_AIU_WOW_ON, m_LED_AIU_WowOn);
    DDX_Control(pDX, IDC_AIU_BIT_IN_PROGRESS, m_LED_AIIU_BITInProgress);
    DDX_Control(pDX, IDC_AIU_COMSEC_INTERFACE, m_TEXT_AIU_COMSECInterface);
    DDX_Control(pDX, IDC_AIU_CURRENT_WARNING, m_TEXT_AIU_CurrentWarning);
}

BEGIN_MESSAGE_MAP(CITC_GUI_01Dlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_CLOSE()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_MBTN_EXIT, &CITC_GUI_01Dlg::OnBnClickedMbtnExit)
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_MBTN_CONNECT, &CITC_GUI_01Dlg::OnBnClickedMbtnConnect)
    ON_BN_CLICKED(IDC_MBTN_SET_ETHERNET, &CITC_GUI_01Dlg::OnBnClickedMbtnSetEthernet)
    ON_BN_CLICKED(IDC_MBTN_SET_ARC1, &CITC_GUI_01Dlg::OnBnClickedMbtnSetArc1)
    ON_BN_CLICKED(IDC_MBTN_SET_ARC2, &CITC_GUI_01Dlg::OnBnClickedMbtnSetArc2)
    ON_CBN_SELCHANGE(IDC_COMBO_MIC1, &CITC_GUI_01Dlg::OnCbnSelchangeComboMic1)
    ON_CBN_SELCHANGE(IDC_COMBO_MIC2, &CITC_GUI_01Dlg::OnCbnSelchangeComboMic2)
    ON_CBN_SELCHANGE(IDC_COMBO_TONE1, &CITC_GUI_01Dlg::OnCbnSelchangeComboTone1)
    ON_CBN_SELCHANGE(IDC_COMBO_TONE2, &CITC_GUI_01Dlg::OnCbnSelchangeComboTone2)
    ON_MESSAGE(25001, &CITC_GUI_01Dlg::On25001)
    ON_MESSAGE(25002, &CITC_GUI_01Dlg::On25002)
    ON_BN_CLICKED(IDC_BTN_MWOD_STATUS1, &CITC_GUI_01Dlg::OnBnClickedBtnMwodStatus1)
    ON_BN_CLICKED(IDC_BTN_PRESET_STATUS1, &CITC_GUI_01Dlg::OnBnClickedBtnPresetStatus1)
    ON_BN_CLICKED(IDC_BTN_BIT_SUMMARY1, &CITC_GUI_01Dlg::OnBnClickedBtnBitSummary1)
    ON_BN_CLICKED(IDC_BTN_MWOD_STATUS2, &CITC_GUI_01Dlg::OnBnClickedBtnMwodStatus2)
    ON_BN_CLICKED(IDC_BTN_PRESET_STATUS2, &CITC_GUI_01Dlg::OnBnClickedBtnPresetStatus2)
    ON_BN_CLICKED(IDC_BTN_BIT_SUMMARY2, &CITC_GUI_01Dlg::OnBnClickedBtnBitSummary2)
    ON_BN_CLICKED(IDC_MBTN_SET_ICS, &CITC_GUI_01Dlg::OnBnClickedMbtnSetIcs)
    ON_BN_CLICKED(IDC_BTN_FAULT_DATA, &CITC_GUI_01Dlg::OnBnClickedBtnFaultData)
    ON_CBN_SELCHANGE(IDC_COMBO_SPK1, &CITC_GUI_01Dlg::OnCbnSelchangeComboSpk1)
    ON_CBN_SELCHANGE(IDC_COMBO_SPK2, &CITC_GUI_01Dlg::OnCbnSelchangeComboSpk2)
    ON_BN_CLICKED(IDC_BTN_MIC1, &CITC_GUI_01Dlg::OnBnClickedBtnMic1)
    ON_BN_CLICKED(IDC_BTN_MIC2, &CITC_GUI_01Dlg::OnBnClickedBtnMic2)
    ON_BN_CLICKED(IDC_BTN_TONE1, &CITC_GUI_01Dlg::OnBnClickedBtnTone1)
    ON_BN_CLICKED(IDC_BTN_TONE2, &CITC_GUI_01Dlg::OnBnClickedBtnTone2)
    ON_BN_CLICKED(IDC_BTN_SPK1, &CITC_GUI_01Dlg::OnBnClickedBtnSpk1)
    ON_BN_CLICKED(IDC_BTN_SPK2, &CITC_GUI_01Dlg::OnBnClickedBtnSpk2)
    ON_BN_CLICKED(IDC_MBTN_POW_SUP, &CITC_GUI_01Dlg::OnBnClickedMbtnPowSup)
    ON_MESSAGE(UWM_ICS_DIS, &CITC_GUI_01Dlg::OnUwmIcsDis)
    ON_BN_CLICKED(IDC_BTN_ARC1, &CITC_GUI_01Dlg::OnBnClickedBtnArc1)
    ON_BN_CLICKED(IDC_BTN_ARC2, &CITC_GUI_01Dlg::OnBnClickedBtnArc2)
    ON_BN_CLICKED(IDC_BTN_LOG_CLEAR, &CITC_GUI_01Dlg::OnBnClickedBtnLogClear)
    ON_WM_TIMER()
    ON_BN_CLICKED(IDC_MBTN_1553B, &CITC_GUI_01Dlg::OnBnClickedMbtn1553b)
    ON_WM_DESTROY()
    ON_BN_CLICKED(IDC_BTN_ICS_BIT, &CITC_GUI_01Dlg::OnBnClickedBtnIcsBit)
    ON_MESSAGE(UWM_RDY_ICS_DIS, &CITC_GUI_01Dlg::OnUwmRdyIcsDis)
    ON_MESSAGE(UWM_SAVE_ARC1_MWOD, &CITC_GUI_01Dlg::OnUwmSaveArc1Mwod)
    ON_MESSAGE(UWM_SAVE_ARC1_FMT, &CITC_GUI_01Dlg::OnUwmSaveArc1Fmt)
    ON_MESSAGE(UWM_SAVE_ARC1_PRESET, &CITC_GUI_01Dlg::OnUwmSaveArc1Preset)
    ON_MESSAGE(UWM_SAVE_ARC2_MWOD, &CITC_GUI_01Dlg::OnUwmSaveArc2Mwod)
    ON_MESSAGE(UWM_SAVE_ARC2_FMT, &CITC_GUI_01Dlg::OnUwmSaveArc2Fmt)
    ON_MESSAGE(UWM_SAVE_ARC2_PRESET, &CITC_GUI_01Dlg::OnUwmSaveArc2Preset)
END_MESSAGE_MAP()


// CITC_GUI_01Dlg 메시지 처리기

BOOL CITC_GUI_01Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
    SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

    // TODO: 여기에 추가 초기화 작업을 추가합니다.
    m_mbtn_connect.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON24 ) );
    m_mbtn_set_ethernet.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON21 ) );
    m_mbtn_1553B.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON20 ) );
    m_mbtn_set_1553b.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON16 ) );
    m_mbtn_set_arc1.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON17 ) );
    m_mbtn_set_arc2.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON17 ) );
    m_mbtn_exit.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON19 ) );
    m_mbtn_set_dist.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON23 ) );
    m_mbtn_pow_sup.SetIcon( AfxGetApp() -> LoadIcon( IDI_ICON6 ) );

    SetComboAOUT(&m_combo_MIC1, 4);
    SetComboAOUT(&m_combo_MIC2, 4);
    SetComboAOUT(&m_combo_Tone1, 0);
    SetComboAOUT(&m_combo_Tone2, 0);
    SetComboAOUT(&m_combo_SPK1, 1);
    SetComboAOUT(&m_combo_SPK2, 1);
    SetComboAOUT(&m_combo_Tone_Type1, 2);
    SetComboAOUT(&m_combo_Tone_Type2, 2);
    SetComboAOUT(&m_combo_ARC1, 3);
    SetComboAOUT(&m_combo_ARC2, 3);

    m_combo_MIC1.SetCurSel(0);
    m_combo_MIC2.SetCurSel(0);
    m_combo_Tone1.SetCurSel(0);
    m_combo_Tone2.SetCurSel(0);
    m_combo_SPK1.SetCurSel(0);
    m_combo_SPK2.SetCurSel(0);
    m_combo_Tone_Type1.SetCurSel(0);
    m_combo_Tone_Type2.SetCurSel(0);
    m_combo_ARC1.SetCurSel(0);
    m_combo_ARC2.SetCurSel(0);

    m_slider_mic1.SetRangeMax(10);
    m_slider_mic2.SetRangeMax(10);
    m_slider_tone1.SetRangeMax(10);
    m_slider_tone2.SetRangeMax(10);
    m_slider_spk1.SetRangeMax(10);
    m_slider_spk2.SetRangeMax(10);
    m_slider_arc1.SetRangeMax(10);
    m_slider_arc2.SetRangeMax(10);

    m_slider_mic1.SetPageSize(1);
    m_slider_mic2.SetPageSize(1);
    m_slider_tone1.SetPageSize(1);
    m_slider_tone2.SetPageSize(1);
    m_slider_spk1.SetPageSize(1);
    m_slider_spk2.SetPageSize(1);
    m_slider_arc1.SetPageSize(1);
    m_slider_arc2.SetPageSize(1);

    m_slider_mic1.SetLineSize(1);
    m_slider_mic2.SetLineSize(1);
    m_slider_tone1.SetLineSize(1);
    m_slider_tone2.SetLineSize(1);
    m_slider_spk1.SetLineSize(1);
    m_slider_spk2.SetLineSize(1);
    m_slider_arc1.SetLineSize(1);
    m_slider_arc2.SetLineSize(1);

    memset(ARC1_Discrete, 0, 3);
    memset(ARC2_Discrete, 0, 3);
    memset(ICS_Discrete, 0, 21);

    m_str_ip = "192.168.0.100";
    m_str_port = "5000";

    memset(RecvMsg, 0, BUFSIZE);
    memset(MIC1_SentMsg, 0, BUFSIZE);
    memset(TONE1_SentMsg, 0, BUFSIZE);
    memset(SPK1_SentMsg, 0, BUFSIZE);
    memset(MIC2_SentMsg, 0, BUFSIZE);
    memset(TONE2_SentMsg, 0, BUFSIZE);
    memset(SPK2_SentMsg, 0, BUFSIZE);
    memset(WriteMsg, 0, BUFSIZE);
    memset(ARC1_SentMsg, 0, BUFSIZE);
    memset(ARC1_SentMsg2, 0, BUFSIZE);
    memset(ARC2_SentMsg, 0, BUFSIZE);
    memset(ARC2_SentMsg2, 0, BUFSIZE);

    /* 1553B 관련 초기화 파트 */
    memset(aOpCodes, 0, 20);

    un_PRESET_SELECT_ARC1.w_PRESET_SELECT = 0x0000;
    un_MODE_AND_GUARD_ARC1.w_MODE_AND_GUARD = 0x4800;
    un_MARITIME_CHANNEL_ARC1.w_MARITIME_CHANNEL = 0x0000;
    un_FREQUENCY_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_OPTIONS_ARC1.w_OPTIONS = 0x00C0;
    un_RESERVED_CONTROL_ARC1.w_RESERVED_CONTROL = 0x0000;

    un_TOD_STATUS_ARC1.w_TOD_MANAGEMENT = 0x0000;
    un_TOD_RESERVED_ARC1.w_RESERVED = 0x0000;

    un_BIT_SUMMARY_ARC1.w_BIT_SUMMARY = 0x0000;
    un_SOFTWARE_ID_ARC1.w_SOFTWARE_ID = 0x0000;
    un_SOFTWARE_VERSION_ARC1.w_SOFTWARE_VERSION = 0x0000;
    un_RESERVED_ARC1.w_RESERVED = 0x0000;
    un_FAULT_LOCATION01_ARC1.w_FAULT_LOCATION01 = 0x0000;
    un_FAULT_LOCATION02_ARC1.w_FAULT_LOCATION01 = 0x0000;

    un_MWOD_LOAD_STATUS_ARC1.w_MWOD_LOAD_STATUS = 0x0000;
    un_MWOD_1_AND_2_DAY_ARC1.w_MWOD_A_AND_B_DAY = 0x0000;
    un_MWOD_3_AND_4_DAY_ARC1.w_MWOD_A_AND_B_DAY = 0x0000;
    un_MWOD_5_AND_6_DAY_ARC1.w_MWOD_A_AND_B_DAY = 0x0000;

    un_FMT_NET_LOAD_STATUS_ARC1.w_FMT_NET_LOAD_STATUS = 0x0000;

    un_PRESET_GROUP_SELECT_ARC1.w_PRESET_GROUP_SELECT = 0x0000;
    un_COARSE_FREQUENCY_01_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_01_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_02_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_02_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_03_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_03_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_04_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_04_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_05_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_05_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_06_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_06_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_07_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_07_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_08_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_08_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_09_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_09_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_10_ARC1.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_10_ARC1.w_FINE_FREQUENCY_AND_AJ = 0x0000;

    un_prev_ARC1_WOD_SEGMENT1.w_WOD_SEGMENT = 0x0000;;
    un_prev_ARC1_WOD_SEGMENT2.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC1_WOD_SEGMENT3.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC1_WOD_SEGMENT4.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC1_WOD_SEGMENT5.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC1_WOD_SEGMENT6.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC1_WOD_DAY.w_WOD_DAY = 0x0000;

    prev_ARC1_PRESET_GROUP_SELECT = 0;
    un_prev_ARC1_PRESET_GROUP_SELECT.w_PRESET_GROUP_SELECT = 0x0000;

    un_prev_ARC1_FREQUENCY01.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY02.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY03.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY04.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY05.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY06.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY07.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY08.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY09.w_FREQUENCY = 0x2250;
    un_prev_ARC1_FREQUENCY10.w_FREQUENCY = 0x2250;

    un_prev_ARC1_FREQ_MANAGE01.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE02.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE03.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE04.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE05.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE06.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE07.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE08.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE09.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_FREQ_MANAGE10.w_FINE_FREQUENCY_AND_AJ = 0x0000;

    /* 무전기2 */
    un_PRESET_SELECT_ARC2.w_PRESET_SELECT = 0x0000;
    un_MODE_AND_GUARD_ARC2.w_MODE_AND_GUARD = 0x4800;
    un_MARITIME_CHANNEL_ARC2.w_MARITIME_CHANNEL = 0x0000;
    un_FREQUENCY_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_OPTIONS_ARC2.w_OPTIONS = 0x00C0;
    un_RESERVED_CONTROL_ARC2.w_RESERVED_CONTROL = 0x0000;

    un_TOD_STATUS_ARC2.w_TOD_MANAGEMENT = 0x0000;
    un_TOD_RESERVED_ARC2.w_RESERVED = 0x0000;

    un_BIT_SUMMARY_ARC2.w_BIT_SUMMARY = 0x0000;
    un_SOFTWARE_ID_ARC2.w_SOFTWARE_ID = 0x0000;
    un_SOFTWARE_VERSION_ARC2.w_SOFTWARE_VERSION = 0x0000;
    un_RESERVED_ARC2.w_RESERVED = 0x0000;
    un_FAULT_LOCATION01_ARC2.w_FAULT_LOCATION01 = 0x0000;
    un_FAULT_LOCATION02_ARC2.w_FAULT_LOCATION01 = 0x0000;

    un_MWOD_LOAD_STATUS_ARC2.w_MWOD_LOAD_STATUS = 0x0000;
    un_MWOD_1_AND_2_DAY_ARC2.w_MWOD_A_AND_B_DAY = 0x0000;
    un_MWOD_3_AND_4_DAY_ARC2.w_MWOD_A_AND_B_DAY = 0x0000;
    un_MWOD_5_AND_6_DAY_ARC2.w_MWOD_A_AND_B_DAY = 0x0000;

    un_FMT_NET_LOAD_STATUS_ARC2.w_FMT_NET_LOAD_STATUS = 0x0000;

    un_PRESET_GROUP_SELECT_ARC2.w_PRESET_GROUP_SELECT = 0x0000;
    un_COARSE_FREQUENCY_01_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_01_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_02_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_02_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_03_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_03_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_04_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_04_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_05_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_05_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_06_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_06_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_07_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_07_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_08_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_08_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_09_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_09_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_COARSE_FREQUENCY_10_ARC2.w_FREQUENCY = 0x0000;
    un_FINE_FREQUENCY_AND_AJ_10_ARC2.w_FINE_FREQUENCY_AND_AJ = 0x0000;

    un_prev_ARC2_WOD_SEGMENT1.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC2_WOD_SEGMENT2.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC2_WOD_SEGMENT3.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC2_WOD_SEGMENT4.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC2_WOD_SEGMENT5.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC2_WOD_SEGMENT6.w_WOD_SEGMENT = 0x0000;
    un_prev_ARC2_WOD_DAY.w_WOD_DAY = 0x0000;

    prev_ARC2_PRESET_GROUP_SELECT = 0;
    un_prev_ARC2_PRESET_GROUP_SELECT.w_PRESET_GROUP_SELECT = 0x0000;

    un_prev_ARC2_FREQUENCY01.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY02.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY03.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY04.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY05.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY06.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY07.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY08.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY09.w_FREQUENCY = 0x2250;
    un_prev_ARC2_FREQUENCY10.w_FREQUENCY = 0x2250;

    un_prev_ARC2_FREQ_MANAGE01.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE02.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE03.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE04.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE05.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE06.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE07.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE08.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE09.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_FREQ_MANAGE10.w_FINE_FREQUENCY_AND_AJ = 0x0000;

    /* 무전기1 최근 설정 */
    un_prev_ARC1_prev_ARC1_PRESET_SELECT.w_PRESET_SELECT = 0x0040;
    un_prev_ARC1_MODE_AND_GUARD.w_MODE_AND_GUARD = 0x0800;
    un_prev_ARC1_MARITIME_CHANNEL.w_MARITIME_CHANNEL = 0x0000;
    un_prev_ARC1_COARSE_FREQUENCY.w_FREQUENCY = 0x3000;
    un_prev_ARC1_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC1_OPTIONS.w_OPTIONS = 0x0000;
    un_prev_ARC1_RESERVED_CONTROL.w_RESERVED_CONTROL = 0x0000;

    un_prev_ARC1_TOD_MANAGEMENT.w_TOD_MANAGEMENT = 0x0000;
    un_prev_ARC1_TOD_RESERVED.w_RESERVED = 0x0000;

    un_prev_ARC1_BIT_CONTROL.w_BIT_CONTROL = 0x0000;

    /* 무전기1 FMT NET LOAD */
    un_prev_ARC1_FMT_NET_FREQUENCY01.w_FMT_NET_FREQUENCY = 0x8D42;
    un_prev_ARC1_FMT_NET_FREQUENCY02.w_FMT_NET_FREQUENCY = 0x8946;
    un_prev_ARC1_FMT_NET_FREQUENCY03.w_FMT_NET_FREQUENCY = 0x94A5;
    un_prev_ARC1_FMT_NET_FREQUENCY04.w_FMT_NET_FREQUENCY = 0x8E66;
    un_prev_ARC1_FMT_NET_FREQUENCY05.w_FMT_NET_FREQUENCY = 0x9C66;
    un_prev_ARC1_FMT_NET_FREQUENCY06.w_FMT_NET_FREQUENCY = 0x99E2;
    un_prev_ARC1_FMT_NET_FREQUENCY07.w_FMT_NET_FREQUENCY = 0x9892;
    un_prev_ARC1_FMT_NET_FREQUENCY08.w_FMT_NET_FREQUENCY = 0x95CA;
    un_prev_ARC1_FMT_NET_FREQUENCY09.w_FMT_NET_FREQUENCY = 0xC512;
    un_prev_ARC1_FMT_NET_FREQUENCY10.w_FMT_NET_FREQUENCY = 0xC21E;
    un_prev_ARC1_FMT_NET_FREQUENCY11.w_FMT_NET_FREQUENCY = 0xC0CB;
    un_prev_ARC1_FMT_NET_FREQUENCY12.w_FMT_NET_FREQUENCY = 0xA61A;
    un_prev_ARC1_FMT_NET_FREQUENCY13.w_FMT_NET_FREQUENCY = 0xA4D6;
    un_prev_ARC1_FMT_NET_FREQUENCY14.w_FMT_NET_FREQUENCY = 0xA242;
    un_prev_ARC1_FMT_NET_FREQUENCY15.w_FMT_NET_FREQUENCY = 0xA106;
    un_prev_ARC1_FMT_NET_FREQUENCY16.w_FMT_NET_FREQUENCY = 0x9E5E;

    /* 무전기2 최근 설정 */
    un_prev_ARC2_prev_ARC2_PRESET_SELECT.w_PRESET_SELECT = 0x0040;
    un_prev_ARC2_MODE_AND_GUARD.w_MODE_AND_GUARD = 0x0800;
    un_prev_ARC2_MARITIME_CHANNEL.w_MARITIME_CHANNEL = 0x0000;
    un_prev_ARC2_COARSE_FREQUENCY.w_FREQUENCY = 0x3000;
    un_prev_ARC2_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ = 0x0000;
    un_prev_ARC2_OPTIONS.w_OPTIONS = 0x0000;
    un_prev_ARC2_RESERVED_CONTROL.w_RESERVED_CONTROL = 0x0000;

    un_prev_ARC2_TOD_MANAGEMENT.w_TOD_MANAGEMENT = 0x0000;
    un_prev_ARC2_TOD_RESERVED.w_RESERVED = 0x0000;

    un_prev_ARC2_BIT_CONTROL.w_BIT_CONTROL = 0x0000;

    /* 무전기2 FMT NET LOAD */
    un_prev_ARC2_FMT_NET_FREQUENCY01.w_FMT_NET_FREQUENCY = 0x8D42;
    un_prev_ARC2_FMT_NET_FREQUENCY02.w_FMT_NET_FREQUENCY = 0x8946;
    un_prev_ARC2_FMT_NET_FREQUENCY03.w_FMT_NET_FREQUENCY = 0x94A5;
    un_prev_ARC2_FMT_NET_FREQUENCY04.w_FMT_NET_FREQUENCY = 0x8E66;
    un_prev_ARC2_FMT_NET_FREQUENCY05.w_FMT_NET_FREQUENCY = 0x9C66;
    un_prev_ARC2_FMT_NET_FREQUENCY06.w_FMT_NET_FREQUENCY = 0x99E2;
    un_prev_ARC2_FMT_NET_FREQUENCY07.w_FMT_NET_FREQUENCY = 0x9892;
    un_prev_ARC2_FMT_NET_FREQUENCY08.w_FMT_NET_FREQUENCY = 0x95CA;
    un_prev_ARC2_FMT_NET_FREQUENCY09.w_FMT_NET_FREQUENCY = 0xC512;
    un_prev_ARC2_FMT_NET_FREQUENCY10.w_FMT_NET_FREQUENCY = 0xC21E;
    un_prev_ARC2_FMT_NET_FREQUENCY11.w_FMT_NET_FREQUENCY = 0xC0CB;
    un_prev_ARC2_FMT_NET_FREQUENCY12.w_FMT_NET_FREQUENCY = 0xA61A;
    un_prev_ARC2_FMT_NET_FREQUENCY13.w_FMT_NET_FREQUENCY = 0xA4D6;
    un_prev_ARC2_FMT_NET_FREQUENCY14.w_FMT_NET_FREQUENCY = 0xA242;
    un_prev_ARC2_FMT_NET_FREQUENCY15.w_FMT_NET_FREQUENCY = 0xA106;
    un_prev_ARC2_FMT_NET_FREQUENCY16.w_FMT_NET_FREQUENCY = 0x9E5E;

    un_VOICE_WARNING_MESSAGE1.w_VOICE_WARNING_MESSAGE1 = 0x0002;
    un_VOICE_WARNING_MESSAGE2.w_VOICE_WARNING_MESSAGE2 = 0x0842;
    un_VOICE_WARNING_MESSAGE3.w_VOICE_WARNING_MESSAGE3 = 0x0842;
    un_VOICE_WARNING_MESSAGE4.w_VOICE_WARNING_MESSAGE4 = 0x0842;
    un_VOICE_WARNING_MESSAGE5.w_VOICE_WARNING_MESSAGE5 = 0x0842;
    un_VOICE_WARNING_MESSAGE6.w_VOICE_WARNING_MESSAGE6 = 0x0842;
    un_VOICE_WARNING_MESSAGE7.w_VOICE_WARNING_MESSAGE7 = 0x0842;
    un_VOICE_WARNING_MESSAGE8.w_VOICE_WARNING_MESSAGE8 = 0x0842;
    un_VOICE_WARNING_MESSAGE9.w_VOICE_WARNING_MESSAGE9 = 0x0000;

    // FaultData
    un_AIU_FAULT_DATA1.w_AIU_FAULT_DATA = 0x0000;
    un_AIU_FAULT_DATA2.w_AIU_FAULT_DATA = 0x0000;

    un_prev_ICS_CONTROL1.w_ICS_CONTROL1 = 0x0000;
    un_prev_ICS_CONTROL4.w_ICS_CONTROL4 = 0x0000;

    dwHBufLost = 0x00000000;
    dwMsgCount = 0x00000000;
    dwCurCount = 0x00000000;

    memset(wBuffer1, 0, 64);
    memset(wBuffer2, 0, 64);
    memset(wBuffer3, 0, 64);
    memset(wBuffer4, 0, 64);
    memset(wBuffer5, 0, 64);
    memset(wBuffer6, 0, 64);

    memset(wBuffer41, 0, 64);
    memset(wBuffer42, 0, 64);
    memset(wBuffer43, 0, 64);
    memset(wBuffer44, 0, 64);
    memset(wBuffer45, 0, 64);
    memset(wBuffer46, 0, 64);

    m_EditLog.SetLimitText(0);

    OnBnClickedMbtnSetIcs();
    p_CICS_CP->OnClose();

    MSG_AIU_BC2RT[0] = p_CICS_CP->un_ICS_CONTROL1.w_ICS_CONTROL1;
    MSG_AIU_BC2RT[1] = p_CICS_CP->un_ICS_CONTROL2.w_ICS_CONTROL2;
    MSG_AIU_BC2RT[2] = p_CICS_CP->un_ICS_CONTROL3.w_ICS_CONTROL3;
    MSG_AIU_BC2RT[3] = p_CICS_CP->un_ICS_CONTROL4.w_ICS_CONTROL4;

    MSG_AIU_BC2RT[4] = 0x0000;
    MSG_AIU_BC2RT[5] = 0x0000;
    MSG_AIU_BC2RT[6] = 0x0000;

    MSG_AIU_BC2RT[7] = p_CICS_CP->un_VOICE_WARNING_MESSAGE1.w_VOICE_WARNING_MESSAGE1;
    MSG_AIU_BC2RT[8] = p_CICS_CP->un_VOICE_WARNING_MESSAGE2.w_VOICE_WARNING_MESSAGE2;
    MSG_AIU_BC2RT[9] = p_CICS_CP->un_VOICE_WARNING_MESSAGE3.w_VOICE_WARNING_MESSAGE3;
    MSG_AIU_BC2RT[10] = p_CICS_CP->un_VOICE_WARNING_MESSAGE4.w_VOICE_WARNING_MESSAGE4;
    MSG_AIU_BC2RT[11] = p_CICS_CP->un_VOICE_WARNING_MESSAGE5.w_VOICE_WARNING_MESSAGE5;
    MSG_AIU_BC2RT[12] = p_CICS_CP->un_VOICE_WARNING_MESSAGE6.w_VOICE_WARNING_MESSAGE6;
    MSG_AIU_BC2RT[13] = p_CICS_CP->un_VOICE_WARNING_MESSAGE7.w_VOICE_WARNING_MESSAGE7;
    MSG_AIU_BC2RT[14] = p_CICS_CP->un_VOICE_WARNING_MESSAGE8.w_VOICE_WARNING_MESSAGE8;
    MSG_AIU_BC2RT[15] = p_CICS_CP->un_VOICE_WARNING_MESSAGE9.w_VOICE_WARNING_MESSAGE9;

    volt.Format(_T("28"));
    curr.Format(_T("10"));

    return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CITC_GUI_01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CITC_GUI_01Dlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 아이콘을 그립니다.
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CITC_GUI_01Dlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

// 컨트롤러에서 해당 개체 중 하나를 계속 사용하고 있을 경우
//  사용자가 UI를 닫을 때 자동화 서버를 종료하면 안 됩니다. 이들
//  메시지 처리기는 프록시가 아직 사용 중인 경우 UI는 숨기지만,
//  UI가 표시되지 않아도 대화 상자는
//  남겨 둡니다.

void CITC_GUI_01Dlg::OnClose()
{
    if (CanExit())
        aceBCStop(DevNum);
    aceFree(DevNum);
    closesocket(mh_socket);
    mh_socket = INVALID_SOCKET;

    CDialogEx::OnClose();
}

void CITC_GUI_01Dlg::OnOK()
{
    if (CanExit())
        aceBCStop(DevNum);
    aceFree(DevNum);
    closesocket(mh_socket);
    mh_socket = INVALID_SOCKET;

    CDialogEx::OnOK();
}

void CITC_GUI_01Dlg::OnCancel()
{
    if (CanExit())
        aceBCStop(DevNum);
    aceFree(DevNum);
    closesocket(mh_socket);
    mh_socket = INVALID_SOCKET;

    CDialogEx::OnCancel();
}

void CITC_GUI_01Dlg::OnDestroy()
{
    aceBCStop(DevNum);
    aceFree(DevNum);
    closesocket(mh_socket);
    mh_socket = INVALID_SOCKET;

    CDialogEx::OnDestroy();
    // TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

BOOL CITC_GUI_01Dlg::CanExit()
{
    // 프록시 개체가 계속 남아 있으면 자동화 컨트롤러에서는
    //  이 응용 프로그램을 계속 사용합니다. 대화 상자는 남겨 두지만
    //  해당 UI는 숨깁니다.
    if (m_pAutoProxy != NULL)
    {
        ShowWindow(SW_HIDE);
        return FALSE;
    }

    return TRUE;
}



void CITC_GUI_01Dlg::OnBnClickedMbtnExit()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    aceBCStop(DevNum);
    aceFree(DevNum);

    closesocket(mh_socket);
    closesocket(Client_socket);
    mh_socket = INVALID_SOCKET;
    Client_socket = INVALID_SOCKET;

    AfxGetMainWnd()->PostMessage(WM_COMMAND,ID_APP_EXIT);
    // CDialogEx::OnCancel();
}


HBRUSH CITC_GUI_01Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    UINT nID = pWnd -> GetDlgCtrlID();

    switch(nID)
    {
    case IDC_STATIC_ITC_STATE:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    case IDC_STATIC_ARC1_STATE:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    case IDC_STATIC_ARC2_STATE:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    case IDC_STATIC_ITC_STATE2:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    case IDC_STATIC_AIU_STATE:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    }

    return hbr;
}


void CITC_GUI_01Dlg::OnBnClickedMbtnConnect()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    if(m_connect_flag == 0)
        m_mbtn_connect.SetWindowTextW(L"연결 해제");
    else
        m_mbtn_connect.SetWindowTextW(L"연결");

    TCP_CONNECT();

}


void CITC_GUI_01Dlg::OnBnClickedMbtnSetEthernet()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    m_CSET_ETHERNET.m_str_setting_ip = m_str_ip;
    m_CSET_ETHERNET.m_str_setting_port = m_str_port;

    if( IDOK == m_CSET_ETHERNET.DoModal())
    {
        m_str_ip = m_CSET_ETHERNET.m_str_setting_ip;
        m_str_port = m_CSET_ETHERNET.m_str_setting_port;
    }
}


void CITC_GUI_01Dlg::TCP_CONNECT(void)
{
    if(m_connect_flag)  // 접속 시도 중이거나 접속 중이라면 접속을 해제하는 if구문
    {
        m_connect_flag = 2;
        ChangeIcon( &m_icon_ethernet, m_connect_flag );

        prev_MIC1_Path = 100;
        prev_MIC2_Path = 100;
        prev_TONE1_Path = 100;
        prev_TONE2_Path = 100;
        prev_SPK1_Path = 100;
        prev_SPK2_Path = 100;
        prev_ARC1_Path = 100;
        prev_ARC2_Path = 100;

        AddEventString(_T("> 서버에 접속을 종료합니다.\r\n"));
        m_mbtn_connect.SetWindowTextW(L"연결");

        closesocket(mh_socket);
        mh_socket = INVALID_SOCKET;

        m_connect_flag = 0;
        return;
    }

    U16BIT m_us_Port = _ttoi(m_str_port);   // m_str_port(문자열)를 unsigned short로 변환 후 m_us_Port에 저장

    mh_socket = socket( AF_INET, SOCK_STREAM, 0 );  //소켓 생성

    memset( &srv_addr, 0, sizeof( struct sockaddr_in ) );
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = inet_addr( (CStringA)m_str_ip );
    srv_addr.sin_port = htons( m_us_Port );

    // mh_socket 소켓에 FD_CONNECT라는 이벤트가 발생하면 m_hWnd 다이얼로그에 25001 메시지 실행 요청
    WSAAsyncSelect( mh_socket, m_hWnd, 25001, FD_CONNECT );

    m_connect_flag = 2;
    ChangeIcon( &m_icon_ethernet, m_connect_flag );

    AddEventString(_T("> 서버에 접속을 시도합니다.\r\n"));
    m_EditLog.ReplaceSel(str_log);

    connect(mh_socket, (LPSOCKADDR)&srv_addr, sizeof(srv_addr));

    // DisplayIpPort();
}


afx_msg LRESULT CITC_GUI_01Dlg::On25001(WPARAM wParam, LPARAM lParam)
{
    if (WSAGETSELECTERROR(lParam))  // if문에 들어오면 접속 실패
    {
        m_connect_flag = 0;
        ChangeIcon( &m_icon_ethernet, m_connect_flag );
        closesocket(mh_socket);
        mh_socket = INVALID_SOCKET;

        AfxMessageBox(_T("> 서버 접속 실패.\r\n"));
        m_mbtn_connect.SetWindowTextW(L"연결");


    }
    else   // 접속 성공
    {
        m_connect_flag = 1;
        ChangeIcon( &m_icon_ethernet, m_connect_flag );
        WSAAsyncSelect(mh_socket, m_hWnd, 25002, FD_READ | FD_CLOSE);

        AddEventString(_T("> 서버에 접속했습니다.\r\n"));
        CString str;
        str.Format(L"> IP : %s      포트 : %s\r\n", m_str_ip, m_str_port);
        int n_Length = m_EditLog.GetWindowTextLengthW();
        m_EditLog.SetSel(n_Length, n_Length);
        m_EditLog.ReplaceSel(str);
    }

    return 0;
}


afx_msg LRESULT CITC_GUI_01Dlg::On25002(WPARAM wParam, LPARAM lParam)
{
    CString str;
    int n_Length = 0;

    if (WSAGETSELECTEVENT(lParam) == FD_READ)
    {
        WSAAsyncSelect(wParam, m_hWnd, 25002, FD_CLOSE);

        recv(wParam, (char*)RecvMsg, BUFSIZE, 0);

        if((RecvMsg[0] == 0xD3) && (RecvMsg[6] == 0x7F))
        {
            str.Format(L"> 수신 : %02X %02X %02X %02X %02X% 02X %02X\r\n"
                , RecvMsg[0], RecvMsg[1], RecvMsg[2], RecvMsg[3], RecvMsg[4], RecvMsg[5], RecvMsg[6]);
            n_Length = m_EditLog.GetWindowTextLengthW();
            m_EditLog.SetSel(n_Length, n_Length);
            m_EditLog.ReplaceSel(str);

            WORD m_OP = MAKEWORD(RecvMsg[5], RecvMsg[4]);

            switch(m_OP)
            {
            case 0x1101:
            case 0x1102:
            case 0x2201:
            case 0x2202:
            case 0x3301:
            case 0x3302:
            case 0x4401:
            case 0x4402:
            case 0x4403:
            case 0x4404:
            case 0x5501:
            case 0x5502:
            case 0x6601:
            case 0x6602:
            case 0x7701:
            case 0x7702:
                KillTimer(m_OP);
                f_ACK = FALSE;
                break;
            }
        }
        else
        {
            //str.Format(L"> 수신 : %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n"
            //    , RecvMsg[4], RecvMsg[5], RecvMsg[6], RecvMsg[7], RecvMsg[8], RecvMsg[9], RecvMsg[10], RecvMsg[11], RecvMsg[12], RecvMsg[13], RecvMsg[14], RecvMsg[15], RecvMsg[16]);
            //n_Length = m_EditLog.GetWindowTextLengthW();
            //m_EditLog.SetSel(n_Length, n_Length);
            //m_EditLog.ReplaceSel(str);

            //str.Format(L"> 수신 : %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n"
            //    , RecvMsg[17], RecvMsg[18], RecvMsg[19], RecvMsg[20], RecvMsg[21], RecvMsg[22], RecvMsg[23], RecvMsg[24], RecvMsg[25], RecvMsg[26], RecvMsg[27], RecvMsg[28], RecvMsg[29]);
            //n_Length = m_EditLog.GetWindowTextLengthW();
            //m_EditLog.SetSel(n_Length, n_Length);
            //m_EditLog.ReplaceSel(str);

            if(f_SET_DIS)
                p_CICS_CP->PostMessageW(UWM_DP_ICS_DIS, NULL, NULL);
            if(f_ARC1_Dlg)
                p_CSET_ARC1->PostMessageW(UWM_DP_ICS_DIS, NULL, NULL);
            if(f_ARC2_Dlg)
                p_CSET_ARC2->PostMessageW(UWM_DP_ICS_DIS, NULL, NULL);
            //::SendMessage(m_CICS_CP.m_hWnd, UWM_DP_ICS_DIS, NULL, NULL);
            //::SendMessage(m_CSET_ARC1.m_hWnd, UWM_DP_ICS_DIS, NULL, NULL);
            //::SendMessage(m_CSET_ARC2.m_hWnd, UWM_DP_ICS_DIS, NULL, NULL);
        }
    }
    else
    {//FD_CLOSE
        closesocket(mh_socket);//클라이언트 소켓 클로즈

        mh_socket = INVALID_SOCKET;
        m_connect_flag = 0;//연결 해제 flag 변경

        ChangeIcon( &m_icon_ethernet, m_connect_flag );

        prev_MIC1_Path = 100;
        prev_MIC2_Path = 100;
        prev_TONE1_Path = 100;
        prev_TONE2_Path = 100;
        prev_SPK1_Path = 100;
        prev_SPK2_Path = 100;
        prev_ARC1_Path = 100;
        prev_ARC2_Path = 100;

        AddEventString(_T("> 서버가 연결을 해제 했습니다.\r\n"));
        m_mbtn_connect.SetWindowTextW(L"연결");
    }

    WSAAsyncSelect(wParam, m_hWnd, 25002, FD_READ | FD_CLOSE);

    // memset(RecvMsg, 0, BUFSIZE);

    return 0;
}


void CITC_GUI_01Dlg::OnBnClickedMbtnSetArc1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_CSET_ARC1 = new CSET_ARC1;
    f_ARC1_Dlg = p_CSET_ARC1->Create(IDD_SET_ARC1);
    p_CSET_ARC1->ShowWindow(SW_SHOW);

    //if( IDOK == m_CSET_ARC1.DoModal())
    //{
    //}
}


void CITC_GUI_01Dlg::OnBnClickedMbtnSetArc2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_CSET_ARC2 = new CSET_ARC2;
    f_ARC2_Dlg = p_CSET_ARC2->Create(IDD_SET_ARC2);
    p_CSET_ARC2->ShowWindow(SW_SHOW);

    //if( IDOK == m_CSET_ARC2.DoModal())
    //{
    //}
}


void CITC_GUI_01Dlg::SetComboAOUT(CComboBox* pCombo, UINT8 CurrentState)
{
    switch(CurrentState)
    {
    case 0:
        pCombo->AddString(_T("None"));
        pCombo->AddString(_T("AIU COM1 AIN"));
        pCombo->AddString(_T("AIU COM2 AIN"));
        pCombo->AddString(_T("AIU COM3 AIN"));
        pCombo->AddString(_T("AIU COM4 AIN"));
        pCombo->AddString(_T("AIU COM5 AIN"));
        pCombo->AddString(_T("AIU COM2 RCV WB"));
        pCombo->AddString(_T("AIU COM3 RCV WB"));
        pCombo->AddString(_T("AIU COM2 RCV SEC GD"));
        pCombo->AddString(_T("AIU COM3 RCV SEC GD"));
        pCombo->AddString(_T("---------------------------------"));
        pCombo->AddString(_T("AIU VOR/ILS AUD"));
        pCombo->AddString(_T("AIU MB AUD"));
        pCombo->AddString(_T("AIU MISSION AUD 1"));
        pCombo->AddString(_T("AIU MISSION AUD 2"));
        pCombo->AddString(_T("COMSEC RED RCV"));
        pCombo->AddString(_T("COMSEC BLK XMT WB"));
        pCombo->AddString(_T("COMSEC BLK XMT"));
        pCombo->AddString(_T("SPARE IN 1"));
        pCombo->AddString(_T("SPARE IN 2"));
        break;

    case 1:
        pCombo->AddString(_T("None"));
        pCombo->AddString(_T("AIU COM1 AOUT"));
        pCombo->AddString(_T("AIU COM2 AOUT"));
        pCombo->AddString(_T("AIU COM3 AOUT"));
        pCombo->AddString(_T("AIU COM4 AOUT"));
        pCombo->AddString(_T("AIU COM5 AOUT"));
        pCombo->AddString(_T("AIU COM2 XMT WB"));
        pCombo->AddString(_T("AIU COM3 XMT WB"));
        pCombo->AddString(_T("SPARE OUT 1"));
        pCombo->AddString(_T("SPARE OUT 2"));
        pCombo->AddString(_T("---------------------------------"));
        pCombo->AddString(_T("AIU DTS AUD1"));
        pCombo->AddString(_T("AIU DTS AUD2"));
        pCombo->AddString(_T("AIU FDR AUD"));
        pCombo->AddString(_T("COMSEC RED XMT"));
        pCombo->AddString(_T("COMSEC BLK RCV WB"));
        pCombo->AddString(_T("COMSEC BLK RCV"));
        pCombo->AddString(_T("COMSEC RCV SEC GD"));
        pCombo->AddString(_T("---------------------------------"));
        pCombo->AddString(_T("ARC232 RCVR AUDIO A"));
        pCombo->AddString(_T("ARC232 RCVR AUDIO B"));
        break;

    case 2:
        pCombo->AddString(_T("Type 1"));
        pCombo->AddString(_T("Type 2"));
        pCombo->AddString(_T("Type 3"));
        break;

    case 3:
        pCombo->AddString(_T("None"));
        pCombo->AddString(_T("AIU COM1"));
        pCombo->AddString(_T("AIU COM2"));
        pCombo->AddString(_T("AIU COM3"));
        pCombo->AddString(_T("AIU COM4"));
        pCombo->AddString(_T("AIU COM5"));
        break;

    case 4:
        pCombo->AddString(_T("None"));
        pCombo->AddString(_T("AIU COM1 AIN"));
        pCombo->AddString(_T("AIU COM2 AIN"));
        pCombo->AddString(_T("AIU COM3 AIN"));
        pCombo->AddString(_T("AIU COM4 AIN"));
        pCombo->AddString(_T("AIU COM5 AIN"));
        pCombo->AddString(_T("AIU COM2 RCV WB"));
        pCombo->AddString(_T("AIU COM3 RCV WB"));
        pCombo->AddString(_T("AIU COM2 RCV SEC GD"));
        pCombo->AddString(_T("AIU COM3 RCV SEC GD"));
        pCombo->AddString(_T("---------------------------------"));
        pCombo->AddString(_T("AIU VOR/ILS AUD"));
        pCombo->AddString(_T("AIU MB AUD"));
        pCombo->AddString(_T("AIU MISSION AUD 1"));
        pCombo->AddString(_T("AIU MISSION AUD 2"));
        pCombo->AddString(_T("COMSEC RED RCV"));
        pCombo->AddString(_T("COMSEC BLK XMT WB"));
        pCombo->AddString(_T("COMSEC BLK XMT"));
        pCombo->AddString(_T("SPARE IN 1"));
        pCombo->AddString(_T("SPARE IN 2"));
        pCombo->AddString(_T("---------------------------------"));
        pCombo->AddString(_T("ARC232 XMIT AUDIO A"));
        pCombo->AddString(_T("ARC232 XMIT AUDIO B"));
        break;
    }
}


void CITC_GUI_01Dlg::OnCbnSelchangeComboMic1()
{
    if(10 == m_combo_MIC1.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_MIC1.ResetContent();
        SetComboAOUT(&m_combo_MIC1, 4);
    }
    else if(20 == m_combo_MIC1.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_MIC1.ResetContent();
        SetComboAOUT(&m_combo_MIC1, 4);
    }
}


void CITC_GUI_01Dlg::OnCbnSelchangeComboMic2()
{
    if(10 == m_combo_MIC2.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_MIC2.ResetContent();
        SetComboAOUT(&m_combo_MIC2, 4);
    }
    else if(20 == m_combo_MIC2.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_MIC2.ResetContent();
        SetComboAOUT(&m_combo_MIC2, 4);
    }
}


void CITC_GUI_01Dlg::OnCbnSelchangeComboTone1()
{
    if(10 == m_combo_Tone1.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_Tone1.ResetContent();
        SetComboAOUT(&m_combo_Tone1, 0);
    }
}


void CITC_GUI_01Dlg::OnCbnSelchangeComboTone2()
{
    if(10 == m_combo_Tone2.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_Tone2.ResetContent();
        SetComboAOUT(&m_combo_Tone2, 0);
    }
}


void CITC_GUI_01Dlg::OnCbnSelchangeComboSpk1()
{
    if(10 == m_combo_SPK1.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_SPK1.ResetContent();
        SetComboAOUT(&m_combo_SPK1, 1);
    }
    else if(18 == m_combo_SPK1.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_SPK1.ResetContent();
        SetComboAOUT(&m_combo_SPK1, 1);
    }
}


void CITC_GUI_01Dlg::OnCbnSelchangeComboSpk2()
{
    if(10 == m_combo_SPK2.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_SPK2.ResetContent();
        SetComboAOUT(&m_combo_SPK2, 0);
    }
    else if(10 == m_combo_SPK2.GetCurSel())
    {
        AddEventString(_T("> 올바른 선택이 아닙니다.\r\n"));
        m_combo_SPK2.ResetContent();
        SetComboAOUT(&m_combo_SPK2, 0);
    }
}



void CITC_GUI_01Dlg::ChangeIcon(CStatic* m_Icon, U8BIT flag)
{
    HICON h_Icon;   // 아이콘 객체 생성

    if(flag == 1)   // 연결 상태 → 초록불
        h_Icon = ::LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE( IDI_ICON12 ));

    else if(flag == 2)  // 연결 중  → 회색불
        h_Icon = ::LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE( IDI_ICON10 ));

    else    // 미연결 상태 → 빨간불
        h_Icon = ::LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE( IDI_ICON11 ));

    m_Icon->SetIcon(h_Icon);
}


void CITC_GUI_01Dlg::AddEventString(wchar_t* ap_string)
{
    //while(m_EditLog.GetCount() > 500) // 500줄 이상이면
    //{
    //    m_list_log.DeleteString(0);   // 첫 번째 줄을 삭제

    //}
    int len = m_EditLog.GetWindowTextLengthW();
    m_EditLog.SetSel(-2, -1);
    m_EditLog.ReplaceSel((LPCTSTR)ap_string);
}


void CITC_GUI_01Dlg::OnBnClickedBtnMwodStatus1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_ARC1_CMWOD_LOAD_STATUS = new CMWOD_LOAD_STATUS;
    p_ARC1_CMWOD_LOAD_STATUS->Create(IDD_MWOD_LOAD_STATUS);
    p_ARC1_CMWOD_LOAD_STATUS->ShowWindow(SW_SHOW);

    //if( IDOK == m_CMWOD_LOAD_STATUS.DoModal())
    //{
    //}
}


void CITC_GUI_01Dlg::OnBnClickedBtnPresetStatus1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_ARC1_CPRESET_STATUS = new CPRESET_STATUS;
    p_ARC1_CPRESET_STATUS->Create(IDD_PRESET_STATUS);
    p_ARC1_CPRESET_STATUS->ShowWindow(SW_SHOW);

    //if( IDOK == m_CPRESET_STATUS.DoModal())
    //{
    //}
}


void CITC_GUI_01Dlg::OnBnClickedBtnBitSummary1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_ARC1_CBIT_SUMMARY = new CBIT_SUMMARY;
    p_ARC1_CBIT_SUMMARY->Create(IDD_BIT_SUMMARY);
    p_ARC1_CBIT_SUMMARY->ShowWindow(SW_SHOW);

    //if( IDOK == m_CBIT_SUMMARY.DoModal())
    //{
    //}
}


void CITC_GUI_01Dlg::OnBnClickedBtnMwodStatus2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_ARC2_CMWOD_LOAD_STATUS = new CMWOD_LOAD_STATUS2;
    p_ARC2_CMWOD_LOAD_STATUS->Create(IDD_MWOD_LOAD_STATUS2);
    p_ARC2_CMWOD_LOAD_STATUS->ShowWindow(SW_SHOW);
}


void CITC_GUI_01Dlg::OnBnClickedBtnPresetStatus2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_ARC2_CPRESET_STATUS = new CPRESET_STATUS2;
    p_ARC2_CPRESET_STATUS->Create(IDD_PRESET_STATUS2);
    p_ARC2_CPRESET_STATUS->ShowWindow(SW_SHOW);
    //if( IDOK == m_CPRESET_STATUS.DoModal())
    //{
    //}
}


void CITC_GUI_01Dlg::OnBnClickedBtnBitSummary2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_ARC2_CBIT_SUMMARY = new CBIT_SUMMARY2;
    p_ARC2_CBIT_SUMMARY->Create(IDD_BIT_SUMMARY2);
    p_ARC2_CBIT_SUMMARY->ShowWindow(SW_SHOW);
    //if( IDOK == m_CBIT_SUMMARY.DoModal())
    //{
    //}
}


void CITC_GUI_01Dlg::OnBnClickedMbtnSetIcs()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_CICS_CP = new CICS_CP;
    f_ICS_SET = p_CICS_CP->Create(IDD_ICS_CP);
    p_CICS_CP->ShowWindow(SW_SHOW);
}


void CITC_GUI_01Dlg::OnBnClickedBtnFaultData()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    p_CFAULT_DATA = new CFAULT_DATA;
    p_CFAULT_DATA->Create(IDD_FAULT_DATA);
    p_CFAULT_DATA->ShowWindow(SW_SHOW);
}


void CITC_GUI_01Dlg::OnBnClickedBtnMic1()
{
    if(CheckTestFlag())
    {
        return;
    }

    MIC1_Index = m_combo_MIC1.GetCurSel();

    if(CheckConnect() == (-1))
    {
        return;
    }

    CheckPath(MIC1_Index);

    if((1 <= MIC1_Index) && (MIC1_Index <= 9))
    {
        if(MIC2_Left_Flag)
            AfxMessageBox(L"> 좌측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 좌측 채널을 선택하였습니다.\r\n"));
            Clssfctn(MIC1_Index, &m_slider_mic1, MIC1, 1);
            MIC1_XAudio_A_Flag = FALSE;
            MIC1_XAudio_B_Flag = FALSE;
            MIC1_Right_Flag = FALSE;
            MIC1_Left_Flag = TRUE;
        }
    }
    else if((11 <= MIC1_Index) && (MIC1_Index <= 19))
    {
        if(MIC2_Right_Flag)
            AfxMessageBox(L"> 우측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 우측 채널을 선택하였습니다.\r\n"));
            Clssfctn(MIC1_Index, &m_slider_mic1, MIC1, 1);
            MIC1_XAudio_A_Flag = FALSE;
            MIC1_XAudio_B_Flag = FALSE;
            MIC1_Left_Flag = FALSE;
            MIC1_Right_Flag = TRUE;
        }
    }
    else if(MIC1_Index == 21)
    {
        if(MIC2_XAudio_A_Flag)
            AfxMessageBox(L"> XAudio A는 이미 사용 중입니다.\r\n");
        else
        {
            Clssfctn(MIC1_Index, &m_slider_mic1, MIC1, 1);
            MIC1_Left_Flag = FALSE;
            MIC1_Right_Flag = FALSE;
            MIC1_XAudio_A_Flag = TRUE;
            MIC1_XAudio_B_Flag = FALSE;
        }
    }
    else if(MIC1_Index == 22)
    {
        if(MIC2_XAudio_B_Flag)
            AfxMessageBox(L"> XAudio B는 이미 사용 중입니다.\r\n");
        else
        {
            MIC1_Left_Flag = FALSE;
            MIC1_Right_Flag = FALSE;
            MIC1_XAudio_A_Flag = FALSE;
            MIC1_XAudio_B_Flag = TRUE;
            Clssfctn(MIC1_Index, &m_slider_mic1, MIC1, 1);
        }
    }
    else if(MIC1_Index == 0)
    {
        AddEventString(_T("> None을 선택하였습니다.\r\n"));
        Clssfctn(MIC1_Index, &m_slider_mic1, MIC1, 1);
        MIC1_Left_Flag = FALSE;
        MIC1_Right_Flag = FALSE;
        MIC1_XAudio_A_Flag = FALSE;
        MIC1_XAudio_B_Flag = FALSE;
    }
}


void CITC_GUI_01Dlg::OnBnClickedBtnMic2()
{
    if(CheckTestFlag())
    {
        return;
    }

    MIC2_Index = m_combo_MIC2.GetCurSel();  // 현재 선택된 콤보박스 인덱스 저장

    if(CheckConnect() == (-1))
    {
        return;
    }

    CheckPath(MIC2_Index);

    if((1 <= MIC2_Index) && (MIC2_Index <= 9))
    {
        if(MIC1_Left_Flag)
            AfxMessageBox(L"> 좌측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 좌측 채널을 선택하였습니다.\r\n"));
            Clssfctn(MIC2_Index, &m_slider_mic2, MIC2, 1);
            MIC2_XAudio_A_Flag = FALSE;
            MIC2_XAudio_B_Flag = FALSE;
            MIC2_Right_Flag = FALSE;
            MIC2_Left_Flag = TRUE;
        }
    }
    else if((11 <= MIC2_Index) && (MIC2_Index <= 19))
    {
        if(MIC1_Right_Flag)
            AfxMessageBox(L"> 우측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 우측 채널을 선택하였습니다.\r\n"));
            Clssfctn(MIC2_Index, &m_slider_mic2, MIC2, 1);
            MIC2_XAudio_A_Flag = FALSE;
            MIC2_XAudio_B_Flag = FALSE;
            MIC2_Left_Flag = FALSE;
            MIC2_Right_Flag = TRUE;
        }
    }
    else if(MIC2_Index == 21)
    {
        if(MIC1_XAudio_A_Flag)
            AfxMessageBox(L"> XAudio A는 이미 사용 중입니다.\r\n");
        else
        {
            MIC2_Left_Flag = FALSE;
            MIC2_Right_Flag = FALSE;
            MIC2_XAudio_A_Flag = TRUE;
            MIC2_XAudio_B_Flag = FALSE;
            Clssfctn(MIC2_Index, &m_slider_mic2, MIC2, 1);
        }
    }
    else if(MIC2_Index == 22)
    {
        if(MIC1_XAudio_B_Flag)
            AfxMessageBox(L"> XAudio B는 이미 사용 중입니다.\r\n");
        else
        {
            MIC2_Left_Flag = FALSE;
            MIC2_Right_Flag = FALSE;
            MIC2_XAudio_A_Flag = FALSE;
            MIC2_XAudio_B_Flag = TRUE;
            Clssfctn(MIC2_Index, &m_slider_mic2, MIC2, 1);
        }
    }
    else if(MIC2_Index == 0)
    {
        AddEventString(_T("> None을 선택하였습니다.\r\n"));
        Clssfctn(MIC2_Index, &m_slider_mic2, MIC2, 1);
        MIC2_Left_Flag = FALSE;
        MIC2_Right_Flag = FALSE;
        MIC2_XAudio_A_Flag = FALSE;
        MIC2_XAudio_B_Flag = FALSE;
    }
}


void CITC_GUI_01Dlg::OnBnClickedBtnTone1()
{
    if(CheckTestFlag())
    {
        return;
    }

    TONE1_Index = m_combo_Tone1.GetCurSel();  // 현재 선택된 콤보박스 인덱스 저장
    UINT8 m_Tone_Type1 = m_combo_Tone_Type1.GetCurSel();

    if(CheckConnect() == (-1))
    {
        return;
    }
    CheckPath(TONE1_Index);

    if(m_Tone_Type1 == 0xFF)
    {
        AddEventString(_T("> Tone Type을 선택해주세요.\r\n"));
        return;
    }

    if((1 <= TONE1_Index) && (TONE1_Index <= 9))
    {
        if(TONE2_Left_Flag)
            AfxMessageBox(L"> 좌측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 좌측 채널을 선택하였습니다.\r\n"));
            Clssfctn2(TONE1_Index, &m_slider_tone1, m_Tone_Type1, TONE1, 0x01);

            // prev_TONE1_Path = TONE1_Index;
            TONE1_Right_Flag = FALSE;
            TONE1_Left_Flag = TRUE;
        }
    }
    else if((11 <= TONE1_Index) && (TONE1_Index <= 19))
    {
        if(TONE2_Right_Flag)
            AfxMessageBox(L"> 우측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 우측 채널을 선택하였습니다.\r\n"));
            // prev_TONE1_Path = TONE1_Index;
            Clssfctn2(TONE1_Index, &m_slider_tone1, m_Tone_Type1, TONE1, 0x01);

            TONE1_Left_Flag = FALSE;
            TONE1_Right_Flag = TRUE;
        }
    }
    else if(TONE1_Index == 0)
    {
        AddEventString(_T("> None을 선택하였습니다.\r\n"));
        // prev_TONE1_Path = TONE1_Index;
        Clssfctn2(TONE1_Index, &m_slider_tone1, m_Tone_Type1, TONE1, 0x01);

        TONE1_Left_Flag = FALSE;
        TONE1_Right_Flag = FALSE;


    }
}


void CITC_GUI_01Dlg::OnBnClickedBtnTone2()
{
    if(CheckTestFlag())
    {
        return;
    }

    TONE2_Index = m_combo_Tone2.GetCurSel();  // 현재 선택된 콤보박스 인덱스 저장
    UINT8 m_Tone_Type2 = m_combo_Tone_Type2.GetCurSel();

    if(CheckConnect() == (-1))
    {
        return;
    }
    CheckPath(TONE2_Index);

    if(m_Tone_Type2 == 0xFF)
    {
        AddEventString(_T("> Tone Type을 선택해주세요.\r\n"));
        return;
    }

    if((1 <= TONE2_Index) && (TONE2_Index <= 9))
    {
        if(TONE1_Left_Flag)
            AfxMessageBox(L"> 좌측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 좌측 채널을 선택하였습니다.\r\n"));
            // prev_TONE2_Path = TONE2_Index;
            Clssfctn2(TONE2_Index, &m_slider_tone2, m_Tone_Type2, TONE2, 0x02);

            TONE2_Right_Flag = FALSE;
            TONE2_Left_Flag = TRUE;
        }
    }
    else if((11 <= TONE2_Index) && (TONE2_Index <= 19))
    {
        if(TONE1_Right_Flag)
            AfxMessageBox(L"> 우측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 우측 채널을 선택하였습니다.\r\n"));
            // prev_TONE2_Path = TONE2_Index;
            Clssfctn2(TONE2_Index, &m_slider_tone2, m_Tone_Type2, TONE2, 0x02);

            TONE2_Left_Flag = FALSE;
            TONE2_Right_Flag = TRUE;
        }
    }
    else if(TONE2_Index == 0)
    {
        AddEventString(_T("> None을 선택하였습니다.\r\n"));
        Clssfctn2(TONE2_Index, &m_slider_tone2, m_Tone_Type2, TONE2, 0x02);

        // prev_TONE2_Path = TONE2_Index;
        TONE2_Left_Flag = FALSE;
        TONE2_Right_Flag = FALSE;
    }
}


void CITC_GUI_01Dlg::OnBnClickedBtnSpk1()
{
    if(CheckTestFlag())
    {
        return;
    }

    SPK1_Index = m_combo_SPK1.GetCurSel();  // 현재 선택된 콤보박스 인덱스 저장

    if(CheckConnect() == (-1))
    {
        return;
    }
    CheckPath(SPK1_Index);


    if((1 <= SPK1_Index) && (SPK1_Index <= 9))
    {
        if(SPK2_Left_Flag)
            AfxMessageBox(L"> 좌측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 좌측 채널을 선택하였습니다.\r\n"));
            Clssfctn(SPK1_Index, &m_slider_spk1, SPK1, 2);
            SPK1_Right_Flag = FALSE;
            SPK1_Left_Flag = TRUE;
            SPK1_RAudio_A_Flag = FALSE;
            SPK1_RAudio_B_Flag = FALSE;
        }
    }
    else if((11 <= SPK1_Index) && (SPK1_Index <= 17))
    {
        if(SPK2_Right_Flag)
            AfxMessageBox(L"> 우측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 우측 채널을 선택하였습니다.\r\n"));
            Clssfctn(SPK1_Index, &m_slider_spk1, SPK1, 2);
            SPK1_Left_Flag = FALSE;
            SPK1_Right_Flag = TRUE;
            SPK1_RAudio_A_Flag = FALSE;
            SPK1_RAudio_B_Flag = FALSE;
        }
    }
    else if(19 == SPK1_Index)
    {
        if(SPK2_RAudio_A_Flag)
            AfxMessageBox(L"> Audio A는 이미 사용 중입니다.\r\n");
        else
        {
            Clssfctn(SPK1_Index, &m_slider_spk1, SPK1, 2);
            SPK1_Left_Flag = FALSE;
            SPK1_Right_Flag = FALSE;
            SPK1_RAudio_A_Flag = TRUE;
            SPK1_RAudio_B_Flag = FALSE;
        }
    }
    else if(20 == SPK1_Index)
    {
        if(SPK2_RAudio_B_Flag)
            AfxMessageBox(L"> Audio B는 이미 사용 중입니다.\r\n");
        else
        {
            Clssfctn(SPK1_Index, &m_slider_spk1, SPK1, 2);
            SPK1_Left_Flag = FALSE;
            SPK1_Right_Flag = FALSE;
            SPK1_RAudio_A_Flag = FALSE;
            SPK1_RAudio_B_Flag = TRUE;
        }
    }
    else if(SPK1_Index == 0)
    {
        AddEventString(_T("> None을 선택하였습니다.\r\n"));
        Clssfctn(SPK1_Index, &m_slider_spk1, SPK1, 2);
        SPK1_Left_Flag = FALSE;
        SPK1_Right_Flag = FALSE;
        SPK1_RAudio_A_Flag = FALSE;
        SPK1_RAudio_B_Flag = FALSE;

    }
}

void CITC_GUI_01Dlg::OnBnClickedBtnSpk2()
{
    if(CheckTestFlag())
    {
        return;
    }

    SPK2_Index = m_combo_SPK2.GetCurSel();  // 현재 선택된 콤보박스 인덱스 저장

    if(CheckConnect() == (-1))
    {
        return;
    }
    CheckPath(SPK2_Index);


    if((1 <= SPK2_Index) && (SPK2_Index <= 9))
    {
        if(SPK1_Left_Flag)
            AfxMessageBox(L"> 좌측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 좌측 채널을 선택하였습니다.\r\n"));
            Clssfctn(SPK2_Index, &m_slider_spk2, SPK2, 2);
            SPK2_Right_Flag = FALSE;
            SPK2_Left_Flag = TRUE;
            //RAudio_A_Flag = FALSE;
            //RAudio_B_Flag = FALSE;
        }
    }
    else if((11 <= SPK2_Index) && (SPK2_Index <= 17))
    {
        if(SPK1_Right_Flag)
            AfxMessageBox(L"> 우측 채널은 이미 사용 중입니다.\r\n");
        else
        {
            AddEventString(_T("> 우측 채널을 선택하였습니다.\r\n"));
            Clssfctn(SPK2_Index, &m_slider_spk2, SPK2, 2);
            SPK2_Left_Flag = FALSE;
            SPK2_Right_Flag = TRUE;
            SPK2_RAudio_A_Flag = FALSE;
            SPK2_RAudio_B_Flag = FALSE;
        }
    }
    else if(19 == SPK2_Index)
    {
        if(SPK1_RAudio_A_Flag)
            AfxMessageBox(L"> Audio A는 이미 사용 중입니다.\r\n");
        else
        {
            Clssfctn(SPK2_Index, &m_slider_spk2, SPK2, 2);
            SPK2_Left_Flag = FALSE;
            SPK2_Right_Flag = FALSE;
            SPK2_RAudio_A_Flag = TRUE;
            SPK2_RAudio_B_Flag = FALSE;
        }
    }
    else if(20 == SPK2_Index)
    {
        if(SPK1_RAudio_B_Flag)
            AfxMessageBox(L"> Audio B는 이미 사용 중입니다.\r\n");
        else
        {
            Clssfctn(SPK2_Index, &m_slider_spk2, SPK2, 2);
            SPK2_Left_Flag = FALSE;
            SPK2_Right_Flag = FALSE;
            SPK2_RAudio_A_Flag = FALSE;;
            SPK2_RAudio_B_Flag = TRUE;
        }
    }
    else if(SPK2_Index == 0)
    {
        AddEventString(_T("> None을 선택하였습니다.\r\n"));
        Clssfctn(SPK2_Index, &m_slider_spk2, SPK2, 2);
        SPK2_Left_Flag = FALSE;
        SPK2_Right_Flag = FALSE;
        SPK2_RAudio_A_Flag = FALSE;
        SPK2_RAudio_B_Flag = FALSE;
    }
}

void CITC_GUI_01Dlg::OnBnClickedBtnArc1()
{
    int Len_ARC1_SentMsg = 0;

    if(CheckTestFlag())
    {
        return;
    }

    if(CheckConnect() == (-1))
    {
        return;
    }

    ARC1_Index = m_combo_ARC1.GetCurSel();  // 현재 선택된 콤보박스 인덱스 저장
    CheckPath(ARC1_Index);

    if((1 <= ARC1_Index) && (ARC1_Index <= 5))
    {
        if(b_ARC2_flag)
        {
            AfxMessageBox(_T("> 사용 불가.\r\n"));
        }
        else
        {
            if(prev_ARC1_Path != 0x64)
            {
                if(prev_ARC1_Path != 0)
                {
                    if((b_PrevCOM2XMode == TRUE) | (b_PrevCOM3XMode == TRUE))
                    {
                        b_PrevCOM2XMode = FALSE;
                        b_PrevCOM3XMode = FALSE;

                        ARC1_SentMsg[11] = 0x00;
                        ARC1_SentMsg2[11] = 0x00;

                        Len_ARC1_SentMsg = 13;
                    }
                    else
                    {
                        ARC1_SentMsg[14] = 0x00;
                        ARC1_SentMsg2[14] = 0x00;

                        Len_ARC1_SentMsg = 16;
                    }
                    send(mh_socket, ARC1_SentMsg, Len_ARC1_SentMsg, 0); 
                    SetTimer(ARC1, 300, NULL);
                    f_ACK = TRUE;
                    Sleep(299);

                    send(mh_socket, ARC1_SentMsg2, Len_ARC1_SentMsg, 0); 
                    SetTimer(ARC1, 300, NULL);
                    f_ACK = TRUE;
                    Sleep(299);

                    SendARCState(0x0344, prev_ARC1_Path, 0);
                    SetTimer(ARC1, 300, NULL);
                    f_ACK = TRUE;
                    Sleep(299);
                    //memset(ARC1_SentMsg, 0, BUFSIZE);
                    //memset(ARC1_SentMsg2, 0, BUFSIZE);
                }
            }
            Clssfctn(ARC1_Index, &m_slider_arc1, ARC1, 1);
            memcpy(ARC1_SentMsg, &SendMsg, sizeof(SendMsg));
            Sleep(299);

            Clssfctn(ARC1_Index, &m_slider_arc1, ARC1, 2);
            memcpy(ARC1_SentMsg2, &SendMsg, sizeof(SendMsg));
            Sleep(299);

            SendARCState(0x0344, ARC1_Index, 1);
            SetTimer(ARC1, 30, NULL);
            f_ACK = TRUE;
            Sleep(299);

            prev_ARC1_Path = ARC1_Index;

            b_ARC1_flag = TRUE;
        }

    }
    else if(ARC1_Index == 0 && (prev_ARC1_Path != 0))
    {
        AddEventString(_T("> None을 선택하였습니다.\r\n"));
        if(prev_ARC1_Path != 0x64)
        {
            if((b_PrevCOM2XMode == TRUE) | (b_PrevCOM3XMode == TRUE))
            {
                b_PrevCOM2XMode = FALSE;
                b_PrevCOM3XMode = FALSE;

                ARC1_SentMsg[11] = 0x00;
                ARC1_SentMsg2[11] = 0x00;

                Len_ARC1_SentMsg = 13;
            }
            else
            {
                ARC1_SentMsg[14] = 0x00;
                ARC1_SentMsg2[14] = 0x00;

                Len_ARC1_SentMsg = 16;
            }

            ARC1_SentMsg[14] = 0x00;
            send(mh_socket, ARC1_SentMsg, Len_ARC1_SentMsg, 0); 
            SetTimer(ARC1, 300, NULL);
            f_ACK = TRUE;
            Sleep(299);

            ARC1_SentMsg2[14] = 0x00;
            send(mh_socket, ARC1_SentMsg2, Len_ARC1_SentMsg, 0); 
            SetTimer(ARC1, 300, NULL);
            f_ACK = TRUE;
            Sleep(299);

            SendARCState(0x0344, prev_ARC1_Path, 0);
            SetTimer(ARC1, 300, NULL);
            f_ACK = TRUE;
            Sleep(299);
            //memset(ARC1_SentMsg, 0, BUFSIZE);
            //memset(ARC1_SentMsg2, 0, BUFSIZE);
        }

        prev_ARC1_Path = ARC1_Index;

        b_ARC1_flag = FALSE;
    }

    //if(f_ARC1_Dlg)
    //            p_CSET_ARC1->PostMessageW(UWM_RTON_ENABLE, NULL, NULL);
}

void CITC_GUI_01Dlg::OnBnClickedBtnArc2()
{
    int Len_ARC2_SentMsg = 0;

    if(CheckTestFlag())
    {
        return;
    }

    if(CheckConnect() == (-1))
    {
        return;
    }

    ARC2_Index = m_combo_ARC2.GetCurSel();  // 현재 선택된 콤보박스 인덱스 저장
    CheckPath(ARC2_Index);

    if((1 <= ARC2_Index) && (ARC2_Index <= 5))
    {
        if(b_ARC1_flag)
        {
            AfxMessageBox(_T("> 사용 불가.\r\n"));
        }
        else
        {
            if(prev_ARC2_Path != 0x64)
            {
                if(prev_ARC2_Path != 0)
                {
                    if((b_PrevCOM2XMode == TRUE) | (b_PrevCOM3XMode == TRUE))
                    {
                        b_PrevCOM2XMode = FALSE;
                        b_PrevCOM3XMode = FALSE;

                        ARC2_SentMsg[11] = 0x00;
                        ARC2_SentMsg2[11] = 0x00;

                        Len_ARC2_SentMsg = 13;
                    }
                    else
                    {
                        ARC2_SentMsg[14] = 0x00;
                        ARC2_SentMsg2[14] = 0x00;

                        Len_ARC2_SentMsg = 16;
                    }
                    send(mh_socket, ARC2_SentMsg, Len_ARC2_SentMsg, 0); 
                    SetTimer(ARC2, 300, NULL);
                    f_ACK = TRUE;
                    Sleep(299);

                    send(mh_socket, ARC2_SentMsg2, Len_ARC2_SentMsg, 0); 
                    SetTimer(ARC2, 300, NULL);
                    f_ACK = TRUE;
                    Sleep(299);

                    SendARCState(0x0444, prev_ARC2_Path, 0);
                    SetTimer(ARC2, 300, NULL);
                    f_ACK = TRUE;
                    Sleep(299);
                    //memset(ARC2_SentMsg, 0, BUFSIZE);
                    //memset(ARC2_SentMsg2, 0, BUFSIZE);
                }
            }
            Clssfctn(ARC2_Index, &m_slider_arc2, ARC2, 1);
            memcpy(ARC2_SentMsg, &SendMsg, sizeof(SendMsg));
            Sleep(299);

            Clssfctn(ARC2_Index, &m_slider_arc2, ARC2, 2);
            memcpy(ARC2_SentMsg2, &SendMsg, sizeof(SendMsg));
            Sleep(299);

            SendARCState(0x0444, ARC2_Index, 1);
            SetTimer(ARC2, 300, NULL);
            f_ACK = TRUE;
            Sleep(299);

            prev_ARC2_Path = ARC2_Index;

            b_ARC2_flag = TRUE;
        }
    }
    else if(ARC2_Index == 0 && (prev_ARC2_Path != 0))
    {
        AddEventString(_T("> None을 선택하였습니다.\r\n"));
        if(prev_ARC2_Path != 0x64)
        {
            if((b_PrevCOM2XMode == TRUE) | (b_PrevCOM3XMode == TRUE))
            {
                b_PrevCOM2XMode = FALSE;
                b_PrevCOM3XMode = FALSE;

                ARC2_SentMsg[11] = 0x00;
                ARC2_SentMsg2[11] = 0x00;

                Len_ARC2_SentMsg = 13;
            }
            else
            {
                ARC2_SentMsg[14] = 0x00;
                ARC2_SentMsg2[14] = 0x00;

                Len_ARC2_SentMsg = 16;
            }
            ARC2_SentMsg[14] = 0x00;
            send(mh_socket, ARC2_SentMsg, Len_ARC2_SentMsg, 0); 
            SetTimer(ARC2, 300, NULL);
            f_ACK = TRUE;
            Sleep(299);

            ARC2_SentMsg2[14] = 0x00;
            send(mh_socket, ARC2_SentMsg2, Len_ARC2_SentMsg, 0); 
            SetTimer(ARC2, 300, NULL);
            f_ACK = TRUE;
            Sleep(299);

            SendARCState(0x0444, prev_ARC2_Path, 0);
            SetTimer(ARC2, 300, NULL);
            f_ACK = TRUE;
            Sleep(299);
            //memset(ARC2_SentMsg, 0, BUFSIZE);
            //memset(ARC2_SentMsg2, 0, BUFSIZE);
        }

        prev_ARC2_Path = ARC2_Index;

        b_ARC2_flag = FALSE;
    }
    //if(f_ARC2_Dlg)
    //            p_CSET_ARC2->PostMessageW(UWM_RTON_ENABLE, NULL, NULL);
}


void CITC_GUI_01Dlg::Clssfctn(U8BIT m_Path, CSliderCtrl* m_CSliderCtrl, U16BIT m_OP, U8BIT f_MICorSPK)
{
    UINT8 m_CH = 0;
    m_SCVolume = m_CSliderCtrl->GetPos();

    if(m_SCVolume>0)
    {
        m_SCVolume = (m_SCVolume * 6 ) + 3;
    }
    else
    {
        m_SCVolume = 0;
    }

    m_OP = htons(m_OP);

    if(f_MICorSPK == 1)
    {
        if((1 <= m_Path) && (m_Path <= 9))
        {
            if((m_OP == 0x0144) | (m_OP == 0x0244)) // ARC1 또는 ARC2 선택 시
            {
                if((m_Path == 2) & (RecvMsg[16]))   // COM2 X-MODE Enable 시
                {
                    b_PrevCOM2XMode = TRUE;
                    m_CH = 2;
                }
                else if((m_Path == 3) & (RecvMsg[17]))  // COM3 X-MODE Enable 시
                {
                    b_PrevCOM3XMode = TRUE;
                    m_CH = 2;
                }
                else
                {
                    m_CH = 1;
                }
            }
            else
            {
                if(m_Path <= 5)
                {
                    m_CH = 1;
                }
                else
                {
                    m_CH = 2;
                }
            }
        }
        else if((11 <= m_Path) && (m_Path <= 19))
        {
            if(f_MICorSPK == 1)
            {
                if(m_Path <= 14)
                {
                    m_CH = 4;
                }
                else
                {
                    m_CH = 5;
                }
            }
            else if(f_MICorSPK == 2)
            {
                if(m_Path <= 13)
                {
                    m_CH = 4;
                }
                else
                {
                    m_CH = 5;
                }
            }
        }
        else if((21 <= m_Path) && (m_Path <= 22))
        {
            m_CH = 6;
        }
        else if(m_Path == 0)
        {
            m_CH = 0;
        }
    }

    else if(f_MICorSPK == 2)
    {
        if((1 <= m_Path) && (m_Path <= 9))
        {
            if(m_Path <= 5)
            {
                m_CH = 1;
            }
            else
            {
                m_CH = 2;
            }

        }
        else if((11 <= m_Path) && (m_Path <= 17))
        {
            if(f_MICorSPK == 1)
            {
                if(m_Path <= 14)
                {
                    m_CH = 4;
                }
                else
                {
                    m_CH = 5;
                }
            }
            else if(f_MICorSPK == 2)
            {
                if(m_Path <= 13)
                {
                    m_CH = 4;
                }
                else
                {
                    m_CH = 5;
                }
            }
        }
        else if((19 <= m_Path) && (m_Path <= 20))
        {
            m_CH = 6;
        }
        else if(m_Path == 0)
        {
            m_CH = 0;
        }
    }
    MakeFrame(m_Path, m_CH, m_SCVolume, m_OP, f_MICorSPK);
}


void CITC_GUI_01Dlg::MakeFrame(U8BIT m_Path, U8BIT m_Codec,  U8BIT m_Volume, U16BIT m_OP, U8BIT f_MICorSPK)
{
    U8BIT Port1 = 0, Port2 = 0, Port3 = 0, Port4 = 0, Port5 = 0, Port6 = 0, Port7 = 0, Port8 = 0, Port9 = 0;   // Port1~6 변수 선언
    U8BIT m_OnOff = 0x01;
    U8BIT MsgSize = 0;
    U8BIT m_cnt_Data = 0;
    U8BIT m_Input = 0, m_Output = 0;

    if(m_connect_flag != 1)
    {
        AfxMessageBox(_T("> 연결 중인 상태가 아닙니다.\r\n"));
        return;
    }

    if(m_OP == 0x0111)
    {
        if(prev_MIC1_Path != 0x64)
        {
            if((prev_Codec_MIC1 == 1) || (prev_Codec_MIC1 == 5))
            {
                MIC1_SentMsg[14] = 0x00;
                send(mh_socket, MIC1_SentMsg, prev_MsgSize(prev_Codec_MIC1), 0); 
            }
            else if((prev_Codec_MIC1 == 2) || (prev_Codec_MIC1 == 4))
            {
                MIC1_SentMsg[11] = 0x00;
                send(mh_socket, MIC1_SentMsg, prev_MsgSize(prev_Codec_MIC1), 0); 
            }
            else if(prev_Codec_MIC1 == 6)
            {
                MIC1_SentMsg[8] = 0x00;
                send(mh_socket, MIC1_SentMsg, prev_MsgSize(prev_Codec_MIC1), 0); 
            }    
            memset(MIC1_SentMsg, 0, BUFSIZE);
            Sleep(299);
        }
        prev_MIC1_Path = m_Path;
    }
    else if(m_OP == 0x0211)
    {
        if(prev_MIC2_Path != 0x64)
        {
            if((prev_Codec_MIC2 == 1) || (prev_Codec_MIC2 == 5))
            {
                MIC2_SentMsg[14] = 0x00;
                send(mh_socket, MIC2_SentMsg, prev_MsgSize(prev_Codec_MIC2), 0); 

            }
            else if((prev_Codec_MIC2 == 2) || (prev_Codec_MIC2 == 4))
            {
                MIC2_SentMsg[11] = 0x00;
                send(mh_socket, MIC2_SentMsg, prev_MsgSize(prev_Codec_MIC2), 0); 
            }
            else if(prev_Codec_MIC2 == 6)
            {
                MIC2_SentMsg[8] = 0x00;
                send(mh_socket, MIC2_SentMsg, prev_MsgSize(prev_Codec_MIC2), 0); 
            }    
            memset(MIC2_SentMsg, 0, BUFSIZE);
            Sleep(299);
        }
        prev_MIC2_Path = m_Path;
    }
    else if(m_OP == 0x0133)
    {
        if(prev_SPK1_Path != 0x64)
        {
            if((prev_Codec_SPK1 == 1) || (prev_Codec_SPK1 == 5))
            {
                SPK1_SentMsg[14] = 0x00;
                send(mh_socket, SPK1_SentMsg, prev_MsgSize(prev_Codec_SPK1), 0); 
            }
            else if((prev_Codec_SPK1 == 2) || (prev_Codec_SPK1 == 4))
            {
                SPK1_SentMsg[11] = 0x00;
                send(mh_socket, SPK1_SentMsg, prev_MsgSize(prev_Codec_SPK1), 0); 
            }
            else if(prev_Codec_SPK1 == 6)
            {
                SPK1_SentMsg[8] = 0x00;
                send(mh_socket, SPK1_SentMsg, prev_MsgSize(prev_Codec_SPK1), 0); 
            }    
            memset(SPK1_SentMsg, 0, BUFSIZE);
            Sleep(299);
        }
        prev_SPK1_Path = m_Path;
    }
    else if(m_OP == 0x0233)
    {
        if(prev_SPK2_Path != 0x64)
        {
            if((prev_Codec_SPK2 == 1) || (prev_Codec_SPK2 == 5))
            {
                SPK2_SentMsg[14] = 0x00;
                send(mh_socket, SPK2_SentMsg, prev_MsgSize(prev_Codec_SPK2), 0); 
            }
            else if((prev_Codec_SPK2 == 2) || (prev_Codec_SPK2 == 4))
            {
                SPK2_SentMsg[11] = 0x00;
                send(mh_socket, SPK2_SentMsg, prev_MsgSize(prev_Codec_SPK2), 0); 
            }
            else if(prev_Codec_SPK2 == 6)
            {
                SPK2_SentMsg[8] = 0x00;
                send(mh_socket, SPK2_SentMsg, prev_MsgSize(prev_Codec_SPK2), 0); 
            }    
            memset(SPK2_SentMsg, 0, BUFSIZE);
            Sleep(299);
        }
        prev_SPK2_Path = m_Path;
    }


    switch(m_OP)
    {
    case 0x0111:
        m_Input = 0x01;
        break;
    case 0x0211:
        m_Input = 0x02;
        break;
    case 0x0133:
        m_Input = 0x01;
        m_Output = 0x01;
        break;
    case 0x0233:
        m_Input = 0x02;
        m_Output = 0x02;
        break;
    case 0x0144:
        m_Input = 0x06;
        m_Output = 0x03;
        break;
    case 0x0244:
        m_Input = 0x05;
        m_Output = 0x04;
        break;
    }

    if(f_MICorSPK == 1)
    {
        if(m_Codec == 1)
        {
            m_Output = m_Path;

            Port1 = 0x02;   // CH3
            Port2 = m_Input;
            Port3 = 0x06;   // CH3->CH2 RX

            Port4 = 0x01;   // CH2
            Port5 = 0x06;   // 
            Port6 = 0x06;   // 

            Port7 = 0x00;   // CH1
            Port8 = 0x06;   // 
            Port9 = m_Output;   // 
        }
        else if(m_Codec == 2)
        {
            if(((m_OP == 0x0144) | (m_OP == 0x0244)) & (m_Path == 2))
            {
                m_Output = 1;
            }
            else if(((m_OP == 0x0144) | (m_OP == 0x0244)) & (m_Path == 3))
            {
                m_Output = 2;
            }
            else
                m_Output = m_Path - 0x05;

            Port1 = 0x02;   // CH3
            Port2 = m_Input;
            Port3 = 0x06;

            Port4 = 0x01;   // CH2
            Port5 = 0x06;
            Port6 = m_Output;
        }
        else if(m_Codec == 4)
        {
            m_Output = m_Path - 0x0A;

            Port1 = 0x02;   // CH3->CH4 TX
            Port2 = m_Input;   // CH4
            Port3 = 0x05;   // CH3->CH4 RX

            Port4 = 0x03;   // CH4
            Port5 = 0x05;
            Port6 = m_Output;
        }
        else if(m_Codec == 5)
        {
            m_Output = m_Path - 0x0E;

            Port1 = 0x02;   // CH3->CH4 TX
            Port2 = m_Input;   // CH4
            Port3 = 0x05;   // CH3->CH4 RX

            Port4 = 0x03;   // CH4
            Port5 = 0x05;
            Port6 = 0x05;

            Port7 = 0x04;   // CH4
            Port8 = 0x05;
            Port9 = m_Output;
        }
        else if(m_Codec == 6)
        {
            m_Output = m_Path - 0x12;

            Port1 = 0x02;   // CH3
            Port2 = m_Input;   // CH4
            Port3 = m_Output;   // CH3->CH4 RX
        }
    }
    else if(f_MICorSPK == 2)
    {
        if(m_Codec == 1)
        {
            m_Input = m_Path;

            Port1 = 0x00;   // CH1
            Port2 = m_Input;
            Port3 = 0x06;   // CH1->CH2 TX

            Port4 = 0x01;   // CH2
            Port5 = 0x05;   // CH1->CH2 RX
            Port6 = 0x05;   // CH2->CH3 TX

            Port7 = 0x02;   // CH3
            Port8 = 0x04;   // CH2->CH3 RX
            Port9 = m_Output;   // 
        }
        else if(m_Codec == 2)
        {

            if(((m_OP == 0x0144) | (m_OP == 0x0244)) & (m_Path == 2))
            {
                m_Output = 1;
            }
            else if(((m_OP == 0x0144) | (m_OP == 0x0244)) & (m_Path == 3))
            {
                m_Output = 2;
            }
            else
                m_Output = m_Path - 0x05;

            Port1 = 0x01;   // CH3
            Port2 = m_Output;
            Port3 = 0x05;

            Port4 = 0x02;   // CH2
            Port5 = 0x04;
            Port6 = m_Input;
        }
        else if(m_Codec == 4)
        {
            m_Output = m_Path - 0x0A;
            // AfxMessageBox(_T("1"));

            Port1 = 0x03;   // CH4
            Port2 = m_Output;
            Port3 = 0x06;   // CH4->CH3 TX

            Port4 = 0x02;   // CH3
            Port5 = 0x03;   // CH4->CH3 RX
            Port6 = m_Input;
        }
        else if(m_Codec == 5)
        {
            m_Output = m_Path - 0x0D;
            // AfxMessageBox(_T("2"));

            Port1 = 0x04;   // CH5
            Port2 = m_Output;
            Port3 = 0x06;   // CH5->CH4 TX

            Port4 = 0x03;   // CH4
            Port5 = 0x06;   // CH5->CH4 RX
            Port6 = 0x06;   // CH4->CH3 TX

            Port7 = 0x02;   // CH3
            Port8 = 0x03;   // CH4->CH3 RX
            Port9 = m_Input;
        }
        else if(m_Codec == 6)
        {
            if(m_Path == 0x13)
                m_Input = 0x06;
            else if(m_Path == 0x14)
                m_Input = 0x05;
            // m_Input = m_Path - 0x10;
            // m_Output = m_Path - 0x12;

            Port1 = 0x02;   // CH3
            Port2 = m_Input;   // CH3
            Port3 = m_Output;   // CH3
        }
    }

    if((m_Codec == 1) || (m_Codec == 5))
    {
        MsgSize = 16;
        m_cnt_Data = 11;
    }
    else if((m_Codec == 2) || (m_Codec == 4) || (m_Codec == 0))
    {
        MsgSize = 13;
        m_cnt_Data = 8;
    }
    else if(m_Codec == 6)
    {
        MsgSize = 10;
        m_cnt_Data = 5;
    }

    if((m_Codec == 2)||(m_Codec== 4))
    {
        memcpy(SendMsg, &StartCode, sizeof(StartCode));
        memcpy(SendMsg + sizeof(StartCode), &m_cnt_Data, sizeof(m_cnt_Data));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data), &m_OP, sizeof(m_OP));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP), &Port1, sizeof(Port1));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1), &Port2, sizeof(Port2));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2), &Port3, sizeof(Port3));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3), &Port4, sizeof(Port4));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4), &Port5, sizeof(Port5));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5), &Port6, sizeof(Port6));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6), &m_Volume, sizeof(m_Volume));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6) + sizeof(m_Volume), &m_OnOff, sizeof(m_OnOff));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6) + sizeof(m_Volume) + sizeof(m_OnOff), &EndCode, sizeof(EndCode));

        send(mh_socket, SendMsg, MsgSize, 0); 

        SetTimer(m_OP, 300, NULL);
        Sleep(299);
        f_ACK = TRUE;
    }
    else if((m_Codec == 1)||(m_Codec== 5))
    {
        memcpy(SendMsg, &StartCode, sizeof(StartCode));
        memcpy(SendMsg + sizeof(StartCode), &m_cnt_Data, sizeof(m_cnt_Data));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data), &m_OP, sizeof(m_OP));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP), &Port1, sizeof(Port1));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1), &Port2, sizeof(Port2));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2), &Port3, sizeof(Port3));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3), &Port4, sizeof(Port4));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4), &Port5, sizeof(Port5));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5), &Port6, sizeof(Port6));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6), &Port7, sizeof(Port7));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6) + sizeof(Port7), &Port8, sizeof(Port8));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6) + sizeof(Port7) + sizeof(Port8), &Port9, sizeof(Port9));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6) + sizeof(Port7) + sizeof(Port8) + sizeof(Port9), &m_Volume, sizeof(m_Volume));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6) + sizeof(Port7) + sizeof(Port8) + sizeof(Port9) + sizeof(m_Volume), &m_OnOff, sizeof(m_OnOff));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(Port4) + sizeof(Port5) + sizeof(Port6) + sizeof(Port7) + sizeof(Port8) + sizeof(Port9) + sizeof(m_Volume) + sizeof(m_OnOff), &EndCode, sizeof(EndCode));

        send(mh_socket, SendMsg, MsgSize, 0); 

        SetTimer(m_OP, 300, NULL);
        Sleep(299);
        f_ACK = TRUE;
    }
    else if(m_Codec == 6)
    {
        memcpy(SendMsg, &StartCode, sizeof(StartCode));
        memcpy(SendMsg + sizeof(StartCode), &m_cnt_Data, sizeof(m_cnt_Data));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data), &m_OP, sizeof(m_OP));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP), &Port1, sizeof(Port1));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1), &Port2, sizeof(Port2));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2), &Port3, sizeof(Port3));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3), &m_Volume, sizeof(m_Volume));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(m_Volume), &m_OnOff, sizeof(m_OnOff));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(Port1) + sizeof(Port2) + sizeof(Port3) + sizeof(m_Volume) + sizeof(m_OnOff), &EndCode, sizeof(EndCode));

        send(mh_socket, SendMsg, MsgSize, 0); 

        SetTimer(m_OP, 299, NULL);
        Sleep(299);
        f_ACK = TRUE;
    }

    if(m_OP == 0x0111)
    {
        memcpy(MIC1_SentMsg, &SendMsg, sizeof(SendMsg));
        prev_Codec_MIC1 = m_Codec;
    }
    else if(m_OP == 0x0211)
    {
        memcpy(MIC2_SentMsg, &SendMsg, sizeof(SendMsg));
        prev_Codec_MIC2 = m_Codec;
    }
    else if(m_OP == 0x0133)
    {
        memcpy(SPK1_SentMsg, &SendMsg, sizeof(SendMsg));
        prev_Codec_SPK1 = m_Codec;
    }
    else if(m_OP == 0x0233)
    {
        memcpy(SPK2_SentMsg, &SendMsg, sizeof(SendMsg));
        prev_Codec_SPK2 = m_Codec;
    }

    // memset(SendMsg, 0, MsgSize);
}


void CITC_GUI_01Dlg::Clssfctn2(U8BIT m_Path, CSliderCtrl* m_CSliderCtrl, U8BIT m_Tone_Type, U16BIT m_OP, U8BIT m_BTN_Num)
{
    U8BIT m_CH;
    m_SCVolume = m_CSliderCtrl->GetPos();

    if(m_SCVolume>0)
    {
        m_SCVolume = (m_SCVolume * 6 )+ 3;
    }
    else
    {
        m_SCVolume = 0;
    }

    m_OP = htons(m_OP);

    if((1 <= m_Path) && (m_Path <= 9))
    {
        if(m_Path <= 5)
        {
            m_CH = 0;
        }
        else
        {
            m_CH = 1;
        }
    }
    else if((11 <= m_Path) && (m_Path <= 19))
    {
        if(m_Path <= 14)
        {
            m_CH = 3;
        }
        else
        {
            m_CH = 4;
        }
    }
    else
    {
        m_CH = 0;
    }
    MakeFrame2(m_Path, m_CH, m_SCVolume , m_Tone_Type, m_OP, m_BTN_Num);
}


void CITC_GUI_01Dlg::MakeFrame2(U8BIT m_Path, U8BIT m_Codec, U8BIT m_Volume, U8BIT m_Tone_Type, U16BIT m_OP, U8BIT m_BTN_Num)
{
    U8BIT Port1 = 0;
    U8BIT m_OnOff = 0x01;
    U8BIT m_cnt_Data = 0x05;

    if(m_Codec == 0)
    {
        Port1 = m_Path;
    }
    else if(m_Codec == 1)
    {
        Port1 = m_Path - 5;
    }
    else if(m_Codec == 3)
    {
        Port1 = m_Path - 10;
    }
    else if(m_Codec == 4)
    {
        Port1 = m_Path - 14;
    }

    if(m_BTN_Num == 0x01)
    {
        if(prev_TONE1_Path != 0x64)
        {
            if((prev_TONE1_Path != m_Path))
            {
                if(prev_TONE1_Path != 0x00)
                {
                    TONE1_SentMsg[7] = 0x00;
                    send(mh_socket, TONE1_SentMsg, 10, 0);
                    Sleep(299);
                }
                memset(TONE1_SentMsg, 0, 10);
            }
            else if((prev_TONE1_Path == 0x00) && (m_Path == 0x00))
            {
                AddEventString(_T("> None이 이미 선택되었습니다.\r\n"));
                return;
            }
            else
            {
                //if(prev_TONE1_Type != m_Tone_Type)
                //{
                TONE1_SentMsg[7] = 0x00;
                send(mh_socket, TONE1_SentMsg, 10, 0);
                Sleep(299);
                memset(TONE1_SentMsg, 0, 10);
                //}
                //else
                //{
                //    AddEventString(_T("> 동일한 경로가 사용 중입니다.\r\n"));
                //    return;
                //}
            }
        }
        prev_TONE1_Type = m_Tone_Type;
        prev_TONE1_Path = m_Path;
    }

    else if(m_BTN_Num == 0x02)
    {
        if(prev_TONE2_Path != 0x64)
        {
            if(prev_TONE2_Path != m_Path)
            {
                if(prev_TONE2_Path != 0x00)
                {
                    TONE2_SentMsg[7] = 0x00;
                    send(mh_socket, TONE2_SentMsg, 10, 0);
                    Sleep(299);
                }
                memset(TONE2_SentMsg, 0, 10);
            }
            else if((prev_TONE2_Path == 0x00) && (m_Path == 0x00))
            {
                AddEventString(_T("> None이 이미 선택되었습니다.\r\n"));
                return;
            }
            else
            {
                //if(prev_TONE2_Type != m_Tone_Type)
                //{
                TONE2_SentMsg[7] = 0x00;
                send(mh_socket, TONE2_SentMsg, 10, 0);
                Sleep(299);
                memset(TONE2_SentMsg, 0, 10);
                //}
                //else
                //{
                //    AddEventString(_T("> 동일한 경로가 사용 중입니다.\r\n"));
                //    return;
                //}
            }
        }
        prev_TONE2_Type = m_Tone_Type;
        prev_TONE2_Path = m_Path;
    }

    // Start code, OP code, 최종 출력 포트, 볼륨, On·Off 플래그, End code로 구성
    if(m_Path != 0x00)
    {
        memcpy(SendMsg, &StartCode, sizeof(StartCode));
        memcpy(SendMsg + sizeof(StartCode), &m_cnt_Data, sizeof(m_cnt_Data));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data), &m_OP, sizeof(m_OP));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP), &m_Codec, sizeof(m_Codec));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(m_Codec), &Port1, sizeof(Port1));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(m_Codec) + sizeof(Port1), &m_Volume, sizeof(m_Volume));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(m_Codec) + sizeof(Port1) + sizeof(m_Volume), &m_OnOff, sizeof(m_OnOff));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(m_Codec) + sizeof(Port1) + sizeof(m_Volume) + sizeof(m_OnOff), &m_Tone_Type, sizeof(m_Tone_Type));
        memcpy(SendMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(m_OP) + sizeof(m_Codec) + sizeof(Port1) + sizeof(m_Volume) + sizeof(m_OnOff) + sizeof(m_Tone_Type), &EndCode, sizeof(EndCode));

        send(mh_socket, SendMsg, 10, 0); 

        SetTimer(m_OP, 300, NULL);
        Sleep(299);
        f_ACK = TRUE;
    }

    // 지금 보낼 메시지를 보냈던 메시지 변수(배열)에 저장
    if(m_BTN_Num == 0x01)
        memcpy(TONE1_SentMsg, &SendMsg, sizeof(SendMsg));
    else if(m_BTN_Num == 0x02)
        memcpy(TONE2_SentMsg, &SendMsg, sizeof(SendMsg));

    // memset(SendMsg, 0, 10);
}


int CITC_GUI_01Dlg::CheckConnect(void)
{
    if(m_connect_flag != 1)
    {
        AfxMessageBox(_T("> 연결 중인 상태가 아닙니다.\r\n"));
        return -1;

    }
    else
        return 1;
}


void CITC_GUI_01Dlg::CheckPath(UINT8 Index)
{
    if(Index == 0xFF)
    {
        AfxMessageBox(_T("> 경로를 선택해주세요.\r\n"));
        return;
    }
}


U8BIT CITC_GUI_01Dlg::prev_MsgSize(U8BIT prev_Path)
{
    U8BIT MsgSize = 0;

    if((prev_Path == 1) || (prev_Path == 5))
    {
        MsgSize = 16;
    }
    else if((prev_Path == 2) || (prev_Path == 4) || (prev_Path == 0))
    {
        MsgSize = 13;
    }
    else if(prev_Path == 6)
    {
        MsgSize = 10;
    }

    return U8BIT(MsgSize);
}


void CITC_GUI_01Dlg::OnBnClickedMbtnPowSup()
{
    p_CCtrlPowSup = new CCtrlPowSup;
    p_CCtrlPowSup->Create(IDD_CTRLPOWSUP);
    p_CCtrlPowSup->ShowWindow(SW_SHOW);

    //m_ClientSocket.Create();

    //if( m_ClientSocket.Connect(IpAddr, nPort) == FALSE )
    //{
    //    m_mbtn_pow_sup.SetWindowTextW(L"전원공급기 ON");
    //    b_PowerSupp = FALSE;
    //    AfxMessageBox(_T("ERROR : Failed to connect PowerSupply"));

    //    m_ClientSocket.Close();

    //    return;
    //}
    //// test.Format(_T("%4X"), MSG_AIU_BC2RT[0]);
    //if(b_PowerSupp == FALSE)
    //    outp = _T("outp 1\n");
    //else
    //    outp = _T("outp 0\n");

    //CStringA voltA(volt);
    //CStringA currA(curr);
    //CStringA outpA(outp);

    //m_ClientSocket.Send(voltA, voltA.GetLength() * 2);
    //Sleep(100);
    //    m_ClientSocket.Send(currA, currA.GetLength() * 2);
    //    Sleep(100);
    //    m_ClientSocket.Send(outpA, outpA.GetLength() * 2);

    //if(b_PowerSupp == FALSE)
    //{
    //    m_mbtn_pow_sup.SetWindowTextW(L"전원공급기 OFF");
    //    b_PowerSupp = TRUE;
    //    //m_ClientSocket.Send(voltA, voltA.GetLength() * 2);
    //    //Sleep(100);
    //    //m_ClientSocket.Send(currA, currA.GetLength() * 2);
    //    //Sleep(100);
    //    //m_ClientSocket.Send(outpA, outpA.GetLength() * 2);
    //    //Sleep(100);
    //}
    //else
    //{
    //    m_mbtn_pow_sup.SetWindowTextW(L"전원공급기 ON");
    //    b_PowerSupp = FALSE;
    //    //m_ClientSocket.Send(outpA, outpA.GetLength() * 2);
    //    //Sleep(100);
    //}

    //m_ClientSocket.Close();

    //// AfxMessageBox(test);
}


afx_msg LRESULT CITC_GUI_01Dlg::OnUwmIcsDis(WPARAM wParam, LPARAM lParam)
{


    memcpy(WriteMsg, &m_CICS_CP.WriteMsg, sizeof(m_CICS_CP.WriteMsg));
    AddEventString(_T("> OnBnClickedMbtnSetIcs.\r\n"));
    send(mh_socket, WriteMsg, 26, 0);

    return 0;
}


void CITC_GUI_01Dlg::OnBnClickedBtnLogClear()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    m_EditLog.SetSel(0, -1, TRUE);
    m_EditLog.Clear();
}


void CITC_GUI_01Dlg::SendARCState(U16BIT ARCNum, U8BIT Port, U8BIT OnOff)
{
    U8BIT m_cnt_Data = 2;

    memcpy(ARC_StatetMsg, &(StartCode), sizeof(StartCode));
    memcpy(ARC_StatetMsg + sizeof(StartCode), &m_cnt_Data , sizeof(m_cnt_Data));
    memcpy(ARC_StatetMsg + sizeof(StartCode) + sizeof(m_cnt_Data), &ARCNum, sizeof(ARCNum));
    memcpy(ARC_StatetMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(ARCNum), &Port, sizeof(Port));
    memcpy(ARC_StatetMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(ARCNum) + sizeof(Port), &OnOff, sizeof(OnOff));
    memcpy(ARC_StatetMsg + sizeof(StartCode) + sizeof(m_cnt_Data) + sizeof(ARCNum) + sizeof(Port) + sizeof(OnOff), &EndCode, sizeof(EndCode));

    send(mh_socket, ARC_StatetMsg, 8, 1);
    memset(ARC_StatetMsg, 0, BUFSIZE);
}


void CITC_GUI_01Dlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    //CString str;
    //str.Format(L"OnTimer");
    //m_list_log.InsertString(-1, str);
    int wResult = 0;

    if(nIDEvent == ARC1_STATE)
    {
        // AddEventString(_T("ACK가 수신되지 않았습니다.\r\n"));
        UpdateARC1State();
    }
    else if(nIDEvent == MWOD_LOAD)
    {
        if( p_CSET_ARC1->un_OPTIONS.st_OPTIONS.WODData == 0 )
            p_CSET_ARC1->un_OPTIONS.st_OPTIONS.WODData = 1;
        else if( p_CSET_ARC1->un_OPTIONS.st_OPTIONS.WODData == 1 )
        {
            p_CSET_ARC1->un_OPTIONS.st_OPTIONS.WODData = 0;
            KillTimer(MWOD_LOAD);
        }

        MSG_FUNCTION_CONTROL_ARC1[5] = p_CSET_ARC1->un_OPTIONS.w_OPTIONS;

        CString str;

        str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
            , MSG_FUNCTION_CONTROL_ARC1[0], MSG_FUNCTION_CONTROL_ARC1[1], MSG_FUNCTION_CONTROL_ARC1[2], MSG_FUNCTION_CONTROL_ARC1[3], MSG_FUNCTION_CONTROL_ARC1[4]
        , MSG_FUNCTION_CONTROL_ARC1[5], MSG_FUNCTION_CONTROL_ARC1[6]);

        int n_Length = m_EditLog.GetWindowTextLengthW();
        m_EditLog.SetSel(n_Length, n_Length);
        m_EditLog.ReplaceSel(str);

        aceBCDataBlkWrite(DevNum, DBLK17, MSG_FUNCTION_CONTROL_ARC1, 7, 0);
        wResult = aceBCSendAsyncMsgHP(DevNum, MSG17, wFrmTime);

        if(wResult < 0)
            AfxMessageBox(_T("aceBCSendAsyncMsgHP 에러!\r\n"));
        else
            AddEventString(_T("aceBCSendAsyncMsgHP 성공!\r\n"));

    }
    else if(nIDEvent == FMT_NET_LOAD)
    {
        if( p_CSET_ARC1->un_OPTIONS.st_OPTIONS.FMTData == 0 )
            p_CSET_ARC1->un_OPTIONS.st_OPTIONS.FMTData = 1;
        else if( p_CSET_ARC1->un_OPTIONS.st_OPTIONS.FMTData == 1 )
        {
            p_CSET_ARC1->un_OPTIONS.st_OPTIONS.FMTData = 0;
            KillTimer(FMT_NET_LOAD);
        }

        MSG_FUNCTION_CONTROL_ARC1[5] = p_CSET_ARC1->un_OPTIONS.w_OPTIONS;

        CString str;

        str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
            , MSG_FUNCTION_CONTROL_ARC1[0], MSG_FUNCTION_CONTROL_ARC1[1], MSG_FUNCTION_CONTROL_ARC1[2], MSG_FUNCTION_CONTROL_ARC1[3], MSG_FUNCTION_CONTROL_ARC1[4]
        , MSG_FUNCTION_CONTROL_ARC1[5], MSG_FUNCTION_CONTROL_ARC1[6]);

        int n_Length = m_EditLog.GetWindowTextLengthW();
        m_EditLog.SetSel(n_Length, n_Length);
        m_EditLog.ReplaceSel(str);

        aceBCDataBlkWrite(DevNum, DBLK17, MSG_FUNCTION_CONTROL_ARC1, 7, 0);
        aceBCSendAsyncMsgHP(DevNum, MSG17, wFrmTime);
    }
    else if(nIDEvent == PRESET_LOAD)
    {
        if( p_CSET_ARC1->un_OPTIONS.st_OPTIONS.PresetData == 0 )
            p_CSET_ARC1->un_OPTIONS.st_OPTIONS.PresetData = 1;
        else if( p_CSET_ARC1->un_OPTIONS.st_OPTIONS.PresetData == 1 )
        {
            p_CSET_ARC1->un_OPTIONS.st_OPTIONS.PresetData = 0;
            KillTimer(PRESET_LOAD);
        }

        MSG_FUNCTION_CONTROL_ARC1[5] = p_CSET_ARC1->un_OPTIONS.w_OPTIONS;

        CString str;

        str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
            , MSG_FUNCTION_CONTROL_ARC1[0], MSG_FUNCTION_CONTROL_ARC1[1], MSG_FUNCTION_CONTROL_ARC1[2], MSG_FUNCTION_CONTROL_ARC1[3], MSG_FUNCTION_CONTROL_ARC1[4]
        , MSG_FUNCTION_CONTROL_ARC1[5], MSG_FUNCTION_CONTROL_ARC1[6]);

        int n_Length = m_EditLog.GetWindowTextLengthW();
        m_EditLog.SetSel(n_Length, n_Length);
        m_EditLog.ReplaceSel(str);

        aceBCDataBlkWrite(DevNum, DBLK17, MSG_FUNCTION_CONTROL_ARC1, 7, 0);
        aceBCSendAsyncMsgHP(DevNum, MSG17, wFrmTime);
    }
    else if(nIDEvent == MWOD_LOAD_2)
    {
        if( p_CSET_ARC2->un_OPTIONS.st_OPTIONS.WODData == 0 )
            p_CSET_ARC2->un_OPTIONS.st_OPTIONS.WODData = 1;
        else if( p_CSET_ARC2->un_OPTIONS.st_OPTIONS.WODData == 1 )
        {
            p_CSET_ARC2->un_OPTIONS.st_OPTIONS.WODData = 0;
            KillTimer(MWOD_LOAD_2);
        }

        MSG_FUNCTION_CONTROL_ARC2[5] = p_CSET_ARC2->un_OPTIONS.w_OPTIONS;

        CString str;

        str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
            , MSG_FUNCTION_CONTROL_ARC2[0], MSG_FUNCTION_CONTROL_ARC2[1], MSG_FUNCTION_CONTROL_ARC2[2], MSG_FUNCTION_CONTROL_ARC2[3], MSG_FUNCTION_CONTROL_ARC2[4]
        , MSG_FUNCTION_CONTROL_ARC2[5], MSG_FUNCTION_CONTROL_ARC2[6]);

        int n_Length = m_EditLog.GetWindowTextLengthW();
        m_EditLog.SetSel(n_Length, n_Length);
        m_EditLog.ReplaceSel(str);

        aceBCDataBlkWrite(DevNum, DBLK27, MSG_FUNCTION_CONTROL_ARC2, 7, 0);
        wResult = aceBCSendAsyncMsgHP(DevNum, MSG27, wFrmTime);

        if(wResult < 0)
            AfxMessageBox(_T("aceBCSendAsyncMsgHP 에러!\r\n"));
        else
            AddEventString(_T("aceBCSendAsyncMsgHP 성공!\r\n"));
    }
    else if(nIDEvent == FMT_NET_LOAD_2)
    {
        if( p_CSET_ARC2->un_OPTIONS.st_OPTIONS.FMTData == 0 )
            p_CSET_ARC2->un_OPTIONS.st_OPTIONS.FMTData = 1;
        else if( p_CSET_ARC2->un_OPTIONS.st_OPTIONS.FMTData == 1 )
        {
            p_CSET_ARC2->un_OPTIONS.st_OPTIONS.FMTData = 0;
            KillTimer(FMT_NET_LOAD_2);
        }

        MSG_FUNCTION_CONTROL_ARC2[5] = p_CSET_ARC2->un_OPTIONS.w_OPTIONS;

        CString str;

        str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
            , MSG_FUNCTION_CONTROL_ARC2[0], MSG_FUNCTION_CONTROL_ARC2[1], MSG_FUNCTION_CONTROL_ARC2[2], MSG_FUNCTION_CONTROL_ARC2[3], MSG_FUNCTION_CONTROL_ARC2[4]
        , MSG_FUNCTION_CONTROL_ARC2[5], MSG_FUNCTION_CONTROL_ARC2[6]);

        int n_Length = m_EditLog.GetWindowTextLengthW();
        m_EditLog.SetSel(n_Length, n_Length);
        m_EditLog.ReplaceSel(str);

        aceBCDataBlkWrite(DevNum, DBLK27, MSG_FUNCTION_CONTROL_ARC2, 7, 0);
        aceBCSendAsyncMsgHP(DevNum, MSG27, wFrmTime);
    }
    else if(nIDEvent == PRESET_LOAD_2)
    {
        if( p_CSET_ARC2->un_OPTIONS.st_OPTIONS.PresetData == 0 )
            p_CSET_ARC2->un_OPTIONS.st_OPTIONS.PresetData = 1;
        else if( p_CSET_ARC2->un_OPTIONS.st_OPTIONS.PresetData == 1 )
        {
            p_CSET_ARC2->un_OPTIONS.st_OPTIONS.PresetData = 0;
            KillTimer(PRESET_LOAD_2);
        }

        MSG_FUNCTION_CONTROL_ARC2[5] = p_CSET_ARC2->un_OPTIONS.w_OPTIONS;

        CString str;

        str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
            , MSG_FUNCTION_CONTROL_ARC2[0], MSG_FUNCTION_CONTROL_ARC2[1], MSG_FUNCTION_CONTROL_ARC2[2], MSG_FUNCTION_CONTROL_ARC2[3], MSG_FUNCTION_CONTROL_ARC2[4]
        , MSG_FUNCTION_CONTROL_ARC2[5], MSG_FUNCTION_CONTROL_ARC2[6]);

        int n_Length = m_EditLog.GetWindowTextLengthW();
        m_EditLog.SetSel(n_Length, n_Length);
        m_EditLog.ReplaceSel(str);

        aceBCDataBlkWrite(DevNum, DBLK27, MSG_FUNCTION_CONTROL_ARC2, 7, 0);
        aceBCSendAsyncMsgHP(DevNum, MSG27, wFrmTime);
    }
    else
    {
        f_ACK = FALSE;
        KillTimer(nIDEvent);
    }

    // ::SendMessage(m_CITC_SET_DIS->m_hWnd, UWM_ICS_DIS, NULL, NULL);
    CDialogEx::OnTimer(nIDEvent);
}


BOOL CITC_GUI_01Dlg::CheckTestFlag(void)
{
    if(f_ACK == TRUE)
    {
        AfxMessageBox(_T("다른 테스트가 진행 중에 있습니다.\r\n"));

        return TRUE;
    }
    else
        return FALSE;
}

void CITC_GUI_01Dlg::OnBnClickedMbtn1553b()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    //CString test;
    //test.Format(_T("%04X"), p_CICS_CP->un_VOICE_WARNING_MESSAGE7.w_VOICE_WARNING_MESSAGE7);
    //AfxMessageBox(test);

    if(b_BCState == FALSE)
    {

        int m_1553B_Connect = aceInitialize(DevNum, ACE_ACCESS_CARD, ACE_MODE_BC, 0, 0, 0);
        if(m_1553B_Connect < 0)
        {
            ChangeIcon(&m_icon_1553b, 2);
            m_mbtn_1553B.SetWindowTextW(L"1553B 연결");
            return;
        }
        else
        {
            ChangeIcon(&m_icon_1553b, 1);
            b_BCState = TRUE;
            m_mbtn_1553B.SetWindowTextW(L"1553B 연결  해제");
        }

        wResult = aceBCConfigure(DevNum, ACE_BC_ASYNC_HMODE);
        if(wResult < 0)
        {
            AfxMessageBox(_T("> aceBCConfigure 에러!\r\n"));
        }
        else
        {
            AddEventString(_T("> aceBCConfigure 성공!\r\n"));
        }
        /* 무전기1 상태확인 */
        aceBCDataBlkCreate(DevNum, DBLK1, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK2, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK3, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK4, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK5, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK6, 32, MSG_TMP, 32);

        /* 무전기2 상태확인 */
        aceBCDataBlkCreate(DevNum, DBLK41, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK42, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK43, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK44, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK45, 32, MSG_TMP, 32);
        aceBCDataBlkCreate(DevNum, DBLK46, 32, MSG_TMP, 32);

        /* AIU 제어 */
        aceBCDataBlkCreate(DevNum, DBLK31, 32, MSG_AIU_BC2RT, 32);
        aceBCDataBlkCreate(DevNum, DBLK32, 32, MSG_TMP, 32);    // RT-BC-01
        aceBCDataBlkCreate(DevNum, DBLK33, 32, MSG_TMP, 32);    // RT-BC-02


        /* Create message block */
        // FUNCTION_STATUS
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG1,                /* Message ID to create             */
            DBLK1,               /* Message will use this data block */
            RT1_ADDR,                   /* RT address                       */
            01,                   /* RT subaddress                    */
            7,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // TOD_STATUS
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG2,                /* Message ID to create             */
            DBLK2,               /* Message will use this data block */
            RT1_ADDR,                   /* RT address                       */
            05,                   /* RT subaddress                    */
            2,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // BIT_REPORT
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG3,                /* Message ID to create             */
            DBLK3,               /* Message will use this data block */
            RT1_ADDR,                   /* RT address                       */
            29,                   /* RT subaddress                    */
            6,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // MWOD Load Status
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG4,                /* Message ID to create             */
            DBLK4,               /* Message will use this data block */
            RT1_ADDR,                   /* RT address                       */
            02,                   /* RT subaddress                    */
            4,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // FMT Net Load Status
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG5,                /* Message ID to create             */
            DBLK5,               /* Message will use this data block */
            RT1_ADDR,                   /* RT address                       */
            03,                   /* RT subaddress                    */
            1,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // Preset Status
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG6,                /* Message ID to create             */
            DBLK6,               /* Message will use this data block */
            RT1_ADDR,                   /* RT address                       */
            07,                   /* RT subaddress                    */
            21,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG41,                /* Message ID to create             */
            DBLK41,               /* Message will use this data block */
            RT2_ADDR,                   /* RT address                       */
            01,                   /* RT subaddress                    */
            7,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // TOD_STATUS
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG42,                /* Message ID to create             */
            DBLK42,               /* Message will use this data block */
            RT2_ADDR,                   /* RT address                       */
            05,                   /* RT subaddress                    */
            2,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // BIT_REPORT
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG43,                /* Message ID to create             */
            DBLK43,               /* Message will use this data block */
            RT2_ADDR,                   /* RT address                       */
            29,                   /* RT subaddress                    */
            6,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // MWOD Load Status
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG44,                /* Message ID to create             */
            DBLK44,               /* Message will use this data block */
            RT2_ADDR,                   /* RT address                       */
            02,                   /* RT subaddress                    */
            4,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // FMT Net Load Status
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG45,                /* Message ID to create             */
            DBLK45,               /* Message will use this data block */
            RT2_ADDR,                   /* RT address                       */
            03,                   /* RT subaddress                    */
            1,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        // Preset Status
        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG46,                /* Message ID to create             */
            DBLK46,               /* Message will use this data block */
            RT2_ADDR,                   /* RT address                       */
            07,                   /* RT subaddress                    */
            21,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */

        aceBCMsgCreateBCtoRT(
            DevNum,              /* Device number                    */
            MSG31,                /* Message ID to create             */
            DBLK31,               /* Message will use this data block */
            AIU_ADDR,                   /* RT address                       */
            1,                   /* RT subaddress                    */
            16,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A);   /* use chl A options                */

        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG32,                /* Message ID to create             */
            DBLK32,               /* Message will use this data block */
            AIU_ADDR,                   /* RT address                       */
            1,                   /* RT subaddress                    */
            10,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A);   /* use chl A options                */

        aceBCMsgCreateRTtoBC(
            DevNum,              /* Device number                    */
            MSG33,                /* Message ID to create             */
            DBLK33,               /* Message will use this data block */
            AIU_ADDR,                   /* RT address                       */
            2,                   /* RT subaddress                    */
            2,                  /* Word count                       */
            0,                   /* Default message timer            */
            ACE_BCCTRL_CHL_A);   /* use chl A options                */
        //ACE_BCCTRL_CHL_A | ACE_BCCTRL_RETRY_ENA);   /* use chl A options                */
        /* Create XEQ opcode that will use msg block */
        aceBCOpCodeCreate(DevNum, OP1, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG1, 0, 0);
        aceBCOpCodeCreate(DevNum, OP2, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG2, 0, 0);
        aceBCOpCodeCreate(DevNum, OP3, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG3, 0, 0);
        aceBCOpCodeCreate(DevNum, OP4, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG4, 0, 0);
        aceBCOpCodeCreate(DevNum, OP5, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG5, 0, 0);
        aceBCOpCodeCreate(DevNum, OP6, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG6, 0, 0);

        aceBCOpCodeCreate(DevNum, OP41, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG41, 0, 0);
        aceBCOpCodeCreate(DevNum, OP42, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG42, 0, 0);
        aceBCOpCodeCreate(DevNum, OP43, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG43, 0, 0);
        aceBCOpCodeCreate(DevNum, OP44, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG44, 0, 0);
        aceBCOpCodeCreate(DevNum, OP45, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG45, 0, 0);
        aceBCOpCodeCreate(DevNum, OP46, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG46, 0, 0);

        aceBCOpCodeCreate(DevNum, OP31, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG31, 0, 0);
        aceBCOpCodeCreate(DevNum, OP32, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG32, 0, 0);
        aceBCOpCodeCreate(DevNum, OP33, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG33, 0, 0);

        /* Create CAL opcode that will call mnr frame from major */
        aceBCOpCodeCreate(DevNum, OP8, ACE_OPCODE_CAL, ACE_CNDTST_ALWAYS, MNR1, 0, 0);
        aceBCOpCodeCreate(DevNum, OP48, ACE_OPCODE_CAL, ACE_CNDTST_ALWAYS, MNR2, 0, 0);
        aceBCOpCodeCreate(DevNum, OP38, ACE_OPCODE_CAL, ACE_CNDTST_ALWAYS, MNR3, 0, 0);

        /* Create Minor Frame */
        aOpCodes[0] = OP1;
        aOpCodes[1] = OP2;
        aOpCodes[2] = OP3;
        aOpCodes[3] = OP4;
        aOpCodes[4] = OP5;
        aOpCodes[5] = OP6;
        aceBCFrameCreate(DevNum, MNR1, ACE_FRAME_MINOR, aOpCodes, 6, 500, 0);

        aOpCodes[0] = OP41;
        aOpCodes[1] = OP42;
        aOpCodes[2] = OP43;
        aOpCodes[3] = OP44;
        aOpCodes[4] = OP45;
        aOpCodes[5] = OP46;
        aceBCFrameCreate(DevNum, MNR2, ACE_FRAME_MINOR, aOpCodes, 6, 500, 0);

        aOpCodes[0] = OP31;
        aOpCodes[1] = OP32;
        aOpCodes[2] = OP33;
        aceBCFrameCreate(DevNum, MNR3, ACE_FRAME_MINOR, aOpCodes, 3, 600, 0);

        /* Create Major Frame */
        aOpCodes[0] = OP8;
        aOpCodes[1] = OP48;
        aOpCodes[2] = OP38;
        aceBCFrameCreate(DevNum, MJR, ACE_FRAME_MAJOR, aOpCodes, 3, 0, 0); /* WonJoon : 500 -> 50 msec */

        /* Create Host Buffer */
        aceBCInstallHBuf(DevNum, 16 * 1024);

        // aceBCSetMsgRetry(DevNum, ACE_RETRY_TWICE, ACE_RETRY_ALT, ACE_RETRY_SAME, 0);

        aceBCStart(DevNum, MJR, -1);

        aceBCGetHBufMsgDecoded(DevNum, &sMsg, &dwMsgCount, &dwHBufLost, ACE_BC_MSGLOC_NEXT_PURGE);

        DDC_MSLEEP(1);

        SetTimer(ARC1_STATE, 300, NULL);
    }
    else
    {
        aceBCStop(DevNum);
        aceFree(DevNum);

        b_BCState = FALSE;
        m_mbtn_1553B.SetWindowTextW(L"1553B 연결");

        ChangeIcon(&m_icon_1553b, 2);
    }

}


BOOL CITC_GUI_01Dlg::UpdateARC1State(void)
{

    aceBCDataBlkRead(DevNum, DBLK1, wBuffer1, 7, 0);
    aceBCDataBlkRead(DevNum, DBLK2, wBuffer2, 2, 0);
    aceBCDataBlkRead(DevNum, DBLK3, wBuffer3, 6, 0);
    //aceBCDataBlkRead(DevNum, DBLK4, wBuffer4, 4, 0);
    aceBCDataBlkRead(DevNum, DBLK5, wBuffer5, 1, 0);
    aceBCDataBlkRead(DevNum, DBLK6, wBuffer6, 21, 0);

    aceBCDataBlkRead(DevNum, DBLK41, wBuffer41, 7, 0);
    aceBCDataBlkRead(DevNum, DBLK42, wBuffer42, 2, 0);
    aceBCDataBlkRead(DevNum, DBLK43, wBuffer43, 6, 0);
    //aceBCDataBlkRead(DevNum, DBLK44, wBuffer44, 4, 0);
    aceBCDataBlkRead(DevNum, DBLK45, wBuffer45, 1, 0);
    aceBCDataBlkRead(DevNum, DBLK46, wBuffer46, 21, 0);

    aceBCDataBlkRead(DevNum, DBLK32, wBuffer32, 10, 0);
    aceBCDataBlkRead(DevNum, DBLK33, wBuffer33, 2, 0);
    //CString str_log_1553B;

    //str_log_1553B.Format(_T("  1] %04X %04X %04X %04X %04X %04X %04X\r\n\r\n"), wBuffer1[0], wBuffer1[1], wBuffer1[2], wBuffer1[3], wBuffer1[4], wBuffer1[5], wBuffer1[6]);
    //int n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("  5] %04X %04X\r\n\r\n"), wBuffer2[0], wBuffer2[1]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("29] %04X %04X %04X %04X %04X %04X\r\n\r\n"), wBuffer3[0], wBuffer3[1], wBuffer3[2], wBuffer3[3], wBuffer3[4], wBuffer3[5]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("  2] %04X %04X %04X %04X\r\n\r\n"), wBuffer4[0], wBuffer4[1], wBuffer4[2], wBuffer4[3]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("  3] %04X\r\n\r\n"), wBuffer5[0]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("  7] %04X %04X %04X %04X %04X %04X %04X\r\n"), wBuffer6[0], wBuffer6[1], wBuffer6[2], wBuffer6[3], wBuffer6[4], wBuffer6[5], wBuffer6[6]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("       %04X %04X %04X %04X %04X %04X %04X\r\n"), wBuffer6[7], wBuffer6[8], wBuffer6[9], wBuffer6[10], wBuffer6[11], wBuffer6[12], wBuffer6[13]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("       %04X %04X %04X %04X %04X %04X %04X\r\n\r\n\r\n"), wBuffer6[14], wBuffer6[15], wBuffer6[16], wBuffer6[17], wBuffer6[18], wBuffer6[19], wBuffer6[20]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    un_PRESET_SELECT_ARC1.w_PRESET_SELECT = wBuffer1[0];
    un_MODE_AND_GUARD_ARC1.w_MODE_AND_GUARD = wBuffer1[1];
    un_MARITIME_CHANNEL_ARC1.w_MARITIME_CHANNEL = wBuffer1[2];
    un_FREQUENCY_ARC1.w_FREQUENCY = wBuffer1[3];
    un_FINE_FREQUENCY_AND_AJ_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer1[4];
    un_OPTIONS_ARC1.w_OPTIONS = wBuffer1[5];

    un_TOD_STATUS_ARC1.w_TOD_MANAGEMENT = wBuffer2[0];
    un_TOD_RESERVED_ARC1.w_RESERVED = wBuffer2[1];

    un_BIT_SUMMARY_ARC1.w_BIT_SUMMARY = wBuffer3[0];
    un_SOFTWARE_ID_ARC1.w_SOFTWARE_ID = wBuffer3[1];
    un_SOFTWARE_VERSION_ARC1.w_SOFTWARE_VERSION = wBuffer3[2];
    un_FAULT_LOCATION01_ARC1.w_FAULT_LOCATION01 = wBuffer3[4];
    un_FAULT_LOCATION02_ARC1.w_FAULT_LOCATION01 = wBuffer3[5];

    //un_MWOD_LOAD_STATUS_ARC1.w_MWOD_LOAD_STATUS = wBuffer4[0];
    //un_MWOD_1_AND_2_DAY_ARC1.w_MWOD_A_AND_B_DAY = wBuffer4[1];
    //un_MWOD_3_AND_4_DAY_ARC1.w_MWOD_A_AND_B_DAY = wBuffer4[2];
    //un_MWOD_5_AND_6_DAY_ARC1.w_MWOD_A_AND_B_DAY = wBuffer4[3];

    un_FMT_NET_LOAD_STATUS_ARC1.w_FMT_NET_LOAD_STATUS = wBuffer5[4];

    un_PRESET_GROUP_SELECT_ARC1.w_PRESET_GROUP_SELECT = wBuffer6[0];
    un_COARSE_FREQUENCY_01_ARC1.w_FREQUENCY = wBuffer6[1];
    un_FINE_FREQUENCY_AND_AJ_01_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[2];
    un_COARSE_FREQUENCY_02_ARC1.w_FREQUENCY = wBuffer6[3];
    un_FINE_FREQUENCY_AND_AJ_02_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[4];
    un_COARSE_FREQUENCY_03_ARC1.w_FREQUENCY = wBuffer6[5];
    un_FINE_FREQUENCY_AND_AJ_03_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[6];
    un_COARSE_FREQUENCY_04_ARC1.w_FREQUENCY = wBuffer6[7];
    un_FINE_FREQUENCY_AND_AJ_04_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[8];
    un_COARSE_FREQUENCY_05_ARC1.w_FREQUENCY = wBuffer6[9];
    un_FINE_FREQUENCY_AND_AJ_05_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[10];
    un_COARSE_FREQUENCY_06_ARC1.w_FREQUENCY = wBuffer6[11];
    un_FINE_FREQUENCY_AND_AJ_06_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[12];
    un_COARSE_FREQUENCY_07_ARC1.w_FREQUENCY = wBuffer6[13];
    un_FINE_FREQUENCY_AND_AJ_07_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[14];
    un_COARSE_FREQUENCY_08_ARC1.w_FREQUENCY = wBuffer6[15];
    un_FINE_FREQUENCY_AND_AJ_08_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[16];
    un_COARSE_FREQUENCY_09_ARC1.w_FREQUENCY = wBuffer6[17];
    un_FINE_FREQUENCY_AND_AJ_09_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[18];
    un_COARSE_FREQUENCY_10_ARC1.w_FREQUENCY = wBuffer6[19];
    un_FINE_FREQUENCY_AND_AJ_10_ARC1.w_FINE_FREQUENCY_AND_AJ = wBuffer6[20];

    un_AIU_FAULT_DATA1.w_AIU_FAULT_DATA = wBuffer32[0];
    un_AIU_FAULT_DATA2.w_AIU_FAULT_DATA = wBuffer32[1];
    un_ICS_SW_ID1.w_ICS_SW_ID = wBuffer32[2];
    un_ICS_SW_ID2.w_ICS_SW_ID = wBuffer32[3];
    un_ICS_SW_ID3.w_ICS_SW_ID = wBuffer32[4];
    un_ICP1_STATUS.w_ICP_STATUS = wBuffer32[5];
    un_ICP2_STATUS.w_ICP_STATUS = wBuffer32[6];
    un_ICP3_STATUS.w_ICP_STATUS = wBuffer32[7];
    un_ICP4_STATUS.w_ICP_STATUS = wBuffer32[8];
    un_ICP5_STATUS.w_ICP_STATUS = wBuffer32[9];

    un_AIU_STATUS.w_AIU_STATUS = wBuffer33[0];
    un_AIU_NO_NAME.w_AIU_NO_NAME = wBuffer33[1];

    CString m_str_state;
    if((WORD)un_PRESET_SELECT_ARC1.st_PRESET_SELECT.ChannelNumber <= 0x63)
        m_str_state.Format(_T("%u"), un_PRESET_SELECT_ARC1.st_PRESET_SELECT.ChannelNumber);
    else if((WORD)un_PRESET_SELECT_ARC1.st_PRESET_SELECT.ChannelNumber == 0x81)
        m_str_state.Format(_T("Hailing"));
    else
        m_str_state.Format(_T("Error %d"), (WORD)un_PRESET_SELECT_ARC1.st_PRESET_SELECT.ChannelNumber);

    m_TEXT_ARC1_CHANNEL.SetWindowTextW(m_str_state);

    /*GUI (Guard, Zeroize) */
    /* Gurard(0111)  = Operation Mode : G */
    /* Zeroize(1111) = Zeroize */
    if(un_PRESET_SELECT_ARC1.st_PRESET_SELECT.MemoryManagement == 0xF)
    {
        ChangeIcon(&m_LED_ARC1_ZEROIZE, 1);
    }
    else if(un_PRESET_SELECT_ARC1.st_PRESET_SELECT.MemoryManagement == 0x7)
    {
        m_str_state.Format(_T("G"));
        m_TEXT_ARC1_OPMODE.SetWindowTextW(m_str_state);
    }

    if(un_MODE_AND_GUARD_ARC1.st_MODE_AND_GUARD.Modulation ==0x0)
    {
        m_str_state.Format(_T("Default"));
        m_TEXT_ARC1_MODULATION.SetWindowTextW(m_str_state);
    }
    else if(un_MODE_AND_GUARD_ARC1.st_MODE_AND_GUARD.Modulation ==0x1)
    {
        m_str_state.Format(_T("AM"));
        m_TEXT_ARC1_MODULATION.SetWindowTextW(m_str_state);
    }
    else if(un_MODE_AND_GUARD_ARC1.st_MODE_AND_GUARD.Modulation ==0x2)
    {
        m_str_state.Format(_T("FM"));
        m_TEXT_ARC1_MODULATION.SetWindowTextW(m_str_state);
    }

    if(un_MODE_AND_GUARD_ARC1.st_MODE_AND_GUARD.ADF ==0x1)
    {
        ChangeIcon(&m_LED_ARC1_ADF, 1);
    }
    else
    {
        ChangeIcon(&m_LED_ARC1_ADF, 2);
    }

    if(un_MODE_AND_GUARD_ARC1.st_MODE_AND_GUARD.XMode ==0x1)
    {
        ChangeIcon(&m_LED_ARC1_XMODE, 1);
    }
    else
    {
        ChangeIcon(&m_LED_ARC1_XMODE, 2);
    }

    if(un_PRESET_SELECT_ARC1.st_PRESET_SELECT.MemoryManagement ==0x7)
    {
        m_str_state.Format(_T("G"));
        m_TEXT_ARC1_OPMODE.SetWindowTextW(m_str_state);
    }
    else if(un_MODE_AND_GUARD_ARC1.st_MODE_AND_GUARD.GuardReceiver ==0x1)
    {
        m_str_state.Format(_T("T/R+G"));
        m_TEXT_ARC1_OPMODE.SetWindowTextW(m_str_state);
    }
    else if(un_MODE_AND_GUARD_ARC1.st_MODE_AND_GUARD.GuardReceiver ==0x0)
    {
        m_str_state.Format(_T("T/R"));
        m_TEXT_ARC1_OPMODE.SetWindowTextW(m_str_state);
    }

    m_str_state = NumToString(un_FREQUENCY_ARC1.st_FREQUENCY.HundredsDigit, un_FREQUENCY_ARC1.st_FREQUENCY.TensDigit, un_FREQUENCY_ARC1.st_FREQUENCY.OnesDigit, un_FREQUENCY_ARC1.st_FREQUENCY.TenthsDigit, un_FINE_FREQUENCY_AND_AJ_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit, un_FINE_FREQUENCY_AND_AJ_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit);
    m_TEXT_ARC1_FREQ.SetWindowTextW(m_str_state);

    if(un_FINE_FREQUENCY_AND_AJ_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        m_str_state.Format(_T("Active"));
        m_TEXT_ARC1_FREQ_MNGMT.SetWindowTextW(m_str_state);
    }
    else if(un_FINE_FREQUENCY_AND_AJ_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        m_str_state.Format(_T("Fixed"));
        m_TEXT_ARC1_FREQ_MNGMT.SetWindowTextW(m_str_state);
    }

    if(un_OPTIONS_ARC1.st_OPTIONS.CompressorOption ==0x1)
    {
        ChangeIcon(&m_LED_ARC1_COMPRESSOR, 1);
    }
    else
    {
        ChangeIcon(&m_LED_ARC1_COMPRESSOR, 2);
    }

    if(un_OPTIONS_ARC1.st_OPTIONS.MainSquelch ==0x1)
    {
        ChangeIcon(&m_LED_ARC1_MAINSQUELCH, 2);
    }
    else
    {
        ChangeIcon(&m_LED_ARC1_MAINSQUELCH, 1);
    }

    if(un_OPTIONS_ARC1.st_OPTIONS.GuardSquelch ==0x1)
    {
        ChangeIcon(&m_LED_ARC1_GUARD_SQUELCH, 2);
    }
    else
    {
        ChangeIcon(&m_LED_ARC1_GUARD_SQUELCH, 1);
    }

    if(un_OPTIONS_ARC1.st_OPTIONS.ToneKey ==0x1)
    {
        ChangeIcon(&m_LED_ARC1_TONEKEY, 1);
    }
    else
    {
        ChangeIcon(&m_LED_ARC1_TONEKEY, 2);
    }

    if(un_OPTIONS_ARC1.st_OPTIONS.RFPower == 0x0)
    {
        m_str_state.Format(_T("High Power"));
        m_TEXT_ARC1_RFPOWER.SetWindowTextW(m_str_state);
    }
    else if(un_OPTIONS_ARC1.st_OPTIONS.RFPower == 0x1)
    {
        m_str_state.Format(_T("Medium Power"));
        m_TEXT_ARC1_RFPOWER.SetWindowTextW(m_str_state);
    }
    else if(un_OPTIONS_ARC1.st_OPTIONS.RFPower == 0x2)
    {
        m_str_state.Format(_T("Low Power"));
        m_TEXT_ARC1_RFPOWER.SetWindowTextW(m_str_state);
    }

    switch(un_TOD_STATUS_ARC1.st_TOD_MANAGEMENT.TODManagement)
    {
    case(0x0):
        m_str_state.Format(_T("No TOD"));
        break;
    case(0x1):
        m_str_state.Format(_T("TOD Valid"));
        break;
    case(0x2):
        m_str_state.Format(_T("TOD Xmit"));
        break;
    case(0x5):
        m_str_state.Format(_T("TOD Rec."));
        break;
    case(0x6):
        m_str_state.Format(_T("TOD Send"));
        break;
    case(0x8):
        m_str_state.Format(_T("Day Set"));
        break;
    case(0xA):
        m_str_state.Format(_T("Emer. Start"));
        break;
    case(0xB):
        m_str_state.Format(_T("Emer. wDay"));
        break;
    default:
        m_str_state.Format(_T("잘못된 값"));
        break;
    }
    m_TEXT_ARC1_TOD_STAT.SetWindowTextW(m_str_state);

    m_str_state.Format(_T("%d%d"), un_TOD_STATUS_ARC1.st_TOD_MANAGEMENT.DayTensDigit, un_TOD_STATUS_ARC1.st_TOD_MANAGEMENT.DayOnesDigit);
    m_TEXT_ARC1_TOD_DAY.SetWindowTextW(m_str_state);

    //if(un_SOFTWARE_ID_ARC1.st_SOFTWARE_ID.CodeType == 0x0)
    //{
    //    m_str_state.Format(_T("Controlled"));
    //    m_TEXT_ARC1_FREQ_MNGMT.SetWindowTextW(m_str_state);
    //}
    //else if(un_SOFTWARE_ID_ARC1.st_SOFTWARE_ID.CodeType == 0x1)
    //{
    //    m_str_state.Format(_T("Engineering"));
    //    m_TEXT_ARC1_FREQ_MNGMT.SetWindowTextW(m_str_state);
    //}

    m_str_state.Format(_T("%X%X"), un_SOFTWARE_ID_ARC1.st_SOFTWARE_ID.SoftwareRadioIdent / 10, un_SOFTWARE_ID_ARC1.st_SOFTWARE_ID.SoftwareRadioIdent % 10);
    m_TEXT_ARC1_SWID.SetWindowTextW(m_str_state);

    m_str_state.Format(_T("%d.%d"), un_SOFTWARE_VERSION_ARC1.st_SOFTWARE_VERSION.SoftwareVersion, un_SOFTWARE_VERSION_ARC1.st_SOFTWARE_VERSION.SoftwareReversion);
    m_TEXT_ARC1_SWVER.SetWindowTextW(m_str_state);

    if(un_FMT_NET_LOAD_STATUS_ARC1.st_FMT_NET_LOAD_STATUS.FreqLimits == 0x0)
    {
        ChangeIcon(&m_LED_ARC1_FMT_VALID, 1);
    }
    else if(un_OPTIONS_ARC1.st_OPTIONS.RFPower == 0x1)
    {
        ChangeIcon(&m_LED_ARC1_FMT_VALID, 0);
    }

    if(un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.ControlData == 0x0)
    {
        ChangeIcon(&m_LED_ARC1_CONTROL_DATA, 1);
    }
    else if(un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.ControlData == 0x1)
    {
        ChangeIcon(&m_LED_ARC1_CONTROL_DATA, 0);
    }

    ///* 무전기2 */
    //str_log_1553B.Format(_T("  1] %04X %04X %04X %04X %04X %04X %04X\r\n"), wBuffer1[0], wBuffer1[1], wBuffer1[2], wBuffer1[3], wBuffer1[4], wBuffer1[5], wBuffer1[6]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("  5] %04X %04X\r\n"), wBuffer2[0], wBuffer2[1]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("29] %04X %04X %04X %04X %04X %04X\r\n"), wBuffer3[0], wBuffer3[1], wBuffer3[2], wBuffer3[3], wBuffer3[4], wBuffer3[5]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("  2] %04X %04X %04X %04X\r\n"), wBuffer4[0], wBuffer4[1], wBuffer4[2], wBuffer4[3]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("  3] %04X\r\n"), wBuffer5[0]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("  7] %04X %04X %04X %04X %04X %04X %04X\r\n"), wBuffer6[0], wBuffer6[1], wBuffer6[2], wBuffer6[3], wBuffer6[4], wBuffer6[5], wBuffer6[6]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("       %04X %04X %04X %04X %04X %04X %04X\r\n"), wBuffer6[7], wBuffer6[8], wBuffer6[9], wBuffer6[10], wBuffer6[11], wBuffer6[12], wBuffer6[13]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    //str_log_1553B.Format(_T("       %04X %04X %04X %04X %04X %04X %04X\r\n\r\n"), wBuffer6[14], wBuffer6[15], wBuffer6[16], wBuffer6[17], wBuffer6[18], wBuffer6[19], wBuffer6[20]);
    //n_Length = m_EditLog.GetWindowTextLengthW();
    //m_EditLog.SetSel(n_Length, n_Length);
    //m_EditLog.ReplaceSel(str_log_1553B);

    un_PRESET_SELECT_ARC2.w_PRESET_SELECT = wBuffer41[0];
    un_MODE_AND_GUARD_ARC2.w_MODE_AND_GUARD = wBuffer41[1];
    un_MARITIME_CHANNEL_ARC2.w_MARITIME_CHANNEL = wBuffer41[2];
    un_FREQUENCY_ARC2.w_FREQUENCY = wBuffer41[3];
    un_FINE_FREQUENCY_AND_AJ_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer41[4];
    un_OPTIONS_ARC2.w_OPTIONS = wBuffer41[5];

    un_TOD_STATUS_ARC2.w_TOD_MANAGEMENT = wBuffer42[0];
    un_TOD_RESERVED_ARC2.w_RESERVED = wBuffer42[1];

    un_BIT_SUMMARY_ARC2.w_BIT_SUMMARY = wBuffer43[0];
    un_SOFTWARE_ID_ARC2.w_SOFTWARE_ID = wBuffer43[1];
    un_SOFTWARE_VERSION_ARC2.w_SOFTWARE_VERSION = wBuffer43[2];
    un_FAULT_LOCATION01_ARC2.w_FAULT_LOCATION01 = wBuffer43[4];
    un_FAULT_LOCATION02_ARC2.w_FAULT_LOCATION01 = wBuffer43[5];

    //un_MWOD_LOAD_STATUS_ARC2.w_MWOD_LOAD_STATUS = wBuffer44[0];
    //un_MWOD_1_AND_2_DAY_ARC2.w_MWOD_A_AND_B_DAY = wBuffer44[1];
    //un_MWOD_3_AND_4_DAY_ARC2.w_MWOD_A_AND_B_DAY = wBuffer44[2];
    //un_MWOD_5_AND_6_DAY_ARC2.w_MWOD_A_AND_B_DAY = wBuffer44[3];

    un_FMT_NET_LOAD_STATUS_ARC2.w_FMT_NET_LOAD_STATUS = wBuffer45[4];

    un_PRESET_GROUP_SELECT_ARC2.w_PRESET_GROUP_SELECT = wBuffer4[0];
    un_COARSE_FREQUENCY_01_ARC2.w_FREQUENCY = wBuffer4[1];
    un_FINE_FREQUENCY_AND_AJ_01_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[2];
    un_COARSE_FREQUENCY_02_ARC2.w_FREQUENCY = wBuffer4[3];
    un_FINE_FREQUENCY_AND_AJ_02_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[4];
    un_COARSE_FREQUENCY_03_ARC2.w_FREQUENCY = wBuffer4[5];
    un_FINE_FREQUENCY_AND_AJ_03_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[6];
    un_COARSE_FREQUENCY_04_ARC2.w_FREQUENCY = wBuffer4[7];
    un_FINE_FREQUENCY_AND_AJ_04_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[8];
    un_COARSE_FREQUENCY_05_ARC2.w_FREQUENCY = wBuffer4[9];
    un_FINE_FREQUENCY_AND_AJ_05_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[10];
    un_COARSE_FREQUENCY_06_ARC2.w_FREQUENCY = wBuffer4[11];
    un_FINE_FREQUENCY_AND_AJ_06_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[12];
    un_COARSE_FREQUENCY_07_ARC2.w_FREQUENCY = wBuffer4[13];
    un_FINE_FREQUENCY_AND_AJ_07_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[14];
    un_COARSE_FREQUENCY_08_ARC2.w_FREQUENCY = wBuffer4[15];
    un_FINE_FREQUENCY_AND_AJ_08_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[16];
    un_COARSE_FREQUENCY_09_ARC2.w_FREQUENCY = wBuffer4[17];
    un_FINE_FREQUENCY_AND_AJ_09_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[18];
    un_COARSE_FREQUENCY_10_ARC2.w_FREQUENCY = wBuffer4[19];
    un_FINE_FREQUENCY_AND_AJ_10_ARC2.w_FINE_FREQUENCY_AND_AJ = wBuffer4[20];

    m_str_state;
    if((WORD)un_PRESET_SELECT_ARC2.st_PRESET_SELECT.ChannelNumber <= 0x63)
        m_str_state.Format(_T("%u"), un_PRESET_SELECT_ARC2.st_PRESET_SELECT.ChannelNumber);
    else if((WORD)un_PRESET_SELECT_ARC2.st_PRESET_SELECT.ChannelNumber == 0x81)
        m_str_state.Format(_T("Hailing"));
    else
        m_str_state.Format(_T("Error %d"), (WORD)un_PRESET_SELECT_ARC2.st_PRESET_SELECT.ChannelNumber);

    m_TEXT_ARC2_CHANNEL.SetWindowTextW(m_str_state);

    /*GUI (Guard, Zeroize) */
    /* Gurard(0111)  = Operation Mode : G */
    /* Zeroize(1111) = Zeroize */
    if(un_PRESET_SELECT_ARC2.st_PRESET_SELECT.MemoryManagement == 0xF)
    {
        ChangeIcon(&m_LED_ARC2_ZEROIZE, 1);
    }
    else if(un_PRESET_SELECT_ARC2.st_PRESET_SELECT.MemoryManagement == 0x7)
    {
        m_str_state.Format(_T("G"));
        m_TEXT_ARC2_OPMODE.SetWindowTextW(m_str_state);
    }

    if(un_MODE_AND_GUARD_ARC2.st_MODE_AND_GUARD.Modulation ==0x0)
    {
        m_str_state.Format(_T("Default"));
        m_TEXT_ARC2_MODULATION.SetWindowTextW(m_str_state);
    }
    else if(un_MODE_AND_GUARD_ARC2.st_MODE_AND_GUARD.Modulation ==0x1)
    {
        m_str_state.Format(_T("AM"));
        m_TEXT_ARC2_MODULATION.SetWindowTextW(m_str_state);
    }
    else if(un_MODE_AND_GUARD_ARC2.st_MODE_AND_GUARD.Modulation ==0x2)
    {
        m_str_state.Format(_T("FM"));
        m_TEXT_ARC2_MODULATION.SetWindowTextW(m_str_state);
    }

    if(un_MODE_AND_GUARD_ARC2.st_MODE_AND_GUARD.ADF ==0x1)
    {
        ChangeIcon(&m_LED_ARC2_ADF, 1);
    }
    else
    {
        ChangeIcon(&m_LED_ARC2_ADF, 2);
    }

    if(un_MODE_AND_GUARD_ARC2.st_MODE_AND_GUARD.XMode ==0x1)
    {
        ChangeIcon(&m_LED_ARC2_XMODE, 1);
    }
    else
    {
        ChangeIcon(&m_LED_ARC2_XMODE, 2);
    }

    if(un_PRESET_SELECT_ARC2.st_PRESET_SELECT.MemoryManagement ==0x7)
    {
        m_str_state.Format(_T("G"));
        m_TEXT_ARC2_OPMODE.SetWindowTextW(m_str_state);
    }
    else if(un_MODE_AND_GUARD_ARC2.st_MODE_AND_GUARD.GuardReceiver ==0x1)
    {
        m_str_state.Format(_T("T/R+G"));
        m_TEXT_ARC2_OPMODE.SetWindowTextW(m_str_state);
    }
    else if(un_MODE_AND_GUARD_ARC2.st_MODE_AND_GUARD.GuardReceiver ==0x0)
    {
        m_str_state.Format(_T("T/R"));
        m_TEXT_ARC2_OPMODE.SetWindowTextW(m_str_state);
    }

    m_str_state = NumToString(un_FREQUENCY_ARC2.st_FREQUENCY.HundredsDigit, un_FREQUENCY_ARC2.st_FREQUENCY.TensDigit, un_FREQUENCY_ARC2.st_FREQUENCY.OnesDigit, un_FREQUENCY_ARC2.st_FREQUENCY.TenthsDigit, un_FINE_FREQUENCY_AND_AJ_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit, un_FINE_FREQUENCY_AND_AJ_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit);
    m_TEXT_ARC2_FREQ.SetWindowTextW(m_str_state);

    if(un_FINE_FREQUENCY_AND_AJ_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        m_str_state.Format(_T("Active"));
        m_TEXT_ARC2_FREQ_MNGMT.SetWindowTextW(m_str_state);
    }
    else if(un_FINE_FREQUENCY_AND_AJ_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        m_str_state.Format(_T("Fixed"));
        m_TEXT_ARC2_FREQ_MNGMT.SetWindowTextW(m_str_state);
    }

    if(un_OPTIONS_ARC2.st_OPTIONS.CompressorOption ==0x1)
    {
        ChangeIcon(&m_LED_ARC2_COMPRESSOR, 1);
    }
    else
    {
        ChangeIcon(&m_LED_ARC2_COMPRESSOR, 2);
    }

    if(un_OPTIONS_ARC2.st_OPTIONS.MainSquelch ==0x1)
    {
        ChangeIcon(&m_LED_ARC2_MAINSQUELCH, 2);
    }
    else
    {
        ChangeIcon(&m_LED_ARC2_MAINSQUELCH, 1);
    }

    if(un_OPTIONS_ARC2.st_OPTIONS.GuardSquelch ==0x1)
    {
        ChangeIcon(&m_LED_ARC2_GUARD_SQUELCH, 2);
    }
    else
    {
        ChangeIcon(&m_LED_ARC2_GUARD_SQUELCH, 1);
    }

    if(un_OPTIONS_ARC2.st_OPTIONS.ToneKey ==0x1)
    {
        ChangeIcon(&m_LED_ARC2_TONEKEY, 1);
    }
    else
    {
        ChangeIcon(&m_LED_ARC2_TONEKEY, 2);
    }

    if(un_OPTIONS_ARC2.st_OPTIONS.RFPower == 0x0)
    {
        m_str_state.Format(_T("High Power"));
        m_TEXT_ARC2_RFPOWER.SetWindowTextW(m_str_state);
    }
    else if(un_OPTIONS_ARC2.st_OPTIONS.RFPower == 0x1)
    {
        m_str_state.Format(_T("Medium Power"));
        m_TEXT_ARC2_RFPOWER.SetWindowTextW(m_str_state);
    }
    else if(un_OPTIONS_ARC2.st_OPTIONS.RFPower == 0x2)
    {
        m_str_state.Format(_T("Low Power"));
        m_TEXT_ARC2_RFPOWER.SetWindowTextW(m_str_state);
    }

    switch(un_TOD_STATUS_ARC2.st_TOD_MANAGEMENT.TODManagement)
    {
    case(0x0):
        m_str_state.Format(_T("No TOD"));
        break;
    case(0x1):
        m_str_state.Format(_T("TOD Valid"));
        break;
    case(0x2):
        m_str_state.Format(_T("TOD Xmit"));
        break;
    case(0x5):
        m_str_state.Format(_T("TOD Rec."));
        break;
    case(0x6):
        m_str_state.Format(_T("TOD Send"));
        break;
    case(0x8):
        m_str_state.Format(_T("Day Set"));
        break;
    case(0xA):
        m_str_state.Format(_T("Emer. Start"));
        break;
    case(0xB):
        m_str_state.Format(_T("Emer. wDay"));
        break;
    default:
        m_str_state.Format(_T("잘못된 값"));
        break;
    }
    m_TEXT_ARC2_TOD_STAT.SetWindowTextW(m_str_state);

    m_str_state.Format(_T("%d%d"), un_TOD_STATUS_ARC2.st_TOD_MANAGEMENT.DayTensDigit, un_TOD_STATUS_ARC2.st_TOD_MANAGEMENT.DayOnesDigit);
    m_TEXT_ARC2_TOD_DAY.SetWindowTextW(m_str_state);

    //if(un_SOFTWARE_ID_ARC2.st_SOFTWARE_ID.CodeType == 0x0)
    //{
    //    m_str_state.Format(_T("Controlled"));
    //    m_TEXT_ARC2_FREQ_MNGMT.SetWindowTextW(m_str_state);
    //}
    //else if(un_SOFTWARE_ID_ARC2.st_SOFTWARE_ID.CodeType == 0x1)
    //{
    //    m_str_state.Format(_T("Engineering"));
    //    m_TEXT_ARC2_FREQ_MNGMT.SetWindowTextW(m_str_state);
    //}

    m_str_state.Format(_T("%X%X"), un_SOFTWARE_ID_ARC2.st_SOFTWARE_ID.SoftwareRadioIdent / 10, un_SOFTWARE_ID_ARC2.st_SOFTWARE_ID.SoftwareRadioIdent % 10);
    m_TEXT_ARC2_SWID.SetWindowTextW(m_str_state);

    m_str_state.Format(_T("%d.%d"), un_SOFTWARE_VERSION_ARC2.st_SOFTWARE_VERSION.SoftwareVersion, un_SOFTWARE_VERSION_ARC2.st_SOFTWARE_VERSION.SoftwareReversion);
    m_TEXT_ARC2_SWVER.SetWindowTextW(m_str_state);

    if(un_FMT_NET_LOAD_STATUS_ARC2.st_FMT_NET_LOAD_STATUS.FreqLimits == 0x0)
    {
        ChangeIcon(&m_LED_ARC2_FMT_VALID, 1);
    }
    else if(un_OPTIONS_ARC2.st_OPTIONS.RFPower == 0x1)
    {
        ChangeIcon(&m_LED_ARC2_FMT_VALID, 0);
    }

    if(un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.ControlData == 0x0)
    {
        ChangeIcon(&m_LED_ARC2_CONTROL_DATA, 1);
    }
    else if(un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.ControlData == 0x1)
    {
        ChangeIcon(&m_LED_ARC2_CONTROL_DATA, 0);
    }

    m_str_state.Format(_T("%c%c%c%c%c%c"), un_ICS_SW_ID1.st_ICS_SW_ID.SWIDCharacter1, un_ICS_SW_ID1.st_ICS_SW_ID.SWIDCharacter2
        , un_ICS_SW_ID2.st_ICS_SW_ID.SWIDCharacter1, un_ICS_SW_ID2.st_ICS_SW_ID.SWIDCharacter2
        , un_ICS_SW_ID3.st_ICS_SW_ID.SWIDCharacter1, un_ICS_SW_ID3.st_ICS_SW_ID.SWIDCharacter2);
    m_TEXT_AIU_SW_ID.SetWindowTextW(m_str_state);

    // ICP1
    m_str_state.Format(_T(""));

    switch( un_ICP1_STATUS.st_ICP_STATUS.CommunicationMode )
    {
    case 0x0:
        m_str_state.Format(_T("PVT"));
        break;
    case 0x1:
        m_str_state.Format(_T("ICS"));
        break;
    case 0x2:
        m_str_state.Format(_T("COM1"));
        break;
    case 0x3:
        m_str_state.Format(_T("COM2"));
        break;
    case 0x4:
        m_str_state.Format(_T("COM3"));
        break;
    case 0x5:
        m_str_state.Format(_T("COM4"));
        break;
    case 0x6:
        m_str_state.Format(_T("COM5"));
        break;
    case 0x7:
        m_str_state.Format(_T("RMT"));
        break;
    }
    m_TEXT_ICP1ComMode.SetWindowTextW(m_str_state);

    if(un_ICP1_STATUS.st_ICP_STATUS.PTTStatus == 0x0)
    {
        ChangeIcon(&m_LED_ICP1ICSPTT, 2);
        ChangeIcon(&m_LED_ICP1SelectedPTT, 2);
    }
    else if(un_ICP1_STATUS.st_ICP_STATUS.PTTStatus == 0x1)
    {
        ChangeIcon(&m_LED_ICP1ICSPTT, 2);
        ChangeIcon(&m_LED_ICP1SelectedPTT, 1);
    }
    else if(un_ICP1_STATUS.st_ICP_STATUS.PTTStatus == 0x2)
    {
        ChangeIcon(&m_LED_ICP1ICSPTT, 1);
        ChangeIcon(&m_LED_ICP1SelectedPTT, 2);
    }

    m_str_state.Format(_T(""));

    switch( un_ICP1_STATUS.st_ICP_STATUS.SeletedRadioInRMT )
    {
    case 0x0:
        m_str_state.Format(_T("COM1"));
        break;
    case 0x1:
        m_str_state.Format(_T("COM2"));
        break;
    case 0x2:
        m_str_state.Format(_T("COM3"));
        break;
    case 0x3:
        m_str_state.Format(_T("COM4"));
        break;
    }
    m_TEXT_ICP1RadioInRmt.SetWindowTextW(m_str_state);

    m_str_state.Format(_T(""));

    switch( un_ICP1_STATUS.st_ICP_STATUS.VMUMode )
    {
    case 0x0:
        m_str_state.Format(_T("VMU"));
        break;
    case 0x1:
        m_str_state.Format(_T("TEST"));
        break;
    case 0x2:
        m_str_state.Format(_T("INHIBIT"));
        break;
    }
    m_TEXT_ICP1VMUMode.SetWindowTextW(m_str_state);

    // ICP2
    m_str_state.Format(_T(""));

    switch( un_ICP2_STATUS.st_ICP_STATUS.CommunicationMode )
    {
    case 0x0:
        m_str_state.Format(_T("PVT"));
        break;
    case 0x1:
        m_str_state.Format(_T("ICS"));
        break;
    case 0x2:
        m_str_state.Format(_T("COM1"));
        break;
    case 0x3:
        m_str_state.Format(_T("COM2"));
        break;
    case 0x4:
        m_str_state.Format(_T("COM3"));
        break;
    case 0x5:
        m_str_state.Format(_T("COM4"));
        break;
    case 0x6:
        m_str_state.Format(_T("COM5"));
        break;
    case 0x7:
        m_str_state.Format(_T("RMT"));
        break;
    }
    m_TEXT_ICP2ComMode.SetWindowTextW(m_str_state);

    if(un_ICP2_STATUS.st_ICP_STATUS.PTTStatus == 0x0)
    {
        ChangeIcon(&m_LED_ICP2ICSPTT, 2);
        ChangeIcon(&m_LED_ICP2SelectedPTT, 2);
    }
    else if(un_ICP2_STATUS.st_ICP_STATUS.PTTStatus == 0x1)
    {
        ChangeIcon(&m_LED_ICP2ICSPTT, 2);
        ChangeIcon(&m_LED_ICP2SelectedPTT, 1);
    }
    else if(un_ICP2_STATUS.st_ICP_STATUS.PTTStatus == 0x2)
    {
        ChangeIcon(&m_LED_ICP2ICSPTT, 1);
        ChangeIcon(&m_LED_ICP2SelectedPTT, 2);
    }

    m_str_state.Format(_T(""));

    switch( un_ICP2_STATUS.st_ICP_STATUS.SeletedRadioInRMT )
    {
    case 0x0:
        m_str_state.Format(_T("COM1"));
        break;
    case 0x1:
        m_str_state.Format(_T("COM2"));
        break;
    case 0x2:
        m_str_state.Format(_T("COM3"));
        break;
    case 0x3:
        m_str_state.Format(_T("COM4"));
        break;
    }
    m_TEXT_ICP2RadioInRmt.SetWindowTextW(m_str_state);

    m_str_state.Format(_T(""));

    switch( un_ICP2_STATUS.st_ICP_STATUS.VMUMode )
    {
    case 0x0:
        m_str_state.Format(_T("VMU"));
        break;
    case 0x1:
        m_str_state.Format(_T("TEST"));
        break;
    case 0x2:
        m_str_state.Format(_T("INHIBIT"));
        break;
    }
    m_TEXT_ICP2VMUMode.SetWindowTextW(m_str_state);

    // AIU 상태
    if(un_AIU_STATUS.st_AIU_STATUS.BITInProgress == 0x1)
    {
        ChangeIcon(&m_LED_AIIU_BITInProgress, 1);
    }
    else
    {
        ChangeIcon(&m_LED_AIIU_BITInProgress, 2);
    }

    m_str_state.Format(_T(""));

    switch( un_AIU_STATUS.st_AIU_STATUS.CurrentVoiceWarning )
    {
    case 0:
        m_str_state.Format(_T("None"));
        break;
    case 1:
        m_str_state.Format(_T("Low Altitude (RALT)"));
        break;
    case 2:
        m_str_state.Format(_T("Low Altitude (Baro)"));
        break;
    case 3:
        m_str_state.Format(_T("No.1 Engine Fire"));
        break;
    case 4:
        m_str_state.Format(_T("No.2 Engine Fire"));
        break;
    case 5:
        m_str_state.Format(_T("APU Fire"));
        break;
    case 6:
        m_str_state.Format(_T("MGB Fire"));
        break;
    case 7:
        m_str_state.Format(_T("No.1 Engine Out"));
        break;
    case 8:
        m_str_state.Format(_T("No.2 Engine Out"));
        break;
    case 9:
        m_str_state.Format(_T("Low RPM"));
        break;
    case 10:
        m_str_state.Format(_T("Dispense Ready"));
        break;
    case 11:
        m_str_state.Format(_T("MWR Threat"));
        break;
    case 12:
        m_str_state.Format(_T("RWR Gun Launch"));
        break;
    case 13:
        m_str_state.Format(_T("RWR Gun Lock-on"));
        break;
    case 14:
        m_str_state.Format(_T("RWR Gun Track"));
        break;
    case 15:
        m_str_state.Format(_T("LWR Laser Beam"));
        break;
    case 16:
        m_str_state.Format(_T("LWR Laser Designation"));
        break;
    case 17:
        m_str_state.Format(_T("LWR Laser Range"));
        break;
    case 18:
        m_str_state.Format(_T("LWR Laser Unknown"));
        break;
    case 19:
        m_str_state.Format(_T("RWR Helicopter Launch"));
        break;
    case 20:
        m_str_state.Format(_T("RWR Fixed Wing Launch"));
        break;
    case 21:
        m_str_state.Format(_T("RWR Radar Launch"));
        break;
    case 22:
        m_str_state.Format(_T("RWR Helicopter Lock-on"));
        break;
    case 23:
        m_str_state.Format(_T("RWR Fixed Wing Lock-on"));
        break;
    case 24:
        m_str_state.Format(_T("RWR Radar Lock-on"));
        break;
    case 25:
        m_str_state.Format(_T("RWR Helicopter Track"));
        break;
    case 26:
        m_str_state.Format(_T("RWR Fixed Wing Track"));
        break;
    case 27:
        m_str_state.Format(_T("RWR Radar Track"));
        break;
    case 28:
        m_str_state.Format(_T("RWR Radar Unknown"));
        break;
    case 29:
        m_str_state.Format(_T("RWR Gun Search"));
        break;
    case 30:
        m_str_state.Format(_T("RWR Helicopter Search"));
        break;
    case 31:
        m_str_state.Format(_T("RWR Fixed Wing Search"));
        break;
    case 32:
        m_str_state.Format(_T("RWR Radar Search"));
        break;
    case 33:
        m_str_state.Format(_T("RWR Radar"));
        break;
    case 34:
        m_str_state.Format(_T("Flare Out"));
        break;
    case 35:
        m_str_state.Format(_T("Chaff Out"));
        break;
    case 36:
        m_str_state.Format(_T("Other1 Out"));
        break;
    case 37:
        m_str_state.Format(_T("Other2 Out"));
        break;
    case 38:
        m_str_state.Format(_T("Flare Low"));
        break;
    case 39:
        m_str_state.Format(_T("Chaff Low"));
        break;
    case 40:
        m_str_state.Format(_T("Other1 Low"));
        break;
    case 41:
        m_str_state.Format(_T("Other2 Low"));
        break;
    case 42:
        m_str_state.Format(_T("Air Speed"));
        break;
    case 43:
        m_str_state.Format(_T("Caution (By CWP)"));
        break;
    case 44:
        m_str_state.Format(_T("Return Fuel Warning"));
        break;
    case 45:
        m_str_state.Format(_T("Mission Fuel Warning"));
        break;
    case 46:
        m_str_state.Format(_T("Stall"));
        break;
    default:
        m_str_state.Format(_T(" "));
        break;
    }
    m_TEXT_AIU_CurrentWarning.SetWindowTextW(m_str_state);

    if(un_AIU_STATUS.st_AIU_STATUS.WeightOnWheelState == 0x1)
    {
        ChangeIcon(&m_LED_AIU_WowOn, 1);
    }
    else
    {
        ChangeIcon(&m_LED_AIU_WowOn, 2);
    }

    m_str_state.Format(_T(""));

    switch( un_AIU_NO_NAME.st_AIU_NO_NAME.COMSECInterfaceControl )
    {
    case 0:
        m_str_state.Format(_T("COMSEC 미연동"));
        break;
    case 1:
        m_str_state.Format(_T("COMSEC-COM2 연동"));
        break;
    case 2:
        m_str_state.Format(_T("COMSEC-COM3 연동"));
        break;
    }
    m_TEXT_AIU_COMSECInterface.SetWindowTextW(m_str_state);

    return 0;
}


void CITC_GUI_01Dlg::OnBnClickedBtnIcsBit()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


CString CITC_GUI_01Dlg::NumToString(U16BIT Hundreds, U16BIT Tens, U16BIT Ones, U16BIT Tenths, U16BIT Hundredths, U16BIT Thousandths)
{
    CString str;

    str.Format(_T("%X%X%X.%X%X%X"), Hundreds, Tens, Ones, Tenths, Hundredths, Thousandths);

    return str;
}



BOOL CITC_GUI_01Dlg::PreTranslateMessage(MSG* pMsg)
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


void CITC_GUI_01Dlg::PostNcDestroy()
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    delete this;
    CDialogEx::PostNcDestroy();
}


afx_msg LRESULT CITC_GUI_01Dlg::OnUwmRdyIcsDis(WPARAM wParam, LPARAM lParam)
{
    f_SET_DIS = TRUE;
    // AddEventString(_T("> Recved UWM_RDY_ICS_DIS\r\n"));
    return 0;
}


afx_msg LRESULT CITC_GUI_01Dlg::OnUwmSaveArc1Mwod(WPARAM wParam, LPARAM lParam)
{
    p_CSET_ARC1->CheckARC1Setting();

    MSG_FUNCTION_CONTROL_ARC1[0] = p_CSET_ARC1->un_PRESET_SELECT.w_PRESET_SELECT;
    MSG_FUNCTION_CONTROL_ARC1[1] = p_CSET_ARC1->un_MODE_AND_GUARD.w_MODE_AND_GUARD;
    MSG_FUNCTION_CONTROL_ARC1[2] = p_CSET_ARC1->un_MARITIME_CHANNEL.w_MARITIME_CHANNEL;
    MSG_FUNCTION_CONTROL_ARC1[3] = p_CSET_ARC1->un_COARSE_FREQUENCY.w_FREQUENCY;
    MSG_FUNCTION_CONTROL_ARC1[4] = p_CSET_ARC1->un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ;
    p_CSET_ARC1->un_OPTIONS.st_OPTIONS.WODData = 0x0;
    MSG_FUNCTION_CONTROL_ARC1[5] = p_CSET_ARC1->un_OPTIONS.w_OPTIONS;
    MSG_FUNCTION_CONTROL_ARC1[6] = p_CSET_ARC1->un_RESERVED_CONTROL.w_RESERVED_CONTROL;

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG17,               /* Message ID to create             */
        DBLK17,              /* Data Block ID                    */
        RT1_ADDR,                  /* RT address                       */
        01,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_FUNCTION_CONTROL_ARC1);               /* Data words for the async message */

    CString str;

    str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
        , MSG_FUNCTION_CONTROL_ARC1[0], MSG_FUNCTION_CONTROL_ARC1[1], MSG_FUNCTION_CONTROL_ARC1[2], MSG_FUNCTION_CONTROL_ARC1[3], MSG_FUNCTION_CONTROL_ARC1[4]
    , MSG_FUNCTION_CONTROL_ARC1[5], MSG_FUNCTION_CONTROL_ARC1[6]);

    int n_Length = m_EditLog.GetWindowTextLengthW();
    m_EditLog.SetSel(n_Length, n_Length);
    m_EditLog.ReplaceSel(str);

    aceBCDataBlkWrite(DevNum, DBLK17, MSG_FUNCTION_CONTROL_ARC1, 7, 0);

    wResult = aceBCSendAsyncMsgHP(DevNum, MSG17, wFrmTime);

    if(wResult < 0)
        AfxMessageBox(_T("aceBCSendAsyncMsgHP 에러!\r\n"));
    else
        AddEventString(_T("aceBCSendAsyncMsgHP 성공!\r\n"));

    SetTimer(MWOD_LOAD, 1000, NULL);

    return 0;
}


afx_msg LRESULT CITC_GUI_01Dlg::OnUwmSaveArc1Fmt(WPARAM wParam, LPARAM lParam)
{
    p_CSET_ARC1->CheckARC1Setting();

    MSG_FUNCTION_CONTROL_ARC1[0] = p_CSET_ARC1->un_PRESET_SELECT.w_PRESET_SELECT;
    MSG_FUNCTION_CONTROL_ARC1[1] = p_CSET_ARC1->un_MODE_AND_GUARD.w_MODE_AND_GUARD;
    MSG_FUNCTION_CONTROL_ARC1[2] = p_CSET_ARC1->un_MARITIME_CHANNEL.w_MARITIME_CHANNEL;
    MSG_FUNCTION_CONTROL_ARC1[3] = p_CSET_ARC1->un_COARSE_FREQUENCY.w_FREQUENCY;
    MSG_FUNCTION_CONTROL_ARC1[4] = p_CSET_ARC1->un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ;
    p_CSET_ARC1->un_OPTIONS.st_OPTIONS.FMTData = 0x0;
    MSG_FUNCTION_CONTROL_ARC1[5] = p_CSET_ARC1->un_OPTIONS.w_OPTIONS;
    MSG_FUNCTION_CONTROL_ARC1[6] = p_CSET_ARC1->un_RESERVED_CONTROL.w_RESERVED_CONTROL;

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG17,               /* Message ID to create             */
        DBLK17,              /* Data Block ID                    */
        RT1_ADDR,                  /* RT address                       */
        01,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_FUNCTION_CONTROL_ARC1);          /* Data words for the async message */

    aceBCDataBlkWrite(DevNum, DBLK17, MSG_FUNCTION_CONTROL_ARC1, 7, 0);

    aceBCSendAsyncMsgHP(DevNum, MSG17, wFrmTime);

    CString str;

    str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
        , MSG_FUNCTION_CONTROL_ARC1[0], MSG_FUNCTION_CONTROL_ARC1[1], MSG_FUNCTION_CONTROL_ARC1[2], MSG_FUNCTION_CONTROL_ARC1[3], MSG_FUNCTION_CONTROL_ARC1[4]
    , MSG_FUNCTION_CONTROL_ARC1[5], MSG_FUNCTION_CONTROL_ARC1[6]);

    int n_Length = m_EditLog.GetWindowTextLengthW();
    m_EditLog.SetSel(n_Length, n_Length);
    m_EditLog.ReplaceSel(str);

    SetTimer(FMT_NET_LOAD, 1000, NULL);

    return 0;
}


afx_msg LRESULT CITC_GUI_01Dlg::OnUwmSaveArc1Preset(WPARAM wParam, LPARAM lParam)
{
    p_CSET_ARC1->CheckARC1Setting();

    MSG_FUNCTION_CONTROL_ARC1[0] = p_CSET_ARC1->un_PRESET_SELECT.w_PRESET_SELECT;
    MSG_FUNCTION_CONTROL_ARC1[1] = p_CSET_ARC1->un_MODE_AND_GUARD.w_MODE_AND_GUARD;
    MSG_FUNCTION_CONTROL_ARC1[2] = p_CSET_ARC1->un_MARITIME_CHANNEL.w_MARITIME_CHANNEL;
    MSG_FUNCTION_CONTROL_ARC1[3] = p_CSET_ARC1->un_COARSE_FREQUENCY.w_FREQUENCY;
    MSG_FUNCTION_CONTROL_ARC1[4] = p_CSET_ARC1->un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ;
    p_CSET_ARC1->un_OPTIONS.st_OPTIONS.PresetData = 0x0;
    MSG_FUNCTION_CONTROL_ARC1[5] = p_CSET_ARC1->un_OPTIONS.w_OPTIONS;
    MSG_FUNCTION_CONTROL_ARC1[6] = p_CSET_ARC1->un_RESERVED_CONTROL.w_RESERVED_CONTROL;

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG17,               /* Message ID to create             */
        DBLK17,              /* Data Block ID                    */
        RT1_ADDR,                  /* RT address                       */
        01,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_FUNCTION_CONTROL_ARC1);          /* Data words for the async message */

    aceBCDataBlkWrite(DevNum, DBLK17, MSG_FUNCTION_CONTROL_ARC1, 7, 0);

    aceBCSendAsyncMsgHP(DevNum, MSG17, wFrmTime);

    CString str;

    str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
        , MSG_FUNCTION_CONTROL_ARC1[0], MSG_FUNCTION_CONTROL_ARC1[1], MSG_FUNCTION_CONTROL_ARC1[2], MSG_FUNCTION_CONTROL_ARC1[3], MSG_FUNCTION_CONTROL_ARC1[4]
    , MSG_FUNCTION_CONTROL_ARC1[5], MSG_FUNCTION_CONTROL_ARC1[6]);

    int n_Length = m_EditLog.GetWindowTextLengthW();
    m_EditLog.SetSel(n_Length, n_Length);
    m_EditLog.ReplaceSel(str);

    SetTimer(PRESET_LOAD, 1000, NULL);

    return 0;
}


afx_msg LRESULT CITC_GUI_01Dlg::OnUwmSaveArc2Mwod(WPARAM wParam, LPARAM lParam)
{
    p_CSET_ARC2->CheckARC2Setting();

    MSG_FUNCTION_CONTROL_ARC2[0] = p_CSET_ARC2->un_PRESET_SELECT.w_PRESET_SELECT;
    MSG_FUNCTION_CONTROL_ARC2[1] = p_CSET_ARC2->un_MODE_AND_GUARD.w_MODE_AND_GUARD;
    MSG_FUNCTION_CONTROL_ARC2[2] = p_CSET_ARC2->un_MARITIME_CHANNEL.w_MARITIME_CHANNEL;
    MSG_FUNCTION_CONTROL_ARC2[3] = p_CSET_ARC2->un_COARSE_FREQUENCY.w_FREQUENCY;
    MSG_FUNCTION_CONTROL_ARC2[4] = p_CSET_ARC2->un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ;
    p_CSET_ARC2->un_OPTIONS.st_OPTIONS.WODData = 0x0;
    MSG_FUNCTION_CONTROL_ARC2[5] = p_CSET_ARC2->un_OPTIONS.w_OPTIONS;
    MSG_FUNCTION_CONTROL_ARC2[6] = p_CSET_ARC2->un_RESERVED_CONTROL.w_RESERVED_CONTROL;

    CString str;

    str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
        , MSG_FUNCTION_CONTROL_ARC2[0], MSG_FUNCTION_CONTROL_ARC2[1], MSG_FUNCTION_CONTROL_ARC2[2], MSG_FUNCTION_CONTROL_ARC2[3], MSG_FUNCTION_CONTROL_ARC2[4]
    , MSG_FUNCTION_CONTROL_ARC2[5], MSG_FUNCTION_CONTROL_ARC2[6]);

    int n_Length = m_EditLog.GetWindowTextLengthW();
    m_EditLog.SetSel(n_Length, n_Length);
    m_EditLog.ReplaceSel(str);

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG27,               /* Message ID to create             */
        DBLK27,              /* Data Block ID                    */
        RT2_ADDR,                  /* RT address                       */
        01,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_FUNCTION_CONTROL_ARC2);          /* Data words for the async message */

    aceBCDataBlkWrite(DevNum, DBLK27, MSG_FUNCTION_CONTROL_ARC2, 7, 0);

    wResult = aceBCSendAsyncMsgHP(DevNum, MSG27, wFrmTime);

    if(wResult < 0)
        AfxMessageBox(_T("aceBCSendAsyncMsgHP 에러!\r\n"));
    else
        AddEventString(_T("aceBCSendAsyncMsgHP 성공!\r\n"));

    SetTimer(MWOD_LOAD_2, 1000, NULL);

    return 0;
}


afx_msg LRESULT CITC_GUI_01Dlg::OnUwmSaveArc2Fmt(WPARAM wParam, LPARAM lParam)
{
    p_CSET_ARC2->CheckARC2Setting();

    MSG_FUNCTION_CONTROL_ARC2[0] = p_CSET_ARC2->un_PRESET_SELECT.w_PRESET_SELECT;
    MSG_FUNCTION_CONTROL_ARC2[1] = p_CSET_ARC2->un_MODE_AND_GUARD.w_MODE_AND_GUARD;
    MSG_FUNCTION_CONTROL_ARC2[2] = p_CSET_ARC2->un_MARITIME_CHANNEL.w_MARITIME_CHANNEL;
    MSG_FUNCTION_CONTROL_ARC2[3] = p_CSET_ARC2->un_COARSE_FREQUENCY.w_FREQUENCY;
    MSG_FUNCTION_CONTROL_ARC2[4] = p_CSET_ARC2->un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ;
    p_CSET_ARC2->un_OPTIONS.st_OPTIONS.FMTData = 0x0;
    MSG_FUNCTION_CONTROL_ARC2[5] = p_CSET_ARC2->un_OPTIONS.w_OPTIONS;
    MSG_FUNCTION_CONTROL_ARC2[6] = p_CSET_ARC2->un_RESERVED_CONTROL.w_RESERVED_CONTROL;

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG27,               /* Message ID to create             */
        DBLK27,              /* Data Block ID                    */
        RT2_ADDR,                  /* RT address                       */
        01,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_FUNCTION_CONTROL_ARC2);          /* Data words for the async message */

    aceBCDataBlkWrite(DevNum, DBLK27, MSG_FUNCTION_CONTROL_ARC2, 7, 0);

    aceBCSendAsyncMsgHP(DevNum, MSG27, wFrmTime);

    CString str;

    str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
        , MSG_FUNCTION_CONTROL_ARC2[0], MSG_FUNCTION_CONTROL_ARC2[1], MSG_FUNCTION_CONTROL_ARC2[2], MSG_FUNCTION_CONTROL_ARC2[3], MSG_FUNCTION_CONTROL_ARC2[4]
    , MSG_FUNCTION_CONTROL_ARC2[5], MSG_FUNCTION_CONTROL_ARC2[6]);

    int n_Length = m_EditLog.GetWindowTextLengthW();
    m_EditLog.SetSel(n_Length, n_Length);
    m_EditLog.ReplaceSel(str);

    SetTimer(FMT_NET_LOAD_2, 1000, NULL);

    return 0;
}


afx_msg LRESULT CITC_GUI_01Dlg::OnUwmSaveArc2Preset(WPARAM wParam, LPARAM lParam)
{
    p_CSET_ARC2->CheckARC2Setting();

    MSG_FUNCTION_CONTROL_ARC2[0] = p_CSET_ARC2->un_PRESET_SELECT.w_PRESET_SELECT;
    MSG_FUNCTION_CONTROL_ARC2[1] = p_CSET_ARC2->un_MODE_AND_GUARD.w_MODE_AND_GUARD;
    MSG_FUNCTION_CONTROL_ARC2[2] = p_CSET_ARC2->un_MARITIME_CHANNEL.w_MARITIME_CHANNEL;
    MSG_FUNCTION_CONTROL_ARC2[3] = p_CSET_ARC2->un_COARSE_FREQUENCY.w_FREQUENCY;
    MSG_FUNCTION_CONTROL_ARC2[4] = p_CSET_ARC2->un_FINE_FREQUENCY_AND_AJ.w_FINE_FREQUENCY_AND_AJ;
    p_CSET_ARC2->un_OPTIONS.st_OPTIONS.PresetData = 0x0;
    MSG_FUNCTION_CONTROL_ARC2[5] = p_CSET_ARC2->un_OPTIONS.w_OPTIONS;
    MSG_FUNCTION_CONTROL_ARC2[6] = p_CSET_ARC2->un_RESERVED_CONTROL.w_RESERVED_CONTROL;

    aceBCAsyncMsgCreateBCtoRT(
        DevNum,             /* Device number                    */
        MSG27,               /* Message ID to create             */
        DBLK27,              /* Data Block ID                    */
        RT2_ADDR,                  /* RT address                       */
        01,                  /* RT subaddress                    */ // subaddress : 02 (MWOD Load)
        7,                  /* Word Count                       */
        0,                  /* Devault Message Timer            */
        ACE_BCCTRL_CHL_A,   /* use chl A options                */
        MSG_FUNCTION_CONTROL_ARC2);          /* Data words for the async message */

    aceBCDataBlkWrite(DevNum, DBLK27, MSG_FUNCTION_CONTROL_ARC2, 7, 0);

    aceBCSendAsyncMsgHP(DevNum, MSG27, wFrmTime);

    CString str;

    str.Format(L"MainDlg> %04X %04X %04X %04X %04X %04X %04X\r\n"
        , MSG_FUNCTION_CONTROL_ARC2[0], MSG_FUNCTION_CONTROL_ARC2[1], MSG_FUNCTION_CONTROL_ARC2[2], MSG_FUNCTION_CONTROL_ARC2[3], MSG_FUNCTION_CONTROL_ARC2[4]
    , MSG_FUNCTION_CONTROL_ARC2[5], MSG_FUNCTION_CONTROL_ARC2[6]);

    int n_Length = m_EditLog.GetWindowTextLengthW();
    m_EditLog.SetSel(n_Length, n_Length);
    m_EditLog.ReplaceSel(str);

    SetTimer(PRESET_LOAD_2, 1000, NULL);

    return 0;
}
