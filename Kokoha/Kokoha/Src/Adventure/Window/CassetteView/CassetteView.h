#pragma once


#include "../../../Cassette/Cassette/Cassette.h"


namespace Kokoha
{
	/*
	CassetteViewクラス
	SetupWindowで主に使用
	カセットの一覧を処理
	*/
	class CassetteView
	{
	private:

		// 先頭のインデックス
		int32 mBeginId;

		// ボタンにつける名前
		const String mButtonName;

		// 描画座標
		const Point mDrawPoint;

	public:

		CassetteView(const Point& drawPos,const String& buttonName);

		/// <summary>
		/// ボタンをButtonManagerにセット
		/// </summary>
		void setButton() const;

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="cassetteSet"> カセットの集合 </param>
		void update(const CassettePtrSet& cassetteSet);

		/// <summary>
		/// 描画
		/// </summary>
		/// <param name="cassetteSet"> カセットの集合 </param>
		void draw(const CassettePtrSet& cassetteSet) const;

	};
}
