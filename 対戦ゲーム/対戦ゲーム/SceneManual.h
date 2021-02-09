#pragma once
//使用するヘッダーファイル
#include "GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームタイトル
class SceneManual :public CScene
{
public:
	SceneManual(int p1_con, int p2_con);
	~SceneManual();
	void InitScene(); //ゲームタイトルの初期化メソッド
	void Scene();     //ゲームタイトルの実行中メソッド

private:

	int m_p1_con;
	int m_p2_con;

};