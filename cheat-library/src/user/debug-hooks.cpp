#include "pch-il2cpp.h"

#include "debug-hooks.h"

#include "util/HookManager.h"
#include "helpers.h"
#include <iostream>

app::Byte__Array* LoadCustomLuaFile_Hook(app::LuaManager* __this, app::String** filePath, bool* recycleBytes, MethodInfo* method) {
    std::cout << "Load library: " << il2cppi_to_string(*filePath) << ".lua" << std::endl;
    return callOrigin(LoadCustomLuaFile_Hook, __this, filePath, recycleBytes, method);
}

void __stdcall SendInfo_Hook(app::GameLogin* __this, app::GKOJAICIOPA* info, MethodInfo* method) {
    std::cout << "Game sending game info to server." << std::endl;
    std::cout << "Content: " << std::endl;

#define printString(i) if (info->fields.string_ ## i > (void *)1 && info->fields.string_ ## i ##->fields.length > 0)\
    std::cout << "\tfield#" << i << ": " << il2cppi_to_string(info->fields.string_ ## i) << std::endl;

    printString(1);
    printString(2);
    printString(3);
    printString(4);
    printString(5);
    printString(6);
    printString(7);
    printString(8);
    printString(9);
    printString(10);
    printString(11);
    printString(12);
    printString(13);
    printString(14);
    printString(15);
    printString(16);

#undef printString

    callOrigin(SendInfo_Hook, __this, info, method);
}


void InitDebugHooks() {
    HookManager::set(app::LuaManager_LoadCustomLuaFile, LoadCustomLuaFile_Hook);
    std::cout << "Hooked LoadCustomLuaFile. Origin at 0x" << (void*)HookManager::getOrigin(LoadCustomLuaFile_Hook) << std::endl;
    
    HookManager::set(app::GameLogin_SendInfo_2, SendInfo_Hook);
    std::cout << "Hooked GameLogin::SendGameInfo. Origin at 0x" << (void*)HookManager::getOrigin(SendInfo_Hook) << std::endl;
}