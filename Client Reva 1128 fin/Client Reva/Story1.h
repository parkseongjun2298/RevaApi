#pragma once
#include "Scene.h"
class CStory1 :
	public CScene
{
public:
	CStory1();
	virtual ~CStory1();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

