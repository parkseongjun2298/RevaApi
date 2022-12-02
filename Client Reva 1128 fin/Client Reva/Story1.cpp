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
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/��������1��ȭ.bmp", L"Talk1");
	CSoundMgr::Get_Instance()->PlayBGM(L"������.mp3");
}


void CStory1::Update()
{
	
}

void CStory1::LateUpdate()
{
	// ����ڰ� ���� �ϸ� ���� ������ �Ѿ�� ������. 
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
