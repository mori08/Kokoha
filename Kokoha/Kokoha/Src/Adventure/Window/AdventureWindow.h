#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	AdventureWindow�N���X
	AdventureManager�ŕ\������E�B���h�E
	��ԏ�ɗ��� -> �I��
	*/
	class AdventureWindow
	{
	protected:

		// �E�B���h�E�w�i
		const RoundRect mWindowBoard;

	public:

		/// <summary>
		/// �E�B���h�E
		/// </summary>
		/// <param name="region"> �E�B���h�E�͈̔� </param>
		AdventureWindow(const Rect& region);

		/// <summary>
		/// �I���������̏���
		/// </summary>
		virtual void select() = 0;

		/// <summary>
		/// �X�V
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// �I�����̍X�V
		/// </summary>
		virtual void selectedUpdate() = 0;

		/// <summary>
		/// �`��
		/// </summary>
		virtual void draw() const = 0;

	protected:

		/// <summary>
		/// �E�B���h�E�w�i�̕`��
		/// </summary>
		void drawBoard() const;

	};

	using WindowPtr = std::unique_ptr<AdventureWindow>;
}