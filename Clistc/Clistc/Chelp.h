#pragma once


// Chelp 对话框

class Chelp : public CDialogEx
{
	DECLARE_DYNAMIC(Chelp)

public:
	Chelp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Chelp();

// 对话框数据
	enum { IDD = IDD_Help_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
