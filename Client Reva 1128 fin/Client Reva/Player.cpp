#include "stdafx.h"
#include "Player.h"
#include"Jackspike.h"
#include"Cross.h"
#include"FlashMine.h"
#include"Neiphamtan.h"
#include"Buster.h"
#include"Flasher.h"
#include"FLeezer.h"
#include"HyperSkill.h"
#include"NillSna.h"
#include"C4.h"
#include"FlameShot.h"
#include"ObjMgr.h"
CPlayer::CPlayer()
{
	
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initiailize()
{
	
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/���ٿ�����.bmp", L"Player_Right");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/���ٿ���.bmp", L"Player_Left");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/f�̹�����.bmp", L"FBuster");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/G��.bmp", L"GFlasher");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/H��.bmp", L"HFleezer");
	
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/�ҽ���������.bmp", L"NillSnaJin");
	bJumpCheck = false;
	m_iMaxHp = 500;
	m_iMaxMp = 500;
	m_iMp = m_iMaxMp;
	m_iHp = m_iMaxHp;
	m_iAtt = 10;
	m_tInfo.iCX = 191;
	m_tInfo.iCY = 202;
	m_PlayerSpeed= 5.f;
	m_tInfo.fSpeed = 5.f;
	//m_dwOldTime2 = GetTickCount();
	//m_dwOldTime3 = GetTickCount();
	m_eState = PLAYER::IDLE;
	m_eState2 = PLAYERJS::IDLE;
	m_Accer = 40;
	iCount = 6;
	iCount2 = 5;
	iCount3 = 4;
	m_bDead = false;
	m_bCheck = false;
	m_iDrawID = -1;
	m_iDrawID2 = -1;
	m_iDrawID3 = -1;
	m_iDrawID4 = -1;
	m_fCheck = false;
	m_GCheck = false;
	m_TCheck = false;
	m_pFrameKey = L"Player_Right";
	m_eCurState = STATE_R;
	m_eNextState = STATE_IDLE;

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 2;
	m_tFrame.iFrameScene = 6;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();
}

int CPlayer::Update()
{
	



	if (m_bDead)
	{
		return OBJ_DEAD;
	}


	if (Get_State2() == PLAYERJS::RIGHT)
	{
		m_pFrameKey = L"Player_Right";
		m_eNextState = STATE_IDLE;
	}
	if (Get_State2() == PLAYERJS::LEFT)
	{
		m_pFrameKey = L"Player_Left";
		m_eNextState = STATE_IDLE;
	}
	if (m_tInfo.fX <= 49 )
	{
		m_tInfo.fX = 50;
	}
	if (m_tInfo.fX >= WINCX)
	{
		m_tInfo.fX = WINCX-20;
	}

	if (m_eState == PLAYER::JUMP)
	{
		
		bJumpCheck = true;
		m_tInfo.fY -= m_Accer;
		m_Accer -= 3.f;
		if (m_tInfo.fY >= WINCY - 125)
		{
			
			m_tInfo.fY = WINCY - 125;
			m_eState = PLAYER::IDLE;
			bJumpCheck = false;

		}
		if (Get_State2() == PLAYERJS::RIGHT)
		{
			m_pFrameKey = L"Player_Right";
			m_eNextState = STATE_JUMP;
		}
		if (Get_State2() == PLAYERJS::LEFT)
		{
			m_pFrameKey = L"Player_Left";
			m_eNextState = STATE_JUMP;
		}


	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000&& bJumpCheck == false)
	{
		
			m_tInfo.fX -= m_PlayerSpeed;
			m_eState = PLAYER::LEFT;
			m_eState2 = PLAYERJS::LEFT;
			m_pFrameKey = L"Player_Left";
			m_eNextState = STATE_WALK;
			//CSoundMgr::Get_Instance()->PlaySound(L"�ȴ¼Ҹ�.mp3", CSoundMgr::PLAYER);
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && bJumpCheck == false)
	{
		
			m_tInfo.fX += m_PlayerSpeed;
			m_eState = PLAYER::RIGHT;
			m_eState2 = PLAYERJS::RIGHT;
			m_pFrameKey = L"Player_Right";
			m_eNextState = STATE_WALK;
			//CSoundMgr::Get_Instance()->PlaySound(L"�ȴ¼Ҹ�.mp3", CSoundMgr::PLAYER);
			
	}
	 if(GetAsyncKeyState('C') & 0x8000) 
	{
		 
		 if (m_eState != PLAYER::JUMP)
		 {
			 CSoundMgr::Get_Instance()->PlaySound(L"�����Ҹ�.mp3", CSoundMgr::PLAYER);
			 m_eState = PLAYER::JUMP;
			 m_Accer = 40.f;
		 }
	
	 
	 }
	 if (GetAsyncKeyState('X') & 0x8000)
	 {

		 if (Get_State() == PLAYER::RIGHT)
		 {
			 m_pFrameKey = L"Player_Right";
			 m_eNextState = STATE_ATT;
		 }

		 if (Get_State() == PLAYER::LEFT)
		 {
			 m_pFrameKey = L"Player_Left";
			 m_eNextState = STATE_ATT;
		 }
		 CSoundMgr::Get_Instance()->PlaySound(L"��Ÿ.mp3", CSoundMgr::PLAYER);
	 }
	 if (GetAsyncKeyState('A') & 0x8000)
	 {
	
	/* if (m_dwOldTime + 1000 < GetTickCount()) 
	 {
		 m_dwOldTime = GetTickCount();*/

		 CSoundMgr::Get_Instance()->PlaySound(L"�轺����ũ.mp3", CSoundMgr::EFFECT);
		

			 CObj* pObj = new CJackspike;
			 pObj->Initiailize();
			 dynamic_cast<CJackspike*>(pObj)->Set_Player(this);
			 if (Get_State()==PLAYER::RIGHT) {
				 m_pFrameKey = L"Player_Right";
				 m_eNextState = STATE_A;
				 pObj->Set_Pos(m_tInfo.fX , m_tInfo.fY);
			 }
			 if (Get_State() == PLAYER::LEFT) {
				 m_pFrameKey = L"Player_Left";
				 m_eNextState = STATE_A;
				 pObj->Set_Pos(m_tInfo.fX , m_tInfo.fY);
			 }
			 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::JACKSPIKE);

			

		// }
	 }

	 if (GetAsyncKeyState('D') & 0x8000)
	 {
		
	 if (m_dwOldTime2 + 5000 < GetTickCount())
	 {
		 CSoundMgr::Get_Instance()->PlaySound(L"cross.mp3", CSoundMgr::EFFECT);
		 m_dwOldTime2 = GetTickCount();
		
			 CObj* pObj = new CCross;
			 pObj->Initiailize();
			 dynamic_cast<CCross*>(pObj)->Set_Player(this);
			 if (Get_State() == PLAYER::RIGHT) {
				 m_pFrameKey = L"Player_Right";
				 m_eNextState = STATE_ATT;
				 pObj->Set_Pos(m_tInfo.fX + 250, m_tInfo.fY);
			 }
			 if (Get_State() == PLAYER::LEFT) {
				 m_pFrameKey = L"Player_Left";
				 m_eNextState = STATE_ATT;
				 pObj->Set_Pos(m_tInfo.fX - 250, m_tInfo.fY);
			 }
			 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::CROSS);
			 Set_Mp(Get_Mp() - 40);
		 }
	 }

	 if (GetAsyncKeyState('F') & 0x0001)

		 //icount�� 6�϶� ����
	 {
		 m_fCheck = true;
		 m_bCheck = true;
		 CSoundMgr::Get_Instance()->PlaySound(L"F����.mp3", CSoundMgr::EFFECT);
		 if ( iCount >0 && iCount <= 5 && m_bCheck == true) // 0���� ũ�� ,5 ���� �۾ƾߵǰ�, Ʈ�� 
		 {
			 if (m_dwOldTime2 + 500 < GetTickCount())
			 {
				 CSoundMgr::Get_Instance()->PlaySound(L"F������.mp3", CSoundMgr::EFFECT);
				 CObj* pObj = new CBuster;
				 pObj->Initiailize();
				 dynamic_cast<CBuster*>(pObj)->Set_Player(this);
				 if (Get_State() == PLAYER::RIGHT) {
					 pObj->Set_Pos(m_tInfo.fX + 100, m_tInfo.fY);
				 }
				 if (Get_State() == PLAYER::LEFT) {
					 pObj->Set_Pos(m_tInfo.fX - 100, m_tInfo.fY);
				 }
				 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::BUSTER);
				 Set_Mp(Get_Mp() - 30);
				 
				 m_dwOldTime2 = GetTickCount();
			 }
		 }
		 else if (iCount == 0)
		 {
			 iCount = 6;
			// m_fCheck = false;
		 }
		 --iCount;



	 }
	 if (GetAsyncKeyState('G') & 0x0001)
	 {
		 //icount�� 4�϶� ����
		 m_GCheck = true;
		 m_bCheck = true;
		 CSoundMgr::Get_Instance()->PlaySound(L"G����.mp3", CSoundMgr::EFFECT);
		 if (iCount2 > 0 && iCount2 <= 4 && m_bCheck == true)
		 {
			 if (m_dwOldTime2 + 500 < GetTickCount())
			 {
				
				
				 CSoundMgr::Get_Instance()->PlaySound(L"����ź.mp3", CSoundMgr::EFFECT);
				 CObj* pObj = new CFlasher;
				 pObj->Initiailize();
				 dynamic_cast<CFlasher*>(pObj)->Set_Player(this);
				 if (Get_State() == PLAYER::RIGHT) {
					 pObj->Set_Pos(m_tInfo.fX + 100, m_tInfo.fY);
				 }
				 if (Get_State() == PLAYER::LEFT) {
					 pObj->Set_Pos(m_tInfo.fX - 100, m_tInfo.fY);
				 }
				 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::FLASHER);
				 Set_Mp(Get_Mp() - 30);
				 m_dwOldTime2 = GetTickCount();
			 }
		 }
		 else if (iCount2 == 0)
		 {
			 iCount2 = 5;
		 }
		 --iCount2;
	 }

	 //icount�� 4�϶� ����
	 if (GetAsyncKeyState('H') & 0x0001)
	 {
		 m_bCheck = true;
		 CSoundMgr::Get_Instance()->PlaySound(L"H����.mp3", CSoundMgr::EFFECT);
		 if (iCount3 > 0 && iCount3 <= 3 && m_bCheck == true)
		 {
			 if (m_dwOldTime2 + 500 < GetTickCount())
			 {
				 CSoundMgr::Get_Instance()->PlaySound(L"Hȿ����.mp3", CSoundMgr::EFFECT);
				 m_dwOldTime2 = GetTickCount();

				 CObj* pObj = new CFLeezer;
				 pObj->Initiailize();
				 dynamic_cast<CFLeezer*>(pObj)->Set_Player(this);
				 if (Get_State() == PLAYER::RIGHT) {
					 pObj->Set_Pos(m_tInfo.fX + 100, m_tInfo.fY);
				 }
				 if (Get_State() == PLAYER::LEFT) {
					 pObj->Set_Pos(m_tInfo.fX - 100, m_tInfo.fY);
				 }
				 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::FLEEZER);
				 Set_Mp(Get_Mp() - 30);
				 m_dwOldTime2 = GetTickCount();
			 }
		 }
		 else if (iCount3 == 0)
		 {
			 iCount3 = 4;
		 }
		 --iCount3;
	 }


	 if (GetAsyncKeyState('Q') & 0x8000)
	 {
		 CSoundMgr::Get_Instance()->PlaySound(L"Q��Ű.mp3", CSoundMgr::EFFECT);
		 if (m_dwOldTime8 + 5000 < GetTickCount())
		 {
			 m_dwOldTime8 = GetTickCount();


			 CObj* pObj = new CFlameShot;
		
			 pObj->Initiailize();
			 dynamic_cast<CFlameShot*>(pObj)->Set_Player(this);
			 dynamic_cast<CFlameShot*>(pObj)->Set_Gun(m_pGun);
			 if (Get_State() == PLAYER::RIGHT) {
				 pObj->Set_Pos(m_tInfo.fX, m_tInfo.fY - 100);
			 }
			 if (Get_State() == PLAYER::LEFT) {
				 pObj->Set_Pos(m_tInfo.fX, m_tInfo.fY - 100);
			 }
			 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::FLAMESHOT);

		 }
	 }

	 if (GetAsyncKeyState('W') & 0x8000)
	 {
	 if (m_dwOldTime3 + 5000 < GetTickCount())
		{
		 m_dwOldTime3 = GetTickCount();
		
			 CObj* pObj = new CFlashMine;
			 pObj->Initiailize();
			 dynamic_cast<CFlashMine*>(pObj)->Set_Player(this);
			 if (Get_State() == PLAYER::RIGHT) {
				 pObj->Set_Pos(m_tInfo.fX+50 , m_tInfo.fY+60);
			 }
			 if (Get_State() == PLAYER::LEFT) {
				 pObj->Set_Pos(m_tInfo.fX-50 , m_tInfo.fY+60);
			 }
			 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::FLASHMINE);
			 Set_Mp(Get_Mp() - 50);
		 }
	 }


	 if (GetAsyncKeyState('E') & 0x8000)
	 {
		 CSoundMgr::Get_Instance()->PlaySound(L"E.mp3", CSoundMgr::EFFECT);
		 if (m_dwOldTime7 + 5000 < GetTickCount())
		 {
			 m_dwOldTime7 = GetTickCount();

			 CObj* pObj = new CC4;
			 pObj->Initiailize();
			 dynamic_cast<CC4*>(pObj)->Set_Player(this);
			 if (Get_State() == PLAYER::RIGHT) {
				 pObj->Set_Pos(m_tInfo.fX+50 , m_tInfo.fY + 60);
			 }
			 if (Get_State() == PLAYER::LEFT) {
				 pObj->Set_Pos(m_tInfo.fX-50 , m_tInfo.fY + 60);
			 }
			 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::C4);
			 Set_Mp(Get_Mp() - 50);
		 }
	 }

	 //1���ڼ������ϰ� ��� �ؾ���
	 if (GetAsyncKeyState('R') & 0x8000)
	 {
		 
			

		 CSoundMgr::Get_Instance()->PlaySound(L"R.mp3", CSoundMgr::EFFECT);

/*
			 if (m_dwOldTime4 + 5000 < GetTickCount())
			 {
				 m_dwOldTime4 = GetTickCount();*/

			
			//	  }
				 CObj* pObj = new CNeiphamtan;
				 pObj->Initiailize();
				 dynamic_cast<CNeiphamtan*>(pObj)->Set_Player(this);
				 if (Get_State() == PLAYER::RIGHT) {
					 pObj->Set_Pos(m_tInfo.fX + 300, m_tInfo.fY);
					 m_pFrameKey = L"Player_Right";
					 m_eNextState = STATE_R;
				 }
				 if (Get_State() == PLAYER::LEFT) {
					 pObj->Set_Pos(m_tInfo.fX - 300, m_tInfo.fY);
					 m_pFrameKey = L"Player_Left";
					 m_eNextState = STATE_R;
				 }
				 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::NEIPHAMTAN);
				 Set_Mp(Get_Mp() - 5);
			
		 
	 }

	 if (GetAsyncKeyState('T') & 0x8000)
	 {
		 CSoundMgr::Get_Instance()->PlaySound(L"�ҽ���.mp3", CSoundMgr::EFFECT);
		 m_TCheck =true;
		
		 if (m_dwOldTime6 + 20000 < GetTickCount())
		 {
			 m_dwOldTime6 = GetTickCount();
			
			 

			 CObj* pObj = new CNillSna;
			 pObj->Initiailize();
			 dynamic_cast<CNillSna*>(pObj)->Set_Player(this);
			 if (Get_State() == PLAYER::RIGHT) {
				 pObj->Set_Pos(m_tInfo.fX , m_tInfo.fY);
			 }
			 if (Get_State() == PLAYER::LEFT) {
				 pObj->Set_Pos(m_tInfo.fX , m_tInfo.fY);
			 }
			 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::NILLSNA);
			 Set_Mp(Get_Mp() - 100);
			
			
		 }

	 }

	 if (GetAsyncKeyState('Y') & 0x8000)
	 {

		 if (m_dwOldTime5 + 10000 < GetTickCount())
		 {

			 m_dwOldTime5 = GetTickCount();

			 CSoundMgr::Get_Instance()->PlaySound(L"�Ŀ¸��̺�����.mp3", CSoundMgr::EFFECT);
			 CSoundMgr::Get_Instance()->PlaySound(L"���������.mp3", CSoundMgr::EFFECT);

			 CObj* pObj = new CHyperSkill;
			 pObj->Initiailize();
			 			
			 dynamic_cast<CHyperSkill*>(pObj)->Set_Player(this);
			 if (Get_State() == PLAYER::RIGHT) {
				 pObj->Set_Pos(m_tInfo.fX , m_tInfo.fY);
			 }
			 if (Get_State() == PLAYER::LEFT) {
				 pObj->Set_Pos(m_tInfo.fX , m_tInfo.fY );
			 }

			
			 CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::HYPERSKILL);
		
			 Set_Mp(Get_Mp() - 150);
		 }

	 }




	return 0;
}

void CPlayer::LateUpdate()
{
	if (CKeyMgr::Get_Instance()->KeyDown('F'))
	{
		//������
		m_iDrawID++;
		if (m_iDrawID >= 5)
		{
			m_iDrawID = -1;
			return;
		}
	}

	if (CKeyMgr::Get_Instance()->KeyDown('G'))
	{
		//������
		++m_iDrawID2;
		if (m_iDrawID2 >= 4)
		{
			m_iDrawID2 = -1;
			return;
		}
	}
	if (CKeyMgr::Get_Instance()->KeyDown('H'))
	{
		//������
		++m_iDrawID4;
		if (m_iDrawID4 >= 3)
		{
			m_iDrawID4 = -1;
			return;
		}
	}
	//�ҽ�������
	if (CKeyMgr::Get_Instance()->KeyDown('T'))
	{
		++m_iDrawID3;

		if (m_iDrawID3 >= 7)
		{
			m_iDrawID3 = -1;
			return;
		}

	}


	FrameChange();
	CObj::FrameMove();




}

void CPlayer::Render(HDC hDC)
{


	


	CObj::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(m_pFrameKey);
	//BitBlt(hDC, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0, SRCCOPY);
	GdiTransparentBlt(hDC,//������� ��� 
		m_tRect.left, m_tRect.top,// ����� �»�� ��ǥ 
		m_tInfo.iCX, m_tInfo.iCY, // �󸶸�ŭ ��� �� ������ 
		hMemDC,// ������ ��� 
		m_tInfo.iCX * m_tFrame.iFrameStart, m_tInfo.iCY * m_tFrame.iFrameScene,// �׸������� ���� �»�� ��ǥ 
		m_tInfo.iCX, m_tInfo.iCY,// �׸����� �󸶸�ŭ ����� ������ . 
		RGB(255, 0, 255));
	//�ҽ�������
	if (m_TCheck == true)
	{
		HDC hMemDC4 = CBitmapMgr::Get_Instance()->Get_MemDC(L"NillSnaJin");
		if (nullptr == hMemDC4)
			return;


		GdiTransparentBlt(hDC,
			500, 200,
			60, 153,
			hMemDC4,
			60 * m_iDrawID3, 0,
			60, 153,
			RGB(255, 0, 255));
	}


	//f�ѹ��������� �������
	if (m_fCheck == true)
	{
		HDC hMemDC2 = CBitmapMgr::Get_Instance()->Get_MemDC(L"FBuster");
		if (nullptr == hMemDC2)
			return;


		GdiTransparentBlt(hDC,
			0, 370,
			71, 37,
			hMemDC2,
			71 * m_iDrawID, 0,
			71, 37,
			RGB(255, 0, 255));
	}


	if (m_GCheck == true)
	{
		HDC hMemDC3 = CBitmapMgr::Get_Instance()->Get_MemDC(L"GFlasher");
		if (nullptr == hMemDC3)
			return;


		GdiTransparentBlt(hDC,
			70, 370,
			56, 34,
			hMemDC3,
			56 * m_iDrawID2, 0,
			56, 34,
			RGB(255, 0, 255));
	}

	//H�ѹ��������� �������
	if (m_fCheck == true)
	{
		HDC hMemDC4 = CBitmapMgr::Get_Instance()->Get_MemDC(L"HFleezer");
		if (nullptr == hMemDC4)
			return;


		GdiTransparentBlt(hDC,
			127, 370, //��������ġ
			56, 31,//ũ��
			hMemDC4,
			56 * m_iDrawID4, 0,
			56, 31,
			RGB(255, 0, 255));
	}
	

}




void CPlayer::Release()
{
}

void CPlayer::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{
		case CPlayer::STATE_IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 50;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CPlayer::STATE_JUMP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iFrameScene = 1;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CPlayer::STATE_WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iFrameScene = 2;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		
		case CPlayer::STATE_ATT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iFrameScene = 3;
			m_tFrame.dwFrameSpeed = 100;   //  ��Ÿ��/�������� �ؾ� ��
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CPlayer::STATE_A:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iFrameScene = 4;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CPlayer::STATE_R:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iFrameScene = 5;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CPlayer::STATE_PAIN:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iFrameScene = 6;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		
		case CPlayer::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}


