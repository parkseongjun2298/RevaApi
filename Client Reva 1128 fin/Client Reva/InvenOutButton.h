#pragma once
#include "Obj.h"
class CInvenOutButton :
	public CObj
{
public:
	CInvenOutButton();
	virtual ~CInvenOutButton();

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

