#pragma once


#include "../../Scene.h"


namespace Kokoha
{
	/*
	StageMakingScene�N���X
	�X�e�[�W�̓������m�F������f�o�b�O�p�V�[��
	�ǐՕ����ⓦ�������������
	*/
	class CheckStageScene : public MyApp::Scene
	{
	public:

		CheckStageScene(const InitData& init);

	private:

		void update();

		void draw()const;

	};
}