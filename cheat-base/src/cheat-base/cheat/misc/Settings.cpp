#include <pch.h>
#include "Settings.h"

#include <cheat-base/cheat/CheatManagerBase.h>
#include <cheat-base/render/renderer.h>
#include <cheat-base/render/gui-util.h>
#include <misc/cpp/imgui_stdlib.h>
#include <cheat-base/util.h>

#include "shlwapi.h"
#pragma comment(lib, "shlwapi.lib")

namespace cheat::feature
{
	Settings::Settings() : Feature(),
		NF(f_MenuKey, "Show Cheat Menu Key", "General", Hotkey(VK_F1)),
		NF(f_HotkeysEnabled, "Hotkeys Enabled", "General", true),
		
		NF(f_StatusMove, "Move Status Window", "General::StatusWindow", true),
		NF(f_StatusShow, "Show Status Window", "General::StatusWindow", true),

		NF(f_InfoMove, "Move Info Window", "General::InfoWindow", true),
		NF(f_InfoShow, "Show Info Window", "General::InfoWindow", true),

		NF(f_FpsMove, "Move FPS Indicator", "General::FPS", false),
		NF(f_FpsShow, "Show FPS Indicator", "General::FPS", true),

		NF(f_NotificationsShow, "Show Notifications", "General::Notify", true),
		NF(f_NotificationsDelay, "Notifications Delay", "General::Notify", 500),

		NF(f_FileLogging, "File Logging", "General::Logging", false),
		NF(f_ConsoleLogging, "Console Logging", "General::Logging", true),

		NF(f_FastExitEnable, "Fast Exit", "General::FastExit", false),
		NF(f_HotkeyExit, "Hotkeys", "General::FastExit", Hotkey(VK_F12)),
		
		NF(f_FontSize, "Font Size", "General", 16.0f),
		NF(f_ShowStyleEditor, "Show Colors Customization", "General", false),
		NFS(f_DefaultTheme, "Theme", "General::Colors", "Default"),
		themesDir(util::GetCurrentPath() / "themes")

	{
		renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
		f_HotkeyExit.value().PressedEvent += MY_METHOD_HANDLER(Settings::OnExitKeyPressed);
		if (!std::filesystem::exists(themesDir))
			std::filesystem::create_directory(themesDir);

	}

	bool inited = false;
	void Settings::Init() {
		if (this->f_DefaultTheme.value() != "Default" && !inited)
		{
			LOG_INFO("Loading theme: %s", themesDir / (f_DefaultTheme.value() + ".json").c_str());
			if (!std::filesystem::exists(themesDir / (f_DefaultTheme.value() + ".json")))
				f_DefaultTheme = "Default";
			else Colors_Import(f_DefaultTheme.value());
			inited = true;
		}
	}

	const FeatureGUIInfo& Settings::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "Settings", false };
		return info;
	}

	void Settings::Colors_Export(std::string name)
	{
		ImGuiStyle& style = ImGui::GetStyle();
		auto colors = style.Colors;

		nlohmann::json json;
		for (int i = 0; i < ImGuiCol_COUNT; i++)
			json[ImGui::GetStyleColorName((ImGuiCol)i)] = { colors[i].x, colors[i].y, colors[i].z, colors[i].w };
		std::ofstream file(themesDir / (name + ".json"));
		file << std::setw(4) << json << std::endl;
	}

	void Settings::Colors_Import(std::string name)
	{
		ImGuiStyle& style = ImGui::GetStyle();
		auto colors = style.Colors;
		nlohmann::json json;
		std::ifstream file(themesDir / (name + ".json"));
		file >> json;
		for (int i = 0; i < ImGuiCol_COUNT; i++)
		{
			auto color = json[ImGui::GetStyleColorName((ImGuiCol)i)];
			colors[i].x = color[0];
			colors[i].y = color[1];
			colors[i].z = color[2];
			colors[i].w = color[3];
		}
	}

	void Settings::DrawMain()
	{

		ImGui::BeginGroupPanel("General");
		{
			ConfigWidget(f_MenuKey, false,
				"Key to toggle main menu visibility. Cannot be empty.\n"\
				"If you forget this key, you can see or set it in your config file.");
			ConfigWidget(f_HotkeysEnabled, "Enable hotkeys.");
					}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Logging");
		{
			bool consoleChanged = ConfigWidget(f_ConsoleLogging,
				"Enable console for logging information (changes will take effect after relaunch)");
			if (consoleChanged && !f_ConsoleLogging)
			{
				Logger::SetLevel(Logger::Level::None, Logger::LoggerType::ConsoleLogger);
			}

			bool fileLogging = ConfigWidget(f_FileLogging,
				"Enable file logging (changes will take effect after relaunch).\n" \
				"A folder in the app directory will be created for logs.");
			if (fileLogging && !f_FileLogging)
			{
				Logger::SetLevel(Logger::Level::None, Logger::LoggerType::FileLogger);
			}
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Status Window");
		{
			ConfigWidget(f_StatusShow);
			ConfigWidget(f_StatusMove, "Allow moving of 'Status' window.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Info Window");
		{
			ConfigWidget(f_InfoShow);
			ConfigWidget(f_InfoMove, "Allow moving of 'Info' window.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("FPS indicator");
		{
			ConfigWidget(f_FpsShow);
			ConfigWidget(f_FpsMove, "Allow moving of 'FPS Indicator' window.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Show Notifications");
		{
			ConfigWidget(f_NotificationsShow, "Notifications on the bottom-right corner of the window will be displayed.");
			ConfigWidget(f_NotificationsDelay, 1, 1, 10000, "Delay in milliseconds between notifications.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Fast Exit");
		{
			ConfigWidget("Enabled",
				f_FastExitEnable,
				"Enable Fast Exit.\n"
			);
			if (!f_FastExitEnable)
				ImGui::BeginDisabled();

			ConfigWidget("Key", f_HotkeyExit, true,
				"Key to exit the game.");

			if (!f_FastExitEnable)
				ImGui::EndDisabled();
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Interface Customization");
		{
			if (ConfigWidget(f_FontSize, 1, 8, 64, "Adjust interface font size."))
			{
				f_FontSize = std::clamp(f_FontSize.value(), 8, 64);
				renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
			}
			ImGui::Spacing();

			ConfigWidget(f_ShowStyleEditor, "Show colors customization window.");
			ImGui::Spacing();

			ImGui::Text("Save Customized Color");
			static std::string nameBuffer_;
			ImGui::InputText("Color Name", &nameBuffer_);
			if (ImGui::Button("Save"))
				Colors_Export(nameBuffer_);
				ImGui::SameLine();

			if (std::filesystem::exists(themesDir / (nameBuffer_ + ".json")))
			{
				if (this->f_DefaultTheme.value() != nameBuffer_)
				{
					if (ImGui::Button("Set as default"))
					{
						f_DefaultTheme = nameBuffer_;
					}
					ImGui::SameLine();
					if (ImGui::Button("Load"))
					{
						Colors_Import(nameBuffer_);
					}
				}
			}
			else
			{
				ImGui::Text("Color does not exist.");
			}
		}
		ImGui::EndGroupPanel();
	}

	Settings& Settings::GetInstance()
	{
		static Settings instance;
		return instance;
	}

	void Settings::OnExitKeyPressed()
	{
		if (!f_FastExitEnable || CheatManagerBase::IsMenuShowed())
			return;

		ExitProcess(0);
	}
}
