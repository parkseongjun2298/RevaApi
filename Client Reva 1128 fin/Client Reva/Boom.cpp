#include "stdafx.h"
#include "Boom.h"


CBoom::CBoom()
{
	dwTime = GetTickCount();  //이거해야 프래임돌아감
}


CBoom::~CBoom()
{
}

void CBoom::Initiailize()
{
	m_iAtt = 1;
	m_tInfo.iCX = 300;
	m_tInfo.iCY = 300;
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/Boom.bmp", L"Boom");


	m_pFrameKey = L"Boom";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 24;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 50;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CBoom::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (dwTime + 4000 < GetTickCount()) //스킬 이펙트 지속시간
	{
		dwTime = GetTickCount();

		m_bDead = true;

	}

	m_tInfo.fX -= 1.f;

	return 0;
}

void CBoom::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CBoom::Render(HDC hDC)
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

void CBoom::Release()
{
}

void CBoom::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CBoom::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 24;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 20;   //  쿨타임/사진개수 해야 딱
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CBoom::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
