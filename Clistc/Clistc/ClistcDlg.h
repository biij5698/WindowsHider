
// ClistcDlg.h : 头文件
//



#include "ListCtrlEx.h"
#include "MyVolumeCtrl.h"

#pragma once

#define MYWM_NOTIFYICON WM_USER+1


// CClistcDlg 对话框
class CClistcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClistcDlg)
// 构造
public:
	CClistcDlg(CWnd* pParent = NULL);	// 标准构造函数
	CString GetProcessName(int ProcessID, bool fullpath =false);

// 对话框数据
	enum { IDD = IDD_CLISTC_DIALOG };
	CListCtrlEx	m_List;
	CString	m_WindowsFound;
	CButton m_check;
	NOTIFYICONDATA m_tnid;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	int m_margin;
	HWND m_mWnd;
	
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCheck1();
	afx_msg void On32776();
	afx_msg void On32774();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

public:
	vector<HWND> ClickChecked;
	CMyVolumeCtrl MC;

	
	afx_msg void Onabout();
	afx_msg void OnHelp();
	afx_msg void Onset();
};







/*
int HandleComp(CString s1, CString s2)
{
	char* stop;
	s1 = "0X" + s1.Mid(1);
	long i1 = strtol(s1,&stop,16);
	s2 = "0X" + s2.Mid(1);
	long i2 = strtol(s2,&stop,16);
	if(i1==i2)return 0;
	if(i1<i2) return -1;
	return 1;

}*/
