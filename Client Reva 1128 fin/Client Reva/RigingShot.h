#pragma once
#include "Obj.h"
class CRigingShot :
	//�Ѿ��ϳ� ������ ������ ���
	public CObj
{
public:
	CRigingShot();
	virtual ~CRigingShot();

	// CObj��(��) ���� ��ӵ�
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	float m_fGun_Speed;


};

