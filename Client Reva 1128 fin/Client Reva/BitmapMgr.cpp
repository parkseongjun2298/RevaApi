#include "stdafx.h"
#include "BitmapMgr.h"
#include"Bmp.h"


CBitmapMgr* CBitmapMgr::m_pInstance = nullptr;
CBitmapMgr::CBitmapMgr()
{
}


CBitmapMgr::~CBitmapMgr()
{
	Release();
}

HDC CBitmapMgr::Get_MemDC(const TCHAR * pKey)
{
	if (m_mapBmp.empty())
		return nullptr;

	auto& iter = find_if(m_mapBmp.begin(), m_mapBmp.end(), [&](auto& rPair)
	{
		return !lstrcmp(rPair.first, pKey);
	});

	if (iter == m_mapBmp.end())
		return nullptr;

	return iter->second->Get_MemDC();
}

void CBitmapMgr::Insert_Image(const TCHAR * pPath, const TCHAR * pKey)
{
	auto& iter = find_if(m_mapBmp.begin(), m_mapBmp.end(), [&](auto& rPair)
	{
		return !lstrcmp(rPair.first, pKey);
	});

	if (m_mapBmp.end() == iter)
	{
		// ?? 
		CBmp* pBmp = new CBmp;
		pBmp->Insert_Bitmap(pPath);
		m_mapBmp.insert({ pKey, pBmp });
		// 		m_mapBmp.insert(make_pair(pKey, pBmp));
		// 		m_mapBmp.insert(map<const TCHAR*, CBmp*>::value_type(pKey, pBmp));
		// 		m_mapBmp.emplace( pKey, pBmp);
	}
}

void CBitmapMgr::Release()
{
	for (auto& rPair : m_mapBmp)
	{
		if (rPair.second)
		{
			delete rPair.second;
			rPair.second = nullptr;
		}
	}
	m_mapBmp.clear();
}
