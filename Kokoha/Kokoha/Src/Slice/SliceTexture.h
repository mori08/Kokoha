#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	SliceTexture�N���X
	1���̉摜�𕡐��̉摜�ɕ���,
	�؂�ւ��Ȃǂ��s����悤�ɂ���.
	*/
	class SliceTexture
	{
	private:

		// �摜�̖��O
		const String mTextureName;

		// �摜��؂蕪����傫��
		const Size mSliceSize;

		// �`�悷��摜�̔ԍ�
		Point mTexturePos;

		// true �̂Ƃ����E���]���ĕ`��
		bool mMirror;

	public:

		/// <summary>
		/// �摜�̐؂蕪��
		/// </summary>
		/// <param name="textureName"> �摜�̖��O             </param>
		/// <param name="sliceSize">   �摜��؂蕪����傫�� </param>
		/// <param name="pos">         �摜�̏����ԍ�         </param>
		SliceTexture(const String& textureName, const Size& sliceSize, const Point& pos);

		/// <summary>
		/// �\������摜�̔ԍ��̕ύX
		/// </summary>
		/// <param name="pos"> �摜�̔ԍ� </param>
		void setTexturePos(const Point& pos)
		{
			mTexturePos = pos;
		}



	};

}