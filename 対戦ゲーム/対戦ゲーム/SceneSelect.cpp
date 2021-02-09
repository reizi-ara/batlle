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
#include "SceneSelect.h"
#include "GameHead.h"

//�R���X�g���N�^
SceneSelect::SceneSelect()
{

}

//�f�X�g���N�^
SceneSelect::~SceneSelect()
{

}

//�Z���N�g�^�C�g�����������\�b�h
void SceneSelect::InitScene()
{
	Draw::LoadImage(L"�摜/��.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/���{�b�N�X.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�X�e�[�W.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/HP�Q�[�W.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�u�[�X�g�Q�[�W.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�Z���N�g�J�[�\��.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�R���g���[���[.png", 8, TEX_SIZE_512);
	Audio::LoadAudio(1, L"BGM/�Z���N�g.wav", BACK_MUSIC);

	CObjSceneSelect* ss = new CObjSceneSelect();
	Objs::InsertObj(ss, OBJ_SCENE_SELECT, 1);

	Audio::Start(1);
}

//�Q�[���^�C�g�����s���\�b�h
void SceneSelect::Scene()
{

}