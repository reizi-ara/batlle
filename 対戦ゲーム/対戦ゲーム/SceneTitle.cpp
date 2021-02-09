//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneTitle.h"
#include "GameHead.h"

//コンストラクタ
SceneTitle::SceneTitle()
{

}

//デストラクタ
SceneTitle::~SceneTitle()
{

}

//セレクトタイトル初期化メソッド
void SceneTitle::InitScene()
{
	Draw::LoadImage(L"画像/白.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"画像/白ボックス.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"画像/ステージ.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"画像/HPゲージ.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"画像/ブーストゲージ.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"画像/セレクトカーソル.png", 5, TEX_SIZE_512);
	Audio::LoadAudio(1, L"BGM/タイトル.wav", BACK_MUSIC);

	CObjSceneTitle* t = new CObjSceneTitle();
	Objs::InsertObj(t, OBJ_SCENE_TITLE, 1);

	Audio::Start(1);
	Audio::Volume(-0.7f, 1);
}

//ゲームタイトル実行メソッド
void SceneTitle::Scene()
{

}