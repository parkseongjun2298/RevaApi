#include "stdafx.h"
#include "Gun.h"
#include"ObjMgr.h"
#include"Bullet.h"
#include"FlameShot.h"
#include"FlameBullet.h"
#include"RigingShot.h"
#include"Player.h"
#include"CollisionMgr.h"
CGun::CGun()
{

}


CGun::~CGun()
{
}

void CGun::Initiailize()
{
	m_pPlayer = CObjMgr::Get_Instance()->Get_Player();
	m_pFlame = CObjMgr::Get_Instance()->Get_Flame();
	m_tInfo.iCX = 20;
	m_tInfo.iCY = 20;
	m_fSpeed = 5.f;
	m_iAtt = 10;

	m_bQ = false;
	m_FlameCheck = false;
	//m_dwOldTime = GetTickCount();
	//m_dwOldTime2 = GetTickCount();
}

int CGun::Update()
{
	m_pFlame = CObjMgr::Get_Instance()->Get_Flame();
	if (static_cast<CPlayer*>(m_pPlayer)->Get_State() == PLAYER::LEFT)
	{
		m_tInfo.fX = m_pPlayer->Get_Info()->fX - 100;
		m_tInfo.fY = m_pPlayer->Get_Info()->fY;
	}
	if (static_cast<CPlayer*>(m_pPlayer)->Get_State() == PLAYER::RIGHT)
	{
		m_tInfo.fX = m_pPlayer->Get_Info()->fX + 100;
		m_tInfo.fY = m_pPlayer->Get_Info()->fY;
	}


	if (GetAsyncKeyState('Q') & 0x8000)
	{
		m_bQ = true;
	}

	//점프할떄도 따라오게
	
	if (m_dwOldTime + 300 < GetTickCount()) 
	{
		m_dwOldTime = GetTickCount();

		if (m_pFlame)
		{
			if (static_cast<CFlameShot*>(m_pFlame)->Get_CheckFlame() == true && GetAsyncKeyState('X') & 0x8000)// 여기 지금  이상함
			{
				if (static_cast<CPlayer*>(m_pPlayer)->Get_State() == PLAYER::LEFT)
					m_plistFlameBullet->emplace_back(CreateBullet2(BULLET2::LEFT));
				if (static_cast<CPlayer*>(m_pPlayer)->Get_State() == PLAYER::RIGHT)
					m_plistFlameBullet->emplace_back(CreateBullet2(BULLET2::RIGHT));
			}
		}

		if (!m_pFlame)
		{
			if (GetAsyncKeyState('X') & 0x8000)
			{
				if (static_cast<CPlayer*>(m_pPlayer)->Get_State() == PLAYER::LEFT)
					m_plistBullet->emplace_back(CreateBullet(BULLET::LEFT));
				if (static_cast<CPlayer*>(m_pPlayer)->Get_State() == PLAYER::RIGHT)
					m_plistBullet->emplace_back(CreateBullet(BULLET::RIGHT));
			}
		}


		if (m_dwOldTime2 + 700 < GetTickCount())
		{
			if (GetAsyncKeyState('S') & 0x8000)
			{
			CSoundMgr::Get_Instance()->PlaySound(L"S.mp3", CSoundMgr::EFFECT);
			m_dwOldTime2 = GetTickCount();
			
				if (static_cast<CPlayer*>(m_pPlayer)->Get_State() == PLAYER::RIGHT)
					CObjMgr::Get_Instance()->Add_Object(OBJ::RIGINGSHOT, CreateBullet<CRigingShot>()); //여기에 크래이트 할떄 (RINGINGSHOT::방향) 넘겨줘야하는데 몰겠음 
				if (static_cast<CPlayer*>(m_pPlayer)->Get_State() == PLAYER::LEFT)
					CObjMgr::Get_Instance()->Add_Object(OBJ::RIGINGSHOT, CreateBullet<CRigingShot>());
				//오른쪽으로만쏴짐 
				

			}

		}


		
	}
	return 0;
}

void CGun::LateUpdate()
{
}

void CGun::Render(HDC hDC)
{
	CObj::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CGun::Release()
{
}

CObj * CGun::CreateBullet(BULLET::DIR eDir)
{
	
	{
		CObj* pBullet = new CBullet;
		pBullet->Initiailize();
		pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
		dynamic_cast<CBullet*>(pBullet)->Set_Dir(eDir);
	

		return pBullet;
	}
}

CObj * CGun::CreateBullet2(BULLET2::DIR eDir2)
{
	{
		CObj* pFlameBullet = new CFlameBullet;
		pFlameBullet->Initiailize();
		pFlameBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
		dynamic_cast<CFlameBullet*>(pFlameBullet)->Set_Dir2(eDir2);


		return pFlameBullet;
	}
}

