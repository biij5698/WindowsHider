#pragma once


// Chelp �Ի���

class Chelp : public CDialogEx
{
	DECLARE_DYNAMIC(Chelp)

public:
	Chelp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Chelp();

// �Ի�������
	enum { IDD = IDD_Help_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
