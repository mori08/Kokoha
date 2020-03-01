#pragma once


#include "EventObject.h"


namespace Kokoha
{
	/*
	EventEffect�N���X
	�Ó]��m�C�Y���o���s��EventObject
	*/
	class EventEffect : public EventObject
	{
	private:

		// true�̂Ƃ��m�C�Y
		bool mNoise;

		// true�̂Ƃ��Ó]
		bool mDark;

		// �Ó]���̃A���t�@�l
		double mDarkAlpha;

	public:

		EventEffect(const Point& pos);

	public:

		void update() override;

		void draw(const Point& cameraPos) const override;

		void changeNoise()
		{
			mNoise = !mNoise;
		}

		void changeDark()
		{
			mDark = !mDark;
		}

	};
}