// Cabout.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Clistc.h"
#include "Cabout.h"
#include "afxdialogex.h"


// Cabout �Ի���

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


// Cabout ��Ϣ�������


void Cabout::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
