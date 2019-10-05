#pragma once


#include <Siv3D.hpp>
#include <HamFramework.hpp>


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

}