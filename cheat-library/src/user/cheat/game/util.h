#pragma once

#include <il2cpp-appdata.h>
#include <vector>

#include <helpers.h>

#include "Entity.h"
#include "SimpleFilter.h"

namespace cheat::game
{
	struct WaypointInfo
	{
		uint32_t sceneId = 0;
		uint32_t waypointId = 0;
		app::Vector3 position = {};
		app::MapModule_ScenePointData* data = nullptr;
	};

	WaypointInfo FindNearestWaypoint(app::Vector3& position, uint32_t targetId = 0);
	static std::vector<WaypointInfo> GetUnlockedWaypoints(uint32_t targetId = 0);
	uint32_t GetCurrentMapSceneID();
	uint32_t GetCurrentPlayerSceneID();

	app::GadgetEntity* GetGadget(uint32_t runtimeID);
	app::GadgetEntity* GetGadget(Entity* entity);
	app::GadgetEntity* GetGadget(app::BaseEntity* entity);

	game::Entity* FindNearestEntity(const IEntityFilter& filter);
	game::Entity* FindNearestEntity(std::vector<game::Entity*>& entities);

	app::AccountDataItem* GetAccountData();
}
