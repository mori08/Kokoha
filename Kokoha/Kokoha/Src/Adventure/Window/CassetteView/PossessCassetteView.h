#pragma once


#include "../../../Cassette/Cassette/Cassette.h"


namespace Kokoha
{
	/*
	CassetteView�N���X
	SetupWindow�Ŏ�Ɏg�p
	�J�Z�b�g�̈ꗗ������
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
