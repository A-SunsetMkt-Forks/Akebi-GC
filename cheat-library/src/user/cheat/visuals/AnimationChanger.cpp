#include "pch-il2cpp.h"
#include "AnimationChanger.h"

#include <helpers.h>
#include <cheat/events.h>
#include <misc/cpp/imgui_stdlib.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature
{
    static std::string f_Animation;

    AnimationChanger::AnimationChanger() : Feature(),
		NFEX(f_Enabled, "Animation Changer", "AnimationChanger", "Visuals", false, false)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(AnimationChanger::OnGameUpdate);
    }

    const FeatureGUIInfo& AnimationChanger::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "AnimationChanger", "Visuals", false };
        return info;
    }

    void AnimationChanger::DrawMain()
    {
        ConfigWidget(f_Enabled, "Changes active character's animation.");
        ImGui::InputText("Animation", &f_Animation);
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

    void AnimationChanger::OnGameUpdate()
    {
        auto& manager = game::EntityManager::instance();
        auto avatar = manager.avatar();
        if (avatar->animator() == nullptr)
            return;

        static bool changed = false;

        if (f_Enabled)
        {
            auto avatarObj = avatar->gameObject();
            auto rootObj = app::MoleMole_BaseEntity_get_rootGameObject(avatar->raw(), nullptr); // (Clone)
            auto path = app::Object_1_get_name(reinterpret_cast<app::Object_1*>(avatarObj), nullptr);
            auto pathavatarObj = app::Object_1_get_name(reinterpret_cast<app::Object_1*>(rootObj), nullptr); // (Clone)
            
            if (!changed)
            {
                app::Animator_Play(avatar->animator(), string_to_il2cppi(f_Animation.c_str()), 0, 0, nullptr);
                changed = true;
            }

        }
        else
        {
            if (changed)
            {
                app::Animator_Rebind(avatar->animator(), nullptr);
                changed = false;
            }
        }
    }
}

/*
//------Animations------\\
SlipFaceWall
SlipBackWall
DropDown
JumpOffWall
Jump
JumpForRun
JumpForWalk
Fly
FlyStart
JumpForSprint
SwimIdle
SwimMove
SwimDash
ClimbMove1
ClimbIdle
ClimbJump
ClimbMove0
FallToGroundRun
FallOnGroundLit
FallOnGround
FallToGroundRunHard
FallToGroundSprint
Walk
Run
Standby
RunToIdle
RunToWalk
WalkToIdle
WalkToRun
Sprint
SprintToIdle
SprintToRun
ClimbDownToGround
SprintBS
ShowUp
CrouchToStandby
CrouchIdle
CrouchRoll
CrouchMove
SkiffNormal
Upstairs
JumpUpWallForStandby
JumpUpWallReady
Standby2ClimbA
SwimJump
SwimJumpDrop
SwimJumpToWater
Standby2ClimbB
CrouchDrop
TurnDir
StandbyWeapon
StandbyPutaway
StandbyPutawayOver
Icespine_Out
Icespine
LiquidStrike_MoveStandby
LiquidStrike_AS
LiquidStrike_BS
LiquidStrike_BS1
LiquidStrike_Move
LiquidStrike_Strike
LiquidStrike_FatalStandby
LiquidStrike_FatalMove
LiquidStrike_AS_OnWater
LiquidStrike_BS_0
FrozenWindmill
FrozenWindmill_AS
Attack03
Attack04
Attack05
Attack01
Attack02
ExtraAttack
ExtraAttack_AS
FallingAnthem_Loop
FallingAnthem_AS_2
FallingAnthem_BS_1
FallingAnthem_BS_2
FallingAnthem_AS_1
FallingAnthem_Loop_Low
SitBDown
SitBLoop
SitBUp
SitDown
SitLoop
SitUp
StandbyShow_01
StandbyShow_02
StandbyVoice
Think01BS
Think01Loop
Think01AS
Akimbo02BS
Akimbo02Loop
Akimbo02AS
ChannelBS
ChannelLoop
ChannelAS
PlayMusic_Lyre_AS
PlayMusic_Lyre_BS
PlayMusic_Lyre_Loop
PlayMusic_Qin_BS
PlayMusic_Qin_AS
PlayMusic_Qin_Loop
ActivitySkill_ElectricCoreFly
Hit_H
Hit_L
Hit_Throw
Hit_Throw_Ground
Hit_ThrowAir
Struggle
NormalDie
SwimDie
HitGroundDie
FallDie_AS
FallDie

//------Main Character------\\
UziExplode_AS
UziExplode_BS
UziExplode_Charge_01
UziExplode_Strike_02
UziExplode_Charge_02
UziExplode_Strike_01
UziExplode_BS_1
WindBreathe_AS
WindBreathe
Hogyoku_AS
Hogyoku_BS
Hogyoku
Hogyoku_Charge
Hogyoku_Charge_AS
Hogyoku_Charge_2
RockTide_AS
RockTide
CrouchThrowBS
CrouchThrowLoop
CrouchThrowAS
FindCatThrowBS
FindCatThrowLoop
FindCatThrowAS
Player_Electric_ElementalArt
Player_Electric_ElementalArt_AS
Player_Electric_ElementalBurst
Player_Electric_ElementalBurst_AS
PutHand01BS
PutHand01Loop
PutHand01AS
Akimbo01BS
Backrake01BS
Forerake01BS
StrikeChest01BS
Akimbo01Loop
Akimbo01AS
Backrake01Loop
Backrake01AS
Forerake01Loop
Forerake01AS
StrikeChest01Loop
StrikeChest01AS
HoldHead01BS
HoldHead01Loop
HoldHead01AS
Clap01
Turn01_90LBS
Turn01_90RBS
Turn01_90LAS
Turn01_90RAS
Alert01BS
Alert01Loop
Alert01AS
Fishing01_BS
Fishing01Loop
Fishing01AS
Think01_BS
Think01_Loop
Think01_AS
Channel01BS
Channel01Loop
Channel01AS
Fishing_Battle_BS
Fishing_Cast_AS
Fishing_Cast_BS
Fishing_Cast_Loop
Fishing_Choose
Fishing_Choose_Loop
Fishing_End
Fishing_Pull_01
Fishing_Pull_02
Fishing_Wait
Fishing_Pull_Fail
Bartender_MixingStandby
Bartender_MixingStart
Bartender_MixingToPour
Bartender_Pour
Bartender_PourFinish
Bartender_PourStandby
Bartender_AddLoop
Bartender_PrepareStart
Bartender_Standby
Bartender_AddStandby
Bartender_PrepareToStandby
Bartender_StandbyFinish
Blocking_BS
Blocking_Loop
Blocking_Back
Blocking_Bounce
Blocking_Hit
Blocking_AS
*/