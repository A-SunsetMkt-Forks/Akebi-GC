#include "pch-il2cpp.h"

#include "protection-bypass.h"

#include "util/HookManager.h"
#include "util/Config.h"

#include <string>
#include <util/util.h>
#include <iostream>

static std::map<int32_t, std::string> correctSignatures;

app::Byte__Array* RecordUserData_Hook(int32_t nType) {

    if (correctSignatures.count(nType))
    {
        auto byteClass = app::GetIl2Classes()[0x25];

        auto content = correctSignatures[nType];
        auto newArray = (app::Byte__Array*)il2cpp_array_new(byteClass, content.size());
        memmove_s(newArray->vector, content.size(), content.data(), content.size());

        return newArray;
    }

    app::Byte__Array* result = callOrigin(RecordUserData_Hook, nType);
    auto length = app::Array_get_Length(reinterpret_cast<app::Array*>(result), nullptr);

    if (length == 0)
        return result;


    auto stringValue = std::string((char*)result->vector, length);
    correctSignatures[nType] = stringValue;

    std::cout << "Sniffed correct signature for type " << nType << " value " << stringValue << std::endl;

    return result;
}


void InitProtectionBypass() {
    HookManager::set(app::Unity_RecordUserData, RecordUserData_Hook);
    std::cout << "RecordUserData function address is 0x" << (void*)app::Unity_RecordUserData << std::endl;

    for (int i = 0; i < 4; i++) {
        std::cout << "Emulating call of RecordUserData with type " << i << std::endl;
        app::Application_RecordUserData(nullptr, i, nullptr);
    }

    if (Config::disableMhyProt) {
        std::cout << "Trying to close mhyprot handle." << std::endl;
        if (CloseHandleByName(L"\\Device\\mhyprot2"))
            std::cout << "Mhyprot2 handle successfuly closed. Happy hacking ^)" << std::endl;
        else
            std::cout << "Failed closing mhyprot2 handle. Maybe dev updated driver." << std::endl;
    }
    
}