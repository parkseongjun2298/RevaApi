#pragma once
#include "Obj.h"
class MyButton :
	public CObj
{
public:
	MyButton();
	virtual ~MyButton();
public:
	void Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }
	// CObj을(를) 통해 상속됨
	virtual void Initiailize() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
private:
	TCHAR* m_pFrameKey;
	int m_iDrawID;
};

