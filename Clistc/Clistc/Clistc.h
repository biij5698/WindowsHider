
// Clistc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CClistcApp:
// �йش����ʵ�֣������ Clistc.cpp
//

class CClistcApp : public CWinApp
{
public:
	CClistcApp();

// ��д
public:
	virtual BOOL InitInstance();
	

// ʵ��
	DECLARE_MESSAGE_MAP()
};

extern CClistcApp theApp;