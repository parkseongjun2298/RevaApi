#pragma once
#include "Obj.h"
class CCharButton :
	public CObj
{
public:
	CCharButton();
	virtual ~CCharButton();

	// CObj을(를) 통해 상속됨
	void Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
private:
	TCHAR* m_pFrameKey;
	int m_iDrawID;
};

