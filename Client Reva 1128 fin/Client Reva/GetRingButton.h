#pragma once
#include "Obj.h"
class CGetRingButton :
	public CObj
{
public:
	CGetRingButton();
	virtual ~CGetRingButton();

	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	void Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }



private:
	TCHAR* m_pFrameKey;
	int m_iDrawID;
};

