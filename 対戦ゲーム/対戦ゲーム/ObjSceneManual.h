#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjSceneManual : public CObj
{
public:
	CObjSceneManual(int con_1_num, int con_2_num);
	~CObjSceneManual() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:
	int con1_num;
	int con2_num;

	int m_time;

	int m_p1_num;
	int m_p2_num;
};