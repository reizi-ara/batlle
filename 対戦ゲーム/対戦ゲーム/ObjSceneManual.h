#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjSceneManual : public CObj
{
public:
	CObjSceneManual(int con_1_num, int con_2_num);
	~CObjSceneManual() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	int con1_num;
	int con2_num;

	int m_time;

	int m_p1_num;
	int m_p2_num;
};