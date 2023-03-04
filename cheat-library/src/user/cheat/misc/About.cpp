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
        ImGui::TextColored(ImColor(28, 202, 214, 255), "Jokebi github:");
        TextURL("Github link", "https://github.com/Jokebi-Group/", true, false);

		ImGui::TextColored(ImColor(28, 202, 214, 255), "Jokebi discord:");
		TextURL("Discord invite link", "https://discord.com/Jokebii", true, false);

        ImGui::Text("Founder:");
        ImGui::SameLine();
        ImGui::TextColored(ImColor(0, 102, 255, 255), "Fuck_Callow");
        
		ImGui::Text("Main developer and updater:");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(0, 102, 255, 255), "Taiga");

		ImGui::Text("Main contributors:");
		ImGui::TextColored(ImColor(0, 102, 255, 255), "RyujinZX, WitchGod, m0nkrel, Shichiha, harlanx, andiabrudan, hellomykami");

		ImGui::Text("Full contributor list:");
		TextURL("Github link", "https://github.com/Group-Group/", true, false);
    }

    About& About::GetInstance()
    {
        static About instance;
        return instance;
    }
}