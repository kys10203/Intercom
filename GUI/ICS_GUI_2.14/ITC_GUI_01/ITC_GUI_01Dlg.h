
// ITC_GUI_01Dlg.h : 헤더 파일
//
#define UWM_ICS_DIS (WM_USER+1)
#define UWM_DP_ICS_DIS (WM_USER+2)
#define UWM_RDY_ICS_DIS (WM_USER+3)

#define UWM_SAVE_ARC1_MWOD (WM_USER+5)
#define UWM_SAVE_ARC1_FMT (WM_USER+6)
#define UWM_SAVE_ARC1_PRESET (WM_USER+7)
#define UWM_SAVE_ARC2_MWOD (WM_USER+8)
#define UWM_SAVE_ARC2_FMT (WM_USER+9)
#define UWM_SAVE_ARC2_PRESET (WM_USER+10)

#define UWM_RTON_ENABLE (WM_USER+100)


/* define data blocks */
#define DBLK1   1   // 무전기1 상태확인
#define DBLK2   2
#define DBLK3   3
#define DBLK4   4
#define DBLK5   5
#define DBLK6   6
#define DBLK7   7
#define DBLK8   8

#define DBLK11   11 // 무전기1 제어
#define DBLK12   12
#define DBLK13   13
#define DBLK14   14
#define DBLK15   15
#define DBLK16   16
#define DBLK17   17
#define DBLK18   18

#define DBLK21   21 // 무전기2 제어
#define DBLK22   22
#define DBLK23   23
#define DBLK24   24
#define DBLK25   25
#define DBLK26   26
#define DBLK27   27
#define DBLK28   28

#define DBLK31   31 // AIU 제어
#define DBLK32   32
#define DBLK33   33
#define DBLK34   34
#define DBLK35   35
#define DBLK36   36
#define DBLK37   37
#define DBLK38   38

#define DBLK41   41 // 무전기2 상태확인
#define DBLK42   42
#define DBLK43   43
#define DBLK44   44
#define DBLK45   45
#define DBLK46   46
#define DBLK47   47
#define DBLK48   48

/* define message constants */
#define MSG1    1
#define MSG2    2
#define MSG3    3
#define MSG4    4
#define MSG5    5
#define MSG6    6
#define MSG7    7
#define MSG8    8
#define MSG11    11
#define MSG12    12
#define MSG13    13
#define MSG14    14
#define MSG15    15
#define MSG16    16
#define MSG17    17
#define MSG18    18
#define MSG21    21
#define MSG22    22
#define MSG23    23
#define MSG24    24
#define MSG25    25
#define MSG26    26
#define MSG27    27
#define MSG28    28
#define MSG31    31
#define MSG32    32
#define MSG33    33
#define MSG34    34
#define MSG35    35
#define MSG36    36
#define MSG37    37
#define MSG38    38
#define MSG41    41
#define MSG42    42
#define MSG43    43
#define MSG44    44
#define MSG45    45
#define MSG46    46
#define MSG47    47
#define MSG48    48

/* define opcodes */
#define OP1     1
#define OP2     2
#define OP3     3
#define OP4     4
#define OP5     5
#define OP6     6
#define OP7     7
#define OP8     8
#define OP11    11
#define OP12    12
#define OP13    13
#define OP14    14
#define OP15    15
#define OP16    16
#define OP17    17
#define OP18    18
#define OP21    21
#define OP22    22
#define OP23    23
#define OP24    24
#define OP25    25
#define OP26    26
#define OP27    27
#define OP28    28
#define OP31    31
#define OP32    32
#define OP33    33
#define OP34    34
#define OP35    35
#define OP36    36
#define OP37    37
#define OP38    38
#define OP41    41
#define OP42    42
#define OP43    43
#define OP44    44
#define OP45    45
#define OP46    46
#define OP47    47
#define OP48    48

/* define frame constants */
#define MNR1    1
#define MNR2    2
#define MNR3    3
#define MNR4    4
#define MNR5    5
#define MNR6    6
#define MNR7    7
#define MNR8    8

#define MJR     11

/* Change this to change your Frame Time */
#define wFrmTime    1000
#pragma once
#include "afxbutton.h"
#include "set_ethernet.h"
#include "set_arc1.h"
#include "set_arc2.h"
#include "afxwin.h"
#include "mwod_load_status.h"
#include "mwod_load_status2.h"
#include "preset_status.h"
#include "preset_status2.h"
#include "bit_summary.h"
#include "bit_summary2.h"
#include "ics_cp.h"
#include "fault_data.h"
#include "afxcmn.h"
#include "CtrlPowSup.h"
#include "ClientSocket.h"

#include <conio.h>
#include "stdemace.h"

class CITC_GUI_01DlgAutoProxy;


// CITC_GUI_01Dlg 대화 상자
class CITC_GUI_01Dlg : public CDialogEx
{
    DECLARE_DYNAMIC(CITC_GUI_01Dlg);
    friend class CITC_GUI_01DlgAutoProxy;

    // 생성입니다.
public:
    CITC_GUI_01Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
    virtual ~CITC_GUI_01Dlg();

    // 대화 상자 데이터입니다.
    enum { IDD = IDD_ITC_GUI_01_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


    // 구현입니다.
protected:
    CITC_GUI_01DlgAutoProxy* m_pAutoProxy;
    HICON m_hIcon;

    BOOL CanExit();

    // 생성된 메시지 맵 함수
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnClose();
    virtual void OnOK();
    virtual void OnCancel();
    DECLARE_MESSAGE_MAP()
public:
    CMFCButton m_mbtn_power;
    CMFCButton m_mbtn_set_mode;
    CMFCButton m_mbtn_set_func;
    CMFCButton m_mbtn_set_bit;
    CMFCButton m_mbtn_exit;
    CMFCButton m_mbtn_connect;
    CMFCButton m_mbtn_set_ethernet;
    CMFCButton m_mbtn_set_1553b;
    CMFCButton m_mbtn_set_arc1;
    CMFCButton m_mbtn_set_arc2;

    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

    afx_msg void OnBnClickedMbtnConnect();
    afx_msg void OnBnClickedMbtnSetEthernet();
    afx_msg void OnBnClickedMbtnSetItc();
    afx_msg void OnBnClickedMbtnSetArc1();
    afx_msg void OnBnClickedMbtnSetArc2();
    afx_msg void OnBnClickedMbtnExit();

    CSET_ETHERNET m_CSET_ETHERNET;
    CString m_str_ip;
    CString m_str_port;
    CComboBox m_combo_MIC1;
    CComboBox m_combo_MIC2;

    afx_msg void OnCbnSelchangeComboMic1();
    afx_msg void OnCbnSelchangeComboMic2();
    UINT8 MIC1_Index;
    UINT8 MIC2_Index;

    CComboBox m_combo_Tone1;
    CComboBox m_combo_Tone2;
    afx_msg void OnCbnSelchangeComboTone1();
    afx_msg void OnCbnSelchangeComboTone2();
    UINT8 TONE1_Index;
    UINT8 TONE2_Index;

    CComboBox m_combo_Tone_Type1;
    CComboBox m_combo_Tone_Type2;
    afx_msg void OnBnClickedMbtnSetDis();
    CMFCButton m_mbtn_set_dist;
    void TCP_CONNECT(void);
private:
    U8BIT m_connect_flag;
public:
    void ChangeIcon(CStatic* m_Icon, U8BIT flag);
    CStatic m_icon_ethernet;
    CStatic m_icon_1553b;
    SOCKET mh_socket;
    SOCKET Client_socket;
    void AddEventString(wchar_t* ap_string);
    struct sockaddr_in srv_addr;
protected:
    afx_msg LRESULT On25001(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT On25002(WPARAM wParam, LPARAM lParam);
public:
    CHAR SendMsg[BUFSIZE];
    UCHAR RecvMsg[BUFSIZE];
    afx_msg void OnBnClickedBtnMwodStatus1();
    afx_msg void OnBnClickedBtnPresetStatus1();
    afx_msg void OnBnClickedBtnBitSummary1();
    afx_msg void OnBnClickedBtnMwodStatus2();
    afx_msg void OnBnClickedBtnPresetStatus2();
    afx_msg void OnBnClickedBtnBitSummary2();
    // CSET_ARC1 m_CSET_ARC1;

    //afx_msg void OnBnClickedButton16();
    //afx_msg void OnBnClickedButton17();
    CMWOD_LOAD_STATUS m_ARC1_CMWOD_LOAD_STATUS;
    CPRESET_STATUS m_ARC1_CPRESET_STATUS;
    CBIT_SUMMARY m_ARC1_CBIT_SUMMARY;
    CITC_SET_DIS* m_CITC_SET_DIS;
    CICS_CP m_CICS_CP;
    CSET_ARC1 m_CSET_ARC1;
    CSET_ARC2 m_CSET_ARC2;

    CMWOD_LOAD_STATUS* p_ARC1_CMWOD_LOAD_STATUS;
    CPRESET_STATUS* p_ARC1_CPRESET_STATUS;
    CBIT_SUMMARY* p_ARC1_CBIT_SUMMARY;

    CMWOD_LOAD_STATUS2* p_ARC2_CMWOD_LOAD_STATUS;
    CPRESET_STATUS2* p_ARC2_CPRESET_STATUS;
    CBIT_SUMMARY2* p_ARC2_CBIT_SUMMARY;

    CITC_SET_DIS* p_CITC_SET_DIS;
    CICS_CP* p_CICS_CP;
    CSET_ARC1* p_CSET_ARC1;
    CSET_ARC2* p_CSET_ARC2;

    afx_msg void OnBnClickedMbtnSetIcs();
    CFAULT_DATA m_CFAULT_DATA;
    CFAULT_DATA* p_CFAULT_DATA;
    afx_msg void OnBnClickedBtnFaultData();
    afx_msg void OnCbnSelchangeComboSpk1();
    afx_msg void OnCbnSelchangeComboSpk2();
    CComboBox m_combo_SPK1;
    CComboBox m_combo_SPK2;
    UINT8 SPK1_Index;
    UINT8 SPK2_Index;

    afx_msg void OnBnClickedBtnMic1();
    afx_msg void OnBnClickedBtnMic2();
    afx_msg void OnBnClickedBtnTone1();
    afx_msg void OnBnClickedBtnTone2();
    afx_msg void OnBnClickedBtnSpk1();
    afx_msg void OnBnClickedBtnSpk2();

    void SetComboAOUT(CComboBox* pCombo, UINT8 CurrentState);

    BOOL MIC1_Left_Flag, MIC1_Right_Flag, MIC2_Left_Flag, MIC2_Right_Flag
        , TONE1_Left_Flag, TONE1_Right_Flag, TONE2_Left_Flag, TONE2_Right_Flag
        , SPK1_Left_Flag, SPK1_Right_Flag, SPK2_Left_Flag, SPK2_Right_Flag;

    void MakeFrame(U8BIT m_Path, U8BIT m_Codec,  U8BIT m_Volume, U16BIT m_OP, U8BIT f_MICorSPK);
    void Clssfctn(U8BIT m_Path, CSliderCtrl* m_CSliderCtrl, U16BIT m_OP, U8BIT f_MICorSPK);
    void Clssfctn2(U8BIT m_Path, CSliderCtrl* m_CSliderCtrl, U8BIT m_Tone_Type, U16BIT m_OP, U8BIT m_BTN_Num);
    void MakeFrame2(U8BIT m_Path, U8BIT m_Codec, U8BIT m_Volume, U8BIT m_Tone_Type, U16BIT m_OP, U8BIT m_BTN_Num);

    const U8BIT StartCode, EndCode;
    CSliderCtrl m_slider_mic1;
    CSliderCtrl m_slider_mic2;
    CSliderCtrl m_slider_tone1;
    CSliderCtrl m_slider_tone2;
    CSliderCtrl m_slider_spk1;
    CSliderCtrl m_slider_spk2;

    UINT8 m_SCVolume;

    U16BIT MIC1;
    U16BIT MIC2;
    U16BIT TONE1;
    U16BIT TONE2;
    U16BIT SPK1;
    U16BIT SPK2;

    int CheckConnect(void);
    void CheckPath(UINT8 Index);

    CHAR MIC1_SentMsg[BUFSIZE];
    CHAR TONE1_SentMsg[BUFSIZE];
    CHAR SPK1_SentMsg[BUFSIZE];
    CHAR MIC2_SentMsg[BUFSIZE];
    CHAR TONE2_SentMsg[BUFSIZE];
    CHAR SPK2_SentMsg[BUFSIZE];
    CHAR ARC1_SentMsg[BUFSIZE];
    CHAR ARC2_SentMsg[BUFSIZE];
    CHAR ARC1_SentMsg2[BUFSIZE];
    CHAR ARC2_SentMsg2[BUFSIZE];
    CHAR ARC_StatetMsg[BUFSIZE];

    U8BIT prev_MIC1_Path, prev_TONE1_Path, prev_SPK1_Path, prev_MIC2_Path, prev_TONE2_Path, prev_SPK2_Path, prev_ARC1_Path, prev_ARC2_Path;
    U8BIT prev_Codec_MIC1, prev_Codec_MIC2, prev_Codec_SPK1, prev_Codec_SPK2;

    CHAR WriteMsg[BUFSIZE];
    U8BIT prev_MsgSize(U8BIT prev_Path);
    afx_msg void OnBnClickedMbtnPowSup();
protected:
    afx_msg LRESULT OnUwmIcsDis(WPARAM wParam, LPARAM lParam);
    /*1553*/
public:
    afx_msg void OnBnClickedBtnArc1();
    afx_msg void OnBnClickedBtnArc2();
    CComboBox m_combo_ARC1;
    CComboBox m_combo_ARC2;
    BOOL b_ARC1_flag, b_ARC2_flag;
    UINT8 ARC1_Index;
    UINT8 ARC2_Index;
    CSliderCtrl m_slider_arc1;
    CSliderCtrl m_slider_arc2;
    U16BIT ARC1;
    U16BIT ARC2;
    U8BIT prev_TONE1_Type;
    U8BIT prev_TONE2_Type;
    CMFCButton m_mbtn_pow_sup;

    CString str_log;    //  Edixbox에 추가될 문자열 변수

    /* 1553B 관련 변수 */
    int wResult;
    S16BIT aOpCodes[10];
    afx_msg void OnBnClickedBtnLogClear();
    void PathOff(CHAR* Msg, U16BIT Index, U16BIT Size);
    void SendARCState(U16BIT ARCNum, U8BIT Port, U8BIT OnOff);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    BOOL f_ACK;
    BOOL CheckTestFlag(void);

    afx_msg void OnBnClickedMbtn1553b();

    U16BIT MSG_PRESET_SELECT_ARC1[BUFSIZE];
    U16BIT MSG_MODE_AND_GUARD_ARC1[BUFSIZE];
    U16BIT MSG_MARITIME_CHANNEL_ARC1[BUFSIZE];
    U16BIT MSG_COARSE_FREQUENCY_ARC1[BUFSIZE];
    U16BIT MSG_FINE_FREQUENCY_AND_AJ_ARC1[BUFSIZE];
    U16BIT MSG_OPTIONS_ARC1[BUFSIZE];
    U16BIT MSG_RESERVED_CONTROL_ARC1[BUFSIZE];
    U16BIT MSG_TMP[BUFSIZE];

    WORD MSG_FUNCTION_CONTROL_ARC1[BUFSIZE];
    WORD MSG_FUNCTION_CONTROL_ARC2[BUFSIZE];

    U32BIT dwHBufLost;
    U32BIT dwMsgCount;
    U32BIT dwCurCount;
    U16BIT wRepeatCount;
    MSGSTRUCT sMsg;
    afx_msg void OnDestroy();
    BOOL UpdateARC1State(void);

    /* 무전기1 부분 */
    UNION_PRESET_SELECT un_PRESET_SELECT_ARC1;
    UNION_MODE_AND_GUARD un_MODE_AND_GUARD_ARC1;
    UNION_MARITIME_CHANNEL un_MARITIME_CHANNEL_ARC1;
    UNION_FREQUENCY un_FREQUENCY_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_ARC1;
    UNION_OPTIONS un_OPTIONS_ARC1;
    UNION_RESERVED_CONTROL un_RESERVED_CONTROL_ARC1;

    UNION_TOD_MANAGEMENT un_TOD_STATUS_ARC1;
    UNION_RESERVED un_TOD_RESERVED_ARC1;

    UNION_BIT_SUMMARY un_BIT_SUMMARY_ARC1;
    UNION_SOFTWARE_ID un_SOFTWARE_ID_ARC1;
    UNION_SOFTWARE_VERSION un_SOFTWARE_VERSION_ARC1;
    UNION_RESERVED un_RESERVED_ARC1;
    UNION_FAULT_LOCATION01 un_FAULT_LOCATION01_ARC1;
    UNION_FAULT_LOCATION02 un_FAULT_LOCATION02_ARC1;

    /* MWOD Status 무전기1 */
    UNION_MWOD_LOAD_STATUS un_MWOD_LOAD_STATUS_ARC1;
    UNION_MWOD_A_AND_B_DAY un_MWOD_1_AND_2_DAY_ARC1;
    UNION_MWOD_A_AND_B_DAY un_MWOD_3_AND_4_DAY_ARC1;
    UNION_MWOD_A_AND_B_DAY un_MWOD_5_AND_6_DAY_ARC1;

    UNION_FMT_NET_LOAD_STATUS un_FMT_NET_LOAD_STATUS_ARC1;

    UNION_PRESET_GROUP_SELECT un_PRESET_GROUP_SELECT_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_01_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_02_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_03_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_04_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_05_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_06_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_07_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_08_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_09_ARC1;
    UNION_FREQUENCY un_COARSE_FREQUENCY_10_ARC1;

    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_01_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_02_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_03_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_04_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_05_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_06_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_07_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_08_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_09_ARC1;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_10_ARC1;

    /* 무전기2 부분 */
    UNION_PRESET_SELECT un_PRESET_SELECT_ARC2;
    UNION_MODE_AND_GUARD un_MODE_AND_GUARD_ARC2;
    UNION_MARITIME_CHANNEL un_MARITIME_CHANNEL_ARC2;
    UNION_FREQUENCY un_FREQUENCY_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_ARC2;
    UNION_OPTIONS un_OPTIONS_ARC2;
    UNION_RESERVED_CONTROL un_RESERVED_CONTROL_ARC2;

    UNION_TOD_MANAGEMENT un_TOD_STATUS_ARC2;
    UNION_RESERVED un_TOD_RESERVED_ARC2;

    UNION_BIT_SUMMARY un_BIT_SUMMARY_ARC2;
    UNION_SOFTWARE_ID un_SOFTWARE_ID_ARC2;
    UNION_SOFTWARE_VERSION un_SOFTWARE_VERSION_ARC2;
    UNION_RESERVED un_RESERVED_ARC2;
    UNION_FAULT_LOCATION01 un_FAULT_LOCATION01_ARC2;
    UNION_FAULT_LOCATION02 un_FAULT_LOCATION02_ARC2;

    /* MWOD Status 무전기2 */
    UNION_MWOD_LOAD_STATUS un_MWOD_LOAD_STATUS_ARC2;
    UNION_MWOD_A_AND_B_DAY un_MWOD_1_AND_2_DAY_ARC2;
    UNION_MWOD_A_AND_B_DAY un_MWOD_3_AND_4_DAY_ARC2;
    UNION_MWOD_A_AND_B_DAY un_MWOD_5_AND_6_DAY_ARC2;

    UNION_FMT_NET_LOAD_STATUS un_FMT_NET_LOAD_STATUS_ARC2;

    UNION_PRESET_GROUP_SELECT un_PRESET_GROUP_SELECT_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_01_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_02_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_03_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_04_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_05_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_06_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_07_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_08_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_09_ARC2;
    UNION_FREQUENCY un_COARSE_FREQUENCY_10_ARC2;

    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_01_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_02_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_03_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_04_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_05_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_06_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_07_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_08_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_09_ARC2;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ_10_ARC2;

    U16BIT wBuffer1[32];
    U16BIT wBuffer2[32];
    U16BIT wBuffer3[32];
    U16BIT wBuffer4[32];
    U16BIT wBuffer5[32];
    U16BIT wBuffer6[32];

    U16BIT wBuffer41[32];
    U16BIT wBuffer42[32];
    U16BIT wBuffer43[32];
    U16BIT wBuffer44[32];
    U16BIT wBuffer45[32];
    U16BIT wBuffer46[32];

    U16BIT wBuffer32[32];
    U16BIT wBuffer33[32];

    CStatic m_TEXT_ARC1_OPMODE;
    CStatic m_TEXT_ARC1_MODE;
    CStatic m_TEXT_ARC1_FREQ;
    CStatic m_TEXT_ARC1_FREQ_MNGMT;
    CStatic m_TEXT_ARC1_CHANNEL;
    CStatic m_TEXT_ARC1_MODULATION;
    CStatic m_TEXT_ARC1_RFPOWER;
    CStatic m_TEXT_ARC1_TOD_STAT;
    CStatic m_TEXT_ARC1_TOD_DAY;
    CStatic m_TEXT_ARC1_SWID;
    CStatic m_TEXT_ARC1_SWVER;
    CStatic m_LED_ARC1_ZEROIZE;
    CStatic m_LED_ARC1_ADF;
    CStatic m_LED_ARC1_COMPRESSOR;
    CStatic m_LED_ARC1_GUARD_SQUELCH;
    CStatic m_LED_ARC1_XMODE;
    CStatic m_LED_ARC1_MAINSQUELCH;
    CStatic m_LED_ARC1_TONEKEY;
    CStatic m_LED_ARC1_FMT_VALID;
    CStatic m_LED_ARC1_CONTROL_DATA;

    afx_msg void OnBnClickedBtnIcsBit();
    CString NumToString(U16BIT Hundreds, U16BIT Tens, U16BIT Ones, U16BIT Tenths, U16BIT Hundredths, U16BIT Thousandths);
    CEdit m_EditLog;
    BOOL b_BCState;
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    BOOL b_PrevCOM2XMode;
    BOOL b_PrevCOM3XMode;
    virtual void PostNcDestroy();

    CHAR ARC1_Discrete[3];
    CHAR ARC2_Discrete[3];
    CHAR ICS_Discrete[21];

    CStatic m_TEXT_ARC2_OPMODE;
    CStatic m_TEXT_ARC2_MODE;
    CStatic m_TEXT_ARC2_FREQ;
    CStatic m_TEXT_ARC2_FREQ_MNGMT;
    CStatic m_TEXT_ARC2_CHANNEL;
    CStatic m_TEXT_ARC2_MODULATION;
    CStatic m_TEXT_ARC2_RFPOWER;
    CStatic m_TEXT_ARC2_TOD_STAT;
    CStatic m_TEXT_ARC2_TOD_DAY;
    CStatic m_TEXT_ARC2_SWID;
    CStatic m_TEXT_ARC2_SWVER;
    CStatic m_LED_ARC2_ZEROIZE;
    CStatic m_LED_ARC2_ADF;
    CStatic m_LED_ARC2_COMPRESSOR;
    CStatic m_LED_ARC2_GUARD_SQUELCH;
    CStatic m_LED_ARC2_XMODE;
    CStatic m_LED_ARC2_MAINSQUELCH;
    CStatic m_LED_ARC2_TONEKEY;
    CStatic m_LED_ARC2_FMT_VALID;
    CStatic m_LED_ARC2_CONTROL_DATA;

    BOOL f_ARC1_Dlg;
    BOOL f_ARC2_Dlg;
    BOOL f_ICS_SET;
    BOOL f_SET_DIS;

    WORD MSG_AIU_BC2RT[MAX_WORD];

protected:
    afx_msg LRESULT OnUwmRdyIcsDis(WPARAM wParam, LPARAM lParam);
public:
    CString test;
    BOOL MIC1_XAudio_A_Flag;
    BOOL MIC1_XAudio_B_Flag;
    BOOL MIC2_XAudio_A_Flag;
    BOOL MIC2_XAudio_B_Flag;
    CHAR XAudio_Msg[BUFSIZE];
    BOOL SPK1_RAudio_A_Flag;
    BOOL SPK1_RAudio_B_Flag;
    BOOL SPK2_RAudio_A_Flag;
    BOOL SPK2_RAudio_B_Flag;

    /* 무전기1 최근 설정 */
    UNION_PRESET_SELECT un_prev_ARC1_prev_ARC1_PRESET_SELECT;
    UNION_MODE_AND_GUARD un_prev_ARC1_MODE_AND_GUARD;
    UNION_MARITIME_CHANNEL un_prev_ARC1_MARITIME_CHANNEL;
    UNION_FREQUENCY un_prev_ARC1_COARSE_FREQUENCY;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FINE_FREQUENCY_AND_AJ;
    UNION_OPTIONS un_prev_ARC1_OPTIONS;
    UNION_RESERVED_CONTROL un_prev_ARC1_RESERVED_CONTROL;

    UNION_TOD_MANAGEMENT un_prev_ARC1_TOD_MANAGEMENT;
    UNION_RESERVED un_prev_ARC1_TOD_RESERVED;

    UNION_BIT_CONTROL un_prev_ARC1_BIT_CONTROL;

    /* 무전기1 MWOD */
    UNION_WOD_SEGMENT un_prev_ARC1_WOD_SEGMENT1;
    UNION_WOD_SEGMENT un_prev_ARC1_WOD_SEGMENT2;
    UNION_WOD_SEGMENT un_prev_ARC1_WOD_SEGMENT3;
    UNION_WOD_SEGMENT un_prev_ARC1_WOD_SEGMENT4;
    UNION_WOD_SEGMENT un_prev_ARC1_WOD_SEGMENT5;
    UNION_WOD_SEGMENT un_prev_ARC1_WOD_SEGMENT6;
    UNION_WOD_DAY un_prev_ARC1_WOD_DAY;

    /* 무전기1 PRESET */
    U16BIT prev_ARC1_PRESET_GROUP_SELECT;
    UNION_PRESET_GROUP_SELECT un_prev_ARC1_PRESET_GROUP_SELECT;

    UNION_FREQUENCY un_prev_ARC1_FREQUENCY01;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY02;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY03;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY04;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY05;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY06;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY07;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY08;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY09;
    UNION_FREQUENCY un_prev_ARC1_FREQUENCY10;

    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE01;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE02;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE03;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE04;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE05;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE06;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE07;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE08;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE09;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC1_FREQ_MANAGE10;

    /* 무전기1 FMT NET FREQUENCY */
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY01;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY02;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY03;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY04;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY05;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY06;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY07;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY08;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY09;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY10;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY11;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY12;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY13;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY14;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY15;
    UNION_FMT_NET_FREQUENCY un_prev_ARC1_FMT_NET_FREQUENCY16;

    /* 무전기2 최근 설정 */
    UNION_PRESET_SELECT un_prev_ARC2_prev_ARC2_PRESET_SELECT;
    UNION_MODE_AND_GUARD un_prev_ARC2_MODE_AND_GUARD;
    UNION_MARITIME_CHANNEL un_prev_ARC2_MARITIME_CHANNEL;
    UNION_FREQUENCY un_prev_ARC2_COARSE_FREQUENCY;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FINE_FREQUENCY_AND_AJ;
    UNION_OPTIONS un_prev_ARC2_OPTIONS;
    UNION_RESERVED_CONTROL un_prev_ARC2_RESERVED_CONTROL;

    UNION_TOD_MANAGEMENT un_prev_ARC2_TOD_MANAGEMENT;
    UNION_RESERVED un_prev_ARC2_TOD_RESERVED;

    UNION_BIT_CONTROL un_prev_ARC2_BIT_CONTROL;

    /* 무전기2 MWOD */
    UNION_WOD_SEGMENT un_prev_ARC2_WOD_SEGMENT1;
    UNION_WOD_SEGMENT un_prev_ARC2_WOD_SEGMENT2;
    UNION_WOD_SEGMENT un_prev_ARC2_WOD_SEGMENT3;
    UNION_WOD_SEGMENT un_prev_ARC2_WOD_SEGMENT4;
    UNION_WOD_SEGMENT un_prev_ARC2_WOD_SEGMENT5;
    UNION_WOD_SEGMENT un_prev_ARC2_WOD_SEGMENT6;
    UNION_WOD_DAY un_prev_ARC2_WOD_DAY;
    CMFCButton m_mbtn_1553B;

    /* 무전기2 PRESET */
    U16BIT prev_ARC2_PRESET_GROUP_SELECT;
    UNION_PRESET_GROUP_SELECT un_prev_ARC2_PRESET_GROUP_SELECT;

    UNION_FREQUENCY un_prev_ARC2_FREQUENCY01;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY02;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY03;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY04;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY05;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY06;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY07;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY08;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY09;
    UNION_FREQUENCY un_prev_ARC2_FREQUENCY10;

    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE01;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE02;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE03;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE04;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE05;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE06;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE07;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE08;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE09;
    UNION_FINE_FREQUENCY_AND_AJ un_prev_ARC2_FREQ_MANAGE10;

    /* 무전기2 FMT NET FREQUENCY */
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY01;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY02;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY03;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY04;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY05;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY06;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY07;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY08;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY09;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY10;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY11;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY12;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY13;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY14;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY15;
    UNION_FMT_NET_FREQUENCY un_prev_ARC2_FMT_NET_FREQUENCY16;

    UNION_VOICE_WARNING_MESSAGE1 un_VOICE_WARNING_MESSAGE1;
    UNION_VOICE_WARNING_MESSAGE2 un_VOICE_WARNING_MESSAGE2;
    UNION_VOICE_WARNING_MESSAGE3 un_VOICE_WARNING_MESSAGE3;
    UNION_VOICE_WARNING_MESSAGE4 un_VOICE_WARNING_MESSAGE4;
    UNION_VOICE_WARNING_MESSAGE5 un_VOICE_WARNING_MESSAGE5;
    UNION_VOICE_WARNING_MESSAGE6 un_VOICE_WARNING_MESSAGE6;
    UNION_VOICE_WARNING_MESSAGE7 un_VOICE_WARNING_MESSAGE7;
    UNION_VOICE_WARNING_MESSAGE8 un_VOICE_WARNING_MESSAGE8;
    UNION_VOICE_WARNING_MESSAGE9 un_VOICE_WARNING_MESSAGE9;

    UNION_AIU_FAULT_DATA un_AIU_FAULT_DATA1;
    UNION_AIU_FAULT_DATA un_AIU_FAULT_DATA2;

    UNION_ICS_SW_ID un_ICS_SW_ID1;
    UNION_ICS_SW_ID un_ICS_SW_ID2;
    UNION_ICS_SW_ID un_ICS_SW_ID3;

    UNION_ICP_STATUS un_ICP1_STATUS;
    UNION_ICP_STATUS un_ICP2_STATUS;
    UNION_ICP_STATUS un_ICP3_STATUS;
    UNION_ICP_STATUS un_ICP4_STATUS;
    UNION_ICP_STATUS un_ICP5_STATUS;

    UNION_AIU_STATUS un_AIU_STATUS;
    UNION_ICS_CONTROL1 un_prev_ICS_CONTROL1;
    UNION_ICS_CONTROL4 un_prev_ICS_CONTROL4;

    UNION_AIU_NO_NAME un_AIU_NO_NAME;
    CStatic m_TEXT_AIU_SW_ID;
    CStatic m_TEXT_ICP1ComMode;
    CStatic m_TEXT_ICP2ComMode;
    CStatic m_TEXT_ICP1RadioInRmt;
    CStatic m_TEXT_ICP2RadioInRmt;
    CStatic m_TEXT_ICP1VMUMode;
    CStatic m_TEXT_ICP2VMUMode;
    CStatic m_LED_ICP1ICSPTT;
    CStatic m_LED_ICP2ICSPTT;
    CStatic m_LED_ICP1SelectedPTT;
    CStatic m_LED_ICP2SelectedPTT;
    CStatic m_LED_AIU_WowOn;
    CStatic m_LED_AIIU_BITInProgress;
    CStatic m_TEXT_AIU_COMSECInterface;
    CStatic m_TEXT_AIU_CurrentWarning;

    BOOL ARC1_RT_ON;
    BOOL ARC2_RT_ON;

    BOOL ARC1_XMODE_EN;
    BOOL ARC2_XMODE_EN;

    BOOL ARC1_PTT;
    BOOL ARC2_PTT;

    CClientSocket m_ClientSocket;
    /* 전원공급기 */
    BOOL b_PowerSupp;
    CCtrlPowSup* p_CCtrlPowSup;

    CString volt;
    CString curr;

protected:
    afx_msg LRESULT OnUwmSaveArc1Mwod(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUwmSaveArc1Fmt(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUwmSaveArc1Preset(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUwmSaveArc2Mwod(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUwmSaveArc2Fmt(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUwmSaveArc2Preset(WPARAM wParam, LPARAM lParam);
};
