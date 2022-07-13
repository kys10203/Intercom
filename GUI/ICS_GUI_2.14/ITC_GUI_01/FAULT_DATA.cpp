// FAULT_DATA.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "FAULT_DATA.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CFAULT_DATA 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFAULT_DATA, CDialogEx)

    CFAULT_DATA::CFAULT_DATA(CWnd* pParent /*=NULL*/)
    : CDialogEx(CFAULT_DATA::IDD, pParent)
{

    EnableAutomation();

}

CFAULT_DATA::~CFAULT_DATA()
{
}

void CFAULT_DATA::OnFinalRelease()
{
    // 자동화 개체에 대한 마지막 참조가 해제되면
    // OnFinalRelease가 호출됩니다. 기본 클래스에서 자동으로 개체를 삭제합니다.
    // 기본 클래스를 호출하기 전에 개체에 필요한 추가 정리 작업을
    // 추가하십시오.

    CDialogEx::OnFinalRelease();
}

void CFAULT_DATA::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDI_LED_F01, m_LED_F01);
    DDX_Control(pDX, IDI_LED_F02, m_LED_F02);
    DDX_Control(pDX, IDI_LED_F03, m_LED_F03);
    DDX_Control(pDX, IDI_LED_F04, m_LED_F04);
    DDX_Control(pDX, IDI_LED_F05, m_LED_F05);
    DDX_Control(pDX, IDI_LED_F06, m_LED_F06);
    DDX_Control(pDX, IDI_LED_F07, m_LED_F07);
    DDX_Control(pDX, IDI_LED_F08, m_LED_F08);
    DDX_Control(pDX, IDI_LED_F09, m_LED_F09);
    DDX_Control(pDX, IDI_LED_F10, m_LED_F10);
    DDX_Control(pDX, IDI_LED_F11, m_LED_F11);
    DDX_Control(pDX, IDI_LED_F12, m_LED_F12);
    DDX_Control(pDX, IDI_LED_F13, m_LED_F13);
    DDX_Control(pDX, IDI_LED_F14, m_LED_F14);
    DDX_Control(pDX, IDI_LED_F15, m_LED_F15);
    DDX_Control(pDX, IDI_LED_F16, m_LED_F16);
    DDX_Control(pDX, IDI_LED_F17, m_LED_F17);
    DDX_Control(pDX, IDI_LED_F18, m_LED_F18);
    DDX_Control(pDX, IDI_LED_F19, m_LED_F19);
    DDX_Control(pDX, IDI_LED_F20, m_LED_F20);
    DDX_Control(pDX, IDI_LED_F21, m_LED_F21);
    DDX_Control(pDX, IDI_LED_F22, m_LED_F22);
    DDX_Control(pDX, IDI_LED_F23, m_LED_F23);
    DDX_Control(pDX, IDI_LED_F24, m_LED_F24);
    DDX_Control(pDX, IDI_LED_F25, m_LED_F25);
    DDX_Control(pDX, IDI_LED_F26, m_LED_F26);
    DDX_Control(pDX, IDI_LED_F27, m_LED_F27);
    DDX_Control(pDX, IDI_LED_F28, m_LED_F28);
    DDX_Control(pDX, IDI_LED_F29, m_LED_F29);
    DDX_Control(pDX, IDI_LED_F30, m_LED_F30);
    DDX_Control(pDX, IDI_LED_F31, m_LED_F31);
    DDX_Control(pDX, IDI_LED_F32, m_LED_F32);
}


BEGIN_MESSAGE_MAP(CFAULT_DATA, CDialogEx)
    ON_WM_CLOSE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFAULT_DATA, CDialogEx)
END_DISPATCH_MAP()

// 참고: IID_IFAULT_DATA에 대한 지원을 추가하여
//  VBA에서 형식 안전 바인딩을 지원합니다. 
//  이 IID는 .IDL 파일에 있는 dispinterface의 GUID와 일치해야 합니다.

// {EA185368-4728-4774-BCD1-21D7757D2509}
static const IID IID_IFAULT_DATA =
{ 0xEA185368, 0x4728, 0x4774, { 0xBC, 0xD1, 0x21, 0xD7, 0x75, 0x7D, 0x25, 0x9 } };

BEGIN_INTERFACE_MAP(CFAULT_DATA, CDialogEx)
    INTERFACE_PART(CFAULT_DATA, IID_IFAULT_DATA, Dispatch)
END_INTERFACE_MAP()


// CFAULT_DATA 메시지 처리기입니다.


BOOL CFAULT_DATA::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetTimer(FAULT_DATA_STATUS, 300, NULL);

    return TRUE;  // return TRUE unless you set the focus to a control
}


void CFAULT_DATA::OnClose()
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    KillTimer(FAULT_DATA_STATUS);
    DestroyWindow();
    CDialogEx::OnClose();
}


void CFAULT_DATA::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData0 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F01, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData0 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F01, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData1 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F02, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData1 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F02, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData2 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F03, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData2 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F03, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData3 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F04, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData3 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F04, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData4 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F05, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData4 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F05, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData5== 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F06, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData5 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F06, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData6 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F07, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData6 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F07, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData7 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F08, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData7 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F08, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData8 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F09, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData8 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F09, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData9 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F10, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData9 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F10, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData10 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F11, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData10 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F11, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData11 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F12, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData11 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F12, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData12 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F13, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData12 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F13, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData13 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F14, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData13 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F14, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData14 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F15, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData14 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F15, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData15 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F16, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA1.st_AIU_FAULT_DATA.FaultData15 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F16, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData0 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F17, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData0 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F17, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData1 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F18, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData1 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F18, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData2 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F19, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData2 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F19, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData3 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F20, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData3 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F20, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData4 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F21, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData4 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F21, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData5 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F22, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData5 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F22, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData6 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F23, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData6 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F23, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData7 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F24, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData7 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F24, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData8 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F25, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData8 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F25, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData9 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F26, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData9 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F26, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData10 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F27, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData10 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F27, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData11 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F28, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData11 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F28, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData12 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F29, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData12 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F29, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData13 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F30, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData13 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F30, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData14 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F31, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData14 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F31, 0);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData15 == 0x0)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F32, 1);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_AIU_FAULT_DATA2.st_AIU_FAULT_DATA.FaultData15 == 0x1)
    {
        ((CITC_GUI_01Dlg*)GetParent())->ChangeIcon(&m_LED_F32, 0);
    }

    CDialogEx::OnTimer(nIDEvent);
}
