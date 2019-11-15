#include "CassetteView.h"
#include "../CassetteMoveWindow.h"
#include "../../AdventureManager.h"
#include "../../../Input/ButtonManager.h"
#include "../../../Cassette/CassetteManager.h"


namespace
{
	// �{�^���̐�
	constexpr int32 BUTTON_NUM = 10;

	// �T�C�Y
	constexpr Size BUTTON_SIZE(150, 30);

	// �}�E�X���͂��󂯕t����͈�
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

	// �{�^���̐ݒ�
	for (int32 i = 0; i < BUTTON_NUM; ++i)
	{
		ButtonManager::instance().registerButton
		(
			mButtonName + ToString(i),
			region
		);

		region.y += BUTTON_SIZE.y;
	}

	// �{�^���̈ʒu�֌W�̐ݒ�
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

	// �\������J�Z�b�g����O��
	if ((KeyW.down() || (Mouse::Wheel() > 0 && Rect(mDrawPoint, VIEW_SIZE).mouseOver()))
		&& mBeginId > 0 && selectedButton.getName() == mButtonName + ToString(0))
	{
		--mBeginId;
	}

	// �\������J�Z�b�g������
	if ((KeyS.down() || (Mouse::Wheel() < 0 && Rect(mDrawPoint, VIEW_SIZE).mouseOver()))
		&& mBeginId + BUTTON_NUM < cassetteSet.size() && selectedButton.getName() == mButtonName + ToString(BUTTON_NUM - 1))
	{
		++mBeginId;
	}

	// �J�Z�b�g��S�Ęg���Ɏ��߂�
	mBeginId = Max(0, Min(mBeginId, (int32)cassetteSet.size() - BUTTON_NUM));

	// �I�����̏���
	for (size_t i = 0; i < BUTTON_NUM; ++i)
	{
		if (mBeginId + i < 0 || mBeginId + i >= cassetteSet.size()) { continue; }

		if (mButtonName + ToString(i) == selectedButton.getName() && (KeyEnter.up() || selectedButton.getRegion().leftClicked()))
		{
			// �I���ł��Ă���
		}
		else
		{
			continue; // �ł��Ă��Ȃ�
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

	// �{�^����`�悷����W
	Point pos(mDrawPoint);

	for (int32 i = 0; i < BUTTON_NUM; ++i)
	{
		FontAsset(U"20")((*itr)->NAME).draw(pos);

		pos.y += BUTTON_SIZE.y;
		if (++itr == cassetteSet.end()) { break; }
	}
}

