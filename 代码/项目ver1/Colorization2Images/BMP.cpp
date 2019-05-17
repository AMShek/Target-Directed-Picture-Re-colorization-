#include "stdafx.h"
#include "BMP.h"

void BMP::read(CString fileName){
	
	//if (data!=NULL){//�����ζ�ȡ�����
	//	delete[] data;
	//	data=NULL;
	//}
	FILE* f;
	f = fopen(fileName,"rb");

    if (f == NULL)
    {
		AfxMessageBox(fileName);
    }

    fread(&head,sizeof(Head),1,f);
	int a=sizeof(Head);
    fread(&infoHead,sizeof(InfoHead),1,f);

	if (head.type!=0x4d42)
	{
		fclose(f);
		AfxMessageBox("This is not a BMP file.\n");
		return;

    }
	if (infoHead.bitColor == 8)
    {
		fseek(f,256*sizeof(RGBQUAD),SEEK_CUR);
		if(palette==NULL){
			palette=new RGBQUAD[256];
			for(int i=0;i<256;i++){
				palette[i].rgbBlue=i;
				palette[i].rgbGreen=i;
				palette[i].rgbRed=i;
			}
		}
		
	}else if(infoHead.bitColor != 24){
		fclose(f);
		AfxMessageBox("can only load 24 or 8 BMP file.\n");
		return;
	}


	int biBitCount = infoHead.bitColor;//�������������ͼ��ÿ��������ռ���ֽ�����������4�ı�����
	int lineByte=(infoHead.weidth * biBitCount/8+3)/4*4;//�Ҷ�ͼ������ɫ������ɫ�����Ϊ256
	dataSize=lineByte * infoHead.height;//����������Ϣ��С
	
	//����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�
	data = new BYTE[dataSize];
    fread(data,1,dataSize,f);

	fclose(f);
	
};
void BMP::write(CString fileName){
	FILE * fp = fopen(fileName,"wb");
	if(!fp) 
		return;
	//����Ƿ���bmp�ļ�
	if (head.type!=0x4d42)
	{
		fclose(fp);
		AfxMessageBox("This is not a BMP file.\n");
		return;

    }
	infoHead.bitColor=24;
	fwrite(&head, 1, sizeof(Head), fp);
	fwrite(&infoHead, 1, sizeof(InfoHead), fp);
	
	////8λ�ĵ��������ɫ��
	//if(infoHead.bitColor==8){
	//	fwrite(palette,256*sizeof(RGBQUAD),1,fp);
	//}
	fwrite(data, 1, dataSize, fp );
	fclose(fp);
}

void BMP::draw(CDC* pDC, CPoint origin)   
{   
	if (head.type!=0x4d42)
	{
		AfxMessageBox("This is not a BMP file.\n");
		return;

    }
   
    // ������ʾģʽ    
    pDC->SetStretchBltMode(COLORONCOLOR);   
   
    // ���豸��originλ���ϻ�ͼ�� 
	BITMAPINFO* lpbmif=(BITMAPINFO*)HeapAlloc(GetProcessHeap(),0,sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD));

	memcpy(&(lpbmif->bmiHeader),&infoHead,sizeof(InfoHead));
	if(infoHead.bitColor==8)
		memcpy(lpbmif->bmiColors,palette,256 * sizeof(RGBQUAD));

	//lpbmif->bmiColors
	::StretchDIBits(pDC->GetSafeHdc(), origin.x, origin.y,infoHead.weidth,infoHead.height,   
	0, 0, infoHead.weidth, infoHead.height,data,lpbmif, DIB_RGB_COLORS, SRCCOPY);   
	
    return;   
}   
