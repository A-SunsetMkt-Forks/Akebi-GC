#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>
#include <cheat-base/util.h>

namespace cheat::feature
{

	class Settings : public Feature
	{
	public:
		config::Field<Hotkey> f_MenuKey;
		config::Field<bool> f_HotkeysEnabled;

		config::Field<bool> f_StatusMove;
		config::Field<bool> f_StatusShow;

		config::Field<bool> f_InfoMove;
		config::Field<bool> f_InfoShow;

		config::Field<bool> f_FpsShow;
		config::Field<bool> f_FpsMove;

		config::Field<bool> f_NotificationsShow;
		config::Field<int> f_NotificationsDelay;

		config::Field<bool> f_ConsoleLogging;
		config::Field<bool> f_FileLogging;

		config::Field<bool> f_FastExitEnable;
		config::Field<Hotkey> f_HotkeyExit;

		config::Field<int> f_FontSize;
		config::Field<bool> f_ShowStyleEditor;
		std::filesystem::path themesDir;
		config::Field<std::string> f_DefaultTheme;


		static Settings& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
		void Init();

	private:
		struct Theme{
			std::map<std::string, ImVec4> colors;
			std::map<std::string, std::any> styles;
		};
		std::map<std::string, Theme> m_Themes;
		void ThemeImport(std::filesystem::directory_entry file);
		void ThemeExport(std::string name, bool replace = false);
		void ApplyTheme(std::string name);

		void OnExitKeyPressed();
		Settings();
	};
}

