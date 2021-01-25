//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"

#include "FastBullet.h"
#include "GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjFastBullet::CObjFastBullet(float x, float y, bool f, float c,int dam)
{
	m_px = x;
	m_py = y;
	turn_flag = f;

	color = c;

	damage = dam;
}

//�C�j�V�����C�Y
void CObjFastBullet::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	Hits::SetHitBox(this, m_px, m_py, 8.0f, 8.0f, ELEMENT_BULLET, OBJ_FAST_BULLET, 1);
}

//�A�N�V����
void CObjFastBullet::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjBalance* b = (CObjBalance*)Objs::GetObj(OBJ_BALANCE);

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
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		b->GetDamege(damage);
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

//�h���[
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