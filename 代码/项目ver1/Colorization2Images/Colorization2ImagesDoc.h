// Colorization2ImagesDoc.h : CColorization2ImagesDoc 类的接口
//


#pragma once
#include "BMP.h"

class CColorization2ImagesDoc : public CDocument
{
protected: // 仅从序列化创建
	CColorization2ImagesDoc();
	DECLARE_DYNCREATE(CColorization2ImagesDoc)

// 属性
public:
	BMP* sbmp;
	BMP* ssbmp;
	BMP* tbmp;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	BOOL OnSaveDocument(LPCTSTR filename);
// 实现
public:
	virtual ~CColorization2ImagesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


