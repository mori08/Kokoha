#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	AccessState�N���X
	�J�n�O�̉��o
	*/
	class AccessState : public GameState
	{
	private:

		// �o�ߎ���(s)
		double mTimeSecond;

		// �A���t�@�l
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