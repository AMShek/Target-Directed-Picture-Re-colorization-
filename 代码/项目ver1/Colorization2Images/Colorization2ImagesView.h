// Colorization2ImagesView.h : CColorization2ImagesView ��Ľӿ�
//

#pragma once
#include "IMG1_DLG.h"
#include "IMG2_DLG.h"
#include "RE_DLG.h"

class CColorization2ImagesView : public CView
{
protected: // �������л�����
	CColorization2ImagesView();
	DECLARE_DYNCREATE(CColorization2ImagesView)

// ����
public:
	CColorization2ImagesDoc* GetDocument() const;
	IMG2_Dlg img2Dlg;
	IMG1_Dlg img1Dlg;
	RE_Dlg reDlg;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CColorization2ImagesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // Colorization2ImagesView.cpp �еĵ��԰汾
inline CColorization2ImagesDoc* CColorization2ImagesView::GetDocument() const
   { return reinterpret_cast<CColorization2ImagesDoc*>(m_pDocument); }
#endif

