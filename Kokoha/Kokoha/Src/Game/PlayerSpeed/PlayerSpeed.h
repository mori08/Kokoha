#pragma once


#include <queue>


namespace Kokoha
{
	/*
	PlayerSpeedクラス
	プレイヤーの速さの倍率の管理
	*/
	class PlayerSpeed
	{
	private:

		using ChangeSpeed = std::pair<double, double>;

	private:

		// 時間(秒)
		double mTime;

		// 速さの倍率
		double mSpeed;

		// 速さの変更についてのキュー { 時間,倍率 }
		std::priority_queue<ChangeSpeed, std::vector<ChangeSpeed>, std::greater<ChangeSpeed>> mChangeSpeedQueue;

	public:

		PlayerSpeed()
			: mTime(0)
			, mSpeed(0)
		{
		}

		/// <summary>
		/// 初期化
		/// </summary>
		void init();

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 速さの倍率の取得
		/// </summary>
		/// <returns>
		/// 速さの倍率
		/// </returns>
		double get()const
		{
			return mSpeed;
		}

		/// <summary>
		/// 速さの変更の設定
		/// </summary>
		/// <param name="speedRate"> 速さの倍率 </param>
		/// <param name="endTime"  > 終了時刻   </param>
		void change(double speedRate, double endTime);

	};
}