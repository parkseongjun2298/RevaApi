#pragma once
#include "Scene.h"
class CStory6 :
	public CScene
{
public:
	CStory6();
	virtual ~CStory6();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

