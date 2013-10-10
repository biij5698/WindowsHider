// Cset.cpp : 实现文件
//

#include "stdafx.h"
#include "Clistc.h"
#include "Cset.h"
#include "afxdialogex.h"


// Cset 对话框

IMPLEMENT_DYNAMIC(Cset, CDialogEx)

Cset::Cset(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cset::IDD, pParent)
{

}

Cset::~Cset()
{
}

void Cset::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cset, CDialogEx)
END_MESSAGE_MAP()


// Cset 消息处理程序
