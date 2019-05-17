#include "stdafx.h"
#include "BMP.h"

void BMP::read(CString fileName){
	
	//if (data!=NULL){//处理多次读取的情况
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


	int biBitCount = infoHead.bitColor;//定义变量，计算图像每行像素所占的字节数（必须是4的倍数）
	int lineByte=(infoHead.weidth * biBitCount/8+3)/4*4;//灰度图像有颜色表，且颜色表表项为256
	dataSize=lineByte * infoHead.height;//更新正文信息大小
	
	//申请位图数据所需要的空间，读位图数据进内存
	data = new BYTE[dataSize];
    fread(data,1,dataSize,f);

	fclose(f);
	
};
void BMP::write(CString fileName){
	FILE * fp = fopen(fileName,"wb");
	if(!fp) 
		return;
	//检查是否是bmp文件
	if (head.type!=0x4d42)
	{
		fclose(fp);
		AfxMessageBox("This is not a BMP file.\n");
		return;

    }
	infoHead.bitColor=24;
	fwrite(&head, 1, sizeof(Head), fp);
	fwrite(&infoHead, 1, sizeof(InfoHead), fp);
	
	////8位的单独处理调色板
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
   
    // 设置显示模式    
    pDC->SetStretchBltMode(COLORONCOLOR);   
   
    // 在设备的origin位置上画图象 
	BITMAPINFO* lpbmif=(BITMAPINFO*)HeapAlloc(GetProcessHeap(),0,sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD));

	memcpy(&(lpbmif->bmiHeader),&infoHead,sizeof(InfoHead));
	if(infoHead.bitColor==8)
		memcpy(lpbmif->bmiColors,palette,256 * sizeof(RGBQUAD));

	//lpbmif->bmiColors
	::StretchDIBits(pDC->GetSafeHdc(), origin.x, origin.y,infoHead.weidth,infoHead.height,   
	0, 0, infoHead.weidth, infoHead.height,data,lpbmif, DIB_RGB_COLORS, SRCCOPY);   
	
    return;   
}   
