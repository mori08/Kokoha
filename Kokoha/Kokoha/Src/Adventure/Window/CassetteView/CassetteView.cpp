#include "CassetteView.h"
#include "../CassetteMoveWindow.h"
#include "../../AdventureManager.h"
#include "../../../Input/ButtonManager.h"
#include "../../../Cassette/CassetteManager.h"


namespace
{
	// ボタンの数
	constexpr int32 BUTTON_NUM = 10;

	// サイズ
	constexpr Size BUTTON_SIZE(150, 30);

	// マウス入力を受け付ける範囲
	constexpr Size VIEW_SIZE(BUTTON_SIZE.x, BUTTON_NUM * BUTTON_SIZE.y);
}


Kokoha::CassetteView::CassetteView(const Point& drawPos,const String& buttonName)
	: mBeginId(0)
	, mDrawPoint(drawPos)
	, mButtonName(buttonName)
{
}


void Kokoha::CassetteView::setButton()const
{
	Rect region(mDrawPoint, BUTTON_SIZE);

	// ボタンの設定
	for (int32 i = 0; i < BUTTON_NUM; ++i)
	{
		ButtonManager::instance().registerButton
		(
			mButtonName + ToString(i),
			region
		);

		region.y += BUTTON_SIZE.y;
	}

	// ボタンの位置関係の設定
	for (int32 i = 0; i < BUTTON_NUM-1; ++i)
	{
		ButtonManager::instance().setVerticalAdjacentButton
		(
			mButtonName + ToString(i),
			mButtonName + ToString(i + 1)
		);
	}
}


void Kokoha::CassetteView::update(const CassettePtrSet& cassetteSet, int32 selectedEquipmentId)
{
	const auto& selectedButton = ButtonManager::instance().getSelectedButton();

	// 表示するカセットを一つ前に
	if ((KeyW.down() || (Mouse::Wheel() > 0 && Rect(mDrawPoint, VIEW_SIZE).mouseOver()))
		&& mBeginId > 0 && selectedButton.getName() == mButtonName + ToString(0))
	{
		--mBeginId;
	}

	// 表示するカセットを一つ後に
	if ((KeyS.down() || (Mouse::Wheel() < 0 && Rect(mDrawPoint, VIEW_SIZE).mouseOver()))
		&& mBeginId + BUTTON_NUM < cassetteSet.size() && selectedButton.getName() == mButtonName + ToString(BUTTON_NUM - 1))
	{
		++mBeginId;
	}

	// カセットを全て枠内に収める
	mBeginId = Max(0, Min(mBeginId, (int32)cassetteSet.size() - BUTTON_NUM));

	// 選択時の処理
	for (size_t i = 0; i < BUTTON_NUM; ++i)
	{
		if (mBeginId + i < 0 || mBeginId + i >= cassetteSet.size()) { continue; }

		if (mButtonName + ToString(i) == selectedButton.getName() && (KeyEnter.up() || selectedButton.getRegion().leftClicked()))
		{
			// 選択できている
		}
		else
		{
			continue; // できていない
		}

		auto itr = cassetteSet.begin();
		std::advance(itr, mBeginId + i);

		AdventureManager::instance().openWindow
		(
			std::make_unique<CassetteMoveWindow>(*itr, mDrawPoint + Point(0, i * BUTTON_SIZE.y), selectedEquipmentId)
		);
	}
}


void Kokoha::CassetteView::draw(const CassettePtrSet& cassetteSet) const
{
	if (cassetteSet.empty()) { return; }

	auto itr = cassetteSet.begin();

	std::advance(itr, mBeginId);

	// ボタンを描画する座標
	Point pos(mDrawPoint);

	for (int32 i = 0; i < BUTTON_NUM; ++i)
	{
		FontAsset(U"20")((*itr)->NAME).draw(pos);

		pos.y += BUTTON_SIZE.y;
		if (++itr == cassetteSet.end()) { break; }
	}
}

