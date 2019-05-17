#pragma once
#include "BMP.h"

// RE_Dlg 对话框

class RE_Dlg : public CDialog
{
	DECLARE_DYNAMIC(RE_Dlg)

public:
	BMP* bmp;
	RE_Dlg(CWnd* pParent = NULL);   // 标准构造函数 
	virtual ~RE_Dlg();
	void setBMP(BMP* bmp){
		this->bmp=bmp;
	}
// 对话框数据
	enum { IDD = IDD_DIALOG_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
