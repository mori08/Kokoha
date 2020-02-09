#include "AdventureObject.h"
#include "AdventureManager.h"
#include "../MyLibrary.h"
#include "../Input/InputManager.h"
#include "../Record/RecordManager.h"

// �E�B���h�E
#include "Window/InfoWindow.h"
#include "Window/ChallengeStageWindow.h"
#include "Window/AreaWindow.h"


namespace 
{
	// �v���C���[�ƌ������� "����" �Ƃ��̕s�����x
	constexpr double INTERSECTS_ALPHA = 0.5;
	// �v���C���[�ƌ������� "���Ȃ�" �Ƃ��̕s�����x
	constexpr double NON_INTERSECTS_ALPHA = 1.0;
	// �s�����x�̕ω��ʂ�����������
	constexpr double ALPHA_RATE = 0.4;
}


std::unordered_map<String, std::function<void()>> Kokoha::AdventureObject::sMakeWindowFuncMap;


Kokoha::AdventureObject::AdventureObject(const Point& pos, const String& textureName, bool pass)
	: mRegion(pos,TextureAsset(textureName).size())
	, mTextureName(textureName)
	, mAlpha(NON_INTERSECTS_ALPHA)
	, mIsPassing(pass)
	, mOnClick([](){})
{
	if (sMakeWindowFuncMap.count(mTextureName))
	{
		mOnClick = sMakeWindowFuncMap[mTextureName];
	}
}


void Kokoha::AdventureObject::registerWindow()
{
	// �e�L�X�g�̕\��
	sMakeWindowFuncMap[U"DoctorWorkbench"] = []() { openWindow(std::make_unique<InfoWindow>(U"��Ƒ�,\n�U�炩���Ă�.")); };
	sMakeWindowFuncMap[U"TrashBox0"]       = []() { openWindow(std::make_unique<InfoWindow>(U"�������̂ĂĂ���.")); };
	sMakeWindowFuncMap[U"Cardboard"]       = []() { openWindow(std::make_unique<InfoWindow>(U"�i�{�[��,\n���g�͕�����Ȃ�.")); };
	sMakeWindowFuncMap[U"OpenedCardboard"] = []() { openWindow(std::make_unique<InfoWindow>(U"�i�{�[��,\n���g�͋�.")); };
	sMakeWindowFuncMap[U"Shelf"]           = []() { openWindow(std::make_unique<InfoWindow>(U"�傫�ȒI��.\n�������͓͂��Ȃ�.")); };
	sMakeWindowFuncMap[U"LaboWorkbench"]   = []() { openWindow(std::make_unique<InfoWindow>(U"��Ƒ�,\n������������Ղ�����.")); };

	// �X�e�[�W�ɒ���
	sMakeWindowFuncMap[U"BrokenSearcher1"] = []() { openStageWindow(U"1-1"); };
	sMakeWindowFuncMap[U"BrokenDeveloper"] = []() { openStageWindow(Array<String>{U"2-1", U"2-2", U"2-3"}); };
	sMakeWindowFuncMap[U"BrokenRepair0"]   = []() { openStageWindow(U"3-1"); };

	// �ʃG���A�Ɉړ�
	sMakeWindowFuncMap[U"Door[StoreRoom]"]  = []() { openWindow(std::make_unique<AreaWindow>()); };
	sMakeWindowFuncMap[U"Door[Labolatory]"] = []() { openWindow(std::make_unique<AreaWindow>()); };
	sMakeWindowFuncMap[U"Door[Entrance]"]   = []() { openWindow(std::make_unique<AreaWindow>()); };
}


void Kokoha::AdventureObject::update(const Rect& playerRegion)
{
	if (!mIsPassing) { return; }

	double goalAlpha = NON_INTERSECTS_ALPHA;

	if (mRegion.intersects(playerRegion))
	{
		goalAlpha = INTERSECTS_ALPHA;
	}

	internalDividingPoint(mAlpha, goalAlpha, ALPHA_RATE);
}


void Kokoha::AdventureObject::draw(const Point& cameraPoint) const
{
	TextureAsset(mTextureName).draw(mRegion.pos - cameraPoint, AlphaF(mAlpha));
}


void Kokoha::AdventureObject::openWindow(WindowPtr&& windowPtr)
{
	AdventureManager::instance().openWindow(std::move(windowPtr));
}


void Kokoha::AdventureObject::openStageWindow(const String& stageName)
{
	if (RecordManager::instance().getRecord(stageName))
	{
		openWindow(std::make_unique<InfoWindow>(U"���̃��{�b�g�ɂ�\n�����p�͂Ȃ�"));
		return;
	}

	openWindow(std::make_unique<ChallengeStageWindow>(stageName));
}


void Kokoha::AdventureObject::openStageWindow(const Array<String>& stageNameList)
{
	for (const auto& stageName : stageNameList)
	{
		if (RecordManager::instance().getRecord(stageName)) { continue; }
		
		// �N���A���Ă��Ȃ��X�e�[�W������Ƃ�
		openWindow(std::make_unique<ChallengeStageWindow>(stageName));

		return;
	}

	// �S�ăN���A���Ă���Ƃ�
	openWindow(std::make_unique<InfoWindow>(U"���̃��{�b�g�ɂ�\n�����p�͂Ȃ�"));
}
