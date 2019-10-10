#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	Linear�N���X
	���double��Vec2�Ȃǂ̏����l�ň���
	���`�I�ɒl��ύX����
	*/
	template<typename Type>
	class Linearly
	{
	private:

		// ���b�Œl��ύX���邩
		const double mTimeSecond;

		// { �n�_, �I�_-�n�_ }
		const std::pair<Type, Type> mValue;

		// ������ [0,1]
		double mRate;

	public:

		/// <summary>
		/// ���`�⊮
		/// </summary>
		/// <param name="timeSecond"> ���b�Œl��ύX���邩 </param>
		/// <param name="value">      { �n�_, �I�_-�n�_ }  </param>
		Linearly(double timeSecond, const std::pair<Type, Type> value)
			: mTimeSecond(timeSecond)
			, mValue(value)
			, mRate(0)
		{
		}

		/// <summary>
		/// �X�V
		/// </summary>
		/// <returns>
		/// �����䂪 1 �𒴂����� true, �����łȂ��Ƃ� false
		/// </returns>
		bool update();

		/// <summary>
		/// �l�̎擾
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