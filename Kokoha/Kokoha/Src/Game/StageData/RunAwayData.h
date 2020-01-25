#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	�p�O���t
	�p�𒸓_�Ƃ����O���t�Ń}�X�̕]���Ȃǂɖ𗧂�����
	*/
	namespace CornerGraph
	{
		// ���_
		class Vertex
		{
		public:

			// �}�X���W
			const Point square;

			// �p�̕���
			const Point corner;

		public:

			/// <summary>
			/// �p�O���t�̒��_
			/// </summary>
			/// <param name="s"> �}�X���W </param>
			/// <param name="c"> �p�̕��� </param>
			Vertex(const Point& s, const Point& c)
				: square(s)
				, corner(c)
			{
			}

		};
	}


	/*
	RunAwayData�N���X
	�v���C���[���瓦����I�u�W�F�N�g���K�v�Ƃ�����̌v�Z�E�Ǘ�
	*/
	class RunAwayData
	{
	private:

		// �p�O���t�̒��_�̃��X�g
		std::unordered_map<int32, CornerGraph::Vertex> mCornerVertexList;

	public:

		/// <summary>
		/// �p�O���t�̍쐬
		/// </summary>
		/// <remarks>
		/// O(N^3)�����鏈��
		/// LoadScene�̔h���N���X���g���ď�������
		/// </remarks>
		void makeCornerGraph();

		/// <summary>
		/// �f�o�b�O�p�̕`��
		/// </summary>
		/// <remarks>
		/// �N���X������ɍ폜
		/// </remarks>
		void drawDebug()const;

	};
}