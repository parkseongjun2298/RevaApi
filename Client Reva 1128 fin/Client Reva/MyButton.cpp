#include "stdafx.h"
#include "MyButton.h"
#include "SceneMgr.h"

MyButton::MyButton()
{
}


MyButton::~MyButton()
{
	Release();
}

void MyButton::Initiailize()
{
	m_tInfo.iCX = 150;
	m_tInfo.iCY = 150;
}

int MyButton::Update()
{
	return 0;
}

void MyButton::LateUpdate()
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
			if (!lstrcmp(L"Start", m_pFrameKey))
			{
				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_SELECTDUN);
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

void MyButton::Render(HDC hDC)
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

void MyButton::Release()
{
}
