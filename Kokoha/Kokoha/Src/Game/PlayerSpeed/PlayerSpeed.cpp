#include "PlayerSpeed.h"
#include <Siv3D.hpp>


void Kokoha::PlayerSpeed::init()
{
	mTime  = 0;
	mSpeed = 1;

	// ƒLƒ…[‚Ì’†g‚ğ‹ó‚É
	while (!mChangeSpeedQueue.empty())
	{
		mChangeSpeedQueue.pop();
	}
}


void Kokoha::PlayerSpeed::update()
{
	mTime += Scene::DeltaTime();

	while (!mChangeSpeedQueue.empty() && mChangeSpeedQueue.top().first < mTime)
	{
		mSpeed *= mChangeSpeedQueue.top().second;
		mChangeSpeedQueue.pop();

		Print << mTime << U" : " << mSpeed;
	}
}


void Kokoha::PlayerSpeed::change(double speedRate, double endTime)
{
	mSpeed *= speedRate;
	mChangeSpeedQueue.push({ endTime  , 1/speedRate });

	Print << mTime << U" : " << mSpeed;
}
