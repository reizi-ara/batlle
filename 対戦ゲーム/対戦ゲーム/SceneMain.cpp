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
	Draw::LoadImage(L"白ボックス.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"ステージ.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"HPゲージ.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"ブーストゲージ.png", 5, TEX_SIZE_512);

	CObjMain* m = new CObjMain(30.0f, 1.0f);
	Objs::InsertObj(m, OBJ_MAIN, 1);
	CObjBalance* b = new CObjBalance(738.0f, 1.0f);
	Objs::InsertObj(b, OBJ_BALANCE, 1);
	CObjSceneMain* sm = new CObjSceneMain();
	Objs::InsertObj(sm, OBJ_SCENE_MAIN, 1);
}

//ゲームタイトル実行メソッド
void SceneMain::Scene()
{

}