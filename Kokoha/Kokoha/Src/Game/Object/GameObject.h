#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	GameObject�N���X
	GameManager�ň����I�u�W�F�N�g
	*/
	class GameObject
	{
	protected:

		enum class ObjectType
		{
			PLAYER,      // �v���C���[
			BLACK_ENEMY, // �����G
			WHITE_ENEMY  // �����G
		};

	protected:

		// �͈�
		Circle mBody;

		// ���
		const ObjectType mType;

	public:

		/// <summary>
		/// �I�u�W�F�N�g
		/// </summary>
		/// <param name="body"> �͈� </param>
		/// <param name="type"> ��� </param>
		GameObject(const Circle& body, const ObjectType& type)
			: mBody(body)
			, mType(type)
		{
		}

		/// <summary>
		/// �X�V
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// �`��
		/// </summary>
		/// <remarks>
		/// #F0F0F0 �ł̂ݕ`��
		/// </remarks>
		virtual void draw()const = 0;

		/// <summary>
		/// ���̕`��
		/// </summary>
		/// <remarks>
		/// #0F0F0F �ł̂ݕ`��
		/// </remarks>
		virtual void drawLight()const
		{
		}

		/// <summary>
		/// ���̃I�u�W�F�N�g���폜���邩
		/// </summary>
		/// <returns>
		/// �폜����Ƃ� true , ���Ȃ��Ƃ� false
		/// </returns>
		virtual bool isEraseAble()const
		{
			return false;
		}

		/// <summary>
		/// ���̃I�u�W�F�N�g�Ƃ̏Փ˂��m�F
		/// �Փ˂��Ă����Ƃ�onCollision()���Ă�
		/// </summary>
		/// <param name="another"> ���̃I�u�W�F�N�g </param>
		void collisionCheck(GameObjectPtr& another);

	protected:

		/// <summary>
		/// �I�u�W�F�N�g���ړ�
		/// </summary>
		/// <param name="movement"> �ړ��� </param>
		/// <remarks>
		/// �v���C���[�̑����̊�{�l��1.0�Ƃ���.
		/// </remarks>
		void walk(Vec2 movement);

		/// <summary>
		/// �I�u�W�F�N�g��ړI�n�ֈړ�
		/// </summary>
		/// <param name="speed"> ����   </param>
		/// <param name="goal" > �ړI�n </param>
		/// <remarks>
		/// �v���C���[�̑����̊�{�l��1.0�Ƃ���.
		/// </remarks>
		void walkToGoal(double speed, const Vec2& goal);

		/// <summary>
		/// �Փˎ��̏���
		/// </summary>
		virtual void onCollision(const ObjectType&)
		{
		}

	};

	using GameObjectPtr = std::unique_ptr<GameObject>;
}