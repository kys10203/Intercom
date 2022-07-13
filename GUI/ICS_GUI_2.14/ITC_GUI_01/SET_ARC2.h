#pragma once
#include "mwod_load2.h"
#include "fmt_net_load2.h"
#include "preset_load2.h"
#include "afxwin.h"
#include "stdemace.h"

#include "BIT_FIELD.h"

#define MAX_WORD 64
#define UVHF_STATE 5502
#define UWM_ICS_DIS (WM_USER+1)
#define UWM_DP_ICS_DIS (WM_USER+2)

#define UWM_RTON_ENABLE (WM_USER+100)

// CSET_ARC2 대화 상자입니다.

class CSET_ARC2 : public CDialogEx
{
    DECLARE_DYNAMIC(CSET_ARC2)

public:
    CSET_ARC2(CWnd* pParent = NULL);   // 표준 생성자입니다.
    virtual ~CSET_ARC2();

    virtual void OnFinalRelease();

    // 대화 상자 데이터입니다.
    enum { IDD = IDD_SET_ARC2 };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

    DECLARE_MESSAGE_MAP()
    DECLARE_DISPATCH_MAP()
    DECLARE_INTERFACE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

    CMWOD_LOAD2 m_CMWOD_LOAD;
    CFMT_NET_LOAD2 m_CFMT_NET_LOAD;
    CPRESET_LOAD2 m_CPRESET_LOAD;

    CMWOD_LOAD2* p_CMWOD_LOAD;
    CFMT_NET_LOAD2* p_CFMT_NET_LOAD;
    CPRESET_LOAD2* p_CPRESET_LOAD;

    afx_msg void OnBnClickedButton9();
    afx_msg void OnBnClickedButton10();
    afx_msg void OnBnClickedButton11();

    CComboBox m_combo_arc2_rf_power;
    CComboBox m_combo_arc2_tod_manage;
    CComboBox m_combo_arc2_mode;
    CComboBox m_combo_arc2_op_mode;
    CComboBox m_combo_arc2_freq1_manage;
    CComboBox m_combo_arc2_modulation;

protected:
    afx_msg LRESULT OnUwmDpIcsDis(WPARAM wParam, LPARAM lParam);
public:
    afx_msg void OnBnClickedBtnSendArc2();

    WORD MSG_Function_Control[MAX_WORD];
    WORD MSG_TOD_Management[MAX_WORD];
    WORD MSG_BIT_Control[MAX_WORD];

    signed short wResult;
    void CheckARC2Setting(void);
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    U8BIT GetTODDay(CEdit* EditBox);

    CEdit m_edit_arc2_freq;
    CEdit m_edit_arc2_channel;
    CEdit m_edit_arc2_todday;
    CButton m_check_arc2_zeroize;
    CButton m_check_arc2_adf;
    CButton m_check_arc2_compressor;
    CButton m_check_arc2_GuardSquelch;
    CButton m_check_arc2_XMode;
    CButton m_check_arc2_MainSquelch;
    CButton m_check_arc2_ToneKey;
    CButton m_check_arc2_ibit;
    CButton m_check_arc2_rton;
    CButton m_check_arc2_xmode_en;
    CButton m_check_arc2_ptt;

    CStatic m_ICON_ARC2_READY_DISCRETE;
    CStatic m_ICON_ARC2_MAIN_SQ_BROKEN;
    CStatic m_TEXT_ARC2_XMODE;
    CStatic m_TEXT_ARC2_PTT;

    UNION_PRESET_SELECT un_PRESET_SELECT;
    UNION_MODE_AND_GUARD un_MODE_AND_GUARD;
    UNION_MARITIME_CHANNEL un_MARITIME_CHANNEL;
    UNION_FREQUENCY un_COARSE_FREQUENCY;
    UNION_FINE_FREQUENCY_AND_AJ un_FINE_FREQUENCY_AND_AJ;
    UNION_OPTIONS un_OPTIONS;
    UNION_RESERVED_CONTROL un_RESERVED_CONTROL;

    UNION_TOD_MANAGEMENT un_TOD_MANAGEMENT;
    UNION_RESERVED un_TOD_RESERVED;

    UNION_BIT_CONTROL un_BIT_CONTROL;

    CHAR WriteMsg[8];
    afx_msg void OnBnClickedBtnArc2DiscreteSend();
    afx_msg void OnCbnSelchangeComboArc2Mode();
    afx_msg void OnClose();
    void DpPrevSet(void);
protected:
    afx_msg LRESULT OnUwmRtonEnable(WPARAM wParam, LPARAM lParam);
};
