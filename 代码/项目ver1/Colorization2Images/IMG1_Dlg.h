#pragma once
#include "BMP.h"

// IMG1_Dlg�Ի���

class IMG1_Dlg : public CDialog
{
	DECLARE_DYNAMIC(IMG1_Dlg)

public:
	BMP* bmp;
	IMG1_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	
	void setBMP(BMP* bmp){
		this->bmp=bmp;
	}
	virtual ~IMG1_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_IMG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
