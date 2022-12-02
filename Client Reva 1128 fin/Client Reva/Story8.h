#pragma once
#include "Scene.h"
class CStory8 :
	public CScene
{
public:
	CStory8();
	virtual ~CStory8();

	// CScene��(��) ���� ��ӵ�
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

