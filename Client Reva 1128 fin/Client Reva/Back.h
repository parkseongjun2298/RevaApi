#pragma once
#include "Scene.h"
class CBack :
	public CScene
{
public:
	CBack();
	virtual ~CBack();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

