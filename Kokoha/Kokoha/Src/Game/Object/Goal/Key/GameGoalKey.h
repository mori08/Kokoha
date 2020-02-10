#pragma once


#include "../../GameObject.h"


namespace Kokoha
{
	/*
	GameGoalKeyクラス
	ゴールを開ける鍵
	*/
	class GameGoalKey : public GameObject
	{
	private:

		// プレイヤーに接触 true
		bool mIsChecked;

		// ゴールを変更する時間
		double mChangeGoalSecond;

		// 目的座標
		Vec2 mGoal;

	public:

		GameGoalKey(const Vec2& pos);

		virtual void update();

		void draw() const;

		void checkAnother(const GameObject& another);

		/// <summary>
		/// プレイヤーに接触済みだと true
		/// </summary>
		bool isChecked() const
		{
			return mIsChecked;
		}

	private:

		void changeGoal();

	};
}