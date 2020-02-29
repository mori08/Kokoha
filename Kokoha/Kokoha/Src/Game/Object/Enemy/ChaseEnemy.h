#pragma once


#include "GameEnemy.h"


namespace
{
	// プレイヤーを追いかける速さ
	constexpr double CHASE_SPEED = 0.8;
}


namespace Kokoha
{
	/*
	ChaseEnemyクラス
	プレイヤーを追跡する敵オブジェクト
	*/
	template<typename BaseType>
	class ChaseEnemy : public BaseType
	{
	private:

		// ゴール
		Vec2 mGoal;

		// 追いかける速さ
		const double mSpeed;

	public:

		ChaseEnemy(const Vec2& pos);

	private:

		void update() override;

		void checkAnother(const GameObject& another) override;

	};


	template<typename BaseType>
	inline ChaseEnemy<BaseType>::ChaseEnemy(const Vec2& pos)
		: BaseType(pos)
		, mGoal(pos)
		, mSpeed(CHASE_SPEED)
	{
	}


	template<typename BaseType>
	inline void ChaseEnemy<BaseType>::update()
	{
		BaseType::update();
		this->walkToGoal(mSpeed, mGoal);
	}


	template<typename BaseType>
	inline void ChaseEnemy<BaseType>::checkAnother(const GameObject& another)
	{
		GameEnemy::checkAnother(another);

		if (auto goal = another.checkTypeAndGetPos(ObjectType::PLAYER))
		{
			mGoal = goal.value();
		}
	}
}