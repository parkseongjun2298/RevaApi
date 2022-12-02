#pragma once
#include "Obj.h"
class CFlasher :
	public CObj
{
public:
	CFlasher();
	virtual ~CFlasher();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }



private:
	float 	m_FlasherSpeed;
	CObj*	m_pPlayer;
	DWORD	m_time;
	
	float m_Accer2;
};

