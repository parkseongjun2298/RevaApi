#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include"Monster1.h"
#include"ObjMgr.h"
#include"Gun.h"
#include"SceneMgr.h"
#include"Obj.h"
CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	
	
	CObjMgr::Get_Instance()->MakeMap(); //스테이지생성
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/스킬창.bmp", L"SkillMenu");
	
	
}

void CStage::Update()
{
	CObjMgr::Get_Instance()->Update();


}

void CStage::LateUpdate()
{
	
	CObjMgr::Get_Instance()->LateUpdate();
	if (CObjMgr::Get_Instance()->Get_DeathCheck()==true)//맵의 모든 몬스터가 죽으면 스테이지 넘어가기 (몇마리를 생성했는지, 죽었는지 체크)
	{
		//CObjMgr::Get_Instance()->Get_Hyper()->Set_Dead();
		CObjMgr::Get_Instance()->Get_Player()->Set_Hp(500);
		CObjMgr::Get_Instance()->Get_Player()->Set_Mp(500);
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STORY7);
		CObjMgr::Get_Instance()->Set_DeathCheck(false);
	}

}

void CStage::Render(HDC hDC)
{
	


	CObjMgr::Get_Instance()->Render(hDC);

	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"SkillMenu");
	
	
	//BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
	

	GdiTransparentBlt(hDC,//복사받을 대상 
		0, 0,// 출력할 좌상단 좌표 
		251, 124, // 얼마만큼 출력 할 것인지 
		hMemDC,// 복사할 대상 
		0 ,0 ,// 그림에서의 시작 좌상단 좌표 
		251, 124,// 그림에서 얼마만큼 출력할 것인지 . 
		RGB(255, 0, 255));


	
	HBRUSH brush, oldbrush;
	//Hp바
	brush = CreateSolidBrush(RGB(255, 0, 0));
	oldbrush = (HBRUSH)SelectObject(hDC, brush);
	Rectangle(hDC, 22, 10, CObjMgr::Get_Instance()->Get_Player()->Get_Hp()/4-5, 20);
	SelectObject(hDC, oldbrush);
	DeleteObject(brush);

	//Mp바
	brush = CreateSolidBrush(RGB(0, 0, 255));
	oldbrush = (HBRUSH)SelectObject(hDC, brush);
	Rectangle(hDC, 22, 22, CObjMgr::Get_Instance()->Get_Player()->Get_Mp() / 4-5, 30);
	SelectObject(hDC, oldbrush);
	DeleteObject(brush);
}

void CStage::Release()
{
}
