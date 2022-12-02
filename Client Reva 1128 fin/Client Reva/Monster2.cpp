#include "stdafx.h"
#include "Monster2.h"
#include "ObjMgr.h"
#include"MonAtt.h"
#include"MonSkill.h"
CMonster2::CMonster2()
{
}


CMonster2::~CMonster2()
{
	Release();
}

void CMonster2::Initiailize()
{
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/대장고블린왼쪽.bmp", L"KMonster_Left");
	CBitmapMgr::Get_Instance()->Insert_Image(L"../Image/대장고블린오른쪽.bmp", L"KMonster_Right");
	m_pPlayer = CObjMgr::Get_Instance()->Get_Player();

	m_fSpeed = 1.5f;
	m_tInfo.iCX = 164;
	m_tInfo.iCY = 181;
	m_tInfo.fSpeed = 1.5f;
	m_iMaxHp = 800;
	m_iHp = m_iMaxHp;
	m_iAtt = 30;
	m_Accer = 40.f;

	m_pFrameKey = L"KMonster_Left";
	m_eCurState = STATE_IDLE;
	m_eNextState = STATE_IDLE;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 15;
	m_tFrame.iFrameScene = 2;
	m_tFrame.dwFrameSpeed = 100;
	m_tFrame.dwFrameTime = GetTickCount();


	m_DeBuffFM = false;
	m_FleezeTime = 0;
}

void CMonster2::Render(HDC hDC)
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
	Rectangle(hDC, m_tInfo.fX - 40, m_tInfo.fY + 80, m_tInfo.fX - 40 + m_iHp/4, m_tInfo.fY + 90);
	SelectObject(hDC, oldbrush);
	DeleteObject(brush);


	
}

int CMonster2::Update()
{
	CMonster::Update();


	if (m_bDead)
		return OBJ_DEAD;


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
		m_pFrameKey = L"KMonster_Left";
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
			
			m_pFrameKey = L"KMonster_Left";
			m_eNextState = STATE_MOVE;
		}

		if (Get_State() == MONSTER::RIGHT)
		{
			m_pFrameKey = L"KMonster_Right";
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



	if (m_pTarget->Get_Info()->fX < m_tInfo.fX)//몬스터가 플레이어 오른쪽
		m_Monstate = MONSTER::LEFT;
	if (m_pTarget->Get_Info()->fX > m_tInfo.fX)//몬스터가 플레이어 왼쪽
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
				m_pFrameKey = L"KMonster_Right";
				m_eNextState = STATE_ATT;

			}

			if (Get_State() == MONSTER::LEFT&&Get_State2() == MONSTER2::ATT)
			{

				pObj->Set_Pos(m_tInfo.fX - 20, m_tInfo.fY);



				m_pFrameKey = L"KMonster_Left";
				m_eNextState = STATE_ATT;

			}
			CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::ATTMON);

		}
	}


	if (fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) < 400|| fabs(m_pTarget->Get_Info()->fX - m_tInfo.fX) >= 200)
	{

		m_Monstate2 = MONSTER2::SKILL;
		dwTime = GetTickCount();
		if (m_dwOldTime3 + 4000 < GetTickCount())
		{
			m_dwOldTime3 = GetTickCount();
			
			CObj* pObj = new CMonSkill;
			pObj->Initiailize();
			dynamic_cast<CMonSkill*>(pObj)->Set_Monster(this);

			if (Get_State() == MONSTER::RIGHT&&Get_State2() == MONSTER2::SKILL)
			{

				pObj->Set_Pos(m_tInfo.fX+100, m_tInfo.fY);
				m_pFrameKey = L"KMonster_Right";
				m_eNextState = STATE_SKILL;

			}

			if (Get_State() == MONSTER::LEFT&&Get_State2() == MONSTER2::SKILL)
			{

				pObj->Set_Pos(m_tInfo.fX - 100, m_tInfo.fY);
				m_pFrameKey = L"KMonster_Left";
				m_eNextState = STATE_SKILL;
			}
			CObjMgr::Get_Instance()->Push_Element(pObj, OBJ::MONSKILL);

		}
	}




	return 0;
}

void CMonster2::LateUpdate()
{
	FrameChange();
	CObj::FrameMove();
}

void CMonster2::FrameChange()
{
	if (m_eCurState != m_eNextState)
	{
		switch (m_eNextState)
		{
		
		case CMonster2::STATE_MOVE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 10;
			m_tFrame.iFrameScene = 0;
			m_tFrame.dwFrameSpeed = 20;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CMonster2::STATE_ATT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 10;
			m_tFrame.iFrameScene = 1;
			m_tFrame.dwFrameSpeed = 200;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
		case CMonster2::STATE_SKILL:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 15;
			m_tFrame.iFrameScene = 2;
			m_tFrame.dwFrameSpeed = 200;
			m_tFrame.dwFrameTime = GetTickCount();
			break;
			
		
		case CMonster2::STATE_END:
			break;
		default:
			break;
		}
		m_eCurState = m_eNextState;
	}
}
