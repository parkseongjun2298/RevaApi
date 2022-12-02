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
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/마우스.bmp", L"Mouse");
	m_tInfo.iCX = 69;
	m_tInfo.iCY = 69;
	// 마우스 커서 그릴지 말지 함수. 
	ShowCursor(FALSE);
}

int CMouse::Update()
{
	POINT pt = {};
	// 마우스 좌표를 얻어온다. 스크린 좌표로. 
	GetCursorPos(&pt);
	// 마우스 좌표를 스크린 좌표에서 클라이언트 좌표로 바꿔준다. 
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
	GdiTransparentBlt(hDC,//복사받을 대상 
		m_tRect.left, m_tRect.top,// 출력할 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY, // 얼마만큼 출력 할 것인지 
		hMemDC,// 복사할 대상 
		0, 0, // 그림에서의 시작 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY,// 그림에서 얼마만큼 출력할 것인지 . 
		RGB(255, 0, 255));

}

void CMouse::Release()
{
}
