#include "pch-il2cpp.h"
#include "FakeTime.h"
#include <cheat/events.h>


namespace cheat::feature
{
	//CNLouisLiu
	void* LevelTimeManager = NULL;
	FakeTime::FakeTime() : Feature(),
		NF(f_Enabled, "FakeTime", "Enabled", false)
	{
		HookManager::install(app::LevelTimeManager_SetInternalTimeOfDay, LevelTimeManager_SetInternalTimeOfDay_Hook);

		events::GameUpdateEvent += MY_METHOD_HANDLER(FakeTime::OnGameUpdate);
	}
	FakeTime& FakeTime::GetInstance()
	{
		static FakeTime instance;
		return instance;
	}
	const FeatureGUIInfo& FakeTime::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "FakeTime", "World", true };
		return info;
	}
	void FakeTime::DrawMain()
	{
		ConfigWidget("Enabled", f_Enabled, "Keep the game in daylight (12 noon)");
	}
	bool FakeTime::NeedStatusDraw() const
	{
		return f_Enabled;
	}
	void FakeTime::DrawStatus()
	{
		ImGui::Text("FakeTime");
	}
	void FakeTime::OnGameUpdate()
	{
		if (LevelTimeManager != NULL&& f_Enabled) {
			CALL_ORIGIN(LevelTimeManager_SetInternalTimeOfDay_Hook, LevelTimeManager, 12.00f, false, false, (MethodInfo*)0);
		}
	}
	void FakeTime::LevelTimeManager_SetInternalTimeOfDay_Hook(void* __this, float inHours, bool force, bool refreshEnviroTime, MethodInfo* method) {
		float Hours = inHours;

		if (GetInstance().f_Enabled)
		{
			Hours = 12.00f;
		}
		CALL_ORIGIN(LevelTimeManager_SetInternalTimeOfDay_Hook, __this, Hours, force, refreshEnviroTime, method);
		
	}

}