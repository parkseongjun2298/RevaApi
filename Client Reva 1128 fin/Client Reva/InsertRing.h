#pragma once
#include "Scene.h"
class CInsertRing :
	public CScene
{
public:
	CInsertRing();
	virtual ~CInsertRing();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

