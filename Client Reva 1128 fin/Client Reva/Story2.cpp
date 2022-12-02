#include "stdafx.h"
#include "Story2.h"
#include"SceneMgr.h"

CStory2::CStory2()
{
}


CStory2::~CStory2()
{
}

void CStory2::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/��������1��ȭ2.bmp", L"Talk2");
}

void CStory2::Update()
{

}

void CStory2::LateUpdate()
{
	// ����ڰ� ���� �ϸ� ���� ������ �Ѿ�� ������. 
	if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STORY3);
}

void CStory2::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Talk2");
	if (nullptr == hMemDC)
		return;

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CStory2::Release()
{
}
