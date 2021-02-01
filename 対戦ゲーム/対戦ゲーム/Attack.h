#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjAttack : public CObj
{
public:
	CObjAttack(float x, float y, bool f, float c,int con_num);
	~CObjAttack() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

	void GetPoint() { gurd_point++; }
private:

	float m_px;
	float m_py;

	float m_vx;
	float m_vy;

	bool turn_flag;

	float color;

	int m_con_num;

	int gurd_point;

};