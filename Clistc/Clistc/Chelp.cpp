// Chelp.cpp : 实现文件
//

#include "stdafx.h"
#include "Clistc.h"
#include "Chelp.h"
#include "afxdialogex.h"


// Chelp 对话框

IMPLEMENT_DYNAMIC(Chelp, CDialogEx)

Chelp::Chelp(CWnd* pParent /*=NULL*/)
	: CDialogEx(Chelp::IDD, pParent)
{

}

Chelp::~Chelp()
{
}

void Chelp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Chelp, CDialogEx)
END_MESSAGE_MAP()


// Chelp 消息处理程序
