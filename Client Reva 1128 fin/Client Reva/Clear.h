#pragma once
#include "Scene.h"
class CClear :
	public CScene
{
public:
	CClear();
	virtual ~CClear();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

