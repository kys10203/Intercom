// PRESET_STATUS.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "PRESET_STATUS.h"
#include "afxdialogex.h"
#include "ITC_GUI_01Dlg.h"

// CPRESET_STATUS ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPRESET_STATUS, CDialogEx)

    CPRESET_STATUS::CPRESET_STATUS(CWnd* pParent /*=NULL*/)
    : CDialogEx(CPRESET_STATUS::IDD, pParent)
{

    EnableAutomation();

}

CPRESET_STATUS::~CPRESET_STATUS()
{
}

void CPRESET_STATUS::OnFinalRelease()
{
    // �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
    // OnFinalRelease�� ȣ��˴ϴ�. �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
    // �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
    // �߰��Ͻʽÿ�.

    CDialogEx::OnFinalRelease();
}

void CPRESET_STATUS::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TEXT_ARC1_GROUPSELECT, m_TEXT_ARC1_GroupSelect);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ01, m_TEXT_ARC1_Freq01);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ02, m_TEXT_ARC1_Freq02);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ03, m_TEXT_ARC1_Freq03);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ04, m_TEXT_ARC1_Freq04);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ05, m_TEXT_ARC1_Freq05);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ06, m_TEXT_ARC1_Freq06);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ07, m_TEXT_ARC1_Freq07);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ08, m_TEXT_ARC1_Freq08);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ09, m_TEXT_ARC1_Freq09);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ10, m_TEXT_ARC1_Freq10);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG01, m_TEXT_ARC1_FreqMng01);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG02, m_TEXT_ARC1_FreqMng02);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG03, m_TEXT_ARC1_FreqMng03);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG04, m_TEXT_ARC1_FreqMng04);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG05, m_TEXT_ARC1_FreqMng05);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG06, m_TEXT_ARC1_FreqMng06);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG07, m_TEXT_ARC1_FreqMng07);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG08, m_TEXT_ARC1_FreqMng08);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG09, m_TEXT_ARC1_FreqMng09);
    DDX_Control(pDX, IDC_TEXT_ARC1_FREQ_MNG10, m_TEXT_ARC1_FreqMng10);
}


BEGIN_MESSAGE_MAP(CPRESET_STATUS, CDialogEx)
    ON_WM_CLOSE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPRESET_STATUS, CDialogEx)
END_DISPATCH_MAP()

// ����: IID_IPRESET_STATUS�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�. 
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {1EE600BB-74FE-46A4-93D3-6463B699D9F3}
static const IID IID_IPRESET_STATUS =
{ 0x1EE600BB, 0x74FE, 0x46A4, { 0x93, 0xD3, 0x64, 0x63, 0xB6, 0x99, 0xD9, 0xF3 } };

BEGIN_INTERFACE_MAP(CPRESET_STATUS, CDialogEx)
    INTERFACE_PART(CPRESET_STATUS, IID_IPRESET_STATUS, Dispatch)
END_INTERFACE_MAP()


// CPRESET_STATUS �޽��� ó�����Դϴ�.


void CPRESET_STATUS::OnClose()
{
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
    KillTimer(PRESET_STATUS);
    DestroyWindow();
    CDialogEx::OnClose();
}


BOOL CPRESET_STATUS::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetTimer(PRESET_STATUS, 300, NULL);

    return TRUE;  // return TRUE unless you set the focus to a control

}


void CPRESET_STATUS::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
    CString str;

    str.Format(_T("%d"), ((CITC_GUI_01Dlg*)GetParent())->un_PRESET_GROUP_SELECT_ARC1.st_PRESET_GROUP_SELECT.GroupSelect); 
    m_TEXT_ARC1_GroupSelect.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_01_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_01_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_01_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_01_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_01_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_01_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq01.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_02_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_02_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_02_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_02_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_02_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_02_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq02.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_03_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_03_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_03_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_03_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_03_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_03_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq03.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_04_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_04_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_04_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_04_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_04_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_04_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq04.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_05_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_05_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_05_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_05_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_05_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_05_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq05.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_06_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_06_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_06_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_06_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_06_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_06_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq06.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_07_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_07_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_07_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_07_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_07_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_07_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq07.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_08_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_08_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_08_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_08_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_08_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_08_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq08.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_09_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_09_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_09_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_09_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_09_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_09_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq09.SetWindowTextW(str);

    str.Format(_T("%d%d%d.%d%d%d"), ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_10_ARC1.st_FREQUENCY.HundredsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_10_ARC1.st_FREQUENCY.TensDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_10_ARC1.st_FREQUENCY.OnesDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_COARSE_FREQUENCY_10_ARC1.st_FREQUENCY.TenthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_10_ARC1.st_FINE_FREQUENCY_AND_AJ.HundredthsDigit
        , ((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_10_ARC1.st_FINE_FREQUENCY_AND_AJ.ThousandthsDigit );
    m_TEXT_ARC1_Freq10.SetWindowTextW(str);

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_01_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng01.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_01_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng01.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_02_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng02.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_02_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng02.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_03_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng03.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_03_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng03.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_04_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng04.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_04_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng04.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_05_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng05.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_05_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng05.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_06_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng06.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_06_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng06.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_07_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng07.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_07_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng07.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_08_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng08.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_08_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng08.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_09_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng09.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_09_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng09.SetWindowTextW(str);
    }

    if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_10_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x0)
    {
        str.Format(_T("FIXED FREQ"));
        m_TEXT_ARC1_FreqMng10.SetWindowTextW(str);
    }
    else if(((CITC_GUI_01Dlg*)GetParent())->un_FINE_FREQUENCY_AND_AJ_10_ARC1.st_FINE_FREQUENCY_AND_AJ.FrequncyManagement == 0x1)
    {
        str.Format(_T("HQ ACTIVE"));
        m_TEXT_ARC1_FreqMng10.SetWindowTextW(str);
    }

    CDialogEx::OnTimer(nIDEvent);
}
