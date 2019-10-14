#pragma once


#include <Siv3D.hpp>


namespace Kokoha
{
	/// <summary>
	/// デバッグ用の文字列を出力
	/// </summary>
	/// <param name="message"> 出力する文字列 </param>
	void printDebug(const String& message);

	/// <summary>
	/// アセット管理
	/// </summary>
	/// <param name="direName"> ディレクトリの名前 </param>
	void registerAsset(const String& dirName);

	/// <summary>
	/// 指定された頻度でランダムに 1 を出力
	/// </summary>
	/// <param name="frequency"> 頻度 (times/second) </param>
	/// <returns> 
	/// ランダムで 1 または 0 
	/// </param>
	/// <remarks>
	/// 頻度がフレームレートを超えたとき, 毎フレーム 1 を出力
	/// </remarks>
	int32 randomFrequency(double frequency);

	/// <summary>
	/// 内分点を使った値の変更
	/// </summary>
	/// <param name="x"> 変更したい値     </param>
	/// <param name="a"> 目的値           </param>
	/// <param name="r"> 内分比(0,1) (/s) </param>
	/// <remarks>
	/// r には (0,1)の範囲の小数値
	/// 数値は0に近づけるほど速く移動
	/// </remarks>
	template<typename TYPE_X, typename TYPE_A>
	void internalDividingPoint(TYPE_X& x, const TYPE_A& a, double r)
	{
		r = Pow(r, Scene::DeltaTime());
		x = r * x + (1 - r) * a;
	}

	/// <summary>
	/// FPSの表示
	/// </summary>
	void showFps();
}