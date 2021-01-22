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
SceneMain::SceneMain()
{

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

	CObjMain* m = new CObjMain(30.0f, 1.0f);
	Objs::InsertObj(m, OBJ_MAIN, 1);
	CObjBalance* b = new CObjBalance(738.0f, 1.0f);
	Objs::InsertObj(b, OBJ_BALANCE, 1);
	CObjSceneMain* sm = new CObjSceneMain();
	Objs::InsertObj(sm, OBJ_SCENE_MAIN, 1);
}

//�Q�[���^�C�g�����s���\�b�h
void SceneMain::Scene()
{

}