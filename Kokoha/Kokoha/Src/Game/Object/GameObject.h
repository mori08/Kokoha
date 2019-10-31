#pragma once


#include <Siv3D.hpp>
#include <limits>
#include "ObjectType.h"


namespace Kokoha
{
	/*
	GameObject�N���X
	GameManager�ň����I�u�W�F�N�g
	*/
	class GameObject
	{
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
		/// ���̃I�u�W�F�N�g�̎�ނƈʒu�̊m�F
		/// </summary>
		/// <param name="another"> ���̃I�u�W�F�N�g </param>
		virtual void checkAnother(const GameObject& another) = 0;

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

	public:

		/// <summary>
		/// �w��̎�ނ̃I�u�W�F�N�g�ƏՓ˂̊m�F
		/// </summary>
		/// <param name="another"  > ���̃I�u�W�F�N�g </param>
		/// <param name="checkType"> �w�肷����     </param>
		/// <returns>
		/// another���w��̎�ނ̃I�u�W�F�N�g���Փ˂��Ă���Ƃ� true , �����łȂ��Ƃ� false
		/// </returns>
		bool checkTypeAndCollision(const GameObject& another, const ObjectType& checkType) const
		{
			return (another.mType & checkType) && mBody.intersects(another.mBody);
		}

		/// <summary>
		/// �w��̎�ނ̃I�u�W�F�N�g�̂Ƃ����W�̎擾
		/// </summary>
		/// <param name="checkType"> �w�肷���� </param>
		/// <returns>
		/// ���W
		/// </returns>
		Optional<Vec2> checkTypeAndGetPos(const ObjectType& checkType) const;

	};

	using GameObjectPtr = std::unique_ptr<GameObject>;
}