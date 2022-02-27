#include "pch-il2cpp.h"
#include "HookManager.h"

#include <iostream>

std::map<void*, void*> HookManager::holderMap;

//template<typename Fn>
//static void HookManager::set(Fn func, Fn handler) noexcept
//{
//	auto existHolder = get(handler);
//	if (existHolder != nullptr)
//		existHolder->disable();
//	
//	auto holder = HookFactory::install(func, handler);
//	holderMap[handler] = holder;
//}

//template<typename Fn>
//static HookHolder<Fn>* HookManager::get(Fn handler) noexcept
//{
//	if (holderMap.count(handler) == 0)
//		return nullptr;
//	return (HookHolder<Fn>)* holderMap[handler];
//}

//template<typename Fn>
//static Fn* HookManager::getOrigin(Fn handler) noexcept
//{
//	auto holder = get(handler);
//	if (holder == nullptr)
//		return nullptr;
//	return &holder->origin();
//}
//
//template<typename Fn>
//static void HookManager::remove(Fn func) noexcept
//{
//	holderMap.erase(func);
//}
