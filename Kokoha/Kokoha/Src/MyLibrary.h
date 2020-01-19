#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
#ifdef _DEBUG
	/// <summary>
	/// �f�o�b�O�p�̕�������o��
	/// </summary>
	/// <param name="message"> �o�͂��镶���� </param>
	inline void printDebug(const String& message)
	{
		Print << message;
	}
#else
	inline void printDebug(const String&)
	{

	}
#endif // _DEBUG

	/// <summary>
	/// �A�Z�b�g�Ǘ�
	/// </summary>
	/// <param name="direName"> �f�B���N�g���̖��O </param>
	void registerAsset(const String& dirName);

	/// <summary>
	/// �w�肳�ꂽ�p�x�Ń����_���� 1 ���o��
	/// </summary>
	/// <param name="frequency"> �p�x (times/second) </param>
	/// <returns> 
	/// �����_���� 1 �܂��� 0 
	/// </param>
	/// <remarks>
	/// �p�x���t���[�����[�g�𒴂����Ƃ�, ���t���[�� 1 ���o��
	/// </remarks>
	int32 randomFrequency(double frequency);

	/// <summary>
	/// �����_���g�����l�̕ύX
	/// </summary>
	/// <param name="x"> �ύX�������l     </param>
	/// <param name="a"> �ړI�l           </param>
	/// <param name="r"> ������(0,1) (/s) </param>
	/// <remarks>
	/// r �ɂ� (0,1)�͈̔͂̏����l
	/// ���l��0�ɋ߂Â���قǑ����ړ�
	/// </remarks>
	template<typename TYPE_X, typename TYPE_A>
	void internalDividingPoint(TYPE_X& x, const TYPE_A& a, double r)
	{
		r = Pow(r, Scene::DeltaTime());
		x = r * x + (1 - r) * a;
	}

	/// <summary>
	/// FPS�̕\��
	/// </summary>
	void showFps();

	/// <summary>
	/// ���S���W�����߂������`�̎擾
	/// </summary>
	/// <param name="center"> ���S���W </param>
	/// <param name="size">   �T�C�Y   </param>
	/// <returns> �����` </returns>
	inline constexpr Rect getRectFromCenter(const Point& center, const Size& size)
	{
		return std::move(Rect(center - size / 2, size));
	}

	/// <summary>
	/// 2���_���璷���`�̎擾
	/// </summary>
	/// <param name="pos1"> ���_1 </param>
	/// <param name="pos2"> ���_2 </param>
	/// <returns> �����` </returns>
	inline constexpr Rect getRectFromTwoPoint(const Point& pos1, const Point& pos2)
	{
		return std::move(Rect(Min(pos1.x, pos2.x), Min(pos1.y, pos2.y), Abs(pos1.x - pos2.x), Abs(pos1.y - pos2.y)));
	}

	/// <summary>
	/// �����`���ɂ���i�q�_�̃��X�g�̎擾
	/// </summary>
	/// <param name="rect"> �����` </param>
	/// <returns> �i�q�_ </returns>
	Array<Point> getGridPoint(const Rect& rect);

}