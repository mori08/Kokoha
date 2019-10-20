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
		void update(const Array<AdventureObject>& objectList);

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

	};
}