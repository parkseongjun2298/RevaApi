#include "stdafx.h"
#include "Stage4.h"
#include"ObjMgr.h"
#include"SceneMgr.h"
#include"BossMonster.h"
#include"Gun.h"
CStage4::CStage4()
{
}


CStage4::~CStage4()
{
	Release();
}

void CStage4::Initialize()
{
	
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/���3.bmp", L"back3");
	CObjMgr::Get_Instance()->MakeMap4(); //������������
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/��ųâ.bmp", L"SkillMenu");
	
	
}

void CStage4::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage4::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	if (CObjMgr::Get_Instance()->Get_DeathCheck() == true)//���� ��� ���Ͱ� ������ �������� �Ѿ�� (����� �����ߴ���, �׾����� üũ)
	{
		
		CObjMgr::Get_Instance()->Get_Player()->Set_Dead();
		//CObjMgr::Get_Instance()->Get_Hyper()->Set_Dead();
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_END);
	
		//�÷��̾��׿��� �㿡 �ȳ�����


	}
}

void CStage4::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"back3");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);

	HDC hMemDC2 = CBitmapMgr::Get_Instance()->Get_MemDC(L"SkillMenu");
	GdiTransparentBlt(hDC,//������� ��� 
		0, 0,// ����� �»�� ��ǥ 
		251, 124, // �󸶸�ŭ ��� �� ������ 
		hMemDC2,// ������ ��� 
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

void CStage4::Release()
{
	

}
