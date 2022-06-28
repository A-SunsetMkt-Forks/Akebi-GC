#include "pch-il2cpp.h"
#include "AutoSeelie.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/util.h>

namespace cheat::feature
{
	AutoSeelie::AutoSeelie() : Feature(),
		NF(f_Enabled, "Auto follow seelie", "AutoSeelie", false)

    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(AutoSeelie::OnGameUpdate);
    }
	const FeatureGUIInfo& AutoSeelie::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "World", true };
		return info;
	}

    void AutoSeelie::DrawMain()
    {
        ConfigWidget("Auto seelie", f_Enabled, "Auto follow seelie to it home");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), "Don't work with Electro Seelies");
    }

	bool AutoSeelie::NeedStatusDraw() const
	{
		return f_Enabled;
	}

	void AutoSeelie::DrawStatus()
	{
		ImGui::Text ("AutoSeelie");
	}

	AutoSeelie& AutoSeelie::GetInstance()
	{
		static AutoSeelie instance;
		return instance;
	}

	bool AutoSeelie::IsEntityForVac(game::Entity* entity)
	{
		auto& manager = game::EntityManager::instance();
		auto distance = manager.avatar()->distance(entity);
		float radius = 100.0f;
	
		if (entity->name().find("Gear_Seelie") != std::string::npos || entity->name().find("_FireSeelie") != std::string::npos ||
			entity->name().find("_LitSeelie") != std::string::npos)
		{
			return distance <= radius;
		}
		
		return false;
	}


    void AutoSeelie::OnGameUpdate()
    {
        if (!f_Enabled)
            return;

		auto currentTime = util::GetCurrentTimeMillisec();
		if (currentTime < nextTime)
			return;

        auto& manager = game::EntityManager::instance();
		auto avatarEntity = manager.avatar();
        for (const auto& entity : manager.entities())
        {
            if (!IsEntityForVac(entity))
                continue;

            entity->setRelativePosition(avatarEntity->relativePosition());
        }
		nextTime = currentTime + 1000;
    }
	
}