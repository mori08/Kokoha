#pragma once


#include "../../../Cassette/Cassette/Cassette.h"


namespace Kokoha
{
	/*
	PossessCassetteView�N���X
	SetupWindow�ŏ������Ă���J�Z�b�g�̑���E�`��
	*/
	class PossessCassetteView
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
