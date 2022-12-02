#pragma once
#include "Scene.h"
class CInven :
	public CScene
{
public:
	CInven();
	virtual ~CInven();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

