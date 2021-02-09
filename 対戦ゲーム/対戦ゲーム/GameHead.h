#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
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

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
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
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
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

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include"SceneSelect.h"
#include"SceneTitle.h"
#include"SceneManual.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START SceneTitle  
//-----------------------------------------------