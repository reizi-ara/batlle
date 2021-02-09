//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"


#include"ObjSceneMain.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjSceneMain::CObjSceneMain()
{

}

//イニシャライズ
void CObjSceneMain::Init()
{
	victory_flag = 0;
	con1_num = 0;
	con2_num = 0;
	
	Battle_flag = false;

	m_time = 0;
}

//アクション
void CObjSceneMain::Action()
{
		con1_num = Input::UpdateXControlerConnected();
		con2_num = Input::UpdateXControlerConnected() - 1;
		
		if (m_time < 240)
			m_time++;

		if (m_time >= 240)
		{
			Battle_flag = true;
		}
	if (victory_flag != 0)
	{
		if (Input::GetConButtons(con1_num, GAMEPAD_B) == true || Input::GetConButtons(con2_num, GAMEPAD_B) == true)
		{
			Scene::SetScene(new SceneSelect());
		}
	}

	if (Input::GetVKey('V') == true)
	{
		Scene::SetScene(new SceneSelect());
	}
}

//ドロー
void CObjSceneMain::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float bk_c[4] = { 0.0f,0.0f,0.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	RECT_F src2;
	RECT_F dst2;
	RECT_F src3;
	RECT_F dst3;

	RECT_F src4;
	RECT_F dst4;
	RECT_F src5;
	RECT_F dst5;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	

	Draw::Draw(3, &src, &dst, c, 0.0f);

	//ゲージ
	src2.m_top = 0.0f;
	src2.m_left = 0.0f;
	src2.m_right = 128.0f;
	src2.m_bottom = 128.0f;


	dst2.m_top = 560.0f;
	dst2.m_left = 60.0f;
	dst2.m_right = dst2.m_left +128;
	dst2.m_bottom = dst2.m_top + 128.0f;

	Draw::Draw(4, &src2, &dst2, c, 0.0f);

	//ゲージ
	src3.m_top = 0.0f;
	src3.m_left = 0.0f;
	src3.m_right = 128.0f;
	src3.m_bottom = 128.0f;


	dst3.m_top = 560.0f;
	dst3.m_left =680.0f;
	dst3.m_right = dst3.m_left+128.0f;
	dst3.m_bottom = dst3.m_top + 128.0f;

	Draw::Draw(4, &src3, &dst3, c, 0.0f);

	//ゲージ
	src4.m_top = 0.0f;
	src4.m_left = 0.0f;
	src4.m_right = 128.0f;
	src4.m_bottom = 128.0f;


	dst4.m_top = 560.0f;
	dst4.m_left = 170.0f;
	dst4.m_right = dst4.m_left + 128;
	dst4.m_bottom = dst4.m_top + 128.0f;

	Draw::Draw(5, &src4, &dst4, c, 0.0f);

	//ゲージ
	src5.m_top = 0.0f;
	src5.m_left = 0.0f;
	src5.m_right = 128.0f;
	src5.m_bottom = 128.0f;


	dst5.m_top = 560.0f;
	dst5.m_left = 530.0f;
	dst5.m_right = dst5.m_left + 128.0f;
	dst5.m_bottom = dst5.m_top + 128.0f;

	Draw::Draw(5, &src5, &dst5, c, 0.0f);

	Font::StrDraw(L"Bust", 600, 580, 15, bk_c);
	Font::StrDraw(L"Bust", 170, 580, 15, bk_c);

	if (victory_flag == 1)
	{
		Font::StrDraw(L"WIN1P", 337.5f, 250, 50, c);
		Font::StrDraw(L"Press:B", 317.5f, 350, 50, c);
	}
		
	if (victory_flag == 2)
	{
		Font::StrDraw(L"WIN2P", 337.5f, 250, 50, c);
		Font::StrDraw(L"Press:B", 317.5f, 350, 50, c);
	}

	if (m_time > 0 && m_time < 60)
	{
		Font::StrDraw(L"3", 375, 250, 100, c);
	}
	if (m_time > 60 && m_time < 120)
	{
		Font::StrDraw(L"2", 375, 250, 100, c);
	}
	if (m_time > 120 && m_time < 180)
	{
		Font::StrDraw(L"1", 375, 250, 100, c);
	}
	if (m_time > 180 && m_time < 240)
	{
		Font::StrDraw(L"GO!!", 300, 250, 100, c);
	}
		
}

