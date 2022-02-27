#include <Windows.h>
#include <iostream>
#include <sstream>
#include <filesystem>

#include "injector.h"
#include "simple-ini.hpp"
#include "util.h"

const std::string GlobalGenshinProcName = "GenshinImpact.exe";
const std::string ChinaGenshinProcName = "YuanShen.exe";

const char* INIFileName = "config.ini";

static CSimpleIni ini;

HANDLE OpenGenshinProcess();

int main(int argc, char* argv[])
{
    auto path = std::filesystem::path(argv[0]).parent_path();
    std::filesystem::current_path(path);
    
    WaitForCloseProcess(GlobalGenshinProcName);
    WaitForCloseProcess(ChinaGenshinProcName);

    Sleep(1000); // Wait for unloading all dlls.

    ini.SetUnicode();
    ini.LoadFile(INIFileName);

    HANDLE hProcess = OpenGenshinProcess();
    if (hProcess == NULL)
    {
        std::cout << "Failed to open GenshinImpact process." << std::endl;
        return 1;
    }

    ini.SaveFile(INIFileName);

    std::filesystem::current_path(path);

    std::string filename = (argc == 2 ? argv[1] : "CLibrary.dll");
    std::filesystem::path currentDllPath = std::filesystem::current_path() / filename;
    std::filesystem::path tempDllPath = std::filesystem::temp_directory_path() / filename;

    std::filesystem::copy(currentDllPath, tempDllPath, std::filesystem::copy_options::update_existing);
    InjectDLL(hProcess, tempDllPath.string());

    CloseHandle(hProcess);
}

HANDLE OpenGenshinProcess() {
    STARTUPINFOA startInfo{};
    PROCESS_INFORMATION processInformation{};

    auto savedPath = ini.GetValue("Inject", "GenshinPath");
    bool exePathNotExist = savedPath == nullptr;

    std::string* filePath = exePathNotExist ? nullptr : new std::string(savedPath);
    if (exePathNotExist) {
        std::cout << "Genshin path not found. Please point to it manually. ^)" << std::endl;
        filePath = GetFilePathByUser();
        if (filePath == nullptr) {
            std::cout << "Failed to get genshin path from user. Exiting..." << std::endl;
            return NULL;
        }
    }

    BOOL result = CreateProcessA(filePath->c_str(),
        nullptr, 0, 0, false, CREATE_SUSPENDED, nullptr, nullptr, &startInfo, &processInformation);
    if (result == FALSE) {
        std::cout << "Failed to create game process." << std::endl;
        std::cout << "Error: " << GetLastErrorAsString() << std::endl;
        std::cout << "If you have problem with GenshinImpact.exe path. You can change it manually in " << INIFileName << "." << std::endl;
        return NULL;
    }

    if (exePathNotExist) {
        ini.SetValue("Inject", "genshinPath", (*filePath).c_str());
        std::cout << "New GenshinImpact.exe path saved to " << INIFileName << "." << std::endl;
    }

    delete filePath;

    std::cout << "Created game process." << std::endl;

    ResumeThread(processInformation.hThread);

    return processInformation.hProcess;
}
