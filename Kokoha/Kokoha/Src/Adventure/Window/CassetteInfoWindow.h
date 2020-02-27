#pragma once


#include "AdventureWindow.h"
#include "../../Cassette/CassetteManager.h"


namespace Kokoha
{
	/*
	CassetteInfoWindow�N���X
	�J�Z�b�g�̏ڍׂ�����
	*/
	class CassetteInfoWindow : public AdventureWindow
	{
	private:

		CassettePtr mCassettePtr;

		// csv
		static CSVData sCSV;

	public:

		/// <summary>
		/// �J�Z�b�g�̏ڍ�
		/// </summary>
		/// <param name="cassette"> �J�Z�b�g </param>
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