#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	GameState�N���X
	GameManager�ł̏�Ԃ�����
	�h���N���X������ď�ԑJ�ڂ���
	*/
	class GameState
	{
	public:

		/// <summary>
		/// �X�V
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// �`��
		/// </summary>
		virtual void draw() const = 0;

	};

	using GameStatePtr = std::unique_ptr<GameState>;
}