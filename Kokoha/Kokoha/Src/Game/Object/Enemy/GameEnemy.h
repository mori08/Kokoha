#pragma once


#include "../GameObject.h"
#include "../../../Slice/SliceTexture.h"


namespace Kokoha
{
	/*
	GameEnemy�N���X
	GameManager�Ŏg�p����G�I�u�W�F�N�g
	*/
	class GameEnemy : public GameObject
	{
	private:

		// �̂̉摜�ƃA�j���[�V����
		SliceTexture mBodySlide;

		// ��̉摜�ƃA�j���[�V����
		SliceTexture mFaceSlide;

	public:

		/// <summary>
		/// �G
		/// </summary>
		/// <param name="pos"        > ���W   </param>
		/// <param name="type"       > ���   </param>
		/// <param name="textureName"> �摜�� </param>
		GameEnemy(const Vec2& pos,const ObjectType& type, const String& textureName);

		virtual void update() override;

		virtual void draw()const override;

	};
}


#include "BlackEnemy.h"
#include "WhiteEnemy.h"