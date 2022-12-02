#pragma once
#include "Scene.h"
class CStory4 :
	public CScene
{
public:
	CStory4();
	virtual ~CStory4();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

