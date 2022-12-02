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
	int iFrameStart; // 시작점. 
	int iFrameEnd;  // 끝점 
	int iFrameScene; // y값. y 값이 변함에 따라 플레이어 혹은 몬스터의 상태가 변환.
	DWORD dwFrameSpeed; // 얼마만큼 빠르게 움지길 것인지 
	DWORD dwFrameTime; // 움직이는 시간값. 
}FRAME;