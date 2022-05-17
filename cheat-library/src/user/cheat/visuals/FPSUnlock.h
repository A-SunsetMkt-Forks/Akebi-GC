#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature
{

	class FPSUnlock : public Feature
	{
	public:
		config::Field<bool> f_Enabled;
		config::Field<int> f_Fps;

		static FPSUnlock& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
		void OnGameUpdate();

	private:
		FPSUnlock();
	};
}

