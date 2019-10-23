#pragma once


#include "../Slice/SliceTexture.h"
#include "AdventureObject.h"


namespace Kokoha
{
	/*
	AdventurePlayer�N���X
	AdventureManager�ł̃v���C���[
	���W�E�͈͂̊Ǘ� �� �`��
	*/
	class AdventurePlayer
	{
	private:

		// x���W
		double mPosX;

		// �摜�ƃA�j���[�V����
		SliceTexture mSlide;

		// ���� x���ɂ��� �� -> +1 , �� -> -1
		int32 mDirection;

		// �m�F�}�[�N�̕\���ʒu
		Optional<Point> mCheckPos;

	public:

		AdventurePlayer();

		/// <summary>
		/// �ݒ�
		/// </summary>
		void set(int32 posX, int32 direction);

		/// <summary>
		/// �X�V
		/// </summary>
		/// <param name="objectList"> �I�u�W�F�N�g�̃��X�g </param>
		void update(Array<AdventureObject>& objectList);

		/// <summary>
		/// �`��
		/// </summary>
		void draw(const Point& cameraPos)const;

		/// <summary>
		/// �v���C���[�͈̔͂̎擾
		/// </summary>
		/// <returns>
		/// �͈�
		/// </returns>
		Rect getRegion()const;

	private:

		/// <summary>
		/// �v���C���[�̈ړ�
		/// </summary>
		/// <param name="objectList"> �I�u�W�F�N�g�̃��X�g </param>
		void walk(const Array<AdventureObject>& objectList);

		/// <summary>
		/// �אڃI�u�W�F�N�g���m�F
		/// </summary>
		/// <param name="objectList"> �I�u�W�F�N�g�̃��X�g </param>
		/// <returns>
		/// �אڃI�u�W�F�N�g�̍��W
		/// </returns>
		Optional<Point> check(Array<AdventureObject>& objectList);

	};
}