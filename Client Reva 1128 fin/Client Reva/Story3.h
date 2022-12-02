#pragma once
#include "Scene.h"
class CStory3 :
	public CScene
{
public:
	CStory3();
	virtual ~CStory3();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

