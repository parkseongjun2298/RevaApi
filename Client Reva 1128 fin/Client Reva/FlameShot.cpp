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
	//���⿡ ���� �ִ���üũ �� ��������� �ѿ� �Ѱ��ֱ�
	
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
	
		
		GdiTransparentBlt(hDC,//������� ��� 
			m_tRect.left, m_tRect.top,// ����� �»�� ��ǥ 
			38, 27, // �󸶸�ŭ ��� �� ������ 
			hMemDC3,// ������ ��� 
			0, 0,// �׸������� ���� �»�� ��ǥ 
			38, 27,// �׸����� �󸶸�ŭ ����� ������ . 
			RGB(255, 0, 255));
		CObj::UpdateRect();
	
}

void CFlameShot::Release()
{
}
