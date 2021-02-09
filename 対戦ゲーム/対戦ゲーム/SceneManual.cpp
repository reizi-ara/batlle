//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneManual.h"
#include "GameHead.h"

//�R���X�g���N�^
SceneManual::SceneManual(int p1_con, int p2_con)
{
	m_p1_con = p1_con;
	m_p2_con = p2_con;
}

//�f�X�g���N�^
SceneManual::~SceneManual()
{

}

//�Z���N�g�^�C�g�����������\�b�h
void SceneManual::InitScene()
{
	Draw::LoadImage(L"�摜/�R���g���[���[.png", 1, TEX_SIZE_512);

	CObjSceneManual* m = new CObjSceneManual(m_p1_con, m_p2_con);
	Objs::InsertObj(m, OBJ_SCENE_MANUAL, 1);
}

//�Q�[���^�C�g�����s���\�b�h
void SceneManual::Scene()
{

}