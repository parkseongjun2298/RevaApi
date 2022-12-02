#include "stdafx.h"
#include "Stage2.h"
#include"Monster1.h"
#include"ObjMgr.h"
#include"Gun.h"
#include"SceneMgr.h"
CStage2::CStage2()
{
}


CStage2::~CStage2()
{
	Release();
}

void CStage2::Initialize()
{
	
	CObjMgr::Get_Instance()->MakeMap2(); //������������
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/��ųâ.bmp", L"SkillMenu");
}

void CStage2::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage2::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	if (CObjMgr::Get_Instance()->Get_DeathCheck() == true)//���� ��� ���Ͱ� ������ �������� �Ѿ�� (����� �����ߴ���, �׾����� üũ)
	{
		//CObjMgr::Get_Instance()->Get_Hyper()->Set_Dead();
		CObjMgr::Get_Instance()->Get_Player()->Set_Hp(500);
		CObjMgr::Get_Instance()->Get_Player()->Set_Mp(500);
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_GETRINGSTORY);
		CObjMgr::Get_Instance()->Set_DeathCheck(false);



	}
}

void CStage2::Render(HDC hDC)
{
	CObjMgr::Get_Instance()->Render(hDC);

	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"SkillMenu");
	GdiTransparentBlt(hDC,//������� ��� 
		0, 0,// ����� �»�� ��ǥ 
		251, 124, // �󸶸�ŭ ��� �� ������ 
		hMemDC,// ������ ��� 
		0, 0,// �׸������� ���� �»�� ��ǥ 
		251, 124,// �׸����� �󸶸�ŭ ����� ������ . 
		RGB(255, 0, 255));

	HBRUSH brush, oldbrush;
	//Hp��
	brush = CreateSolidBrush(RGB(255, 0, 0));
	oldbrush = (HBRUSH)SelectObject(hDC, brush);
	Rectangle(hDC, 22, 10, CObjMgr::Get_Instance()->Get_Player()->Get_Hp() / 4 - 5, 20);
	SelectObject(hDC, oldbrush);
	DeleteObject(brush);

	//Mp��
	brush = CreateSolidBrush(RGB(0, 0, 255));
	oldbrush = (HBRUSH)SelectObject(hDC, brush);
	Rectangle(hDC, 22, 22, CObjMgr::Get_Instance()->Get_Player()->Get_Mp() / 4 - 5, 30);
	SelectObject(hDC, oldbrush);
	DeleteObject(brush);
}

void CStage2::Release()
{
}
