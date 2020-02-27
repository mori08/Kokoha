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

	private:

		/// <summary>
		/// コストの描画
		/// </summary>
		/// <param name="pos"> 座標   </param>
		/// <param name="pos"> 装備ID </param>
		void drawCost(const Point& pos, const int32 id) const;

	};
}