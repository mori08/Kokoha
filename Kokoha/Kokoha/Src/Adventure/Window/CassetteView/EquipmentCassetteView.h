#pragma once


#include "../../../Cassette/Cassette/Cassette.h"


namespace Kokoha
{
	/*
	EquipmentCassetteView�N���X
	SetUpWindow�ő������Ă���J�Z�b�g�̑���E�`��
	*/
	class EquipmentCassetteView
	{
	public:

		/// <summary>
		/// �{�^����ButtonManager�ɃZ�b�g
		/// </summary>
		void setButton()const;

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw() const;

	};
}