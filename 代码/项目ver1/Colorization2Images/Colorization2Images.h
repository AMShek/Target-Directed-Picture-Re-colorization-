// Colorization2Images.h : Colorization2Images Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"   


class CColorization2ImagesApp : public CWinApp
{
public:
	CColorization2ImagesApp();
public:
	virtual BOOL InitInstance();
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CColorization2ImagesApp theApp;
