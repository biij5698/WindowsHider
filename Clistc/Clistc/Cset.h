#pragma once


// Cset �Ի���

class Cset : public CDialogEx
{
	DECLARE_DYNAMIC(Cset)

public:
	Cset(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cset();

// �Ի�������
	enum { IDD = IDD_Set_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
