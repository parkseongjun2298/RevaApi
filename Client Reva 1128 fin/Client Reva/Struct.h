#pragma once
typedef struct tagInfo {
	float	fX;
	float	fY;
	int		iCX;
	int		iCY;
	float   fSpeed;
}INFO;
typedef struct tagFrame
{
	int iFrameStart; // ������. 
	int iFrameEnd;  // ���� 
	int iFrameScene; // y��. y ���� ���Կ� ���� �÷��̾� Ȥ�� ������ ���°� ��ȯ.
	DWORD dwFrameSpeed; // �󸶸�ŭ ������ ������ ������ 
	DWORD dwFrameTime; // �����̴� �ð���. 
}FRAME;