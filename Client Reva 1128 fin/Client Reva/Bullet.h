#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	CBullet();
	CBullet(float fx, float fy);
	virtual ~CBullet();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	BULLET::DIR Get_State() { return m_eDir; }

	

public:
	void Set_Dir(BULLET::DIR eDir) { m_eDir = eDir; }
private:
	BULLET::DIR m_eDir;
	float m_fGun_Speed;
};

