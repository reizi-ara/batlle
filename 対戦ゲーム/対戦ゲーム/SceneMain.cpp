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
	Draw::LoadImage(L"�摜/��.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/���{�b�N�X.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�X�e�[�W.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/HP�Q�[�W.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�u�[�X�g�Q�[�W.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/���h��.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�u�[�X�g.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"�摜/�R���g���[���[.png", 8, TEX_SIZE_512);
	Audio::LoadAudio(1, L"BGM/�Z���N�g.wav", BACK_MUSIC);
	Audio::LoadAudio(8, L"BGM/�퓬�V�[��.wav", BACK_MUSIC);
	Audio::LoadAudio(2, L"SE/�e.wav", EFFECT);
	Audio::LoadAudio(3, L"SE/����.wav", EFFECT);
	Audio::LoadAudio(4, L"SE/��e.wav", EFFECT);
	Audio::LoadAudio(5, L"SE/���V.wav", EFFECT);
	Audio::LoadAudio(6, L"SE/�C��.wav", EFFECT);
	Audio::LoadAudio(7, L"SE/�h��.wav", EFFECT);



	
	

	if (m_p1_con == 1)
	{
		CObjMain* m = new CObjMain(30.0f, 1.0f, 1, m_p2_con);
		Objs::InsertObj(m, OBJ_MAIN, 5);
	}
	if (m_p2_con == 1)
	{
		CObjMain* m = new CObjMain(738.0f, 1.0f, 2, m_p1_con);
		Objs::InsertObj(m, OBJ_MAIN, 5);
	}

	if (m_p1_con == 2)
	{
		CObjBalance* b = new CObjBalance(30.0f, 1.0f, 1, m_p2_con);
		Objs::InsertObj(b, OBJ_BALANCE, 5);
		
	}
	if (m_p2_con == 2)
	{
		CObjBalance* b = new CObjBalance(738.0f, 1.0f, 2, m_p1_con);
		Objs::InsertObj(b, OBJ_BALANCE, 5);
		
	}
	if (m_p1_con == 3)
	{
		
		CObjBreak* bb = new CObjBreak(30.0f, 1.0f, 1, m_p2_con);
		Objs::InsertObj(bb, OBJ_BREAK, 5);
	}
	if (m_p2_con == 3)
	{
		
		CObjBreak* bb = new CObjBreak(738.0f, 1.0f, 2, m_p1_con);
		Objs::InsertObj(bb, OBJ_BREAK, 5);
	}

	/*CObjBreak* bb = new CObjBreak(738.0f, 1.0f, 2);
	Objs::InsertObj(bb, OBJ_BREAK, 5);*/

	CObjSceneMain* sm = new CObjSceneMain();
	Objs::InsertObj(sm, OBJ_SCENE_MAIN, 1);

	//Audio::Init(0.1f);
	//Audio::VolumeMaster(0.01f);

	
	Audio::Start(8);
	Audio::Volume(-0.4f, 2);
	Audio::Volume(-0.2f, 4);
	Audio::Volume(-0.8f, 8);
	Audio::Volume(-0.9f, 3);
	Audio::Volume(-0.5f, 5);
	Audio::Volume(-0.7f, 7);
	
}

//�Q�[���^�C�g�����s���\�b�h
void SceneMain::Scene()
{

}