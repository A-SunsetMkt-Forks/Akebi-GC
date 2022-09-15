#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature
{

	class HideUI : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<bool> f_DamageOverlayHide;
		config::Field<bool> f_RadarOverlayHide;
		config::Field<bool> f_TopRightOverlayHide;
		config::Field<bool> f_PingOverlayHide;
		config::Field<bool> f_TeamOverlayHide;
		config::Field<bool> f_SkillOverlayHide;
		config::Field<bool> f_HpOverlayHide;
		config::Field<bool> f_ChatOverlayHide;
		config::Field<bool> f_RewardOverlayHide;
		config::Field<bool> f_InteractOverlayHide;
		config::Field<bool> f_ArLevelOverlayHide;

		static HideUI& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
		void OnGameUpdate();

	private:
		HideUI();
	};
}

