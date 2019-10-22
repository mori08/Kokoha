#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	InfoWindow�N���X
	�e�L�X�g��\��
	*/
	class InfoWindow : public AdventureWindow
	{
	private:

		// �e�L�X�g
		String mText;

	public:

		/// <summary>
		/// �e�L�X�g��\������E�B���h�E
		/// </summary>
		InfoWindow(const String& text);

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};

}
