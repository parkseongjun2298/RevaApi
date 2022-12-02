#pragma once
class CBmp;
class CBitmapMgr
{

public:
	static CBitmapMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CBitmapMgr;
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
	CBitmapMgr();
	~CBitmapMgr();
	void operator=(CBitmapMgr& rObj) {}
	CBitmapMgr(CBitmapMgr& rObj) {}

public:
	HDC Get_MemDC(const TCHAR* pKey);
	void Insert_Image(const TCHAR* pPath, const TCHAR* pKey);
	void Release();

private:
	static CBitmapMgr* m_pInstance;
	map<const TCHAR*, CBmp*> m_mapBmp;

};

