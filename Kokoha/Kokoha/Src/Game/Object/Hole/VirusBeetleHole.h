#pragma once


#include "GameHole.h"


namespace Kokoha
{
	/*
	VirusBeetleHole�N���X
	�����ɓ���
	�s�������Ƃ̂Ȃ��אڃ}�X��D��I�ɖK�₷��
	*/
	class VirusBeetleHole : public GameHole
	{
	private:

		// ���݂���}�X
		Point mNowSquare;

		// ��O�ɂ����}�X
		Point mPreSquare;

		// �K��񐔂��L�^
		static Array<int32> mVisitedCount;

	public:

		VirusBeetleHole(const Vec2& pos);

	private:

		void update() override;

	};
}