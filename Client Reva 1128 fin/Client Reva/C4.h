#pragma once
#include "Obj.h"
class CC4 :
	public CObj
{
public:
	CC4();
	virtual ~CC4();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	enum STATE { STATE_SKILL, STATE_END };
	void FrameChange();
private:
	TCHAR* m_pFrameKey;
	DWORD m_dwOldTime2;
	STATE m_eCurState;
	STATE m_eNextState;

	DWORD dwTime;
	CObj* m_pPlayer;

};

