#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
	:m_bAirboon(false)
{
}


CMonster::~CMonster()
{
}

void CMonster::Initiailize()
{
	m_Accer = 40.f;
	m_fSpeed = 1.f;
	
}

int CMonster::Update()
{
	
	if (m_bDead)
		return OBJ_DEAD;
	if (m_bAirboon)
	{
		m_tInfo.fY -= m_Accer;
		m_Accer -= 3.f;
		if (m_tInfo.fY >= WINCY - 125)
		{

			m_tInfo.fY = WINCY - 125;
		
			m_bAirboon = false;
			m_Accer = 40.f;

		}
	}
	return 0;
}

void CMonster::LateUpdate()
{
}

void CMonster::Render(HDC hDC)
{
}

void CMonster::Release()
{
}


