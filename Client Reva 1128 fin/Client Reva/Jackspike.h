#pragma once
#include "Obj.h"
class CJackspike :
	//�������ζ��±��
	public CObj
{
public:
	CJackspike();
	virtual ~CJackspike();

	// CObj��(��) ���� ��ӵ�
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

