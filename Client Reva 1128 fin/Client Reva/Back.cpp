#include "stdafx.h"
#include "Back.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include"Obj.h"
CBack::CBack()
{
}


CBack::~CBack()
{
}

void CBack::Initialize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/���3.bmp", L"back3");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/��ųâ.bmp", L"SkillMenu");
}

void CBack::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CBack::LateUpdate()
{
	CObjMgr::Get_Instance()->LateUpdate();
}

void CBack::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"back3");
	if (nullptr == hMemDC)
		return;

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

void CBack::Release()
{
	CObjMgr::Get_Instance()->Delete_Object(OBJ::UIBACK);
}
