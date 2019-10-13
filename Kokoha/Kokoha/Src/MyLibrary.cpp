#include "MyLibrary.h"


#ifdef _DEBUG
void Kokoha::printDebug(const String& message)
{
	Print << message;
}
#else
inline void Kokoha::printDebug(const String&)
{
	
}
#endif // _DEBUG


void Kokoha::registerAsset(const String& dirName)
{
	// �w�肳�ꂽ�f�B���N�g���̃t�@�C���p�X��z���
	Array<FilePath> contents = FileSystem::DirectoryContents(dirName);

	for (const auto& content : contents)
	{
		String fileName = FileSystem::FileName(content);

		// �w�肳�ꂽ�p�X���f�B���N�g���ł���Ƃ�
		if (FileSystem::IsDirectory(content))
		{
			registerAsset(dirName + fileName + U"/");
		}

		// �w�肳�ꂽ�p�X���t�@�C���ł���Ƃ�
		else if (FileSystem::IsFile(content))
		{

			// �g���q��png�̂Ƃ�
			if (FileSystem::Extension(content) == U"png")
			{
				TextureAsset::Register(FileSystem::BaseName(content), dirName + fileName);
			}

			// �g���q��mp3�̂Ƃ�
			else if (FileSystem::Extension(content) == U"mp3")
			{
				AudioAsset::Register(FileSystem::BaseName(content), dirName + fileName);
			}

		}
	}
}


int Kokoha::randomFrequency(double frequency)
{
	// [0,FPS] < frequency �� 1 ���o��
	return (Random(1.0 / Scene::DeltaTime()) < frequency) ? 1 : 0;
}

