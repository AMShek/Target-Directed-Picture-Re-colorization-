// Colorization2ImagesView.cpp : CColorization2ImagesView 类的实现
//

#include "stdafx.h"
#include "Colorization2Images.h"

#include "Colorization2ImagesDoc.h"
#include "Colorization2ImagesView.h"

#include<math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CColorization2ImagesView

IMPLEMENT_DYNCREATE(CColorization2ImagesView, CView)

BEGIN_MESSAGE_MAP(CColorization2ImagesView, CView)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_OPEN_SRC, &CColorization2ImagesView::OnOpenSrc)
	ON_COMMAND(ID_OPEN_TE, &CColorization2ImagesView::OnOpenTe)
	ON_COMMAND(ID_COLOR, &CColorization2ImagesView::OnColor)
END_MESSAGE_MAP()


CColorization2ImagesView::CColorization2ImagesView()
{
	img1Dlg.Create(IDD_DIALOG_IMG1) ; 
	img2Dlg.Create(IDD_DIALOG_IMG2) ; 
}

CColorization2ImagesView::~CColorization2ImagesView()
{

}

BOOL CColorization2ImagesView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

void CColorization2ImagesView::OnDraw(CDC* /*pDC*/)
{
	CColorization2ImagesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}

BOOL CColorization2ImagesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CColorization2ImagesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CColorization2ImagesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

#ifdef _DEBUG
void CColorization2ImagesView::AssertValid() const
{
	CView::AssertValid();
}

void CColorization2ImagesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CColorization2ImagesDoc* CColorization2ImagesView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorization2ImagesDoc)));
	return (CColorization2ImagesDoc*)m_pDocument;
}
#endif 

void CColorization2ImagesView::OnOpenSrc()
{
	CColorization2ImagesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST);
	dlg.m_ofn.nFilterIndex = 1;
	int hResult = (int)dlg.DoModal();
	if(FAILED(hResult)||dlg.GetFileName()=="") {
		return;
	}
	if(pDoc->sbmp!=NULL){
		delete pDoc->sbmp;
		pDoc->sbmp=NULL;
	}
	pDoc->sbmp=new BMP();
	pDoc->sbmp->read(dlg.GetFileName());
	
	pDoc->ssbmp=new BMP();
	pDoc->ssbmp->read(dlg.GetFileName());

	img1Dlg.setBMP(pDoc->ssbmp);
	  
	img1Dlg.ShowWindow(SW_SHOW);

}

void CColorization2ImagesView::OnOpenTe()
{
	CColorization2ImagesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST);
	dlg.m_ofn.nFilterIndex = 1;
	int hResult = (int)dlg.DoModal();
	if(FAILED(hResult)||dlg.GetFileName()=="") {
		return;
	}
	if(pDoc->tbmp!=NULL){
		delete pDoc->tbmp;
		pDoc->tbmp=NULL;
	}
	pDoc->tbmp=new BMP();
	pDoc->tbmp->read(dlg.GetFileName());

	
	img2Dlg.setBMP(pDoc->tbmp);
	  
	img2Dlg.ShowWindow(SW_SHOW);

}

/*************************************************************************
 * function name：
 *   swap(double &a,double &b)
 * parameters:
 *   double &a                     
 *   double &b                     
 * return value:
 *   void               
 * objective:
 *      swapping
 ************************************************************************/
void swap(double &a,double &b)
{double c=a;a=b;b=c;};

/*************************************************************************
 * function name：
 *   DinV(double A[3][3],int n)
 * parameters:
 *   double A[3][3]             matrix to inverse
 *   int n                      size of matrix
 * return value:
 *   void               
 * objective:
 *      matrix inversion
 ************************************************************************/
int DinV(double A[3][3],int n)
{
	int i,j,k;
	double d;
	int JS[3],IS[3];
	for (k=0;k<n;k++)
	{
		d=0;
		for (i=k;i<n;i++)
			for (j=k;j<n;j++)
			{
				if (fabs(A[i][j])>d)
				{
					d=fabs(A[i][j]);
					IS[k]=i;
					JS[k]=j;
				}
			}
			if (d+1.0==1.0) 
				return 0;
			if (IS[k]!=k)
				for (j=0;j<n;j++)
					swap(A[k][j],A[IS[k]][j]);
			if (JS[k]!=k)
				for (i=0;i<n;i++)
					swap(A[i][k],A[i][JS[k]]);
			A[k][k]=1/A[k][k];
			for (j=0;j<n;j++)
				if (j!=k) 
					A[k][j]=A[k][j]*A[k][k];
			for (i=0;i<n;i++)
				if (i!=k)
					for (j=0;j<n;j++)
						if (j!=k) 
							A[i][j]=A[i][j]-A[i][k]*A[k][j];
			for (i=0;i<n;i++)
				if (i!=k) 
					A[i][k]=-A[i][k]*A[k][k];
	}
	for (k=n-1;k>=0;k--)
	{
		for (j=0;j<n;j++)
			if (JS[k]!=k) 
				swap(A[k][j],A[JS[k]][j]);
		for (i=0;i<n;i++)
			if (IS[k]!=k) 
				swap(A[i][k],A[i][IS[k]]);
	}


}


/*************************************************************************
 * function name：
 *   RGB2Lab(double R ,double G, double B, double &l,double &a ,double &b)
 * parameters:
 *   double R             
 *   double G             =
 *   double B             
 *   double &l            
 *   double &a            
 *   double &b            
 * return value:
 *   void               
 * objective:
 *      RGB space -> lab space
 ************************************************************************/
double BLACK = 20;
double YELLOW = 70;
void RGB2Lab(double R ,double G, double B, double &l,double &a ,double &b)
{
	double X,Y,Z,fX,fY,fZ;

	X = 0.412453*R + 0.357580*G + 0.180423*B;
	Y = 0.212671*R + 0.715160*G + 0.072169*B;
	Z = 0.019334*R + 0.119193*G + 0.950227*B;

	X /= (255 * 0.950456);
	Y /=  255;
	Z /= (255 * 1.088754);

	if (Y > 0.008856)
	{
		fY = pow(Y,1.0/3.0);
		l = 116.0*fY - 16.0;
	}
	else
	{
		fY = 7.787*Y + 16.0/116.0;
		l = 903.3*Y;
	}

	if (X > 0.008856)
		fX = pow(X,1.0/3.0);
	else
		fX = 7.787*X + 16.0/116.0;

	if (Z > 0.008856)
		fZ = pow(Z,1.0/3.0);
	else
		fZ = 7.787*Z + 16.0/116.0;

	a = 500.0*(fX - fY);
	b = 200.0*(fY - fZ);

	if (l < BLACK)
	{
		a *= exp((l - BLACK) / (BLACK / 4));
		b *= exp((l - BLACK) / (BLACK / 4));
		l = BLACK;
	}
	if (b > YELLOW)
		b = YELLOW;


}

/*************************************************************************
 * function name：
 *   Lab2RGB(double l, double a ,double b ,double &R ,double &G ,double &B)
 * parameters:
 *   double l             
 *   double a             
 *   double b             
 *   double &R            
 *   double &G            
 *   double &B            
 * return value:
 *   void               
 * objective:
 *      lab space -> RGB space
 ************************************************************************/
void Lab2RGB(double l, double a ,double b ,double &R ,double &G ,double &B)
{
	double X,Y,Z,fX,fY,fZ;
	double RR,GG,BB;

	fY = pow((l + 16.0) / 116.0,3.0);
	if (fY < 0.008856)
		fY = l / 903.3;
	Y = fY;

	if (fY > 0.008856)
		fY = pow(fY,1.0/3.0);
	else
		fY = 7.787 * fY + 16.0/116.0;

	fX = a / 500.0 + fY;
	if (fX > 0.206893)
		X = pow(fX,3.0);
	else
		X = (fX - 16.0/116.0) / 7.787;

	fZ = fY - b /200.0;
	if (fZ > 0.206893)
		Z = pow(fZ,3.0);
	else
		Z = (fZ - 16.0/116.0) / 7.787;

	X *= (0.950456 * 255);
	Y *=             255;
	Z *= (1.088754 * 255);

	RR =  3.240479*X - 1.537150*Y - 0.498535*Z;
	GG = -0.969256*X + 1.875992*Y + 0.041556*Z;
	BB =  0.055648*X - 0.204043*Y + 1.057311*Z;

	R = (float)(RR < 0 ? 0 : RR > 255 ? 255 : RR);
	G = (float)(GG < 0 ? 0 : GG > 255 ? 255 : GG);
	B = (float)(BB < 0 ? 0 : BB > 255 ? 255 : BB);
}





/*************************************************************************
 * function name：
 *   transLAB(byte * RGBArray,int weidth,int height ,double *LABArray)
 * parameters:
 *   byte * RGBArray            
 *   int weidth                 
 *   int height                 
 *   double *LABArray           
 * return value:
 *   void               
 * objective:
 *      data points in RGB -> convert and store in LABArray in lab space
*		call function RGB2Lab
 ************************************************************************/
void transLAB(byte * RGBArray,int weidth,int height ,double *LABArray)
{
	byte *lpData;
	int lineByte=(weidth * 3+3)/4*4;
	double r,g,b;
	int LABindex=0;

	for(int i=0;i<height;i++)
	{
		for(int j=0;j<weidth;j++)
		{
		
			lpData=RGBArray+lineByte*i+j*3;
			r=(double)(*(lpData));
			g=(double)(*(lpData+1));
			b=(double)(*(lpData+2));


            RGB2Lab(r,g,b,LABArray[LABindex],LABArray[LABindex+1],LABArray[LABindex+2]);
            LABindex=LABindex+3;
		}
	}

}


/*************************************************************************
 * function name：
 *   transRGB(byte *RGBArray,int weidth,int height ,double *LABArray)
 * parameters:
 *   byte * RGBArray           
 *   int weidth                 
 *   int height                 
 *   double *LABArray           
 * return value:
 *   void               
 * objective:
 *      data points in lab space -> convert and store in RGBArray in RGB space
*		call function Lab2RGB
 ************************************************************************/
void transRGB(byte *RGBArray,int weidth,int height ,double *LABArray)
{

	int lineByte=(weidth * 3+3)/4*4;
	double r,g,b;
	double ll,aa,bb;
	int LABindex=0;


	for(int i=0;i<height;i++)
	{
		for(int j=0;j<weidth;j++)
		{
	
			LABindex=(weidth*i+j)*3;
			ll=LABArray[LABindex];
			aa=LABArray[LABindex+1];
			bb=LABArray[LABindex+2];

			
			Lab2RGB(ll,aa,bb,r,g,b);

		
			RGBArray[(lineByte*i+j*3)]=(byte)(int)(r+0.5);
			RGBArray[(lineByte*i+j*3)+1]=(byte)(int)(g+0.5);
			RGBArray[(lineByte*i+j*3)+2]=(byte)(int)(b+0.5);
		}

	}

}


/*************************************************************************
 * function name：
 *   getMeans(double * arr,int n,double & l_means,double & a_means,double & b_means)
 * parameters:
 *   double * arr            
 *   int n                   
 *   double & l_means        
 *   double & a_means        
 *   double & b_means        
 * return value:
 *   void               
 * objective:
 *		get the mean of data points in lab space
 ************************************************************************/
void getMeans(double * arr,int n,double & l_means,double & a_means,double & b_means)
{
	double sum_l=0,sum_a=0,sum_b=0;
	for(int i=0;i<n*3;i+=3)
	{
		sum_l += arr[i];
		sum_a += arr[i+1];
		sum_b += arr[i+2];
	}

	l_means = sum_l / n;
	a_means = sum_a / n;
	b_means = sum_b / n;
}


/*************************************************************************
 * function name：
 *   getStdError(double * arr,int n,double & l_err,double & a_err,double & b_err,double l_m,double a_m,double b_m)
 * parameters:
 *   double * arr            
 *   int n                   
 *   double & l_err          
 *   double & a_err          
 *   double & b_err          
 *   double l_m            
 *   double a_m              
 *   double b_m            
 * return value:
 *   void               
 * objective:
 *      get the standard deviation of data points in lab space
 ************************************************************************/
void getStdError(double * arr,int n,double & l_err,double & a_err,double & b_err,double l_m,double a_m,double b_m)
{
	double sum_l=0,sum_a=0,sum_b=0;
	for(int i=0;i<n*3;i+=3)
	{
		sum_l += pow( (arr[i] - l_m) , 2);
		sum_a += pow( (arr[i+1] - a_m) , 2);
		sum_b += pow( (arr[i+2] - b_m) , 2);
	}

	l_err = sqrt(sum_l / n);
	a_err = sqrt(sum_a / n);
	b_err = sqrt(sum_b / n);

}


void CColorization2ImagesView::OnColor()
{
	CColorization2ImagesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int sh=pDoc->sbmp->infoHead.height;
	int sw=pDoc->sbmp->infoHead.weidth;
	int th=pDoc->tbmp->infoHead.height;
	int tw=pDoc->tbmp->infoHead.weidth;
	double* sLAB=new double[sh*sw*3];
	double* tLAB=new double[th*tw*3];

	//space conversion - RGB to lab
	transLAB(pDoc->sbmp->data,sw ,sh,sLAB);
	transLAB(pDoc->tbmp->data,tw ,th,tLAB);

	//color processing - the standard deviation and mean of the image to be colorized
	double sl_means,sa_means,sb_means;
	double sl_StdError,sa_StdError,sb_StdError;
	getMeans(sLAB,sh*sw,sl_means,sa_means,sb_means);
	getStdError(sLAB,sh*sw,sl_StdError,sa_StdError,sb_StdError,sl_means,sa_means,sb_means);

	//color processing - the standard deviation and mean of the target image
	double tl_means,ta_means,tb_means;
	double tl_StdError,ta_StdError,tb_StdError;
	getMeans(tLAB,th*tw,tl_means,ta_means,tb_means);
	getStdError(tLAB,th*tw,tl_StdError,ta_StdError,tb_StdError,tl_means,ta_means,tb_means);

	for(long i=0;i<sh*sw*3;i=i+3){
		sLAB[i]=tl_StdError/sl_StdError*(sLAB[i]-sl_means)+tl_means;
		sLAB[i+1]=ta_StdError/sa_StdError*(sLAB[i+1]-sa_means)+ta_means;		
		sLAB[i+2]=tb_StdError/sb_StdError*(sLAB[i+2]-sb_means)+tb_means;	
	}
	
	//space conversion - lab to RGB
	transRGB(pDoc->sbmp->data,sw,sh ,sLAB);

	reDlg.setBMP(pDoc->sbmp);
	reDlg.Create(IDD_DIALOG_RESULT) ;   
	reDlg.ShowWindow(SW_SHOW);
}


