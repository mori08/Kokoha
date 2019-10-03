#pragma once


#include "InputState.h"


namespace Kokoha
{
	/*
	InputManager�N���X
	�}�E�X�E�L�[�{�[�h�̓��͂̐؂�ւ����s��,
	����,�L�����Z���̓��͂��m�F���܂�.
	*/
	class InputManager
	{
	private:

		// ���͕��@�ɂ��Ă̏��
		std::unique_ptr<InputState> mInputState;

	private:

		InputManager();

		InputManager(const InputManager&)            = default;
		InputManager& operator=(const InputManager&) = default;
		InputManager(InputManager&&)                 = default;
		InputManager& operator=(InputManager&&)      = default;

	public:

		/// <summary>
		/// �V���O���g���Ƃ��ĊǗ����Ă���InputManager�̃C���X�^���X�̎擾
		/// </summary>
		/// <returns>
		/// �C���X�^���X
		/// </returns>
		static InputManager& instatnce();

		/// <summary>
		/// ����̓���
		/// </summary>
		/// <returns>
		/// ���͂��ꂽ�� true , �����łȂ��Ƃ� false
		/// </returns>
		bool decision() const;

		/// <summary>
		/// �L�����Z���̓���
		/// </summary>
		/// <returns>
		/// ���͂��ꂽ�� true , �����łȂ��Ƃ� false
		/// </returns>
		bool cancel() const;

		/// <summary>
		/// ���͂̏�Ԃ�ύX���܂�
		/// </summary>
		/// <remarks>
		/// ���[�v�̍ŏ��Ŏg�p
		/// 1���[�v��1�x����
		/// </remarks>
		void changeInputState();

	};
}