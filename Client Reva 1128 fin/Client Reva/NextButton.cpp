#include "stdafx.h"
#include "NextButton.h"
#include "SceneMgr.h"

CNextButton::CNextButton()
{
}


CNextButton::~CNextButton()
{
	Release();
}

void CNextButton::Initiailize()
{
	m_tInfo.iCX = 181;
	m_tInfo.iCY = 31;
}

int CNextButton::Update()
{
	return 0;
}

void CNextButton::LateUpdate()
{
	CObj::UpdateRect();
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);
	// 점과 사각형의 충돌을 판별해주는 함수 PtInRect()- 충돌하면 참, 아니면 펄스 
	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->KeyDown(VK_LBUTTON))
		{
			if (!lstrcmp(L"NextButton", m_pFrameKey))
			{

				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STAGE4); //다음씬으로바꾸기
				CSoundMgr::Get_Instance()->PlayBGM(L"보스전브금.mp3");
				return;

			}

		}

		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CNextButton::Render(HDC hDC)
{
	CObj::UpdateRect();
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(m_pFrameKey);
	GdiTransparentBlt(hDC,
		m_tRect.left, m_tRect.top,
		m_tInfo.iCX, m_tInfo.iCY,
		hMemDC,
		m_tInfo.iCX * m_iDrawID, 0,
		m_tInfo.iCX, m_tInfo.iCY,
		RGB(255, 0, 255));
}

void CNextButton::Release()
{
}
