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

		// true �̂Ƃ����C�g������
		static bool sOnLight;

		// ���̔��a
		static double sLightRadius;

		// ����\�����鎞��
		static double sLightSecond;

	private:

		// �̂̉摜�ƃA�j���[�V����
		SliceTexture mBodySlide;

		// ��̉摜�ƃA�j���[�V����
		SliceTexture mFaceSlide;

		// ���̃A���t�@�l
		double mLightAlpha;

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

		void drawLight()const override;

		void checkAnother(const GameObject& another) override;

	public:

		/// <summary>
		/// �G�̏ꏊ��������������
		/// </summary>
		/// <param name="radius"> ���a             </param>
		/// <param name="second"> ����\�����鎞�� </param>
		static void lightOn(double radius, double second);

		/// <summary>
		/// �G�̏ꏊ��������������
		/// </summary>
		static void lightOff();

		/// <summary>
		/// �G�̏ꏊ���������̍X�V
		/// </summary>
		static void lightUpdate();

	};
}


#include "BlackEnemy.h"
#include "WhiteEnemy.h"