#include "stdafx.h"
#include "Clear.h"
#include"SceneMgr.h"
#include"ObjMgr.h"
#include"NextButton.h"
#include"InvenGoButton.h"
CClear::CClear()
{
}


CClear::~CClear()
{
	Release();
}

void CClear::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/스테이지1클리어.bmp", L"Clear1");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/다음스테이지.bmp", L"NextButton");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/인벤.bmp", L"InvenButton");
}

void CClear::Update()
{

	CObj* pObj = new CNextButton;
	pObj->Initiailize();
	pObj->Set_Pos(284, 294);
	dynamic_cast<CNextButton*> (pObj)->Set_FrameKey(L"NextButton");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI4, pObj);

	CObj* pObj2 = new CInvenGoButton;
	pObj2->Initiailize();
	pObj2->Set_Pos(322, 258);
	dynamic_cast<CInvenGoButton*> (pObj2)->Set_FrameKey(L"InvenButton");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI6, pObj2);

	CObjMgr::Get_Instance()->Update();
}

void CClear::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();

}

void CClear::Render(HDC hDC)
{
	
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Clear1");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);



	CObjMgr::Get_Instance()->Render(hDC);
}

void CClear::Release()
{
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UI4);
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UI6);
}
