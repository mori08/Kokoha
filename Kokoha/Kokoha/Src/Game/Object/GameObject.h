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
			PLAYER,      // プレイヤー
			BLACK_ENEMY, // 黒い敵
			WHITE_ENEMY  // 白い敵
		};

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
		/// 他のオブジェクトとの衝突を確認
		/// 衝突していたときonCollision()を呼ぶ
		/// </summary>
		/// <param name="another"> 他のオブジェクト </param>
		void collisionCheck(GameObjectPtr& another);

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

		/// <summary>
		/// 衝突時の処理
		/// </summary>
		virtual void onCollision(const ObjectType&)
		{
		}

	};

	using GameObjectPtr = std::unique_ptr<GameObject>;
}