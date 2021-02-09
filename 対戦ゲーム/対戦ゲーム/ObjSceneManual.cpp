//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"


#include"ObjSceneManual.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjSceneManual::CObjSceneManual(int con_1_num,int con_2_num)
{
	m_p1_num = con_1_num;
	m_p2_num = con_2_num;
}

//イニシャライズ
void CObjSceneManual::Init()
{
	con1_num = 0;
	con2_num = 0;
	m_time = 0;
}

//アクション
void CObjSceneManual::Action()
{
	con1_num = Input::UpdateXControlerConnected();
	con2_num = Input::UpdateXControlerConnected() - 1;

	if (m_time < 300)
		m_time++;

	if (m_time >= 300)
	{
		if (Input::GetConButtons(con1_num, GAMEPAD_B) == true|| Input::GetConButtons(con2_num, GAMEPAD_B) == true)
		{
			Scene::SetScene(new SceneMain(m_p1_num, m_p2_num));
		}
	}
}

//ドロー
void CObjSceneManual::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float bk_c[4] = { 0.0f,0.0f,0.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 512.0f;


	dst.m_top = 100.0f;
	dst.m_left = 100.0f;
	dst.m_right = 700.0f;
	dst.m_bottom = 500.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	if (m_time >= 300)
	{
		Font::StrDraw(L"Press:B", 295, 500, 60, c);
	}
}

