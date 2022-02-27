#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <TlHelp32.h>
#include <stdio.h>
#include <string>

#include "util.h"

using f_LoadLibraryA = HINSTANCE(WINAPI*)(const char* lpLibFilename);
using f_GetProcAddress = FARPROC(WINAPI*)(HMODULE hModule, LPCSTR lpProcName);
using f_DLL_ENTRY_POINT = BOOL(WINAPI*)(void* hDll, DWORD dwReason, void* pReserved);

#ifdef _WIN64
using f_RtlAddFunctionTable = BOOL(WINAPIV*)(PRUNTIME_FUNCTION FunctionTable, DWORD EntryCount, DWORD64 BaseAddress);
#endif

struct ConfigInfo {
	bool disableMhyprot;
	bool consoleLogging;
};

struct MANUAL_MAPPING_DATA
{
	f_LoadLibraryA pLoadLibraryA;
	f_GetProcAddress pGetProcAddress;
#ifdef _WIN64
	f_RtlAddFunctionTable pRtlAddFunctionTable;
#endif
	BYTE* pbase;
	HINSTANCE hMod;
	DWORD fdwReasonParam;
	LPVOID reservedParam;
	BOOL SEHSupport;
};


bool InjectDLL(HANDLE hProc, const std::string& filepath);

#ifdef _DEBUG
static bool LoadLibraryInject(HANDLE hProc, const std::string& dllpath);
#endif 

// Note: Exception support only x64 with build params /EHa or /EHc
bool ManualMapDll(HANDLE hProc, BYTE* pSrcData, SIZE_T FileSize, bool ClearHeader = false, bool ClearNonNeededSections = false, bool AdjustProtections = false, bool SEHExceptionSupport = false, DWORD fdwReason = DLL_PROCESS_ATTACH);
void __stdcall Shellcode(MANUAL_MAPPING_DATA* pData);