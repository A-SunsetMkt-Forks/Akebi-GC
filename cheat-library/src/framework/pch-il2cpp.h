// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_IL2CPP_H
#define PCH_IL2CPP_H

// add headers that you want to pre-compile here
#include "il2cpp-appdata.h"

#include <nlohmann/json.hpp>
#include <magic_enum.hpp>
#include <fmt/format.h>

#include <iostream>
#include <filesystem>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <queue>
#include <optional>
#include <random>

#include <Windows.h>

#include <cheat-base/Logger.h>
#include <cheat-base/config/config.h>
#include <cheat-base/util.h>
#include <cheat-base/cheat/CheatManagerBase.h>
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/cheat/misc/Settings.h>
#include <cheat-base/PipeTransfer.h>
#include <cheat-base/HookManager.h>
#include <cheat-base/Patch.h>
#include <cheat-base/render/gui-util.h>
#include <cheat-base/render/ImageLoader.h>

#include <cheat-base/events/event.hpp>
#include <cheat-base/events/handlers/methodeventhandler.hpp>
#include <cheat-base/events/handlers/functoreventhandler.hpp>
#include <cheat-base/events/joins/handlereventjoin.hpp>
#include <cheat-base/events/joins/eventjoinwrapper.hpp>

#include <cheat-base/ResourceLoader.h>

#include <cheat-base/globals.h>

#include <imgui.h>
#include <imgui_notify.h>

#endif //PCH_IL2CPP_H