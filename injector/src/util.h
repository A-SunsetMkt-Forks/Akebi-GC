#include <string>
#include <Windows.h>

#pragma once
std::string GetLastErrorAsString();
std::string* GetFilePathByUser();

int FindProcessId(const std::string& processName);
void WaitForCloseProcess(const std::string& processName);