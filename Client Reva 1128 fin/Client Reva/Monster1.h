#pragma once
#include "Monster.h"
class CMonster1 :
	public CMonster
{
public:
	CMonster1();
	virtual ~CMonster1();
	inline int			Get_Hp() { return m_iHp; }
	inline void				Set_Hp(int _Hp) { m_iHp = _Hp; }
	inline bool			Get_Pain() { return m_bPain; }
	inline void				Set_Pain(bool _Pain) { m_bPain = _Pain; }
	inline void				Set_Die(bool _Die) { m_bDie = _Die; }

	
public:
	virtual void Initiailize() override;
	virtual void Render(HDC hDC) override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	enum STATE { STATE_IDLE, STATE_MOVE, STATE_ATT, STATE_PAIN, STATE_DIE, STATE_END };
	void FrameChange();
private:
	TCHAR* m_pFrameKey;
	DWORD m_dwOldTime2;
	STATE m_eCurState;
	STATE m_eNextState;
	DWORD dwTime;
	bool  m_bPain;
	bool  m_bDie;
	
	
};

