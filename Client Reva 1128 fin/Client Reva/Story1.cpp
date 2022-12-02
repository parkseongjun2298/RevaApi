#include "stdafx.h"
#include "Story1.h"
#include"SceneMgr.h"

CStory1::CStory1()
{
}


CStory1::~CStory1()
{
}

void CStory1::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/스테이지1대화.bmp", L"Talk1");
	CSoundMgr::Get_Instance()->PlayBGM(L"고블린브금.mp3");
}


void CStory1::Update()
{
	
}

void CStory1::LateUpdate()
{
	// 사용자가 뭔가 하면 다음 씬으로 넘어가게 만들자. 
	if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STORY2);
}

void CStory1::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Talk1");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CStory1::Release()
{
}
