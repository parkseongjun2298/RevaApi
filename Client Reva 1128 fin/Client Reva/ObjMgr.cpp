#include "stdafx.h"
#include "ObjMgr.h"
#include"Obj.h"
#include"Monster1.h"
#include"Monster2.h"
#include"BossMonster.h"
#include"Gun.h"
#include"CollisionMgr.h"
#include"Player.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;


void CObjMgr::Initialize()
{
	m_bDeathCheck = false;
}

void CObjMgr::Update()
{
	for (int i = 0; i < OBJ::END; ++i)
		for (list<CObj*>::iterator iter = m_lstObject[i].begin(); iter != m_lstObject[i].end();)
		{
			int iEvent = (*iter)->Update();
			if (OBJ_DEAD == iEvent)
			{
				delete *iter;
				*iter = nullptr;
				iter = m_lstObject[i].erase(iter);
			}
			else if (PLAYER_DEAD == iEvent)
			{
				
				delete *iter;
				*iter = nullptr;
				iter = m_lstObject[i].erase(iter);
			}
			else
				++iter;
		}
}

void CObjMgr::LateUpdate()
{
	/*for (auto& Lst : m_lstObject)
	{
		for (auto& pElement : Lst)
			pElement->LateUpdate();
	}*/
	
	for (int i = 0; i < OBJ::END; ++i)
	{
		for (auto& iter : m_lstObject[i])
		{
			iter->LateUpdate();
			if (m_lstObject[OBJ::MONSTER].empty())
			{
				m_bDeathCheck = true;
			}
		
			
			if (m_lstObject[i].empty())
				break;
		}
	}
	
	CCollisionMgr::CollisionBullet_N_Monster(m_lstObject[OBJ::BULLET], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionFlameBullet_N_Monster(m_lstObject[OBJ::FLAMEBULLET], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionRigingshot_N_Monster(m_lstObject[OBJ::RIGINGSHOT], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionJackspike_N_Monster(m_lstObject[OBJ::JACKSPIKE], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionCross_N_Monster(m_lstObject[OBJ::CROSS], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionFlashMine_N_Monster(m_lstObject[OBJ::FLASHMINE], m_lstObject[OBJ::MONSTER]);

	CCollisionMgr::CollisionPlayer_N_AttMon(m_lstObject[OBJ::PLAYER], m_lstObject[OBJ::ATTMON]);
	CCollisionMgr::CollisionPlayer_N_MonSkill(m_lstObject[OBJ::PLAYER], m_lstObject[OBJ::MONSKILL]);
	CCollisionMgr::CollisionPlayer_N_BOOM(m_lstObject[OBJ::PLAYER], m_lstObject[OBJ::BOOM]);
	CCollisionMgr::CollisionPlayer_N_LIGHTAIR(m_lstObject[OBJ::PLAYER], m_lstObject[OBJ::LIGHTAIR]);
	CCollisionMgr::CollisionPlayer_N_RANSHOT(m_lstObject[OBJ::PLAYER], m_lstObject[OBJ::RANSHOT]);


	CCollisionMgr::CollisionNeiphamtan_N_Monster(m_lstObject[OBJ::NEIPHAMTAN], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionBuster_N_Monster(m_lstObject[OBJ::BUSTER], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionFlasher_N_Monster(m_lstObject[OBJ::FLASHER], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionFleezer_N_Monster(m_lstObject[OBJ::FLEEZER], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionC4_N_Monster(m_lstObject[OBJ::C4], m_lstObject[OBJ::MONSTER]);
	CCollisionMgr::CollisionNillSna_N_Monster(m_lstObject[OBJ::NILLSNA], m_lstObject[OBJ::MONSTER]);
	
	CCollisionMgr::CollisionHyper_N_Monster(m_lstObject[OBJ::HYPERSKILL], m_lstObject[OBJ::MONSTER]);
}

void CObjMgr::Render(HDC hDC)
{

	for (int i = 0; i < OBJ::END; ++i)
		for (auto& pElement : m_lstObject[i])
			pElement->Render(hDC);
	
}

void CObjMgr::Release()
{

	//ReleaseDC(g_hWND, m_hDC);
	for (int i = 0; i < OBJ::END; ++i)
	{
		for (auto& iter : m_lstObject[i])
		{
			if (iter)
			{
				delete iter;
				iter = nullptr;
			}
		}
		m_lstObject[i].clear();
	}
	
}

void CObjMgr::MakeMap()
{
	CObj* pObj = new CPlayer;
	pObj->Initiailize();
	pObj->Set_Pos(100, WINCY - 125);
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::PLAYER);

	CObjMgr::Get_Instance()->Initialize();


	 pObj = new CMonster1;
	pObj->Initiailize();
	pObj->Set_Pos(500, WINCY - 100);
	dynamic_cast<CMonster*>(pObj)->Set_Target(m_lstObject[OBJ::PLAYER].front());
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::MONSTER);

	pObj = new CGun;
	pObj->Initiailize();
	pObj->Set_Pos(20, WINCY - 125);
	
	dynamic_cast<CGun*>(pObj)->Set_FlameBulletlist(&m_lstObject[OBJ::FLAMEBULLET]);//총알넣기
	dynamic_cast<CGun*>(pObj)->Set_Bulletlist(&m_lstObject[OBJ::BULLET]);//총알넣기
	dynamic_cast<CGun*>(pObj)->Set_Player(m_lstObject[OBJ::PLAYER].front());//플레이어위치따라다니는거
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::GUN);

}

void CObjMgr::MakeMap2()
{
	/*CObj* pObj = new CPlayer;
	pObj->Initiailize();
	pObj->Set_Pos(250, WINCY - 125);
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::PLAYER);

	CObjMgr::Get_Instance()->Initialize();*/


	CObj* pObj = new CMonster1;
	pObj->Initiailize();
	pObj->Set_Pos(300, WINCY - 100);
	dynamic_cast<CMonster*>(pObj)->Set_Target(m_lstObject[OBJ::PLAYER].front());
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::MONSTER);

	pObj = new CMonster1;
	pObj->Initiailize();
	pObj->Set_Pos(450, WINCY - 100);
	dynamic_cast<CMonster*>(pObj)->Set_Target(m_lstObject[OBJ::PLAYER].front());
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::MONSTER);

	pObj = new CMonster1;
	pObj->Initiailize();
	pObj->Set_Pos(200, WINCY - 100);
	dynamic_cast<CMonster*>(pObj)->Set_Target(m_lstObject[OBJ::PLAYER].front());
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::MONSTER);

	pObj = new CMonster1;
	pObj->Initiailize();
	pObj->Set_Pos(50, WINCY - 100);
	dynamic_cast<CMonster*>(pObj)->Set_Target(m_lstObject[OBJ::PLAYER].front());
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::MONSTER);

	//pObj = new CGun;
	//pObj->Initiailize();
	//pObj->Set_Pos(20, WINCY - 125);
	//dynamic_cast<CGun*>(pObj)->Set_Bulletlist(&m_lstObject[OBJ::BULLET]);//총알넣기
	//dynamic_cast<CGun*>(pObj)->Set_Player(m_lstObject[OBJ::PLAYER].front());//플레이어위치따라다니는거
	//CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::GUN);
}

void CObjMgr::MakeMap3()
{

	CObj* pObj = new CMonster2;
	pObj->Initiailize();
	pObj->Set_Pos(500, WINCY - 100);
	dynamic_cast<CMonster*>(pObj)->Set_Target(m_lstObject[OBJ::PLAYER].front());
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::MONSTER);

	//pObj = new CGun;
	//pObj->Initiailize();
	//pObj->Set_Pos(20, WINCY - 125);
	//dynamic_cast<CGun*>(pObj)->Set_Bulletlist(&m_lstObject[OBJ::BULLET]);//총알넣기
	//dynamic_cast<CGun*>(pObj)->Set_Player(m_lstObject[OBJ::PLAYER].front());//플레이어위치따라다니는거
	//CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::GUN);
}

void CObjMgr::MakeMap4()
{
	CObj* pObj = new CPlayer;
	pObj->Initiailize();
	pObj->Set_Pos(100, WINCY - 125);

	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::PLAYER);

	CObjMgr::Get_Instance()->Initialize();

	 pObj = new CBossMonster;
	pObj->Initiailize();
	pObj->Set_Pos(500, WINCY - 100);
	dynamic_cast<CMonster*>(pObj)->Set_Target(m_lstObject[OBJ::PLAYER].front());
	CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::MONSTER);

	//pObj = new CGun;
	//pObj->Initiailize();
	//pObj->Set_Pos(20, WINCY - 125);
	//dynamic_cast<CGun*>(pObj)->Set_FlameBulletlist(&m_lstObject[OBJ::FLAMEBULLET]);//총알넣기
	//dynamic_cast<CGun*>(pObj)->Set_Bulletlist(&m_lstObject[OBJ::BULLET]);//총알넣기
	//dynamic_cast<CGun*>(pObj)->Set_Player(m_lstObject[OBJ::PLAYER].front());//플레이어위치따라다니는거
	//CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::GUN);

}

void CObjMgr::Add_Object(OBJ::ID eID, CObj * pObj)
{
	m_lstObject[eID].emplace_back(pObj);
}

void CObjMgr::Delete_Object(OBJ::ID eID)
{
	for (auto& pObj : m_lstObject[eID])
	{
		Safe_Delete(pObj);
	}
	m_lstObject[eID].clear();

	



}


