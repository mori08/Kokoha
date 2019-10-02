#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	class Button;
	using ButtonPtr = std::shared_ptr<Button>;

	/*
	Button�N���X
	���ButtonManager�Ŏg�p����.
	*/
	class Button
	{
	public:

		enum class Direction
		{
			UP,   // ��
			DOWN, // ��
			LEFT, // ��
			RIGHT // �E
		};

	private:

		// �אڃ{�^���̃}�b�v
		std::unordered_map<Direction, std::shared_ptr<Button>> mAdjacentButtonMap;

		// ���O
		const String mName;

		// �͈�
		const Rect   mRegion;

	public:

		/// <summary>
		/// �{�^��
		/// </summary>
		/// <param name="name">   ���O </param>
		/// <param name="region"> �͈� </param>
		Button(const String& name, const Rect& region);

	public:

		/// <summary>
		/// �אڂ���{�^����ݒ�
		/// </summary>
		/// <param name="direction">         ����                     </param>
		/// <param name="adjacentButtonPtr"> �אڂ���{�^���̃|�C���^ </param>
		void setAdjacentButton(const Direction& direction, ButtonPtr adjacentButtonPtr);

		/// <summary>
		/// �w�肳�ꂽ�����ɗאڂ���{�^���̃|�C���^�̎擾
		/// </summary>
		/// <param name="direction"> ���� </param>
		/// <returns>
		/// �w�肳�ꂽ�����ɗאڂ���{�^���̃|�C���^
		/// </returns>
		std::shared_ptr<Button> getAdjacentButton(const Direction& direction);

		/// <summary>
		/// �{�^���̖��O���擾
		/// </summary>
		/// <returns>
		/// �{�^���̖��O
		/// </returns>
		const String& getName() const;

		/// <summary>
		/// �{�^���͈̔͂��擾
		/// </summary>
		/// <returns>
		/// �{�^���͈̔�
		/// </returns>
		const Rect& getRegion() const;

	};

}