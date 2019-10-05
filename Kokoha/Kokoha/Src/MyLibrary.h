#pragma once


#include <Siv3D.hpp>
#include <HamFramework.hpp>


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

}