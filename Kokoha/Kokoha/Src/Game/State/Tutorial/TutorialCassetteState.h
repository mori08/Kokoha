#pragma once


#include "TutorialState.h"


namespace Kokoha
{
	/*
	TutorialCassetteState�N���X
	�J�Z�b�g�ύX�̐���
	*/
	class TutorialCassetteState : public TutorialState
	{
	private:

		// �����ύX��
		int32 mEquipmentChangeCount;

	public:

		TutorialCassetteState();

	private:

		void update() override;

		void draw() const override;

	};
}