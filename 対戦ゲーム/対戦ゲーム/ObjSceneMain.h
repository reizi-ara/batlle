#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�^�C�g��
class CObjSceneMain : public CObj
{
public:
	CObjSceneMain();
	~CObjSceneMain() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

	void GetVictory(int flag) { victory_flag = flag; }
private:

	int victory_flag;

	int m_p1;
	int m_p2;
	int con1_num;
	int con2_num;
};