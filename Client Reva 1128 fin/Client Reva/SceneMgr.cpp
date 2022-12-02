#include "stdafx.h"
#include "SceneMgr.h"
#include"Logo.h"
#include"MyMenu.h"
#include"Stage.h"
#include"Stage2.h"
#include"Stage3.h"
#include"SelectDun.h"
#include"Story1.h"
#include"Story2.h"
#include"Story3.h"
#include"Story4.h"
#include"Story5.h"
#include"Story6.h"
#include"Strory7.h"
#include"Story8.h"
#include"Clear.h"
#include"Stage4.h"
#include"Back.h"
#include"Ending.h"
#include"Inven.h"
#include"InsertRing.h"
#include"GetRing.h"
CSceneMgr* CSceneMgr::m_pInstance = nullptr;
CSceneMgr::CSceneMgr()
	:m_eNextScene(SCENE_END)
	, m_eCurScene(SCENE_END)
	, m_pScene(nullptr)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}


void CSceneMgr::Update()
{
	m_pScene->Update();
}

void CSceneMgr::LateUpdate()
{
	m_pScene->LateUpdate();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	if (m_pScene)
	{
		delete m_pScene;
		m_pScene = nullptr;
	}
}

void CSceneMgr::SceneChange(SCENEID eNextScene)
{
	m_eNextScene = eNextScene;
	if (m_eCurScene != m_eNextScene)
	{
		// 여기 들어왔다는 말은 무슨말? 씬을 교체해야 된다라는 뜻. 
		// 현재 씬을 지워주자! 
		Safe_Delete(m_pScene);
		// 들어오는 씬으로 씬을 교체!
		switch (m_eNextScene)
		{
		case CSceneMgr::SCENE_LOGO:
			m_pScene = new CLogo;
			break;
		case CSceneMgr::SCENE_MENU:
			m_pScene = new CMyMenu;
			break;
		case CSceneMgr::SCENE_SELECTDUN:
			m_pScene = new CSelectDun;
			break;
		case CSceneMgr::SCENE_STORY1:
			m_pScene = new CStory1;
			break;
		case CSceneMgr::SCENE_STORY2:
			m_pScene = new CStory2;
			break;
		case CSceneMgr::SCENE_STORY3:
			m_pScene = new CStory3;
			break;
		case CSceneMgr::SCENE_STORY4:
			m_pScene = new CStory4;
			break;
		case CSceneMgr::SCENE_STORY5:
			m_pScene = new CStory5;
			break;
		case CSceneMgr::SCENE_STORY6:
			m_pScene = new CStory6;
			break;
		case CSceneMgr::SCENE_STAGE:
			m_pScene = new CStage;
			break;
		case CSceneMgr::SCENE_GETRINGSTORY:
			m_pScene = new CGetRing;
			break;
			
		case CSceneMgr::SCENE_STORY7:
			m_pScene = new CStrory7;
			break;
		case CSceneMgr::SCENE_STAGE2:
			m_pScene = new CStage2;
			break;
		case CSceneMgr::SCENE_STORY8:
			m_pScene = new CStory8;
			break;
		case CSceneMgr::SCENE_STAGE3:
			m_pScene = new CStage3;
			break;
		case CSceneMgr::SCENE_CLEAR1:
			m_pScene = new CClear;
			break;
		case CSceneMgr::SCENE_INVEN:
			m_pScene = new CInven;
			break;
		case CSceneMgr::SCENE_INSERTRING:
			m_pScene = new CInsertRing;
			break;
			
		case CSceneMgr::SCENE_STAGE4:
			m_pScene = new CStage4;
			break; 
		case CSceneMgr::SCENE_BACKGROUND:
			m_pScene = new CBack;
			break;
		case CSceneMgr::SCENE_BOSS:
			break;
		case CSceneMgr::SCENE_END:
			m_pScene = new CEnding;
			break;
		default:
			break;
		}
		// 씬을 만들었으니 초기화 함수를 불러주자! 데이터는 Initialize 함수에서 만들고 있으니깐!
		m_pScene->Initialize();

		//현재씬을 받아온 씬으로 바꿔주면? 다시 이벤트 발생하기 전까지는 더이상 이곳을 수행하지 않는다!
		m_eCurScene = m_eNextScene;
	}
}
