#pragma once


#include "../../Slice/SliceTexture.h"


namespace Kokoha
{
	// ���o�p�֐�
	using Act = std::function<void()>;

	/*
	EventObject�N���X
	EventManager�Ŏg�p����I�u�W�F�N�g
	�`��E�ړ��E���̑��A�N�V����������

	���̃N���X�̔h���N���X�����Ƃ���
	GenerateObject��setAllGenerateObjectFunc�֐��ɓo�^
	*/
	class EventObject
	{
	protected:

		// ���W
		Point mPos;

		// ����̊Ǘ�
		Linearly<Vec2> mLinearMove;

		// �C�x���g�p�֐�
		std::unordered_map<String, Act> mActMap;

		// �摜�ƃA�j���[�V����
		SliceTexture mSlide;

		// true �̂Ƃ���\��
		bool mIsHidden;

		// ���o�E�ړ��I�������Ƃ� true
		bool mIsFinished;

	public:

		/// <summary>
		/// �C�x���g�I�u�W�F�N�g
		/// </summary>
		/// <param name="pos"> ���W </param>
		/// <param name="textureName"> �摜�̖��O             </param>
		/// <param name="sliceSize">   �摜��؂蕪����傫�� </param>
		/// <param name="texturePos">  �摜�̏����ԍ�         </param>
		EventObject(const Point& pos, const String& textureName, const Size& sliceSize, const Point& texturePos);

		/// <summary>
		/// �X�V
		/// </summary>
		/// <remarks>
		/// �h���N���X�ŃI�[�o�[���[�h����Ƃ���
		/// EventObject::update()���Ă�
		/// </remarks>
		virtual void update();

		/// <summary>
		/// �`��
		/// </summary>
		/// <param name="cameraPos"> �J�����̍��W </param> 
		/// <remarks>
		/// �h���N���X�ŃI�[�o�[���[�h����Ƃ�
		/// mIsHidden��true�̂Ƃ������`�悵�Ȃ��悤�ɒ���
		/// </remarks>
		virtual void draw(const Point& cameraPos) const;

		/// <summary>
		/// �I�u�W�F�N�g�̈ړ��̐ݒ�
		/// </summary>
		/// <param name="time">      �ړ��ɂ����鎞��         </param>
		/// <param name="movement">  �ړ���̍��W             </param>
		/// <param name="wait">      �C�x���g�S�̂�҂����邩 </param>
		void setLinearMove(double time, const Point& movement, bool wait);

		/// <summary>
		/// �ړ��E���o���I�����Ă��邩
		/// </summary>
		/// <returns>
		/// �I�����Ă���Ƃ� true , �����łȂ��Ƃ� false
		/// </returns>
		bool isFinished() const
		{
			return mIsFinished;
		}

		/// <summary>
		/// ���o�����݂��邩�Ԃ��܂�.
		/// </summary>
		/// <param name="actName"> ���o�� </param>
		/// <returns>
		/// ���݂���Ƃ� true , �����łȂ��Ƃ� false
		/// </retruns>
		bool isExistedAct(const String& actName) const
		{
			return mActMap.count(actName);
		}

		/// <summary>
		/// ���o�̎��s
		/// </summary>
		/// <param name="actName"> ���o�� </param>
		void act(const String& actName)
		{
			mActMap[actName]();
		}

	protected:

		/// <summary>
		/// �A�j���[�V������mActMap��mSlide�ɐݒ�
		/// </summary>
		/// <param name="animName"> �A�j���[�V������ </param>
		/// <param name="anim">     �A�j���[�V����   </param>
		void setAnimation(const String& animName, const Animation& anim);

	};


	// �I�u�W�F�N�g�̃|�C���^
	using EventObjectPtr = std::unique_ptr<EventObject>;
}