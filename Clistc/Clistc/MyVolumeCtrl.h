#pragma once

#include <commctrl.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <devicetopology.h>
#include <Audioclient.h>

#define EXIT_ON_ERROR(hres)  \
              if (FAILED(hres)) { goto Exit; }
#define SAFE_RELEASE(punk)  \
	if ((punk) != NULL)  \
{ (punk)->Release(); (punk) = NULL; }




typedef enum WindowsType //ö�ٲ���ϵͳ����
{
	UnknownOS = 0,
	WindowsXP = 1,
	WindowsVista = 2,
	Windows7 = 3,
};


#define MAX_VOL 100 //�����������Ϊ100

class CMyVolumeCtrl
{

public:
	CMyVolumeCtrl(void);
	~CMyVolumeCtrl(void);
	int GetMaxVol(); //����������
	int GetMinVol(); //�����С����
	int GetVolume(int nType); //��õ�ǰ����
	BOOL SetVolume(int nType,int nVol); //��������
	BOOL SetMute(int nType,BOOL bMute); //���þ���״̬
	BOOL GetMute(int nType); //��ȡ����״̬

protected: 
	BOOL vInitEndPoint(int nType);
	BOOL vMuteSet(int nType,BOOL bMute);
	BOOL vMuteGet(int nType);
	BOOL vVolumeSet(int nType,DWORD dwVolume);
	BOOL vVolumeGet(int nType,DWORD* pdwVolume);
	BOOL vUninitEndPoint();
	
protected:
	WindowsType vGetWindowsType();//��õ�ǰ����ϵͳ����

protected:
	WindowsType m_eWinType;
	IDeviceTopology *pDeviceTopology;
	IAudioEndpointVolume *m_pEndptVolCtrl;
	IMMDeviceEnumerator *m_pEnumerator;
	IAudioVolumeLevel *m_pVolumeLevel;
	GUID m_guidMyContext;

public:
	float VMin,VMax,VStep;
	IMMDevice *m_pDevice;
	BOOL SelectCaptureDevice(IMMDevice *pEndptDev);
	BOOL getMicrophoneBoostVolumeLevel(IMMDevice *pEndptDev);
	BOOL GetMicLevelRange();
	BOOL SetMicLevel(float fValue);
};
