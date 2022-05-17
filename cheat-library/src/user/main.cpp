#include "pch-il2cpp.h"
#include "main.h"

#include <helpers.h>
#include <il2cpp-init.h>
#include <cheat/cheat.h>
#include <cheat-base/cheat/misc/Settings.h>

#include <cheat/ILPatternScanner.h>
#include <resource.h>

bool StubTerminateProcess();

void Run(HMODULE* phModule)
{
#ifdef _DEBUG
	Sleep(10000);
#else
	while (GetModuleHandle("UserAssembly.dll") == nullptr)
	{
		Sleep(2000);
	}
    Sleep(15000);
#endif

	ResourceLoader::SetModuleHandle(*phModule);

	// Init config
	std::string configPath = (std::filesystem::current_path() / "cfg.json").string();
	config::Initialize(configPath);

	// Init logger
	auto& settings = cheat::feature::Settings::GetInstance();
	if (settings.f_FileLogging)
	{
		Logger::PrepareFileLogging((std::filesystem::current_path() / "logs").string());
		Logger::SetLevel(Logger::Level::Trace, Logger::LoggerType::FileLogger);
	}

	if (settings.f_ConsoleLogging)
	{
		Logger::SetLevel(Logger::Level::Debug, Logger::LoggerType::ConsoleLogger);
		il2cppi_new_console();
	}

	init_il2cpp();

	if (StubTerminateProcess())
		LOG_INFO("TerminateProcess stubbed successfully.");
	else
		LOG_ERROR("Stub TerminateProcess failed.");

	cheat::Init();

    LOG_DEBUG("Config path is at %s", configPath.c_str());
    LOG_DEBUG("UserAssembly.dll is at 0x%p", il2cppi_get_base_address());
    LOG_DEBUG("UnityPlayer.dll is at 0x%p", il2cppi_get_unity_address());
}

BOOL WINAPI TerminateProcess_Hook(HANDLE hProcessUINT, UINT uExitCode)
{
    return TRUE;
}

bool StubTerminateProcess()
{
    HMODULE hKernelBase = GetModuleHandle("kernelbase.dll");
    if (hKernelBase == NULL)
    {
        LOG_LAST_ERROR("Failed to get the kernelbase.dll handle.");
        return false;
    }

    FARPROC pTerminateProcess = GetProcAddress(hKernelBase, "TerminateProcess");
    if (pTerminateProcess == nullptr)
    {
        LOG_LAST_ERROR("Getting KernelBase::NtTerminateProcess failed.");
        return false;
    }
    using TerminateProcess_Type = BOOL(*)(HANDLE, UINT);
    
    HookManager::install((TerminateProcess_Type)pTerminateProcess, TerminateProcess_Hook);
    LOG_DEBUG("Terminate process hooked. Origin at 0x%p", HookManager::getOrigin(TerminateProcess_Hook));
    return true;
}