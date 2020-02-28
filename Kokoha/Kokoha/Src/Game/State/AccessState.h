#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	AccessStateクラス
	開始前の演出
	*/
	class AccessState : public GameState
	{
	private:

		// 経過時間(s)
		double mTimeSecond;

		// アルファ値
		double mAlpha;

		static std::unordered_map<String, String> sRobotIconMap;

	public:

		AccessState();

	private:

		void update() override;

		void draw() const override;

	public:

		static void setRobotIcon();

	};
}