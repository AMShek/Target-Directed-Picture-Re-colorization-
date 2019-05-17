// IMG1_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Colorization2Images.h"
#include "IMG1_Dlg.h"


// IMG1_Dlg 对话框

IMPLEMENT_DYNAMIC(IMG1_Dlg, CDialog)

IMG1_Dlg::IMG1_Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IMG1_Dlg::IDD, pParent)
{

}

IMG1_Dlg::~IMG1_Dlg()
{
}

void IMG1_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IMG1_Dlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// IMG1_Dlg 消息处理程序

void IMG1_Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CDC* cdc=&dc;
	
	CPoint p;
	p.x=0;
	p.y=0;
	
	bmp->draw(cdc,p);
	::MoveWindow(this->m_hWnd,100,50,bmp->infoHead.weidth+5,bmp->infoHead.height+32,true);
}
