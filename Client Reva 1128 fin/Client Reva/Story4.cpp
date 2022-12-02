#include "stdafx.h"
#include "Story4.h"
#include"SceneMgr.h"


CStory4::CStory4()
{
}


CStory4::~CStory4()
{
}

void CStory4::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/스테이지1대화4.bmp", L"Talk4");
}

void CStory4::Update()
{
}

void CStory4::LateUpdate()
{

	if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STORY5);
}

void CStory4::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Talk4");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CStory4::Release()
{
}
