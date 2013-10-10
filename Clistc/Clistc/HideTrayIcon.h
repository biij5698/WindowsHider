
#include "stdafx.h"

void HideTrayIcon(HWND hWnd,bool bShow)
{
	/*
	DWORD lngPID;
	WPARAM i;
	DWORD ret = ::GetWindowThreadProcessId(hWnd, &lngPID);
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS
        |PROCESS_VM_OPERATION
        |PROCESS_VM_READ
        |PROCESS_VM_WRITE,
        0,
        lngPID);

	LPVOID lngAddress = VirtualAllocEx(hProcess,  0,  0x4096, MEM_COMMIT, PAGE_READWRITE);
	ret = ::SendMessage(hWnd,TB_GETBUTTON,i,long(lngAddress));


	int BID;

	//ret = ::ReadProcessMemory(hProcess, LPVOID(lngTextAdr),  strBuff,  1024,  0);
	ret = ::ReadProcessMemory(hProcess, LPVOID(long(lngAddress) + 4),  &BID,  4,  0);
	*/
	int ID=(int)::SendMessage(hWnd, TB_GETBUTTON, 0, 0);

	HWND hShellTray = ::FindWindow("Shell_TrayWnd", NULL);
	if(hShellTray == NULL )
	return;
	HWND hTrayNotify = ::FindWindowEx(hShellTray, NULL, "TrayNotifyWnd", NULL);
	if(hTrayNotify == NULL)
	return;
	HWND hSysPager = ::FindWindowEx(hTrayNotify, NULL, "SysPager", NULL);
	if(hSysPager == NULL)
	return;
	HWND hToolBar = ::FindWindowEx(hSysPager, NULL, "ToolbarWindow32", NULL);
	if(hToolBar)
	{
		::SendMessage(hToolBar, TB_HIDEBUTTON, ID, !bShow);
	}
	/*
	//if(HideOrShow==0)
		::SendMessage(hWnd,   TB_HIDEBUTTON,   BID,  MAKELONG (true, 0)); //Òþ²ØÍ¼±ê
	//else if(HideOrShow==1)
		//::SendMessage(hWnd,   TB_HIDEBUTTON,   BID,  MAKELONG (false,0)); //ÏÔÊ¾Í¼±ê



	::VirtualFreeEx( hProcess,  lngAddress,  0x4096, MEM_RELEASE);
	::CloseHandle(hProcess);*/
	
	/*
	DWORD ID ; 
	::GetWindowThreadProcessId(hWnd, &ID);

	
	for(int i=ID;i<ID+5;i++)
	{
		NOTIFYICONDATA   target;
		target.cbSize   =   sizeof (NOTIFYICONDATA); 
		target.hWnd   =   hWnd; 
		target.uID   =   i; 
		target.uFlags   =   NIF_ICON|NIF_MESSAGE|NIF_TIP; 
		Shell_NotifyIcon(NIM_DELETE,   &target);
	}*/

	


}

void __fastcall ShowTrayIcon(int nIndex, bool bShow)
{
	

	HWND hShellTray = ::FindWindow("Shell_TrayWnd", NULL);
	if(hShellTray == NULL )
	return;
	HWND hTrayNotify = ::FindWindowEx(hShellTray, NULL, "TrayNotifyWnd", NULL);
	if(hTrayNotify == NULL)
	return;
	HWND hSysPager = ::FindWindowEx(hTrayNotify, NULL, "SysPager", NULL);
	if(hSysPager == NULL)
	return;
	HWND hToolBar = ::FindWindowEx(hSysPager, NULL, "ToolbarWindow32", NULL);
	if(hToolBar)
	{
		::SendMessage(hToolBar, TB_HIDEBUTTON, nIndex, !bShow);
	}
}