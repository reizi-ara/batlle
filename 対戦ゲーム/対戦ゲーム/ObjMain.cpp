//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"


#include"ObjMain.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjMain::CObjMain(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjMain::Init()
{
	flag = false;
	m_hit_down = false;
	button_flag = false;
	
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_jump_num = 0;

	turn_flag = false;

	hp = 10;

	gurd_flag = false;
	
	Hits::SetHitBox(this, m_px, m_py, 32.0f, 32.0f, ELEMENT_PLAYER, OBJ_BALANCE, 1);
}

//アクション
void CObjMain::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	con_num = Input::UpdateXControlerConnected();
	if (gurd_flag == false)
	{
		if (Input::GetConButtons(con_num, GAMEPAD_X) == true)
		{
			if (bullet_flag == true)
			{
				CObjFastBullet* nb = new CObjFastBullet(m_px + 16.0f, m_py + 16.0f, turn_flag, 1.0f);
				Objs::InsertObj(nb, OBJ_FAST_BULLET, 1);
				bullet_flag = false;
			}
		}
		else
			bullet_flag = true;


		m_vx += Input::GetConVecStickLX(con_num);
		if (m_vx > 3.0f)
		{
			m_vx = 3.0f;
		}
		if (m_vx < -3.0f)
		{
			m_vx = -3.0f;
		}

		if (Input::GetConButtons(con_num, GAMEPAD_A) == true)
		{
			//if (button_flag == true)
			//{
			if (m_hit_down == true)
				m_vy = -12.0f;
			m_hit_down = false;
			if (/*m_vy >= -3.0f&&*/m_hit_down == false && m_jump_num < 50)
			{
				m_vy = -9.0f;
				m_jump_num += 1;
			}
			button_flag = false;
			//}
		}
		else
			button_flag = true;

		if (Input::GetConVecStickLX(con_num) == 0.0f)
		{
			m_vx *= 0.78;
		}
		if (m_py + 32.0f < 600.0f)
		{
			if(gurd_flag==false)
				m_vy += 6.8 / (16.0f);
		}
		
		
	}
	if (gurd_flag == true)
	{
		m_vx = 0.0f;
		m_vy = 0.0f;
	}

	if (m_vx > 0.0f)
		turn_flag = false;
	if (m_vx < 0.0f)
		turn_flag = true;


	m_px += m_vx;
	m_py += m_vy;

	if (m_py + 32.0f >= 600.0f)
	{
		m_py = 600.0f - 32.0f;
		if (gurd_flag == false)
		{
			m_hit_down = true;
			m_jump_num = 0;
		}
	}
	if (m_py < 0.0f)
	{
		m_py = 0;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
	if (m_px + 32.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}
	if (Input::GetConButtons(con_num, GAMEPAD_RIGHT_SHOULDER) == false)
	{
		gurd_flag = false;
		if (hit->CheckObjNameHit(OBJ_NORMAL_BULLET) != nullptr)
		{
			hp -= 1;
		}
	}
	if (Input::GetConButtons(con_num, GAMEPAD_RIGHT_SHOULDER) == true)
	{
		if (m_jump_num < 50)
		{
			gurd_flag = true;
			m_jump_num += 1;
		}
		
	}
	if (m_jump_num == 50)
	{
		gurd_flag = false;
	}
	if (hp == 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	hit->SetPos(m_px, m_py);
}

//ドロー
void CObjMain::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = 32.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	wchar_t str[256];
	
	swprintf_s(str, L"1P   HP:%d", hp);
	Font::StrDraw(str, 20, 20, 20, c);
	wchar_t str2[256];

	swprintf_s(str2, L"Bust::%d", m_jump_num);
	Font::StrDraw(str2, 20, 40, 20, c);
}

