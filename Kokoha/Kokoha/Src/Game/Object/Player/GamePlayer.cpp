#include "GamePlayer.h"
#include "../../../MyColor.h"
#include "../../GameManager.h"


namespace
{
	// プレイヤーの当たり判定の範囲
	constexpr double BODY_RADIUS = 12.0;

	// 光をループさせる時間(秒)
	constexpr double LIGHT_LOOP_TIME = 2.0;
	// 光の厚さ
	constexpr double LIGHT_THICKNESS = 2.5;
	// 光の半径の最大値
	constexpr double LIGHT_RADIUS = 40.0;
	// 光の半径にかかる指数
	constexpr double RADIUS_POW = 0.3;
	// 光の不透明度にかかる指数
	constexpr double ALPHA_POW = 1.2;
}


Kokoha::GamePlayer::GamePlayer(const Vec2& pos)
	: GameObject(Circle(pos, BODY_RADIUS), ObjectType::PLAYER)
	, mLightRate(LIGHT_LOOP_TIME, 1.0)
{

}


void Kokoha::GamePlayer::update()
{
	// 移動
	Point direction = Point::Zero();
	if (KeyW.pressed()) { direction += Point::Up();    }
	if (KeyS.pressed()) { direction += Point::Down();  }
	if (KeyA.pressed()) { direction += Point::Left();  }
	if (KeyD.pressed()) { direction += Point::Right(); }
	walk(GameManager::instance().getPlayerSpeed() * direction);

	// 座標の設定
	GameManager::instance().setPlayerPos(mBody.center);

	// 光
	if (mLightRate.update()) { mLightRate.restart(); }
}


void Kokoha::GamePlayer::draw() const
{
	TextureAsset(U"Player").drawAt(mBody.center);
}


void Kokoha::GamePlayer::drawLight() const
{
	const double rate = mLightRate.getValue();

	const ColorF color(MyWhite, 1.0 - pow(rate, ALPHA_POW));

	const double radius = LIGHT_RADIUS * pow(rate, RADIUS_POW);

	Circle(mBody.center, radius).drawFrame(LIGHT_THICKNESS, color);
}

void Kokoha::GamePlayer::checkAnother(const GameObject&)
{
	/*
	TODO
	ゴールにあたるとクリア
	敵にあたるとゲームオーバー
	*/
}
