#pragma once


#include "Button.h"


namespace Kokoha
{
	using ButtonPtrMap = std::unordered_map<String, ButtonPtr>;

	/*
	InputState�N���X
	ButtonManager�Ŏg�p������͂̏�Ԃ̊��
	*/
	class InputState
	{
	public:

		/// <summary>
		/// ����̓���
		/// </summary>
		/// <returns>
		/// ���͂��ꂽ�� true , �����łȂ��Ƃ� false </returns>
		/// </returns>
		virtual bool decesion() const = 0;

		/// <summary>
		/// �L�����Z���̓���
		/// </summary>
		/// <returns>
		/// ���͂��ꂽ�� true , �����łȂ��Ƃ� false </returns>
		virtual bool cancel() const = 0;

		/// <summary>
		/// �{�^����I�����܂��B
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
		virtual Optional<String> selectButton(ButtonPtr& selectedButtonPtr, const ButtonPtrMap& buttonPtrMap) const = 0;

	};
}