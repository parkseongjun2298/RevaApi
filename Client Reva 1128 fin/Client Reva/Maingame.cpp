#include "stdafx.h"
#include "Maingame.h"
#include"ObjMgr.h"
#include "Mouse.h"
#include "SceneMgr.h"
CMaingame::CMaingame()
{
}


CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/���2.bmp", L"Back");
	//������۸��ϱ�
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/�������.bmp", L"BackBuffer");
	m_hDC = GetDC(g_hWND);
	CSoundMgr::Get_Instance()->Initialize();

	CObj* pObj = new CMouse;
	pObj->Initiailize();
	CObjMgr::Get_Instance()->Add_Object(OBJ::MOUSE, pObj);

	//CObjMgr::Get_Instance()->MakeMap();
	CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_LOGO);

	
	
}

void CMaingame::Update()
{
	//CObjMgr::Get_Instance()->Update();
	CSceneMgr::Get_Instance()->Update();
}

void CMaingame::LateUpdate()
{
	//CObjMgr::Get_Instance()->LateUpdate();
	CSceneMgr::Get_Instance()->LateUpdate();
	CKeyMgr::Get_Instance()->KeyUpdate();
}

void CMaingame::Render()
{
	
	HDC hBack = CBitmapMgr::Get_Instance()->Get_MemDC(L"BackBuffer");

	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Back");
	if (nullptr == hMemDC || nullptr == hBack)
		return;
	BitBlt(hBack,// ���� ���� DC
		0, 0,// �׸��� ����� �� ��� ��ǥ 
		WINCX, WINCY,// �׸��� ũ�� 
		hMemDC,// ���� �� DC
		0, 0,// �׸������� �� ��� ��ǥ 
		SRCCOPY);// �׸� ��� ���. 

	//CObjMgr::Get_Instance()->Render(m_hDC);
	CSceneMgr::Get_Instance()->Render(hBack);
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBack, 0, 0, SRCCOPY);
}

void CMaingame::Release()
{
	
	ReleaseDC(g_hWND, m_hDC);
	CBitmapMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();
	CSoundMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
}
