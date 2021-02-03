#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjAttack : public CObj
{
public:
	CObjAttack(float x, float y, bool f, float c, int con_num, int num);
	~CObjAttack() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	void GetPoint() { gurd_point++; }
	int GetNUM() { return char_num; }
private:

	float m_px;
	float m_py;

	float m_vx;
	float m_vy;

	bool turn_flag;

	float color;

	int m_con_num;

	int gurd_point;

	int char_num;

	int m_hp;
};