#include "stdafx.h"
#include "MonAtt.h"


CMonAtt::CMonAtt()
{
}


CMonAtt::~CMonAtt()
{
}

void CMonAtt::Initiailize()
{

	m_tInfo.iCX = 100;
	m_tInfo.iCY = 50;
	m_AttSpeed = 5.f;
	m_time = GetTickCount();
	m_iAtt = 1;
}

int CMonAtt::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (m_time + 100 < GetTickCount())
	{
		m_time = GetTickCount();

		m_bDead = true;

	}


	return 0;
}

void CMonAtt::LateUpdate()
{
}

void CMonAtt::Render(HDC hDC)
{
	CObj::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonAtt::Release()
{
}
