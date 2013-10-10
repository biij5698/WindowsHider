// Cabout.cpp : 实现文件
//

#include "stdafx.h"
#include "Clistc.h"
#include "Cabout.h"
#include "afxdialogex.h"


// Cabout 对话框

IMPLEMENT_DYNAMIC(Cabout, CDialogEx)

Cabout::Cabout(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cabout::IDD, pParent)
{

}

Cabout::~Cabout()
{
}

void Cabout::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cabout, CDialogEx)
	ON_BN_CLICKED(IDOK, &Cabout::OnBnClickedOk)
END_MESSAGE_MAP()


// Cabout 消息处理程序


void Cabout::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
