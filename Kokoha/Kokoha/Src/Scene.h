#pragma once


#include <Siv3D.hpp>


// シーンの名前
enum class SceneName
{
	TITLE,       // タイトル
	SAVE_RECORD, // レコードのセーブ
	LOAD_RECORD  // レコードのロード
};


// ゲームデータ
struct GameData
{

};


// シーン管理クラス
using MyApp = SceneManager<SceneName, GameData>;
