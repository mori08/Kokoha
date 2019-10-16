#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	TextEvent�N���X
	�e�L�X�g�{�b�N�X�Ƀe�L�X�g�Ȃǂ�ݒ�
	*/
	class TextEvent : public Event
	{
	private:

		// �b����̖��O
		String mSpeakerName;

		// �A�C�R����
		String mIconName;

		// 1�����\�����鎞��
		double mSpanSecond;

		// �e�L�X�g
		String mText;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}