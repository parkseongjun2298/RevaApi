#pragma once
#include "Obj.h"
class CMonSkill :
	public CObj
{
public:
	CMonSkill();
	virtual ~CMonSkill();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	void Set_Monster(CObj* _Monster) { m_pMonster = _Monster; }

private:
	float 	m_AttSpeed;
	CObj*	m_pMonster;
	DWORD	m_time;
};

