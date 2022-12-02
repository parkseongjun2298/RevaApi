#pragma once
#include "Scene.h"
class CStory2 :
	public CScene
{
public:
	CStory2();
	virtual ~CStory2();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

