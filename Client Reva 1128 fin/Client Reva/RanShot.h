#pragma once
#include "Obj.h"

class CRanShot :
	public CObj
{
public:
	CRanShot();
	virtual ~CRanShot();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	void Set_Monster(CObj* _Monster) { m_pMonster = _Monster; }
	enum STATE {  STATE_SKILL,  STATE_END };
	void FrameChange();
private:
	TCHAR* m_pFrameKey;
	DWORD m_dwOldTime2;
	STATE m_eCurState;
	STATE m_eNextState;
	DWORD dwTime;
	CObj* m_pMonster;
};

