#include "stdafx.h"
#include "DunButton.h"
#include "SceneMgr.h"

CDunButton::CDunButton()
{
}


CDunButton::~CDunButton()
{
	Release();
}

void CDunButton::Initiailize()
{
	m_tInfo.iCX = 154;
	m_tInfo.iCY = 26;
}

int CDunButton::Update()
{
	return 0;
}

void CDunButton::LateUpdate()
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
			if (!lstrcmp(L"Dun2", m_pFrameKey))
			{
				CSoundMgr::Get_Instance()->StopSound(CSoundMgr::BGM);//��ݸ��߱�
				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STORY1);
			
				return;
			}
			else if (!lstrcmp(L"Exit", m_pFrameKey))
				DestroyWindow(g_hWND);
		}
		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CDunButton::Render(HDC hDC)
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

void CDunButton::Release()
{
}
