#include "stdafx.h"
#include "RanShot.h"


CRanShot::CRanShot()
{
	dwTime = GetTickCount();  //�̰��ؾ� �����ӵ��ư�
}


CRanShot::~CRanShot()
{
}

void CRanShot::Initiailize()
{
	m_iAtt = 1;
	m_tInfo.iCX = 200;
	m_tInfo.iCY = 200;
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/RanshotEffect.bmp", L"RanshotEffect");

	
	m_pFrameKey = L"RanshotEffect";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CRanShot::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (dwTime + 1000 < GetTickCount()) //��ų ����Ʈ ���ӽð�
	{
		dwTime = GetTickCount();

		m_bDead = true;

	}
	
	m_tInfo.fX -= 2.f;

	return 0;
}

void CRanShot::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CRanShot::Render(HDC hDC)
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

void CRanShot::Release()
{
}

void CRanShot::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{
		

		case CRanShot::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 100;   //  ��Ÿ��/�������� �ؾ� ��
			m_tFrame.dwFrameTime = GetTickCount();
			break;
	
		case CRanShot::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}

}
