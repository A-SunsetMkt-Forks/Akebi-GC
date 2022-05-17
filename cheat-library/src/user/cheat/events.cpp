#include "pch-il2cpp.h"
#include "events.h"

namespace cheat::events
{
	TEvent<> GameUpdateEvent{};
	TEvent<uint32_t> AccountChangedEvent{};
	TEvent<uint32_t, app::MotionInfo*> MoveSyncEvent{};
}