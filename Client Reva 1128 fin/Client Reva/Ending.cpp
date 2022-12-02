#include "stdafx.h"
#include "Ending.h"
#include"SceneMgr.h"
#include"ObjMgr.h"

CEnding::CEnding()
{
}


CEnding::~CEnding()
{
	Release();
}

void CEnding::Initialize()
{
	CSoundMgr::Get_Instance()->StopSound(CSoundMgr::BGM);//브금멈추기
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/엔딩.bmp", L"End");
}

void CEnding::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CEnding::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CEnding::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"End");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CEnding::Release()
{
}
