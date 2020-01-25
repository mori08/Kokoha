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

			static const int32 DIRECTION_NUM = 2;

			// �}�X���W
			const Point square;

			// �p�̕���
			const Point corner;

			std::array<int32, DIRECTION_NUM> mEdgeNum;

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
				mEdgeNum[0] = mEdgeNum[1] = 0;
			}

		public:

			/// <summary>
			/// �p���猩���������L���Ȃ��̂�
			/// </summary>
			/// <param name="another"> �ӂ������������_ </param>
			bool isConnectAbleEdge(const Vertex& another)const;

			/// <summary>
			/// �p���猩������
			/// </summary>
			/// <param name="another"> �ӂ������������_ </param>
			int32 getCornerDirection(const Vertex& another)const;

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
		std::unordered_map<int32, CornerGraph::Vertex> mVertexList;

		// �p�O���t�̕ӂ̃��X�g [�[�_i][�[�_j] = ����
		std::unordered_map<int32, std::unordered_map<int32, int32>> mEdgeList;

		// �e���_����̓������̌��_
		Array<std::set<int32>> mRunAwaySuggest;

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
		/// �������̎擾
		/// </summary>
		/// <param name="pixel"> ������I�u�W�F�N�g�̍��W </param>
		/// <returns> �������̍��W </returns>
		Vec2 suggest(const Vec2& pixel)const;

		/// <summary>
		/// �f�o�b�O�p�̕`��
		/// </summary>
		/// <remarks>
		/// �N���X������ɍ폜
		/// </remarks>
		void drawDebug()const;

	private:

		/// <summary>
		/// �s�v�Ȓ��_�̍폜
		/// </summary>
		/// <param name="vertexId"> ���_�ԍ� </param>
		void removeNoVertex(int32 vertexId);

	};
}