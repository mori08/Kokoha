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
		static InputManager& instatnce()
		{
			static InputManager inputManager;
			return inputManager;
		}

		/// <summary>
		/// ����̓���
		/// </summary>
		/// <returns>
		/// ���͂��ꂽ�� true , �����łȂ��Ƃ� false
		/// </returns>
		bool decision() const
		{
			return mInputState->decesion();
		}

		/// <summary>
		/// �L�����Z���̓���
		/// </summary>
		/// <returns>
		/// ���͂��ꂽ�� true , �����łȂ��Ƃ� false
		/// </returns>
		bool cancel() const
		{
			return mInputState->cancel();
		}

		/// <summary>
		/// �{�^����I��
		/// </summary>
		/// <param name="selectedButtonPtr"> �I�𒆂̃{�^�� </param>
		/// <param name="buttonPtrMap">      �{�^���̃��X�g </param>
		/// <returns> 
		/// ���肪���͂��ꂽ�Ƃ��ɂ��̃{�^���̃L�[��Ԃ��܂��B
		/// �����I������Ă��Ȃ��Ƃ������l��Ԃ��܂��B
		/// </returns>
		/// <remarks>
		/// ���͂ɉ������{�^���I���̕ύX���s���܂��B
		/// 1�t���[����2�x�ȏ�g�p���Ȃ��ł��������B
		/// �{�^�����o�^����Ă��Ȃ���ԂŎg�p���Ȃ��ł��������B
		/// </remarks>
		Optional<String> selectButton(ButtonPtr selectedButtonPtr, const ButtonPtrMap& buttonPtrMap) const
		{
			return mInputState->selectButton(selectedButtonPtr, buttonPtrMap);
		}

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