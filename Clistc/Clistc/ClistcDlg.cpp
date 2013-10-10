
// ClistcDlg.cpp : ʵ���ļ�
//


#include "stdafx.h"
#include "Clistc.h"
#include "ClistcDlg.h"
#include "afxdialogex.h"
#include "HideTrayIcon.h"
#include "Cabout.h"
#include "Chelp.h"
#include "Cset.h"

#include <sstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClistcDlg �Ի���

IMPLEMENT_DYNAMIC(CClistcDlg, CDialog)

CClistcDlg::CClistcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClistcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CClistcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_List);
	DDX_Control(pDX, IDC_CHECK1, m_check);
}

BEGIN_MESSAGE_MAP(CClistcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CClistcDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CClistcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CClistcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CClistcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CClistcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK1, &CClistcDlg::OnBnClickedCheck1)
	ON_WM_DESTROY()
	ON_COMMAND(ID_32776, &CClistcDlg::On32776)
	ON_COMMAND(ID_32774, &CClistcDlg::On32774)
	ON_COMMAND(ID_about, &CClistcDlg::Onabout)
	ON_COMMAND(ID_HELP, &CClistcDlg::OnHelp)
	ON_COMMAND(ID_set, &CClistcDlg::Onset)
END_MESSAGE_MAP()


// CClistcDlg ��Ϣ�������

BOOL CClistcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	m_mWnd = NULL;
	int col=0;
	m_List.AddColumn("",	col++,40);
	//m_List.AddColumn("Handle",	col++,70); m_List.SetColumnSortCallback(col-1,HandleComp);
	//m_List.AddColumn("Process",	col++,100);
	//m_List.AddColumn("Enabled",	col++,25);
	m_List.AddColumn("��������",	col++,450);
	m_List.AddColumn("����ID",		col++,73,LVCFMT_RIGHT); m_List.SetColumnSortCallback(col-1,IntComp);
	//m_List.AddColumn("����",	col++,50,LVCFMT_CENTER);
	//m_List.AddColumn("����",	col++,200);
	//m_List.AddColumn("Parent",	col++,150);
	m_List.SetExtendedStyle(
		 LVS_EX_CHECKBOXES            //ѡ��
        |LVS_EX_FULLROWSELECT     //��������ѡ��
        //|LVS_EX_HEADERDRAGDROP    //���������ҷ
        |LVS_EX_ONECLICKACTIVATE //������ʾ
        |LVS_EX_GRIDLINES          //����������
		|LVS_EX_FLATSB        //��ƽ��������
		);

	CRect rlist,r;
	m_List.GetWindowRect(rlist);
	GetWindowRect(r);
	ScreenToClient(r);
	ScreenToClient(rlist);
	m_margin = r.Width() - rlist.left - rlist.Width();


	OnBnClickedButton1();	//ˢ���б�
	

	//��������ͼ����Ϣ
	m_tnid.cbSize=sizeof(NOTIFYICONDATA);
	m_tnid.hWnd=this->m_hWnd;
	m_tnid.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
	m_tnid.uCallbackMessage=MYWM_NOTIFYICON;
	CString szToolTip;
	szToolTip=_T("������������");
	_tcscpy(m_tnid.szTip, szToolTip);
	m_tnid.uID=IDR_MAINFRAME;
	HICON hIcon;
	hIcon=AfxGetApp()->LoadIcon(IDI_MYICON);
	m_tnid.hIcon=hIcon;
	::Shell_NotifyIcon(NIM_ADD,&m_tnid);
	if(hIcon)
	{
		::DestroyIcon(hIcon);
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void CClistcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CClistcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CClistcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClistcDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)				//�б���趨
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;
	/*
	if(pNMLV->uNewState == 0) 
		return;

	int pos = pNMLV->iItem;

	if (pos<0) 
		return;

	m_mWnd = HWND(pNMLV->lParam);
	*/

	int i;
	int nItemCount = m_List.GetItemCount();
	
	for (i = 0; i < nItemCount; ++i)
	{
		if (m_List.GetCheck(i))
		{	
			ClickChecked.push_back(HWND(pNMLV->lParam));
		}
	}

	/*
	for (i = 1; i <= nItemCount;i++)
	{
		if (m_List.GetCheck(i)==0 && ClickChecked[i]!=NULL)
		{	
			vector<HWND>::iterator result =find( ClickChecked.begin( ), ClickChecked.end( ),ClickChecked[i] );
			ClickChecked.erase(result);
		}
	}	*/
}




void CClistcDlg::OnBnClickedButton1()					//ˢ�°�ť
{
	m_List.DelAll();

	// search windows:
	char title[512], titlepadre[512], clase[100];
	HWND mWnd = NULL;
	HWND mWndPad = NULL;
	HWND mWndSys = NULL;
	mWnd = ::FindWindowEx(NULL,mWnd,NULL,NULL);

	int ii=0;
	while ( mWnd )
	{
		::GetWindowText(mWnd, title, 256);
		::GetClassName(mWnd, clase, 100);
		CString vis = ::IsWindowVisible(mWnd)?"��":"��";
		CString ena = ::IsWindowEnabled(mWnd)?"��":"��";

		CString Cadena = "";
		mWndPad = mWnd;
		CString TitPad = "";
		memset(titlepadre,0,512);
		/*do
		{
			mWndPad = ::GetParent(mWndPad);
			if (mWndPad)
				if(m_ParentHandler.GetCheck()!=0)
					sprintf(titlepadre,"#%X",mWndPad);
				else
					::GetWindowText(mWndPad, titlepadre, 256);
			TitPad = titlepadre;
			TitPad.TrimRight();
			Cadena = CString(mWndPad?CString((TitPad=="")?"[no title]":TitPad):"[Desktop]") + CString(" :: ") + Cadena;
		}
		while (mWndPad);*/

		
		CString Tit = title;
		if(Tit=="")Tit="[no title]";
		
		DWORD wd=0;
		GetWindowThreadProcessId(mWnd,&wd);
		stringstream ss,ssw;
		ss<<wd;
		CString proc;
		//bool full = m_FullPath.GetCheck() != 0;
		//proc = GetProcessName(wd,full);
		
		if(vis=="��" || Tit=="������������ V1.0" || Tit=="Program Manager" || Tit=="��ʼ" || Tit=="[no title]")
		{mWnd = ::GetNextWindow(mWnd,GW_HWNDNEXT);continue;}
		
		int col=0;
		ssw<<"#"<<uppercase<<hex<<(int)mWnd;
		m_List.AddItem(ii,col++,"");
		//m_List.AddItem(ii,col++,ssw.str());
		//m_List.AddItem(ii,col++,proc);
		//m_List.AddItem(ii,col++,ena);
		m_List.AddItem(ii,col++,Tit);
		m_List.AddItem(ii,col++,ss.str());
		//m_List.AddItem(ii,col++,vis);
		//m_List.AddItem(ii,col++,clase);
		//m_List.AddItem(ii,col++,Cadena);
		m_List.SetItemData(ii,DWORD(mWnd));

		ii++;

		mWnd = ::GetNextWindow(mWnd,GW_HWNDNEXT);
	}


	ostringstream ss;
	ss<<"Windows found ("<<ii<<"):";
	m_WindowsFound = ss.str().c_str();
	ss.str("");
	UpdateData(FALSE);
}


void CClistcDlg::OnBnClickedButton2()					//���ذ�ť
{
	//::ShowWindow(m_mWnd,SW_HIDE);
	//vecChecked.push_back(m_mWnd);
	
	int count=ClickChecked.size();
	int i;
	for(i=0;i<count;i++)
	{
		HideTrayIcon(ClickChecked[i],false);
		//ShowTrayIcon(4,false);
		::ShowWindow(ClickChecked[i],SW_HIDE);
	}
	if(m_check.GetCheck() && i>0)
			MC.SetMute(0,1);
}



void CClistcDlg::OnBnClickedButton3()             //��ʾ��ť
{
	//::ShowWindow(m_mWnd,SW_SHOW);
	//vecChecked.pop_back();

	int count=ClickChecked.size();
	for(int i=count-1;i>=0;i--)
	{
		HideTrayIcon(ClickChecked[i],true);
		//ShowTrayIcon(4,true);
		::ShowWindow(ClickChecked[i],SW_SHOW);
		ClickChecked.pop_back();
		//m_List.SetItemState(i, 0, LVIS_SELECTED|LVIS_FOCUSED);	
	}

	if(m_check.GetCheck())
		MC.SetMute(0,0);

	OnBnClickedButton1();
}



void CClistcDlg::OnBnClickedButton4()				//�˳���ť
{
	::Shell_NotifyIcon(NIM_DELETE,&m_tnid);
	while(!ClickChecked.empty())
	{
		HWND SP;
		SP=ClickChecked[ClickChecked.size()-1];
		ClickChecked.pop_back();
		::ShowWindow(SP,SW_SHOW);
	}
	MC.SetMute(0,0);
	::exit(0);
}


void CClistcDlg::OnBnClickedCheck1()
{
}



LRESULT CClistcDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case MYWM_NOTIFYICON:
	   	 //������û��������Ϣ
	   	 if(lParam==WM_LBUTTONDBLCLK)
	   	  {
	   	   //���˫��ʱ�����ڳ���
	   	   	AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOW);
	   	  }
		  else if(lParam==WM_RBUTTONDOWN)
	   	  { 
			  //����Ҽ���������ѡ��
	   	     CMenu menu;
	   	     menu.LoadMenu(IDR_MENU1); //�������ȶ����ѡ��
	   	     CMenu* pMenu=menu.GetSubMenu(0);
	   	     CPoint pos;
	   	     GetCursorPos(&pos);
	   	     pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,pos.x,pos.y,AfxGetMainWnd());
	   	  }
		 break;
	case WM_SYSCOMMAND:
		if(wParam==SC_MINIMIZE || wParam==SC_CLOSE)
		{
   		    //���յ���С����Ϣʱ����������
			AfxGetApp()->m_pMainWnd->ShowWindow(SW_HIDE);
			return 0;
		}

		break;
	}
	return CDialog::WindowProc(message, wParam, lParam);
}



void CClistcDlg::On32776()					//����-�˳�
{
	//::Shell_NotifyIcon(NIM_DELETE,&m_tnid);
	OnBnClickedButton4();	
}


void CClistcDlg::On32774()					//����-��ʾ������
{
	ShowWindow(SW_SHOW);
}


void CClistcDlg::Onabout()
{
	// TODO: �ڴ���������������
	Cabout dlg;
	dlg.DoModal();
}


void CClistcDlg::OnHelp()
{
	// TODO: �ڴ���������������
	Chelp dlg;
	dlg.DoModal();
}


void CClistcDlg::Onset()
{
	// TODO: �ڴ���������������
	Cset dlg;
	dlg.DoModal();
}
