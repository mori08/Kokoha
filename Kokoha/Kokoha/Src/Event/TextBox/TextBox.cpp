#include "TextBox.h"
#include "../../Input/InputManager.h"


namespace
{
	constexpr Point TEXTBOX_DRAW_POS(0  , 320); // �e�L�X�g�{�b�N�X��\��������W
	constexpr Point ICON_DRAW_POS   (16 , 336); // �A�C�R���̕`��
	constexpr Point TEXT_DRAW_POS   (176, 336); // �e�L�X�g��\��������W
}


Kokoha::TextBox::TextBox()
	: mDrawAbleLength(0, 0)
{
}


void Kokoha::TextBox::reset()
{
	mSpeakerName    = U"";
	mIconName       = U"";
	mDrawAbleLength = Linearly<double>(0, 0);
	mText           = U"";
	mIsReady        = true;
}


void Kokoha::TextBox::set(const String& speakerName, const String& iconName, double drawSpan, const String& text)
{
	mSpeakerName    = speakerName;
	mIconName       = iconName;
	mDrawAbleLength = Linearly<double>(drawSpan * text.size(), (double)text.size());
	mText           = text;
	mIsReady        = false;
}


void Kokoha::TextBox::update()
{
	// �S�e�L�X�g��\�����Ă��邩
	bool isEnd = mDrawAbleLength.update();

	if (InputManager::instatnce().decision())
	{
		if (isEnd) { reset(); }
		else       { mDrawAbleLength.toEndPoint(); }
	}
}


void Kokoha::TextBox::draw() const
{
	TextureAsset(U"TextBox").draw(TEXTBOX_DRAW_POS);

	if (mIconName != U"")
	{
		TextureAsset(mIconName).draw(ICON_DRAW_POS);
	}

	FontAsset(U"10")(mText.substr(0, (size_t)mDrawAbleLength.getValue())).draw(TEXT_DRAW_POS);
}
