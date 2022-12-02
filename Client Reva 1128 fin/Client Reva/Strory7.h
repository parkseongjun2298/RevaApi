#pragma once
#include "Scene.h"
class CStrory7 :
	public CScene
{
public:
	CStrory7();
	virtual ~CStrory7();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
private:
	int			m_iDrawID;
	RECT		m_tRect;
	INFO		m_tInfo;
};

