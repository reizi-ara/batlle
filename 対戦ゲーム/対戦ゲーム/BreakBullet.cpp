//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"

#include "BreakBullet.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjBreakBullet::CObjBreakBullet(float x, float y, bool f, float c, int dam, bool break_flag, int i,int enemy)
{
	m_px = x;
	m_py = y;
	turn_flag = f;

	color = c;

	damage = dam;

	m_break_flag = break_flag;

	line_flag = i;

	enemy_num = enemy;
}

//イニシャライズ
void CObjBreakBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	break_time = 0;

	turn_time = 0.0f;

	Hits::SetHitBox(this, m_px, m_py, 8.0f, 8.0f, ELEMENT_BREAK_BULLET, OBJ_FAST_BULLET, 1);
}

//アクション
void CObjBreakBullet::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	
	
	CObjAttack* a = (CObjAttack*)Objs::GetObj(OBJ_ATTACK);

	if (turn_time >= 360.0f)
	{
		turn_time = 0.0f;
	}
	turn_time += 2.0f;

	if (m_break_flag == false)
	{
		/*if (line_flag == 0)
		{
			if (turn_flag == true)
			{
				m_vx = -10.0f;
			}
			if (turn_flag == false)
			{
				m_vx = 10.0f;
			}
		}*/
		switch (line_flag)
		{
			case 0:
			{
				if (turn_flag == true)
				{
					m_vx = -10.0f;
				}
				if (turn_flag == false)
				{
					m_vx = 10.0f;
				}
				break;
			}
			case 1:
			{
				m_vx = -10.0f;
				m_vy = 0.0f;
				break;
			}
			case 2:
			{
				m_vx = 10.0f;
				m_vy = 0.0f;
				break;
			}
			case 3:
			{
				m_vx = 0.0f;
				m_vy = 10.0f;
				break;
			}
			case 4:
			{
				m_vx = 0.0f;
				m_vy = -10.0f;
				break;
			}
			case 5:
			{
				m_vx = 10.0f;
				m_vy = 10.0f;
				break;
			}
			case 6:
			{
				m_vx = -10.0f;
				m_vy = -10.0f;
				break;
			}
			case 7:
			{
				m_vx = -10.0f;
				m_vy = 10.0f;
				break;
			}
			case 8:
			{
				m_vx = 5.0f;
				m_vy = 10.0f;
				break;
			}
			case 9:
			{
				m_vx = 10.0f;
				m_vy = 5.0f;
				break;
			}
			case 10:
			{
				m_vx = -5.0f;
				m_vy = 10.0f;
				break;
			}
			case 11:
			{
				m_vx = -10.0f;
				m_vy = 5.0f;
				break;
			}
			case 12:
			{
				m_vx = 5.0f;
				m_vy = -10.0f;
				break;
			}
			case 13:
			{
				m_vx = 10.0f;
				m_vy = -5.0f;
				break;
			}
			case 14:
			{
				m_vx = -5.0f;
				m_vy = -10.0f;
				break;
			}
			case 15:
			{
				m_vx = -10.0f;
				m_vy = -5.0f;
				break;
			}
			case 16:
			{
				m_vx = 10.0f;
				m_vy = -10.0f;
				break;
			}
			
		}
	}
	if (m_break_flag == true)
	{
		m_vx = 0;
		break_time++;
		if (break_time >= 120)
		{
			break_time = 0;
			for (int i = 1; i < 17; i++)
			{
				CObjBreakBullet* nb = new CObjBreakBullet(m_px, m_py, turn_flag, 0.5f, 2, false, i, enemy_num);
				Objs::InsertObj(nb, OBJ_BREAK_BULLET, 1);
			}
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
	m_px += m_vx;
	m_py += m_vy;

	hit->SetPos(m_px, m_py);

	if (hit->CheckElementHit(ELEMENT_PLAYER2) == true && m_break_flag == false)
	{
		
		CObjBalance* b = (CObjBalance*)Objs::GetObj(OBJ_BALANCE);
		b->GetDamege(damage);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	}
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true && m_break_flag == false)
	{
		

		CObjMain* m = (CObjMain*)Objs::GetObj(OBJ_MAIN);
		m->GetDamege(damage);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (enemy_num == 1)
	{
		if (hit->CheckElementHit(ELEMENT_ATTACK1) == true)
		{
			CObjMain* m = (CObjMain*)Objs::GetObj(OBJ_MAIN);
			m->GetVX(m_vx / 10.0f);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

	if (enemy_num == 2)
	{
		if (hit->CheckElementHit(ELEMENT_ATTACK2) == true)
		{
			CObjBalance* b = (CObjBalance*)Objs::GetObj(OBJ_BALANCE);
			b->GetVX(m_vx / 10.0f);
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
}

//ドロー
void CObjBreakBullet::Draw()
{
	float c[4] = { color,color,1.0f,1.0f };

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