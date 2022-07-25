#include "pch-il2cpp.h"
#include "FreezeEnemies.h"

#include <helpers.h>

#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/filters.h>

namespace cheat::feature 
{

    FreezeEnemies::FreezeEnemies() : Feature(),
        NF(f_Enabled, "Freeze Enemies", "FreezeEnemies", false)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(FreezeEnemies::OnGameUpdate);
    }

    const FeatureGUIInfo& FreezeEnemies::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", "World", false };
        return info;
    }

    void FreezeEnemies::DrawMain()
    {
        ConfigWidget(f_Enabled, "Freezes all enemies' animation speed.");
    }

    bool FreezeEnemies::NeedStatusDraw() const
{
        return f_Enabled;
    }

    void FreezeEnemies::DrawStatus() 
    { 
        ImGui::Text("Freeze Enemies");
    }

    FreezeEnemies& FreezeEnemies::GetInstance()
    {
        static FreezeEnemies instance;
        return instance;
    }

	void FreezeEnemies::OnGameUpdate()
	{
        auto& manager = game::EntityManager::instance();

        for (const auto& monster : manager.entities(game::filters::combined::Monsters))
        {
            auto animator = monster->animator();
            if (animator == nullptr)
                return;

            f_Enabled ? app::Animator_set_speed(animator, 0.f, nullptr) : app::Animator_set_speed(animator, 1.f, nullptr);
        }
	}
}

