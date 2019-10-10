#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	SliceTextureクラス
	1枚の画像を複数の画像に分け,
	切り替えなどを行えるようにする.
	*/
	class SliceTexture
	{
	private:

		// 画像の名前
		const String mTextureName;

		// 画像を切り分ける大きさ
		const Size mSliceSize;

		// 描画する画像の番号
		Point mTexturePos;

		// true のとき左右反転して描画
		bool mMirror;

	public:

		/// <summary>
		/// 画像の切り分け
		/// </summary>
		/// <param name="textureName"> 画像の名前             </param>
		/// <param name="sliceSize">   画像を切り分ける大きさ </param>
		/// <param name="pos">         画像の初期番号         </param>
		SliceTexture(const String& textureName, const Size& sliceSize, const Point& pos);

		/// <summary>
		/// 表示する画像の番号の変更
		/// </summary>
		/// <param name="pos"> 画像の番号 </param>
		void setTexturePos(const Point& pos)
		{
			mTexturePos = pos;
		}



	};

}