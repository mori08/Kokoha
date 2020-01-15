#pragma once


#include "../../../Cassette/Cassette/Cassette.h"


namespace Kokoha
{
	/*
	EquipmentCassetteViewクラス
	SetUpWindowで装備しているカセットの操作・描画
	*/
	class EquipmentCassetteView
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