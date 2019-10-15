#pragma once


#include "../Event/Event.h"


namespace Kokoha
{
	/*
	ActEventクラス
	オブジェクトの演出の実行
	*/
	class ActEvent : public Event
	{
	private:

		// オブジェクト名
		String mObjName;

		// 演出名
		String mActName;

	private:

		bool load(const EventArg& eventArg) override;

		void perform() override;

		bool isCompleted() const override;

	};
}