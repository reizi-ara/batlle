#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjBreakBullet : public CObj
{
public:
	CObjBreakBullet(float x, float y, bool f, float c, int dam, bool break_flag,int i,int enemy);
	~CObjBreakBullet() {};
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

	bool m_break_flag;

	int break_time;

	int line_flag;

	float turn_time;

	int enemy_num;
};