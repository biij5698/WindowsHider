// MainFrm.h : CMainFrame ��Ľӿ�
//


#pragma once

#include "trayicon.h"
class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
protected:
	CStatusBar  m_wndStatusBar;

	CTrayIcon	m_trayIcon;		// my tray icon
	CEdit			m_wndEdit;		// to display tray notifications
	int			m_iWhichIcon;	// 0/1 which HICON to use
	BOOL			m_bShutdown;	// OK to terminate TRAYTEST
	BOOL			m_bShowTrayNotifications;	// display info in main window

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	//CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnTrayNotification(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnClose();
	afx_msg void OnAppOpen();
	afx_msg void OnAppSuspend();
};


