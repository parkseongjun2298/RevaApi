#pragma once
#include "Obj.h"
class CFlameBullet :
	public CObj
{
public:
	CFlameBullet();
	CFlameBullet(float fx, float fy);
	virtual ~CFlameBullet();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;


	BULLET2::DIR Get_State2() { return m_eDir2; }
public:
	enum STATE { STATE_IDLE,STATE_END };
	void FrameChange();


public:
	void Set_Dir2(BULLET2::DIR eDir2) { m_eDir2 = eDir2; }
private:
	BULLET2::DIR m_eDir2;
	float m_fGun_Speed;

private:
	TCHAR* m_pFrameKey;
	//DWORD m_dwOldTime2;
	STATE m_eCurState;
	STATE m_eNextState;
};

