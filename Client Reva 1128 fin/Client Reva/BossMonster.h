#pragma once
#include "Monster.h"
class CBossMonster :
	public CMonster
{
public:
	CBossMonster();
	virtual ~CBossMonster();


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
	enum STATE { STATE_IDLE,  STATE_ATT, STATE_SKILL, STATE_MOVE, STATE_PAIN, STATE_DIE, STATE_END };
	void FrameChange();
private:
	TCHAR* m_pFrameKey;
	DWORD m_dwOldTime2;//ÄðÅ¸ÀÓ
	DWORD m_dwOldTime3;
	STATE m_eCurState;
	STATE m_eNextState;
	DWORD dwTime;
	bool  m_bPain;
	bool  m_bDie;
};

