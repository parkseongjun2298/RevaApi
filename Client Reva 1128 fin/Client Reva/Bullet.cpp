#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}
CBullet::CBullet(float fx, float fy)
{
	m_tInfo.fX = fx;
	m_tInfo.fY = fy;
}

CBullet::~CBullet()
{
}

void CBullet::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/총알2.bmp", L"Bullet");
	m_tInfo.iCX = 12;
	m_tInfo.iCY = 11;
	m_fGun_Speed = 5.f;
	m_eDir = BULLET::RIGHT;
	m_iAtt = 10;
}

int CBullet::Update()
{

	if (m_bDead)
		return OBJ_DEAD;
	switch (m_eDir)
	{
	case BULLET::LEFT:
		m_tInfo.fX -= m_fGun_Speed;
		break;
	case BULLET::RIGHT:
		m_tInfo.fX += m_fGun_Speed;
		break;
	default:
		break;
	}
	return 0;

}

void CBullet::LateUpdate()
{
}

void CBullet::Render(HDC hDC)
{
	CObj::UpdateRect();
	
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Bullet");
	//BitBlt(hDC, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0, SRCCOPY);
	GdiTransparentBlt(hDC,//복사받을 대상 
		m_tRect.left, m_tRect.top,// 출력할 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY, // 얼마만큼 출력 할 것인지 
		hMemDC,// 복사할 대상 
		0, 0, // 그림에서의 시작 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY,// 그림에서 얼마만큼 출력할 것인지 . 
		RGB(255, 0, 255));



}

void CBullet::Release()
{
}
