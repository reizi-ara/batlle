//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/DrawFont.h"
#include"GameL/HitBoxManager.h"

#include "Attack.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

CObjAttack::CObjAttack(float x, float y, bool f, float c)
{
	m_px = x;
	m_py = y;

	turn_flag = f;

	color = c;

}

//イニシャライズ
void CObjAttack::Init()
{
	
}

//アクション
void CObjAttack::Action()
{
	
}

//ドロー
void CObjAttack::Draw()
{
	float c[4] = { 1.0f,color,color,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = 8.0f + m_px;
	dst.m_bottom = 8.0f + m_py;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}