//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
SceneMain::SceneMain(int p1_con,int p2_con)
{
	m_p1_con = p1_con;
	m_p2_con = p2_con;
}

//�f�X�g���N�^
SceneMain::~SceneMain()
{

}

//�Z���N�g�^�C�g�����������\�b�h
void SceneMain::InitScene()
{
	Draw::LoadImage(L"��.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"���{�b�N�X.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�X�e�[�W.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"HP�Q�[�W.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�u�[�X�g�Q�[�W.png", 5, TEX_SIZE_512);

	
	

	if (m_p1_con == 1)
	{
		CObjMain* m = new CObjMain(30.0f, 1.0f, 1);
		Objs::InsertObj(m, OBJ_MAIN, 5);
	}
	if (m_p2_con == 1)
	{
		CObjMain* m = new CObjMain(738.0f, 1.0f, 2);
		Objs::InsertObj(m, OBJ_MAIN, 5);
	}

	if (m_p1_con == 2)
	{
		CObjBalance* b = new CObjBalance(30.0f, 1.0f, 1);
		Objs::InsertObj(b, OBJ_BALANCE, 5);
	}
	if (m_p2_con == 2)
	{
		CObjBalance* b = new CObjBalance(738.0f, 1.0f, 2);
		Objs::InsertObj(b, OBJ_BALANCE, 5);
	}

	CObjSceneMain* sm = new CObjSceneMain();
	Objs::InsertObj(sm, OBJ_SCENE_MAIN, 1);
	
}

//�Q�[���^�C�g�����s���\�b�h
void SceneMain::Scene()
{

}