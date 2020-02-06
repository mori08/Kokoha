#pragma once


#include "GameState.h"


namespace Kokoha
{
	/*
	InfoState�N���X
	�X�e�[�W���N���A�������Ƃɂ����
	�N����ω���\��
	*/
	class InfoState : public GameState
	{
	public:

		using AreaFlag = Optional<String>;

		// ���̂܂Ƃ�
		class Info
		{
		public:

			// �J�Z�b�g
			const Optional<int> CASSETTE_ID;

			// �X�e�[�W
			const std::function<AreaFlag()> AREA_FLAG_FUNC;

			Info()
				: CASSETTE_ID(none)
				, AREA_FLAG_FUNC([]() { return none; })
			{
			}

			Info(const Optional<int>& cassetteId, const std::function<AreaFlag()>& areaFlag)
				: CASSETTE_ID   (cassetteId)
				, AREA_FLAG_FUNC(areaFlag)
			{
			}
		};

	private:

		// �X�e�[�W���Ƃ̕\�����
		static std::unordered_map<String, Info> sInfoMap;

		// �o�ߎ���(s)
		double mTimeSecond;

		// �\������e�L�X�g�̃��X�g
		Array<String> mTextList;

		// �e�L�X�g��\������X���W
		double mDrawTextPosX;

		// ���F�̃A���t�@�l
		double mAlpha;

	public:

		InfoState();

		/// <summary>
		/// �}�b�v��Info��ݒ�
		/// </summary>
		static void setInfoMap();

	private:

		void update() override;

		void draw() const override;

		Optional<SceneName> isChangeAbleScene() const override;

	};
}