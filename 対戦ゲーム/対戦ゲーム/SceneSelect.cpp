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
#include "SceneSelect.h"
#include "GameHead.h"

//コンストラクタ
SceneSelect::SceneSelect()
{

}

//デストラクタ
SceneSelect::~SceneSelect()
{

}

//セレクトタイトル初期化メソッド
void SceneSelect::InitScene()
{
	Draw::LoadImage(L"白.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"白ボックス.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"ステージ.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"HPゲージ.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"ブーストゲージ.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"セレクトカーソル.png", 5, TEX_SIZE_512);

	CObjSceneSelect* ss = new CObjSceneSelect();
	Objs::InsertObj(ss, OBJ_SCENE_SELECT, 1);
}

//ゲームタイトル実行メソッド
void SceneSelect::Scene()
{

}