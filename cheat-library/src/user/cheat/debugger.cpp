#include <pch-il2cpp.h>

enum THREADINFOCLASS { ThreadHideFromDebugger = 0x11 };

typedef NTSTATUS(WINAPI* NtQueryInformationThread_t)(HANDLE, THREADINFOCLASS, PVOID, ULONG, LPVOID);
typedef NTSTATUS(WINAPI* NtSetInformationThread_t)(HANDLE, THREADINFOCLASS, PVOID, ULONG);
typedef void(WINAPI* DbgUiRemoteBreakin_t)();

NtQueryInformationThread_t fnNtQueryInformationThread = nullptr;
NtSetInformationThread_t fnNtSetInformationThread = nullptr;
DbgUiRemoteBreakin_t fnDbgUiRemoteBreakin = nullptr;

static void RunVEH();
static void FindAPI();
static bool Patch_NtSetInformationThread();
static bool Patch_DbgUiRemoteBreakin();

static long WINAPI DebugHandler(PEXCEPTION_POINTERS exception);
static void WINAPI DbgUiRemoteBreakin_Hook();
static NTSTATUS WINAPI NtSetInformationThread_Hook(HANDLE handle, THREADINFOCLASS infoClass, PVOID pValue, ULONG pSize);

void DebuggerBypassPre()
{
	if (!Patch_NtSetInformationThread())
		LOG_ERROR("Failed to patch NtSetInformationThread, so main thread will be hidden from debugger. ^(");
}

void DebuggerBypassPost()
{
	if (!Patch_DbgUiRemoteBreakin())
		LOG_ERROR("Failed to patch DbgUiRemoteBreakin, so when debugger will try to attach, game crash. ^(");

	RunVEH();
}

static void RunVEH()
{
	AddVectoredExceptionHandler(1, DebugHandler);
}

static bool Patch_NtSetInformationThread()
{
	if (fnNtSetInformationThread == nullptr && (FindAPI(), fnNtSetInformationThread == nullptr))
		return false;

	HookManager::install(fnNtSetInformationThread, NtSetInformationThread_Hook);
	LOG_DEBUG("NtSetInformationThread api hooked. Origin at 0x%p", HookManager::getOrigin(NtSetInformationThread_Hook));
	return true;
}

static bool Patch_DbgUiRemoteBreakin()
{
	if (fnDbgUiRemoteBreakin == nullptr && (FindAPI(), fnDbgUiRemoteBreakin == nullptr))
		return false;

	HookManager::install(fnDbgUiRemoteBreakin, DbgUiRemoteBreakin_Hook);
	LOG_DEBUG("DbgUiRemoteBreakin api hooked. Origin at 0x%p", HookManager::getOrigin(DbgUiRemoteBreakin_Hook));
	return true;
}

static void FindAPI()
{
	HMODULE hNTDLL = GetModuleHandle("ntdll.dll");
	if (hNTDLL == NULL)
	{
		LOG_LAST_ERROR("Failed to get the 'ntdll.dll' handle");
		return;
	}

	if (fnDbgUiRemoteBreakin == nullptr)
	{
		fnDbgUiRemoteBreakin = reinterpret_cast<DbgUiRemoteBreakin_t>(GetProcAddress(hNTDLL, "DbgUiRemoteBreakin"));
		if (fnDbgUiRemoteBreakin == nullptr)
			LOG_LAST_ERROR("GetProcAddress(ntdll::DbgUiRemoteBreakin) failed");
	}

	if (fnNtQueryInformationThread == nullptr)
	{
		fnNtQueryInformationThread = reinterpret_cast<NtQueryInformationThread_t>(GetProcAddress(hNTDLL, "NtQueryInformationThread"));
		if (fnNtQueryInformationThread == nullptr)
			LOG_LAST_ERROR("GetProcAddress(ntdll::NtQueryInformationThread) failed");
	}

	if (fnNtSetInformationThread == nullptr)
	{
		fnNtSetInformationThread = reinterpret_cast<NtSetInformationThread_t>(GetProcAddress(hNTDLL, "NtSetInformationThread"));
		if (fnNtSetInformationThread == nullptr)
			LOG_LAST_ERROR("GetProcAddress(ntdll::NtSetInformationThread) failed");
	}
}

// Modified version of https://guidedhacking.com/threads/how-to-find-hidden-threads-threadhidefromdebugger-antidebug-trick.14281/
static bool IsThreadHidden(DWORD threadID)
{
	if (fnNtQueryInformationThread == nullptr &&
		(FindAPI(), fnNtQueryInformationThread == nullptr)) // Yeah, seems like a shit ^)
		return false;

	HANDLE hThread = OpenThread(
		THREAD_QUERY_INFORMATION,
		false,
		threadID);

	if (hThread == NULL) {
		std::cout << " - Error :" << util::GetLastErrorAsString();
		return false;
	}

	unsigned char lHideThread = 0;
	ULONG lRet = 0;
	NTSTATUS errorCode = fnNtQueryInformationThread(hThread, (THREADINFOCLASS)0x11, &lHideThread, sizeof(lHideThread), &lRet);
	WaitForSingleObject(hThread, INFINITE);
	return static_cast<bool>(lHideThread);
}

static long WINAPI DebugHandler(PEXCEPTION_POINTERS exception) {
	PEXCEPTION_RECORD record = exception->ExceptionRecord;
	PCONTEXT context = exception->ContextRecord;

	if (record->ExceptionCode == EXCEPTION_SINGLE_STEP) {
		SuspendThread(GetCurrentThread());
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	else if (record->ExceptionCode == EXCEPTION_BREAKPOINT)
	{
		CONTEXT ctx = {};
		ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;

		DWORD threadID = GetThreadId(GetCurrentThread());
		LOG_WARNING("Breakpoint exception! Thread: %d; Hidden: %s", threadID, IsThreadHidden(threadID) ? "true" : "false");
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	else if (context->Rip == 0x8887777)
	{
		SuspendThread(GetCurrentThread());
		return EXCEPTION_CONTINUE_EXECUTION;
	}
	return EXCEPTION_CONTINUE_SEARCH;
}

static void WINAPI DbgUiRemoteBreakin_Hook()
{
	return;
}

static NTSTATUS WINAPI NtSetInformationThread_Hook(HANDLE handle, THREADINFOCLASS infoClass, PVOID pValue, ULONG pSize)
{
	if (infoClass == ThreadHideFromDebugger)
	{
		return 1;
	}
	return CALL_ORIGIN(NtSetInformationThread_Hook, handle, infoClass, pValue, pSize);
}