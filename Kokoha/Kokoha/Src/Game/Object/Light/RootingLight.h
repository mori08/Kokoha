#pragma once


#include "GameLight.h"


namespace Kokoha
{
	/*
	RootingLight�N���X
	���ē��p���C�g
	�v���C���[����S�[���֍����Ō�����
	*/
	class RootingLight : public GameLight
	{
	public:

		/// <summary>
		/// ���ē��p���C�g
		/// </summary>
		/// <param name="eraseSecond"> �폜�܂ł̎��� </param>
		RootingLight(double eraseSecond);

	private:

		void checkAnother(const GameObject& another)override;

	};
}