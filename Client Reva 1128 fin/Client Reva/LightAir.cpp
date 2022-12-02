#include "stdafx.h"
#include "LightAir.h"


CLightAir::CLightAir()
{
	dwTime = GetTickCount();
}


CLightAir::~CLightAir()
{
}

void CLightAir::Initiailize()
{
	m_iAtt = 1;
	m_tInfo.iCX = 154;
	m_tInfo.iCY = 168;
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/LightAirEffect.bmp", L"LightAirEffect");


	m_pFrameKey = L"LightAirEffect";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 7;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CLightAir::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (dwTime + 1000 < GetTickCount()) //스킬 이펙트 지속시간
	{
		dwTime = GetTickCount();

		m_bDead = true;

	
	}

	



	return 0;
}

void CLightAir::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CLightAir::Render(HDC hDC)
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

void CLightAir::Release()
{
}

void CLightAir::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CLightAir::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 7;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 200;   //  쿨타임/사진개수 해야 딱
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CLightAir::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
