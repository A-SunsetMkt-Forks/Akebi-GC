#include "pch-il2cpp.h"
#include "AutoChallenge.h"

#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/filters.h>

namespace cheat::feature
{

	AutoChallenge::AutoChallenge() : Feature(),
		NF(f_Enabled, "Auto challenge", "AutoChallenge", false),
		NF(f_BombDestroy, "Bomb destroy", "AutoChallenge", false),
		NF(f_Delay, "Collect delay", "AutoChallenge", 1000),
		NF(f_Range, "Collect range", "AutoChallenge", 20.f)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(AutoChallenge::OnGameUpdate);
	}

	const FeatureGUIInfo& AutoChallenge::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Auto Challenge", "World", true };
		return info;
	}

	void AutoChallenge::DrawMain()
	{
		ConfigWidget("Enabled", f_Enabled, "Auto collect time challenge item");
		ImGui::SameLine();
		ConfigWidget("Destroy Bomb", f_BombDestroy, "Auto destroy bombbarrel");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), "I haven't tested how high the risk is");
		ImGui::SetNextItemWidth(200.f);
		ConfigWidget("Range", f_Range, 0.1f, 0.f, 300.f, "Collect range.");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(200.f);
		ConfigWidget("Delay", f_Delay, 1, 0, 2000, "Collect delay.");
	}

	bool AutoChallenge::NeedStatusDraw() const
	{
		return f_Enabled;
	}

	void AutoChallenge::DrawStatus()
	{
		ImGui::Text("Challenge [%.01fm]", f_Range.value());
	}

	AutoChallenge& AutoChallenge::GetInstance()
	{
		static AutoChallenge instance;
		return instance;
	}

	void AutoChallenge::OnGameUpdate()
	{
		static uint64_t lastTime = 0;
		auto timestamp = app::MoleMole_TimeUtil_get_LocalNowMsTimeStamp(nullptr);

		if (!f_Enabled || lastTime + f_Delay > timestamp)
			return;

		auto& entityManager = game::EntityManager::instance();
		auto avatarEntity = entityManager.avatar();

		for (auto& entity : entityManager.entities(game::filters::puzzle::TimeTrialChallengeCollection))
		{
			if (avatarEntity->distance(entity) > f_Range)
				continue;

			auto combat = entity->combat();
			if (combat != nullptr)
			{
				if (entity->name().find("SkillObj_EmptyGadget") != std::string::npos)
				{
					auto combatProp = combat->fields._combatProperty_k__BackingField;
					auto maxHP = app::MoleMole_SafeFloat_get_Value(combatProp->fields.maxHP, nullptr);
					// so many entities named "SkillObj_EmptyGadget", but the collection's hp is 99999.f
					if (maxHP > 99998 && maxHP < 99999.9)
					{
						entity->setRelativePosition(avatarEntity->relativePosition());
					}
				}
				else
				{
					entity->setRelativePosition(avatarEntity->relativePosition());
				}
			}
		}
	}
}