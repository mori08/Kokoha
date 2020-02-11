#pragma once


#include "../GameObject.h"
#include "../../../Slice/Linearly.h"


namespace Kokoha
{
	/*
	GameHole�N���X
	WhiteEnemy�𐶐�����I�u�W�F�N�g
	*/
	class GameHole : public GameObject
	{
	public:

		// �ւ̐�
		static const int32 RING_NUM = 2;

	protected:

		// �G�̐����Ԋu(s)
		Linearly<double> mGenerateSpan;

	private:

		// �ւ��Ȃ��p�x
		std::array<double, RING_NUM> mRingAngleList;

	public:

		/// <summary>
		/// �����G�𐶐�����I�u�W�F�N�g
		/// </summary>
		/// <param name="pos"> �������W </param>
		/// <param name="generateSpan"> �G�̐����Ԋu(s) </param>
		GameHole(const Vec2& pos, double generateSpan);

	protected:

		virtual void update() override;

		void draw() const override;

		void checkAnother(const GameObject&) override
		{
		}

	};
}