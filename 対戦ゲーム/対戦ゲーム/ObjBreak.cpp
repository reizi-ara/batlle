//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"


#include"ObjBreak.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjBreak::CObjBreak(float x, float y, int p_con, int enemy)
{
	m_px = x;
	m_py = y;

	m_p_con = p_con;
	enemy_num = enemy;
}

//イニシャライズ
void CObjBreak::Init()
{
	flag = false;
	m_hit_down = false;
	button_flag = false;

	m_vx = 0.0f;
	m_vy = 0.0f;
	m_jump_num = 0;

	if (m_p_con == 1)
		turn_flag = false;
	if (m_p_con == 2)
		turn_flag = true;

	hp = 50;

	gurd_flag = false;

	breaktime = 0;

	sub_R = 3;
	sub_R_time = 0;

	main_R = 10;
	main_R_time = 0;

	gurd_time = false;

	break_flag = false;

	bust_draw_flag = false;

	Hits::SetHitBox(this, m_px, m_py, 32.0f, 32.0f, ELEMENT_PLAYER3, OBJ_BALANCE, 1);
}

//アクション
void CObjBreak::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjSceneMain* m = (CObjSceneMain*)Objs::GetObj(OBJ_SCENE_MAIN);

	if (m->GetBattle() == true)
	{
		if (m_p_con == 1)
			con_num = Input::UpdateXControlerConnected();
		if (m_p_con == 2)
			con_num = Input::UpdateXControlerConnected() - 1;
		if (gurd_flag == false)
		{
			if (Input::GetConButtons(con_num, GAMEPAD_X) == true)
			{
				if (bullet_flag == true && breaktime == 0 && main_R > 0)
				{
					CObjBreakBullet* nb = new CObjBreakBullet(m_px + 16.0f, m_py + 16.0f, turn_flag, 0.5f, 2, false, 0, enemy_num);
					Objs::InsertObj(nb, OBJ_BREAK_BULLET, 1);

					Audio::Start(2);

					bullet_flag = false;
					main_R--;
				}
			}
			else
				bullet_flag = true;


			if (Input::GetConButtons(con_num, GAMEPAD_RIGHT_SHOULDER) == true)
			{
				if (sub_bullet_flag == true && breaktime == 0 && sub_R > 0)
				{
					CObjBreakBullet* nb = new CObjBreakBullet(m_px + 16.0f, m_py + 16.0f, turn_flag, 0.5f, 2, true, 0, enemy_num);
					Objs::InsertObj(nb, OBJ_BREAK_BULLET, 1);

					sub_bullet_flag = false;
					sub_R--;
				}
			}
			else
				sub_bullet_flag = true;


			if (breaktime == 0)
			{
				//左右移動処理
				m_vx += Input::GetConVecStickLX(con_num);
			}
			if (breaktime == 0)
			{
				//移動速度制御
				if (m_vx > 5.0f)
				{
					m_vx = 5.0f;
				}
				if (m_vx < -5.0f)
				{
					m_vx = -5.0f;
				}
			}

			//ジャンプ処理
			if (Input::GetConButtons(con_num, GAMEPAD_A) == true && breaktime == 0)
			{
				/*if (m_hit_down == true)
					m_vy = -12.0f;*/
				m_hit_down = false;
				if (m_hit_down == false && m_jump_num < 50)
				{
					m_vy = -9.0f;
					m_jump_num += 1;
					bust_draw_flag = true;
				}
				else
				{
					bust_draw_flag = false;
				}
				button_flag = false;
			}
			else
			{
				button_flag = true;
				bust_draw_flag = false;
			}

			//摩擦
			if (Input::GetConVecStickLX(con_num) == 0.0f && breaktime == 0)
			{
				m_vx *= 0.78;
			}
			if (m_py + 32.0f < 536.0f)
			{
				if (gurd_flag == false)
					m_vy += 6.8 / (16.0f);

			}

		}
		//防御中は移動を制限する
		if (gurd_flag == true && breaktime == 0)
		{
			m_vx = 0.0f;
			m_vy = 0.0f;
		}
		if (m_jump_num == 50)
		{
			m_vx = 0.0f;
		}




		//左右の向きのフラグ
		if (m_vx > 0.0f)
			turn_flag = false;
		if (m_vx < 0.0f)
			turn_flag = true;

		//位置の更新
		m_px += m_vx;
		m_py += m_vy;

		//画面外領域処理---------------------
		if (m_py + 32.0f >= 536.0f)
		{
			m_hit_down = true;
			m_py = 536.0f - 32.0f;
			if (gurd_flag == false && breaktime == 20)
			{

				m_jump_num = 0;
				breaktime = 0;
			}
			else if (m_jump_num < 50 && gurd_flag == false)
			{
				m_jump_num = 0;
			}
		}
		if (m_py < 64.0f)
		{
			m_py = 64.0f;
		}
		if (m_px < 30.0f)
		{
			m_px = 30.0f;
		}
		if (m_px + 32.0f > 770.0f)
		{
			m_px = 770.0f - 32.0f;
		}
		//--------------------------------------

		/*if (Input::GetConButtons(con_num, GAMEPAD_B) == true)
		{
			break_flag = true;
		}
		else
		{
			break_flag = false;
		}*/

		//ガードをしていないとき
		/*if (Input::GetConButtons(con_num, GAMEPAD_LEFT_SHOULDER) == false)
		{
			gurd_flag = false;
			if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
			{
				hp -= 1;
			}
		}*/
		if (Input::GetConButtons(con_num, GAMEPAD_LEFT_SHOULDER) == false)
		{
			gurd_flag = false;
			gurd_time = false;
		}
		//ガードをしているとき
		if (Input::GetConButtons(con_num, GAMEPAD_LEFT_SHOULDER) == true)
		{
			if (m_jump_num < 50)
			{
				if (gurd_time == false)
				{
					if (hp > 0)
					{
						CObjAttack* a = new CObjAttack(m_px, m_py, turn_flag, 1.0f, 2, 3);
						Objs::InsertObj(a, OBJ_ATTACK, 1);
						//gurd_time = true;
					}

				}
				gurd_flag = true;
				m_jump_num += 1;
			}
		}
		/*if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
		{
			hp -= 1;
		}*/
		//ブースト残量がないためガードをできない
		if (m_jump_num == 50)
		{
			gurd_flag = false;
			if (breaktime < 20 && m_hit_down == true)
				breaktime++;
			gurd_time = false;
		}
		//HPが0になった時
		if (hp <= 0)
		{
			if (m_p_con == 1)
				m->GetVictory(2);
			if (m_p_con == 2)
				m->GetVictory(1);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			//Scene::SetScene(new SceneMain());
		}

		hit->SetPos(m_px, m_py);

		if (sub_R == 0)
		{
			sub_R_time++;
		}

		if (sub_R_time == 400)
		{
			sub_R = 3;
			sub_R_time = 0;
		}

		if (main_R == 0)
		{
			main_R_time++;
		}
		if (main_R_time == 120)
		{
			main_R = 10;
			main_R_time = 0;
		}


	}

	if (m->GetBattle() == false)
	{
		//位置の更新
		m_px += m_vx;
		m_py += m_vy;

		hit->SetPos(m_px, m_py);

		//落下処理
		if (m_py + 32.0f < 536.0f)
		{
			if (gurd_flag == false)
				m_vy += 6.8 / (16.0f);
		}
		if (m_py + 32.0f >= 536.0f)
		{
			m_hit_down = true;
			m_py = 536.0f - 32.0f;

			if (gurd_flag == false && breaktime == 20)
			{

				m_jump_num = 0;
				breaktime = 0;
			}
			else if (m_jump_num < 500 && gurd_flag == false)
			{
				m_jump_num = 0;
			}
		}
		if (m_py < 64.0f)
		{
			m_py = 64.0f;
		}
		if (m_px < 30.0f)
		{
			m_px = 30.0f;
		}
		if (m_px + 32.0f > 770.0f)
		{
			m_px = 770.0f - 32.0f;
		}

	}
	
}

//ドロー
void CObjBreak::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b_c[4] = { 0.5f,0.5f,1.0f,1.0f };
	float bk_c[4] = { 0.0f,0.0f,0.0f,1.0f };
	float wt_c[4] = { 1.0f,1.0f,1.0f,1.0f };

	int gd = 1;

	if (gurd_flag == true)
	{
		gd = 6;
	}

	wchar_t str[256];
	wchar_t str2[256];
	wchar_t str3[256];

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
	RECT_F src6;
	RECT_F dst6;
	RECT_F src7;
	RECT_F dst7;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	if (turn_flag == false)
	{
		dst.m_top = m_py;
		dst.m_left = m_px;
		dst.m_right = 32.0f + m_px;
		dst.m_bottom = 32.0f + m_py;
	}
	if (turn_flag == true)
	{
		dst.m_top = m_py;
		dst.m_left = 32.0f + m_px;
		dst.m_right = m_px;
		dst.m_bottom = 32.0f + m_py;
	}

	Draw::Draw(gd, &src, &dst, b_c, 0.0f);

	RECT_F src8;
	RECT_F dst8;

	src8.m_top = 0.0f;
	src8.m_left = 0.0f;
	src8.m_right = 64.0f;
	src8.m_bottom = 64.0f;

	dst8.m_top = 32.0f + m_py;
	dst8.m_left = m_px;
	dst8.m_right = 32.0f + m_px;
	dst8.m_bottom = 64.0f + m_py;

	if (bust_draw_flag == true)
		Draw::Draw(7, &src8, &dst8, wt_c, 0.0f);


	if (m_p_con == 1)
	{


		Font::StrDraw(L"1P", 20, 560, 20, b_c);


		//ゲージ
		src2.m_top = 0.0f;
		src2.m_left = 0.0f;
		src2.m_right = 64.0f;
		src2.m_bottom = 64.0f;


		dst2.m_top = 560.0f;
		dst2.m_left = 170.0f;
		dst2.m_right = dst2.m_left + (m_jump_num * 2);
		dst2.m_bottom = dst2.m_top + 20.0f;

		Draw::Draw(2, &src2, &dst2, b_c, 0.0f);


		//ゲージ
		src3.m_top = 0.0f;
		src3.m_left = 0.0f;
		src3.m_right = 64.0f;
		src3.m_bottom = 64.0f;


		dst3.m_top = 560.0f;
		dst3.m_left = 60.0f;
		dst3.m_right = dst3.m_left + hp;
		dst3.m_bottom = dst3.m_top + 20.0f;


		Draw::Draw(2, &src3, &dst3, b_c, 0.0f);

		swprintf_s(str, L"%d", hp);
		Font::StrDraw(str, 60, 560, 20, bk_c);


		//ゲージ
		src4.m_top = 0.0f;
		src4.m_left = 0.0f;
		src4.m_right = 64.0f;
		src4.m_bottom = 64.0f;


		dst4.m_top = 10.0f;
		dst4.m_left = 120.0f;
		dst4.m_right = dst4.m_left + sub_R * (50 / 3);
		dst4.m_bottom = dst4.m_top + 20.0f;

		Draw::Draw(2, &src4, &dst4, b_c, 0.0f);

		//ゲージ
		src5.m_top = 0.0f;
		src5.m_left = 0.0f;
		src5.m_right = 64.0f;
		src5.m_bottom = 64.0f;


		dst5.m_top = 10.0f;
		dst5.m_left = 120.0f;
		dst5.m_right = dst5.m_left + sub_R_time / 8;
		dst5.m_bottom = dst5.m_top + 20.0f;

		Draw::Draw(2, &src5, &dst5, bk_c, 0.0f);

		swprintf_s(str2, L"サブ：%d", sub_R);
		Font::StrDraw(str2, 60, 10, 20, bk_c);

		//メインゲージ
		src6.m_top = 0.0f;
		src6.m_left = 0.0f;
		src6.m_right = 64.0f;
		src6.m_bottom = 64.0f;


		dst6.m_top = 40.0f;
		dst6.m_left = 120.0f;
		dst6.m_right = dst6.m_left + main_R * 5;
		dst6.m_bottom = dst6.m_top + 20.0f;

		//メインゲージ描画
		Draw::Draw(2, &src6, &dst6, b_c, 0.0f);

		//メインリロードゲージ
		src7.m_top = 0.0f;
		src7.m_left = 0.0f;
		src7.m_right = 64.0f;
		src7.m_bottom = 64.0f;


		dst7.m_top = 40.0f;
		dst7.m_left = 120.0f;
		dst7.m_right = dst7.m_left + main_R_time / 12 * 5;
		dst7.m_bottom = dst7.m_top + 20.0f;

		//メインリロードゲージ描画
		Draw::Draw(2, &src7, &dst7, bk_c, 0.0f);


		swprintf_s(str2, L"メイン：%d", main_R);
		Font::StrDraw(str2, 40, 40, 20, bk_c);

		if (m_jump_num == 50)
		{
			if (breaktime % 5 == 0)
				Font::StrDraw(L"OVERHEAT", 170, 560, 20, bk_c);
		}
	}
	if (m_p_con == 2)
	{


		//2P表記
		Font::StrDraw(L"2P", 750, 560, 20, b_c);


		//Boostゲージ
		src2.m_top = 0.0f;
		src2.m_left = 0.0f;
		src2.m_right = 64.0f;
		src2.m_bottom = 64.0f;


		dst2.m_top = 560.0f;
		dst2.m_left = 630.0f;
		dst2.m_right = dst2.m_left - (m_jump_num * 2);
		dst2.m_bottom = dst2.m_top + 20.0f;

		//Boostゲージ描画
		Draw::Draw(2, &src2, &dst2, b_c, 0.0f);

		//HPゲージ
		src3.m_top = 0.0f;
		src3.m_left = 0.0f;
		src3.m_right = 64.0f;
		src3.m_bottom = 64.0f;


		dst3.m_top = 560.0f;
		dst3.m_left = 730.0f;
		dst3.m_right = dst3.m_left - hp;
		dst3.m_bottom = dst3.m_top + 20.0f;

		//HPゲージ描画
		Draw::Draw(2, &src3, &dst3, b_c, 0.0f);

		//HP表示
		swprintf_s(str, L"%d", hp);
		Font::StrDraw(str, 710, 560, 20, bk_c);

		//サブゲージ
		src4.m_top = 0.0f;
		src4.m_left = 0.0f;
		src4.m_right = 64.0f;
		src4.m_bottom = 64.0f;


		dst4.m_top = 10.0f;
		dst4.m_left = 610.0f;
		dst4.m_right = dst4.m_left - sub_R * (50 / 3);
		dst4.m_bottom = dst4.m_top + 20.0f;

		//サブゲージ描画
		Draw::Draw(2, &src4, &dst4, b_c, 0.0f);

		//サブリロードゲージ
		src5.m_top = 0.0f;
		src5.m_left = 0.0f;
		src5.m_right = 64.0f;
		src5.m_bottom = 64.0f;


		dst5.m_top = 10.0f;
		dst5.m_left = 610.0f;
		dst5.m_right = dst5.m_left - sub_R_time / 8;
		dst5.m_bottom = dst5.m_top + 20.0f;

		//サブリロードゲージ描画
		Draw::Draw(2, &src5, &dst5, bk_c, 0.0f);


		swprintf_s(str2, L"%d：サブ", sub_R);
		Font::StrDraw(str2, 600, 10, 20, bk_c);

		//メインゲージ
		src6.m_top = 0.0f;
		src6.m_left = 0.0f;
		src6.m_right = 64.0f;
		src6.m_bottom = 64.0f;


		dst6.m_top = 40.0f;
		dst6.m_left = 610.0f;
		dst6.m_right = dst6.m_left - main_R * 5;
		dst6.m_bottom = dst6.m_top + 20.0f;

		//メインゲージ描画
		Draw::Draw(2, &src6, &dst6, b_c, 0.0f);

		//メインリロードゲージ
		src7.m_top = 0.0f;
		src7.m_left = 0.0f;
		src7.m_right = 64.0f;
		src7.m_bottom = 64.0f;


		dst7.m_top = 40.0f;
		dst7.m_left = 610.0f;
		dst7.m_right = dst7.m_left - main_R_time / 12 * 5;
		dst7.m_bottom = dst7.m_top + 20.0f;

		//メインリロードゲージ描画
		Draw::Draw(2, &src7, &dst7, bk_c, 0.0f);

		swprintf_s(str3, L"%d：メイン", main_R);
		if (main_R < 10)
			Font::StrDraw(str3, 600, 40, 20, bk_c);
		else
			Font::StrDraw(str3, 590, 40, 20, bk_c);

		if (m_jump_num >= 50)
		{
			if (breaktime % 5 == 0)
				Font::StrDraw(L"OVERHEAT", 550, 560, 20, bk_c);
		}
	}

}