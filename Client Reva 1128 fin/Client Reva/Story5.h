#pragma once
#include "Scene.h"
class CStory5 :
	public CScene
{
public:
	CStory5();
	virtual ~CStory5();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

