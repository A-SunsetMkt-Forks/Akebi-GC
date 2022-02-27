#pragma once

#include "HookLib.h"
#include <map>

#define callOrigin(function, ...) \
	HookManager::getOrigin(function)(__VA_ARGS__);

class HookManager
{
public:
	template <typename Fn>
	static void set(Fn func, Fn handler) {
		auto existHolder = get(handler);
		if (existHolder != nullptr)
			existHolder->disable();
	
		auto holder = new HookHolder(func, handler);
		holder->enable();

		holderMap[reinterpret_cast<void*>(handler)] = reinterpret_cast<void*>(holder);
	}

	template <typename Fn>
	[[nodiscard]] static HookHolder<Fn>* get(Fn handler) noexcept {
		if (holderMap.count(reinterpret_cast<void*>(handler)) == 0)
			return nullptr;
		return reinterpret_cast<HookHolder<Fn>*>(holderMap[reinterpret_cast<void*>(handler)]);
	}

	template <typename Fn>
	[[nodiscard]] static Fn getOrigin(Fn handler) noexcept {
		auto holder = get(handler);
		return holder->original();
	}

	template <typename Fn>
	[[nodiscard]] static void remove(Fn handler) noexcept {
		holderMap.erase(reinterpret_cast<void*>(handler));
	}

private:
	static std::map<void*, void*> holderMap;
};


