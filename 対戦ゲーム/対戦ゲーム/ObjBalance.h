#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjBalance : public CObj
{
public:
	CObjBalance(float x, float y,int p_con);
	~CObjBalance() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

	float GetPX() { return m_px; }
	float GetPY() { return m_py; }

	bool GetGurd() { return gurd_flag; }


	void GetDamege(int dam)
	{
		if (gurd_flag == false)
			hp -= dam;
	}
	void GetVX(float x)
	{
		m_px += x;
	}

	void GetJump() { m_jump_num = 500; }
private:

	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	bool flag;

	int con_num;

	bool m_hit_down;

	int m_jump_num;

	bool button_flag;

	bool turn_flag;//trueが左、falseが右

	bool bullet_flag;

	int hp;

	bool gurd_flag;

	int breaktime;

	bool boost_flag;

	int sub_R;
	int sub_R_time;

	int main_R;
	int main_R_time;

	int m_p_con;

	bool gurd_time;
};