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


void Kokoha::showFps()
{
#ifdef _DEBUG

	static double nowFps; // 現在のFPS
	static double maxFps; // FPSの範囲
	static double minFps; // FPSの範囲
	
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

