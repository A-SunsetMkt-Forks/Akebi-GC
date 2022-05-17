#pragma once

#include <il2cpp-appdata.h>

#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/Config.h>

namespace cheat::feature
{
    class CustomTeleports : public Feature
    {
    public:
        config::Field<config::Toggle<Hotkey>> f_DebugMode;
        static CustomTeleports& GetInstance();
        const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
    private:
        CustomTeleports();
    };
}