#pragma once
#include "Obj.h"
class CRigingShot :
	//총알하나 던져서 맞으면 에어본
	public CObj
{
public:
	CRigingShot();
	virtual ~CRigingShot();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	float m_fGun_Speed;


};

