#include "pch-il2cpp.h"
#include "GameSpeed.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature
{
    GameSpeed::GameSpeed() : Feature(),
        NF(f_Enabled, "GameSpeed Enabled", "GameSpeed", false),
        NF(f_Hotkey, "GameSpeed HotKey", "GameSpeed", Hotkey(VK_CAPITAL)),
        NF(f_Speed, "GameSpeed Multiplier", "GameSpeed", 5.0f)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(GameSpeed::OnGameUpdate);
    }

    const FeatureGUIInfo& GameSpeed::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "GameSpeed", "World", true };
        return info;
    }

    void GameSpeed::DrawMain()
    {
        ConfigWidget("GameSpeed Enabled", f_Enabled, "Speeds up game with hotkey");
        if (f_Enabled)
        {
            ConfigWidget("GameSpeed Hotkey", f_Hotkey);
            ConfigWidget(f_Speed, 1.0f, 0.0f, 20.0f, "Set GameSpeed Multiplier\n" \
                "Do NOT use this in the Open World, only use in menus/etc, VERY DANGEROUS!");
        }
    }

    bool GameSpeed::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void GameSpeed::DrawStatus()
    {
        ImGui::Text("GameSpeed");
    }

    GameSpeed& GameSpeed::GetInstance()
    {
        static GameSpeed instance;
        return instance;
    }

    void GameSpeed::OnGameUpdate()
    {
        static bool isSpeed = false;
        float currentSpeed = app::Time_get_timeScale(nullptr);

        if (f_Enabled)
        {
            if (f_Hotkey.value().IsPressed())
            {
                if (currentSpeed == 1.0f)
                {
                    app::Time_set_timeScale(f_Speed, nullptr);
                    isSpeed = true;
                }
            }

            if (!f_Hotkey.value().IsPressed() && isSpeed)
            {
                if (currentSpeed != 1.0f)
                {
                    app::Time_set_timeScale(1.0f, nullptr);
                    isSpeed = false;
                }
            }
        }
        else
        {
            // Aditional check if user is still pressing key and they decide to disable the feature
            if (isSpeed)
            {
                if (currentSpeed != 1.0f)
                {
                    app::Time_set_timeScale(1.0f, nullptr);
                    isSpeed = false;
                }
            }
        }
    }
}
