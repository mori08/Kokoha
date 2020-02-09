#pragma once


#include "../../GameObject.h"


namespace Kokoha
{
	/*
	GameGoalKey�N���X
	�S�[�����J���錮
	*/
	class GameGoalKey : public GameObject
	{
	private:

		// �v���C���[�ɐڐG true
		bool mIsChecked;

		// �ړI���W
		Vec2 mGoal;

	public:

		GameGoalKey(const Vec2& pos);

		virtual void update();

		void draw() const;

		void checkAnother(const GameObject& another);

		/// <summary>
		/// �v���C���[�ɐڐG�ς݂��� true
		/// </summary>
		bool isChecked() const
		{
			return mIsChecked;
		}

	};
}