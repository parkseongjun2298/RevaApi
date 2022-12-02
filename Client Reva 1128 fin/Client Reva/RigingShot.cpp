#include "stdafx.h"
#include "RigingShot.h"
#include"Player.h"

CRigingShot::CRigingShot()
{
}


CRigingShot::~CRigingShot()
{
}

void CRigingShot::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/S.bmp", L"RShot");
	m_tInfo.iCX = 27;
	m_tInfo.iCY = 17;
	m_fGun_Speed = 8.f;
	m_iAtt = 20;
}

int CRigingShot::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	
		m_tInfo.fX += m_fGun_Speed; //한쪽만됨 
	
	
	
	return 0;
}

void CRigingShot::LateUpdate()
{
}

void CRigingShot::Render(HDC hDC)
{
	CObj::UpdateRect();
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"RShot");
	//BitBlt(hDC, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0, SRCCOPY);
	GdiTransparentBlt(hDC,//복사받을 대상 
		m_tRect.left, m_tRect.top,// 출력할 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY, // 얼마만큼 출력 할 것인지 
		hMemDC,// 복사할 대상 
		0, 0, // 그림에서의 시작 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY,// 그림에서 얼마만큼 출력할 것인지 . 
		RGB(255, 0, 255));
}

void CRigingShot::Release()
{
}
