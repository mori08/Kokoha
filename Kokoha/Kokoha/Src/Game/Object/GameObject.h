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
			PLAYER
		};

	protected:

		// ���W
		Vec2 mPos;

		// ���
		const ObjectType mType;

	public:

		/// <summary>
		/// �I�u�W�F�N�g
		/// </summary>
		/// <param name="pos">  ���W </param>
		/// <param name="type"> ��� </param>
		GameObject(const Vec2& pos, const ObjectType& type)
			: mPos (pos)
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

	};

	using GameObjectPtr = std::unique_ptr<GameObject>;
}