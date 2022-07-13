// PRESET_STATUS2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "PRESET_STATUS2.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CPRESET_STATUS2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPRESET_STATUS2, CDialogEx)

CPRESET_STATUS2::CPRESET_STATUS2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPRESET_STATUS2::IDD, pParent)
{

	EnableAutomation();

}

CPRESET_STATUS2::~CPRESET_STATUS2()
{
}

void CPRESET_STATUS2::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CDialogEx::OnFinalRelease();
}

void CPRESET_STATUS2::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TEXT_ARC2_GROUPSELECT, m_TEXT_ARC2_GroupSelect);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ01, m_TEXT_ARC2_Freq01);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ02, m_TEXT_ARC2_Freq02);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ03, m_TEXT_ARC2_Freq03);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ04, m_TEXT_ARC2_Freq04);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ05, m_TEXT_ARC2_Freq05);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ06, m_TEXT_ARC2_Freq06);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ07, m_TEXT_ARC2_Freq07);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ08, m_TEXT_ARC2_Freq08);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ09, m_TEXT_ARC2_Freq09);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ10, m_TEXT_ARC2_Freq10);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG01, m_TEXT_ARC2_FreqMng01);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG02, m_TEXT_ARC2_FreqMng02);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG03, m_TEXT_ARC2_FreqMng03);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG04, m_TEXT_ARC2_FreqMng04);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG05, m_TEXT_ARC2_FreqMng05);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG06, m_TEXT_ARC2_FreqMng06);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG07, m_TEXT_ARC2_FreqMng07);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG08, m_TEXT_ARC2_FreqMng08);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG09, m_TEXT_ARC2_FreqMng09);
    DDX_Control(pDX, IDC_TEXT_ARC2_FREQ_MNG10, m_TEXT_ARC2_FreqMng10);
}


BEGIN_MESSAGE_MAP(CPRESET_STATUS2, CDialogEx)
    ON_WM_CLOSE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPRESET_STATUS2, CDialogEx)
END_DISPATCH_MAP()

// ����: IID_IPRESET_STATUS2�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {61BA0EBF-7A3C-45FB-9096-B86DF9A4AABE}
static const IID IID_IPRESET_STATUS2 =
{ 0x61BA0EBF, 0x7A3C, 0x45FB, { 0x90, 0x96, 0xB8, 0x6D, 0xF9, 0xA4, 0xAA, 0xBE } };

BEGIN_INTERFACE_MAP(CPRESET_STATUS2, CDialogEx)
	INTERFACE_PART(CPRESET_STATUS2, IID_IPRESET_STATUS2, Dispatch)
END_INTERFACE_MAP()


// CPRESET_STATUS2 �޽��� ó�����Դϴ�.


void CPRESET_STATUS2::OnClose()
{
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
    KillTimer(PRESET_STATUS_2);
    DestroyWindow();
    CDialogEx::OnClose();
}


BOOL CPRESET_STATUS2::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetTimer(PRESET_STATUS_2, 300, NULL);

    return TRUE;  // return TRUE unless you set the focus to a control
}


void CPRESET_STATUS2::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
    CString str;

    str.Format(_T("%d"), ((CITC_GUI_01Dlg*)GetParent())->un_PRESET_GROUP_SELECT_ARC2.st_PRESET_GROUP_SELECT.GroupSelect); 
    m_TEXT_ARC2_GroupSelect.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_01_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_01_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_01_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_01_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_01_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_01_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq01.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_02_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_02_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_02_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_02_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_02_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_02_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq02.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_03_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_03_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_03_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_03_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_03_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_03_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq03.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_04_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_04_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_04_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_04_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_04_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_04_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq04.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_05_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_05_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_05_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_05_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_05_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_05_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq05.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_06_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_06_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_06_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_06_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_06_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_06_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq06.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_07_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_07_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_07_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_07_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_07_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_07_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq07.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_08_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_08_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_08_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_08_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_08_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_08_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq08.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_09_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_09_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_09_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_09_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_09_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_09_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq09.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_10_ARC2.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_10_ARC2.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_10_ARC2.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_10_ARC2.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_10_ARC2.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_10_ARC2.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC2_Freq10.SetWindowTextW(str);

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_01_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng01.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_01_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng01.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_02_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng02.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_02_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng02.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_03_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng03.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_03_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng03.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_04_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng04.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_04_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng04.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_05_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng05.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_05_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng05.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_06_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng06.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_06_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng06.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_07_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng07.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_07_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng07.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_08_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng08.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_08_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng08.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_09_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng09.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_09_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng09.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_10_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC2_FreqMng10.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_10_ARC2.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC2_FreqMng10.SetWindowTextW(str);
    }

    CDialogEx::OnTimer(nIDEvent);
}
