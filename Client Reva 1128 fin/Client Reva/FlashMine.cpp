#include "stdafx.h"
#include "FlashMine.h"


CFlashMine::CFlashMine()
{
	dwTime = GetTickCount();
}


CFlashMine::~CFlashMine()
{
}

void CFlashMine::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/w.bmp", L"FlashMine");
	//m_time = GetTickCount();
	m_tInfo.iCX = 99;
	m_tInfo.iCY = 102;
	m_iAtt = 1;

	m_pFrameKey = L"FlashMine";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 35;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 40;
	m_tFrame.dwFrameTime = GetTickCount();
	
}

int CFlashMine::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (dwTime + 1666 < GetTickCount())
	{
		dwTime = GetTickCount();

		m_bDead = true;

	}
	return 0;
	

}

void CFlashMine::LateUpdate()
{
	
	FrameChange();
	CObj::FrameMove();
}

void CFlashMine::Render(HDC hDC)
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

void CFlashMine::Release()
{
}

void CFlashMine::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CFlashMine::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 35;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 50;   //  쿨타임/사진개수 해야 딱
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CFlashMine::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}

