#pragma once
#include "BMP.h"

// RE_Dlg �Ի���

class RE_Dlg : public CDialog
{
	DECLARE_DYNAMIC(RE_Dlg)

public:
	BMP* bmp;
	RE_Dlg(CWnd* pParent = NULL);   // ��׼���캯�� 
	virtual ~RE_Dlg();
	void setBMP(BMP* bmp){
		this->bmp=bmp;
	}
// �Ի�������
	enum { IDD = IDD_DIALOG_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
