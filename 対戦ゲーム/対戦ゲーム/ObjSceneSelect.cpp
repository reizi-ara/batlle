//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"


#include"ObjSceneSelect.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjSceneSelect::Init()
{
	m_p1_px = 100.0f;
	m_p1_py = 300.0f;
	m_p1_vx = 0.0f;
	m_p1_vy = 0.0f;
	m_p2_px = 668.0f;
	m_p2_py = 300.0f;
	m_p2_vx = 0.0f;
	m_p2_vy = 0.0f;

	m_p1_con_num = 0;
	m_p2_con_num = 0;

	m_p1_con = 0;
	m_p2_con = 0;

	m_p1_battle_flag = false;
	m_p2_battle_flag = false;
}

//アクション
void CObjSceneSelect::Action()
{
	m_p1_con_num = Input::UpdateXControlerConnected() ;
	m_p2_con_num = Input::UpdateXControlerConnected() - 1;

	//左右移動処理
	m_p1_vx += Input::GetConVecStickLX(m_p1_con_num);
	m_p1_vy -= Input::GetConVecStickLY(m_p1_con_num);

	//移動速度制御
	if (m_p1_vx > 6.0f)
	{
		m_p1_vx = 6.0f;
	}
	if (m_p1_vx < -6.0f)
	{
		m_p1_vx = -6.0f;
	}
	//移動速度制御
	if (m_p1_vy > 6.0f)
	{
		m_p1_vy = 6.0f;
	}
	if (m_p1_vy < -6.0f)
	{
		m_p1_vy = -6.0f;
	}

	//左右移動処理
	m_p2_vx += Input::GetConVecStickLX(m_p2_con_num);
	m_p2_vy -= Input::GetConVecStickLY(m_p2_con_num);

	//移動速度制御
	if (m_p2_vx > 6.0f)
	{
		m_p2_vx = 6.0f;
	}
	if (m_p2_vx < -6.0f)
	{
		m_p2_vx = -6.0f;
	}
	//移動速度制御
	if (m_p2_vy > 6.0f)
	{
		m_p2_vy = 6.0f;
	}
	if (m_p2_vy < -6.0f)
	{
		m_p2_vy = -6.0f;
	}

	if (Input::GetConVecStickLX(m_p1_con_num) == 0.0f)
	{
		m_p1_vx = 0.0f;
	}
	if (Input::GetConVecStickLY(m_p1_con_num) == 0.0f)
	{
		m_p1_vy = 0.0f;
	}
	if (Input::GetConVecStickLX(m_p2_con_num) == 0.0f)
	{
		m_p2_vx = 0.0f;
	}
	if (Input::GetConVecStickLY(m_p2_con_num) == 0.0f)
	{
		m_p2_vy = 0.0f;
	}

	//位置の更新
	m_p1_px += m_p1_vx;
	m_p1_py += m_p1_vy;

	m_p2_px += m_p2_vx;
	m_p2_py += m_p2_vy;

	//領域外処理
	if (m_p1_py + 32.0f >= 600.0f)
	{
		m_p1_py = 568.0f;
	}
	if (m_p1_py < 0.0f)
	{
		m_p1_py = 0.0f;
	}
	if (m_p1_px < 0.0f)
	{
		m_p1_px = 0.0f;
	}
	if (m_p1_px + 32.0f > 800.0f)
	{
		m_p1_px = 768.0f;
	}

	//領域外処理
	if (m_p2_py + 32.0f >= 600.0f)
	{
		m_p2_py = 568.0f;
	}
	if (m_p2_py < 0.0f)
	{
		m_p2_py = 0.0f;
	}
	if (m_p2_px < 0.0f)
	{
		m_p2_px = 0.0f;
	}
	if (m_p2_px + 32.0f > 800.0f)
	{
		m_p2_px = 768.0f;
	}
	//砲撃タイプ
	if (m_p1_px + 16.0f >= 50 && m_p1_px + 16.0f <= 250)
	{
		if (m_p1_py + 16.0f >= 150 && m_p1_py + 16.0f <= 350)
		{
			if (Input::GetConButtons(m_p1_con_num, GAMEPAD_X) == true)
			{
				if (m_p2_con != 1)
					m_p1_con = 1;
			}
		}
	}
	if (m_p2_px + 16.0f >= 50 && m_p2_px + 16.0f <= 250)
	{
		if (m_p2_py + 16.0f >= 150 && m_p2_py + 16.0f <= 350)
		{
			if (Input::GetConButtons(m_p2_con_num, GAMEPAD_X) == true)
			{
				if (m_p1_con != 1)
					m_p2_con = 1;
			}
		}
	}
	//浮遊タイプ
	if (m_p1_px + 16.0f >= 300 && m_p1_px + 16.0f <= 500)
	{
		if (m_p1_py + 16.0f >= 150 && m_p1_py + 16.0f <= 350)
		{
			if (Input::GetConButtons(m_p1_con_num, GAMEPAD_X) == true)
			{
				if (m_p2_con != 2)
					m_p1_con = 2;
			}
		}
	}
	if (m_p2_px + 16.0f >= 300 && m_p2_px + 16.0f <= 500)
	{
		if (m_p2_py + 16.0f >= 150 && m_p2_py + 16.0f <= 350)
		{
			if (Input::GetConButtons(m_p2_con_num, GAMEPAD_X) == true)
			{
				if (m_p1_con != 2)
					m_p2_con = 2;
			}			
		}
	}
	//爆裂タイプ
	if (m_p1_px + 16.0f >= 550 && m_p1_px + 16.0f <= 750)
	{
		if (m_p1_py + 16.0f >= 150 && m_p1_py + 16.0f <= 350)
		{
			if (Input::GetConButtons(m_p1_con_num, GAMEPAD_X) == true)
			{
				if (m_p2_con != 3)
					m_p1_con = 3;
			}
		}
	}
	if (m_p2_px + 16.0f >= 550 && m_p2_px + 16.0f <= 750)
	{
		if (m_p2_py + 16.0f >= 150 && m_p2_py + 16.0f <= 350)
		{
			if (Input::GetConButtons(m_p2_con_num, GAMEPAD_X) == true)
			{
				if (m_p1_con != 3)
					m_p2_con = 3;
			}
		}
	}

	

	if (Input::GetConButtons(m_p1_con_num, GAMEPAD_Y) == true)
	{
		if (m_p1_con != 0)
			m_p1_battle_flag = true;
	}
	if (Input::GetConButtons(m_p2_con_num, GAMEPAD_Y) == true)
	{
		if (m_p2_con != 0)
			m_p2_battle_flag = true;
	}
	if (Input::GetConButtons(m_p1_con_num, GAMEPAD_A) == true)
	{
		m_p1_con = 0;
		m_p1_battle_flag = false;
	}
	if (Input::GetConButtons(m_p2_con_num, GAMEPAD_A) == true)
	{
		m_p2_con = 0;
		m_p2_battle_flag = false;
	}
	//準備完了
	if (m_p1_battle_flag == true && m_p2_battle_flag == true)
	{
		Scene::SetScene(new SceneManual(m_p1_con,m_p2_con));
	}
	
	//エクストラキー（デバッグ用）
	if (Input::GetVKey('V') == true)
	{
		if (m_p2_con != 1)
			m_p1_con = 1;
		if (m_p1_con != 2)
			m_p2_con = 2;
		m_p1_battle_flag = true;
		m_p2_battle_flag = true;
	}
	if (Input::GetVKey('B') == true)
	{
		if (m_p2_con != 2)
			m_p1_con = 2;
		if (m_p1_con != 3)
			m_p2_con = 3;
		m_p1_battle_flag = true;
		m_p2_battle_flag = true;
	}
	if (Input::GetVKey('N') == true)
	{
		if (m_p2_con != 3)
			m_p1_con = 3;
		if (m_p1_con != 1)
			m_p2_con = 1;
		m_p1_battle_flag = true;
		m_p2_battle_flag = true;
	}
}

//ドロー
void CObjSceneSelect::Draw()
{
	float w_c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r_c[4] = { 1.0f,0.0f,0.0f,1.0f };
	float b_c[4] = { 0.5f,0.5f,1.0f,1.0f };

	RECT_F src1;
	RECT_F dst1;
	RECT_F src2;
	RECT_F dst2;
	RECT_F src3;
	RECT_F dst3;
	RECT_F src4;
	RECT_F dst4;
	RECT_F src5;
	RECT_F dst5;
	RECT_F src6;
	RECT_F dst6;

	src1.m_top = 0.0f;
	src1.m_left = 0.0f;
	src1.m_right = 64.0f;
	src1.m_bottom = 64.0f;

	src2.m_top = 0.0f;
	src2.m_left = 0.0f;
	src2.m_right = 64.0f;
	src2.m_bottom = 64.0f;

	src3.m_top = 0.0f;
	src3.m_left = 0.0f;
	src3.m_right = 64.0f;
	src3.m_bottom = 64.0f;

	src4.m_top = 0.0f;
	src4.m_left = 0.0f;
	src4.m_right = 64.0f;
	src4.m_bottom = 64.0f;

	src5.m_top = 0.0f;
	src5.m_left = 0.0f;
	src5.m_right = 64.0f;
	src5.m_bottom = 64.0f;

	/*src6.m_top = 0.0f;
	src6.m_left = 0.0f;
	src6.m_right = 1024.0f;
	src6.m_bottom = 512.0f;


	dst6.m_top = 400.0f;
	dst6.m_left = 100.0f;
	dst6.m_right = 700.0f;
	dst6.m_bottom = 600.0f;

	Draw::Draw(8, &src6, &dst6, w_c, 0.0f);*/

	dst1.m_top = m_p1_py;
	dst1.m_left = m_p1_px;
	dst1.m_right = 32.0f + m_p1_px;
	dst1.m_bottom = 32.0f + m_p1_py;

	dst2.m_top = m_p2_py;
	dst2.m_left = m_p2_px;
	dst2.m_right = 32.0f + m_p2_px;
	dst2.m_bottom = 32.0f + m_p2_py;

	dst3.m_top = 150.0f;
	dst3.m_left = 50.0f;
	dst3.m_right = 250.0f;
	dst3.m_bottom = 350.0f;

	dst4.m_top = 150.0f;
	dst4.m_left = 300.0f;
	dst4.m_right = 500.0f;
	dst4.m_bottom = 350.0f;

	dst5.m_top = 150.0f;
	dst5.m_left = 550.0f;
	dst5.m_right = 750.0f;
	dst5.m_bottom = 350.0f;

	

	Draw::Draw(1, &src3, &dst3, w_c, 0.0f);
	Draw::Draw(1, &src4, &dst4, r_c, 0.0f);
	Draw::Draw(1, &src5, &dst5, b_c, 0.0f);

	Draw::Draw(5, &src1, &dst1, w_c, 0.0f);
	Draw::Draw(5, &src2, &dst2, r_c, 0.0f);


	wchar_t str1[256];
	if (m_p1_con == 1)
	{
		Font::StrDraw(L"1Pは砲撃タイプです", 40, 40, 20, w_c);
		if (m_p1_battle_flag == false)
		{
			Font::StrDraw(L"Press:Yで準備完了", 40, 60, 20, w_c);
			Font::StrDraw(L"Press:Aでキャンセル", 40, 80, 20, w_c);
		}
		if (m_p1_battle_flag == true)
		{
			Font::StrDraw(L"準備完了", 40, 60, 20, w_c);
		}
	}
	
	if (m_p2_con == 1)
	{
		Font::StrDraw(L"2Pは砲撃タイプです", 440, 40, 20, w_c);
		if (m_p2_battle_flag == false)
		{
			Font::StrDraw(L"Press:Yで準備完了", 440, 60, 20, w_c);
			Font::StrDraw(L"Press:Aでキャンセル", 440, 80, 20, w_c);
		}
		if (m_p2_battle_flag == true)
		{
			Font::StrDraw(L"準備完了", 440, 60, 20, w_c);
		}
	}
		
	if (m_p1_con == 2)
	{
		Font::StrDraw(L"1Pは浮遊タイプです", 40, 40, 20, r_c);
		if (m_p1_battle_flag == false)
		{
			Font::StrDraw(L"Press:Yで準備完了", 40, 60, 20, r_c);
			Font::StrDraw(L"Press:Aでキャンセル", 40, 80, 20, r_c);
		}
		if (m_p1_battle_flag == true)
		{
			Font::StrDraw(L"準備完了", 40, 60, 20, r_c);
		}
	}
		
	if (m_p2_con == 2)
	{
		Font::StrDraw(L"2Pは浮遊タイプです", 440, 40, 20, r_c);
		if (m_p2_battle_flag == false)
		{
			Font::StrDraw(L"Press:Yで準備完了", 440, 60, 20, r_c);
			Font::StrDraw(L"Press:Aでキャンセル", 440, 80, 20, r_c);
		}
		if (m_p2_battle_flag == true)
		{
			Font::StrDraw(L"準備完了", 440, 60, 20, r_c);
		}
	}
	if (m_p1_con == 3)
	{
		Font::StrDraw(L"1Pは爆裂タイプです", 40, 40, 20, b_c);
		if (m_p1_battle_flag == false)
		{
			Font::StrDraw(L"Press:Yで準備完了", 40, 60, 20, b_c);
			Font::StrDraw(L"Press:Aでキャンセル", 40, 80, 20, b_c);
		}
		if (m_p1_battle_flag == true)
		{
			Font::StrDraw(L"準備完了", 40, 60, 20, b_c);
		}
	}

	if (m_p2_con == 3)
	{
		Font::StrDraw(L"2Pは爆裂タイプです", 440, 40, 20, b_c);
		if (m_p2_battle_flag == false)
		{
			Font::StrDraw(L"Press:Yで準備完了", 440, 60, 20, b_c);
			Font::StrDraw(L"Press:Aでキャンセル", 440, 80, 20, b_c);
		}
		if (m_p2_battle_flag == true)
		{
			Font::StrDraw(L"準備完了", 440, 60, 20, b_c);
		}
	}
		

	//砲撃タイプ
	if (m_p1_px + 16.0f >= 50 && m_p1_px + 16.0f <= 250)
	{
		if (m_p1_py + 16.0f >= 150 && m_p1_py + 16.0f <= 350)
		{
			if (m_p1_con == 0)
				Font::StrDraw(L"Press:X", 40, 40, 20, w_c);
			Font::StrDraw(L"砲撃タイプ", 100, 380.0f, 20, w_c);
			Font::StrDraw(L"強力なビームを打てるキャラ", 30, 420.0f, 20, w_c);
		}
	}
	if (m_p2_px + 16.0f >= 50 && m_p2_px + 16.0f <= 250)
	{
		if (m_p2_py + 16.0f >= 150 && m_p2_py + 16.0f <= 350)
		{
			if (m_p2_con == 0)
				Font::StrDraw(L"Press:X", 440, 40, 20, w_c);
			Font::StrDraw(L"砲撃タイプ", 100, 380.0f, 20, w_c);
			Font::StrDraw(L"強力なビームを打てるキャラ", 30, 420.0f, 20, w_c);
		}
	}
	//浮遊タイプ
	if (m_p1_px + 16.0f >= 300 && m_p1_px + 16.0f <= 500)
	{
		if (m_p1_py + 16.0f >= 150 && m_p1_py + 16.0f <= 350)
		{
			if (m_p1_con == 0)
				Font::StrDraw(L"Press:X", 40, 40, 20, r_c);
			Font::StrDraw(L"浮遊タイプ", 350, 380.0f, 20, r_c);
			Font::StrDraw(L"浮遊して相手の真上から", 300, 420.0f, 20, r_c);
			Font::StrDraw(L"攻撃できるキャラ", 330, 440.0f, 20, r_c);
		}
	}
	if (m_p2_px + 16.0f >= 300 && m_p2_px + 16.0f <= 500)
	{
		if (m_p2_py + 16.0f >= 150 && m_p2_py + 16.0f <= 350)
		{
			if (m_p2_con == 0)
				Font::StrDraw(L"Press:X", 440, 40, 20, r_c);
			Font::StrDraw(L"浮遊タイプ", 350, 380.0f, 20, r_c);
			Font::StrDraw(L"浮遊して相手の真上から", 300, 420.0f, 20, r_c);
			Font::StrDraw(L"攻撃できるキャラ", 330, 440.0f, 20, r_c);
		}
	}
	//爆裂タイプ
	if (m_p1_px + 16.0f >= 550 && m_p1_px + 16.0f <= 750)
	{
		if (m_p1_py + 16.0f >= 150 && m_p1_py + 16.0f <= 350)
		{
			if (m_p1_con == 0)
				Font::StrDraw(L"Press:X", 40, 40, 20, b_c);
			Font::StrDraw(L"爆裂タイプ", 600, 380.0f, 20, b_c);
			Font::StrDraw(L"一定時間経つと爆発する", 550, 420.0f, 20, b_c);
			Font::StrDraw(L"爆弾を置けるキャラ", 570, 440.0f, 20, b_c);
		}
	}
	if (m_p2_px + 16.0f >= 550 && m_p2_px + 16.0f <= 750)
	{
		if (m_p2_py + 16.0f >= 150 && m_p2_py + 16.0f <= 350)
		{
			if (m_p2_con == 0)
				Font::StrDraw(L"Press:X", 440, 40, 20, b_c);
			Font::StrDraw(L"爆裂タイプ", 600, 380.0f, 20, b_c);
			Font::StrDraw(L"一定時間経つと爆発する", 550, 420.0f, 20, b_c);
			Font::StrDraw(L"爆弾を置けるキャラ", 570, 440.0f, 20, b_c);
		}
	}
	
}

