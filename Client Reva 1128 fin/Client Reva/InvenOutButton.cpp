#include "stdafx.h"
#include "InvenOutButton.h"
#include "SceneMgr.h"

CInvenOutButton::CInvenOutButton()
{
}


CInvenOutButton::~CInvenOutButton()
{
	Release();
}

void CInvenOutButton::Initiailize()
{
	m_tInfo.iCX = 24;
	m_tInfo.iCY = 22;
}

int CInvenOutButton::Update()
{
	return 0;
}

void CInvenOutButton::LateUpdate()
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
			if (!lstrcmp(L"InvenOut", m_pFrameKey))
			{

				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_CLEAR1); //���������ιٲٱ�
				
				return;

			}

		}

		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;
}

void CInvenOutButton::Render(HDC hDC)
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

void CInvenOutButton::Release()
{
}
