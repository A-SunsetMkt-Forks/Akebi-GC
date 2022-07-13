#pragma once

#include <il2cpp-appdata.h>

#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/Config.h>
#include <set>

namespace cheat::feature
{
    class Teleport
    {
        public:
            Teleport(std::string name, app::Vector3 position, std::string description)
            {
                this->name = name;
                this->position = position;
                this->description = description;
            }
            std::string name;
            app::Vector3 position;
            std::string description;
    };
    
    class CustomTeleports : public Feature
    {
    public:
        config::Field<config::Toggle<Hotkey>> f_DebugMode;
        config::Field<config::Toggle<Hotkey>> f_Enabled;
        config::Field<Hotkey> f_Next;
        config::Field<Hotkey> f_Previous;
        static CustomTeleports& GetInstance();
        const FeatureGUIInfo& GetGUIInfo() const override;

        void CheckFolder();
        bool ValidateTeleport(std::string name);
        Teleport Teleport_(std::string name, app::Vector3 position, std::string description);
        void SerializeTeleport(Teleport t);
        void ReloadTeleports();
        Teleport SerializeFromJson(std::string json, bool fromfile);


		void DrawMain() override;
        virtual bool NeedStatusDraw() const override;
        void DrawStatus() override;
        
        std::vector<Teleport> Teleports;
        std::filesystem::path dir = std::filesystem::current_path() / "teleports";

    private:
        std::set<unsigned int> checkedIndices;
        std::set<unsigned int> searchIndices;
        bool selectedByClick = false;
        int selectedIndex = -1;
        std::string selectedName;
        std::string selectedIndexName;
        CustomTeleports();
        void OnTeleportKeyPressed(bool next);
        void OnPrevious();
        void OnNext();
        void UpdateIndexName();
    };

}