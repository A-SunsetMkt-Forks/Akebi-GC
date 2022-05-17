#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

	class GodMode : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;

		static GodMode& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
	
	private:
		GodMode();
	};
}

