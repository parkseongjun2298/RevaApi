#pragma once
#include "Obj.h"
class CDunButton :
	public CObj
{
public:
	CDunButton();
	virtual ~CDunButton();
public:
	// CObj��(��) ���� ��ӵ�
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

