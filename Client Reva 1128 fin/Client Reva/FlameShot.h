#pragma once
#include "Obj.h"
class CFlameShot :
	public CObj
{
public:
	CFlameShot();
	virtual ~CFlameShot();

	// CObj��(��) ���� ��ӵ�
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	void Set_Gun(CObj* pGun) { m_pGun = pGun; }

	bool Get_CheckFlame() { return m_bCheckFlame; }
private:
	DWORD dwTime;
	CObj* m_pPlayer;
	float m_fSpeed;
	float m_fAngle;
	CObj* m_pGun;
	
	bool m_bCheckFlame;
};

