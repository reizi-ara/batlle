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
	Draw::LoadImage(L"画像/白.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"画像/白ボックス.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"画像/ステージ.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"画像/HPゲージ.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"画像/ブーストゲージ.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"画像/白防御.png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"画像/ブースト.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"画像/コントローラー.png", 8, TEX_SIZE_512);
	Audio::LoadAudio(1, L"BGM/セレクト.wav", BACK_MUSIC);
	Audio::LoadAudio(8, L"BGM/戦闘シーン.wav", BACK_MUSIC);
	Audio::LoadAudio(2, L"SE/銃.wav", EFFECT);
	Audio::LoadAudio(3, L"SE/爆発.wav", EFFECT);
	Audio::LoadAudio(4, L"SE/被弾.wav", EFFECT);
	Audio::LoadAudio(5, L"SE/浮遊.wav", EFFECT);
	Audio::LoadAudio(6, L"SE/砲撃.wav", EFFECT);
	Audio::LoadAudio(7, L"SE/防御.wav", EFFECT);



	
	

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

//ゲームタイトル実行メソッド
void SceneMain::Scene()
{

}