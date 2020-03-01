#include "MyLibrary.h"


void Kokoha::outputResource(const FilePath& dirName)
{
#ifdef _DEBUG
	
	static TextWriter writer(U"ResourceList.txt");
	// static TextWriter assetNameWriter(U"AssetName.txt");

	// 指定されたディレクトリのファイルパスを配列に
	Array<FilePath> contents = FileSystem::DirectoryContents(dirName, false);

	for (const auto& content : contents)
	{
		String fileName = FileSystem::FileName(content);

		// 指定されたパスがディレクトリであるとき
		if (FileSystem::IsDirectory(content))
		{
			outputResource(dirName + fileName + U"/");
		}

		// 指定されたパスがファイルであるとき
		else if (FileSystem::IsFile(content))
		{
			writer.writeln(U"Resource(" + dirName + fileName + U")");

			if (FileSystem::Extension(content) == U"png")
			{
				//assetNameWriter.writeln(U"TextureAsset::Register(U\"" + FileSystem::BaseName(content) + U"\", Resource(U\"" + dirName + fileName + U"\"));");
			}
		}
	}
	
#endif
}


void Kokoha::registerAsset(const String& dirName)
{
#ifdef _DEBUG

	// 指定されたディレクトリのファイルパスを配列に
	Array<FilePath> contents = FileSystem::DirectoryContents(dirName, false);

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
				TextureAsset::Register(FileSystem::BaseName(content), Resource(dirName + fileName));
			}

		}
	}

#else

	TextureAsset::Register(U"BlackBack", Resource(U"Assets/Texture/Event_Adventure/BackGround/BlackBack.png"));
	TextureAsset::Register(U"DeveloperPhoto", Resource(U"Assets/Texture/Event_Adventure/BackGround/BrokenPhoto/DeveloperPhoto.png"));
	TextureAsset::Register(U"DoctorPhoto", Resource(U"Assets/Texture/Event_Adventure/BackGround/BrokenPhoto/DoctorPhoto.png"));
	TextureAsset::Register(U"Repair0Photo", Resource(U"Assets/Texture/Event_Adventure/BackGround/BrokenPhoto/Repair0Photo.png"));
	TextureAsset::Register(U"Repair1Photo", Resource(U"Assets/Texture/Event_Adventure/BackGround/BrokenPhoto/Repair1Photo.png"));
	TextureAsset::Register(U"Repair2Photo", Resource(U"Assets/Texture/Event_Adventure/BackGround/BrokenPhoto/Repair2Photo.png"));
	TextureAsset::Register(U"Searcher0Photo", Resource(U"Assets/Texture/Event_Adventure/BackGround/BrokenPhoto/Searcher0Photo.png"));
	TextureAsset::Register(U"Searcher1Photo", Resource(U"Assets/Texture/Event_Adventure/BackGround/BrokenPhoto/Searcher1Photo.png"));
	TextureAsset::Register(U"Entrance", Resource(U"Assets/Texture/Event_Adventure/BackGround/Entrance.png"));
	TextureAsset::Register(U"GarbageDump(now)", Resource(U"Assets/Texture/Event_Adventure/BackGround/GarbageDump(now).png"));
	TextureAsset::Register(U"GarbageDump", Resource(U"Assets/Texture/Event_Adventure/BackGround/GarbageDump.png"));
	TextureAsset::Register(U"Labolatory(now)", Resource(U"Assets/Texture/Event_Adventure/BackGround/Labolatory(now).png"));
	TextureAsset::Register(U"Labolatory", Resource(U"Assets/Texture/Event_Adventure/BackGround/Labolatory.png"));
	TextureAsset::Register(U"LastRoom", Resource(U"Assets/Texture/Event_Adventure/BackGround/LastRoom.png"));
	TextureAsset::Register(U"Library(now)", Resource(U"Assets/Texture/Event_Adventure/BackGround/Library(now).png"));
	TextureAsset::Register(U"Library", Resource(U"Assets/Texture/Event_Adventure/BackGround/Library.png"));
	TextureAsset::Register(U"LibraryAndPC", Resource(U"Assets/Texture/Event_Adventure/BackGround/LibraryAndPC.png"));
	TextureAsset::Register(U"StoreRoom(now)", Resource(U"Assets/Texture/Event_Adventure/BackGround/StoreRoom(now).png"));
	TextureAsset::Register(U"StoreRoom", Resource(U"Assets/Texture/Event_Adventure/BackGround/StoreRoom.png"));
	TextureAsset::Register(U"TutorialBack", Resource(U"Assets/Texture/Event_Adventure/BackGround/TutorialBack.png"));
	TextureAsset::Register(U"WhiteBack", Resource(U"Assets/Texture/Event_Adventure/BackGround/WhiteBack.png"));
	TextureAsset::Register(U"WorkSpace(now)", Resource(U"Assets/Texture/Event_Adventure/BackGround/WorkSpace(now).png"));
	TextureAsset::Register(U"WorkSpace(old)", Resource(U"Assets/Texture/Event_Adventure/BackGround/WorkSpace(old).png"));
	TextureAsset::Register(U"WorkSpace", Resource(U"Assets/Texture/Event_Adventure/BackGround/WorkSpace.png"));
	TextureAsset::Register(U"Accel1Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Accel1Cassette.png"));
	TextureAsset::Register(U"Accel2Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Accel2Cassette.png"));
	TextureAsset::Register(U"Accel3Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Accel3Cassette.png"));
	TextureAsset::Register(U"CassetteIcon", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/CassetteIcon.png"));
	TextureAsset::Register(U"Cost", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Cost.png"));
	TextureAsset::Register(U"Cursor1Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Cursor1Cassette.png"));
	TextureAsset::Register(U"Cursor2Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Cursor2Cassette.png"));
	TextureAsset::Register(U"DashCassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/DashCassette.png"));
	TextureAsset::Register(U"FlashCassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/FlashCassette.png"));
	TextureAsset::Register(U"Goal1Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Goal1Cassette.png"));
	TextureAsset::Register(U"Goal2Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Goal2Cassette.png"));
	TextureAsset::Register(U"KokoroCassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/KokoroCassette.png"));
	TextureAsset::Register(U"NoIconCassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/NoIconCassette.png"));
	TextureAsset::Register(U"Player1Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Player1Cassette.png"));
	TextureAsset::Register(U"Player2Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Player2Cassette.png"));
	TextureAsset::Register(U"Random1Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Random1Cassette.png"));
	TextureAsset::Register(U"Random2Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Random2Cassette.png"));
	TextureAsset::Register(U"Random3Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Random3Cassette.png"));
	TextureAsset::Register(U"Speed1Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Speed1Cassette.png"));
	TextureAsset::Register(U"Speed2Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Speed2Cassette.png"));
	TextureAsset::Register(U"Speed3Cassette", Resource(U"Assets/Texture/Event_Adventure/CassetteIcon/Speed3Cassette.png"));
	TextureAsset::Register(U"Entrance(dvlp)", Resource(U"Assets/Texture/Event_Adventure/Development/Entrance(dvlp).png"));
	TextureAsset::Register(U"GarbageDump(dvlp)", Resource(U"Assets/Texture/Event_Adventure/Development/GarbageDump(dvlp).png"));
	TextureAsset::Register(U"Labolatory(dvlp)", Resource(U"Assets/Texture/Event_Adventure/Development/Labolatory(dvlp).png"));
	TextureAsset::Register(U"Labolatory(old)(dvlp)", Resource(U"Assets/Texture/Event_Adventure/Development/Labolatory(old)(dvlp).png"));
	TextureAsset::Register(U"LastRoom(dvlp)", Resource(U"Assets/Texture/Event_Adventure/Development/LastRoom(dvlp).png"));
	TextureAsset::Register(U"Library(dvlp)", Resource(U"Assets/Texture/Event_Adventure/Development/Library(dvlp).png"));
	TextureAsset::Register(U"StoreRoom(dvlp)", Resource(U"Assets/Texture/Event_Adventure/Development/StoreRoom(dvlp).png"));
	TextureAsset::Register(U"WorkSpace(dvlp)", Resource(U"Assets/Texture/Event_Adventure/Development/WorkSpace(dvlp).png"));
	TextureAsset::Register(U"BookShelf", Resource(U"Assets/Texture/Event_Adventure/Object/BookShelf.png"));
	TextureAsset::Register(U"Boxes", Resource(U"Assets/Texture/Event_Adventure/Object/Boxes.png"));
	TextureAsset::Register(U"BrokenPoster", Resource(U"Assets/Texture/Event_Adventure/Object/BrokenPoster.png"));
	TextureAsset::Register(U"BulletinBoard", Resource(U"Assets/Texture/Event_Adventure/Object/BulletinBoard.png"));
	TextureAsset::Register(U"Cardboard", Resource(U"Assets/Texture/Event_Adventure/Object/Cardboard.png"));
	TextureAsset::Register(U"CeilingCode", Resource(U"Assets/Texture/Event_Adventure/Object/CeilingCode.png"));
	TextureAsset::Register(U"CheckIcon", Resource(U"Assets/Texture/Event_Adventure/Object/CheckIcon.png"));
	TextureAsset::Register(U"Code", Resource(U"Assets/Texture/Event_Adventure/Object/Code.png"));
	TextureAsset::Register(U"DeadDoctor", Resource(U"Assets/Texture/Event_Adventure/Object/DeadDoctor.png"));
	TextureAsset::Register(U"DoctorDesk", Resource(U"Assets/Texture/Event_Adventure/Object/DoctorDesk.png"));
	TextureAsset::Register(U"DoctorWorkbench", Resource(U"Assets/Texture/Event_Adventure/Object/DoctorWorkbench.png"));
	TextureAsset::Register(U"Door[DoctorRoom]", Resource(U"Assets/Texture/Event_Adventure/Object/Door[DoctorRoom].png"));
	TextureAsset::Register(U"Door[Entrance]", Resource(U"Assets/Texture/Event_Adventure/Object/Door[Entrance].png"));
	TextureAsset::Register(U"Door[GarbageDump]", Resource(U"Assets/Texture/Event_Adventure/Object/Door[GarbageDump].png"));
	TextureAsset::Register(U"Door[Labolatory]", Resource(U"Assets/Texture/Event_Adventure/Object/Door[Labolatory].png"));
	TextureAsset::Register(U"Door[LastRoom]", Resource(U"Assets/Texture/Event_Adventure/Object/Door[LastRoom].png"));
	TextureAsset::Register(U"Door[Library]", Resource(U"Assets/Texture/Event_Adventure/Object/Door[Library].png"));
	TextureAsset::Register(U"Door[StoreRoom]", Resource(U"Assets/Texture/Event_Adventure/Object/Door[StoreRoom].png"));
	TextureAsset::Register(U"EntranceGate", Resource(U"Assets/Texture/Event_Adventure/Object/EntranceGate.png"));
	TextureAsset::Register(U"Invisible", Resource(U"Assets/Texture/Event_Adventure/Object/Invisible.png"));
	TextureAsset::Register(U"LaboWorkbench", Resource(U"Assets/Texture/Event_Adventure/Object/LaboWorkbench.png"));
	TextureAsset::Register(U"LightBulb", Resource(U"Assets/Texture/Event_Adventure/Object/LightBulb.png"));
	TextureAsset::Register(U"Monitor", Resource(U"Assets/Texture/Event_Adventure/Object/Monitor.png"));
	TextureAsset::Register(U"OpenedCardboard", Resource(U"Assets/Texture/Event_Adventure/Object/OpenedCardboard.png"));
	TextureAsset::Register(U"OpenEntranceGate", Resource(U"Assets/Texture/Event_Adventure/Object/OpenEntranceGate.png"));
	TextureAsset::Register(U"PC", Resource(U"Assets/Texture/Event_Adventure/Object/PC.png"));
	TextureAsset::Register(U"Poster0x22c", Resource(U"Assets/Texture/Event_Adventure/Object/Poster0x22c.png"));
	TextureAsset::Register(U"BoxRobot", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BoxRobot.png"));
	TextureAsset::Register(U"BrokenBoxRobot", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenBoxRobot.png"));
	TextureAsset::Register(U"BrokenDeveloper", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenDeveloper.png"));
	TextureAsset::Register(U"BrokenHelpRobot", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenHelpRobot.png"));
	TextureAsset::Register(U"BrokenRepair0", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenRepair0.png"));
	TextureAsset::Register(U"BrokenRepair1", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenRepair1.png"));
	TextureAsset::Register(U"BrokenRepair2", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenRepair2.png"));
	TextureAsset::Register(U"BrokenResearcher", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenResearcher.png"));
	TextureAsset::Register(U"BrokenSearcher0", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenSearcher0.png"));
	TextureAsset::Register(U"BrokenSearcher1", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenSearcher1.png"));
	TextureAsset::Register(U"BrokenSearcher2", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/BrokenSearcher2.png"));
	TextureAsset::Register(U"Developer", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/Developer.png"));
	TextureAsset::Register(U"HelpRobot", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/HelpRobot.png"));
	TextureAsset::Register(U"MainRobot", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/MainRobot.png"));
	TextureAsset::Register(U"Repair0", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/Repair0.png"));
	TextureAsset::Register(U"Repair1", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/Repair1.png"));
	TextureAsset::Register(U"Repair2", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/Repair2.png"));
	TextureAsset::Register(U"Researcher", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/Researcher.png"));
	TextureAsset::Register(U"Searcher0", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/Searcher0.png"));
	TextureAsset::Register(U"Searcher1", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/Searcher1.png"));
	TextureAsset::Register(U"Searcher2", Resource(U"Assets/Texture/Event_Adventure/Object/Robot/Searcher2.png"));
	TextureAsset::Register(U"Shelf", Resource(U"Assets/Texture/Event_Adventure/Object/Shelf.png"));
	TextureAsset::Register(U"TrashBox", Resource(U"Assets/Texture/Event_Adventure/Object/TrashBox.png"));
	TextureAsset::Register(U"BoxRobotIcon", Resource(U"Assets/Texture/Event_Adventure/TextBox/BoxRobotIcon.png"));
	TextureAsset::Register(U"DeveloperIcon", Resource(U"Assets/Texture/Event_Adventure/TextBox/DeveloperIcon.png"));
	TextureAsset::Register(U"DoctorIcon", Resource(U"Assets/Texture/Event_Adventure/TextBox/DoctorIcon.png"));
	TextureAsset::Register(U"EntranceGateIcon", Resource(U"Assets/Texture/Event_Adventure/TextBox/EntranceGateIcon.png"));
	TextureAsset::Register(U"HelpRobotIcon", Resource(U"Assets/Texture/Event_Adventure/TextBox/HelpRobotIcon.png"));
	TextureAsset::Register(U"MainRobotIcon", Resource(U"Assets/Texture/Event_Adventure/TextBox/MainRobotIcon.png"));
	TextureAsset::Register(U"Repair0Icon", Resource(U"Assets/Texture/Event_Adventure/TextBox/Repair0Icon.png"));
	TextureAsset::Register(U"Repair1Icon", Resource(U"Assets/Texture/Event_Adventure/TextBox/Repair1Icon.png"));
	TextureAsset::Register(U"Repair2Icon", Resource(U"Assets/Texture/Event_Adventure/TextBox/Repair2Icon.png"));
	TextureAsset::Register(U"ResearcherIcon", Resource(U"Assets/Texture/Event_Adventure/TextBox/ResearcherIcon.png"));
	TextureAsset::Register(U"Searcher0Icon", Resource(U"Assets/Texture/Event_Adventure/TextBox/Searcher0Icon.png"));
	TextureAsset::Register(U"Searcher1Icon", Resource(U"Assets/Texture/Event_Adventure/TextBox/Searcher1Icon.png"));
	TextureAsset::Register(U"Searcher2Icon", Resource(U"Assets/Texture/Event_Adventure/TextBox/Searcher2Icon.png"));
	TextureAsset::Register(U"TextBox", Resource(U"Assets/Texture/Event_Adventure/TextBox/TextBox.png"));
	TextureAsset::Register(U"Attack", Resource(U"Assets/Texture/Game/Attack.png"));
	TextureAsset::Register(U"BlackEnemy", Resource(U"Assets/Texture/Game/BlackEnemy.png"));
	TextureAsset::Register(U"Enemy", Resource(U"Assets/Texture/Game/Enemy.png"));
	TextureAsset::Register(U"Goal", Resource(U"Assets/Texture/Game/Goal.png"));
	TextureAsset::Register(U"GoalKey", Resource(U"Assets/Texture/Game/GoalKey.png"));
	TextureAsset::Register(U"Hole", Resource(U"Assets/Texture/Game/Hole.png"));
	TextureAsset::Register(U"Level", Resource(U"Assets/Texture/Game/Level.png"));
	TextureAsset::Register(U"Patrol", Resource(U"Assets/Texture/Game/Patrol.png"));
	TextureAsset::Register(U"Player", Resource(U"Assets/Texture/Game/Player.png"));
	TextureAsset::Register(U"WhiteEnemy", Resource(U"Assets/Texture/Game/WhiteEnemy.png"));
	TextureAsset::Register(U"Logo", Resource(U"Assets/Texture/Title/Logo.png"));



#endif
}


void Kokoha::readCSV(CSVData& csv, const String& fileName)
{
#ifdef _DEBUG

	csv.load(fileName);

#else

	csv.load(Resource(fileName));

#endif
}


int Kokoha::randomFrequency(double frequency)
{
	// [0,FPS] < frequency で 1 を出力
	return (Random(1.0 / Scene::DeltaTime()) < frequency) ? 1 : 0;
}


void Kokoha::showFps()
{
#ifdef _DEBUG

	static std::list<double> fpsList;
	static Array<double> showNum(5, 60.0);

	double deltaTime = Scene::DeltaTime();
	if (deltaTime > 1.0 / 1e10 && deltaTime < 1e10)
	{
		fpsList.emplace_back(1 / deltaTime);
		if (fpsList.size() > 60) { fpsList.pop_front(); }
	}

	if (fpsList.size() < 60) { return; }

	std::vector<double> fpsVector;
	for (const auto& fps : fpsList) { fpsVector.emplace_back(fps); }
	std::sort(fpsVector.begin(), fpsVector.end());

	internalDividingPoint(showNum[0], fpsVector[0], 0.3);
	internalDividingPoint(showNum[1], (fpsVector[14] + fpsVector[15]) / 2, 0.3);
	internalDividingPoint(showNum[2], (fpsVector[29] + fpsVector[30]) / 2, 0.3);
	internalDividingPoint(showNum[3], (fpsVector[44] + fpsVector[45]) / 2, 0.3);
	internalDividingPoint(showNum[4], fpsVector[59], 0.3);

	const double rate = 640.0 / 60.0;
	const double offset = -320;

	Line(rate * showNum[0] + offset, 0, rate * showNum[4] + offset, 0).draw(8, Palette::Blue);
	Line(rate * showNum[1] + offset, 0, rate * showNum[3] + offset, 0).draw(10, Palette::Aqua);
	Circle(rate * showNum[2] + offset, 7, 2).draw(Palette::Aqua);
	FontAsset(U"20")(Profiler::FPS()).drawAt(rate * Profiler::FPS() + offset, 15, Palette::Aqua);

	FontAsset(U"10")((int32)showNum[0]).drawAt(Max(10.0 , rate * showNum[0] + offset), 8, Palette::Blue);
	FontAsset(U"10")((int32)showNum[4]).drawAt(Min(630.0, rate * showNum[4] + offset), 8, Palette::Blue);


#endif // _DEBUG
}


Array<Point> Kokoha::getGridPoint(const Rect& rect)
{
	Array<Point> rtn;

	for (int32 x : Range(rect.x, rect.x + rect.w))
	{
		for (int32 y : Range(rect.y, rect.y + rect.h))
		{
			rtn.emplace_back(x, y);
		}
	}

	return std::move(rtn);
}

