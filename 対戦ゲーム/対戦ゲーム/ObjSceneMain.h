#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjSceneMain : public CObj
{
public:
	CObjSceneMain();
	~CObjSceneMain() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

	void GetVictory(int flag) { victory_flag = flag; }
private:

	int victory_flag;

	int m_p1;
	int m_p2;
	int con1_num;
	int con2_num;
};