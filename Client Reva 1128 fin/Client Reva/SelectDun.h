#pragma once
#include "Scene.h"
class CSelectDun :
	public CScene
{
public:
	CSelectDun();
	virtual ~CSelectDun();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

