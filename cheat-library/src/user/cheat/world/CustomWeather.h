#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature
{
	class CustomWeather : public Feature
	{
	public:

		enum class WeatherType
		{
			ClearSky,
			Cloudy,
			Foggy,
			Storm,
			RainHeavy,
			FountainRain,
			SnowLight,
			EastCoast,
		};

		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<Hotkey>> f_Lightning;
		config::Field<config::Enum<WeatherType>> f_WeatherType;

		static CustomWeather& GetInstance();
		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
		bool NeedStatusDraw() const override;
		void DrawStatus() override;

	private:
		void OnGameUpdate();
		CustomWeather();
	};
}