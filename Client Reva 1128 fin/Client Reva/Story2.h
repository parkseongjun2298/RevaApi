#pragma once
#include "Scene.h"
class CStory2 :
	public CScene
{
public:
	CStory2();
	virtual ~CStory2();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

