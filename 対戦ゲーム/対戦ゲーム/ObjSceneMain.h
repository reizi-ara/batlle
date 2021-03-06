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

	void GetVictory(int flag) 
	{ 
		if (victory_flag == 0)
			victory_flag = flag;
	}

	bool GetBattle() { return Battle_flag; }

private:

	int victory_flag;

	int m_p1;
	int m_p2;
	int con1_num;
	int con2_num;

	bool Battle_flag;

	int m_time;
};