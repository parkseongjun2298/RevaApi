#pragma once
#include "Scene.h"
class CGetRing :
	public CScene
{
public:
	CGetRing();
	virtual ~CGetRing();

	

	

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;

	virtual void Update() override;

	virtual void LateUpdate() override;

	virtual void Render(HDC hDC) override;

	virtual void Release() override;

};

