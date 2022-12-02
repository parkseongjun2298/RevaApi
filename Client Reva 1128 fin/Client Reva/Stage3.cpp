#include "stdafx.h"
#include "Stage3.h"
#include"Monster2.h"
#include"ObjMgr.h"
#include"Gun.h"
#include"SceneMgr.h"

CStage3::CStage3()
{
}


CStage3::~CStage3()
{
	Release();
}

void CStage3::Initialize()
{
	CObjMgr::Get_Instance()->MakeMap3(); //������������
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/��ųâ.bmp", L"SkillMenu");
}

void CStage3::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage3::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
	if (CObjMgr::Get_Instance()->Get_DeathCheck() == true)//���� ��� ���Ͱ� ������ �������� �Ѿ�� (����� �����ߴ���, �׾����� üũ)
	{
		CSoundMgr::Get_Instance()->StopSound(CSoundMgr::BGM);//��ݸ��߱�
		CSoundMgr::Get_Instance()->StopAll();//�ٸ��߱�
		CObjMgr::Get_Instance()->Get_Player()->Set_Dead();
		//CObjMgr::Get_Instance()->Get_Hyper()->Set_Dead();
		
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_CLEAR1);
	
		//�÷��̾��׿��� �㿡 �ȳ�����
		

	}
}

void CStage3::Render(HDC hDC)
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

void CStage3::Release()
{
}
