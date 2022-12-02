#pragma once
#include "Obj.h"
class CGun :
	public CObj
{
public:
	CGun();
	virtual ~CGun();
	void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;


	template<typename T>
	CObj* CreateBullet()
	{
		CObj* pBullet = new T;
		pBullet->Initiailize();
		pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

		return pBullet;
	}
	void Set_Bulletlist(list<CObj*>* plistBullet) { m_plistBullet = plistBullet; }
	CObj* CreateBullet(BULLET::DIR eDir);
	
	void Set_FlameBulletlist(list<CObj*>* plistBullet) { m_plistFlameBullet = plistBullet; }
	CObj* CreateBullet2(BULLET2::DIR eDir2);


	void Set_FlameCheck() { m_FlameCheck = true; }
	void Set_FlameCheckF() { m_FlameCheck = false; }
	bool Get_FlameCheck() { return m_FlameCheck; }
	
private:
	DWORD m_dwOldTime;
	CObj* m_pPlayer;
	float m_fSpeed;
	float m_fAngle;
	list<CObj*>* m_plistBullet;
	DWORD m_dwOldTime2;

	list<CObj*>* m_plistFlameBullet;

	bool m_FlameCheck;
	CObj* m_pFlame;

	bool m_bQ;
};

