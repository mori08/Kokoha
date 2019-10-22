#pragma once


#include "AdventureWindow.h"


namespace Kokoha
{
	/*
	InfoWindowクラス
	テキストを表示
	*/
	class InfoWindow : public AdventureWindow
	{
	private:

		// テキスト
		String mText;

	public:

		/// <summary>
		/// テキストを表示するウィンドウ
		/// </summary>
		InfoWindow(const String& text);

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};

}
