#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tFrame, sizeof(FRAME));
}



CObj::~CObj()
{
}



void CObj::UpdateRect()
{

	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.iCX / 2);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.iCY / 2);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.iCX / 2);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.iCY / 2);
}

void CObj::FrameMove()
{
	if (m_tFrame.dwFrameTime + m_tFrame.dwFrameSpeed < GetTickCount())
	{
		++m_tFrame.iFrameStart;
		m_tFrame.dwFrameTime = GetTickCount();
	}
	if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		m_tFrame.iFrameStart = 0;
}
