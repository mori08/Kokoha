#pragma once


#include "Event/Event.h"
#include <queue>


namespace Kokoha
{
	// �C�x���g�̃|�C���^
	using EventPtr = std::unique_ptr<Event>;
	
	// �C�x���g�𐶐�����֐�
	using MakeEventFunc = std::function<EventPtr()>;


	/*
	EventManager�N���X
	CSV�t�@�C�������Event�̓ǂݍ��݂���s
	EventObject�̊Ǘ�
	*/
	class EventManager
	{
	private:

		// �C�x���g���Ǘ�����L���[
		std::queue<EventPtr> mEventQueue;

		// �C�x���g�𐶐�����֐��̘A�z�z��
		std::unordered_map<String, MakeEventFunc> mMakeEventMap;

	private:

		EventManager();

		EventManager(const EventManager&)            = default;
		EventManager& operator=(const EventManager&) = default;
		EventManager(EventManager&&)                 = default;
		EventManager& operator=(EventManager&&)      = default;

	public:

		/// <summary>
		/// �V���O���g���Ƃ��ĊǗ����Ă���EventManager�̃C���X�^���X�̎擾
		/// </summary>
		/// <returns>
		/// �C���X�^���X
		/// </returns>
		static EventManager& instance()
		{
			static EventManager eventManager;
			return eventManager;
		}

		/// <summary>
		/// ������
		/// </summary>
		void init();

		/// <summary>
		/// �C�x���g���L�q����csv�t�@�C���̓ǂݍ���
		/// </summary>
		/// <param name="eventFileName"> csv�t�@�C���̖��O </param>
		/// <returns>
		/// ���������Ƃ� true, ���s�����Ƃ� false
		/// </returns>
		bool load(const String& eventFileName);

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw() const;

	private:

		/// <summary>
		/// �C�x���g�̓o�^
		/// </summary>
		/// <param name="name"> �C�x���g�� </param>
		template<typename eventType>
		void setEvent(const String& name)
		{
			mMakeEventMap[name] = MakeEventFunc
			(
				[]()
				{
					return std::move(std::make_unique<eventType>());
				}
			);
		}

		/// <summary>
		/// mEventQueue���̑S�C�x���g�����s
		/// </summary>
		/// <remarks>
		/// �������p�ɍs���܂��B
		/// isCompleted�֐��ł̔���҂��͍s���܂���.
		/// </remarks>
		void runAllEvent();

	};

}