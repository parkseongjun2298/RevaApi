#include "stdafx.h"
#include "HyperSkill.h"


CHyperSkill::CHyperSkill()
{
	dwTime = GetTickCount();
}


CHyperSkill::~CHyperSkill()
{
	Release();
}

void CHyperSkill::Initiailize()
{
	
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/하이퍼.bmp", L"HyperLogo");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/HyperSkill.bmp", L"HyperSkill");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/hyper effect.bmp", L"hypereffect");
	
	m_tInfo.iCX = 244;
	m_tInfo.iCY = 141;
	m_iAtt = 2;
	m_bDead = false;

	m_pFrameKey = L"hypereffect";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 26;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 10;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CHyperSkill::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	
	

	if (dwTime + 10000 < GetTickCount())
	{
		dwTime = GetTickCount();

		m_bDead = true;

	}
	return 0;
}

void CHyperSkill::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
	
}

void CHyperSkill::Render(HDC hDC)
{

	

	//하이퍼 로고

	HDC hMemDC2 = CBitmapMgr::Get_Instance()->Get_MemDC(L"HyperLogo");
	if(m_dwOldTime2<GetTickCount())
	{ 
		m_dwOldTime2 = GetTickCount();
	GdiTransparentBlt(hDC,//복사받을 대상 
		0, 100,// 출력할 좌상단 좌표 
		455, 252, // 얼마만큼 출력 할 것인지 
		hMemDC2,// 복사할 대상 
		0, 0,// 그림에서의 시작 좌상단 좌표 
		455, 252,// 그림에서 얼마만큼 출력할 것인지 . 
		RGB(255, 0, 255));
	}
	//케릭터 모습

	HDC hMemDC3 = CBitmapMgr::Get_Instance()->Get_MemDC(L"HyperSkill");
	if (m_dwOldTime1<GetTickCount())
	{
		m_dwOldTime1 = GetTickCount();
		GdiTransparentBlt(hDC,//복사받을 대상 
			m_tRect.left, m_tRect.top,// 출력할 좌상단 좌표 
			401, 151, // 얼마만큼 출력 할 것인지 
			hMemDC3,// 복사할 대상 
			0, 0,// 그림에서의 시작 좌상단 좌표 
			401, 151,// 그림에서 얼마만큼 출력할 것인지 . 
			RGB(255, 0, 255));
	}

	//꽃 던지는거 
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(m_pFrameKey);
	
	GdiTransparentBlt(hDC,//복사받을 대상 
		m_tRect.left, m_tRect.top,// 출력할 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY, // 얼마만큼 출력 할 것인지 
		hMemDC,// 복사할 대상 
		m_tInfo.iCX * m_tFrame.iFrameStart, m_tInfo.iCY * m_tFrame.iFrameScene,// 그림에서의 시작 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY,// 그림에서 얼마만큼 출력할 것인지 . 
		RGB(255, 0, 255));

	


	CObj::UpdateRect();

}

void CHyperSkill::Release()
{
}

void CHyperSkill::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CHyperSkill::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 26;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 10;   //  쿨타임/사진개수 해야 딱
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CHyperSkill::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}


