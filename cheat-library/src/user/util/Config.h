#pragma once
#include <string>

class Config {
public:
	static bool disableMhyProt;
	static bool fileLogging;
	static bool consoleLogging;

	static void Init(const std::string& configFile);
};