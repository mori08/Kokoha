#pragma once


#include "Event/Event.h"
#include "Object/EventObject.h"
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

		// �I�u�W�F�N�g�ƕ�����̘A�z�z��
		std::map<String, EventObjectPtr> mObjectMap;

		// ���[�h�̃G���[���b�Z�[�W
		String mErrorMessage;

	private:

		EventManager();

		EventManager(const EventManager&)            = default;
		EventManager& operator=(const EventManager&) = default;
		EventManager(EventManager&&)                 = default;
		EventManager& operator=(EventManager&&)      = default;

	public: 
		
		// Scene�N���X�̔h���Ŏg�p
		// ��

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
		/// �G���[���b�Z�[�W�̒ǉ�
		/// </summary>
		/// <param name="str"> �ǉ����镶���� </param>
		void addErrorMessage(const String& str)
		{
			mErrorMessage += str + U"\n";
		}

		/// <summary>
		/// �G���[���b�Z�[�W�̎擾
		/// </summary>
		/// <returns>
		/// �G���[���b�Z�[�W
		/// </returns>
		const String& getErrorMessage()
		{
			return mErrorMessage;
		}

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw() const;

		// ��
		// Scene�N���X�̔h���Ŏg�p

	public:

		// Event�N���X�̔h���Ŏg�p
		// ��

		/// <summary>
		/// �I�u�W�F�N�g�̐���
		/// </summary>
		/// <param name="name">   ���O         </param>
		/// <param name="object"> �I�u�W�F�N�g </param>
		void generateObject(const String& name, EventObjectPtr&& object)
		{
			mObjectMap.try_emplace(name, std::move(object));
		}

		/// <summary>
		/// �I�u�W�F�N�g�̃|�C���^���擾
		/// </summary>
		/// <param name="name"> ���O </param>
		/// <returns>
		/// �I�u�W�F�N�g�̃|�C���^
		/// ���O�ɑΉ������I�u�W�F�N�g���Ȃ��Ƃ� nullptr
		/// </returns>
		EventObjectPtr& getObjectPtr(const String& name)
		{
			return mObjectMap[name];
		}

		// ��
		// Event�N���X�̔h���Ŏg�p

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