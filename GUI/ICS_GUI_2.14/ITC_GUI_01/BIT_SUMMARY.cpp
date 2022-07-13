// BIT_SUMMARY.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "BIT_SUMMARY.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CBIT_SUMMARY 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBIT_SUMMARY, CDialogEx)

CBIT_SUMMARY::CBIT_SUMMARY(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBIT_SUMMARY::IDD, pParent)
{

	EnableAutomation();

}

CBIT_SUMMARY::~CBIT_SUMMARY()
{
}

void CBIT_SUMMARY::OnFinalRelease()
{
	// 자동화 개체에 대한 마지막 참조가 해제되면
	// OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
	// 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
	// 추가하십시오.

	CDialogEx::OnFinalRelease();
}

void CBIT_SUMMARY::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TEXT_ARC1_LATEST_BIT, m_TEXT_ARC1_LatestBIT);
    DDX_Control(pDX, IDC_TEXT_ARC1_FIRST_MODULE, m_TEXT_ARC1_FirstModule);
    DDX_Control(pDX, IDC_TEXT_ARC1_SEC_MODULE, m_TEXT_ARC1_SecModule);
    DDX_Control(pDX, IDC_TEXT_ARC1_TRD_MODULE, m_TEXT_ARC1_TrdModule);
    DDX_Control(pDX, IDC_LED_ARC1_IBIT_RESULT, m_LED_ARC1_IBIT_Result);
    DDX_Control(pDX, IDC_LED_ARC1_POW_REG_FAULT, m_LED_ARC1_PowRegFault);
    DDX_Control(pDX, IDC_LED_ARC1_HIGH_VSWR, m_LED_ARC1_HighVSWR);
    DDX_Control(pDX, IDC_LED_ARC1_LOW_RF, m_LED_ARC1_LowRF);
    DDX_Control(pDX, IDC_LED_ARC1_HIGH_TEMP, m_LED_ARC1_HighTemp);
    DDX_Control(pDX, IDC_LED_ARC1_LOW_BATTERY, m_LED_ARC1_LowBattery);
}


BEGIN_MESSAGE_MAP(CBIT_SUMMARY, CDialogEx)
    ON_WM_CLOSE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CBIT_SUMMARY, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IBIT_SUMMARY에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {2EDCFB4E-D184-4558-9296-5923016A44D5}
static const IID IID_IBIT_SUMMARY =
{ 0x2EDCFB4E, 0xD184, 0x4558, { 0x92, 0x96, 0x59, 0x23, 0x1, 0x6A, 0x44, 0xD5 } };

BEGIN_INTERFACE_MAP(CBIT_SUMMARY, CDialogEx)
	INTERFACE_PART(CBIT_SUMMARY, IID_IBIT_SUMMARY, Dispatch)
END_INTERFACE_MAP()


// CBIT_SUMMARY 메시지 처리기입니다.


BOOL CBIT_SUMMARY::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetTimer(BIT_SUMMARY_STATUS, 300, NULL);

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CBIT_SUMMARY::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    KillTimer(BIT_SUMMARY_STATUS);
    DestroyWindow();
    CDialogEx::OnClose();
}


void CBIT_SUMMARY::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    CString str;

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.LastestBIT == 0x0)
    {
        str.Format(_T("Power up"));
        m_TEXT_ARC1_LatestBIT.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.LastestBIT == 0x1)
    {
        str.Format(_T("Initiated"));
        m_TEXT_ARC1_LatestBIT.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.LastestBIT == 0x2)
    {
        str.Format(_T("Aborted"));
        m_TEXT_ARC1_LatestBIT.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.LastestBIT == 0x3)
    {
        str.Format(_T("Reserved"));
        m_TEXT_ARC1_LatestBIT.SetWindowTextW(str);
    }

    switch(((CITC_GUI_01Dlg*)GetParent())->un_FAULT_LOCATION01_ARC1.st_FAULT_LOCATION01.FirstModule)
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
    m_TEXT_ARC1_FirstModule.SetWindowTextW(str);

    switch(((CITC_GUI_01Dlg*)GetParent())->un_FAULT_LOCATION01_ARC1.st_FAULT_LOCATION01.SecondModule)
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
    m_TEXT_ARC1_SecModule.SetWindowTextW(str);

    switch(((CITC_GUI_01Dlg*)GetParent())->un_FAULT_LOCATION02_ARC1.st_FAULT_LOCATION02.ThirdModule)
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
    m_TEXT_ARC1_TrdModule.SetWindowTextW(str);

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.InitiatedBITResult == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_IBIT_Result, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.InitiatedBITResult == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_IBIT_Result, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.PowerRegulatorFault == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_PowRegFault, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.PowerRegulatorFault == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_PowRegFault, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.HighVSWR == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_HighVSWR, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.HighVSWR == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_HighVSWR, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.LowRFPower == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_LowRF, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.LowRFPower == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_LowRF, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.HighTemperature == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_HighTemp, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.HighTemperature == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_HighTemp, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.LowBattery == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_LowBattery, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_BIT_SUMMARY_ARC1.st_BIT_SUMMARY.LowBattery == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_ARC1_LowBattery, 0);
    }

    CDialogEx::OnTimer(nIDEvent);
}
