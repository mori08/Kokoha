#pragma once


#include "AdventureWindow.h"
#include <thread>


namespace Kokoha
{
	/*
	SaveWindowクラス
	レコードをセーブするウィンドウ
	*/
	class SaveWindow : public AdventureWindow
	{
	private:

		// セーブ用スレッド
		std::thread mSaveThread;

		// true のとき セーブ中
		bool mIsSaving;

	public:

		SaveWindow();

	public:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	};
}