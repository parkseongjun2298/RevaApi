#pragma once
class CBmp
{
public:
	CBmp();
	~CBmp();
public:
	HDC Get_MemDC() { return m_hMemDC; }
public:
	void Insert_Bitmap(const TCHAR* pFilePath);
	void Release();
private:
	HDC m_hMemDC;
	HBITMAP m_hBitmap; // 그림에 대한 정보를 가지고 있을 GDIOBJECT 
	HBITMAP m_hOldBitmp;

};

