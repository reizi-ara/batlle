#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjMain : public CObj
{
public:
	CObjMain(float x,float y);
	~CObjMain() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	void GetDamege(int dam) 
	{
		if (gurd_flag == false)
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

	bool sub_bullet_flag;

	int hp;

	bool gurd_flag;

	int breaktime;

	int sub_R;

	int sub_R_time;

	int main_R;
	int main_R_time;
};