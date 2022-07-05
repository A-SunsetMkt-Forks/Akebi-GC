#include "pch-il2cpp.h"
#include "VacuumLoot.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/util.h>

// Returns the unique categories (i.e. the third element of every tuple) in a filter object.
static std::vector<std::string> uniqueCategories(const std::vector<std::tuple<config::Field<bool>, std::string, std::string>>& filter)
{
	std::vector<std::string> result;
	std::transform(filter.begin(), filter.end(), std::back_inserter(result),
		[](const auto& item) {return std::get<2>(item); });
	std::sort(result.begin(), result.end());
	auto it = std::unique(result.begin(), result.end());
	result.erase(it, result.end());
	return result;
}

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
            if (ImGui::TreeNode(this, "Loot Types"))
            {
                for (const auto& groupCategory : uniqueCategories(m_Filters))
                {
                    if (ImGui::BeginGroupPanel(groupCategory.c_str(), false))
                    {
                        for (auto& [field, name, category] : m_Filters)
                        {
                            if (category == groupCategory)
                            {
                                ImGui::PushID(name.c_str());
                                ConfigWidget(field);
                                ImGui::PopID();
                            }
                        }
                    }
                    ImGui::EndGroupPanel();
                }
                ImGui::TreePop();
            }
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

		for (const auto& [field, name, category] : m_Filters)
			if (field.value())
				if (entity->name().find(name) != std::string::npos)
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
	
    void VacuumLoot::AddFilter(const std::string& friendName,
                               const std::string& name,
                               const std::string& category)
	{
		m_Filters.push_back({
			config::CreateField<bool>(friendName, name,
                                      fmt::format("VacuumLoot::Filters::{}", name),
                                      false, true),
			name, category
			});
	}

	void VacuumLoot::InstallFilters()
	{
		AddFilter("General loot",               "SceneObj_DropItem"   ,"General");
		AddFilter("Ore Drops",                  "SceneObj_Ore_Drop"   ,"Ore");
		AddFilter("Magic Crystal",              "_DropMagicCrystal"   ,"Ore");
		AddFilter("Amethyst Lump",              "_Thundercrystaldrop" ,"Ore");
		AddFilter("Electro Crystal",            "_Ore_ElectricRock"   ,"Ore");
		AddFilter("Starsilver Ore",             "_DropMoonMeteor_"    ,"Ore");
		AddFilter("Noctilucous Jade",           "NightBerth"          ,"Ore");
		AddFilter("Potatoes",                   "_Potato"             ,"Food");
		AddFilter("Radish",                     "_Radish02_Clear"     ,"Food");
		AddFilter("Cabbage",                    "_Cabbage"            ,"Food");
		AddFilter("Carrot",                     "_Carrot02_Clear"     ,"Food");
		AddFilter("Wheat",                      "_Wheat"              ,"Food");
		AddFilter("Crystalflies",               "Wisp"                ,"General");
		AddFilter("Meat & Fowl",                "Meat"                ,"Food");
		AddFilter("Fishmeat",                   "Fishmeat"            ,"Food");
		AddFilter("Crab",                       "Crab"                ,"Food");
		AddFilter("Eel",                        "Eel_"                ,"Food");
		AddFilter("Lizard",                     "Lizard"              ,"General");
		AddFilter("Swords",                     "Equip_Sword"         ,"Equipment");
		AddFilter("Poles",                      "Equip_Pole"          ,"Equipment");
		AddFilter("Bows",                       "Equip_Bow"           ,"Equipment");
		AddFilter("Catalysts",                  "Equip_Catalyst"      ,"Equipment");
		AddFilter("Claymores",                  "Equip_Claymore"      ,"Equipment");
		AddFilter("Butterflies & Fireflies",    "Eff_Animal"          ,"General");
	}
}
