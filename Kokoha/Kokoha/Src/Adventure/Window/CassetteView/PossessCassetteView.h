#pragma once


#include "../../../Cassette/Cassette/Cassette.h"


namespace Kokoha
{
	/*
	PossessCassetteViewクラス
	SetupWindowで所持しているカセットの操作・描画
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
