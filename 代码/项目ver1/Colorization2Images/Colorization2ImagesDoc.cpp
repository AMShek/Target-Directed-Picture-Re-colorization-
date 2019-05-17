// Colorization2ImagesDoc.cpp : CColorization2ImagesDoc 类的实现
//

#include "stdafx.h"
#include "Colorization2Images.h"

#include "Colorization2ImagesDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CColorization2ImagesDoc

IMPLEMENT_DYNCREATE(CColorization2ImagesDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorization2ImagesDoc, CDocument)
END_MESSAGE_MAP()


// CColorization2ImagesDoc 构造/析构

CColorization2ImagesDoc::CColorization2ImagesDoc()
: sbmp(NULL),tbmp(NULL),ssbmp(NULL)

{

}

CColorization2ImagesDoc::~CColorization2ImagesDoc()
{	
	if(sbmp!=NULL){
		delete sbmp;
		sbmp=NULL;
	}
	if(ssbmp!=NULL){
		delete ssbmp;
		ssbmp=NULL;
	}
	if(tbmp!=NULL){
		delete tbmp;
		tbmp=NULL;
	}
}

BOOL CColorization2ImagesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}




// CColorization2ImagesDoc 序列化

void CColorization2ImagesDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}


// CColorization2ImagesDoc 诊断

#ifdef _DEBUG
void CColorization2ImagesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorization2ImagesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif 


// CColorization2ImagesDoc 命令
BOOL CColorization2ImagesDoc::OnSaveDocument(LPCTSTR filename){
	if(strstr(filename,".bmp"))
		sbmp->write(filename);
	return true;
}