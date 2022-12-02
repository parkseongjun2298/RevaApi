#include "stdafx.h"
#include "MyMenu.h"
#include"CharButton.h"
#include "ObjMgr.h"

CMyMenu::CMyMenu()
{
}


CMyMenu::~CMyMenu()
{
	Release();
}

void CMyMenu::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/캐릭터선택.bmp", L"Menu");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/캐릭선택.bmp", L"SelectChar");

	CObj* pObj = new CCharButton;
	pObj->Initiailize();
	pObj->Set_Pos(152.5, 348);
	dynamic_cast<CCharButton*> (pObj)->Set_FrameKey(L"SelectChar");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI, pObj);



	
	
}

void CMyMenu::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CMyMenu::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CMyMenu::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Menu");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CMyMenu::Release()
{
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UI);
}
