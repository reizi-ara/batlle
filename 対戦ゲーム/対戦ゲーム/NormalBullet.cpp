//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"

#include "NormalBullet.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjNormalBullet::CObjNormalBullet(float x, float y,bool f,float c,int dam,bool hf)
{
	m_px = x;
	m_py = y;
	turn_flag = f;

	color = c;

	damage = dam;
	h_flag = hf;
}

//イニシャライズ
void CObjNormalBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	Hits::SetHitBox(this, m_px, m_py, 8.0f, 8.0f, ELEMENT_BULLET, OBJ_NORMAL_BULLET, 1);
}

//アクション
void CObjNormalBullet::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjMain* m = (CObjMain*)Objs::GetObj(OBJ_MAIN);

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
		m_px += m_vx;
	}
	if (h_flag == true)
	{
		m_vy = 10.0f;
		m_py += m_vy;
	}

	

	hit->SetPos(m_px, m_py);
	
	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		m->GetDamege(damage);
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

	Draw::Draw(2, &src, &dst, c, 0.0f);
}