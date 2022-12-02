#pragma once
#include "Monster.h"
class CMonster2 :
	public CMonster
{
public:
	CMonster2();
	virtual ~CMonster2();
	inline int			Get_Hp() { return m_iHp; }
	inline void				Set_Hp(int _Hp) { m_iHp = _Hp; }

public:
	virtual void Initiailize() override;
	virtual void Render(HDC hDC) override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	enum STATE { STATE_IDLE, STATE_MOVE, STATE_ATT,STATE_SKILL, STATE_END };
	void FrameChange();
private:
	TCHAR* m_pFrameKey;
	DWORD m_dwOldTime2;
	STATE m_eCurState;
	STATE m_eNextState;
	DWORD dwTime;
	DWORD m_dwOldTime3;
};

