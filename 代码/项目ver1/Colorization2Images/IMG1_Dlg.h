#pragma once
#include "BMP.h"

// IMG1_Dlg对话框

class IMG1_Dlg : public CDialog
{
	DECLARE_DYNAMIC(IMG1_Dlg)

public:
	BMP* bmp;
	IMG1_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	
	void setBMP(BMP* bmp){
		this->bmp=bmp;
	}
	virtual ~IMG1_Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_IMG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
