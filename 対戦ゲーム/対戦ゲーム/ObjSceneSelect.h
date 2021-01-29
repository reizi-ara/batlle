#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjSceneSelect : public CObj
{
public:
	CObjSceneSelect() {};
	~CObjSceneSelect() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:

	float m_p1_px;
	float m_p1_py;
	float m_p1_vx;
	float m_p1_vy;
	float m_p2_px;
	float m_p2_py;
	float m_p2_vx;
	float m_p2_vy;

	int m_p1_con_num;
	int m_p2_con_num;

	int m_p1_con;
	int m_p2_con;

	bool m_p1_battle_flag;
	bool m_p2_battle_flag;
};