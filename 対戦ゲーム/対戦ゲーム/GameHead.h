#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_MAIN,
	OBJ_BALANCE,
	OBJ_NORMAL_BULLET,
	OBJ_FAST_BULLET,
	OBJ_SCENE_MAIN,
	OBJ_SCENE_SELECT,
	OBJ_ATTACK,
	OBJ_BREAK,
	OBJ_BREAK_BULLET,
	OBJ_SCENE_TITLE,
	OBJ_SCENE_MANUAL,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_PLAYER2,
	ELEMENT_PLAYER3,
	ELEMENT_FAST_BULLET,
	ELEMENT_BREAK_BULLET,
	ELEMENT_NORMAL_BULLET,
	ELEMENT_ATTACK1,
	ELEMENT_ATTACK2,
	ELEMENT_ATTACK3,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include"ObjMain.h"
#include"NormalBullet.h"
#include"ObjBalance.h"
#include"FastBullet.h"
#include"Attack.h"
#include"ObjSceneMain.h"
#include"ObjSceneSelect.h"
#include"BreakBullet.h"
#include"ObjBreak.h"
#include"ObjSceneTitle.h"
#include"ObjSceneManual.h"
//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
#include"SceneSelect.h"
#include"SceneTitle.h"
#include"SceneManual.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START SceneTitle  
//-----------------------------------------------