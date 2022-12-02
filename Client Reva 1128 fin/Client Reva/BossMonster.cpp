#include "stdafx.h"
#include "BossMonster.h"
#include "ObjMgr.h"
#include"MonAtt.h"
#include"RanShot.h"
#include"LightAir.h"
#include"Boom.h"
CBossMonster::CBossMonster()
{
}


CBossMonster::~CBossMonster()
{
	Release();
}

void CBossMonster::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/Zighart_L.bmp", L"Zighart_L");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/Zighart_R.bmp", L"Zighart_R");
	m_pPlayer = CObjMgr::Get_Instance()->Get_Player();

	m_tInfo.fSpeed = 1.f;
	m_fSpeed = 1.f;
	m_tInfo.iCX = 300;
	m_tInfo.iCY = 300;
	m_iMaxHp = 2000;
	m_iHp = m_iMaxHp;
	m_iAtt = 1;
	m_Accer = 40.f;

	m_pFrameKey = L"Zighart_L";
	m_eCurState = STATE_IDLE;
	m_eNextState = STATE_IDLE;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 14;
	m_tFrame.iFrameScene = 5;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();


	m_bPain = false;
	m_bDie = false;

	m_DeBuffFM = false;
	m_FleezeTime = 0;
}

void CBossMonster::Render(HDC hDC)
{
	CObj::UpdateRect();
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	HDC hMemDC = CBitmapMgr::Get_Instance()->Get_MemDC(m_pFrameKey);
	//BitBlt(hDC, m_tRect.left , m_tRect.top, m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0, SRCCOPY);
	GdiTransparentBlt(hDC,//복사받을 대상 
		m_tRect.left, m_tRect.top,// 출력할 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY, // 얼마만큼 출력 할 것인지 
		hMemDC,// 복사할 대상 
		m_tInfo.iCX * m_tFrame.iFrameStart, m_tInfo.iCY * m_tFrame.iFrameScene,// 그림에서의 시작 좌상단 좌표 
		m_tInfo.iCX, m_tInfo.iCY,// 그림에서 얼마만큼 출력할 것인지 . 
		RGB(255, 0, 255));

	HBRUSH brush, oldbrush;
	//Hp바
	brush = CreateSolidBrush(RGB(0, 0, 255));
	oldbrush = (HBRUSH)SelectObject(hDC, brush);
	Rectangle(hDC, m_tInfo.fX - 100, m_tInfo.fY + 80, m_tInfo.fX - 100 + m_iHp/10, m_tInfo.fY + 90);
	SelectObject(hDC, oldbrush);
	DeleteObject(brush);
}

int CBossMonster::Update()
{
	CMonster::Update();
	if (m_bDead)
	{
		if (m_bDie == true)
		{

			Get_State2() == MONSTER2::DIE;
			if (Get_State() == MONSTER::RIGHT)
			{
				m_pFrameKey = L"Zighart_R";
				m_eNextState = STATE_DIE;
			}
			if (Get_State() == MONSTER::LEFT)
			{
				m_pFrameKey = L"Zighart_L";
				m_eNextState = STATE_DIE;
			}

			m_bDie = false;
		}

		return OBJ_DEAD;
	}


	if (m_Monstate2 == MONSTER2::ATT)
	{
		if (dwTime + 1000 < GetTickCount())
		{
			m_Monstate2 = MONSTER2::IDLE;
			dwTime = GetTickCount();
		}
	}


	if (m_Monstate2 == MONSTER2::PAIN)
	{
		if (dwTime + 1000 < GetTickCount())
		{
			m_Monstate2 = MONSTER2::IDLE;
			dwTime = GetTickCount();
		}
	}
	if (m_Monstate2 == MONSTER2::DIE)
	{
		if (dwTime + 1000 < GetTickCount())
		{
			m_Monstate2 = MONSTER2::IDLE;
			dwTime = GetTickCount();
		}
	}

	if (m_fSpeed == 0)
	{
		m_Monstate = MONSTER::IDLE;
		m_pFrameKey = L"Zighart_L";
		m_eNextState = STATE_IDLE;
	}

	if (m_tInfo.fX <= 49)
	{
		m_tInfo.fX = 50;
	}
	if (m_tInfo.fX >= WINCX)
	{
		m_tInfo.fX = WINCX - 20;
	}

	if (m_Monstate2 != MONSTER2::ATT)
	{
		if (Get_State() == MONSTER::LEFT)
		{
			m_pFrameKey = L"Zighart_L";
			m_eNextState = STATE_MOVE;
		}

		if (Get_State() == MONSTER::RIGHT)
		{
			m_pFrameKey = L"Zighart_R";
			m_eNextState = STATE_MOVE;
		}

		if (fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) >= 350) //300 내에 있으면 쫓아가게
		{
			m_fSpeed = 0.f;
		}
		else
		{

			m_fSpeed = 1.5f; // 몬스터속도가 여기서 결정됨;;
		}


		if (m_DeBuffFM == true)
		{
			m_fSpeed = 0.2f;
			m_DeBuffFM = false;
		}



		if (m_DeBuffFleeze == true)
		{

			m_fSpeed = 0.f;

			++m_FleezeTime;
			if (m_FleezeTime > 65)
			{
				m_FleezeTime = 0;
				m_DeBuffFleeze = false;
			}

		}
		float fx = m_pTarget->Get_Info()->fX - m_tInfo.fX;
		float fy = m_pTarget->Get_Info()->fY - m_tInfo.fY;
		float fDist = sqrtf(fx * fx + fy * fy);


		m_fAngle = acosf(fx / fDist);
		if (m_pTarget->Get_Info()->fY > m_tInfo.fY)

			m_fAngle *= -1.f;

		m_tInfo.fX += cosf(m_fAngle) * m_fSpeed;
	}




	if (m_pTarget->Get_Info()->fX  < m_tInfo.fX)//몬스터가 왼쪽으로움직
		m_Monstate = MONSTER::LEFT;
	if (m_pTarget->Get_Info()->fX  > m_tInfo.fX)//몬스터가 오른쪽으로 움직
		m_Monstate = MONSTER::RIGHT;



	if (fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) <= 50)
	{

		m_Monstate2 = MONSTER2::ATT;
		dwTime = GetTickCount();

		if (m_dwOldTime2 + 2000 < GetTickCount())
		{
			m_dwOldTime2 = GetTickCount();

			CObj* pObj = new CMonAtt;
			pObj->Initiailize();
			dynamic_cast<CMonAtt*>(pObj)->Set_Monster(this);

			if (Get_State() == MONSTER::RIGHT&&Get_State2() == MONSTER2::ATT)
			{

				pObj->Set_Pos(m_tInfo.fX + 20, m_tInfo.fY);

				m_pFrameKey = L"Zighart_R";
				m_eNextState = STATE_ATT;

			}

			if (Get_State() == MONSTER::LEFT&&Get_State2() == MONSTER2::ATT)
			{

				pObj->Set_Pos(m_tInfo.fX - 20, m_tInfo.fY);



				m_pFrameKey = L"Zighart_L";
				m_eNextState = STATE_ATT;

			}
			CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::ATTMON);

		}
	}

	//스킬1
	if (fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) <= 200&& fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX)>=100)
	{

		m_Monstate2 = MONSTER2::RANSHOT;
		dwTime = GetTickCount();

		if (m_dwOldTime2 + 3000 < GetTickCount())
		{
			m_dwOldTime2 = GetTickCount();

			CObj* pObj = new CRanShot;
			pObj->Initiailize();
			dynamic_cast<CRanShot*>(pObj)->Set_Monster(this);
		

			if (Get_State() == MONSTER::RIGHT&&Get_State2() == MONSTER2::RANSHOT)
			{

				pObj->Set_Pos(m_tInfo.fX + 100, m_tInfo.fY);

				m_pFrameKey = L"Zighart_R";
				m_eNextState = STATE_SKILL;


			

			}

			if (Get_State() == MONSTER::LEFT&&Get_State2() == MONSTER2::RANSHOT)
			{

				pObj->Set_Pos(m_tInfo.fX - 100, m_tInfo.fY);



				m_pFrameKey = L"Zighart_L";
				m_eNextState = STATE_SKILL;
			}
			CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::RANSHOT);
			
		}
	}

	//스킬2
	if (fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) <= 300&& fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) >= 201)
	{

		m_Monstate2 = MONSTER2::LIGHT;
		dwTime = GetTickCount();

		if (m_dwOldTime3 + 4000 < GetTickCount())
		{
			m_dwOldTime3 = GetTickCount();

			CObj* pObj = new CLightAir;
			pObj->Initiailize();
			dynamic_cast<CLightAir*>(pObj)->Set_Monster(this);


			if (Get_State() == MONSTER::RIGHT&&Get_State2() == MONSTER2::LIGHT)
			{

				pObj->Set_Pos(m_tInfo.fX + 150, m_tInfo.fY);

				m_pFrameKey = L"Zighart_R";
				m_eNextState = STATE_SKILL;




			}

			if (Get_State() == MONSTER::LEFT&&Get_State2() == MONSTER2::LIGHT)
			{

				pObj->Set_Pos(m_tInfo.fX - 150, m_tInfo.fY);



				m_pFrameKey = L"Zighart_L";
				m_eNextState = STATE_SKILL;
			}
			CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::LIGHTAIR);

		}
	}

	//스킬3
	if (fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) <= 500 && fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) >= 301)
	{

		m_Monstate2 = MONSTER2::BOOM;
		dwTime = GetTickCount();

		if (m_dwOldTime3 + 6000 < GetTickCount())
		{
			m_dwOldTime3 = GetTickCount();

			CObj* pObj = new CBoom;
			pObj->Initiailize();
			dynamic_cast<CBoom*>(pObj)->Set_Monster(this);


			if (Get_State() == MONSTER::RIGHT&&Get_State2() == MONSTER2::BOOM)
			{

				pObj->Set_Pos(m_tInfo.fX + 300, m_tInfo.fY);

				m_pFrameKey = L"Zighart_R";
				m_eNextState = STATE_SKILL;




			}

			if (Get_State() == MONSTER::LEFT&&Get_State2() == MONSTER2::BOOM)
			{

				pObj->Set_Pos(m_tInfo.fX - 300, m_tInfo.fY);



				m_pFrameKey = L"Zighart_L";
				m_eNextState = STATE_SKILL;
			}
			CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::BOOM);

		}
	}



	if (m_bPain == true)
	{

		Get_State2() == MONSTER2::PAIN;
		if (Get_State() == MONSTER::RIGHT)
		{
			m_pFrameKey = L"Zighart_R";
			m_eNextState = STATE_PAIN;
		}
		if (Get_State() == MONSTER::LEFT)
		{
			m_pFrameKey = L"Zighart_L";
			m_eNextState = STATE_PAIN;
		}

		m_bPain = false;
	}






	return 0;
}

void CBossMonster::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CBossMonster::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{
		case CBossMonster::STATE_IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 50;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CBossMonster::STATE_ATT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 10;
			m_tFrame.iFrameScene = 1;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;

		case CBossMonster::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iFrameScene = 2;
			m_tFrame.dwFrameSpeed = 50;   //  쿨타임/사진개수 해야 딱
			m_tFrame.dwFrameTime = GetTickCount();
			break;
	
		case CBossMonster::STATE_MOVE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 7;
			m_tFrame.iFrameScene = 3;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CBossMonster::STATE_PAIN:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iFrameScene = 4;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CBossMonster::STATE_DIE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 14;
			m_tFrame.iFrameScene = 5;
			m_tFrame.dwFrameSpeed = 100;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CBossMonster::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
