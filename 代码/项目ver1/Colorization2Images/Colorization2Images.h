// Colorization2Images.h : Colorization2Images 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
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
