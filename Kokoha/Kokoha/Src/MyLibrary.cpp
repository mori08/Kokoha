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


void Kokoha::showFps()
{
#ifdef _DEBUG

	static double nowFps; // ���݂�FPS
	static double maxFps; // FPS�͈̔�
	static double minFps; // FPS�͈̔�
	
	double deltaTime = Scene::DeltaTime();
	if (deltaTime > 1 / 360.0 && deltaTime < 10e5) { nowFps = 1 / deltaTime; }

	Kokoha::internalDividingPoint(maxFps, nowFps, 0.7); maxFps = Max(maxFps, nowFps);
	Kokoha::internalDividingPoint(minFps, nowFps, 0.7); minFps = Min(minFps, nowFps);

	Line(0.0, 0.0, 640 * nowFps / 180, 0.0).draw(5, Palette::Green);
	FontAsset(U"10")((int32)maxFps).drawAt(Min(640 * maxFps / 180, 620.0), 10, Palette::Blue);
	FontAsset(U"10")((int32)minFps).drawAt(640 * minFps / 180, 10, Palette::Red);
	FontAsset(U"10")(Profiler::FPS()).drawAt(640 * Profiler::FPS() / 180, 10, Palette::Green);

#endif // _DEBUG
}

