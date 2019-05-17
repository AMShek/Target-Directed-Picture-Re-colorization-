// Colorization2ImagesDoc.cpp : CColorization2ImagesDoc ���ʵ��
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


// CColorization2ImagesDoc ����/����

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




// CColorization2ImagesDoc ���л�

void CColorization2ImagesDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}


// CColorization2ImagesDoc ���

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


// CColorization2ImagesDoc ����
BOOL CColorization2ImagesDoc::OnSaveDocument(LPCTSTR filename){
	if(strstr(filename,".bmp"))
		sbmp->write(filename);
	return true;
}