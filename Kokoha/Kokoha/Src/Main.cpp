#include "Input/InputManager.h"


using namespace Kokoha;


void Main()
{
	while (System::Update())
	{
		InputManager::instatnce().changeInputState();

		ClearPrint();
		Print << InputManager::instatnce().decision();
		Print << InputManager::instatnce().cancel();
	}
}
