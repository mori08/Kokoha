#pragma once


#include "../../../Cassette/Cassette/Cassette.h"


namespace Kokoha
{
	/*
	CassetteViewクラス
	SetupWindowで主に使用
	カセットの一覧を処理
	*/
	class PossessCassetteView
	{
	public:

		/// <summary>
		/// ボタンをButtonManagerにセット
		/// </summary>
		void setButton()const;

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 描画
		/// </summary>
		void draw() const;

	};
}
