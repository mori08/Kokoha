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
	EventManager�̃R���X�g���N�^�ɓo�^����
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
		virtual void perform() = 0;

		/// <summary>
		/// �I�����Ă��邩����.
		/// </summary>
		/// <returns> �I�����Ă���Ƃ� true , �����łȂ��Ƃ� false </returns>
		virtual bool isCompleted() const = 0;


	protected: // load�֐��ł̃G���[�m�F

		/// <summary>
		/// �����̃T�C�Y�̊m�F
		/// </summary>
		/// <param name="argSize">       �����̃T�C�Y </param>
		/// <param name="expectedValue"> ���Ғl       </param>
		/// <returns>
		/// �������Ƃ� true , �����łȂ��Ƃ� false
		/// </returns>
		static bool checkArgSize(size_t argSize, size_t expectedValue);

		/// <summary>
		/// �����񂩂��l�ւ̕ϊ�
		/// </summary>
		/// <param name="integer"> �ϊ���̓�l�̑���� </param>
		/// <param name="str">     ������               </param>
		/// <returns>
		/// �ϊ��ł����Ƃ� true , �ł��Ȃ������Ƃ� false
		/// </returns>
		static bool toBool(bool& flag, const String& str);

		/// <summary>
		/// �����񂩂琮���l�ւ̕ϊ�
		/// </summary>
		/// <param name="integer"> �ϊ���̐����l�̑���� </param>
		/// <param name="str">     ������                 </param>
		/// <returns>
		/// �ϊ��ł����Ƃ� true , �ł��Ȃ������Ƃ� false
		/// </returns>
		static bool toInteger(int32& integer, const String& str);

		/// <summary>
		/// �����񂩂珬���l(double)�ւ̕ϊ�
		/// </summary>
		/// <param name="value"> �ϊ���̐����l�̑���� </param>
		/// <param name="str">   ������                 </param>
		/// <returns>
		/// �ϊ��ł����Ƃ� true , �ł��Ȃ������Ƃ� false
		/// </returns>
		static bool toDouble(double& value, const String& str);

		/// <summary>
		// �����񂩂���W�ւ̕ϊ�
		/// </summary>
		/// <param name="pos"> �ϊ���̍��W�̑����  </param>
		/// <param name="str"> ������                </param>
		/// <returns>
		/// �ϊ��ł����Ƃ� true , �ł��Ȃ������Ƃ� false
		/// </returns>
		static bool toPoint(Point& pos, const String& str);

		/// <summary>
		/// �I�u�W�F�N�g�����邩�m�F
		/// </summary>
		/// <param name="name"> ���O </param>
		/// <returns>
		/// �I�u�W�F�N�g���������Ƃ� true , �Ȃ��Ƃ� false
		/// </returns>
		static bool isExistedObject(const String& name);

	};
}