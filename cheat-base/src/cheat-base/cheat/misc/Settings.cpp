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
		
		NF(f_FontSize, "Font Size", "General::Theme", 16.0f),
		NF(f_ShowStyleEditor, "Show Theme Customization", "General::Theme", false),
		NFS(f_DefaultTheme, "Theme", "General::Theme", ""),
		themesDir(util::GetCurrentPath() / "themes")

	{
		renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
		f_HotkeyExit.value().PressedEvent += MY_METHOD_HANDLER(Settings::OnExitKeyPressed);
	}

	const FeatureGUIInfo& Settings::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "Settings", false };
		return info;
	}

	ImVec4 HexToColor(std::string hexString)
	{
		int r, g, b, a;
		sscanf_s(hexString.c_str(), "%02x%02x%02x%02x", &r, &g, &b, &a);
		ImVec4 color{ (float(r) / 255), (float(g) / 255), (float(b) / 255), (float(a) / 255) };
		return color;
	}

	std::string ColorToHex(ImVec4& color)
	{
		char hex[16];
		snprintf(hex, sizeof(hex), "%02x%02x%02x%02x",
			static_cast<int>(ceil(color.x * 255)),
			static_cast<int>(ceil(color.y * 255)),
			static_cast<int>(ceil(color.z * 255)),
			static_cast<int>(ceil(color.w * 255))
		);
		for (int i = 0; i < 16; i++)
			hex[i] = toupper(hex[i]);
		return hex;
	}

	static void DefaultTheme()
	{
		auto& styles = ImGui::GetStyle();

		// Colors
		auto colors = styles.Colors;
		colors[ImGuiCol_Border] = HexToColor("26383FFF");
		colors[ImGuiCol_BorderShadow] = HexToColor("33333300");
		colors[ImGuiCol_Button] = HexToColor("23303DFF");
		colors[ImGuiCol_ButtonActive] = HexToColor("474968FF");
		colors[ImGuiCol_ButtonHovered] = HexToColor("444C70FF");
		colors[ImGuiCol_CheckMark] = HexToColor("A5BCDBFF");
		colors[ImGuiCol_ChildBg] = HexToColor("1E262BFF");
		colors[ImGuiCol_DockingEmptyBg] = HexToColor("333333FF");
		colors[ImGuiCol_DockingPreview] = HexToColor("4296F9B2");
		colors[ImGuiCol_DragDropTarget] = HexToColor("FFFF00E5");
		colors[ImGuiCol_FrameBg] = HexToColor("2D3F44FF");
		colors[ImGuiCol_FrameBgActive] = HexToColor("30383DFF");
		colors[ImGuiCol_FrameBgHovered] = HexToColor("26303DFF");
		colors[ImGuiCol_Header] = HexToColor("0000003D");
		colors[ImGuiCol_HeaderActive] = HexToColor("0070EAFF");
		colors[ImGuiCol_HeaderHovered] = HexToColor("1E2833CC");
		colors[ImGuiCol_MenuBarBg] = HexToColor("1E232DFF");
		colors[ImGuiCol_ModalWindowDimBg] = HexToColor("CCCCCC59");
		colors[ImGuiCol_NavHighlight] = HexToColor("4296F9FF");
		colors[ImGuiCol_NavWindowingDimBg] = HexToColor("CCCCCC33");
		colors[ImGuiCol_NavWindowingHighlight] = HexToColor("FFFFFFB2");
		colors[ImGuiCol_PlotHistogram] = HexToColor("E5B200FF");
		colors[ImGuiCol_PlotHistogramHovered] = HexToColor("FF9900FF");
		colors[ImGuiCol_PlotLines] = HexToColor("9B9B9BFF");
		colors[ImGuiCol_PlotLinesHovered] = HexToColor("FF6D59FF");
		colors[ImGuiCol_PopupBg] = HexToColor("14161CEF");
		colors[ImGuiCol_ResizeGrip] = HexToColor("A3C9F93F");
		colors[ImGuiCol_ResizeGripActive] = HexToColor("6D8CB2F2");
		colors[ImGuiCol_ResizeGripHovered] = HexToColor("A5BFDDAA");
		colors[ImGuiCol_ScrollbarBg] = HexToColor("1C1C1C63");
		colors[ImGuiCol_ScrollbarGrab] = HexToColor("875E5EFF");
		colors[ImGuiCol_ScrollbarGrabActive] = HexToColor("8E1919FF");
		colors[ImGuiCol_ScrollbarGrabHovered] = HexToColor("7C3A3AFF");
		colors[ImGuiCol_Separator] = HexToColor("333F49FF");
		colors[ImGuiCol_SeparatorActive] = HexToColor("6B91BFFF");
		colors[ImGuiCol_SeparatorHovered] = HexToColor("4F7299C6");
		colors[ImGuiCol_SliderGrab] = HexToColor("5977ADFF");
		colors[ImGuiCol_SliderGrabActive] = HexToColor("ADCCFFFF");
		colors[ImGuiCol_Tab] = HexToColor("1C262BFF");
		colors[ImGuiCol_TabActive] = HexToColor("333F49FF");
		colors[ImGuiCol_TabHovered] = HexToColor("969696CC");
		colors[ImGuiCol_TabUnfocused] = HexToColor("1C262BFF");
		colors[ImGuiCol_TabUnfocusedActive] = HexToColor("1C262BFF");
		colors[ImGuiCol_TableBorderLight] = HexToColor("3A3A3FFF");
		colors[ImGuiCol_TableBorderStrong] = HexToColor("4F4F59FF");
		colors[ImGuiCol_TableHeaderBg] = HexToColor("303033FF");
		colors[ImGuiCol_TableRowBg] = HexToColor("333F49FF");
		colors[ImGuiCol_TableRowBgAlt] = HexToColor("1C262BFF");
		colors[ImGuiCol_Text] = HexToColor("F2F4F9FF");
		colors[ImGuiCol_TextDisabled] = HexToColor("2B353DFF");
		colors[ImGuiCol_TextSelectedBg] = HexToColor("4296F959");
		colors[ImGuiCol_TitleBg] = HexToColor("232D38A5");
		colors[ImGuiCol_TitleBgActive] = HexToColor("212830FF");
		colors[ImGuiCol_TitleBgCollapsed] = HexToColor("26262682");
		colors[ImGuiCol_WindowBg] = HexToColor("1E2623FF");

		//Styles
		styles.Alpha = 1.0;
		styles.AntiAliasedFill = true;
		styles.AntiAliasedLines = true;
		styles.AntiAliasedLinesUseTex = true;
		styles.ButtonTextAlign = ImVec2(0.5, 0.5);
		styles.CellPadding = ImVec2(4.0, 2.0);
		styles.ChildBorderSize = 1.0;
		styles.ChildRounding = 5.0;
		styles.CircleTessellationMaxError = 0.30000001192092896;
		styles.ColorButtonPosition = 1;
		styles.ColumnsMinSpacing = 6.0;
		styles.CurveTessellationTol = 1.25;
		styles.DisabledAlpha = 0.6000000238418579;
		styles.DisplaySafeAreaPadding = ImVec2(3.0, 3.0);
		styles.DisplayWindowPadding = ImVec2(19.0, 19.0);
		styles.FrameBorderSize = 0.0;
		styles.FramePadding = ImVec2(4.0, 3.0);
		styles.FrameRounding = 4.0;
		styles.GrabMinSize = 10.0;
		styles.GrabRounding = 4.0;
		styles.IndentSpacing = 21.0;
		styles.ItemInnerSpacing = ImVec2(4.0, 4.0);
		styles.ItemSpacing = ImVec2(8.0, 4.0);
		styles.LogSliderDeadzone = 4.0;
		styles.MouseCursorScale = 1.0;
		styles.PopupBorderSize = 1.0;
		styles.PopupRounding = 0.0;
		styles.ScrollbarRounding = 9.0;
		styles.ScrollbarSize = 14.0;
		styles.SelectableTextAlign = ImVec2(0.0, 0.0);
		styles.TabBorderSize = 0.0;
		styles.TabMinWidthForCloseButton = 0.0;
		styles.TabRounding = 4.0;
		styles.TouchExtraPadding = ImVec2(0.0, 0.0);
		styles.WindowBorderSize = 1.0;
		styles.WindowMenuButtonPosition = 0;
		styles.WindowMinSize = ImVec2(32.0, 32.0);
		styles.WindowPadding = ImVec2(8.0, 8.0);
		styles.WindowRounding = 0.0;
		styles.WindowTitleAlign = ImVec2(0.0, 0.5);
	}

	bool hasLoaded = false;
	void Settings::Init() {
		if (hasLoaded)
			return;
		
		if (!std::filesystem::exists(themesDir))
			std::filesystem::create_directory(themesDir);
		else
		{
			m_Themes.clear();
			for (const auto& file : std::filesystem::directory_iterator(themesDir))
				if (std::filesystem::path(file).extension() == ".json")
					ThemeImport(file);
		}

		if (m_Themes.count(f_DefaultTheme.value()) > 0)
			ApplyTheme(f_DefaultTheme.value());
		else
			DefaultTheme();

		hasLoaded = true;
	}

	bool IsThemeOldFormat(nlohmann::json data)
	{
		if (data.count("Colors") > 0 && data.count("Styles") > 0)
			return false;
		
		return true;
	}

	void Settings::ThemeImport(std::filesystem::directory_entry file)
	{
		nlohmann::json data;
		std::ifstream fs(file.path());
		fs >> data;

		Theme theme;
		auto themeName = std::filesystem::path(file).stem().string();
		bool isOldFormat = IsThemeOldFormat(data);

		if (isOldFormat)
		{
			for (auto& [colorName, colorValue] : data.items())
			{
				ImVec4 color{};
				color.x = colorValue[0].get<float>();
				color.y = colorValue[1].get<float>();
				color.z = colorValue[2].get<float>();
				color.w = colorValue[3].get<float>();

				theme.colors.insert({ colorName, color });
			}
		}
		else
		{
			for (auto& [colorName, colorValue] : data["Colors"].items())
				theme.colors.insert({ colorName, HexToColor(colorValue) });

			for (auto& [styleName, styleValue] : data["Styles"].items())
			{
				if(styleValue.is_array())
					theme.styles.insert({ styleName, ImVec2(styleValue.at(0), styleValue.at(1)) });
				else if (styleValue.is_number_integer())
					theme.styles.insert({ styleName, styleValue.get<int>() });
				else if(styleValue.is_boolean())
					theme.styles.insert({ styleName, styleValue.get<bool>() });
				else 
					theme.styles.insert({ styleName, styleValue.get<float>() });
			}
		}

		m_Themes.insert({ themeName,  theme });

		// Convert old format to new format
		if(isOldFormat)
			ThemeExport(themeName, true);
	}

	nlohmann::json GetCurrentStyles(ImGuiStyle& style)
	{
		nlohmann::json stylesData;
		stylesData["Alpha"] = style.Alpha;
		stylesData["DisabledAlpha"] = style.DisabledAlpha;
		stylesData["WindowPadding"] = { style.WindowPadding.x, style.WindowPadding.y };
		stylesData["WindowRounding"] = style.WindowRounding;
		stylesData["WindowBorderSize"] = style.WindowBorderSize;
		stylesData["WindowMinSize"] = { style.WindowMinSize.x, style.WindowMinSize.y };
		stylesData["WindowTitleAlign"] = { style.WindowTitleAlign.x, style.WindowTitleAlign.y };
		stylesData["WindowMenuButtonPosition"] = style.WindowMenuButtonPosition;
		stylesData["ChildRounding"] = style.ChildRounding;
		stylesData["ChildBorderSize"] = style.ChildBorderSize;
		stylesData["PopupRounding"] = style.PopupRounding;
		stylesData["PopupBorderSize"] = style.PopupBorderSize;
		stylesData["FramePadding"] = { style.FramePadding.x, style.FramePadding.y };
		stylesData["FrameRounding"] = style.FrameRounding;
		stylesData["FrameBorderSize"] = style.FrameBorderSize;
		stylesData["ItemSpacing"] = { style.ItemSpacing.x, style.ItemSpacing.y };
		stylesData["ItemInnerSpacing"] = { style.ItemInnerSpacing.x,style.ItemInnerSpacing.y };
		stylesData["CellPadding"] = { style.CellPadding.x, style.CellPadding.y };
		stylesData["TouchExtraPadding"] = { style.TouchExtraPadding.x, style.TouchExtraPadding.y };
		stylesData["IndentSpacing"] = style.IndentSpacing;
		stylesData["ColumnsMinSpacing"] = style.ColumnsMinSpacing;
		stylesData["ScrollbarSize"] = style.ScrollbarSize;
		stylesData["ScrollbarRounding"] = style.ScrollbarRounding;
		stylesData["GrabMinSize"] = style.GrabMinSize;
		stylesData["GrabRounding"] = style.GrabRounding;
		stylesData["LogSliderDeadzone"] = style.LogSliderDeadzone;
		stylesData["TabRounding"] = style.TabRounding;
		stylesData["TabBorderSize"] = style.TabBorderSize;
		stylesData["TabMinWidthForCloseButton"] = style.TabMinWidthForCloseButton;
		stylesData["ColorButtonPosition"] = style.ColorButtonPosition;
		stylesData["ButtonTextAlign"] = { style.ButtonTextAlign.x, style.ButtonTextAlign.y };
		stylesData["SelectableTextAlign"] = { style.SelectableTextAlign.x, style.SelectableTextAlign.y };
		stylesData["DisplayWindowPadding"] = { style.DisplayWindowPadding.x, style.DisplayWindowPadding.y };
		stylesData["DisplaySafeAreaPadding"] = { style.DisplaySafeAreaPadding.x, style.DisplaySafeAreaPadding.y };
		stylesData["MouseCursorScale"] = style.MouseCursorScale;
		stylesData["AntiAliasedLines"] = style.AntiAliasedLines;
		stylesData["AntiAliasedLinesUseTex"] = style.AntiAliasedLinesUseTex;
		stylesData["AntiAliasedFill"] = style.AntiAliasedFill;
		stylesData["CurveTessellationTol"] = style.CurveTessellationTol;
		stylesData["CircleTessellationMaxError"] = style.CircleTessellationMaxError;
		return stylesData;
	}

	void Settings::ThemeExport(std::string name, bool replace)
	{
		ImGuiStyle& style = ImGui::GetStyle();
		nlohmann::json data;
		if (replace)
			for (auto& [colorName, colorValue] : m_Themes[name].colors)
				data["Colors"][colorName] = ColorToHex(colorValue);

		else {
			auto colors = style.Colors;
			for (int i = 0; i < ImGuiCol_COUNT; i++)
			{
				auto colorName = ImGui::GetStyleColorName((ImGuiCol)i);
				data["Colors"][colorName] = ColorToHex(colors[i]);
			}
		}

		data["Styles"] = GetCurrentStyles(style);

		std::ofstream file(themesDir / (name + ".json"));
		file << std::setw(4) << data << std::endl;
	}

	void Settings::ApplyTheme(std::string name)
	{
		ImGuiStyle& style = ImGui::GetStyle();
		auto colors = style.Colors;
		auto& theme = m_Themes[name];

		// Applying Colors
		if (!theme.colors.empty()) {
			for (int i = 0; i < ImGuiCol_COUNT; i++)
			{
				auto& themeColor = theme.colors[ImGui::GetStyleColorName((ImGuiCol)i)];
				colors[i].x = themeColor.x;
				colors[i].y = themeColor.y;
				colors[i].z = themeColor.z;
				colors[i].w = themeColor.w;
			}
		}

		if (!theme.styles.empty())
		{
			// Applying Styles
			style.Alpha = std::any_cast<float>(theme.styles["Alpha"]);
			style.DisabledAlpha = std::any_cast<float>(theme.styles["DisabledAlpha"]);
			style.WindowPadding = std::any_cast<ImVec2>(theme.styles["WindowPadding"]);
			style.WindowRounding = std::any_cast<float>(theme.styles["WindowRounding"]);
			style.WindowBorderSize = std::any_cast<float>(theme.styles["WindowBorderSize"]);
			style.WindowMinSize = std::any_cast<ImVec2>(theme.styles["WindowMinSize"]);
			style.WindowTitleAlign = std::any_cast<ImVec2>(theme.styles["WindowTitleAlign"]);
			style.WindowMenuButtonPosition = ImGuiDir(std::any_cast<int>(theme.styles["WindowMenuButtonPosition"]));
			style.ChildRounding = std::any_cast<float>(theme.styles["ChildRounding"]);
			style.ChildBorderSize = std::any_cast<float>(theme.styles["ChildBorderSize"]);
			style.PopupRounding = std::any_cast<float>(theme.styles["PopupRounding"]);
			style.PopupBorderSize = std::any_cast<float>(theme.styles["PopupBorderSize"]);
			style.FramePadding = std::any_cast<ImVec2>(theme.styles["FramePadding"]);
			style.FrameRounding = std::any_cast<float>(theme.styles["FrameRounding"]);
			style.FrameBorderSize = std::any_cast<float>(theme.styles["FrameBorderSize"]);
			style.ItemSpacing = std::any_cast<ImVec2>(theme.styles["ItemSpacing"]);
			style.ItemInnerSpacing = std::any_cast<ImVec2>(theme.styles["ItemInnerSpacing"]);
			style.CellPadding = std::any_cast<ImVec2>(theme.styles["CellPadding"]);
			style.TouchExtraPadding = std::any_cast<ImVec2>(theme.styles["TouchExtraPadding"]);
			style.IndentSpacing = std::any_cast<float>(theme.styles["IndentSpacing"]);
			style.ColumnsMinSpacing = std::any_cast<float>(theme.styles["ColumnsMinSpacing"]);
			style.ScrollbarSize = std::any_cast<float>(theme.styles["ScrollbarSize"]);
			style.ScrollbarRounding = std::any_cast<float>(theme.styles["ScrollbarRounding"]);
			style.GrabMinSize = std::any_cast<float>(theme.styles["GrabMinSize"]);
			style.GrabRounding = std::any_cast<float>(theme.styles["GrabRounding"]);
			style.LogSliderDeadzone = std::any_cast<float>(theme.styles["LogSliderDeadzone"]);
			style.TabRounding = std::any_cast<float>(theme.styles["TabRounding"]);
			style.TabBorderSize = std::any_cast<float>(theme.styles["TabBorderSize"]);
			style.TabMinWidthForCloseButton = std::any_cast<float>(theme.styles["TabMinWidthForCloseButton"]);
			style.ColorButtonPosition = ImGuiDir(std::any_cast<int>(theme.styles["ColorButtonPosition"]));
			style.ButtonTextAlign = std::any_cast<ImVec2>(theme.styles["ButtonTextAlign"]);
			style.SelectableTextAlign = std::any_cast<ImVec2>(theme.styles["SelectableTextAlign"]);
			style.DisplayWindowPadding = std::any_cast<ImVec2>(theme.styles["DisplayWindowPadding"]);
			style.DisplaySafeAreaPadding = std::any_cast<ImVec2>(theme.styles["DisplaySafeAreaPadding"]);
			style.MouseCursorScale = std::any_cast<float>(theme.styles["MouseCursorScale"]);
			style.AntiAliasedLines = std::any_cast<bool>(theme.styles["AntiAliasedLines"]);
			style.AntiAliasedLinesUseTex = std::any_cast<bool>(theme.styles["AntiAliasedLinesUseTex"]);
			style.AntiAliasedFill = std::any_cast<bool>(theme.styles["AntiAliasedFill"]);
			style.CurveTessellationTol = std::any_cast<float>(theme.styles["CurveTessellationTol"]);
			style.CircleTessellationMaxError = std::any_cast<float>(theme.styles["CircleTessellationMaxError"]);
		}

		LOG_INFO("Theme applied: %s", name.c_str());
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
			ImGui::SetNextItemWidth(200);
			if (ConfigWidget(f_FontSize, 1, 8, 64, "Adjust interface font size."))
				renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));

			static std::string themeNameBuffer_;
			
			ImGui::SetNextItemWidth(200);
		    ImGui::InputText("Theme Name", &themeNameBuffer_);

			bool alreadyExist = m_Themes.count(themeNameBuffer_) > 0;

			ImGui::SameLine();
			if (ImGui::Button(alreadyExist ? "Replace Theme" : "Save Theme"))
			{
				ImGui::SameLine();
				if (themeNameBuffer_.empty())
					ImGui::Text("Theme name is not valid. Falling back into default theme");
				ThemeExport(themeNameBuffer_);
				hasLoaded = false;
				f_DefaultTheme = themeNameBuffer_;
				Init();
				themeNameBuffer_.clear();
			}

			ImGui::SetNextItemWidth(200);
			if (ImGui::BeginCombo("Theme Select", f_DefaultTheme.value().c_str()))
			{
				for (auto& [themeName, themeData] : m_Themes)
				{
					bool isSelected = f_DefaultTheme.value() == themeName;
					if (ImGui::Selectable(themeName.c_str(), isSelected))
					{
						ApplyTheme(themeName);
						f_DefaultTheme = themeName;
					}

					if (isSelected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
			
			ImGui::SameLine();
			if (ImGui::Button("Delete Theme"))
			{
				std::filesystem::remove(themesDir / (f_DefaultTheme.value() + ".json"));
				LOG_INFO("Deleted theme %s", f_DefaultTheme.value().c_str());
				f_DefaultTheme = "";
				hasLoaded = false;
				Init();
			}

			ConfigWidget(f_ShowStyleEditor, "Show ImGui theme customization window.");
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
