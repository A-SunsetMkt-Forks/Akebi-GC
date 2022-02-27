#include "pch-il2cpp.h"

#include "Config.h"

#include "simple-ini.hpp"

bool Config::disableMhyProt = false;
bool Config::consoleLogging = false;
bool Config::fileLogging = false;

static CSimpleIni ini;
static bool changed = false;

bool LoadBool(const char* section, const char* key, bool defaultValue = false) {
	auto result = ini.GetBoolValue(section, key, defaultValue);
	ini.SetBoolValue(section, key, result);
	return result;
}

void Config::Init(const std::string& configFile)
{
	ini.LoadFile(configFile.c_str());
	
	disableMhyProt = LoadBool("DLLUtil", "DisableMhyprot", true);
	consoleLogging = LoadBool("DLLUtil", "ConsoleLogging", true);
	fileLogging =    LoadBool("DLLUtil", "FileLogging", true);

	ini.SaveFile(configFile.c_str());
}
