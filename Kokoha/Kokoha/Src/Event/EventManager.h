#pragma once


#include "Event/Event.h"
#include "Object/EventObject.h"
#include "TextBox/TextBox.h"
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

		// �C�x���g��
		String mEventFileName;

		// �C�x���g���Ǘ�����L���[
		std::queue<EventPtr> mEventQueue;

		// �C�x���g�𐶐�����֐��̘A�z�z��
		std::unordered_map<String, MakeEventFunc> mMakeEventMap;

		// �I�u�W�F�N�g�ƕ�����̘A�z�z��
		std::map<String, EventObjectPtr> mObjectMap;

		// �e�L�X�g�{�b�N�X
		TextBox mTextBox;

		// �w�i�̉摜��
		String mBackgroundName;

		// �J�������W
		Linearly<Vec2> mCameraPos;

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
		/// �C�x���g���̐ݒ�
		/// </summary>
		/// <param name="eventName"> �Ή�����X�e�[�W�� </param>
		void setEventFileName(const String& stageName)
		{
			mEventFileName = U"Assets/Data/Event/Event(" + stageName + U").csv";
		}

		/// <summary>
		/// ������
		/// </summary>
		void init();

		/// <summary>
		/// �C�x���g���L�q����csv�t�@�C���̓ǂݍ���
		/// </summary>
		/// <returns>
		/// ���������Ƃ� true, ���s�����Ƃ� false
		/// </returns>
		bool load()
		{
			return load(mEventFileName);
		}

		/// <summary>
		/// �C�x���g���L�q����csv�t�@�C���̓ǂݍ���
		/// </summary>
		/// <param name="eventFileName"> �C�x���g�̃t�@�C���� </param>
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

		/// <summary>
		/// �w�i�̐ݒ�
		/// </summary>
		/// <param name="backgroundName"> �w�i�摜�̖��O </param>
		void setBackground(const String& backgroundName)
		{
			mBackgroundName = backgroundName;
		}

		/// <summary>
		/// �J�����̈ړ��̐ݒ�
		/// </summary>
		/// <param name="time"    > �ړ�����(�b) </param>
		/// <param name="movement"> �ړ���       </param>
		void setCameraMove(double time,const Point& movement);

		/// <summary>
		/// �J�����̍��W�̐ݒ�
		/// </summary>
		/// <param name="pos"> ���̍��W </param>
		void setCameraPos(const Point& pos)
		{
			mCameraPos = Linearly<Vec2>(0, pos, Vec2::Zero());
		}

		/// <summary>
		/// �e�L�X�g�{�b�N�X�̎擾
		/// </summary>
		/// <returns>
		/// �e�L�X�g�{�b�N�X
		/// </returns>
		/// <remarks>
		/// const�Q�Ƃ��Ⴀ��܂���.
		/// EventManager��TextEvent�ȊO�ł͎g��Ȃ��ł�������.
		/// </remarks>
		TextBox& getTextBox()
		{
			return mTextBox;
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