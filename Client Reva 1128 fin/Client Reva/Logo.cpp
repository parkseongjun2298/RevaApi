#include "stdafx.h"
#include "Logo.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include"StartButton.h"
CLogo::CLogo()
{
}


CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/바탕화면.bmp", L"Logo");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/게임시작.bmp", L"StartButton");
	CSoundMgr::Get_Instance()->PlayBGM(L"시작브금.mp3");
}

void CLogo::Update()
{
	CObj* pObj = new CStartButton;
	pObj->Initiailize();
	pObj->Set_Pos(284, 290);
	dynamic_cast<CStartButton*> (pObj)->Set_FrameKey(L"StartButton");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI3, pObj);
	CObjMgr::Get_Instance()->Update();
}

void CLogo::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	
}

void CLogo::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Logo");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);


	CObjMgr::Get_Instance()->Render(hDC);
}

void CLogo::Release()
{
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UI3);
}
