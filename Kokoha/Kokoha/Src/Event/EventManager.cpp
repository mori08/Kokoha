#include "EventManager.h"
#include "../MyLibrary.h"
#include "../MyColor.h"

// �e�C�x���ghttps://github.com/mori08
#include "Event/EmptyEvent.h"
#include "Event/GenerateEvent.h"
#include "Event/MoveEvent.h"
#include "Event/WaitEvent.h"
#include "Event/ActEvent.h"
#include "Event/TextEvent.h"
#include "Event/BackgroundEvent.h"
#include "Event/CameraEvent.h"
#include "Event/ChangeSceneEvent.h"


namespace 
{
	constexpr int32 EVENT_NAME_COLUMN = 0;     // CSV�t�@�C�����̃C�x���g�̖��O���L�q�����
	constexpr int32 EVENT_ARG_COLUMN  = 1;     // CSV�t�@�C�����̃C�x���g�̏ڍׂ��ŏ��ɋL�q�����
	const String EVENT_ARG_END  = U"#";        // CSV�t�@�C�����ŃC�x���g�̏ڍׂ̍Ō�Ɏg��������
	const String RUN_EVENT_KEY  = U"Run";      // CSV�t�@�C�����œo�^�ς݂̃C�x���g��S�Ď��s���閽��
	const String FUNC_EVENT_KEY = U"Function"; // CSV�t�@�C�����ŕ�CSV�t�@�C���̃C�x���g��ǂݍ��ޖ���
}


Kokoha::EventManager::EventManager()
	: mCameraPos(0, Vec2::Zero())
{
	// �C�x���g�̓o�^
	setEvent<GenerateEvent>   (U"Generate");
	setEvent<MoveEvent>       (U"Move");
	setEvent<WaitEvent>       (U"Wait");
	setEvent<ActEvent>        (U"Act");
	setEvent<TextEvent>       (U"Text");
	setEvent<BackgroundEvent> (U"Background");
	setEvent<CameraEvent>     (U"Camera");
	setEvent<ChangeSceneEvent>(U"Scene");

	GenerateEvent::setAllGenerateObjectFunc();
	ChangeSceneEvent::setSceneNameMap();
}


void Kokoha::EventManager::init()
{
	// �C�x���g�̃L���[����ɂ��܂�
	while (!mEventQueue.empty()) { mEventQueue.pop(); }

	// ��C�x���g���L���[�ɓ���܂�
	mEventQueue.push(std::make_unique<EmptyEvent>());

	// �I�u�W�F�N�g����ɂ��܂�
	mObjectMap.clear();

	// �e�L�X�g�{�b�N�X��������
	mTextBox.reset();

	// �G���[���b�Z�[�W�����Z�b�g���܂�
	mErrorMessage = U"";

	// �V�[���J�ڐ�
	mSceneName = none;
}


bool Kokoha::EventManager::load(const String& eventFileName)
{	
	CSVData csv(eventFileName);
	if (!csv)
	{
		addErrorMessage(U"[EventManger::load]");
		addErrorMessage(eventFileName + U" ��ǂݍ��߂܂���ł���.");
		return false;
	}

	for (int32 loadingRow = 0; loadingRow < csv.rows(); ++loadingRow)
	{
		// �C�x���g�̖��O�̎擾
		String eventName = csv[loadingRow][EVENT_NAME_COLUMN];

		// ���݃L���[�ɂ���S�C�x���g�����s
		if (eventName == RUN_EVENT_KEY)
		{
			runAllEvent();
			continue;
		}

		// ��CSV�t�@�C���̓ǂݍ���
		if (eventName == FUNC_EVENT_KEY)
		{
			String funcName     = csv[loadingRow][EVENT_ARG_COLUMN];
			String funcFileName = U"Assets/Data/Event/Event[" + funcName + U"].csv";
			if (!load(funcFileName))
			{
				addErrorMessage(eventFileName + U" : " + ToString(loadingRow + 1) + U"�s��");
				return false;
			}
			continue;
		}
		
		// �C�x���g�����邩���m�F
		if (!mMakeEventMap.count(eventName))
		{
			addErrorMessage(U"�C�x���g<" + eventName + U">�͑��݂��܂���.");
			addErrorMessage(eventFileName + U" : " + ToString(loadingRow + 1) + U"�s��");
			return false;
		}

		// �C�x���g�̏ڍׂ̍쐬
		EventArg eventArg;
		for (int32 column = EVENT_ARG_COLUMN;; ++column)
		{
			// �I��������������Ȃ��Ƃ��G���[
			if (column >= csv.columns(loadingRow))
			{
				addErrorMessage(U"�I������ " + EVENT_ARG_END + U" ������܂���.");
				addErrorMessage(eventFileName + U" : " + ToString(loadingRow + 1) + U"�s��");
				return false;
			}

			// �I�������̊m�F
			if (csv[loadingRow][column] == EVENT_ARG_END) { break; }
			
			// �ڍׂɒǉ�
			eventArg.emplace_back(csv[loadingRow][column]);
		}
		
		// �C�x���g�̃|�C���^�̐���
		EventPtr eventPtr = mMakeEventMap[eventName]();
		
		// �C�x���g�̏ڍׂ̓ǂݍ���
		if (!eventPtr->load(eventArg))
		{
			addErrorMessage(eventFileName + U" : " + ToString(loadingRow + 1) + U"�s��");
			return false;
		}
		
		// �L���[�ɃC�x���g��ǉ�
		mEventQueue.push(std::move(eventPtr));
	}

	return true;
}


void Kokoha::EventManager::update()
{
	// �C�x���g�̍X�V
	if (mEventQueue.size() > 1 && mEventQueue.front()->isCompleted())
	{
		mEventQueue.pop();
		mEventQueue.front()->perform();
	}

	// �e�L�X�g�{�b�N�X�̍X�V
	mTextBox.update();

	// �I�u�W�F�N�g�̍X�V
	for (auto&& object : mObjectMap)
	{
		object.second->update();
	}

	// �J�����̍X�V
	mCameraPos.update();

	ClearPrint();
}


void Kokoha::EventManager::draw() const
{
	Scene::Rect().draw(MyBlack);

	TextureAsset(mBackgroundName).draw(-mCameraPos.getValue().asPoint());

	for (const auto& object : mObjectMap)
	{
		object.second->draw(-mCameraPos.getValue().asPoint());
	}

	mTextBox.draw();
}


void Kokoha::EventManager::setCameraMove(double time, const Point& movement)
{
	// �ړ����Ԃ�ړ��ʂ̕␳
	const Point  m = movement + (mCameraPos.getGoal() - mCameraPos.getValue()).asPoint();
	const double t = time * m.length() / movement.length();
	mCameraPos = Linearly<Vec2>(t, mCameraPos.getValue(), m);
}


void Kokoha::EventManager::runAllEvent()
{
	while (!mEventQueue.empty())
	{
		mEventQueue.front()->perform();
		mEventQueue.pop();
	}

	mEventQueue.push(std::make_unique<EmptyEvent>());
}
