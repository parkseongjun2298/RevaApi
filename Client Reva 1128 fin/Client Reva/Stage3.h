#pragma once
#include "Scene.h"
class CObj;
class CStage3 :
	public CScene
{
public:
	CStage3();
	virtual ~CStage3();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

