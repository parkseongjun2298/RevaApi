#pragma once
#include "Obj.h"
class CJackspike :
	//무릎으로띄우는기술
	public CObj
{
public:
	CJackspike();
	virtual ~CJackspike();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	void Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	
private:
	float 	m_SpikeSpeed;
	CObj*	m_pPlayer;
	DWORD	m_time;
	

	

};

