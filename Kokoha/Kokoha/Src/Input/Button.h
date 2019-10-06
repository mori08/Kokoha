#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	class Button;
	using ButtonPtr     = std::shared_ptr<Button>;
	using ButtonOnClick = std::function<void()>;

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
		std::unordered_map<Direction, ButtonPtr> mAdjacentButtonMap;

		// ���O
		const String  mName;

		// �͈�
		const Rect    mRegion;

		// �����ꂽ�Ƃ��̏���
		ButtonOnClick mOnClickFunc;

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
		ButtonPtr getAdjacentButton(const Direction& direction) const;

		/// <summary>
		/// �{�^���̖��O���擾
		/// </summary>
		/// <returns>
		/// �{�^���̖��O
		/// </returns>
		const String& getName() const
		{
			return mName;
		}

		/// <summary>
		/// �{�^���͈̔͂��擾
		/// </summary>
		/// <returns>
		/// �{�^���͈̔�
		/// </returns>
		const Rect& getRegion() const
		{
			return mRegion;
		}

		/// <summary>
		/// �������Ƃ��̏����̐ݒ�
		/// </summary>
		/// <param name="onClickFunc"> �������Ƃ��̏��� </param>
		void setOnClickFunc(const ButtonOnClick& onClickFunc)
		{
			mOnClickFunc = onClickFunc;
		}

		/// <summary>
		/// �������Ƃ��̏���
		/// </summary>
		void OnClick() const
		{
			mOnClickFunc();
		}

	};

}