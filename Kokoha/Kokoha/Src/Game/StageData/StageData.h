#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/*
	StageData�N���X
	GameManager�ň����n�`�̊Ǘ���o�H�T�����s���܂�.
	
	��) 2��ނ̍��W���ȉ��̕\���Ŏg��������.
	Vec2  pixel  -> �s�N�Z�����W : �����蔻���`��Ɏg�p
	Point square -> �}�X���W     : ��Q���̊Ǘ���o�H�T���Ɏg�p
	*/
	class StageData
	{
	public:

		static constexpr int32 WIDTH       = 20;           // �X�e�[�W�̕�(�}�X)
		static constexpr int32 HEIGHT      = 15;           // �X�e�[�W�̍���(�}�X)
		static constexpr int32 N           = WIDTH*HEIGHT; // �}�X�ڐ�
		static constexpr int32 SQUARE_SIZE = 32;           // 1�}�X�̈�ӂ̒���(�s�N�Z��)

	private:

		// �n�` true�̂Ƃ���Q������
		std::array<bool, N> mTerrain;

		// [i][j] : i -> j �ւ̍ŒZ�o�H(�P�ʃx�N�g��)
		std::array<std::array<Vec2, N>, N> mPath;

		// [i][j] : i -> j �ւ̍ŒZ����(�}�X��)
		std::array<std::array<double, N>, N> mDistance;

	public:

		/// <summary>
		/// �s�N�Z�����W����}�X���W�ɕϊ�
		/// </summary>
		/// <param name="pixel"> �s�N�Z�����W </param>
		/// <returns>
		/// �}�X���W
		/// </returns>
		static constexpr Point pixelToSquare(const Vec2& pixel)
		{
			return Floor((pixel/SQUARE_SIZE)).asPoint();
		}

		/// <summary>
		/// �}�X���W����s�N�Z�����W�ɕϊ�
		/// </summary>
		/// <param name="square"> �}�X���W </param>
		/// <returns>
		/// �}�X�̒��S�̃s�N�Z�����W
		/// </returns>
		static constexpr Vec2 squareToPixel(const Point& square)
		{
			return SQUARE_SIZE * (Vec2::One() * square + Vec2::One() / 2.0);
		}

		/// <summary>
		/// �����l������ɑΉ�����}�X���W�ɕϊ�
		/// </summary>
		/// <param name="integer"> �����l </param>
		/// <retruns>
		/// �}�X���W
		/// </returns>
		static constexpr Point integerToSquare(int32 integer)
		{
			return Point(integer % WIDTH, integer / WIDTH);
		}

		/// <summary>
		/// �}�X���W������ɑΉ����鐮���l�ɕϊ�
		/// </summary>
		/// <param name="square"> �}�X���W </param>
		/// <returns>
		/// �}�X���W�ɑΉ����鐮���l
		/// </returns>
		static constexpr int32 squareToInteger(const Point& square)
		{
			return square.x + WIDTH * square.y;
		}

	public:

		/// <summary>
		/// �w�肳�ꂽ�}�X���W���s���\��
		/// </summary>
		/// <param name="square"> �}�X���W </param>
		/// <returns>
		/// �X�e�[�W�O�ł���Ƃ����Q��������Ƃ� false , ����ȊO�̂Ƃ� true
		/// </returns>
		bool isWalkAble(const Point& square) const;

		/// <summary>
		/// �w�肳�ꂽ�s�N�Z�����W���s���\��
		/// </summary>
		/// <param name="pixel"> �s�N�Z�����W </param>
		/// <returns>
		/// �X�e�[�W�O�ł���Ƃ����Q��������Ƃ� false , ����ȊO�̂Ƃ� true
		/// </returns>
		bool isWalkAble(const Vec2& pixel) const
		{
			return isWalkAble(pixelToSquare(pixel));
		}

		/// <summary>
		/// �ŒZ�o�H�̎擾
		/// </summary>
		/// <param name="pixelS"> �n�_ (�s�N�Z�����W) </param>
		/// <param name="pixelT"> �I�_ (�s�N�Z�����W) </param>
		/// <returns>
		/// �o�H��ōŏ��ɐi�ޕ����̒P�ʃx�N�g��, �s�����Ƃ��ł��Ȃ��Ƃ� Vec2::Zero()
		/// </returns>
		Vec2 getPath(const Vec2& pixelS, const Vec2& pixelT)const;

		/// <summary>
		/// �ŒZ�����̎擾
		/// </summary>
		/// <param name="pixelS"> �n�_ (�s�N�Z�����W) </param>
		/// <param name="pixelT"> �I�_ (�s�N�Z�����W) </param>
		/// <returns>
		/// ����(�}�X��), �s�����Ƃ��ł��Ȃ��Ƃ� ������ 
		/// </returns>
		double getDistance(const Vec2& pixelS, const Vec2& pixelT)const;

		/// <summary>
		/// ������
		/// </summary>
		void init();

		/// <summary>
		/// ��Q���̐ݒu
		/// </summary>
		/// <param name="square"> �}�X���W </param>
		void setWall(const Point& square)
		{
			mTerrain[squareToInteger(square)] = true;
		}

		/// <summary>
		/// ���[�V�����E�t���C�h�@��p�����o�H�T��
		/// </summary>
		/// <remarks>
		/// O(N^3)�����鏈���ł�.
		/// �K��LoadScene�̔h���N���X���g���ĕʃX���b�h�ŏ�������.
		/// </remarks>
		void searchPath();

		/// <summary>
		/// �n�`�̕`��
		/// </summary>
		void draw()const;

	private:

		/// <summary>
		/// 2���_�Ԃ̕ӂ��擾
		/// </summary>
		/// <param name="s"> �n�_�����������l </param>
		/// <param name="t"> �I�_�����������l </param>
		/// <returns>
		/// �� { ����,�R�X�g } , �ӂ����݂��Ȃ��Ƃ� { Vec::Zero(),INF }
		/// </returns>
		std::pair<Vec2, double> getEdge(int s, int t) const;

	};
}