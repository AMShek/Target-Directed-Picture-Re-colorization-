// Colorization2ImagesDoc.h : CColorization2ImagesDoc ��Ľӿ�
//


#pragma once
#include "BMP.h"

class CColorization2ImagesDoc : public CDocument
{
protected: // �������л�����
	CColorization2ImagesDoc();
	DECLARE_DYNCREATE(CColorization2ImagesDoc)

// ����
public:
	BMP* sbmp;
	BMP* ssbmp;
	BMP* tbmp;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	BOOL OnSaveDocument(LPCTSTR filename);
// ʵ��
public:
	virtual ~CColorization2ImagesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


