#include "stdafx.h"
#include "LightAir.h"


CLightAir::CLightAir()
{
	dwTime = GetTickCount();
}


CLightAir::~CLightAir()
{
}

void CLightAir::Initiailize()
{
	m_iAtt = 1;
	m_tInfo.iCX = 154;
	m_tInfo.iCY = 168;
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/LightAirEffect.bmp", L"LightAirEffect");


	m_pFrameKey = L"LightAirEffect";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 7;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CLightAir::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (dwTime + 1000 < GetTickCount()) //��ų ����Ʈ ���ӽð�
	{
		dwTime = GetTickCount();

		m_bDead = true;

	
	}

	



	return 0;
}

void CLightAir::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CLightAir::Render(HDC hDC)
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

void CLightAir::Release()
{
}

void CLightAir::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CLightAir::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 7;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 200;   //  ��Ÿ��/�������� �ؾ� ��
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CLightAir::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
