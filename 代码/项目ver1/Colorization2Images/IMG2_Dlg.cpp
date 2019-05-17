// IMG2_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Colorization2Images.h"
#include "IMG2_Dlg.h"


// IMG2_Dlg 对话框

IMPLEMENT_DYNAMIC(IMG2_Dlg, CDialog)

IMG2_Dlg::IMG2_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IMG2_Dlg::IDD, pParent)
{

}

IMG2_Dlg::~IMG2_Dlg()
{
}

void IMG2_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IMG2_Dlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// IMG2_Dlg 消息处理程序

void IMG2_Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CDC* cdc=&dc;
	
	CPoint p;
	p.x=0;
	p.y=0;
	
	bmp->draw(cdc,p);
	::MoveWindow(this->m_hWnd,100,430,bmp->infoHead.weidth+5,bmp->infoHead.height+32,true);
}
