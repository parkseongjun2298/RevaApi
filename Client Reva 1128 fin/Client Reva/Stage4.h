#pragma once
#include "Scene.h"
class CObj;
class CStage4 :
	public CScene
{
public:
	CStage4();
	virtual ~CStage4();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

};

