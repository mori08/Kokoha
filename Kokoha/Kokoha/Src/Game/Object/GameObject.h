#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	GameObjectクラス
	GameManagerで扱うオブジェクト
	*/
	class GameObject
	{
	protected:

		enum class ObjectType
		{
			PLAYER
		};

	protected:

		// 座標
		Vec2 mPos;

		// 種類
		const ObjectType mType;

	public:

		/// <summary>
		/// オブジェクト
		/// </summary>
		/// <param name="pos">  座標 </param>
		/// <param name="type"> 種類 </param>
		GameObject(const Vec2& pos, const ObjectType& type)
			: mPos (pos)
			, mType(type)
		{

		}

		/// <summary>
		/// 更新
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// 描画
		/// </summary>
		/// <remarks>
		/// #F0F0F0 でのみ描画
		/// </remarks>
		virtual void draw()const = 0;

		/// <summary>
		/// 光の描画
		/// </summary>
		/// <remarks>
		/// #0F0F0F でのみ描画
		/// </remarks>
		virtual void drawLight()const
		{

		}

	protected:

		/// <summary>
		/// オブジェクトを移動
		/// </summary>
		/// <param name="movement"> 移動量 </param>
		/// <remarks>
		/// プレイヤーの速さの基本値を1.0とする.
		/// </remarks>
		void walk(Vec2 movement);

		/// <summary>
		/// オブジェクトを目的地へ移動
		/// </summary>
		/// <param name="speed"> 速さ   </param>
		/// <param name="goal" > 目的地 </param>
		/// <remarks>
		/// プレイヤーの速さの基本値を1.0とする.
		/// </remarks>
		void walkToGoal(double speed, const Vec2& goal);

	};

	using GameObjectPtr = std::unique_ptr<GameObject>;
}