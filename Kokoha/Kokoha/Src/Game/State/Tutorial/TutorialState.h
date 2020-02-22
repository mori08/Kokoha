#pragma once


#include "../GameState.h"


namespace Kokoha
{
	/*
	TutorialState�N���X
	�`���[�g���A���̏�Ԃ̊��
	*/
	class TutorialState : public GameState
	{
	protected:

		// �ړI�Ɋւ���Z���t
		const String mMissionText;

		// ������@
		const String mControlText;

		// �o�ߎ���
		double mTimeSecond;

		// �B����
		double mAchieveRate;

	public:

		/// <summary>
		/// �`���[�g���A��
		/// </summary>
		/// <param name="misson" > �ړI </param>
		/// <param name="control"> ���� </param> 
		TutorialState(const String& mission, const String& control);

	protected:

		virtual void update() override;

		virtual void draw() const override;

		/// <summary>
		/// �B�����̍X�V
		/// </summary>
		/// <param name="value"> �X�V����l </param>
		void updateAchieveRate(double value);

	};
}