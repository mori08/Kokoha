#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	GoalLight�N���X
	�S�[�����Ƃ炷��
	*/
	class GoalLight : public GameLight
	{
	private:

		// true �̂Ƃ����[�g�ē��p�̌��𐶐�����
		bool mIsRooting;

		// �ē��p�̌����o���܂ł̎���
		double mRootingSecond;

	public:

		/// <summary>
		/// �S�[�����Ƃ炷���C�g
		/// </summary>
		/// <param name="radius"     > ���a               </param>
		/// <param name="eraseSecond"> �폜���鎞��       </param>
		/// <param name="isRooting"  > ���[�g�ē������邩 </param>
		GoalLight(double radius, double eraseSecond, bool isRooting);

	private:

		void update()override;

		void checkAnother(const GameObject& another)override;

	};
}