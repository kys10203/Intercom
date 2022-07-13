// BIT_SUMMARY2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "BIT_SUMMARY2.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CBIT_SUMMARY2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBIT_SUMMARY2, CDialogEx)

CBIT_SUMMARY2::CBIT_SUMMARY2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBIT_SUMMARY2::IDD, pParent)
{

	EnableAutomation();

}

CBIT_SUMMARY2::~CBIT_SUMMARY2()
{
}

void CBIT_SUMMARY2::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CBIT_SUMMARY2::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TEXT_ARC2_LATEST_BIT, m_TEXT_ARC2_LatestBIT);
    DDX_Control(pDX, IDC_TEXT_ARC2_FIRST_MODULE, m_TEXT_ARC2_FirstModule);
    DDX_Control(pDX, IDC_TEXT_ARC2_SEC_MODULE, m_TEXT_ARC2_SecModule);
    DDX_Control(pDX, IDC_TEXT_ARC2_TRD_MODULE, m_TEXT_ARC2_TrdModule);
    DDX_Control(pDX, IDC_LED_ARC2_IBIT_RESULT, m_LED_ARC2_IBIT_Result);
    DDX_Control(pDX, IDC_LED_ARC2_POW_REG_FAULT, m_LED_ARC2_PowRegFault);
    DDX_Control(pDX, IDC_LED_ARC2_HIGH_VSWR, m_LED_ARC2_HighVSWR);
    DDX_Control(pDX, IDC_LED_ARC2_LOW_RF, m_LED_ARC2_LowRF);
    DDX_Control(pDX, IDC_LED_ARC2_HIGH_TEMP, m_LED_ARC2_HighTemp);
    DDX_Control(pDX, IDC_LED_ARC2_LOW_BATTERY, m_LED_ARC2_LowBattery);
}


BEGIN_MESSAGE_MAP(CBIT_SUMMARY2, CDialogEx)
    ON_WM_CLOSE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CBIT_SUMMARY2, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IBIT_SUMMARY2에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {176AEA64-ACED-4471-B42E-9A1ACAFE343A}
static const IID IID_IBIT_SUMMARY2 =
{ 0x176AEA64, 0xACED, 0x4471, { 0xB4, 0x2E, 0x9A, 0x1A, 0xCA, 0xFE, 0x34, 0x3A } };

BEGIN_INTERFACE_MAP(CBIT_SUMMARY2, CDialogEx)
	INTERFACE_PART(CBIT_SUMMARY2, IID_IBIT_SUMMARY2, Dispatch)
END_INTERFACE_MAP()


// CBIT_SUMMARY2 메시지 처리기입니다.


BOOL CBIT_SUMMARY2::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetTimer(BIT_SUMMARY_STATUS_2, 300, NULL);

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CBIT_SUMMARY2::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    KillTimer(BIT_SUMMARY_STATUS_2);
    DestroyWindow();
    CDialogEx::OnClose();
}


void CBIT_SUMMARY2::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    CString str;

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.LastestBIT == 0x0)
    {
        str.Format(_T("Power up"));
        m_TEXT_ARC2_LatestBIT.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.LastestBIT == 0x1)
    {
        str.Format(_T("Initiated"));
        m_TEXT_ARC2_LatestBIT.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.LastestBIT == 0x2)
    {
        str.Format(_T("Aborted"));
        m_TEXT_ARC2_LatestBIT.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.LastestBIT == 0x3)
    {
        str.Format(_T("Reserved"));
        m_TEXT_ARC2_LatestBIT.SetWindowTextW(str);
    }

    switch(((CITC_GUI_01Dlg*)GetParent())->un_FAULT_LOCATION01_ARC2.st_FAULT_LOCATION01.FirstModule)
    {
    case 0x0:
        str.Format(_T("None"));
        break;
    case 0x1:
        str.Format(_T("Front Panel"));
        break;
    case 0x2:
        str.Format(_T("Controller"));
        break;
    case 0x3:
        str.Format(_T("RES"));
        break;
    case 0x6:
        str.Format(_T("Tranmitter"));
        break;
    case 0x7:
        str.Format(_T("Interface"));
        break;
    case 0xB:
        str.Format(_T("Power Regulator"));
        break;
    case 0xC:
        str.Format(_T("Preselector/Guard"));
        break;
    case 0xF:
        str.Format(_T("RT Bus/Motherboard"));
        break;
    }
    m_TEXT_ARC2_FirstModule.SetWindowTextW(str);

    switch(((CITC_GUI_01Dlg*)GetParent())->un_FAULT_LOCATION01_ARC2.st_FAULT_LOCATION01.SecondModule)
    {
    case 0x0:
        str.Format(_T("None"));
        break;
    case 0x1:
        str.Format(_T("Front Panel"));
        break;
    case 0x2:
        str.Format(_T("Controller"));
        break;
    case 0x3:
        str.Format(_T("RES"));
        break;
    case 0x6:
        str.Format(_T("Tranmitter"));
        break;
    case 0x7:
        str.Format(_T("Interface"));
        break;
    case 0xB:
        str.Format(_T("Power Regulator"));
        break;
    case 0xC:
        str.Format(_T("Preselector/Guard"));
        break;
    case 0xF:
        str.Format(_T("RT Bus/Motherboard"));
        break;
    }
    m_TEXT_ARC2_SecModule.SetWindowTextW(str);

    switch(((CITC_GUI_01Dlg*)GetParent())->un_FAULT_LOCATION02_ARC2.st_FAULT_LOCATION02.ThirdModule)
    {
    case 0x0:
        str.Format(_T("None"));
        break;
    case 0x1:
        str.Format(_T("Front Panel"));
        break;
    case 0x2:
        str.Format(_T("Controller"));
        break;
    case 0x3:
        str.Format(_T("RES"));
        break;
    case 0x6:
        str.Format(_T("Tranmitter"));
        break;
    case 0x7:
        str.Format(_T("Interface"));
        break;
    case 0xB:
        str.Format(_T("Power Regulator"));
        break;
    case 0xC:
        str.Format(_T("Preselector/Guard"));
        break;
    case 0xF:
        str.Format(_T("RT Bus/Motherboard"));
        break;
    }
    m_TEXT_ARC2_TrdModule.SetWindowTextW(str);

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.InitiatedBITResult == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_IBIT_Result, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.InitiatedBITResult == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_IBIT_Result, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.PowerRegulatorFault == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_PowRegFault, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.PowerRegulatorFault == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_PowRegFault, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.HighVSWR == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_HighVSWR, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.HighVSWR == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_HighVSWR, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.LowRFPower == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_LowRF, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.LowRFPower == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_LowRF, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.HighTemperature == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_HighTemp, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.HighTemperature == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_HighTemp, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.LowBattery == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_LowBattery, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC2.st_BIT_SUMMARY.LowBattery == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC2_LowBattery, 0);
    }

    CDialogEx::OnTimer(nIDEvent);
}
