#include "stdafx.h"
#include "MonSkill.h"


CMonSkill::CMonSkill()
{
}


CMonSkill::~CMonSkill()
{
	Release();
}

void CMonSkill::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/고블린번개.bmp", L"Monskill");
	m_tInfo.iCX = 289;
	m_tInfo.iCY = 323;
	m_AttSpeed = 5.f;
	m_time = GetTickCount();
	m_iAtt = 1;
	m_iDrawID = 0;
}

int CMonSkill::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (m_time + 1000 < GetTickCount())
	{
		m_time = GetTickCount();

		m_bDead = true;

	}


	return 0;
}

void CMonSkill::LateUpdate()
{
	++m_iDrawID;
}

void CMonSkill::Render(HDC hDC)
{
	CObj::UpdateRect();
	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Monskill");
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

void CMonSkill::Release()
{
}
