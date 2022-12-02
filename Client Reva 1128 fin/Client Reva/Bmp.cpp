#include "stdafx.h"
#include "Bmp.h"


CBmp::CBmp()
{
}


CBmp::~CBmp()
{
	Release();
}
void CBmp::Insert_Bitmap(const TCHAR * pFilePath)
{
	// 내가 도화지를 만들기 위해서는 현재 그려지고 있는 도화지의 정보를 알아야함. 그래서 얻어옴. 
	HDC hDC = GetDC(g_hWND);

	// 도화지를 만드는데 내가 넣어준 인자와 호환이되는 도화지를 만들겠다. 
	// -CreateCompatibleDC(hDC) - 내가 넣어준 인자와 호환이 되는 DC를 만들어주는 함수. 
	m_hMemDC = CreateCompatibleDC(hDC);

	// DC는 시스템 자원이므로 얻어왔고 다썼으면 반드시 지워줘야한다. 
	ReleaseDC(g_hWND, hDC);

	// LoadImage는 그림을 그린단계가 아니라 도구를 얻어오는 단계 . 
	/*LoadImage(1.프로그램 인스턴스 핸들 - 만약 프로그램을 대상으로 얻어올 것이라면 넣어주는게 맞지만 우리는 파일을 대상으로 그림을 얻어올것.
	2. 파일의 경로
	3. 이미지인지 혹은 커서 혹은 아이콘 등등 인지 어떤것을 읽을것인지에 대한 정보.
	4. 5. 그림의 사이즈 xy 두개를 받는다.
	6. 읽어오는 형식 - 현재 넣어준 인자는 LR_LOADFROMFILE - 파일로부터 읽어오겠다 | LR_CREATEDIBSECTION - 비트맵 출력 방식을 DIB형식으로 사용하게따
	) 성공시 GDI 오브젝트를 반환. 실패시 null을 반환.
	*/
	m_hBitmap = (HBITMAP)LoadImage(nullptr, pFilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// 이 구문이 이제 그림을 그렸다 라고 표현할 수 있겠다. 
	//SelectObject( DC에 오브젝트를 등록하는 함수 ( 1. 어떤 DC인지, 2. 어떤 GDI오브젝트인지.  
	// 이 함수가 반환하는 값은 원래 등록되어 있던 GDI오브젝트를 반환 해준다. 
	// GDI오브젝트는 단 하나만 선택될수 있다. 
	m_hOldBitmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void CBmp::Release()
{

	SelectObject(m_hMemDC, m_hOldBitmp);
	DeleteObject(m_hBitmap);
	// DC를 지울때 사용하는 함수 
	//삭제하고자 하는 DC를 넘겨주면 됨.
	//단 주의 할 것은 현재 DC에 선택된 GDIOBJECT는 지울수 없다. 
	//이유는 현재 사용되고 있는 객체를 함부로 삭제하도록 내버려 둘수 없기 때문에 생긴 일종의 안정 장치역할을 하는 규정때문에. 
	// 그리하여 원래 있던 GDIOBJECT를 넣어주고 등록 해제한 다음 우리가 만든 OBJECT를 지워줘야 한다. 

	DeleteDC(m_hMemDC);
}
