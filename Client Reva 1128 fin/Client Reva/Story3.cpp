#include "stdafx.h"
#include "Story3.h"
#include"SceneMgr.h"

CStory3::CStory3()
{
}


CStory3::~CStory3()
{
}

void CStory3::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/스테이지1대화3.bmp", L"Talk3");
}

void CStory3::Update()
{
}

void CStory3::LateUpdate()
{
	if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STORY4);
}

void CStory3::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Talk3");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CStory3::Release()
{
}
