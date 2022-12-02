#include "stdafx.h"
#include "NillSna.h"


CNillSna::CNillSna()
{
	dwTime = GetTickCount();
}


CNillSna::~CNillSna()
{
}

void CNillSna::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/�ҽ�������.bmp", L"Nillsna");
	m_tInfo.iCX = 1000;
	m_tInfo.iCY = 995;
	
	m_NillSpeed = 3.f;
	m_iAtt = 1;
	m_bDead = false;
	m_pFrameKey = L"Nillsna";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 14;
	m_tFrame.iFrameScene = 1;
	m_tFrame.dwFrameSpeed = 10;
	m_tFrame.dwFrameTime = GetTickCount();

	m_NillTime = 0;
}

int CNillSna::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	

	m_pFrameKey = L"Nillsna";
	m_eNextState = STATE_SKILL;

	if (GetAsyncKeyState('J') & 0x8000 )
	{

		m_tInfo.fX -= m_NillSpeed;
		m_pFrameKey = L"Nillsna";
		m_eNextState = STATE_SKILL;
	

	}
	if (GetAsyncKeyState('L') & 0x8000)
	{

		m_tInfo.fX += m_NillSpeed;
		m_pFrameKey = L"Nillsna";
		m_eNextState = STATE_SKILL;

	}
	if (GetAsyncKeyState('I') & 0x8000)
	{

		m_tInfo.fY -= m_NillSpeed;

		m_pFrameKey = L"Nillsna";
		m_eNextState = STATE_SKILL;

	}
	if (GetAsyncKeyState('K') & 0x8000)
	{

		m_tInfo.fY += m_NillSpeed;
		m_pFrameKey = L"Nillsna";
		m_eNextState = STATE_SKILL;

	}
	if (GetAsyncKeyState('T') & 0x8000)
	{
	
		++m_NillTime;
		if (m_NillTime < 65)//�������
		{
			m_pFrameKey = L"Nillsna";
			m_eNextState = STATE_EFFECT;
			m_NillTime = 0;
			
		}
	
		

	}

	if (m_pPlayer->m_iDrawID3 >= 6)
	{

		m_bDead = true;

	}

	if (dwTime + 15000 < GetTickCount())
	{
		
		dwTime = GetTickCount();

		m_bDead = true;

		
	}
	return 0;
}

void CNillSna::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CNillSna::Render(HDC hDC)
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

void CNillSna::Release()
{
}

void CNillSna::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CNillSna::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 10;   //  ��Ÿ��/�������� �ؾ� ��
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CNillSna::STATE_EFFECT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 14;
			m_tFrame.iFrameScene = 1;
			m_tFrame.dwFrameSpeed = 10;   //  ��Ÿ��/�������� �ؾ� ��
			m_tFrame.dwFrameTime = GetTickCount();
			break; 
		case CNillSna::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
