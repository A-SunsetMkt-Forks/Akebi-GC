#include "pch-il2cpp.h"
#include "NoCD.h"

#include <helpers.h>
#include <fmt/chrono.h>

namespace cheat::feature 
{
	static bool HumanoidMoveFSM_CheckSprintCooldown_Hook(void* __this, MethodInfo* method);
	static bool LCAvatarCombat_IsEnergyMax_Hook(void* __this, MethodInfo* method);
	static bool LCAvatarCombat_OnSkillStart(app::LCAvatarCombat* __this, uint32_t skillID, float cdMultipler, MethodInfo* method);
	static void ActorAbilityPlugin_AddDynamicFloatWithRange_Hook(void* __this, app::String* key, float value, float minValue, float maxValue,
		bool forceDoAtRemote, MethodInfo* method);
	 
	static std::list<std::string> abilityLog;

    NoCD::NoCD() : Feature(),
        NF(f_AbilityReduce,      "Reduce Skill/Burst Cooldown",  "NoCD", false),
		NF(f_AbilityReduceValue, "Reduce skill CD value",        "NoCD", 0.1f),

		NF(f_UtimateMaxEnergy,   "Burst max energy",             "NoCD", false),
        NF(f_Sprint,             "No Sprint Cooldown",           "NoCD", false),
		NF(f_InstantBow,         "Instant bow",                  "NoCD", false)

    {
		HookManager::install(app::LCAvatarCombat_IsEnergyMax, LCAvatarCombat_IsEnergyMax_Hook);
		HookManager::install(app::LCAvatarCombat_OnSkillStart, LCAvatarCombat_OnSkillStart);

		HookManager::install(app::HumanoidMoveFSM_CheckSprintCooldown, HumanoidMoveFSM_CheckSprintCooldown_Hook);
		HookManager::install(app::ActorAbilityPlugin_AddDynamicFloatWithRange, ActorAbilityPlugin_AddDynamicFloatWithRange_Hook);
    }

    const FeatureGUIInfo& NoCD::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "Cooldown Effects", "Player", true };
        return info;
    }

    void NoCD::DrawMain()
    {

		ConfigWidget("Max Burst Energy", f_UtimateMaxEnergy,
			"Removes energy requirement for elemental bursts.\n" \
			"(Energy bubble may appear incomplete but still usable.)");

		ConfigWidget("## AbilityReduce", f_AbilityReduce); ImGui::SameLine();
		ConfigWidget("Reduce Skill/Burst Cooldown", f_AbilityReduceValue, 0.1f, 0.2f, 1.0f, 
			"Reduce cooldowns of elemental skills and bursts.\n"\
			"The greater the value, the greater the cooldown.");

    	ConfigWidget(f_Sprint, "Removes delay in-between sprints.");

    	ConfigWidget("Instant Bow Charge", f_InstantBow, "Disable cooldown of bow charge.\n" \
			"Known issues with Fischl.");

    	if (f_InstantBow) {
			ImGui::Text("If Instant Bow Charge doesn't work:");
			TextURL("Please contribute to issue on GitHub.", "https://github.com/CallowBlack/genshin-cheat/issues/47", false, false);
			if (ImGui::TreeNode("Ability Log [DEBUG]"))
			{
				if (ImGui::Button("Copy to Clipboard"))
				{
					ImGui::LogToClipboard();

					ImGui::LogText("Ability Log:\n");

					for (auto& logEntry : abilityLog)
						ImGui::LogText("%s\n", logEntry.c_str());

					ImGui::LogFinish();
				}

				for (std::string& logEntry : abilityLog)
					ImGui::Text(logEntry.c_str());

				ImGui::TreePop();
			}
		}
    }

    bool NoCD::NeedStatusDraw() const
{
        return f_InstantBow || f_AbilityReduce || f_Sprint ;
    }

    void NoCD::DrawStatus() 
    {
		  ImGui::Text("Cooldown\n[%s%s%s%s%s]",
			f_AbilityReduce ? fmt::format("Reduce {:.1f}", f_AbilityReduceValue.value()).c_str() : "",
			f_AbilityReduce && (f_InstantBow || f_Sprint) ? "|" : "",
			f_InstantBow ? "Bow" : "",
			f_InstantBow && f_Sprint ? "|" : "",
			f_Sprint ? "Sprint" : "");
    }

    NoCD& NoCD::GetInstance()
    {
        static NoCD instance;
        return instance;
    }

	static bool LCAvatarCombat_IsEnergyMax_Hook(void* __this, MethodInfo* method)
	{
		NoCD& noCD = NoCD::GetInstance();
		if (noCD.f_UtimateMaxEnergy)
			return true;

		return CALL_ORIGIN(LCAvatarCombat_IsEnergyMax_Hook, __this, method);
	}

	// Multipler CoolDown Timer | RyujinZX#6666
	static bool LCAvatarCombat_OnSkillStart(app::LCAvatarCombat* __this, uint32_t skillID, float cdMultipler, MethodInfo* method) {
		NoCD& noCD = NoCD::GetInstance();
		if (noCD.f_AbilityReduce)
		{
			if (__this->fields._targetFixTimer->fields._._timer_k__BackingField > 0) {
				cdMultipler = noCD.f_AbilityReduceValue / 3;
			}
			else {
				cdMultipler = noCD.f_AbilityReduceValue / 1;
			}
		}		
		return CALL_ORIGIN(LCAvatarCombat_OnSkillStart, __this, skillID, cdMultipler, method);
	}

	// Check sprint cooldown, we just return true if sprint no cooldown enabled.
	static bool HumanoidMoveFSM_CheckSprintCooldown_Hook(void* __this, MethodInfo* method)
	{
		NoCD& noCD = NoCD::GetInstance();
		if (noCD.f_Sprint)
			return true;

		return CALL_ORIGIN(HumanoidMoveFSM_CheckSprintCooldown_Hook, __this, method);
	}

	// This function raise when abilities, whose has charge, is charging, like a bow.
	// value - increase value
	// min and max - bounds of charge.
	// So, to charge make full charge m_Instantly, just replace value to maxValue.
	static void ActorAbilityPlugin_AddDynamicFloatWithRange_Hook(void* __this, app::String* key, float value, float minValue, float maxValue,
		bool forceDoAtRemote, MethodInfo* method)
	{
		std::time_t t = std::time(nullptr);
		auto logEntry = fmt::format("{:%H:%M:%S} | Key: {} value {}.", fmt::localtime(t), il2cppi_to_string(key), value);
		abilityLog.push_front(logEntry);
		if (abilityLog.size() > 50)
			abilityLog.pop_back();

		NoCD& noCD = NoCD::GetInstance();
		// This function is calling not only for bows, so if don't put key filter it cause various game mechanic bugs.
		// For now only "_Enchanted_Time" found for bow charging, maybe there are more. Need to continue research.
		if (noCD.f_InstantBow && il2cppi_to_string(key) == "_Enchanted_Time")
			value = maxValue;
		CALL_ORIGIN(ActorAbilityPlugin_AddDynamicFloatWithRange_Hook, __this, key, value, minValue, maxValue, forceDoAtRemote, method);
	}
}

