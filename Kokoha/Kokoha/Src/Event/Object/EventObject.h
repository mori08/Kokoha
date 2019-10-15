#pragma once


#include "../../Slice/SliceTexture.h"


namespace Kokoha
{
	// 演出用関数
	using Act = std::function<void()>;

	/*
	EventObjectクラス
	EventManagerで使用するオブジェクト
	描画・移動・その他アクションを実装

	このクラスの派生クラスを作るときは
	GenerateObjectのsetAllGenerateObjectFunc関数に登録
	*/
	class EventObject
	{
	protected:

		// 座標
		Point mPos;

		// 動作の管理
		Linearly<Vec2> mLinearMove;

		// イベント用関数
		std::unordered_map<String, Act> mActMap;

		// 画像とアニメーション
		SliceTexture mSlide;

		// true のとき非表示
		bool mIsHidden;

		// 演出・移動終了したとき true
		bool mIsFinished;

	public:

		/// <summary>
		/// イベントオブジェクト
		/// </summary>
		/// <param name="pos"> 座標 </param>
		/// <param name="textureName"> 画像の名前             </param>
		/// <param name="sliceSize">   画像を切り分ける大きさ </param>
		/// <param name="texturePos">  画像の初期番号         </param>
		EventObject(const Point& pos, const String& textureName, const Size& sliceSize, const Point& texturePos);

		/// <summary>
		/// 更新
		/// </summary>
		/// <remarks>
		/// 派生クラスでオーバーロードするときも
		/// EventObject::update()を呼ぶ
		/// </remarks>
		virtual void update();

		/// <summary>
		/// 描画
		/// </summary>
		/// <param name="cameraPos"> カメラの座標 </param> 
		/// <remarks>
		/// 派生クラスでオーバーロードするとき
		/// mIsHiddenがtrueのとき何も描画しないように注意
		/// </remarks>
		virtual void draw(const Point& cameraPos) const;

		/// <summary>
		/// オブジェクトの移動の設定
		/// </summary>
		/// <param name="time">      移動にかける時間         </param>
		/// <param name="movement">  移動先の座標             </param>
		/// <param name="wait">      イベント全体を待たせるか </param>
		void setLinearMove(double time, const Point& movement, bool wait);

		/// <summary>
		/// 移動・演出が終了しているか
		/// </summary>
		/// <returns>
		/// 終了しているとき true , そうでないとき false
		/// </returns>
		bool isFinished() const
		{
			return mIsFinished;
		}

		/// <summary>
		/// 演出が存在するか返します.
		/// </summary>
		/// <param name="actName"> 演出名 </param>
		/// <returns>
		/// 存在するとき true , そうでないとき false
		/// </retruns>
		bool isExistedAct(const String& actName) const
		{
			return mActMap.count(actName);
		}

		/// <summary>
		/// 演出の実行
		/// </summary>
		/// <param name="actName"> 演出名 </param>
		void act(const String& actName)
		{
			mActMap[actName]();
		}

	protected:

		/// <summary>
		/// アニメーションをmActMapとmSlideに設定
		/// </summary>
		/// <param name="animName"> アニメーション名 </param>
		/// <param name="anim">     アニメーション   </param>
		void setAnimation(const String& animName, const Animation& anim);

	};


	// オブジェクトのポインタ
	using EventObjectPtr = std::unique_ptr<EventObject>;
}