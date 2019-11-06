#include "PlayerSpeed.h"
#include <Siv3D.hpp>


void Kokoha::PlayerSpeed::init()
{
	mTime  = 0;
	mSpeed = 1;

	// キューの中身を空に
	while (!mChangeSpeedQueue.empty())
	{
		mChangeSpeedQueue.pop();
	}
}


void Kokoha::PlayerSpeed::update()
{
	mTime += Scene::DeltaTime();

	while (!mChangeSpeedQueue.empty() && mChangeSpeedQueue.top().first > mTime)
	{
		mSpeed *= mChangeSpeedQueue.top().second;
	}
}


void Kokoha::PlayerSpeed::change(double speedRate, double beginTime, double endTime)
{
	mChangeSpeedQueue.push({ beginTime,speedRate });
	mChangeSpeedQueue.push({ endTime,1/speedRate });
}
