#include "stdafx.h"
#include "Story8.h"
#include"SceneMgr.h"
#include"ObjMgr.h"
//#include"Obj.h"
//#include"GetRingButton.h"
CStory8::CStory8()
{
}


CStory8::~CStory8()
{
	Release();
}

void CStory8::Initialize()
{
	m_tRect.bottom = 404;
	m_tRect.left = 0;
	m_tRect.top = 0;
	m_tRect.right = 546;
	m_tInfo.iCX = 546;
	m_tInfo.iCY = 404;
	m_iDrawID = 0;
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/스토리3.bmp", L"Talk8");
	/*CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/하트링.bmp", L"HeartRing");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/하트링확인.bmp", L"GetRingButton");*/
}

void CStory8::Update()
{
	//CObjMgr::Get_Instance()->Update();
	/*CObj* pObj = new CGetRingButton;
	pObj->Initiailize();
	pObj->Set_Pos(284, 294);
	dynamic_cast<CGetRingButton*> (pObj)->Set_FrameKey(L"GetRingButton");
	CObjMgr::Get_Instance()->Add_Object(OBJ::UI8, pObj);*/
}

void CStory8::LateUpdate()
{
	//CObjMgr::Get_Instance()->LateUpdate();

	if (CKeyMgr::Get_Instance()->KeyDown(VK_RETURN))
	{

		m_iDrawID++;
		if (m_iDrawID >= 3)
		{
			CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STAGE3);
			return;
		}
	}
}

void CStory8::Render(HDC hDC)
{
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(L"Talk8");
	if (nullptr == hMemDC)
		return;


	GdiTransparentBlt(hDC,
		m_tRect.left, m_tRect.top,
		m_tInfo.iCX, m_tInfo.iCY,
		hMemDC,
		m_tInfo.iCX * m_iDrawID, 0,
		m_tInfo.iCX, m_tInfo.iCY,
		RGB(0, 255, 255));



	//CObjMgr::Get_Instance()->Render(hDC);

	//HDC hMemDC2 = CBitmapMgr::Get_Instance()->Get_MemDC(L"HeartRing");


	////BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);


	//GdiTransparentBlt(hDC,//복사받을 대상 
	//	60, 40,// 출력할 좌상단 좌표 
	//	283, 148, // 얼마만큼 출력 할 것인지 
	//	hMemDC2,// 복사할 대상 
	//	0, 0,// 그림에서의 시작 좌상단 좌표 
	//	283, 148,// 그림에서 얼마만큼 출력할 것인지 . 
	//	RGB(255, 0, 255));

}

void CStory8::Release()
{
}
