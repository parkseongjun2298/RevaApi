#pragma once
#include "Scene.h"
class CStory3 :
	public CScene
{
public:
	CStory3();
	virtual ~CStory3();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

