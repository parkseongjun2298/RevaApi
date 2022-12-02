#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	PLAYER::State Get_State() { return m_eState; }
	PLAYERJS::State2 Get_State2() { return m_eState2; }
	

	inline int			Get_Hp() { return m_iHp; }
	inline void				Set_Hp(int _Hp){m_iHp = _Hp;  }
	inline int			Get_Mp() { return m_iMp; }
	inline void				Set_Mp(int _Mp) { m_iMp = _Mp; }

public:
	enum STATE { STATE_IDLE, STATE_JUMP, STATE_WALK, STATE_ATT, STATE_A,STATE_R, STATE_PAIN,  STATE_END };
	void FrameChange();


	void Set_Gun(CObj* pGun) { m_pGun = pGun; }

private:
	
	//float m_Power;
	float m_time;
	
	bool m_bIsJumping;
	DWORD m_dwOldTime;
	
	PLAYER::State m_eState;
	PLAYERJS::State2 m_eState2;
	DWORD m_dwOldTime2;
	DWORD m_dwOldTime3;
	DWORD m_dwOldTime4;
	DWORD m_dwOldTime5;
	DWORD m_dwOldTime6;
	DWORD m_dwOldTime7;
	DWORD m_dwOldTime8;
	bool bJumpCheck;

	bool m_bCheck;
	int iCount;
	int iCount2;
	int iCount3;

	bool m_fCheck;
	bool m_GCheck;
	bool m_TCheck;




private:
	TCHAR* m_pFrameKey;
	//DWORD m_dwOldTime2;
	STATE m_eCurState;
	STATE m_eNextState;
	CObj* m_pGun;
};

