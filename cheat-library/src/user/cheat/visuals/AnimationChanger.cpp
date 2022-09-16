#include "pch-il2cpp.h"
#include "AnimationChanger.h"

#include <helpers.h>
#include <cheat/events.h>
#include <misc/cpp/imgui_stdlib.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature
{
    static bool onEntityAppear = false;
    static void MoleMole_PlayerModule_EntityAppear_Hook(app::MoleMole_PlayerModule* __this, app::Proto_SceneEntityInfo* entity, app::VisionType__Enum type, uint32_t infoParam, MethodInfo* method);
    std::vector<std::string> animations;
    
    AnimationChanger::AnimationChanger() : Feature(),
        NF(f_Enabled, "Animation Changer", "Visuals::AnimationChanger", false),
        NF(f_Animation, "Animation", "Visuals::AnimationChanger", "Attack01"),
        NF(f_ApplyKey, "Apply Animation", "Visuals::AnimationChanger", Hotkey('Y')),
        NF(f_ResetKey, "Reset Animation", "Visuals::AnimationChanger", Hotkey('R')),
        NF(f_Delay, "Repeat Delay", "Visuals::AnimationChanger", 400),
        NF(f_Debug, "Debug Animations", "Visuals::AnimationChanger", false)
    {
        HookManager::install(app::MoleMole_PlayerModule_EntityAppear, MoleMole_PlayerModule_EntityAppear_Hook);
        events::GameUpdateEvent += MY_METHOD_HANDLER(AnimationChanger::OnGameUpdate);
    }

    const FeatureGUIInfo& AnimationChanger::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "AnimationChanger", "Visuals", false };
        return info;
    }

    void AnimationChanger::DrawMain()
    {
        ImGui::BeginGroupPanel("Animation Changer");
        {
            ConfigWidget(f_Enabled, "Changes active character's animation.");
            if (f_Enabled)
            {
                if (ImGui::BeginCombo("Animations", f_Animation.value().c_str()))
                {
                    for (auto &animation : animations)
                    {
                        bool is_selected = (f_Animation.value().c_str() == animation);
                        if (ImGui::Selectable(animation.c_str(), is_selected))
                            f_Animation.value() = animation;

                        if (is_selected)
                            ImGui::SetItemDefaultFocus();
                    }
                    ImGui::EndCombo();
                }

                ConfigWidget("Apply Key", f_ApplyKey, true);
                ConfigWidget("Reset Key", f_ResetKey, true);
                ConfigWidget("Delay", f_Delay, 1, 1, 1000000000, "Delay to repeat animation");
                ConfigWidget(f_Debug, "Logs current active character's animation state.");
            }
        }
        ImGui::EndGroupPanel();
    }

    bool AnimationChanger::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void AnimationChanger::DrawStatus()
    {
        ImGui::Text("AnimationChanger");
    }

    AnimationChanger& AnimationChanger::GetInstance()
    {
        static AnimationChanger instance;
        return instance;
    }

    // Taiga#5555: Called when you switch characters. Feel free to get rid of this hook if you find a better function.
    static void MoleMole_PlayerModule_EntityAppear_Hook(app::MoleMole_PlayerModule* __this, app::Proto_SceneEntityInfo* entity, app::VisionType__Enum type, uint32_t infoParam, MethodInfo* method)
    {
        CALL_ORIGIN(MoleMole_PlayerModule_EntityAppear_Hook, __this, entity, type, infoParam, method);
        onEntityAppear = false;
    }

    // Feel free to refactor.
    void AnimationChanger::OnGameUpdate()
    {
        if (!f_Enabled)
            return;

        UPDATE_DELAY(f_Delay);

        auto& manager = game::EntityManager::instance();
        auto avatar = manager.avatar();
        if (avatar->animator() == nullptr)
            return;

        auto avatarName = avatar->name();
        std::string objectName = il2cppi_to_string(app::Object_1_get_name(reinterpret_cast<app::Object_1*>(avatar->gameObject()), nullptr)).c_str();
        
        auto gameObj = app::GameObject_Find(string_to_il2cppi("EntityRoot/AvatarRoot/" + avatarName.substr(0, avatarName.find_first_of(" ")) + "/OffsetDummy/" + objectName.c_str()), nullptr);
        if (gameObj == nullptr)
            return;
        
        auto acComponent = app::GameObject_GetComponentByName(gameObj, string_to_il2cppi("AnimatorController"), nullptr);
        if (acComponent == nullptr)
            return;

        auto stateNamesArray = reinterpret_cast<app::AnimatorController*>(acComponent)->fields._stateNames;

        if (f_Debug)
            LOG_DEBUG(il2cppi_to_string(app::Extension_GetCurrentStateName(avatar->animator(), 0, reinterpret_cast<app::AnimatorController*>(acComponent), nullptr)).c_str());

        static bool isFull = false;
        for (int i = 0; i < stateNamesArray->max_length && !isFull; i++)
        {
            if (animations.size() == stateNamesArray->max_length)
            {
                std::sort(animations.begin(), animations.end());
                animations.erase(unique(animations.begin(), animations.end()), animations.end());
                isFull = true;
                continue;
            }
            
            animations.push_back(il2cppi_to_string(stateNamesArray->vector[i]).c_str());
        }

        if (!onEntityAppear && isFull)
        {
            animations.clear();
            isFull = false;
            onEntityAppear = true;
        }
        
        if (f_ApplyKey.value().IsPressed())
            app::Animator_Play(avatar->animator(), string_to_il2cppi(f_Animation.value().c_str()), 0, 0, nullptr);

        if (f_ResetKey.value().IsPressed())
            app::Animator_Rebind(avatar->animator(), nullptr);
    }
}
