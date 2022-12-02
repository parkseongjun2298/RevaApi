#include "stdafx.h"
#include "Inven.h"
#include"SceneMgr.h"
#include"ObjMgr.h"
#include"InvenOutButton.h"
#include"RingButton.h"
CInven::CInven()
{
}


CInven::~CInven()
{
	Release();
}

void CInven::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/인벤창.bmp", L"Inven");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/인벤나가기.bmp", L"InvenOut");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/인벤반지.bmp", L"InvenRing");
}

void CInven::Update()
{
	CObj* pObj = new CInvenOutButton;
	pObj->Initiailize();
	pObj->Set_Pos(439, 16);
	dynamic_cast<CInvenOutButton*> (pObj)->Set_FrameKey(L"InvenOut");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI5, pObj);

	CObj* pObj2 = new CRingButton;
	pObj2->Initiailize();
	pObj2->Set_Pos(250, 80);
	dynamic_cast<CRingButton*> (pObj2)->Set_FrameKey(L"InvenRing");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI7, pObj2);

	CObjMgr::Get_Instance()->Update();
}

void CInven::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CInven::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Inven");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CInven::Release()
{
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UI5);
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UI7);
}
