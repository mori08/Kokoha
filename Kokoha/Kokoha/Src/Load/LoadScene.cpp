#include "LoadScene.h"
#include "../MyColor.h"
#include "../MyLibrary.h"


namespace
{
	// ���o�̉~
	constexpr Circle LOADING_CIRCLE(500, 460, 11.0);
	// ���o�̌ʂ̑���
	constexpr double LOADING_ARC_THICNESS = 2.0;
	// ���o�̌ʂ̒���
	constexpr double LOADING_ARC_LENGTH = 5.0;
	// �����ȉ~�̌�
	constexpr int32  SMALL_CIRCLE_NUM = 10;

	// �e�L�X�g��\��������W
	constexpr Point TEXT_POS = LOADING_CIRCLE.center.asPoint() + Point(30, -15);
	// Loading�̌�ɂ��� . �̐��̍ő�l
	constexpr int32 MAX_DOT_NUM = 4;
}


Kokoha::LoadScene::LoadScene(const InitData& init, const String& text)
	: IScene(init)
	, mIsLoading(true)
	, mText(text)
	, mError(none)
{
	// �ʃX���b�h�̍쐬
	mLoadThread = std::thread
	(
		[this]()
		{
			mError     = load();
			mIsLoading = false;
		}
	);
}


Kokoha::LoadScene::~LoadScene()
{
	if (mLoadThread.joinable())
	{
		mLoadThread.join();
	}
}


void Kokoha::LoadScene::update()
{
	if (mIsLoading) { return; }

	mLoadThread.join();

	if (mError)
	{
		printDebug(mError.value());
	}

	if (!changeScene(complete()))
	{
		changeScene(SceneName::TITLE);
	}
}


void Kokoha::LoadScene::draw() const
{
	static double angle = 0;
	angle += Scene::DeltaTime();

	for (int32 i = 0; i < SMALL_CIRCLE_NUM; ++i)
	{
		double a = Math::TwoPi * i / SMALL_CIRCLE_NUM - angle;

		Circle
		(
			LOADING_CIRCLE.center + LOADING_CIRCLE.r * Vec2(Cos(a), Sin(a)),
			LOADING_ARC_THICNESS
		).draw(Color(MyWhite, 0xA0));
	}

	LOADING_CIRCLE.drawArc(angle, LOADING_ARC_LENGTH, LOADING_ARC_THICNESS, LOADING_ARC_THICNESS, MyWhite);

	static double t = 0;
	t += Scene::DeltaTime();
	FontAsset(U"20")(mText + String(U"...").substr(0,(int32)t%MAX_DOT_NUM)).draw(TEXT_POS);
}


void Kokoha::LoadScene::drawFadeIn(double) const
{
	draw();
}


void Kokoha::LoadScene::drawFadeOut(double) const
{
	draw();
}
