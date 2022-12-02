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
	HBITMAP m_hBitmap; // �׸��� ���� ������ ������ ���� GDIOBJECT 
	HBITMAP m_hOldBitmp;

};

