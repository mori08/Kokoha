#pragma once


#include "Event.h"
#include "../Object/EventObject.h"


namespace Kokoha
{
	// �C�x���g�I�u�W�F�N�g�𐶐�����֐�
	using GenerateEventObjectFunc = std::function<EventObjectPtr(const Point& pos)>;

	/*
	GenerateEvent�N���X
	EventObject�𐶐���,
	EventManager��mObjectMap�ɒǉ�
	�C�x���g��CSV�f�[�^�ł�Run���O�ɋL�q
	*/
	class GenerateEvent : public Event
	{
	private:

		// �I�u�W�F�N�g�𐶐�����֐��̃}�b�v
		static std::unordered_map<String, GenerateEventObjectFunc> sGenerateObjectMap;

		// ��������I�u�W�F�N�g�̎��
		String mType;

		// ��������I�u�W�F�N�g�̖��O
		String mName;

		// �I�u�W�F�N�g�𐶐�������W
		Point mPos;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	public:

		/// <summary>
		/// �I�u�W�F�N�g�𐶐�����֐���S�ă}�b�v�ɓo�^
		/// </summary>
		static void setAllGenerateObjectFunc();

	private:

		/// <summary>
		/// �I�u�W�F�N�g�𐶐�����֐����}�b�v�ɓo�^
		/// </summary>
		/// <param name="name"> �I�u�W�F�N�g�̌^�� </param>
		template<typename eventObjectType>
		static void setGenerateObjectFunc(const String& name)
		{
			sGenerateObjectMap[name] = GenerateEventObjectFunc
			(
				[](const Point& pos)
				{
					return std::make_unique<eventObjectType>(pos);
				}
			);
		}

	};
}