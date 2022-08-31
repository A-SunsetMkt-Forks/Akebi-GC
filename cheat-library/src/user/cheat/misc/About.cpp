#include "pch-il2cpp.h"
#include "About.h"

#include <helpers.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature 
{
    const FeatureGUIInfo& About::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", "About", false };
        return info;
    }

    void About::DrawMain()
    {
        // Advertisement. To change/delete contact with Callow#1429
        ImGui::TextColored(ImColor(199, 16, 162, 255), "Our private ToF cheat: ");
        TextURL("Acai ToF", "http://acai-tof.shop", true, false);

        ImGui::TextColored(ImColor(28, 202, 214, 255), "Akebi github:");
        TextURL("Github link", "https://github.com/Akebi-Group/Akebi-GC", true, false);

		ImGui::TextColored(ImColor(28, 202, 214, 255), "Akebi discord:");
		TextURL("Discord invite link", "https://discord.com/invite/MmV8hNZB9S", true, false);

        ImGui::Text("Founder:");
        ImGui::SameLine();
        ImGui::TextColored(ImColor(0, 102, 255, 255), "Callow");
        
		ImGui::Text("Main developer and updater:");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(0, 102, 255, 255), "Taiga");

        ImGui::Text("Feature developer and Acai founder:");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(0, 102, 255, 255), "RyujinZX");

		ImGui::Text("Main contributors:");
		ImGui::TextColored(ImColor(0, 102, 255, 255), "WitchGod, m0nkrel, Shichiha, harlanx, andiabrudan, hellomykami");

		ImGui::Text("Full contributor list:");
		TextURL("Github link", "https://github.com/Akebi-Group/Akebi-GC/graphs/contributors", true, false);
    }

    About& About::GetInstance()
    {
        static About instance;
        return instance;
    }
}