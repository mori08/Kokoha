#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	PlayerLightクラス
	プレイヤーを追跡する光
	*/
	class PlayerLight : public GameLight
	{
	public:

		/// <summary>
		/// プレイヤーを追跡する光
		/// </summary>
		/// <param name="radius"> 半径 </param> 
		PlayerLight(double radius);

	private:

		void checkAnother(const GameObject& another)override;

	};
}