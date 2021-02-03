//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"

#include "Attack.h"
#include "GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjAttack::CObjAttack(float x, float y, bool f, float c, int con_num, int num)
{
	m_px = x;
	m_py = y;

	turn_flag = f;

	color = c;

	m_con_num = con_num;

	char_num = num;
}

//�C�j�V�����C�Y
void CObjAttack::Init()
{
	gurd_point = 0;

	if (char_num == 1)
	{
		if (turn_flag == true)//������
			Hits::SetHitBox(this, m_px - 16.0f, m_py, 16.0f, 32.0f, ELEMENT_ATTACK1, OBJ_ATTACK, 1);
		if (turn_flag == false)//�E����
			Hits::SetHitBox(this, m_px + 32.0f, m_py, 16.0f, 32.0f, ELEMENT_ATTACK1, OBJ_ATTACK, 1);
	}
	if (char_num == 2)
	{
		if (turn_flag == true)//������
			Hits::SetHitBox(this, m_px - 16.0f, m_py, 16.0f, 32.0f, ELEMENT_ATTACK2, OBJ_ATTACK, 1);
		if (turn_flag == false)//�E����
			Hits::SetHitBox(this, m_px + 32.0f, m_py, 16.0f, 32.0f, ELEMENT_ATTACK2, OBJ_ATTACK, 1);
	}
	if (char_num == 3)
	{
		if (turn_flag == true)//������
			Hits::SetHitBox(this, m_px - 16.0f, m_py, 16.0f, 32.0f, ELEMENT_ATTACK3, OBJ_ATTACK, 1);
		if (turn_flag == false)//�E����
			Hits::SetHitBox(this, m_px + 32.0f, m_py, 16.0f, 32.0f, ELEMENT_ATTACK3, OBJ_ATTACK, 1);
	}
}

//�A�N�V����
void CObjAttack::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	
		if (char_num == 3)//1�̎����V�^�C�v
		{
			CObjBreak* bb = (CObjBreak*)Objs::GetObj(OBJ_BREAK);
			if (turn_flag == true)//������
			{
				m_px = bb->GetPX() - 16.0f;
				m_py = bb->GetPY();
			}
			if (turn_flag == false)//�E����
			{
				m_px = bb->GetPX() + 32.0f;
				m_py = bb->GetPY();
			}

			if (bb->GetGurd() == false)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
			}

			if (gurd_point >= 10)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				bb->GetJump();
			}
		}
		if (char_num == 2)//1�̎����V�^�C�v
		{
			CObjBalance* b = (CObjBalance*)Objs::GetObj(OBJ_BALANCE);
			if (turn_flag == true)//������
			{
				m_px = b->GetPX() - 16.0f;
				m_py = b->GetPY();
			}
			if (turn_flag == false)//�E����
			{
				m_px = b->GetPX() + 32.0f;
				m_py = b->GetPY();
			}

			if (b->GetGurd() == false)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
			}

			if (gurd_point >= 10)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				b->GetJump();
			}
		}
		if (char_num == 1)//2�̎��C���^�C�v
		{
			CObjMain* m = (CObjMain*)Objs::GetObj(OBJ_MAIN);
			m_hp = m->GetHP();
			if (m_hp <= 0)
			{
				if (turn_flag == true)//������
				{
					m_px = m->GetPX() - 16.0f;
					m_py = m->GetPY();
				}
				if (turn_flag == false)//�E����
				{
					m_px = m->GetPX() + 32.0f;
					m_py = m->GetPY();
				}

				if (m->GetGurd() == false)
				{
					this->SetStatus(false);
					Hits::DeleteHitBox(this);
				}
				if (gurd_point >= 10)
				{
					this->SetStatus(false);
					Hits::DeleteHitBox(this);
					m->GetJump();
				}
			}
		}

	

	hit->SetPos(m_px, m_py);
}

//�h���[
void CObjAttack::Draw()
{
	CHitBox* hit = Hits::GetHitBox(this);

	float c[4] = { 1.0f,color,color,1.0f };
	float b_c[4] = { 0.5f,0.5f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = 16.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	if (hit->CheckElementHit(ELEMENT_NORMAL_BULLET) == true)
	{
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}

	if (hit->CheckElementHit(ELEMENT_FAST_BULLET) == true)
	{
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}
	if (hit->CheckElementHit(ELEMENT_BREAK_BULLET) == true)
	{
		Draw::Draw(2, &src, &dst, b_c, 0.0f);
	}


	this->SetStatus(false);
	Hits::DeleteHitBox(this);

}