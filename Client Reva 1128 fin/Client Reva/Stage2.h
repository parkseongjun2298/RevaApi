#pragma once
#include "Scene.h"
class CObj;
class CStage2 :
	public CScene
{
public:
	CStage2();
	virtual ~CStage2();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

