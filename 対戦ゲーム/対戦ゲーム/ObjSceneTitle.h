#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjSceneTitle : public CObj
{
public:
	CObjSceneTitle() {};
	~CObjSceneTitle() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	
	int m_p1_con_num;
	int m_p2_con_num;

};