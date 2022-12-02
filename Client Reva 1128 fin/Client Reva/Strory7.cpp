#include "stdafx.h"
#include "Strory7.h"
#include"SceneMgr.h"

CStrory7::CStrory7()
{
}


CStrory7::~CStrory7()
{
	Release();
}

void CStrory7::Initialize()
{
	m_tRect.bottom= 404;
	m_tRect.left = 0;
	m_tRect.top = 0;
	m_tRect.right = 546;
	m_tInfo.iCX = 546;
	m_tInfo.iCY = 404;
	m_iDrawID = 0;
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/½ºÅä¸®2.bmp", L"Talk7");
}

void CStrory7::Update()
{
}

void CStrory7::LateUpdate()
{
	
 
	
		if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
		{
			
			m_iDrawID++;
			if (m_iDrawID >= 3)
			{
				CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STAGE2);
				return;
			}
		}
	
}

void CStrory7::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Talk7");
	if (nullptr == hMemDC)
		return;


	GdiTransparentBlt(hDC,
		m_tRect.left, m_tRect.top,
		m_tInfo.iCX, m_tInfo.iCY,
		hMemDC,
		m_tInfo.iCX * m_iDrawID, 0,
		m_tInfo.iCX, m_tInfo.iCY,
		RGB(0, 255, 255));
}

void CStrory7::Release()
{
}
