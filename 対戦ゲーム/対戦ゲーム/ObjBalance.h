#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjBalance : public CObj
{
public:
	CObjBalance(float x, float y);
	~CObjBalance() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	void GetDamege(int dam)
	{
		if (gurd_flag == false && boost_flag == false)
			hp -= dam;
	}
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

	int hp;

	bool gurd_flag;

	int breaktime;

	bool boost_flag;

	int sub_R;
	int sub_R_time;

	int main_R;
	int main_R_time;
};