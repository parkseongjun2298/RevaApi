#include "stdafx.h"
#include "FLeezer.h"
#include"Player.h"

CFLeezer::CFLeezer()
{
	dwTime = GetTickCount();
}



CFLeezer::~CFLeezer()
{
}

void CFLeezer::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/H.bmp", L"Fleezer");

	m_tInfo.iCX = 42;
	m_tInfo.iCY = 43;
	m_FleezerSpeed = 3.f;

	m_Accer = 40.f;
	m_Accer2 = 40.f;

	m_iAtt = 20;


	m_pFrameKey = L"Fleezer";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 14;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CFLeezer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (dwTime + 1000 < GetTickCount())
	{
		dwTime = GetTickCount();

		m_bDead = true;

	}

	if (PLAYER::RIGHT == static_cast<CPlayer*>(m_pPlayer)->Get_State())
	{

		m_tInfo.fX += 10;
		m_Accer -= 4.f;
		m_tInfo.fY -= m_Accer;
		m_Accer2 -= 4.f;

	}
	if (PLAYER::LEFT == static_cast<CPlayer*>(m_pPlayer)->Get_State())
	{

		m_tInfo.fX -= 10;
		m_Accer -= 4.f;
		m_tInfo.fY -= m_Accer;
		m_Accer2 -= 4.f;

	}
	

	return 0;
}

void CFLeezer::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CFLeezer::Render(HDC hDC)
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

void CFLeezer::Release()
{
}

void CFLeezer::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CFLeezer::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 14;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 100;   //  쿨타임/사진개수 해야 딱
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CFLeezer::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
