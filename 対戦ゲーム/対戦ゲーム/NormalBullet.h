#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjNormalBullet : public CObj
{
public:
	CObjNormalBullet(float x, float y,bool f,float c,int dam);
	~CObjNormalBullet() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	float m_px;
	float m_py;

	float m_vx;
	float m_vy;

	bool turn_flag;

	float color;

	int damage;
};