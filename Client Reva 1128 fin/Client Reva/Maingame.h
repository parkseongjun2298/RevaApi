#pragma once
class CMaingame
{
public:
	CMaingame();
	~CMaingame();
public:
	void	Initiailize();
	void	Update();
	void	LateUpdate();
	void	Render();
	void	Release();
private:
	HDC m_hDC;
	
	
};

