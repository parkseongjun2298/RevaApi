#pragma once
class CScene;
class CSceneMgr
{
public:
	enum SCENEID { SCENE_LOGO, SCENE_MENU,SCENE_SELECTDUN, SCENE_STORY1, SCENE_STORY2, SCENE_STORY3, SCENE_STORY4, SCENE_STORY5,
		SCENE_STORY6,SCENE_STAGE, SCENE_GETRINGSTORY, SCENE_STORY7,SCENE_STAGE2,SCENE_STORY8,SCENE_STAGE3,SCENE_CLEAR1,SCENE_INVEN, SCENE_INSERTRING, SCENE_STAGE4, SCENE_BACKGROUND,SCENE_BOSS, SCENE_END };
public:
	static CSceneMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CSceneMgr;

		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;

		}
	}
private:
	CSceneMgr();
	~CSceneMgr();
public:
	void Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();
public:
	void SceneChange(SCENEID eNextScene);

private:
	static CSceneMgr* m_pInstance;
	CScene* m_pScene;
	SCENEID m_eCurScene; // 현재 씬이 무엇인지 표현할 변수 
	SCENEID m_eNextScene; // 다음 들어오는 씬의 정보를 가지고 있을 변수 
};

