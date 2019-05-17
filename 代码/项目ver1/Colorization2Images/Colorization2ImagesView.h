// Colorization2ImagesView.h : CColorization2ImagesView 类的接口
//

#pragma once
#include "IMG1_DLG.h"
#include "IMG2_DLG.h"
#include "RE_DLG.h"

class CColorization2ImagesView : public CView
{
protected: // 仅从序列化创建
	CColorization2ImagesView();
	DECLARE_DYNCREATE(CColorization2ImagesView)

// 属性
public:
	CColorization2ImagesDoc* GetDocument() const;
	IMG2_Dlg img2Dlg;
	IMG1_Dlg img1Dlg;
	RE_Dlg reDlg;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CColorization2ImagesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpenSrc();

public:
	afx_msg void OnOpenTe();
public:
	afx_msg void OnColor();
public:
	afx_msg void On32777();
};

#ifndef _DEBUG  // Colorization2ImagesView.cpp 中的调试版本
inline CColorization2ImagesDoc* CColorization2ImagesView::GetDocument() const
   { return reinterpret_cast<CColorization2ImagesDoc*>(m_pDocument); }
#endif

