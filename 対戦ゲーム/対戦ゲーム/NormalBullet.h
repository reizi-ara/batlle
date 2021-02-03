#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjNormalBullet : public CObj
{
public:
	CObjNormalBullet(float x, float y,bool f,float c,int dam,bool hf,int enemy,int bullet);
	~CObjNormalBullet() {};
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

	bool h_flag;

	int enemy_num;

	float turn_time;

	int bullet_num;
};