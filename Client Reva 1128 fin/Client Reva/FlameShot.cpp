#include "stdafx.h"
#include "FlameShot.h"
#include"Gun.h"

CFlameShot::CFlameShot()
{
	dwTime = GetTickCount();
}


CFlameShot::~CFlameShot()
{
	Release();
}

void CFlameShot::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/Q.bmp", L"Q");
	m_tInfo.iCX = 38;
	m_tInfo.iCY = 27;
	m_fSpeed = 100;
	m_bCheckFlame = true;
}

int CFlameShot::Update()
{
	//여기에 버프 있는지체크 불 변수만들어 총에 넘겨주기
	
	if (m_bDead)
	{
		//static_cast<CGun*>(m_pPlayer)->Set_FlameCheckF();
		m_bCheckFlame = false;
		return OBJ_DEAD;

	}
	//static_cast<CGun*>(m_pPlayer)->Set_FlameCheck();
	m_bCheckFlame = true;

	if (dwTime + 10000 < GetTickCount())
	{
		dwTime = GetTickCount();
		
		m_bDead = true;

	}

	float fx = m_pPlayer->Get_Info()->fX - m_tInfo.fX;
	float fy = m_pPlayer->Get_Info()->fY - m_tInfo.fY;
	float fDist = sqrtf(fx * fx + fy * fy);


	m_fAngle = acosf(fx / fDist);
	if (m_pPlayer->Get_Info()->fY > m_tInfo.fY)

		m_fAngle *= -1.f;

	m_tInfo.fX += cosf(m_fAngle) * m_fSpeed;
	


	return 0;
}

void CFlameShot::LateUpdate()
{
}

void CFlameShot::Render(HDC hDC)
{



	HDC hMemDC3 = CBitmapMgr::Get_Instance()->Get_MemDC(L"Q");
	
		
		GdiTransparentBlt(hDC,//복사받을 대상 
			m_tRect.left, m_tRect.top,// 출력할 좌상단 좌표 
			38, 27, // 얼마만큼 출력 할 것인지 
			hMemDC3,// 복사할 대상 
			0, 0,// 그림에서의 시작 좌상단 좌표 
			38, 27,// 그림에서 얼마만큼 출력할 것인지 . 
			RGB(255, 0, 255));
		CObj::UpdateRect();
	
}

void CFlameShot::Release()
{
}
