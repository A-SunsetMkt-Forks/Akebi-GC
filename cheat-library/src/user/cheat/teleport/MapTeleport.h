#pragma once

#include <il2cpp-appdata.h>

#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

	class MapTeleport : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<bool> f_DetectHeight;
		config::Field<float> f_DefaultHeight;
		config::Field<Hotkey> f_Key;

		static MapTeleport& GetInstance();

		void TeleportTo(app::Vector3 position, bool needHeightCalc = false, uint32_t sceneId = 0);

		void TeleportTo(app::Vector2 mapPosition);

		void OnGetTargetPos(app::Vector3& position);

		void OnCheckTeleportDistance(bool needTransByServer);

		void OnPerformPlayerTransmit(app::Vector3& position);

		void OnSetAvatarPosition(app::Vector3& position);

		void OnGameUpdate();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
		
	private:
		struct TeleportTaskInfo
		{
			bool waitingThread = false;
			bool needHeightCalculation = false;
			int currentStage = 0;
			app::Vector3 targetPosition = {};
			uint32_t sceneId = 0;
			uint32_t waypointId = 0;
		};
		TeleportTaskInfo taskInfo;

		MapTeleport();
	};
}

