#pragma once
#include "Obj.h"
class CMonster :
	public CObj
{
public:
	CMonster();
	virtual ~CMonster();
	void Set_Target(CObj* pTarget) { m_pTarget = pTarget; }
	
	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	void Set_Airboon() { m_bAirboon = true; }
	float Get_Speed() { return m_fSpeed; }
	void Set_Speed(float _Speed) { m_fSpeed = _Speed; }

	void Set_DebuffFM(bool _Debuff) { m_DeBuffFM = _Debuff; }
	void Set_DebuffFleeze(bool _Debuff2) { m_DeBuffFleeze = _Debuff2; }
	MONSTER::State Get_State() { return m_Monstate; }
	MONSTER2::State2 Get_State2() { return m_Monstate2; }
protected:
	CObj* m_pTarget;
	
	float m_fAngle;
	bool  m_bAirboon;
	MONSTER::State		m_Monstate;
	MONSTER2::State2	m_Monstate2;
	float m_fSpeed;

	bool m_DeBuffFM;
	bool m_DeBuffFleeze;

	int m_FleezeTime;
};

