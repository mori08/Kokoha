#pragma once


#include "Event.h"
#include "../../Scene.h"


namespace Kokoha
{
	/*
	ChangeSceneEvent�N���X
	�V�[���J�ڐ�C�x���g
	*/
	class ChangeSceneEvent : public Event
	{
	private:

		// �V�[�����̃}�b�v
		static std::unordered_map<String, SceneName> sSceneNameMap;

		// �V�[���J�ڐ�
		SceneName mSceneName;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	public:

		/// <summary>
		/// �V�[�����̃}�b�v�̐ݒ�
		/// </summary>
		static void setSceneNameMap();

	};
}