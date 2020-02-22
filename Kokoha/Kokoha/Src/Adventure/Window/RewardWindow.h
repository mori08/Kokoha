#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	RewardWindow�N���X
	�X�e�[�W�̃N���A��V�̕\�����s��
	*/
	class RewardWindow : public AdventureWindow
	{
	private:

		// ��V�܂Ƃ�
		class Reward
		{
		public:

			// �J�Z�b�gID
			const Optional<int32> CASSETTE_ID;

			// �X�e�[�W
			const std::function<Optional<String>()> AREA_FLAG_FUNC;

			Reward()
				: CASSETTE_ID(none)
				, AREA_FLAG_FUNC([]() { return none; })
			{
			}

			Reward(const Optional<int32> cassetteId, const std::function<Optional<String>()>& areaFlagFunc)
				: CASSETTE_ID(cassetteId)
				, AREA_FLAG_FUNC(areaFlagFunc)
			{
			}
		};

	private:

		// �X�e�[�W���Ƃ̕\�����
		static std::unordered_map<String, Reward> sRewardMap;

		// �\������e�L�X�g�̃��X�g
		Array<String> mTextList;

	public:

		/// <summary>
		/// ��V��\������E�B���h�E
		/// </summary>
		/// <param name="stageName"> �X�e�[�W�� </param>
		RewardWindow(const String& stageName);

		/// <summary>
		/// �}�b�v�ɕ�V��ݒ�
		/// </summary>
		static void setRewardMap();

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}