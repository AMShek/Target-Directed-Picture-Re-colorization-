#pragma once
#include "BMP.h"

// IMG2_Dlg �Ի���

class IMG2_Dlg : public CDialog
{
	DECLARE_DYNAMIC(IMG2_Dlg)

public:
	BMP* bmp;
	IMG2_Dlg(CWnd* pParent = NULL);   //��׼���캯��
	IMG2_Dlg(BMP* bmp,CWnd* pParent = NULL): CDialog(IMG2_Dlg::IDD, pParent){
		this->bmp=bmp;
	}
	void setBMP(BMP* bmp){
		this->bmp=bmp;
	}
	virtual ~IMG2_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_IMG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
