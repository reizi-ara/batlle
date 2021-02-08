#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:タイトル
class CObjBreak : public CObj
{
public:
	CObjBreak(float x, float y, int p_con, int enemy);
	~CObjBreak() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

	float GetPX() { return m_px; }
	float GetPY() { return m_py; }

	bool GetGurd() { return gurd_flag; }

	void GetDamege(int dam)
	{
			hp -= dam;
	}
	void GetVX(float x)
	{
		m_px += x;
	}
	void GetJump() { m_jump_num = 50; }

	bool GetBreak() { return break_flag; }
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

	bool sub_bullet_flag;

	int hp;

	bool gurd_flag;

	int breaktime;

	int sub_R;

	int sub_R_time;

	int main_R;
	int main_R_time;

	int m_p_con;

	bool gurd_time;

	int enemy_num;

	bool break_flag;

	bool bust_draw_flag;
};