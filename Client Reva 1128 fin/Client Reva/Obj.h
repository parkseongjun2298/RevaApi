#pragma once
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void		Initiailize()	PURE;
	virtual int			Update()		PURE;
	virtual void		LateUpdate()	PURE;
	virtual void		Render(HDC hDC)		PURE;
	virtual void		Release()		PURE;
public:
	void				UpdateRect();
	inline void			Set_Dead() { m_bDead = true; }
	inline INFO*		Get_Info() { return &m_tInfo; }
	inline RECT*		Get_Rect() { return &m_tRect; }
	inline void			Set_Pos(float fX, float fY) { m_tInfo.fX = fX; m_tInfo.fY = fY; }
	inline int			Get_Att() { return m_iAtt; }
	inline int			Get_Hp() { return m_iHp; }
	inline void			Set_Hp(int _hp) { m_iHp=_hp; }
	inline int			Get_Mp() { return m_iMp; }
	inline void			Set_Mp(int _Mp) { m_iMp = _Mp; }
	inline float			Get_Accer() { return m_Accer; }
	inline void			Set_Accer(float _Accer) { m_Accer= _Accer; }
	
	void FrameMove();

	int			m_iDrawID3;
protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	FRAME		m_tFrame;
	CObj*		m_pPlayer;
	bool		m_bDead;
	int			m_iMaxHp;
	int			m_iHp;
	int			m_iAtt;
	int			m_iMaxMp;
	int			m_iMp;
	float		m_Accer;
	int			m_iDrawID;
	int			m_iDrawID2;
	
	int			m_iDrawID4;
	float m_PlayerSpeed;
};

