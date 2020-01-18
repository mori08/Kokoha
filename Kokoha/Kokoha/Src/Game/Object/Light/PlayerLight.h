#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	PlayerLight�N���X
	�v���C���[��ǐՂ����
	*/
	class PlayerLight : public GameLight
	{
	public:

		/// <summary>
		/// �v���C���[��ǐՂ����
		/// </summary>
		/// <param name="radius"> ���a </param> 
		PlayerLight(double radius);

	private:

		void checkAnother(const GameObject& another)override;

	};
}