#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjBreakBullet : public CObj
{
public:
	CObjBreakBullet(float x, float y, bool f, float c, int dam, bool break_flag,int i,int enemy);
	~CObjBreakBullet() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:
	float m_px;
	float m_py;

	float m_vx;
	float m_vy;

	bool turn_flag;

	float color;

	int damage;

	bool m_break_flag;

	int break_time;

	int line_flag;

	float turn_time;

	int enemy_num;
};