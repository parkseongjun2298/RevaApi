#include "stdafx.h"
#include "StartButton.h"
#include "SceneMgr.h"

CStartButton::CStartButton()
{
}


CStartButton::~CStartButton()
{
	Release();
}

void CStartButton::Initiailize()
{
	m_tInfo.iCX = 113;
	m_tInfo.iCY = 41;
}

int CStartButton::Update()
{
	return 0;
}

void CStartButton::LateUpdate()
{
	CObj::UpdateRect();
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);
	// ���� �簢���� �浹�� �Ǻ����ִ� �Լ� PtInRect()- �浹�ϸ� ��, �ƴϸ� �޽� 
	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->KeyDown(VK_LBUTTON))
		{
			if (!lstrcmp(L"StartButton", m_pFrameKey))
			{
				
					CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_MENU);
					CSoundMgr::Get_Instance()->PlaySound(L"��ư������.mp3", CSoundMgr::UI);

					return;
				
			}
			
		}

		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CStartButton::Render(HDC hDC)
{
	CObj::UpdateRect();
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(m_pFrameKey);
	GdiTransparentBlt(hDC,
		m_tRect.left, m_tRect.top,
		m_tInfo.iCX, m_tInfo.iCY,
		hMemDC,
		m_tInfo.iCX * m_iDrawID, 0,
		m_tInfo.iCX, m_tInfo.iCY,
		RGB(255, 255, 255));
}

void CStartButton::Release()
{
}
