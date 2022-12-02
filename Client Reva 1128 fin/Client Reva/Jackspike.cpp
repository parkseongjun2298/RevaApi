#include "stdafx.h"
#include "Jackspike.h"


CJackspike::CJackspike()
{
}


CJackspike::~CJackspike()
{
}

void CJackspike::Initiailize()
{
	m_tInfo.iCX = 50;
	m_tInfo.iCY = 50;
	m_SpikeSpeed = 5.f;
	m_time= GetTickCount();
	m_iAtt = 20;
}

int CJackspike::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (m_time + 500 < GetTickCount())
	{
		m_time = GetTickCount();

		m_bDead = true;
		
	}
	return 0;
}

void CJackspike::LateUpdate()
{
}

void CJackspike::Render(HDC hDC)
{
	CObj::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CJackspike::Release()
{
}
