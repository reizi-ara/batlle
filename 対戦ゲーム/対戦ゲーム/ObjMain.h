#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjMain : public CObj
{
public:
	CObjMain(float x,float y,int p_con,int enemy);
	~CObjMain() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	float GetPX() { return m_px; }
	float GetPY() { return m_py; }

	bool GetGurd() { return gurd_flag; }
	int GetHP() { return hp; }

	void GetDamege(int dam) 
	{
		
			hp -= dam;
	}
	void GetVX(float x)
	{
		m_px += x;
	}
	void GetJump() { m_jump_num = 50; }
private:

	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	bool flag;

	int con_num;

	bool m_hit_down;

	int m_jump_num;

	bool button_flag;

	bool turn_flag;//true�����Afalse���E

	bool bullet_flag;

	bool sub_bullet_flag;

	int hp;

	bool gurd_flag;

	int breaktime;

	int sub_R;

	int sub_R_time;

	int main_R;
	int main_R_time;

	int m_p_con;

	bool gurd_time;

	int enemy_num;

	int bullet_time;

	int bullet_num;
};