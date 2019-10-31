#pragma once


#include <Siv3D.hpp>
#include <limits>
#include "ObjectType.h"


namespace Kokoha
{
	/*
	GameObjectクラス
	GameManagerで扱うオブジェクト
	*/
	class GameObject
	{
	protected:

		// 範囲
		Circle mBody;

		// 種類
		const ObjectType mType;

	public:

		/// <summary>
		/// オブジェクト
		/// </summary>
		/// <param name="body"> 範囲 </param>
		/// <param name="type"> 種類 </param>
		GameObject(const Circle& body, const ObjectType& type)
			: mBody(body)
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

		/// <summary>
		/// このオブジェクトが削除するか
		/// </summary>
		/// <returns>
		/// 削除するとき true , しないとき false
		/// </returns>
		virtual bool isEraseAble()const
		{
			return false;
		}

		/// <summary>
		/// 他のオブジェクトの種類と位置の確認
		/// </summary>
		/// <param name="another"> 他のオブジェクト </param>
		virtual void checkAnother(const GameObject& another) = 0;

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

	public:

		/// <summary>
		/// 指定の種類のオブジェクトと衝突の確認
		/// </summary>
		/// <param name="another"  > 他のオブジェクト </param>
		/// <param name="checkType"> 指定する種類     </param>
		/// <returns>
		/// anotherが指定の種類のオブジェクトかつ衝突しているとき true , そうでないとき false
		/// </returns>
		bool checkTypeAndCollision(const GameObject& another, const ObjectType& checkType) const
		{
			return (another.mType & checkType) && mBody.intersects(another.mBody);
		}

		/// <summary>
		/// 指定の種類のオブジェクトのとき座標の取得
		/// </summary>
		/// <param name="checkType"> 指定する種類 </param>
		/// <returns>
		/// 座標
		/// </returns>
		Optional<Vec2> checkTypeAndGetPos(const ObjectType& checkType) const;

	};

	using GameObjectPtr = std::unique_ptr<GameObject>;
}