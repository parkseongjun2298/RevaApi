#include "stdafx.h"
#include "CollisionMgr.h"
#include "Player.h"
#include"Bullet.h"
#include"Monster1.h"
#include"Monster2.h"
#include"RigingShot.h"
#include"Jackspike.h"
#include"Cross.h"
#include"ObjMgr.h"
#include"FlashMine.h"
#include"MonAtt.h"
#include"MonSkill.h"
#include"Boom.h"
#include"LightAir.h"
#include"RanShot.h"
#include"Neiphamtan.h"
#include"Buster.h"
#include"Flasher.h"
#include"FLeezer.h"
#include"NillSna.h"
#include"HyperSkill.h"
#include"C4.h"
#include"FlameShot.h"
#include"FlameBullet.h"
//스킬들h다넣어야지 데미지 입힘 





CCollisionMgr::CCollisionMgr()
{
	
}


CCollisionMgr::~CCollisionMgr()
{
}

DWORD CCollisionMgr::m_time = GetTickCount();

float CCollisionMgr::m_Accer = 4;
 MONSTER::State CCollisionMgr::m_eMonState =MONSTER::IDLE ;
 //RECT CCollisionMgr::m_tRect=NULL;


void CCollisionMgr::CollisionBullet_N_Monster(list<CObj*>& rBullet, list<CObj*>& rMonster)
{

	RECT rc = {};
	
	for (auto& rDestObj : rBullet)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (CheckSphere(rDestObj->Get_Info(), rSrcObj->Get_Info()))
			{
				rDestObj->Set_Dead();
			
				
				if (static_cast<CBullet*>(rDestObj)->Get_State() == BULLET::LEFT)
				{
					

					rSrcObj->Get_Info()->fX -= 15;

				}
				if (static_cast<CBullet*>(rDestObj)->Get_State() == BULLET::RIGHT)
				{
					rSrcObj->Get_Info()->fX += 15;
				}


					static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp()-rDestObj->Get_Att());
					static_cast<CMonster1*>(rSrcObj)->Set_Pain(true);
				//	CSoundMgr::Get_Instance()->PlaySound(L"고블린맞을때.mp3", CSoundMgr::MONSTER);
					if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp()<=0))
					{


						static_cast<CMonster1*>(rSrcObj)->Set_Die(true);
						CSoundMgr::Get_Instance()->PlaySound(L"고블린사망.mp3", CSoundMgr::MONSTER);
						rSrcObj->Set_Dead();



					}
			}
		}

	}
}

void CCollisionMgr::CollisionFlameBullet_N_Monster(list<CObj*>& rBullet, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rBullet)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (CheckSphere(rDestObj->Get_Info(), rSrcObj->Get_Info()))
			{
				rDestObj->Set_Dead();


				if (static_cast<CFlameBullet*>(rDestObj)->Get_State2() == BULLET2::LEFT)
				{


					rSrcObj->Get_Info()->fX -= 15;

				}
				if (static_cast<CFlameBullet*>(rDestObj)->Get_State2() == BULLET2::RIGHT)
				{
					rSrcObj->Get_Info()->fX += 15;
				}


				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - rDestObj->Get_Att());
				static_cast<CMonster1*>(rSrcObj)->Set_Pain(true);
			//	CSoundMgr::Get_Instance()->PlaySound(L"고블린맞을때.mp3", CSoundMgr::MONSTER);
				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{


					static_cast<CMonster1*>(rSrcObj)->Set_Die(true);
					CSoundMgr::Get_Instance()->PlaySound(L"고블린사망.mp3", CSoundMgr::MONSTER);
					rSrcObj->Set_Dead();



				}
			}
		}

	}

}


void CCollisionMgr::CollisionRigingshot_N_Monster(list<CObj*>& rBullet, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rBullet)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (CheckSphere(rDestObj->Get_Info(), rSrcObj->Get_Info()))
			{
				
			//	CSoundMgr::Get_Instance()->PlaySound(L"고블린맞을때.mp3", CSoundMgr::MONSTER);

				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{
					

					rSrcObj->Get_Info()->fX -= 15;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rSrcObj->Get_Info()->fX += 15;
				}
				
				//맞으면 점프(에어본)
			
				static_cast<CMonster1*>(rSrcObj)->Set_Airboon();
				
				rDestObj->Set_Dead();

				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - static_cast<CRigingShot*>(rDestObj)->Get_Att());
				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
				


			}
		}

	}
}

void CCollisionMgr::CollisionJackspike_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{
				

					//에어본
			
					static_cast<CMonster1*>(rSrcObj)->Set_Airboon();
				//	CSoundMgr::Get_Instance()->PlaySound(L"고블린맞을때.mp3", CSoundMgr::MONSTER);
				
				rDestObj->Set_Dead();
				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - static_cast<CJackspike*>(rDestObj)->Get_Att());
				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
			}
		}

	}

}

void CCollisionMgr::CollisionCross_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{


	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{

				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{


					rSrcObj->Get_Info()->fX -= 400;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rSrcObj->Get_Info()->fX += 400;
				}
			
				//스킬이펙트살리려고 지움
					//rDestObj->Set_Dead();
					
				
				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - static_cast<CCross*>(rDestObj)->Get_Att());
				
				

				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
				
			}
		}

	}



}

void CCollisionMgr::CollisionFlashMine_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{

	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{
				
					
					//static_cast<CMonster1*>(rSrcObj)->Set_Speed(static_cast<CMonster1*>(rSrcObj)->Get_Speed()-1.f); //한2초 얼리기로바꾸기
				static_cast<CMonster1*>(rSrcObj)->Set_DebuffFM(true);
				//rDestObj->Set_Dead();
				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - static_cast<CFlashMine*>(rDestObj)->Get_Att());
				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
			}
		}

	}


}

void CCollisionMgr::CollisionNeiphamtan_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{


				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{


					rSrcObj->Get_Info()->fX -= 200;


					//에어본

					static_cast<CMonster1*>(rSrcObj)->Set_Airboon();
					
				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rSrcObj->Get_Info()->fX += 200;

					//에어본

					static_cast<CMonster1*>(rSrcObj)->Set_Airboon();
					
				}


				//rDestObj->Set_Dead();
				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - static_cast<CFlashMine*>(rDestObj)->Get_Att());
				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
			}
		}

	}




}

void CCollisionMgr::CollisionPlayer_N_AttMon(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{

				static_cast<CPlayer*>(rDestObj)->Set_Hp(static_cast<CPlayer*>(rDestObj)->Get_Hp() - static_cast<CMonster1*>(rSrcObj)->Get_Att());
				CSoundMgr::Get_Instance()->PlaySound(L"레바맞을떄.mp3", CSoundMgr::PLAYER);
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{


					rDestObj->Get_Info()->fX += 15;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rDestObj->Get_Info()->fX -= 15;
				}
				

			}
		}

	}


}

void CCollisionMgr::CollisionBuster_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (CheckSphere(rDestObj->Get_Info(), rSrcObj->Get_Info()))
			{
				rDestObj->Set_Dead();


				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{

					

					//에어본

					static_cast<CMonster1*>(rSrcObj)->Set_Airboon();
					rSrcObj->Get_Info()->fX -= 200;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{

					//에어본

					static_cast<CMonster1*>(rSrcObj)->Set_Airboon();
					rSrcObj->Get_Info()->fX += 200;
				}


				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - rDestObj->Get_Att());


				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
			}
		}

	}


}

void CCollisionMgr::CollisionFlasher_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (CheckSphere(rDestObj->Get_Info(), rSrcObj->Get_Info()))
			{
				rDestObj->Set_Dead();
				static_cast<CMonster*>(rSrcObj)->Set_Speed(static_cast<CMonster*>(rSrcObj)->Get_Speed() /2);//한2초만 느려지기로바꾸기

				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{


					rSrcObj->Get_Info()->fX -= 100;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rSrcObj->Get_Info()->fX += 100;
				}


				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - rDestObj->Get_Att());


				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
			}
		}

	}

}

void CCollisionMgr::CollisionFleezer_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (CheckSphere(rDestObj->Get_Info(), rSrcObj->Get_Info()))
			{
				rDestObj->Set_Dead();
				static_cast<CMonster1*>(rSrcObj)->Set_DebuffFleeze(true);

			


				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - rDestObj->Get_Att());


				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
			}
		}

	}

}

void CCollisionMgr::CollisionPlayer_N_MonSkill(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{

				static_cast<CPlayer*>(rDestObj)->Set_Hp(static_cast<CPlayer*>(rDestObj)->Get_Hp() - static_cast<CMonster2*>(rSrcObj)->Get_Att());
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{


					rDestObj->Get_Info()->fX += 35;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rDestObj->Get_Info()->fX -= 35;
				}


			}
		}

	}


}

void CCollisionMgr::CollisionNillSna_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{

	//몬스터라는 사각형과 닐스나이퍼의 중간 좌표를 넣어야함 
	//ptinRect쓰자


	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{

			{

				POINT pt = {0};
				pt.x = (rDestObj ->Get_Info()->fX/*+rDestObj->Get_Info()->iCX / 2*/);
				pt.y = (rDestObj->Get_Info()->fY/*+rDestObj->Get_Info()->iCY / 2*/);
			
				//m_tRect = ;
				if (PtInRect(rSrcObj->Get_Rect(), pt)&& CKeyMgr::Get_Instance()->KeyPressing('T'))
				{
					

					static_cast<CMonster1*>(rSrcObj)->Set_Airboon();




					static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - static_cast<CFlashMine*>(rDestObj)->Get_Att());
					if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
					{
						rSrcObj->Set_Dead();
					}

				}
			}

		}
	}


}

void CCollisionMgr::CollisionHyper_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{


			

					static_cast<CMonster1*>(rSrcObj)->Set_Airboon();



			
				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - static_cast<CFlashMine*>(rDestObj)->Get_Att());
				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
			}
		}

	}



}

void CCollisionMgr::CollisionPlayer_N_BOOM(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{

				static_cast<CPlayer*>(rDestObj)->Set_Hp(static_cast<CPlayer*>(rDestObj)->Get_Hp() - static_cast<CMonster1*>(rSrcObj)->Get_Att());
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{


					rDestObj->Get_Info()->fX -= 15;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rDestObj->Get_Info()->fX += 15;
				}


			}
		}

	}
}

void CCollisionMgr::CollisionPlayer_N_LIGHTAIR(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{

				static_cast<CPlayer*>(rDestObj)->Set_Hp(static_cast<CPlayer*>(rDestObj)->Get_Hp() - static_cast<CMonster1*>(rSrcObj)->Get_Att());
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{


					rDestObj->Get_Info()->fX += 15;
					rDestObj->Get_Info()->fSpeed -= 5;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rDestObj->Get_Info()->fX -= 15;
					rDestObj->Get_Info()->fSpeed -= 5;
				}


			}
		}

	}
}

void CCollisionMgr::CollisionPlayer_N_RANSHOT(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{

				static_cast<CPlayer*>(rDestObj)->Set_Hp(static_cast<CPlayer*>(rDestObj)->Get_Hp() - static_cast<CMonster1*>(rSrcObj)->Get_Att());
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX > rSrcObj->Get_Info()->fX)
				{


					rDestObj->Get_Info()->fX += 15;

				}
				if (CObjMgr::Get_Instance()->Get_Player()->Get_Info()->fX < rSrcObj->Get_Info()->fX)
				{
					rDestObj->Get_Info()->fX -= 15;
				}


			}
		}
	}
	
}

void CCollisionMgr::CollisionC4_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster)
{
	RECT rc = {};

	for (auto& rDestObj : rPlayer)
	{
		for (auto& rSrcObj : rMonster)
		{
			if (IntersectRect(&rc, rDestObj->Get_Rect(), rSrcObj->Get_Rect()))
			{


				//static_cast<CMonster1*>(rSrcObj)->Set_Speed(static_cast<CMonster1*>(rSrcObj)->Get_Speed()-1.f); //한2초 얼리기로바꾸기
				static_cast<CMonster1*>(rSrcObj)->Set_DebuffFM(true);
				//rDestObj->Set_Dead();
				static_cast<CMonster1*>(rSrcObj)->Set_Hp(static_cast<CMonster1*>(rSrcObj)->Get_Hp() - static_cast<CFlashMine*>(rDestObj)->Get_Att());
				if ((static_cast<CMonster1*>(rSrcObj)->Get_Hp() <= 0))
				{
					rSrcObj->Set_Dead();
				}
			}
		}

	}

}



bool CCollisionMgr::CheckSphere(INFO * pDst, INFO * pSrc)
{
	float fx = pDst->fX - pSrc->fX;
	float fy = pDst->fY - pSrc->fY;
	float fDist = sqrtf(fx * fx + fy * fy);

	float fRadiusSum = (pDst->iCX >> 1) + (pSrc->iCX >> 1);

	if (fRadiusSum > fDist)
		return true;

	return false;
}
