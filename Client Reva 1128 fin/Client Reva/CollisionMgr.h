#pragma once
class CObj;
class CCollisionMgr
{
public:
	CCollisionMgr();
	virtual ~CCollisionMgr();



	static void CollisionBullet_N_Monster(list<CObj*>& rBullet, list<CObj*>& rMonster);
	static void CollisionFlameBullet_N_Monster(list<CObj*>& rBullet, list<CObj*>& rMonster);

	static void CollisionRigingshot_N_Monster(list<CObj*>& rBullet, list<CObj*>& rMonster);

	static void CollisionJackspike_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);
	
	static void CollisionCross_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);

	static void CollisionFlashMine_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);

	static void CollisionNeiphamtan_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);

	static void CollisionPlayer_N_AttMon(list<CObj*>& rPlayer, list<CObj*>& rMonster);

	static void CollisionBuster_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);

	static void CollisionFlasher_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);
	static void CollisionFleezer_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);
	
	static void CollisionPlayer_N_MonSkill(list<CObj*>& rPlayer, list<CObj*>& rMonster);
	static void CollisionNillSna_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);
	static void CollisionHyper_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);

	static void	CollisionPlayer_N_BOOM(list<CObj*>& rPlayer, list<CObj*>& rMonster);
	static void	CollisionPlayer_N_LIGHTAIR(list<CObj*>& rPlayer, list<CObj*>& rMonster);
	static void	CollisionPlayer_N_RANSHOT(list<CObj*>& rPlayer, list<CObj*>& rMonster);

	static void CollisionC4_N_Monster(list<CObj*>& rPlayer, list<CObj*>& rMonster);

		// inline static RECT*		Set_Rect(RECT* _rect) { m_tRect= _rect; }
private:
	static bool CheckSphere(INFO* pDst, INFO* pSrc);
	PLAYER::State m_eState;
	
	static DWORD		m_time;
	
	static float		m_Accer;
	static MONSTER::State m_eMonState;
	static RECT* m_tRect;
};

