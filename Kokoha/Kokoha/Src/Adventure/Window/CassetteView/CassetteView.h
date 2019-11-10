#pragma once


#include "../../../Cassette/Cassette/Cassette.h"


namespace Kokoha
{
	/*
	CassetteView�N���X
	SetupWindow�Ŏ�Ɏg�p
	�J�Z�b�g�̈ꗗ������
	*/
	class CassetteView
	{
	private:

		// �擪�̃C���f�b�N�X
		int32 mBeginId;

		// �{�^���ɂ��閼�O
		const String mButtonName;

		// �`����W
		const Point mDrawPoint;

	public:

		CassetteView(const Point& drawPos,const String& buttonName);

		/// <summary>
		/// �{�^����ButtonManager�ɃZ�b�g
		/// </summary>
		void setButton() const;

		/// <summary>
		/// �X�V
		/// </summary>
		/// <param name="cassetteSet"> �J�Z�b�g�̏W�� </param>
		void update(const CassettePtrSet& cassetteSet);

		/// <summary>
		/// �`��
		/// </summary>
		/// <param name="cassetteSet"> �J�Z�b�g�̏W�� </param>
		void draw(const CassettePtrSet& cassetteSet) const;

	};
}
