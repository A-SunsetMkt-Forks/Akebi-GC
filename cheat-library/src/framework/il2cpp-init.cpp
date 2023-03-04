// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// IL2CPP application initializer

#include "pch-il2cpp.h"

#include "il2cpp-init.h"
#include "helpers.h"

#include <cheat/ILPatternScanner.h>

// IL2CPP APIs
#define DO_API(r, n, p) r (*n) p
#include "il2cpp-api-functions.h"
#undef DO_API

// Application-specific functions
#define DO_APP_FUNC(a, r, n, p) r (*n) p
#define DO_APP_FUNC_METHODINFO(a, n) struct MethodInfo ** n
namespace app {
#include "il2cpp-functions.h"
#include "il2cpp-unityplayer-functions.h"
}
#undef DO_APP_FUNC
#undef DO_APP_FUNC_METHODINFO

// TypeInfo pointers
#define DO_TYPEDEF(a, n) n ## __Class** n ## __TypeInfo
#define DO_SINGLETONEDEF(a, n) Singleton_1__Class** n ## __TypeInfo
namespace app {
#include "il2cpp-types-ptr.h"
#include <resource.h>
}
#undef DO_TYPEDEF
#undef DO_SINGLETONEDEF

void init_static_offsets()
{
	// Get base address of IL2CPP module
	uintptr_t baseAddress = il2cppi_get_base_address();

	// Define IL2CPP API function addresses
	#define DO_API(r, n, p) n = (r (*) p)(baseAddress + n ## _ptr)
	#include "il2cpp-api-functions.h"
	#undef DO_API

	// Define function addresses
	#define DO_APP_FUNC(a, r, n, p) n = (r (*) p)(baseAddress + a)
	#define DO_APP_FUNC_METHODINFO(a, n) n = (struct MethodInfo **)(baseAddress + a)
	#include "il2cpp-functions.h"
	#undef DO_APP_FUNC
	#undef DO_APP_FUNC_METHODINFO

	// Define TypeInfo variables
	#define DO_SINGLETONEDEF(a, n) n ## __TypeInfo = (Singleton_1__Class**) (baseAddress + a)
	#define DO_TYPEDEF(a, n) n ## __TypeInfo = (n ## __Class**) (baseAddress + a)
	#include "il2cpp-types-ptr.h"
	#undef DO_TYPEDEF
	#undef DO_SINGLETONEDEF

	uintptr_t unityPlayerAddress = il2cppi_get_unity_address();
	// Define UnityPlayer functions
	#define DO_APP_FUNC(a, r, n, p) n = (r (*) p)(unityPlayerAddress + a)
	#define DO_APP_FUNC_METHODINFO(a, n) n = (struct MethodInfo **)(unityPlayerAddress + a)
	#include "il2cpp-unityplayer-functions.h"
	#undef DO_APP_FUNC
	#undef DO_APP_FUNC_METHODINFO
}

void init_scanned_offsets()
{
	// Get base address of IL2CPP module
	uintptr_t baseAddress = il2cppi_get_base_address();

#define SELECT_OR(container, type, val, def) { auto value = val; if (value == 0) container = (type)(def); else container = (type)val; }

	static config::Field<nlohmann::json> offsetDataField = config::CreateField<nlohmann::json>("OffsetData", "OffsetData", "PatternScanner", true, nlohmann::json::object());

	std::string signatures = ResourceLoader::Load("Signatures", RT_RCDATA);

	auto scanner = ILPatternScanner();
	scanner.ParseSignatureFile(signatures);
	scanner.LoadJson(offsetDataField);

	using namespace app;

	// Define IL2CPP API function addresses
	#define DO_API(r, n, p) n = (r (*) p) scanner.SearchAPI(#n);
	#include "il2cpp-api-functions.h"
	#undef DO_API

	il2cpp_thread_attach(il2cpp_domain_get());

	// Define function addresses
	#define DO_APP_FUNC(a, r, n, p) SELECT_OR(n, r (*) p, scanner.Search("UserAssembly.dll", #n), baseAddress + a)
	#define DO_APP_FUNC_METHODINFO(a, n) SELECT_OR(n, struct MethodInfo **, scanner.SearchMethodInfo(#n), baseAddress + a)
	#include "il2cpp-functions.h"
	#undef DO_APP_FUNC
	#undef DO_APP_FUNC_METHODINFO

	// Define TypeInfo variables
	#define DO_SINGLETONEDEF(a, n) SELECT_OR(n ## __TypeInfo, Singleton_1__Class**, scanner.SearchTypeInfo(#n), baseAddress + a)
	#define DO_TYPEDEF(a, n) SELECT_OR(n ## __TypeInfo, n ## __Class**, scanner.SearchTypeInfo(#n), baseAddress + a)
	#include "il2cpp-types-ptr.h"
	#undef DO_TYPEDEF
	#undef DO_SINGLETONEDEF

		uintptr_t unityPlayerAddress = il2cppi_get_unity_address();
		// Define UnityPlayer functions
	#define DO_APP_FUNC(a, r, n, p) SELECT_OR(n, r (*) p, scanner.Search("UnityPlayer.dll", #n), unityPlayerAddress + a)
	#include "il2cpp-unityplayer-functions.h"
	#undef DO_APP_FUNC

	if (scanner.IsUpdated())
	{
		scanner.SaveJson(offsetDataField);
		offsetDataField.FireChanged();

		LOG_INFO("Seems like some offsets was found for a first time. Recommend to restart game for correct cheat and game work.");
	}

#undef SELECT_OR
}

bool IsStaticCheckSumValid()
{
	PatternScanner scanner;
	std::string assemblyChecksumData = ResourceLoader::Load("AssemblyChecksums", RT_RCDATA);

	nlohmann::json assemblyChecksumJson = nlohmann::json::parse(assemblyChecksumData, nullptr, false);
	if (assemblyChecksumJson.is_discarded())
	{
		LOG_ERROR("Failed to parse assembly checksum data.");
		return false;
	}

	static config::Field<nlohmann::json> checksumTimestamps = 
		config::CreateField<nlohmann::json>("ChecksumTimestamp", "m_CheckSumTimestamp", "PatternScanner", true, nlohmann::json::object());
	
	std::string version = assemblyChecksumJson["game_version"];

	for (auto& [moduleName, checksumData] : assemblyChecksumJson["modules"].items())
	{
		if (checksumTimestamps.value().contains(moduleName))
			checksumData["timestamp"] = checksumTimestamps.value()[moduleName];

		if (!scanner.IsValidModuleHash(moduleName, checksumData))
		{
			LOG_WARNING("Seems like assembly checksum don't match with version %s. Either your game isn't updated or you downloaded the wrong version of Akebi", version.c_str());
			system("pause");
			return false;
		}

		checksumTimestamps.value()[moduleName] = scanner.GetModuleTimestamp(moduleName);
	}
	checksumTimestamps.FireChanged();

	return true;
}

// IL2CPP application initializer
void init_il2cpp()
{
	if (IsStaticCheckSumValid())
	{
		init_static_offsets();
		return;
	}

#ifdef _PATTERN_SCANNER
	init_scanned_offsets();
#else
	init_static_offsets();
#endif
	
}