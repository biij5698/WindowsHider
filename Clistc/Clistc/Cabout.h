#pragma once


// Cabout �Ի���

class Cabout : public CDialogEx
{
	DECLARE_DYNAMIC(Cabout)

public:
	Cabout(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cabout();

// �Ի�������
	enum { IDD = IDD_About_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
