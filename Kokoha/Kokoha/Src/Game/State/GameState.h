#pragma once


#include <Siv3D.hpp>
#include "../../Scene.h"


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

		/// <summary>
		/// �V�[���J�ڂɂ���
		/// </summary>
		/// <returns>
		/// �J�ڂ��Ȃ��Ƃ� none
		/// �J�ڂ���Ƃ�   SceneName
		/// </returns>
		virtual Optional<SceneName> isChangeAbleScene() const
		{
			return none;
		}

	};

	using GameStatePtr = std::unique_ptr<GameState>;
}