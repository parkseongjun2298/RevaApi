#include "stdafx.h"
#include "GetRing.h"
#include"SceneMgr.h"

CGetRing::CGetRing()
{
}


CGetRing::~CGetRing()
{
}

void CGetRing::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/¹ÝÁöµæ.bmp", L"GetRingStory");
}

void CGetRing::Update()
{
}

void CGetRing::LateUpdate()
{
	if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STORY8);
}

void CGetRing::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"GetRingStory");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CGetRing::Release()
{
}

