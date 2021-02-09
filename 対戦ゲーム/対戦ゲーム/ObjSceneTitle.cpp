//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"


#include"ObjSceneTitle.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

/*CObjSceneTitle::CObjSceneTitle()
{

}*/

//イニシャライズ
void CObjSceneTitle::Init()
{
	m_p1_con_num = 0;
	m_p2_con_num = 0;
}

//アクション
void CObjSceneTitle::Action()
{
	m_p1_con_num = Input::UpdateXControlerConnected();
	m_p2_con_num = Input::UpdateXControlerConnected() - 1;

	if (Input::GetConButtons(m_p1_con_num, GAMEPAD_B) == true || Input::GetConButtons(m_p2_con_num, GAMEPAD_B) == true)
	{
		Scene::SetScene(new SceneSelect());
	}
	//エクストラキー（デバッグ用）
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new SceneSelect());
	}
}

//ドロー
void CObjSceneTitle::Draw()
{
	float w_c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b_c[4] = { 1.0f,0.0f,0.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 17.0f;
	src.m_right = 63.0f;
	src.m_bottom = 64.0f;
	
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(1, &src, &dst, w_c, 0.0f);

	Font::StrDraw(L"Cube", 300.0f, 100.0f, 100, b_c);
	Font::StrDraw(L"Battle", 250.0f, 200.0f, 100, b_c);
	Font::StrDraw(L"Press:B", 317.5f, 450.0f, 50, b_c);
}

