//�g�p����w�b�_�[�t�@�C��
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"


#include"ObjSceneSelect.h"
#include "GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
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

//�A�N�V����
void CObjSceneSelect::Action()
{
	m_p1_con_num = Input::UpdateXControlerConnected() ;
	m_p2_con_num = Input::UpdateXControlerConnected() - 1;

	//���E�ړ�����
	m_p1_vx += Input::GetConVecStickLX(m_p1_con_num);
	m_p1_vy -= Input::GetConVecStickLY(m_p1_con_num);

	//�ړ����x����
	if (m_p1_vx > 6.0f)
	{
		m_p1_vx = 6.0f;
	}
	if (m_p1_vx < -6.0f)
	{
		m_p1_vx = -6.0f;
	}
	//�ړ����x����
	if (m_p1_vy > 6.0f)
	{
		m_p1_vy = 6.0f;
	}
	if (m_p1_vy < -6.0f)
	{
		m_p1_vy = -6.0f;
	}

	//���E�ړ�����
	m_p2_vx += Input::GetConVecStickLX(m_p2_con_num);
	m_p2_vy -= Input::GetConVecStickLY(m_p2_con_num);

	//�ړ����x����
	if (m_p2_vx > 6.0f)
	{
		m_p2_vx = 6.0f;
	}
	if (m_p2_vx < -6.0f)
	{
		m_p2_vx = -6.0f;
	}
	//�ړ����x����
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
	if (Input::GetConVecStickLX(m_p2_con_num) == 0.0f)
	{
		m_p2_vy = 0.0f;
	}

	//�ʒu�̍X�V
	m_p1_px += m_p1_vx;
	m_p1_py += m_p1_vy;

	m_p2_px += m_p2_vx;
	m_p2_py += m_p2_vy;

	//�̈�O����
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

	//�̈�O����
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
	//�C���^�C�v
	if (m_p1_px >= 200 && m_p1_px + 32.0f <= 400)
	{
		if (m_p1_py >= 200 && m_p1_py + 32.0f <= 400)
		{
			if (Input::GetConButtons(m_p1_con_num, GAMEPAD_X) == true)
			{
				if (m_p2_con != 1)
					m_p1_con = 1;
			}
		}
	}
	if (m_p2_px >= 200 && m_p2_px + 32.0f <= 400)
	{
		if (m_p2_py >= 200 && m_p2_py + 32.0f <= 400)
		{
			if (Input::GetConButtons(m_p2_con_num, GAMEPAD_X) == true)
			{
				if (m_p1_con != 1)
					m_p2_con = 1;
			}
		}
	}
	//���V�^�C�v
	if (m_p1_px >= 400 && m_p1_px + 32.0f <= 600)
	{
		if (m_p1_py >= 200 && m_p1_py + 32.0f <= 400)
		{
			if (Input::GetConButtons(m_p1_con_num, GAMEPAD_X) == true)
			{
				if (m_p2_con != 2)
					m_p1_con = 2;
			}
		}
	}
	if (m_p2_px >= 400 && m_p2_px + 32.0f <= 600)
	{
		if (m_p2_py >= 200 && m_p2_py + 32.0f <= 400)
		{
			if (Input::GetConButtons(m_p2_con_num, GAMEPAD_X) == true)
			{
				if (m_p1_con != 2)
					m_p2_con = 2;
			}			
		}
	}
	//����^�C�v
	if (m_p1_px >= 600 && m_p1_px + 32.0f <= 800)
	{
		if (m_p1_py >= 200 && m_p1_py + 32.0f <= 400)
		{
			if (Input::GetConButtons(m_p1_con_num, GAMEPAD_X) == true)
			{
				if (m_p2_con != 3)
					m_p1_con = 3;
			}
		}
	}
	if (m_p2_px >= 600 && m_p2_px + 32.0f <= 800)
	{
		if (m_p2_py >= 200 && m_p2_py + 32.0f <= 400)
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

	if (m_p1_battle_flag == true && m_p2_battle_flag == true)
	{
		Scene::SetScene(new SceneMain(m_p1_con,m_p2_con));
	}
	
}

//�h���[
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


	dst1.m_top = m_p1_py;
	dst1.m_left = m_p1_px;
	dst1.m_right = 32.0f + m_p1_px;
	dst1.m_bottom = 32.0f + m_p1_py;

	dst2.m_top = m_p2_py;
	dst2.m_left = m_p2_px;
	dst2.m_right = 32.0f + m_p2_px;
	dst2.m_bottom = 32.0f + m_p2_py;

	dst3.m_top = 200.0f;
	dst3.m_left = 200.0f;
	dst3.m_right = 400.0f;
	dst3.m_bottom = 400.0f;

	dst4.m_top = 200.0f;
	dst4.m_left = 400.0f;
	dst4.m_right = 600.0f;
	dst4.m_bottom = 400.0f;

	dst5.m_top = 200.0f;
	dst5.m_left = 600.0f;
	dst5.m_right = 800.0f;
	dst5.m_bottom = 400.0f;

	Draw::Draw(1, &src3, &dst3, w_c, 0.0f);
	Draw::Draw(1, &src4, &dst4, r_c, 0.0f);
	Draw::Draw(1, &src5, &dst5, b_c, 0.0f);

	Draw::Draw(5, &src1, &dst1, w_c, 0.0f);
	Draw::Draw(5, &src2, &dst2, r_c, 0.0f);


	wchar_t str1[256];
	if (m_p1_con == 1)
	{
		Font::StrDraw(L"1P�͖C���^�C�v�ł�", 40, 40, 20, w_c);
		if (m_p1_battle_flag == false)
		{
			Font::StrDraw(L"Press:Y�ŏ�������", 40, 60, 20, w_c);
			Font::StrDraw(L"Press:A�ŃL�����Z��", 40, 80, 20, w_c);
		}
		if (m_p1_battle_flag == true)
		{
			Font::StrDraw(L"��������", 40, 60, 20, w_c);
		}
	}
	
	if (m_p2_con == 1)
	{
		Font::StrDraw(L"2P�͖C���^�C�v�ł�", 440, 40, 20, w_c);
		if (m_p2_battle_flag == false)
		{
			Font::StrDraw(L"Press:Y�ŏ�������", 440, 60, 20, w_c);
			Font::StrDraw(L"Press:A�ŃL�����Z��", 440, 80, 20, w_c);
		}
		if (m_p2_battle_flag == true)
		{
			Font::StrDraw(L"��������", 440, 60, 20, w_c);
		}
	}
		
	if (m_p1_con == 2)
	{
		Font::StrDraw(L"1P�͕��V�^�C�v�ł�", 40, 40, 20, w_c);
		if (m_p1_battle_flag == false)
		{
			Font::StrDraw(L"Press:Y�ŏ�������", 40, 60, 20, w_c);
			Font::StrDraw(L"Press:A�ŃL�����Z��", 40, 80, 20, w_c);
		}
		if (m_p1_battle_flag == true)
		{
			Font::StrDraw(L"��������", 40, 60, 20, w_c);
		}
	}
		
	if (m_p2_con == 2)
	{
		Font::StrDraw(L"2P�͕��V�^�C�v�ł�", 440, 40, 20, w_c);
		if (m_p2_battle_flag == false)
		{
			Font::StrDraw(L"Press:Y�ŏ�������", 440, 60, 20, w_c);
			Font::StrDraw(L"Press:A�ŃL�����Z��", 440, 80, 20, w_c);
		}
		if (m_p2_battle_flag == true)
		{
			Font::StrDraw(L"��������", 440, 60, 20, w_c);
		}
	}
	if (m_p1_con == 3)
	{
		Font::StrDraw(L"1P�͔���^�C�v�ł�", 40, 40, 20, w_c);
		if (m_p1_battle_flag == false)
		{
			Font::StrDraw(L"Press:Y�ŏ�������", 40, 60, 20, w_c);
			Font::StrDraw(L"Press:A�ŃL�����Z��", 40, 80, 20, w_c);
		}
		if (m_p1_battle_flag == true)
		{
			Font::StrDraw(L"��������", 40, 60, 20, w_c);
		}
	}

	if (m_p2_con == 3)
	{
		Font::StrDraw(L"2P�͔���^�C�v�ł�", 440, 40, 20, w_c);
		if (m_p2_battle_flag == false)
		{
			Font::StrDraw(L"Press:Y�ŏ�������", 440, 60, 20, w_c);
			Font::StrDraw(L"Press:A�ŃL�����Z��", 440, 80, 20, w_c);
		}
		if (m_p2_battle_flag == true)
		{
			Font::StrDraw(L"��������", 440, 60, 20, w_c);
		}
	}
		

	//�C���^�C�v
	if (m_p1_px >= 200 && m_p1_px + 32.0f <= 400)
	{
		if (m_p1_py >= 200 && m_p1_py + 32.0f <= 400)
		{
			if (m_p1_con == 0)
				Font::StrDraw(L"Press:X", 40, 40, 20, w_c);
		}
	}
	if (m_p2_px >= 200 && m_p2_px + 32.0f <= 400)
	{
		if (m_p2_py >= 200 && m_p2_py + 32.0f <= 400)
		{
			if (m_p2_con == 0)
				Font::StrDraw(L"Press:X", 440, 40, 20, w_c);
		}
	}
	//���V�^�C�v
	if (m_p1_px >= 400 && m_p1_px + 32.0f <= 600)
	{
		if (m_p1_py >= 200 && m_p1_py + 32.0f <= 400)
		{
			if (m_p1_con == 0)
				Font::StrDraw(L"Press:X", 40, 40, 20, w_c);
		}
	}
	if (m_p2_px >= 400 && m_p2_px + 32.0f <= 600)
	{
		if (m_p2_py >= 200 && m_p2_py + 32.0f <= 400)
		{
			if (m_p2_con == 0)
				Font::StrDraw(L"Press:X", 440, 40, 20, w_c);
		}
	}
	//����^�C�v
	if (m_p1_px >= 600 && m_p1_px + 32.0f <= 800)
	{
		if (m_p1_py >= 200 && m_p1_py + 32.0f <= 400)
		{
			if (m_p1_con == 0)
				Font::StrDraw(L"Press:X", 40, 40, 20, w_c);
		}
	}
	if (m_p2_px >= 600 && m_p2_px + 32.0f <= 800)
	{
		if (m_p2_py >= 200 && m_p2_py + 32.0f <= 400)
		{
			if (m_p2_con == 0)
				Font::StrDraw(L"Press:X", 440, 40, 20, w_c);
		}
	}
	
}

