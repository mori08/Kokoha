#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	// �C�x���g�̈���
	using EventArg = std::vector<String>;

	/*
	Event�N���X
	csv�t�@�C������C�x���g��ǂݍ��񂾂Ƃ�
	����1�s�������̃N���X�ɑΉ�����
	�C�x���g�̎�ނ��Ƃɂ��̃N���X�̔h���N���X���쐬����

	���̃N���X�̔h���N���X�����Ƃ���
	EventManager��setAllEvent�֐��ɓo�^����
	*/
	class Event
	{
	public:

		/// <summary>
		/// ������̔z����󂯎��A�C�x���g�̏ڍׂ�����
		/// </summary>
		/// <param name="eventArg"> ������̔z�� </param>
		/// <returns> ����������ł����Ƃ� true , �����łȂ��Ƃ� false </returns>
		virtual bool load(const EventArg& eventArg) = 0;

		/// <summary>
		/// �C�x���g�̎��s
		/// </summary>
		virtual void perform() const = 0;

		/// <summary>
		/// �I�����Ă��邩����.
		/// </summary>
		/// <returns> �I�����Ă���Ƃ� true , �����łȂ��Ƃ� false </returns>
		virtual bool isCompleted() const = 0;

	};
}