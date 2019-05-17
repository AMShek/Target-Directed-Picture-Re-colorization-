#pragma once
#pragma pack(1)
struct Head{
	WORD type;
	DWORD size;
	DWORD no;
	DWORD off;
};

struct InfoHead{
	long length;
	long weidth;
	long height;
	WORD colorPlane;
    WORD bitColor;
    long zipFormat; 
    long realSize;
    long xPels;
    long yPels;
    long colorUse;
    long colorImportant;
};
#pragma pack()

class BMP{
private:
	Head head;

	
	int dataSize;
	RGBQUAD *palette;
public:
	BYTE* data;
	InfoHead infoHead;
	BMP(){
		data=NULL;
		palette=NULL;
		dataSize=0;
	}
	~BMP(){
		if(data!=NULL){
			delete[] data;
			data=NULL;
		}
		if(palette!=NULL){
			delete[] palette;
			palette=NULL;
		}
	}
	void read(CString fileName);
	void write(CString fileName);
	void draw(CDC* pDC, CPoint origin);
};