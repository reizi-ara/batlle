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
#include "SceneTitle.h"
#include "GameHead.h"

//�R���X�g���N�^
SceneTitle::SceneTitle()
{

}

//�f�X�g���N�^
SceneTitle::~SceneTitle()
{

}

//�Z���N�g�^�C�g�����������\�b�h
void SceneTitle::InitScene()
{
	Draw::LoadImage(L"�摜/��.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/���{�b�N�X.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�X�e�[�W.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/HP�Q�[�W.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�u�[�X�g�Q�[�W.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�Z���N�g�J�[�\��.png", 5, TEX_SIZE_512);
	Audio::LoadAudio(1, L"BGM/�^�C�g��.wav", BACK_MUSIC);

	CObjSceneTitle* t = new CObjSceneTitle();
	Objs::InsertObj(t, OBJ_SCENE_TITLE, 1);

	Audio::Start(1);
	Audio::Volume(-0.7f, 1);
}

//�Q�[���^�C�g�����s���\�b�h
void SceneTitle::Scene()
{

}