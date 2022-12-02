#include "stdafx.h"
#include "Mouse.h"


CMouse::CMouse()
{
}


CMouse::~CMouse()
{
}

void CMouse::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/���콺.bmp", L"Mouse");
	m_tInfo.iCX = 69;
	m_tInfo.iCY = 69;
	// ���콺 Ŀ�� �׸��� ���� �Լ�. 
	ShowCursor(FALSE);
}

int CMouse::Update()
{
	POINT pt = {};
	// ���콺 ��ǥ�� ���´�. ��ũ�� ��ǥ��. 
	GetCursorPos(&pt);
	// ���콺 ��ǥ�� ��ũ�� ��ǥ���� Ŭ���̾�Ʈ ��ǥ�� �ٲ��ش�. 
	ScreenToClient(g_hWND, &pt);
	m_tInfo.fX = float(pt.x);
	m_tInfo.fY = static_cast<float>(pt.y);

	return 0;
}

void CMouse::LateUpdate()
{
}

void CMouse::Render(HDC hDC)
{
	
	CObj::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Mouse");
	//BitBlt(hDC, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0, SRCCOPY);
	GdiTransparentBlt(hDC,//������� ��� 
		m_tRect.left, m_tRect.top,// ����� �»�� ��ǥ 
		m_tInfo.iCX, m_tInfo.iCY, // �󸶸�ŭ ��� �� ������ 
		hMemDC,// ������ ��� 
		0, 0, // �׸������� ���� �»�� ��ǥ 
		m_tInfo.iCX, m_tInfo.iCY,// �׸����� �󸶸�ŭ ����� ������ . 
		RGB(255, 0, 255));

}

void CMouse::Release()
{
}
