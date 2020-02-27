#pragma once


#include "AdventureWindow.h"
#include "../../Cassette/CassetteManager.h"


namespace Kokoha
{
	/*
	CassetteInfoWindowクラス
	カセットの詳細を示す
	*/
	class CassetteInfoWindow : public AdventureWindow
	{
	private:

		CassettePtr mCassettePtr;

		// csv
		static CSVData sCSV;

	public:

		/// <summary>
		/// カセットの詳細
		/// </summary>
		/// <param name="cassette"> カセット </param>
		CassetteInfoWindow(const CassettePtr& cassette);

	private:

		void select() override;

		void update() override;

		void selectedUpdate() override;

		void draw() const override;

	public:

		static void readCSVData();

	};
}