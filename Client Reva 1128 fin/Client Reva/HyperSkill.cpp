#include "stdafx.h"
#include "HyperSkill.h"


CHyperSkill::CHyperSkill()
{
	dwTime = GetTickCount();
}


CHyperSkill::~CHyperSkill()
{
	Release();
}

void CHyperSkill::Initiailize()
{
	
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/������.bmp", L"HyperLogo");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/HyperSkill.bmp", L"HyperSkill");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/hyper effect.bmp", L"hypereffect");
	
	m_tInfo.iCX = 244;
	m_tInfo.iCY = 141;
	m_iAtt = 2;
	m_bDead = false;

	m_pFrameKey = L"hypereffect";
	m_eCurState = STATE_SKILL;
	m_eNextState = STATE_SKILL;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 26;
	m_tFrame.iFrameScene = 0;
	m_tFrame.dwFrameSpeed = 10;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CHyperSkill::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	
	

	if (dwTime + 10000 < GetTickCount())
	{
		dwTime = GetTickCount();

		m_bDead = true;

	}
	return 0;
}

void CHyperSkill::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
	
}

void CHyperSkill::Render(HDC hDC)
{

	

	//������ �ΰ�

	HDC hMemDC2 = CBitmapMgr::Get_Instance()->Get_MemDC(L"HyperLogo");
	if(m_dwOldTime2<GetTickCount())
	{ 
		m_dwOldTime2 = GetTickCount();
	GdiTransparentBlt(hDC,//������� ��� 
		0, 100,// ����� �»�� ��ǥ 
		455, 252, // �󸶸�ŭ ��� �� ������ 
		hMemDC2,// ������ ��� 
		0, 0,// �׸������� ���� �»�� ��ǥ 
		455, 252,// �׸����� �󸶸�ŭ ����� ������ . 
		RGB(255, 0, 255));
	}
	//�ɸ��� ���

	HDC hMemDC3 = CBitmapMgr::Get_Instance()->Get_MemDC(L"HyperSkill");
	if (m_dwOldTime1<GetTickCount())
	{
		m_dwOldTime1 = GetTickCount();
		GdiTransparentBlt(hDC,//������� ��� 
			m_tRect.left, m_tRect.top,// ����� �»�� ��ǥ 
			401, 151, // �󸶸�ŭ ��� �� ������ 
			hMemDC3,// ������ ��� 
			0, 0,// �׸������� ���� �»�� ��ǥ 
			401, 151,// �׸����� �󸶸�ŭ ����� ������ . 
			RGB(255, 0, 255));
	}

	//�� �����°� 
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(m_pFrameKey);
	
	GdiTransparentBlt(hDC,//������� ��� 
		m_tRect.left, m_tRect.top,// ����� �»�� ��ǥ 
		m_tInfo.iCX, m_tInfo.iCY, // �󸶸�ŭ ��� �� ������ 
		hMemDC,// ������ ��� 
		m_tInfo.iCX * m_tFrame.iFrameStart, m_tInfo.iCY * m_tFrame.iFrameScene,// �׸������� ���� �»�� ��ǥ 
		m_tInfo.iCX, m_tInfo.iCY,// �׸����� �󸶸�ŭ ����� ������ . 
		RGB(255, 0, 255));

	


	CObj::UpdateRect();

}

void CHyperSkill::Release()
{
}

void CHyperSkill::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{


		case CHyperSkill::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 26;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 10;   //  ��Ÿ��/�������� �ؾ� ��
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CHyperSkill::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}


