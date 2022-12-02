#include "stdafx.h"
#include "Story6.h"
#include"SceneMgr.h"

CStory6::CStory6()
{
}


CStory6::~CStory6()
{
}

void CStory6::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/스테이지1대화6.bmp", L"Talk6");
}

void CStory6::Update()
{
}

void CStory6::LateUpdate()
{
	if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STAGE);
}

void CStory6::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Talk6");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CStory6::Release()
{
}
