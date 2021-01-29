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
SceneMain::SceneMain(int p1_con,int p2_con)
{
	m_p1_con = p1_con;
	m_p2_con = p2_con;
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

	
	

	if (m_p1_con == 1)
	{
		CObjMain* m = new CObjMain(30.0f, 1.0f, 1);
		Objs::InsertObj(m, OBJ_MAIN, 5);
	}
	if (m_p2_con == 1)
	{
		CObjMain* m = new CObjMain(738.0f, 1.0f, 2);
		Objs::InsertObj(m, OBJ_MAIN, 5);
	}

	if (m_p1_con == 2)
	{
		CObjBalance* b = new CObjBalance(30.0f, 1.0f, 1);
		Objs::InsertObj(b, OBJ_BALANCE, 5);
	}
	if (m_p2_con == 2)
	{
		CObjBalance* b = new CObjBalance(738.0f, 1.0f, 2);
		Objs::InsertObj(b, OBJ_BALANCE, 5);
	}

	CObjSceneMain* sm = new CObjSceneMain();
	Objs::InsertObj(sm, OBJ_SCENE_MAIN, 1);
	
}

//ゲームタイトル実行メソッド
void SceneMain::Scene()
{

}