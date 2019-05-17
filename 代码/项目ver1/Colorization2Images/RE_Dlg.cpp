// RE_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Colorization2Images.h"
#include "RE_Dlg.h"


// RE_Dlg 对话框

IMPLEMENT_DYNAMIC(RE_Dlg, CDialog)

RE_Dlg::RE_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(RE_Dlg::IDD, pParent)
{

}

RE_Dlg::~RE_Dlg()
{
}

void RE_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RE_Dlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// RE_Dlg 消息处理程序

void RE_Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CDC* cdc=&dc;
	
	CPoint p;
	p.x=0;
	p.y=0;
	
	bmp->draw(cdc,p);
	::MoveWindow(this->m_hWnd,600,100,bmp->infoHead.weidth+5,bmp->infoHead.height+32,true);
}
