#pragma once

class CObj;
class CObjMgr
{
private:
	CObjMgr() {}
	CObjMgr(CObjMgr& _rVal) {}
	void operator= (CObjMgr& _rVal) {}
	~CObjMgr() {}


public:
	inline static CObjMgr* Get_Instance() {
		if (m_pInstance == nullptr)
			m_pInstance = new CObjMgr;

		return m_pInstance;
	}
	inline static void	Destroy_Instance() {
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
public:
	void Add_Object(OBJ::ID eID, CObj* pObj);
	void Delete_Object(OBJ::ID eID);
	inline void		Push_Element(CObj* pObj, OBJ::ID eId) { m_lstObject[eId].emplace_back(pObj); }
	

	void			Initialize();
	void			Update();
	void			LateUpdate();
	void			Render(HDC hDC);
	void			Release();
	inline CObj*			Get_Player() 
	{
		if (m_lstObject[OBJ::PLAYER].empty())
			return nullptr;
		return m_lstObject[OBJ::PLAYER].front();
	}
	inline CObj*			Get_Flame()
	{
		if (m_lstObject[OBJ::FLAMESHOT].empty())
			return nullptr;
		return m_lstObject[OBJ::FLAMESHOT].front();
	}
	inline CObj*			Get_Hyper()
	{
		if (m_lstObject[OBJ::HYPERSKILL].empty())
			return nullptr;
		return m_lstObject[OBJ::HYPERSKILL].front();
	}

public:
	bool Get_DeathCheck() { return m_bDeathCheck; }
	void Set_DeathCheck(bool _deathcheck) { m_bDeathCheck= _deathcheck; }
public:
	void	MakeMap();
	void	MakeMap2();
	void	MakeMap3();
	void	MakeMap4();
private:
	static CObjMgr*	m_pInstance;
	list<CObj*>		m_lstObject[OBJ::END];
	bool m_bDeathCheck;

	HDC m_hDC;
	
};

