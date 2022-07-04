#include "pch-il2cpp.h"
#include "VacuumLoot.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/util.h>

namespace cheat::feature
{
	VacuumLoot::VacuumLoot() : Feature(),
		NF(f_Enabled, "Vacuum Loot", "VacuumLoot", false)
    {
		InstallFilters();
        events::GameUpdateEvent += MY_METHOD_HANDLER(VacuumLoot::OnGameUpdate);
    }

	const FeatureGUIInfo& VacuumLoot::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "World", true };
		return info;
	}

    void VacuumLoot::DrawMain()
    {
		if (ImGui::BeginGroupPanel("Vacuum Loot", false))
		{
			ConfigWidget("Enabled", f_Enabled, "Vacuum Loot drops");
			ImGui::TreeNode(this, "Loot Types");
			for (auto& [field, name] : m_Filters)
			{
				ImGui::PushID(name.c_str());
				ConfigWidget(field);
				ImGui::PopID();
			}
			ImGui::TreePop();
		}
		ImGui::EndGroupPanel();
    }

	bool VacuumLoot::NeedStatusDraw() const
	{
		return f_Enabled;
	}

	void VacuumLoot::DrawStatus()
	{
		ImGui::Text ("VacuumLoot");
	}

	VacuumLoot& VacuumLoot::GetInstance()
	{
		static VacuumLoot instance;
		return instance;
	}

	bool VacuumLoot::IsEntityForVac(game::Entity* entity)
	{
		auto& manager = game::EntityManager::instance();
		auto distance = manager.avatar()->distance(entity);
		float radius = 100.0f;

		for (const auto& lootItem : m_Filters)
			if (lootItem.first.value())
				if (entity->name().find(lootItem.second) != std::string::npos)
					return distance <= radius;
		
		return false;
	}

    void VacuumLoot::OnGameUpdate()
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
	
	void VacuumLoot::AddFilter(const std::string& friendName, const std::string& name)
	{
		m_Filters.push_back({
			config::CreateField<bool>(friendName, name,
                                      fmt::format("VacuumLoot::Filters::{}", name),
                                      false, true),
			name
			});
	}

	void VacuumLoot::InstallFilters()
	{
		AddFilter("General loot",               "SceneObj_DropItem"   );
		AddFilter("Ore Drops",                  "SceneObj_Ore_Drop"   );
		AddFilter("Magic Crystal",              "_DropMagicCrystal"   );
		AddFilter("???",                        "_Thundercrystaldrop" );
		AddFilter("Electro Crystal",            "_Ore_ElectricRock"   );
		AddFilter("Starsilver Ore",             "_DropMoonMeteor_"    );
		AddFilter("Potatoes",                   "_Potato"             );
		AddFilter("Radish",                     "_Radish02_Clear"     );
		AddFilter("Cabbage",                    "_Cabbage"            );
		AddFilter("Carrot",                     "_Carrot02_Clear"     );
		AddFilter("Wheat",                      "_Wheat"              );
		AddFilter("Butterflies & Crystalflies", "Wisp"                );
		AddFilter("Meat",                       "Meat"                );
		AddFilter("Fishmeat",                   "Fishmeat"            );
		AddFilter("Swords",                     "Equip_Sword"         );
		AddFilter("Poles",                      "Equip_Pole"          );
		AddFilter("Bows",                       "Equip_Bow"           );
		AddFilter("Catalysts",                  "Equip_Catalyst"      );
		AddFilter("Claymores",                  "Equip_Claymore"      );
		AddFilter("???",                        "Eff_Animal"          );
	}
}
