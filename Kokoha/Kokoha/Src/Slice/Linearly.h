#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	Linearクラス
	主にdoubleやVec2などの小数値で扱う
	線形的に値を変更する
	*/
	template<typename Type>
	class Linearly
	{
	private:

		// 何秒で値を変更するか
		const double mTimeSecond;

		// { 始点, 終点-始点 }
		const std::pair<Type, Type> mValue;

		// 内分比 [0,1]
		double mRate;

	public:

		/// <summary>
		/// 線形補完
		/// </summary>
		/// <param name="timeSecond"> 何秒で値を変更するか </param>
		/// <param name="value">      { 始点, 終点-始点 }  </param>
		Linearly(double timeSecond, const std::pair<Type, Type> value)
			: mTimeSecond(timeSecond)
			, mValue(value)
			, mRate(0)
		{
		}

		/// <summary>
		/// 更新
		/// </summary>
		/// <returns>
		/// 内分比が 1 を超えたら true, そうでないとき false
		/// </returns>
		bool update();

		/// <summary>
		/// 値の取得
		/// </summary>
		Type getValue() const
		{
			return mValue.first + mRate * mValue.second;
		}

	};


	template<typename Type>
	inline bool Linearly<Type>::update()
	{
		mRate += Scene::DeltaTime() / mTimeSecond;
		
		if (mRate > 1)
		{
			mRate = 1;
			return true;
		}

		return false;
	}

}