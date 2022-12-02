#include "stdafx.h"
#include "Buster.h"
#include"Player.h"

CBuster::CBuster()
{
	dwTime = GetTickCount();
}


CBuster::~CBuster()
{
}

void CBuster::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/f��ũ��.bmp", L"Buster");

	m_tInfo.iCX = 37;
	m_tInfo.iCY = 38;
	m_BusterSpeed = 3.f;
	
	m_Accer = 40.f;
	m_Accer2 = 40.f;
	
	m_iAtt = 50;


	m_pFrameKey = L"Buster";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 14;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CBuster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (dwTime + 1000 < GetTickCount())
	{
		dwTime = GetTickCount();

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

void CBuster::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CBuster::Render(HDC hDC)
{
	CObj::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(m_pFrameKey);
	//BitBlt(hDC, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0, SRCCOPY);
	GdiTransparentBlt(hDC,//������� ��� 
		m_tRect.left, m_tRect.top,// ����� �»�� ��ǥ 
		m_tInfo.iCX, m_tInfo.iCY, // �󸶸�ŭ ��� �� ������ 
		hMemDC,// ������ ��� 
		m_tInfo.iCX * m_tFrame.iFrameStart, m_tInfo.iCY * m_tFrame.iFrameScene,// �׸������� ���� �»�� ��ǥ 
		m_tInfo.iCX, m_tInfo.iCY,// �׸����� �󸶸�ŭ ����� ������ . 
		RGB(255, 0, 255));

}

void CBuster::Release()
{
}

void CBuster::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CBuster::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 14;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 100;   //  ��Ÿ��/�������� �ؾ� ��
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CBuster::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
