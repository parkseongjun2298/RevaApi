#include "stdafx.h"
#include "SelectDun.h"
#include"ObjMgr.h"
#include"DunButton.h"
CSelectDun::CSelectDun()
{
}


CSelectDun::~CSelectDun()
{
	Release();
}

void CSelectDun::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/던전선택.bmp", L"SelectDun");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/던전선택2.bmp", L"Dun2");

	CObj* pObj = new CDunButton;
	pObj->Initiailize();
	pObj->Set_Pos(272, 127);
	dynamic_cast<CDunButton*> (pObj)->Set_FrameKey(L"Dun2");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI2, pObj);
}

void CSelectDun::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CSelectDun::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CSelectDun::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"SelectDun");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CSelectDun::Release()
{
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UI2);
}
