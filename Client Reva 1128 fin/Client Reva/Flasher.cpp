#include "stdafx.h"
#include "Flasher.h"
#include"Player.h"

CFlasher::CFlasher()
{
}


CFlasher::~CFlasher()
{
}

void CFlasher::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/G½ºÅ©¸³.bmp", L"Flasher");
	m_tInfo.iCX = 42;
	m_tInfo.iCY = 43;
	m_FlasherSpeed = 3.f;
	m_time = GetTickCount();
	m_Accer = 40.f;
	m_Accer2 = 40.f;
	m_iDrawID2 = 0;
	m_iAtt = 40;
}

int CFlasher::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (m_time + 500 < GetTickCount())
	{
		m_time = GetTickCount();

		m_bDead = true;

	}

	if (PLAYER::RIGHT == static_cast<CPlayer*>(m_pPlayer)->Get_State())
	{

		m_tInfo.fX += 10;
		m_Accer -= 4.f;
		m_tInfo.fY -= m_Accer;
		m_Accer2 -= 4.f;

	}
	if (PLAYER::LEFT == static_cast<CPlayer*>(m_pPlayer)->Get_State())
	{

		m_tInfo.fX -= 10;
		m_Accer -= 4.f;
		m_tInfo.fY -= m_Accer;
		m_Accer2 -= 4.f;

	}
	
	return 0;
}
void CFlasher::LateUpdate()
{
	++m_iDrawID2;
}

void CFlasher::Render(HDC hDC)
{
	CObj::UpdateRect();
	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Flasher");
	if (nullptr == hMemDC)
		return;


	GdiTransparentBlt(hDC,
		m_tRect.left, m_tRect.top,
		m_tInfo.iCX, m_tInfo.iCY,
		hMemDC,
		m_tInfo.iCX * m_iDrawID, 0,
		m_tInfo.iCX, m_tInfo.iCY,
		RGB(255, 0, 255));
}

void CFlasher::Release()
{
}
