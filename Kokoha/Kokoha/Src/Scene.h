#pragma once


#include <Siv3D.hpp>


// シーンの名前
enum class SceneName
{
	TITLE,          // タイトル
	
	SAVE_RECORD,    // レコードのセーブ
	LOAD_RECORD,    // レコードのロード
	LOAD_NEWGAME,   // ゲームの初期化

	LOAD_EVENT,     // イベントのロード
	EVENT,          // イベントの実行

	LOAD_ADVENTURE, // 探索モードのロード
	ADVENTURE,      // 探索モード

	LOAD_GAME,      // ゲームのロード
	RELOAD_GAME,    // ゲームのリロード
	GAME            // ゲーム
};


// ゲームデータ
struct GameData
{

};


// シーン管理クラス
using MyApp = SceneManager<SceneName, GameData>;
