#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjFastBullet : public CObj
{
public:
	CObjFastBullet(float x, float y, bool f, float c,int dam,int enemy,int bullet);
	~CObjFastBullet() {};
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

	int enemy_num;

	float turn_time;
	int bullet_num;
};