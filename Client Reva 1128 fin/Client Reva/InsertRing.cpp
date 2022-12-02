#include "stdafx.h"
#include "InsertRing.h"
#include"SceneMgr.h"
#include"ObjMgr.h"
#include"InvenOutButton.h"
CInsertRing::CInsertRing()
{
}


CInsertRing::~CInsertRing()
{
	Release();
}

void CInsertRing::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/인벤반지장착.bmp", L"InvenInsert");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/인벤나가기.bmp", L"InvenOut");
}

void CInsertRing::Update()
{
	CObj* pObj = new CInvenOutButton;
	pObj->Initiailize();
	pObj->Set_Pos(423, 18);
	dynamic_cast<CInvenOutButton*> (pObj)->Set_FrameKey(L"InvenOut");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI5, pObj);
	CObjMgr::Get_Instance()->Update();
}

void CInsertRing::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CInsertRing::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"InvenInsert");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CInsertRing::Release()
{
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UI5);
}
