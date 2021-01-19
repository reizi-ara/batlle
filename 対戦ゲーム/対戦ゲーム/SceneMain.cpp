//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
SceneMain::SceneMain()
{

}

//デストラクタ
SceneMain::~SceneMain()
{

}

//セレクトタイトル初期化メソッド
void SceneMain::InitScene()
{
	Draw::LoadImage(L"白.png", 1, TEX_SIZE_512);

	CObjMain* m = new CObjMain(0.0f, 1.0f);
	Objs::InsertObj(m, OBJ_MAIN, 1);
	CObjBalance* b = new CObjBalance(768.0f, 1.0f);
	Objs::InsertObj(b, OBJ_BALANCE, 1);
}

//ゲームタイトル実行メソッド
void SceneMain::Scene()
{

}