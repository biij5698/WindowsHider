// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
//#include "test2.h"
#include "resource.h" 
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_MY_TRAY_NOTIFICATION WM_USER+0
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_MESSAGE(WM_MY_TRAY_NOTIFICATION, OnTrayNotification)
	//ON_COMMAND(ID_VIEW_CLEAR,				OnViewClear)
	//ON_COMMAND(ID_TOGGLE_ICON,				OnToggleIcon)
	//ON_COMMAND(ID_VIEW_NOTIFICATIONS,	OnViewNotifications)
	//ON_UPDATE_COMMAND_UI(ID_VIEW_CLEAR, OnUpdateViewClear)
	//ON_UPDATE_COMMAND_UI(ID_VIEW_NOTIFICATIONS, OnUpdateViewNotifications)
	ON_WM_CLOSE()
	ON_COMMAND(ID_APP_OPEN, OnAppOpen)
	ON_COMMAND(ID_APP_SUSPEND, OnAppSuspend)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame(): m_trayIcon(IDR_TRAYICON)
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
	m_bShowTrayNotifications = TRUE;//zxn
	m_bShutdown = FALSE;//zxn
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ��������ͣ������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
 
	// Set up tray icon
	m_trayIcon.SetNotificationWnd(this, WM_MY_TRAY_NOTIFICATION);
	m_iWhichIcon = 1;
	m_trayIcon.SetIcon(IDI_MYICON);
	return 0;
}
void CMainFrame::OnClose() 
{
	if (m_bShutdown)
		CFrameWnd::OnClose();
	else
		ShowWindow(SW_HIDE);
}
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}


// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame ��Ϣ�������
LRESULT CMainFrame::OnTrayNotification(WPARAM uID, LPARAM lEvent)
{
	//if (m_bShowTrayNotifications) {
	//	static LPCSTR MouseMessages[] = { "WM_MOUSEMOVE",
	//		"WM_LBUTTONDOWN", "WM_LBUTTONUP", "WM_LBUTTONDBLCLK",
	//		"WM_RBUTTONDOWN", "WM_RBUTTONUP", "WM_RBUTTONDBLCLK",
	//		"WM_MBUTTONDOWN", "WM_MBUTTONUP", "WM_MBUTTONDBLCLK" };

	//	CString s;
	//	s.Format("����֪ͨ��Ϣ: ID=%d, lEvent=0x%04x %s\r\n", 
	//		uID, lEvent, WM_MOUSEFIRST<=lEvent && lEvent<=WM_MOUSELAST ? 
	//		MouseMessages[lEvent-WM_MOUSEFIRST] : "(δ֪��Ϣ)");

	//	m_wndEdit.SetSel(-1, -1);		// end of edit text
	//	m_wndEdit.ReplaceSel(s);		// append string..
	//	m_wndEdit.SendMessage(EM_SCROLLCARET); // ..and make visible
	//}

	// let tray icon do default stuff
	return m_trayIcon.OnTrayNotification(uID, lEvent);
}
////////////////////////////////////////////////////////////////
// Command handlers below.
//
//void CMainFrame::OnViewClear() 
//{
//	m_wndEdit.SetWindowText("");	
//}

//void CMainFrame::OnUpdateViewClear(CCmdUI* pCmdUI) 
//{
//	pCmdUI->Enable(m_wndEdit.GetLineCount() > 1 || m_wndEdit.LineLength() > 0);
//}
//
//void CMainFrame::OnToggleIcon() 
//{
//	m_iWhichIcon=!m_iWhichIcon;
//	m_trayIcon.SetIcon(m_iWhichIcon ? IDI_MYICON : IDI_MYICON2);
//}

//void CMainFrame::OnViewNotifications() 
//{
//	m_bShowTrayNotifications = !m_bShowTrayNotifications;
//}
//
//void CMainFrame::OnUpdateViewNotifications(CCmdUI* pCmdUI) 
//{
//	pCmdUI->SetCheck(m_bShowTrayNotifications);
//}

void CMainFrame::OnAppOpen() 
{
	ShowWindow(SW_NORMAL);	
	SetForegroundWindow();
}

void CMainFrame::OnAppSuspend() 
{
	m_bShutdown = TRUE;		// really exit
	SendMessage(WM_CLOSE);	
}




