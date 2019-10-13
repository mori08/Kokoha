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
	// 指定されたディレクトリのファイルパスを配列に
	Array<FilePath> contents = FileSystem::DirectoryContents(dirName);

	for (const auto& content : contents)
	{
		String fileName = FileSystem::FileName(content);

		// 指定されたパスがディレクトリであるとき
		if (FileSystem::IsDirectory(content))
		{
			registerAsset(dirName + fileName + U"/");
		}

		// 指定されたパスがファイルであるとき
		else if (FileSystem::IsFile(content))
		{

			// 拡張子がpngのとき
			if (FileSystem::Extension(content) == U"png")
			{
				TextureAsset::Register(FileSystem::BaseName(content), dirName + fileName);
			}

			// 拡張子がmp3のとき
			else if (FileSystem::Extension(content) == U"mp3")
			{
				AudioAsset::Register(FileSystem::BaseName(content), dirName + fileName);
			}

		}
	}
}


int Kokoha::randomFrequency(double frequency)
{
	// [0,FPS] < frequency で 1 を出力
	return (Random(1.0 / Scene::DeltaTime()) < frequency) ? 1 : 0;
}

