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
#include "SceneManual.h"
#include "GameHead.h"

//コンストラクタ
SceneManual::SceneManual(int p1_con, int p2_con)
{
	m_p1_con = p1_con;
	m_p2_con = p2_con;
}

//デストラクタ
SceneManual::~SceneManual()
{

}

//セレクトタイトル初期化メソッド
void SceneManual::InitScene()
{
	Draw::LoadImage(L"画像/コントローラー.png", 1, TEX_SIZE_512);

	CObjSceneManual* m = new CObjSceneManual(m_p1_con, m_p2_con);
	Objs::InsertObj(m, OBJ_SCENE_MANUAL, 1);
}

//ゲームタイトル実行メソッド
void SceneManual::Scene()
{

}