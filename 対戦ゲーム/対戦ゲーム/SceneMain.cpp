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

	CObjMain* m = new CObjMain(0.0f, 1.0f);
	Objs::InsertObj(m, OBJ_MAIN, 1);
	CObjBalance* b = new CObjBalance(768.0f, 1.0f);
	Objs::InsertObj(b, OBJ_BALANCE, 1);
}

//�Q�[���^�C�g�����s���\�b�h
void SceneMain::Scene()
{

}