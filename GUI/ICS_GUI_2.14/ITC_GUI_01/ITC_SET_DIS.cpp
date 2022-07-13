// ITC_SET_DIS.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "ITC_SET_DIS.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"
#include "ICS_CP.h"

// CITC_SET_DIS 대화 상자입니다.

IMPLEMENT_DYNAMIC(CITC_SET_DIS, CDialogEx)

    CITC_SET_DIS::CITC_SET_DIS(CWnd* pParent /*=NULL*/)
    : CDialogEx(CITC_SET_DIS::IDD, pParent)
    , b_ITC_SET_DIS(FALSE)
{

}

CITC_SET_DIS::~CITC_SET_DIS()
{
}

void CITC_SET_DIS::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK_REMOTE_ON, m_CHECK_REMOTE_ON);
    DDX_Control(pDX, IDC_CHECK_COMSEC_X, m_CHECK_COMSEC_X);
    DDX_Control(pDX, IDC_CHECK_SPARE_DIN1, m_CHECK_SPARE_DIN1);
    DDX_Control(pDX, IDC_CHECK_SPARE_DIN2, m_CHECK_SPARE_DIN2);
    DDX_Control(pDX, IDC_CHECK_SPARE_DIN3, m_CHECK_SPARE_DIN3);
    DDX_Control(pDX, IDC_CHECK_SPARE_DIN4, m_CHECK_SPARE_DIN4);
    DDX_Control(pDX, IDC_CHECK_WOW, m_CHECK_WOW);
    DDX_Control(pDX, IDC_CHECK_FUEL_LOW_WARN, m_CHECK_FUEL_LOW_WARN);
    DDX_Control(pDX, IDC_CHECK_LWR_WARN, m_CHECK_LWR_WARN);
    DDX_Control(pDX, IDC_CHECK_RWR_WARN, m_CHECK_RWR_WARN);
    DDX_Control(pDX, IDC_CHECK_MWR_WARN_1, m_CHECK_MWR_WARN_1);
    DDX_Control(pDX, IDC_CHECK_MWR_WARN_2, m_CHECK_MWR_WARN_2);
    DDX_Control(pDX, IDC_CHECK_MWR_WARN_3, m_CHECK_MWR_WARN_3);
    DDX_Control(pDX, IDC_CHECK_MAINT_MODE, m_CHECK_MAINT_MODE);
    DDX_Control(pDX, IDC_CHECK_RALT_LOW_ALT_WARN, m_CHECK_RALT_LOW_ALT_WARN);
    DDX_Control(pDX, IDC_CHECK_BARO_LOW_ALT_WARN, m_CHECK_BARO_LOW_ALT_WARN);
    DDX_Control(pDX, IDC_CHECK_FIRE_WARN, m_CHECK_FIRE_WARN);
    DDX_Control(pDX, IDC_CHECK_ENG_OUT_WARN, m_CHECK_ENG_OUT_WARN);
    DDX_Control(pDX, IDC_CHECK_NR_LOW_WARN, m_CHECK_NR_LOW_WARN);
    DDX_Control(pDX, IDC_CHECK_CAUT, m_CHECK_CAUT);
    DDX_Control(pDX, IDC_CHECK_WARN_RST, m_CHECK_WARN_RST);
    DDX_Control(pDX, IDC_LED_AIU_RDY, m_LED_AIU_RDY);
    DDX_Control(pDX, IDC_LED_AIU_COM1_PTT, m_LED_AIU_COM1_PTT);
    DDX_Control(pDX, IDC_LED_AIU_COM2_PTT, m_LED_AIU_COM2_PTT);
    DDX_Control(pDX, IDC_LED_AIU_COM3_PTT, m_LED_AIU_COM3_PTT);
    DDX_Control(pDX, IDC_LED_AIU_COM4_PTT, m_LED_AIU_COM4_PTT);
    DDX_Control(pDX, IDC_LED_AIU_COM5_PTT, m_LED_AIU_COM5_PTT);
    DDX_Control(pDX, IDC_LED_AIU_COM2_X_EN, m_LED_AIU_COM2_X_EN);
    DDX_Control(pDX, IDC_LED_AIU_COM3_X_EN, m_LED_AIU_COM3_X_EN);
    DDX_Control(pDX, IDC_LED_AIU_COMSEC_PTT, m_LED_AIU_COMSEC_PTT);
    DDX_Control(pDX, IDC_LED_AIU_SPARE_DOUT1, m_LED_AIU_SPARE_DOUT1);
    DDX_Control(pDX, IDC_LED_AIU_SPARE_DOUT2, m_LED_AIU_SPARE_DOUT2);
    DDX_Control(pDX, IDC_LED_AIU_SPARE_DOUT3, m_LED_AIU_SPARE_DOUT3);
    DDX_Control(pDX, IDC_STATIC_COMSEC_AIU_PTT, m_STATIC_COMSEC_AIU_PTT);
    DDX_Control(pDX, IDC_STATIC_COM1_AIU_SQL, m_STATIC_COM1_AIU_SQL);
    DDX_Control(pDX, IDC_STATIC_COM2_AIU_SQL, m_STATIC_COM2_AIU_SQL);
    DDX_Control(pDX, IDC_STATIC_COM3_AIU_SQL, m_STATIC_COM3_AIU_SQL);
    DDX_Control(pDX, IDC_STATIC_COM4_AIU_SQL, m_STATIC_COM4_AIU_SQL);
    DDX_Control(pDX, IDC_STATIC_COM5_AIU_SQL, m_STATIC_COM5_AIU_SQL);
}


BEGIN_MESSAGE_MAP(CITC_SET_DIS, CDialogEx)
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_BTN_SET_DIS, &CITC_SET_DIS::OnBnClickedBtnSetDis)
    ON_WM_TIMER()
    ON_MESSAGE(UWM_ICS_DIS, &CITC_SET_DIS::OnUwmIcsDis)
    ON_MESSAGE(UWM_DP_ICS_DIS, &CITC_SET_DIS::OnUwmDpIcsDis)
    ON_WM_CLOSE()
END_MESSAGE_MAP()


// CITC_SET_DIS 메시지 처리기입니다.


HBRUSH CITC_SET_DIS::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    UINT nID = pWnd -> GetDlgCtrlID();

    switch(nID)
    {
            case IDC_STATIC_SET_DIS:
        pDC -> SetTextColor( RGB(255, 255, 255) );
        pDC -> SetBkColor( RGB(60, 60, 250) );
        hbr = ::CreateSolidBrush( RGB(60, 60, 250) );
        break;
    }

    return hbr;
}


void CITC_SET_DIS::OnBnClickedBtnSetDis()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    if(m_CHECK_COMSEC_X.GetCheck() == 0)
    {
        send(((CITC_GUI_01Dlg *)GetParent())->mh_socket, ComsecMsg2, 13, 0); 
        ((CITC_GUI_01Dlg *)GetParent())->SetTimer(TID_COMSEC_COM2, 300, NULL);
        ((CITC_GUI_01Dlg *)GetParent())->f_ACK = TRUE;
        Sleep(299);
    }
    else if(m_CHECK_COMSEC_X.GetCheck() == 0)
    {
        send(((CITC_GUI_01Dlg *)GetParent())->mh_socket, ComsecMsg, 13, 0); 
        ((CITC_GUI_01Dlg *)GetParent())->SetTimer(TID_COMSEC_COM2, 300, NULL);
        ((CITC_GUI_01Dlg *)GetParent())->f_ACK = TRUE;
        Sleep(299);
    }

    WriteMsg[0] = 0xD3;
    WriteMsg[1] = 0x15;
    WriteMsg[2] = 0x55;
    WriteMsg[3] = 0x01;

    WriteMsg[4] = WriteDiscrete(&m_CHECK_REMOTE_ON);
    WriteMsg[5] = WriteDiscrete(&m_CHECK_COMSEC_X);
    WriteMsg[6] = WriteDiscrete(&m_CHECK_SPARE_DIN1);
    WriteMsg[7] = WriteDiscrete(&m_CHECK_SPARE_DIN2);
    WriteMsg[8] = WriteDiscrete(&m_CHECK_SPARE_DIN3);

    WriteMsg[9] = WriteDiscrete(&m_CHECK_SPARE_DIN4);
    WriteMsg[10] = WriteDiscrete(&m_CHECK_WOW);
    WriteMsg[11] = WriteDiscrete(&m_CHECK_FUEL_LOW_WARN);
    WriteMsg[12] = WriteDiscrete(&m_CHECK_LWR_WARN);
    WriteMsg[13] = WriteDiscrete(&m_CHECK_RWR_WARN);

    WriteMsg[14] = WriteDiscrete(&m_CHECK_MWR_WARN_1);
    WriteMsg[15] = WriteDiscrete(&m_CHECK_MWR_WARN_2);
    WriteMsg[16] = WriteDiscrete(&m_CHECK_MWR_WARN_3);
    WriteMsg[17] = WriteDiscrete(&m_CHECK_MAINT_MODE);
    WriteMsg[18] = WriteDiscrete(&m_CHECK_RALT_LOW_ALT_WARN);

    WriteMsg[19] = WriteDiscrete(&m_CHECK_BARO_LOW_ALT_WARN);
    WriteMsg[20] = WriteDiscrete(&m_CHECK_FIRE_WARN);
    WriteMsg[21] = WriteDiscrete(&m_CHECK_ENG_OUT_WARN);
    WriteMsg[22] = WriteDiscrete(&m_CHECK_NR_LOW_WARN);
    WriteMsg[23] = WriteDiscrete(&m_CHECK_CAUT);

    WriteMsg[24] = WriteDiscrete(&m_CHECK_WARN_RST);

    WriteMsg[25] = 0x7F;

    send(((CITC_GUI_01Dlg *)GetParent())->mh_socket, WriteMsg, 26, 0); 
    ((CITC_GUI_01Dlg *)GetParent())->SetTimer(SET_ICS_DISCRETE, 300, NULL);
        ((CITC_GUI_01Dlg *)GetParent())->f_ACK = TRUE;
        Sleep(299);

    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[0] = WriteDiscrete(&m_CHECK_REMOTE_ON);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[1] = WriteDiscrete(&m_CHECK_COMSEC_X);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[2] = WriteDiscrete(&m_CHECK_SPARE_DIN1);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[3] = WriteDiscrete(&m_CHECK_SPARE_DIN2);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[4] = WriteDiscrete(&m_CHECK_SPARE_DIN3);
    
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[5] = WriteDiscrete(&m_CHECK_SPARE_DIN4);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[6] = WriteDiscrete(&m_CHECK_WOW);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[7] = WriteDiscrete(&m_CHECK_FUEL_LOW_WARN);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[8] = WriteDiscrete(&m_CHECK_LWR_WARN);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[9] = WriteDiscrete(&m_CHECK_RWR_WARN);
    
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[10] = WriteDiscrete(&m_CHECK_MWR_WARN_1);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[11] = WriteDiscrete(&m_CHECK_MWR_WARN_2);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[12] = WriteDiscrete(&m_CHECK_MWR_WARN_3);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[13] = WriteDiscrete(&m_CHECK_MAINT_MODE);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[14] = WriteDiscrete(&m_CHECK_RALT_LOW_ALT_WARN);

    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[15] = WriteDiscrete(&m_CHECK_BARO_LOW_ALT_WARN);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[16] = WriteDiscrete(&m_CHECK_FIRE_WARN);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[17] = WriteDiscrete(&m_CHECK_ENG_OUT_WARN);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[18] = WriteDiscrete(&m_CHECK_NR_LOW_WARN);
    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[19] = WriteDiscrete(&m_CHECK_CAUT);

    ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[20] = WriteDiscrete(&m_CHECK_WARN_RST);
    //memcpy(((CICS_CP*)GetParent())->WriteMsg, WriteMsg, sizeof(WriteMsg));
    // CDialogEx::OnOK();
}


UINT8 CITC_SET_DIS::WriteDiscrete(CButton* p_CButton)
{
    UINT8 m_Chk;

    m_Chk = p_CButton->GetCheck();

    return m_Chk;
}


void CITC_SET_DIS::OnCancel()
{
    // TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
    // CDialogEx::OnOK();
    b_ITC_SET_DIS = FALSE;

    CDialogEx::OnCancel();
}


BOOL CITC_SET_DIS::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    memset(WriteMsg, 0, BUFSIZE);
    memset(ReadMsg, 0, BUFSIZE);

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

    // memcpy(ReadMsg,((CICS_CP *)GetParent())->ReadMsg, sizeof(((CICS_CP *)GetParent())->ReadMsg));

    //CString str;
    //str.Format(L"> %x  %x", ((CITC_GUI_01Dlg *)GetParent())->RecvMsg[10], ((CITC_GUI_01Dlg *)GetParent())->RecvMsg[11]);
    //AfxMessageBox(str);

    // SetTimer(1001, 1000, NULL);

    // b_ITC_SET_DIS = TRUE;

    ::SendMessage(((CITC_GUI_01Dlg*)GetParent())->m_hWnd, UWM_RDY_ICS_DIS, NULL, NULL);
    m_CHECK_REMOTE_ON.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[0] );
    m_CHECK_COMSEC_X.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[1] );
    m_CHECK_SPARE_DIN1.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[2] );
    m_CHECK_SPARE_DIN2.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[3] );
    m_CHECK_SPARE_DIN3.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[4] );

    m_CHECK_SPARE_DIN4.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[5] );
    m_CHECK_WOW.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[6] );
    m_CHECK_FUEL_LOW_WARN.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[7] );
    m_CHECK_LWR_WARN.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[8] );
    m_CHECK_RWR_WARN.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[9] );

    m_CHECK_MWR_WARN_1.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[10] );
    m_CHECK_MWR_WARN_2.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[11] );
    m_CHECK_MWR_WARN_3.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[12] );
    m_CHECK_MAINT_MODE.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[13] );
    m_CHECK_RALT_LOW_ALT_WARN.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[14] );

    m_CHECK_BARO_LOW_ALT_WARN.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[15] );
    m_CHECK_FIRE_WARN.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[16] );
    m_CHECK_ENG_OUT_WARN.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[17] );
    m_CHECK_NR_LOW_WARN.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[18] );
    m_CHECK_CAUT.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[19] );

    m_CHECK_WARN_RST.SetCheck( ((CITC_GUI_01Dlg *)GetParent())->ICS_Discrete[20] );

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CITC_SET_DIS::ChangeIcon(CStatic* m_Icon, U8BIT flag)
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


void CITC_SET_DIS::OnTimer(UINT_PTR nIDEvent)
{

    CDialogEx::OnTimer(nIDEvent);
}


afx_msg LRESULT CITC_SET_DIS::OnUwmIcsDis(WPARAM wParam, LPARAM lParam)
{
    // memcpy(ReadMsg,((CICS_CP *)GetParent())->ReadMsg, sizeof(((CICS_CP *)GetParent())->ReadMsg));
    // memcpy(ReadMsg,((CICS_CP *)GetParent())->ReadMsg, sizeof(((CICS_CP *)GetParent())->ReadMsg));
    // ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("> A\r\n"));

    return 0;
}


afx_msg LRESULT CITC_SET_DIS::OnUwmDpIcsDis(WPARAM wParam, LPARAM lParam)
{
        memcpy(ReadMsg,((CITC_GUI_01Dlg *)GetParent())->RecvMsg, sizeof(((CITC_GUI_01Dlg *)GetParent())->RecvMsg));
        
        ::SendMessage(((CITC_GUI_01Dlg*)GetParent())->m_hWnd, UWM_RDY_ICS_DIS, NULL, NULL);
        // ((CITC_GUI_01Dlg *)GetParent())->AddEventString(_T("> B\r\n"));

        if(ReadMsg[4]==0)
        {
            m_STATIC_COMSEC_AIU_PTT.SetWindowTextW(_T("OFF"));
        }
        else
        {
            m_STATIC_COMSEC_AIU_PTT.SetWindowTextW(_T("ON"));
        }
        if(ReadMsg[5]==0)
        {
            m_STATIC_COM1_AIU_SQL.SetWindowTextW(_T("OFF"));
        }
        else
        {
            m_STATIC_COM1_AIU_SQL.SetWindowTextW(_T("ON"));
        }
        if(ReadMsg[6]==0)
        {
            m_STATIC_COM2_AIU_SQL.SetWindowTextW(_T("OFF"));
        }
        else
        {
            m_STATIC_COM2_AIU_SQL.SetWindowTextW(_T("ON"));
        }
        if(ReadMsg[7]==0)
        {
            m_STATIC_COM3_AIU_SQL.SetWindowTextW(_T("OFF"));
        }
        else
        {
            m_STATIC_COM3_AIU_SQL.SetWindowTextW(_T("ON"));
        }
        if(ReadMsg[8]==0)
        {
            m_STATIC_COM4_AIU_SQL.SetWindowTextW(_T("OFF"));
        }
        else
        {
            m_STATIC_COM4_AIU_SQL.SetWindowTextW(_T("ON"));
        }
        if(ReadMsg[9]==0)
        {
            m_STATIC_COM5_AIU_SQL.SetWindowTextW(_T("OFF"));
        }
        else
        {
            m_STATIC_COM5_AIU_SQL.SetWindowTextW(_T("ON"));
        }

        if(ReadMsg[10]==0)
        {
            ChangeIcon(&m_LED_AIU_RDY, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_RDY, 1);
        }
        if(ReadMsg[11]==0)
        {
            ChangeIcon(&m_LED_AIU_COM1_PTT, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_COM1_PTT, 1);
        }
        if(ReadMsg[12]==0)
        {
            ChangeIcon(&m_LED_AIU_COM2_PTT, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_COM2_PTT, 1);
        }
        if(ReadMsg[13]==0)
        {
            ChangeIcon(&m_LED_AIU_COM3_PTT, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_COM3_PTT, 1);
        }
        if(ReadMsg[14]==0)
        {
            ChangeIcon(&m_LED_AIU_COM4_PTT, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_COM4_PTT, 1);
        }
        if(ReadMsg[15]==0)
        {
            ChangeIcon(&m_LED_AIU_COM5_PTT, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_COM5_PTT, 1);
        }
        if(ReadMsg[16]==0)
        {
            ChangeIcon(&m_LED_AIU_COM2_X_EN, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_COM2_X_EN, 1);
        }
        if(ReadMsg[17]==0)
        {
            ChangeIcon(&m_LED_AIU_COM3_X_EN, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_COM3_X_EN, 1);
        }
        if(ReadMsg[18]==0)
        {
            ChangeIcon(&m_LED_AIU_COMSEC_PTT, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_COMSEC_PTT, 1);
        }
        if(ReadMsg[19]==0)
        {
            ChangeIcon(&m_LED_AIU_SPARE_DOUT1, 1);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_SPARE_DOUT1, 2);
        }
        if(ReadMsg[20]==0)
        {
            ChangeIcon(&m_LED_AIU_SPARE_DOUT2, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_SPARE_DOUT2, 1);
        }
        if(ReadMsg[21]==0)
        {
            ChangeIcon(&m_LED_AIU_SPARE_DOUT3, 2);
        }
        else
        {
            ChangeIcon(&m_LED_AIU_SPARE_DOUT3, 1);
        }
    return 0;
}


BOOL CITC_SET_DIS::PreTranslateMessage(MSG* pMsg)
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


void CITC_SET_DIS::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    DestroyWindow();
    CDialogEx::OnClose();
}
