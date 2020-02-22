#pragma once


#include <Siv3D.hpp>


// �V�[���̖��O
enum class SceneName
{
	TITLE,          // �^�C�g��
	
	SAVE_RECORD,    // ���R�[�h�̃Z�[�u
	LOAD_RECORD,    // ���R�[�h�̃��[�h
	LOAD_NEWGAME,   // �Q�[���̏�����

	LOAD_EVENT,     // �C�x���g�̃��[�h
	EVENT,          // �C�x���g�̎��s

	LOAD_ADVENTURE, // �T�����[�h�̃��[�h
	ADVENTURE,      // �T�����[�h

	LOAD_GAME,      // �Q�[���̃��[�h
	RELOAD_GAME,    // �Q�[���̃����[�h
	GAME            // �Q�[��
};


// �Q�[���f�[�^
struct GameData
{

};


// �V�[���Ǘ��N���X
using MyApp = SceneManager<SceneName, GameData>;
