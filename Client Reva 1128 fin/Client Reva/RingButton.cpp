#include "stdafx.h"
#include "RingButton.h"
#include "SceneMgr.h"

CRingButton::CRingButton()
{
}


CRingButton::~CRingButton()
{
}

void CRingButton::Initiailize()
{
	m_tInfo.iCX = 69;
	m_tInfo.iCY = 46;
}

int CRingButton::Update()
{
	return 0;
}

void CRingButton::LateUpdate()
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
			if (!lstrcmp(L"InvenRing", m_pFrameKey))
			{

				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_INSERTRING); //���������ιٲٱ�

				return;

			}

		}

		m_iDrawID = 0;
	}
	else
		m_iDrawID = 0;
}

void CRingButton::Render(HDC hDC)
{
}

void CRingButton::Release()
{
}
