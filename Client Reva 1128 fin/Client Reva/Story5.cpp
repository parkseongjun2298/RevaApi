#include "stdafx.h"
#include "Story5.h"
#include"SceneMgr.h"

CStory5::CStory5()
{
}


CStory5::~CStory5()
{
}

void CStory5::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/스테이지1대화5.bmp", L"Talk5");
}

void CStory5::Update()
{
}

void CStory5::LateUpdate()
{
	if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STORY6);
}

void CStory5::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Talk5");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CStory5::Release()
{
}
