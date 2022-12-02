#include "stdafx.h"
#include "Boom.h"


CBoom::CBoom()
{
	dwTime = GetTickCount();  //�̰��ؾ� �����ӵ��ư�
}


CBoom::~CBoom()
{
}

void CBoom::Initiailize()
{
	m_iAtt = 1;
	m_tInfo.iCX = 300;
	m_tInfo.iCY = 300;
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/Boom.bmp", L"Boom");


	m_pFrameKey = L"Boom";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 24;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 50;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CBoom::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (dwTime + 4000 < GetTickCount()) //��ų ����Ʈ ���ӽð�
	{
		dwTime = GetTickCount();

		m_bDead = true;

	}

	m_tInfo.fX -= 1.f;

	return 0;
}

void CBoom::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CBoom::Render(HDC hDC)
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

void CBoom::Release()
{
}

void CBoom::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CBoom::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 24;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 20;   //  ��Ÿ��/�������� �ؾ� ��
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CBoom::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
