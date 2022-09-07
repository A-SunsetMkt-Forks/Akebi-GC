#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature
{

	class AutoCook : public Feature
	{
	public:
		enum class CookQuality 
		{
			Delicious,
			Normal,
			Suspicious,
		};

		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<Hotkey>> f_FastProficiency;

		config::Field<int> f_CountField;
		config::Field<config::Enum<CookQuality>> f_QualityField;

		int CookFoodMaxNum; // Maximum quantity at a time
		int CookCount;

		static AutoCook& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

	private:

		AutoCook();
	};
}

