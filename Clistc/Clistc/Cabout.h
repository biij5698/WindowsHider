#pragma once


// Cabout 对话框

class Cabout : public CDialogEx
{
	DECLARE_DYNAMIC(Cabout)

public:
	Cabout(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cabout();

// 对话框数据
	enum { IDD = IDD_About_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
