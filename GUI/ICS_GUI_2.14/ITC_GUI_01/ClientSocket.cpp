// ClientSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ITC_GUI_01.h"
#include "ClientSocket.h"
#include "ITC_GUI_01Dlg.h"

// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket ��� �Լ�


void CClientSocket::OnClose(int nErrorCode)
{
    // TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
    ShutDown();
    Close();

    CSocket::OnClose(nErrorCode);

    AfxMessageBox(_T("ERROR:Disconnected from server!"));
	::PostQuitMessage(0);
}
