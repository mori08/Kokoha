#pragma once


#include "../GameState.h"


namespace Kokoha
{
	/*
	TutorialStateクラス
	チュートリアルの状態の基底
	*/
	class TutorialState : public GameState
	{
	protected:

		// 目的に関するセリフ
		const String mMissionText;

		// 操作方法
		const String mControlText;

		// 経過時間
		double mTimeSecond;

		// 達成率
		double mAchieveRate;

	public:

		/// <summary>
		/// チュートリアル
		/// </summary>
		/// <param name="misson" > 目的 </param>
		/// <param name="control"> 操作 </param> 
		TutorialState(const String& mission, const String& control);

	protected:

		virtual void update() override;

		virtual void draw() const override;

		/// <summary>
		/// 達成率の更新
		/// </summary>
		/// <param name="value"> 更新する値 </param>
		void updateAchieveRate(double value);

	};
}