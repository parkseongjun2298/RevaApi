#include "stdafx.h"
#include "Bmp.h"


CBmp::CBmp()
{
}


CBmp::~CBmp()
{
	Release();
}
void CBmp::Insert_Bitmap(const TCHAR * pFilePath)
{
	// ���� ��ȭ���� ����� ���ؼ��� ���� �׷����� �ִ� ��ȭ���� ������ �˾ƾ���. �׷��� ����. 
	HDC hDC = GetDC(g_hWND);

	// ��ȭ���� ����µ� ���� �־��� ���ڿ� ȣȯ�̵Ǵ� ��ȭ���� ����ڴ�. 
	// -CreateCompatibleDC(hDC) - ���� �־��� ���ڿ� ȣȯ�� �Ǵ� DC�� ������ִ� �Լ�. 
	m_hMemDC = CreateCompatibleDC(hDC);

	// DC�� �ý��� �ڿ��̹Ƿ� ���԰� �ٽ����� �ݵ�� ��������Ѵ�. 
	ReleaseDC(g_hWND, hDC);

	// LoadImage�� �׸��� �׸��ܰ谡 �ƴ϶� ������ ������ �ܰ� . 
	/*LoadImage(1.���α׷� �ν��Ͻ� �ڵ� - ���� ���α׷��� ������� ���� ���̶�� �־��ִ°� ������ �츮�� ������ ������� �׸��� ���ð�.
	2. ������ ���
	3. �̹������� Ȥ�� Ŀ�� Ȥ�� ������ ��� ���� ����� ������������ ���� ����.
	4. 5. �׸��� ������ xy �ΰ��� �޴´�.
	6. �о���� ���� - ���� �־��� ���ڴ� LR_LOADFROMFILE - ���Ϸκ��� �о���ڴ� | LR_CREATEDIBSECTION - ��Ʈ�� ��� ����� DIB�������� ����ϰԵ�
	) ������ GDI ������Ʈ�� ��ȯ. ���н� null�� ��ȯ.
	*/
	m_hBitmap = (HBITMAP)LoadImage(nullptr, pFilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// �� ������ ���� �׸��� �׷ȴ� ��� ǥ���� �� �ְڴ�. 
	//SelectObject( DC�� ������Ʈ�� ����ϴ� �Լ� ( 1. � DC����, 2. � GDI������Ʈ����.  
	// �� �Լ��� ��ȯ�ϴ� ���� ���� ��ϵǾ� �ִ� GDI������Ʈ�� ��ȯ ���ش�. 
	// GDI������Ʈ�� �� �ϳ��� ���õɼ� �ִ�. 
	m_hOldBitmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void CBmp::Release()
{

	SelectObject(m_hMemDC, m_hOldBitmp);
	DeleteObject(m_hBitmap);
	// DC�� ���ﶧ ����ϴ� �Լ� 
	//�����ϰ��� �ϴ� DC�� �Ѱ��ָ� ��.
	//�� ���� �� ���� ���� DC�� ���õ� GDIOBJECT�� ����� ����. 
	//������ ���� ���ǰ� �ִ� ��ü�� �Ժη� �����ϵ��� ������ �Ѽ� ���� ������ ���� ������ ���� ��ġ������ �ϴ� ����������. 
	// �׸��Ͽ� ���� �ִ� GDIOBJECT�� �־��ְ� ��� ������ ���� �츮�� ���� OBJECT�� ������� �Ѵ�. 

	DeleteDC(m_hMemDC);
}
