#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[���F�Q�[���^�C�g��
class SceneManual :public CScene
{
public:
	SceneManual(int p1_con, int p2_con);
	~SceneManual();
	void InitScene(); //�Q�[���^�C�g���̏��������\�b�h
	void Scene();     //�Q�[���^�C�g���̎��s�����\�b�h

private:

	int m_p1_con;
	int m_p2_con;

};