//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"
#include"GameL/Audio.h"

#include "NormalBullet.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjNormalBullet::CObjNormalBullet(float x, float y,bool f,float c,int dam,bool hf,int enemy,int bullet)
{
	m_px = x;
	m_py = y;
	turn_flag = f;

	color = c;

	damage = dam;
	h_flag = hf;

	enemy_num = enemy;

	bullet_num = bullet;
}

//イニシャライズ
void CObjNormalBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	turn_time = 0.0f;

	

	Hits::SetHitBox(this, m_px, m_py, 8.0f, 8.0f, ELEMENT_NORMAL_BULLET, OBJ_NORMAL_BULLET, 1);
}

//アクション
void CObjNormalBullet::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	
	
	CObjAttack* a = (CObjAttack*)Objs::GetObj(OBJ_ATTACK);

	if (turn_time >= 360.0f)
	{
		turn_time = 0.0f;
	}
	turn_time += 2.0f;

	if (h_flag == false)
	{
		if (turn_flag == true)
		{
			m_vx = -10.0f;
		}
		if (turn_flag == false)
		{
			m_vx = 10.0f;
		}
		
	}
	if (h_flag == true)
	{
		switch (bullet_num)
		{
			/*case 0:
			{
				m_vx = 0.0f;
				m_vy = 10.0f;
				break;
			}*/
			case 0:
			{
				m_vx = 2.0f;
				m_vy = 10.0f;
				break;
			}
			case 1:
			{
				m_vx = -2.0f;
				m_vy = 10.0f;
				break;
			}
		}
	}


	m_px += m_vx;
	m_py += m_vy;
	

	hit->SetPos(m_px, m_py);
	
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		
		CObjMain* m = (CObjMain*)Objs::GetObj(OBJ_MAIN);
		m->GetDamege(damage);

		Audio::Start(4);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		
	}
	if (hit->CheckElementHit(ELEMENT_PLAYER3) == true)
	{
		
		CObjBreak* bb = (CObjBreak*)Objs::GetObj(OBJ_BREAK);
		bb->GetDamege(damage);
		Audio::Start(4);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	}

	if (enemy_num == 1)
	{
		if (hit->CheckElementHit(ELEMENT_ATTACK1) == true)
		{
			CObjMain* m = (CObjMain*)Objs::GetObj(OBJ_MAIN);
			if (h_flag == false)
			{
				m->GetVX(m_vx / 10.0f);
				Audio::Start(7);
			}
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
	if (enemy_num == 3)
	{
		if (hit->CheckElementHit(ELEMENT_ATTACK3) == true)
		{
			CObjBreak* bb = (CObjBreak*)Objs::GetObj(OBJ_BREAK);
			if (h_flag == false)
			{
				bb->GetVX(m_vx / 10.0f);
				Audio::Start(7);
			}
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	if (m_px + 8.0f >= 800)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);	
	}
	if (m_px <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (m_py > 600)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjNormalBullet::Draw()
{
	float c[4] = { 1.0f,color,color,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = 8.0f + m_px;
	dst.m_bottom = 8.0f + m_py;

	Draw::Draw(2, &src, &dst, c, turn_time);
}