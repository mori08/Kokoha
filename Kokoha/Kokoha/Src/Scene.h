#pragma once


#include <Siv3D.hpp>


// �V�[���̖��O
enum class SceneName
{
	TITLE,      // �^�C�g��
	SAVE_RECORD // ���R�[�h�̃Z�[�u
};


// �Q�[���f�[�^
struct GameData
{

};


// �V�[���Ǘ��N���X
using MyApp = SceneManager<SceneName, GameData>;
