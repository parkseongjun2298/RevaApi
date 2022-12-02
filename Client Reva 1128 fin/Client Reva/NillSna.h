#pragma once
#include "Obj.h"
class CNillSna :
	public CObj
{
public:
	CNillSna();
	virtual ~CNillSna();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	

	enum STATE { STATE_SKILL,STATE_EFFECT, STATE_END };
	void FrameChange();
private:
	TCHAR* m_pFrameKey;
	DWORD m_dwOldTime2;
	STATE m_eCurState;
	STATE m_eNextState;
	float m_NillSpeed;
	DWORD dwTime;
	CObj* m_pPlayer;


	int m_NillTime;
	
};

