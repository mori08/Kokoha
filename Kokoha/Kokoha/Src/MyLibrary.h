#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/// <summary>
	/// �f�o�b�O�p�̕�������o��
	/// </summary>
	/// <param name="message"> �o�͂��镶���� </param>
	void printDebug(const String& message);

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
}