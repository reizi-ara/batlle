//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"

#include "FastBullet.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjFastBullet::CObjFastBullet(float x, float y, bool f, float c,int dam,int enemy)
{
	m_px = x;
	m_py = y;
	turn_flag = f;

	color = c;

	damage = dam;

	enemy_num = enemy;
}

//イニシャライズ
void CObjFastBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	Hits::SetHitBox(this, m_px, m_py, 8.0f, 8.0f, ELEMENT_FAST_BULLET, OBJ_FAST_BULLET, 1);
}

//アクション
void CObjFastBullet::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	
	
	CObjAttack* a = (CObjAttack*)Objs::GetObj(OBJ_ATTACK);

	if (turn_flag == true)
	{
		m_vx = -10.0f;
	}
	if (turn_flag == false)
	{
		m_vx = 10.0f;
	}
	m_px += m_vx;
	
	hit->SetPos(m_px, m_py);

	if (hit->CheckElementHit(ELEMENT_PLAYER2) == true)
	{

		CObjBalance* b = (CObjBalance*)Objs::GetObj(OBJ_BALANCE);
		b->GetDamege(damage);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		
	}
	if (hit->CheckElementHit(ELEMENT_PLAYER3) == true)
	{
		
		CObjBreak* bb = (CObjBreak*)Objs::GetObj(OBJ_BREAK);
		bb->GetDamege(damage);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);


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
	if (enemy_num== 3)
	{
		if (hit->CheckElementHit(ELEMENT_ATTACK3) == true)
		{
			CObjBreak* bb = (CObjBreak*)Objs::GetObj(OBJ_BREAK);
			bb->GetVX(m_vx / 10.0f);
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
void CObjFastBullet::Draw()
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