#include "stdafx.h"
#include "GetRingButton.h"
#include "SceneMgr.h"

CGetRingButton::CGetRingButton()
{
}


CGetRingButton::~CGetRingButton()
{
}

void CGetRingButton::Initiailize()
{
	m_tInfo.iCX = 45;
	m_tInfo.iCY = 32;
}

int CGetRingButton::Update()
{
	return 0;
}

void CGetRingButton::LateUpdate()
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
			if (!lstrcmp(L"GetRingButton", m_pFrameKey))
			{

				//CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STAGE3); //다음씬으로바꾸기

				return;

			}

		}

		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CGetRingButton::Render(HDC hDC)
{
}

void CGetRingButton::Release()
{
}
