#include "stdafx.h"
#include "FlameBullet.h"


CFlameBullet::CFlameBullet()
{
}

CFlameBullet::CFlameBullet(float fx, float fy)
{
	m_tInfo.fX = fx;
	m_tInfo.fY = fy;
}


CFlameBullet::~CFlameBullet()
{
}

void CFlameBullet::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/총알.bmp", L"FlameBullet");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/총알L.bmp", L"FlameBullet_L");
	m_tInfo.iCX = 75;
	m_tInfo.iCY = 23;
	m_fGun_Speed = 5.f;
	m_eDir2 = BULLET2::RIGHT;
	m_iAtt = 20;


	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CFlameBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	switch (m_eDir2)
	{
	case BULLET2::LEFT:
		m_tInfo.fX -= m_fGun_Speed;
		m_pFrameKey = L"FlameBullet_L";
		m_eNextState = STATE_IDLE;
		break;
	case BULLET2::RIGHT:
		m_pFrameKey = L"FlameBullet";
		m_eNextState = STATE_IDLE;
		m_tInfo.fX += m_fGun_Speed;
		break;
	default:
		break;
	}
	return 0;
}

void CFlameBullet::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CFlameBullet::Render(HDC hDC)
{
	CObj::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(m_pFrameKey);
	//BitBlt(hDC, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0, SRCCOPY);
	GdiTransparentBlt(hDC,//복사받을 대상 
		m_tRect.left, m_tRect.top,// 출력할 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY, // 얼마만큼 출력 할 것인지 
		hMemDC,// 복사할 대상 
		m_tInfo.iCX * m_tFrame.iFrameStart, m_tInfo.iCY * m_tFrame.iFrameScene,// 그림에서의 시작 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY,// 그림에서 얼마만큼 출력할 것인지 . 
		RGB(255, 0, 255));
}

void CFlameBullet::Release()
{
}

void CFlameBullet::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{
		case CFlameBullet::STATE_IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 50;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
	

		case CFlameBullet::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
