#pragma once


#include "Linearly.h"


namespace Kokoha
{
	/*
	Animationクラス
	画像の切り替え順とそれにかかる時間などをまとめたもの
	
	作成に O(画像数) の処理を要するので
	できるだけ LoadScene の派生クラスで使用
	*/
	class Animation
	{
	public:

		// 画像切り替えにかける時間
		const double TIME;

		// 画像の切り替え順
		const Array<Point> POS_LIST;

		// ループするか
		const bool IS_LOOP;

		Animation()
			: TIME(0)
			, POS_LIST()
			, IS_LOOP(false)
		{
		}

		/// <summary>
		/// 画像の切り替え順とそれにかかる時間など
		/// </summary>
		/// <param name="time">    画像切り替えにかける時間 </param>
		/// <param name="posList"> 画像の切り替え順         </param>
		/// <param name="posList"> ループ                   </param>
		Animation(double time, const Array<Point>& posList, bool isLoop)
			: TIME(time)
			, POS_LIST(posList)
			, IS_LOOP(isLoop)
		{
		}

	};


	/*
	SliceTextureクラス
	1枚の画像を複数の画像に分け,
	切り替えなどを行えるようにする.
	*/
	class SliceTexture
	{
	private:

		// 画像の名前
		String mTextureName;

		// 画像を切り分ける大きさ
		Size mSliceSize;

		// true のとき左右反転して描画
		bool mMirror;

		// 画像を遷移する時間
		Linearly<double> mChangeSpan;

		// 現在のAnimationの名前
		String mAnimationName;

		// Animationを管理するマップ
		std::unordered_map<String, Animation> mAnimationMap;

	public:

		/// <summary>
		/// 画像の切り分け
		/// </summary>
		/// <param name="textureName"> 画像の名前             </param>
		/// <param name="sliceSize">   画像を切り分ける大きさ </param>
		/// <param name="pos">         画像の初期番号         </param>
		SliceTexture(const String& textureName, const Size& sliceSize, const Point& pos);

		/// <summary>
		/// 画像の名前の設定
		/// </summary>
		/// <param name="textureName"> 画像の名前             </param>
		/// <param name="sliceSize">   画像を切り分ける大きさ </param>
		void setTextureName(const String& textureName, const Size& sliceSize);

		/// <summary>
		/// アニメーションの設定
		/// </summary>
		/// <param name="anim"> アニメーション </param>
		void setAnimation(const String& name, const Animation& anim)
		{
			mAnimationMap.try_emplace(name, std::move(Animation(anim)));
		}

		/// <summary>
		/// 画像の変更
		/// </summary>
		/// <returns>
		/// 画像の切り替えが終了したとき true , そうでないとき false
		/// ループしているときは true を返すのに注意
		/// </returns>
		bool changeTexture();

		/// <summary>
		/// 画像の反転
		/// </summary>
		void mirror()
		{
			mMirror = !mMirror;
		}

		/// <summary>
		/// アニメーションの開始
		/// </summary>
		/// <param name="name"> アニメーションの名前 </param>
		void start(const String name);

		/// <summary>
		/// 画像の変更
		/// </summary>
		TextureRegion getTexture() const;

	};

}