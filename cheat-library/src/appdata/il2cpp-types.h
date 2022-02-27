// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2017.4.15 - 2017.4.40

#if defined(_GHIDRA_) || defined(_IDA_)
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;
#endif

#if defined(_GHIDRA_)
typedef __int64 size_t;
typedef size_t intptr_t;
typedef size_t uintptr_t;
#endif

#if !defined(_GHIDRA_) && !defined(_IDA_)
#define _CPLUSPLUS_
#endif

// ******************************************************************************
// * IL2CPP internal types
// ******************************************************************************

typedef uint32_t Il2CppMethodSlot;
const uint32_t kInvalidIl2CppMethodSlot = 65535;
const int ipv6AddressSize = 16;
typedef int32_t il2cpp_hresult_t;
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppType Il2CppType;
typedef struct EventInfo EventInfo;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppArray Il2CppArray;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppProfiler Il2CppProfiler;
typedef struct Il2CppObject Il2CppObject;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppReflectionType Il2CppReflectionType;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppThread Il2CppThread;
typedef struct Il2CppAsyncResult Il2CppAsyncResult;
typedef enum Il2CppProfileFlags
{
    IL2CPP_PROFILE_NONE = 0,
    IL2CPP_PROFILE_APPDOMAIN_EVENTS = 1 << 0,
    IL2CPP_PROFILE_ASSEMBLY_EVENTS = 1 << 1,
    IL2CPP_PROFILE_MODULE_EVENTS = 1 << 2,
    IL2CPP_PROFILE_CLASS_EVENTS = 1 << 3,
    IL2CPP_PROFILE_JIT_COMPILATION = 1 << 4,
    IL2CPP_PROFILE_INLINING = 1 << 5,
    IL2CPP_PROFILE_EXCEPTIONS = 1 << 6,
    IL2CPP_PROFILE_ALLOCATIONS = 1 << 7,
    IL2CPP_PROFILE_GC = 1 << 8,
    IL2CPP_PROFILE_THREADS = 1 << 9,
    IL2CPP_PROFILE_REMOTING = 1 << 10,
    IL2CPP_PROFILE_TRANSITIONS = 1 << 11,
    IL2CPP_PROFILE_ENTER_LEAVE = 1 << 12,
    IL2CPP_PROFILE_COVERAGE = 1 << 13,
    IL2CPP_PROFILE_INS_COVERAGE = 1 << 14,
    IL2CPP_PROFILE_STATISTICAL = 1 << 15,
    IL2CPP_PROFILE_METHOD_EVENTS = 1 << 16,
    IL2CPP_PROFILE_MONITOR_EVENTS = 1 << 17,
    IL2CPP_PROFILE_IOMAP_EVENTS = 1 << 18,
    IL2CPP_PROFILE_GC_MOVES = 1 << 19,
    IL2CPP_PROFILE_FILEIO = 1 << 20
} Il2CppProfileFlags;
typedef enum Il2CppProfileFileIOKind
{
    IL2CPP_PROFILE_FILEIO_WRITE = 0,
    IL2CPP_PROFILE_FILEIO_READ
} Il2CppProfileFileIOKind;
typedef enum Il2CppGCEvent
{
    IL2CPP_GC_EVENT_START,
    IL2CPP_GC_EVENT_MARK_START,
    IL2CPP_GC_EVENT_MARK_END,
    IL2CPP_GC_EVENT_RECLAIM_START,
    IL2CPP_GC_EVENT_RECLAIM_END,
    IL2CPP_GC_EVENT_END,
    IL2CPP_GC_EVENT_PRE_STOP_WORLD,
    IL2CPP_GC_EVENT_POST_STOP_WORLD,
    IL2CPP_GC_EVENT_PRE_START_WORLD,
    IL2CPP_GC_EVENT_POST_START_WORLD
} Il2CppGCEvent;
typedef enum Il2CppStat
{
    IL2CPP_STAT_NEW_OBJECT_COUNT,
    IL2CPP_STAT_INITIALIZED_CLASS_COUNT,
    IL2CPP_STAT_METHOD_COUNT,
    IL2CPP_STAT_CLASS_STATIC_DATA_SIZE,
    IL2CPP_STAT_GENERIC_INSTANCE_COUNT,
    IL2CPP_STAT_GENERIC_CLASS_COUNT,
    IL2CPP_STAT_INFLATED_METHOD_COUNT,
    IL2CPP_STAT_INFLATED_TYPE_COUNT,
} Il2CppStat;
typedef enum Il2CppRuntimeUnhandledExceptionPolicy
{
    IL2CPP_UNHANDLED_POLICY_LEGACY,
    IL2CPP_UNHANDLED_POLICY_CURRENT
} Il2CppRuntimeUnhandledExceptionPolicy;
typedef struct Il2CppStackFrameInfo
{
    const MethodInfo* method;
} Il2CppStackFrameInfo;
typedef struct
{
    void* (*malloc_func)(size_t size);
    void* (*aligned_malloc_func)(size_t size, size_t alignment);
    void (*free_func)(void* ptr);
    void (*aligned_free_func)(void* ptr);
    void* (*calloc_func)(size_t nmemb, size_t size);
    void* (*realloc_func)(void* ptr, size_t size);
    void* (*aligned_realloc_func)(void* ptr, size_t size, size_t alignment);
} Il2CppMemoryCallbacks;
typedef uint16_t Il2CppChar;
typedef char Il2CppNativeChar;
typedef void (*il2cpp_register_object_callback)(Il2CppObject** arr, int size, void* userdata);
typedef void (*il2cpp_WorldChangedCallback)();
typedef void (*Il2CppFrameWalkFunc) (const Il2CppStackFrameInfo* info, void* user_data);
typedef void (*Il2CppProfileFunc) (Il2CppProfiler* prof);
typedef void (*Il2CppProfileMethodFunc) (Il2CppProfiler* prof, const MethodInfo* method);
typedef void (*Il2CppProfileAllocFunc) (Il2CppProfiler* prof, Il2CppObject* obj, Il2CppClass* klass);
typedef void (*Il2CppProfileGCFunc) (Il2CppProfiler* prof, Il2CppGCEvent event, int generation);
typedef void (*Il2CppProfileGCResizeFunc) (Il2CppProfiler* prof, int64_t new_size);
typedef void (*Il2CppProfileFileIOFunc) (Il2CppProfiler* prof, Il2CppProfileFileIOKind kind, int count);
typedef const Il2CppNativeChar* (*Il2CppSetFindPlugInCallback)(const Il2CppNativeChar*);
typedef void (*Il2CppLogCallback)(const char*);
typedef struct Il2CppManagedMemorySnapshot Il2CppManagedMemorySnapshot;
typedef void (*Il2CppMethodPointer)();
typedef uintptr_t il2cpp_array_size_t;
typedef struct Il2CppMetadataField
{
    uint32_t offset;
    uint32_t typeIndex;
    const char* name;
    bool isStatic;
} Il2CppMetadataField;
typedef enum Il2CppMetadataTypeFlags
{
    kNone = 0,
    kValueType = 1 << 0,
    kArray = 1 << 1,
    kArrayRankMask = 0xFFFF0000
} Il2CppMetadataTypeFlags;
typedef struct Il2CppMetadataType
{
    Il2CppMetadataTypeFlags flags;
    Il2CppMetadataField* fields;
    uint32_t fieldCount;
    uint32_t staticsSize;
    uint8_t* statics;
    uint32_t baseOrElementTypeIndex;
    char* name;
    const char* assemblyName;
    uint64_t typeInfoAddress;
    uint32_t size;
} Il2CppMetadataType;
typedef struct Il2CppMetadataSnapshot
{
    uint32_t typeCount;
    Il2CppMetadataType* types;
} Il2CppMetadataSnapshot;
typedef struct Il2CppManagedMemorySection
{
    uint64_t sectionStartAddress;
    uint32_t sectionSize;
    uint8_t* sectionBytes;
} Il2CppManagedMemorySection;
typedef struct Il2CppManagedHeap
{
    uint32_t sectionCount;
    Il2CppManagedMemorySection* sections;
} Il2CppManagedHeap;
typedef struct Il2CppStacks
{
    uint32_t stackCount;
    Il2CppManagedMemorySection* stacks;
} Il2CppStacks;
typedef struct NativeObject
{
    uint32_t gcHandleIndex;
    uint32_t size;
    uint32_t instanceId;
    uint32_t classId;
    uint32_t referencedNativeObjectIndicesCount;
    uint32_t* referencedNativeObjectIndices;
} NativeObject;
typedef struct Il2CppGCHandles
{
    uint32_t trackedObjectCount;
    uint64_t* pointersToObjects;
} Il2CppGCHandles;
typedef struct Il2CppRuntimeInformation
{
    uint32_t pointerSize;
    uint32_t objectHeaderSize;
    uint32_t arrayHeaderSize;
    uint32_t arrayBoundsOffsetInHeader;
    uint32_t arraySizeOffsetInHeader;
    uint32_t allocationGranularity;
} Il2CppRuntimeInformation;
typedef struct Il2CppManagedMemorySnapshot
{
    Il2CppManagedHeap heap;
    Il2CppStacks stacks;
    Il2CppMetadataSnapshot metadata;
    Il2CppGCHandles gcHandles;
    Il2CppRuntimeInformation runtimeInformation;
    void* additionalUserInformation;
} Il2CppManagedMemorySnapshot;
typedef enum Il2CppTypeEnum
{
    IL2CPP_TYPE_END = 0x00,
    IL2CPP_TYPE_VOID = 0x01,
    IL2CPP_TYPE_BOOLEAN = 0x02,
    IL2CPP_TYPE_CHAR = 0x03,
    IL2CPP_TYPE_I1 = 0x04,
    IL2CPP_TYPE_U1 = 0x05,
    IL2CPP_TYPE_I2 = 0x06,
    IL2CPP_TYPE_U2 = 0x07,
    IL2CPP_TYPE_I4 = 0x08,
    IL2CPP_TYPE_U4 = 0x09,
    IL2CPP_TYPE_I8 = 0x0a,
    IL2CPP_TYPE_U8 = 0x0b,
    IL2CPP_TYPE_R4 = 0x0c,
    IL2CPP_TYPE_R8 = 0x0d,
    IL2CPP_TYPE_STRING = 0x0e,
    IL2CPP_TYPE_PTR = 0x0f,
    IL2CPP_TYPE_BYREF = 0x10,
    IL2CPP_TYPE_VALUETYPE = 0x11,
    IL2CPP_TYPE_CLASS = 0x12,
    IL2CPP_TYPE_VAR = 0x13,
    IL2CPP_TYPE_ARRAY = 0x14,
    IL2CPP_TYPE_GENERICINST = 0x15,
    IL2CPP_TYPE_TYPEDBYREF = 0x16,
    IL2CPP_TYPE_I = 0x18,
    IL2CPP_TYPE_U = 0x19,
    IL2CPP_TYPE_FNPTR = 0x1b,
    IL2CPP_TYPE_OBJECT = 0x1c,
    IL2CPP_TYPE_SZARRAY = 0x1d,
    IL2CPP_TYPE_MVAR = 0x1e,
    IL2CPP_TYPE_CMOD_REQD = 0x1f,
    IL2CPP_TYPE_CMOD_OPT = 0x20,
    IL2CPP_TYPE_INTERNAL = 0x21,
    IL2CPP_TYPE_MODIFIER = 0x40,
    IL2CPP_TYPE_SENTINEL = 0x41,
    IL2CPP_TYPE_PINNED = 0x45,
    IL2CPP_TYPE_ENUM = 0x55
} Il2CppTypeEnum;
typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t InterfaceOffsetIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
typedef int32_t InteropDataIndex;
const TypeIndex kTypeIndexInvalid = -1;
const TypeDefinitionIndex kTypeDefinitionIndexInvalid = -1;
const DefaultValueDataIndex kDefaultValueIndexNull = -1;
const EventIndex kEventIndexInvalid = -1;
const FieldIndex kFieldIndexInvalid = -1;
const MethodIndex kMethodIndexInvalid = -1;
const PropertyIndex kPropertyIndexInvalid = -1;
const GenericContainerIndex kGenericContainerIndexInvalid = -1;
const GenericParameterIndex kGenericParameterIndexInvalid = -1;
const RGCTXIndex kRGCTXIndexInvalid = -1;
const StringLiteralIndex kStringLiteralIndexInvalid = -1;
const InteropDataIndex kInteropDataIndexInvalid = -1;
typedef uint32_t EncodedMethodIndex;
typedef enum Il2CppMetadataUsage
{
    kIl2CppMetadataUsageInvalid,
    kIl2CppMetadataUsageTypeInfo,
    kIl2CppMetadataUsageIl2CppType,
    kIl2CppMetadataUsageMethodDef,
    kIl2CppMetadataUsageFieldInfo,
    kIl2CppMetadataUsageStringLiteral,
    kIl2CppMetadataUsageMethodRef,
} Il2CppMetadataUsage;
static inline Il2CppMetadataUsage GetEncodedIndexType(EncodedMethodIndex index)
{
    return (Il2CppMetadataUsage)((index & 0xE0000000) >> 29);
}
static inline uint32_t GetDecodedMethodIndex(EncodedMethodIndex index)
{
    return index & 0x1FFFFFFFU;
}
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppTypeDefinitionMetadata Il2CppTypeDefinitionMetadata;
typedef union Il2CppRGCTXDefinitionData
{
    int32_t rgctxDataDummy;
    MethodIndex methodIndex;
    TypeIndex typeIndex;
} Il2CppRGCTXDefinitionData;
typedef enum Il2CppRGCTXDataType
{
    IL2CPP_RGCTX_DATA_INVALID,
    IL2CPP_RGCTX_DATA_TYPE,
    IL2CPP_RGCTX_DATA_CLASS,
    IL2CPP_RGCTX_DATA_METHOD,
    IL2CPP_RGCTX_DATA_ARRAY,
} Il2CppRGCTXDataType;
typedef struct Il2CppRGCTXDefinition
{
    Il2CppRGCTXDataType type;
    Il2CppRGCTXDefinitionData data;
} Il2CppRGCTXDefinition;
typedef struct Il2CppInterfaceOffsetPair
{
    TypeIndex interfaceTypeIndex;
    int32_t offset;
} Il2CppInterfaceOffsetPair;
typedef struct Il2CppTypeDefinition
{
    StringIndex nameIndex;
    StringIndex namespaceIndex;
    CustomAttributeIndex customAttributeIndex;
    TypeIndex byvalTypeIndex;
    TypeIndex byrefTypeIndex;
    TypeIndex declaringTypeIndex;
    TypeIndex parentIndex;
    TypeIndex elementTypeIndex;
    RGCTXIndex rgctxStartIndex;
    int32_t rgctxCount;
    GenericContainerIndex genericContainerIndex;
    uint32_t flags;
    FieldIndex fieldStart;
    MethodIndex methodStart;
    EventIndex eventStart;
    PropertyIndex propertyStart;
    NestedTypeIndex nestedTypesStart;
    InterfacesIndex interfacesStart;
    VTableIndex vtableStart;
    InterfacesIndex interfaceOffsetsStart;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint32_t bitfield;
    uint32_t token;
} Il2CppTypeDefinition;
typedef struct Il2CppFieldDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    CustomAttributeIndex customAttributeIndex;
    uint32_t token;
} Il2CppFieldDefinition;
typedef struct Il2CppFieldDefaultValue
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppFieldDefaultValue;
typedef struct Il2CppFieldMarshaledSize
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    int32_t size;
} Il2CppFieldMarshaledSize;
typedef struct Il2CppFieldRef
{
    TypeIndex typeIndex;
    FieldIndex fieldIndex;
} Il2CppFieldRef;
typedef struct Il2CppParameterDefinition
{
    StringIndex nameIndex;
    uint32_t token;
    CustomAttributeIndex customAttributeIndex;
    TypeIndex typeIndex;
} Il2CppParameterDefinition;
typedef struct Il2CppParameterDefaultValue
{
    ParameterIndex parameterIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppParameterDefaultValue;
typedef struct Il2CppMethodDefinition
{
    StringIndex nameIndex;
    TypeDefinitionIndex declaringType;
    TypeIndex returnType;
    ParameterIndex parameterStart;
    CustomAttributeIndex customAttributeIndex;
    GenericContainerIndex genericContainerIndex;
    MethodIndex methodIndex;
    MethodIndex invokerIndex;
    MethodIndex reversePInvokeWrapperIndex;
    RGCTXIndex rgctxStartIndex;
    int32_t rgctxCount;
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint16_t parameterCount;
} Il2CppMethodDefinition;
typedef struct Il2CppEventDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    MethodIndex add;
    MethodIndex remove;
    MethodIndex raise;
    CustomAttributeIndex customAttributeIndex;
    uint32_t token;
} Il2CppEventDefinition;
typedef struct Il2CppPropertyDefinition
{
    StringIndex nameIndex;
    MethodIndex get;
    MethodIndex set;
    uint32_t attrs;
    CustomAttributeIndex customAttributeIndex;
    uint32_t token;
} Il2CppPropertyDefinition;
typedef struct Il2CppMethodSpec
{
    MethodIndex methodDefinitionIndex;
    GenericInstIndex classIndexIndex;
    GenericInstIndex methodIndexIndex;
} Il2CppMethodSpec;
typedef struct Il2CppStringLiteral
{
    uint32_t length;
    StringLiteralIndex dataIndex;
} Il2CppStringLiteral;
typedef struct Il2CppGenericMethodIndices
{
    MethodIndex methodIndex;
    MethodIndex invokerIndex;
} Il2CppGenericMethodIndices;
typedef struct Il2CppGenericMethodFunctionsDefinitions
{
    GenericMethodIndex genericMethodIndex;
    Il2CppGenericMethodIndices indices;
} Il2CppGenericMethodFunctionsDefinitions;
const int kPublicKeyByteLength = 8;
typedef struct Il2CppAssemblyName
{
    StringIndex nameIndex;
    StringIndex cultureIndex;
    StringIndex hashValueIndex;
    StringIndex publicKeyIndex;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t publicKeyToken[8];
} Il2CppAssemblyName;
typedef struct Il2CppImageDefinition
{
    StringIndex nameIndex;
    AssemblyIndex assemblyIndex;
    TypeDefinitionIndex typeStart;
    uint32_t typeCount;
    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;
    MethodIndex entryPointIndex;
    uint32_t token;
} Il2CppImageDefinition;
typedef struct Il2CppAssembly
{
    ImageIndex imageIndex;
    CustomAttributeIndex customAttributeIndex;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    Il2CppAssemblyName aname;
} Il2CppAssembly;
typedef struct Il2CppMetadataUsageList
{
    uint32_t start;
    uint32_t count;
} Il2CppMetadataUsageList;
typedef struct Il2CppMetadataUsagePair
{
    uint32_t destinationIndex;
    uint32_t encodedSourceIndex;
} Il2CppMetadataUsagePair;
typedef struct Il2CppCustomAttributeTypeRange
{
    int32_t start;
    int32_t count;
} Il2CppCustomAttributeTypeRange;
typedef struct Il2CppRange
{
    int32_t start;
    int32_t length;
} Il2CppRange;
typedef struct Il2CppWindowsRuntimeTypeNamePair
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
} Il2CppWindowsRuntimeTypeNamePair;
#pragma pack(push, p1,4)
typedef struct Il2CppGlobalMetadataHeader
{
    int32_t sanity;
    int32_t version;
    int32_t stringLiteralOffset;
    int32_t stringLiteralCount;
    int32_t stringLiteralDataOffset;
    int32_t stringLiteralDataCount;
    int32_t stringOffset;
    int32_t stringCount;
    int32_t eventsOffset;
    int32_t eventsCount;
    int32_t propertiesOffset;
    int32_t propertiesCount;
    int32_t methodsOffset;
    int32_t methodsCount;
    int32_t parameterDefaultValuesOffset;
    int32_t parameterDefaultValuesCount;
    int32_t fieldDefaultValuesOffset;
    int32_t fieldDefaultValuesCount;
    int32_t fieldAndParameterDefaultValueDataOffset;
    int32_t fieldAndParameterDefaultValueDataCount;
    int32_t fieldMarshaledSizesOffset;
    int32_t fieldMarshaledSizesCount;
    int32_t parametersOffset;
    int32_t parametersCount;
    int32_t fieldsOffset;
    int32_t fieldsCount;
    int32_t genericParametersOffset;
    int32_t genericParametersCount;
    int32_t genericParameterConstraintsOffset;
    int32_t genericParameterConstraintsCount;
    int32_t genericContainersOffset;
    int32_t genericContainersCount;
    int32_t nestedTypesOffset;
    int32_t nestedTypesCount;
    int32_t interfacesOffset;
    int32_t interfacesCount;
    int32_t vtableMethodsOffset;
    int32_t vtableMethodsCount;
    int32_t interfaceOffsetsOffset;
    int32_t interfaceOffsetsCount;
    int32_t typeDefinitionsOffset;
    int32_t typeDefinitionsCount;
    int32_t rgctxEntriesOffset;
    int32_t rgctxEntriesCount;
    int32_t imagesOffset;
    int32_t imagesCount;
    int32_t assembliesOffset;
    int32_t assembliesCount;
    int32_t metadataUsageListsOffset;
    int32_t metadataUsageListsCount;
    int32_t metadataUsagePairsOffset;
    int32_t metadataUsagePairsCount;
    int32_t fieldRefsOffset;
    int32_t fieldRefsCount;
    int32_t referencedAssembliesOffset;
    int32_t referencedAssembliesCount;
    int32_t attributesInfoOffset;
    int32_t attributesInfoCount;
    int32_t attributeTypesOffset;
    int32_t attributeTypesCount;
    int32_t unresolvedVirtualCallParameterTypesOffset;
    int32_t unresolvedVirtualCallParameterTypesCount;
    int32_t unresolvedVirtualCallParameterRangesOffset;
    int32_t unresolvedVirtualCallParameterRangesCount;
    int32_t windowsRuntimeTypeNamesOffset;
    int32_t windowsRuntimeTypeNamesSize;
    int32_t exportedTypeDefinitionsOffset;
    int32_t exportedTypeDefinitionsCount;
} Il2CppGlobalMetadataHeader;
#pragma pack(pop, p1)
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppArrayType
{
    const Il2CppType* etype;
    uint8_t rank;
    uint8_t numsizes;
    uint8_t numlobounds;
    int* sizes;
    int* lobounds;
} Il2CppArrayType;
typedef struct Il2CppGenericInst
{
    uint32_t type_argc;
    const Il2CppType** type_argv;
} Il2CppGenericInst;
typedef struct Il2CppGenericContext
{
    const Il2CppGenericInst* class_inst;
    const Il2CppGenericInst* method_inst;
} Il2CppGenericContext;
typedef struct Il2CppGenericParameter
{
    GenericContainerIndex ownerIndex;
    StringIndex nameIndex;
    GenericParameterConstraintIndex constraintsStart;
    int16_t constraintsCount;
    uint16_t num;
    uint16_t flags;
} Il2CppGenericParameter;
typedef struct Il2CppGenericContainer
{
    int32_t ownerIndex;
    int32_t type_argc;
    int32_t is_method;
    GenericParameterIndex genericParameterStart;
} Il2CppGenericContainer;
typedef struct Il2CppGenericClass
{
    TypeDefinitionIndex typeDefinitionIndex;
    Il2CppGenericContext context;
    Il2CppClass* cached_class;
} Il2CppGenericClass;
typedef struct Il2CppGenericMethod
{
    const MethodInfo* methodDefinition;
    Il2CppGenericContext context;
} Il2CppGenericMethod;
typedef struct Il2CppType
{
    union
    {
        void* dummy;
        TypeDefinitionIndex klassIndex;
        const Il2CppType* type;
        Il2CppArrayType* array;
        GenericParameterIndex genericParameterIndex;
        Il2CppGenericClass* generic_class;
    } data;
    unsigned int attrs : 16;
    Il2CppTypeEnum type : 8;
    unsigned int num_mods : 6;
    unsigned int byref : 1;
    unsigned int pinned : 1;
} Il2CppType;
typedef enum
{
    IL2CPP_CALL_DEFAULT,
    IL2CPP_CALL_C,
    IL2CPP_CALL_STDCALL,
    IL2CPP_CALL_THISCALL,
    IL2CPP_CALL_FASTCALL,
    IL2CPP_CALL_VARARG
} Il2CppCallConvention;
typedef enum Il2CppCharSet
{
    CHARSET_ANSI,
    CHARSET_UNICODE
} Il2CppCharSet;
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppGuid Il2CppGuid;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppAppDomain Il2CppAppDomain;
typedef struct Il2CppAppDomainSetup Il2CppAppDomainSetup;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppAppContext Il2CppAppContext;
typedef struct Il2CppNameToTypeDefinitionIndexHashTable Il2CppNameToTypeDefinitionIndexHashTable;
typedef struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const MethodInfo* method;
} VirtualInvokeData;
typedef enum Il2CppTypeNameFormat
{
    IL2CPP_TYPE_NAME_FORMAT_IL,
    IL2CPP_TYPE_NAME_FORMAT_REFLECTION,
    IL2CPP_TYPE_NAME_FORMAT_FULL_NAME,
    IL2CPP_TYPE_NAME_FORMAT_ASSEMBLY_QUALIFIED
} Il2CppTypeNameFormat;
extern bool g_il2cpp_is_fully_initialized;
typedef struct
{
    Il2CppImage* corlib;
    Il2CppClass* object_class;
    Il2CppClass* byte_class;
    Il2CppClass* void_class;
    Il2CppClass* boolean_class;
    Il2CppClass* sbyte_class;
    Il2CppClass* int16_class;
    Il2CppClass* uint16_class;
    Il2CppClass* int32_class;
    Il2CppClass* uint32_class;
    Il2CppClass* int_class;
    Il2CppClass* uint_class;
    Il2CppClass* int64_class;
    Il2CppClass* uint64_class;
    Il2CppClass* single_class;
    Il2CppClass* double_class;
    Il2CppClass* char_class;
    Il2CppClass* string_class;
    Il2CppClass* enum_class;
    Il2CppClass* array_class;
    Il2CppClass* delegate_class;
    Il2CppClass* multicastdelegate_class;
    Il2CppClass* asyncresult_class;
    Il2CppClass* manualresetevent_class;
    Il2CppClass* typehandle_class;
    Il2CppClass* fieldhandle_class;
    Il2CppClass* methodhandle_class;
    Il2CppClass* systemtype_class;
    Il2CppClass* monotype_class;
    Il2CppClass* exception_class;
    Il2CppClass* threadabortexception_class;
    Il2CppClass* thread_class;
    Il2CppClass* internal_thread_class;
    Il2CppClass* appdomain_class;
    Il2CppClass* appdomain_setup_class;
    Il2CppClass* field_info_class;
    Il2CppClass* method_info_class;
    Il2CppClass* property_info_class;
    Il2CppClass* event_info_class;
    Il2CppClass* mono_event_info_class;
    Il2CppClass* stringbuilder_class;
    Il2CppClass* stack_frame_class;
    Il2CppClass* stack_trace_class;
    Il2CppClass* marshal_class;
    Il2CppClass* typed_reference_class;
    Il2CppClass* marshalbyrefobject_class;
    Il2CppClass* generic_ilist_class;
    Il2CppClass* generic_icollection_class;
    Il2CppClass* generic_ienumerable_class;
    Il2CppClass* generic_ireadonlylist_class;
    Il2CppClass* generic_ireadonlycollection_class;
    Il2CppClass* runtimetype_class;
    Il2CppClass* generic_nullable_class;
    Il2CppClass* il2cpp_com_object_class;
    Il2CppClass* customattribute_data_class;
    Il2CppClass* version;
    Il2CppClass* culture_info;
    Il2CppClass* async_call_class;
    Il2CppClass* assembly_class;
    Il2CppClass* mono_assembly_class;
    Il2CppClass* assembly_name_class;
    Il2CppClass* mono_field_class;
    Il2CppClass* mono_method_class;
    Il2CppClass* mono_method_info_class;
    Il2CppClass* mono_property_info_class;
    Il2CppClass* parameter_info_class;
    Il2CppClass* mono_parameter_info_class;
    Il2CppClass* module_class;
    Il2CppClass* pointer_class;
    Il2CppClass* system_exception_class;
    Il2CppClass* argument_exception_class;
    Il2CppClass* wait_handle_class;
    Il2CppClass* safe_handle_class;
    Il2CppClass* sort_key_class;
    Il2CppClass* dbnull_class;
    Il2CppClass* error_wrapper_class;
    Il2CppClass* missing_class;
    Il2CppClass* value_type_class;
    Il2CppClass* threadpool_wait_callback_class;
    MethodInfo* threadpool_perform_wait_callback_method;
    Il2CppClass* mono_method_message_class;
    Il2CppClass* ireference_class;
    Il2CppClass* ikey_value_pair_class;
    Il2CppClass* key_value_pair_class;
    Il2CppClass* windows_foundation_uri_class;
    Il2CppClass* windows_foundation_iuri_runtime_class_class;
    Il2CppClass* system_uri_class;
} Il2CppDefaults;
extern Il2CppDefaults il2cpp_defaults;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct Il2CppObject Il2CppObject;
typedef struct MemberInfo MemberInfo;
typedef struct CustomAttributesCache
{
    int count;
    Il2CppObject** attributes;
} CustomAttributesCache;
typedef struct CustomAttributeTypeCache
{
    int count;
    Il2CppClass** attributeTypes;
} CustomAttributeTypeCache;
typedef void (*CustomAttributesCacheGenerator)(CustomAttributesCache*);
const int THREAD_STATIC_FIELD_OFFSET = -1;
typedef struct FieldInfo
{
    const char* name;
    const Il2CppType* type;
    Il2CppClass* parent;
    int32_t offset;
    CustomAttributeIndex customAttributeIndex;
    uint32_t token;
} FieldInfo;
typedef struct PropertyInfo
{
    Il2CppClass* parent;
    const char* name;
    const MethodInfo* get;
    const MethodInfo* set;
    uint32_t attrs;
    CustomAttributeIndex customAttributeIndex;
    uint32_t token;
} PropertyInfo;
typedef struct EventInfo
{
    const char* name;
    const Il2CppType* eventType;
    Il2CppClass* parent;
    const MethodInfo* add;
    const MethodInfo* remove;
    const MethodInfo* raise;
    CustomAttributeIndex customAttributeIndex;
    uint32_t token;
} EventInfo;
typedef struct ParameterInfo
{
    const char* name;
    int32_t position;
    uint32_t token;
    CustomAttributeIndex customAttributeIndex;
    const Il2CppType* parameter_type;
} ParameterInfo;
typedef void* (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**);
typedef union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
} Il2CppRGCTXData;
typedef struct MethodInfo
{
    Il2CppMethodPointer methodPointer;
    InvokerMethod invoker_method;
    const char* name;
    Il2CppClass* declaring_type;
    const Il2CppType* return_type;
    const ParameterInfo* parameters;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const Il2CppMethodDefinition* methodDefinition;
    };
    union
    {
        const Il2CppGenericMethod* genericMethod;
        const Il2CppGenericContainer* genericContainer;
    };
    CustomAttributeIndex customAttributeIndex;
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint8_t parameters_count;
    uint8_t is_generic : 1;
    uint8_t is_inflated : 1;
} MethodInfo;
typedef struct Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int32_t offset;
} Il2CppRuntimeInterfaceOffsetPair;
typedef void (*PInvokeMarshalToNativeFunc)(void* managedStructure, void* marshaledStructure);
typedef void (*PInvokeMarshalFromNativeFunc)(void* marshaledStructure, void* managedStructure);
typedef void (*PInvokeMarshalCleanupFunc)(void* marshaledStructure);
typedef struct Il2CppIUnknown* (*CreateCCWFunc)(Il2CppObject* obj);
typedef struct Il2CppInteropData
{
    Il2CppMethodPointer delegatePInvokeWrapperFunction;
    PInvokeMarshalToNativeFunc pinvokeMarshalToNativeFunction;
    PInvokeMarshalFromNativeFunc pinvokeMarshalFromNativeFunction;
    PInvokeMarshalCleanupFunc pinvokeMarshalCleanupFunction;
    CreateCCWFunc createCCWFunction;
    const Il2CppGuid* guid;
    const Il2CppType* type;
} Il2CppInteropData;
typedef struct Il2CppClass
{
    const Il2CppImage* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    const Il2CppType* byval_arg;
    const Il2CppType* this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    Il2CppGenericClass* generic_class;
    const Il2CppTypeDefinition* typeDefinition;
    const Il2CppInteropData* interopData;
    FieldInfo* fields;
    const EventInfo* events;
    const PropertyInfo* properties;
    const MethodInfo** methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct Il2CppClass** typeHierarchy;
    uint32_t cctor_started;
    uint32_t cctor_finished;
    __declspec(align(8)) uint64_t cctor_thread;
    GenericContainerIndex genericContainerIndex;
    CustomAttributeIndex customAttributeIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t packingSize;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import_or_windows_runtime : 1;
    uint8_t is_vtable_initialized : 1;
    VirtualInvokeData vtable[32];
} Il2CppClass;

typedef struct Il2CppClass_0 {
    const Il2CppImage* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    const Il2CppType* byval_arg;
    const Il2CppType* this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    Il2CppGenericClass* generic_class;
    const Il2CppTypeDefinition* typeDefinition;
    const Il2CppInteropData* interopData;
    FieldInfo* fields;
    const EventInfo* events;
    const PropertyInfo* properties;
    const MethodInfo** methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
} Il2CppClass_0;

typedef struct Il2CppClass_1 {
    struct Il2CppClass** typeHierarchy;
    uint32_t cctor_started;
    uint32_t cctor_finished;
#ifdef IS_32BIT
    uint32_t cctor_thread__padding;
    uint32_t cctor_thread;
    uint32_t cctor_thread__hi;
#else
    __declspec(align(8)) uint64_t cctor_thread;
#endif
    GenericContainerIndex genericContainerIndex;
    CustomAttributeIndex customAttributeIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t packingSize;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import_or_windows_runtime : 1;
    uint8_t is_vtable_initialized : 1;
} Il2CppClass_1;

typedef struct __declspec(align(8)) Il2CppClass_Merged {
    struct Il2CppClass_0 _0;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct Il2CppClass_1 _1;
    VirtualInvokeData vtable[32];
} Il2CppClass_Merged;

typedef struct Il2CppTypeDefinitionSizes
{
    uint32_t instance_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
} Il2CppTypeDefinitionSizes;
typedef struct Il2CppDomain
{
    Il2CppAppDomain* domain;
    Il2CppAppDomainSetup* setup;
    Il2CppAppContext* default_context;
    const char* friendly_name;
    uint32_t domain_id;
    volatile int threadpool_jobs;
} Il2CppDomain;
typedef struct Il2CppImage
{
    const char* name;
    const char* nameNoExt;
    AssemblyIndex assemblyIndex;
    TypeDefinitionIndex typeStart;
    uint32_t typeCount;
    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;
    MethodIndex entryPointIndex;
    Il2CppNameToTypeDefinitionIndexHashTable* nameToClassHashTable;
    uint32_t token;
} Il2CppImage;
typedef struct Il2CppCodeGenOptions
{
    bool enablePrimitiveValueTypeGenericSharing;
} Il2CppCodeGenOptions;
typedef struct Il2CppCodeRegistration
{
    uint32_t methodPointersCount;
    const Il2CppMethodPointer* methodPointers;
    uint32_t reversePInvokeWrapperCount;
    const Il2CppMethodPointer* reversePInvokeWrappers;
    uint32_t genericMethodPointersCount;
    const Il2CppMethodPointer* genericMethodPointers;
    uint32_t invokerPointersCount;
    const InvokerMethod* invokerPointers;
    CustomAttributeIndex customAttributeCount;
    const CustomAttributesCacheGenerator* customAttributeGenerators;
    uint32_t unresolvedVirtualCallCount;
    const Il2CppMethodPointer* unresolvedVirtualCallPointers;
    uint32_t interopDataCount;
    Il2CppInteropData* interopData;
} Il2CppCodeRegistration;
typedef struct Il2CppMetadataRegistration
{
    int32_t genericClassesCount;
    Il2CppGenericClass* const* genericClasses;
    int32_t genericInstsCount;
    const Il2CppGenericInst* const* genericInsts;
    int32_t genericMethodTableCount;
    const Il2CppGenericMethodFunctionsDefinitions* genericMethodTable;
    int32_t typesCount;
    const Il2CppType* const* types;
    int32_t methodSpecsCount;
    const Il2CppMethodSpec* methodSpecs;
    FieldIndex fieldOffsetsCount;
    const int32_t** fieldOffsets;
    TypeDefinitionIndex typeDefinitionsSizesCount;
    const Il2CppTypeDefinitionSizes** typeDefinitionsSizes;
    const size_t metadataUsagesCount;
    void** const* metadataUsages;
} Il2CppMetadataRegistration;
typedef struct Il2CppRuntimeStats
{
    uint64_t new_object_count;
    uint64_t initialized_class_count;
    uint64_t method_count;
    uint64_t class_static_data_size;
    uint64_t generic_instance_count;
    uint64_t generic_class_count;
    uint64_t inflated_method_count;
    uint64_t inflated_type_count;
    bool enabled;
} Il2CppRuntimeStats;
extern Il2CppRuntimeStats il2cpp_runtime_stats;
typedef struct Il2CppPerfCounters
{
    uint32_t jit_methods;
    uint32_t jit_bytes;
    uint32_t jit_time;
    uint32_t jit_failures;
    uint32_t exceptions_thrown;
    uint32_t exceptions_filters;
    uint32_t exceptions_finallys;
    uint32_t exceptions_depth;
    uint32_t aspnet_requests_queued;
    uint32_t aspnet_requests;
    uint32_t gc_collections0;
    uint32_t gc_collections1;
    uint32_t gc_collections2;
    uint32_t gc_promotions0;
    uint32_t gc_promotions1;
    uint32_t gc_promotion_finalizers;
    uint32_t gc_gen0size;
    uint32_t gc_gen1size;
    uint32_t gc_gen2size;
    uint32_t gc_lossize;
    uint32_t gc_fin_survivors;
    uint32_t gc_num_handles;
    uint32_t gc_allocated;
    uint32_t gc_induced;
    uint32_t gc_time;
    uint32_t gc_total_bytes;
    uint32_t gc_committed_bytes;
    uint32_t gc_reserved_bytes;
    uint32_t gc_num_pinned;
    uint32_t gc_sync_blocks;
    uint32_t remoting_calls;
    uint32_t remoting_channels;
    uint32_t remoting_proxies;
    uint32_t remoting_classes;
    uint32_t remoting_objects;
    uint32_t remoting_contexts;
    uint32_t loader_classes;
    uint32_t loader_total_classes;
    uint32_t loader_appdomains;
    uint32_t loader_total_appdomains;
    uint32_t loader_assemblies;
    uint32_t loader_total_assemblies;
    uint32_t loader_failures;
    uint32_t loader_bytes;
    uint32_t loader_appdomains_uloaded;
    uint32_t thread_contentions;
    uint32_t thread_queue_len;
    uint32_t thread_queue_max;
    uint32_t thread_num_logical;
    uint32_t thread_num_physical;
    uint32_t thread_cur_recognized;
    uint32_t thread_num_recognized;
    uint32_t interop_num_ccw;
    uint32_t interop_num_stubs;
    uint32_t interop_num_marshals;
    uint32_t security_num_checks;
    uint32_t security_num_link_checks;
    uint32_t security_time;
    uint32_t security_depth;
    uint32_t unused;
    uint64_t threadpool_workitems;
    uint64_t threadpool_ioworkitems;
    unsigned int threadpool_threads;
    unsigned int threadpool_iothreads;
} Il2CppPerfCounters;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct FieldInfo FieldInfo;
typedef struct EventInfo EventInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppAsyncCall Il2CppAsyncCall;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppWaitHandle Il2CppWaitHandle;
typedef struct MonitorData MonitorData;
typedef struct FastMutex FastMutex;
typedef struct Thread Thread;
typedef struct Il2CppReflectionAssembly Il2CppReflectionAssembly;
typedef struct Il2CppObject
{
    Il2CppClass* klass;
    MonitorData* monitor;
} Il2CppObject;
typedef int32_t il2cpp_array_lower_bound_t;
typedef struct Il2CppArrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
} Il2CppArrayBounds;
typedef struct Il2CppArray
{
    Il2CppObject Object;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
} Il2CppArray;
typedef struct Il2CppArraySize
{
    Il2CppArray Array;
    __declspec(align(8)) void* vector;
} Il2CppArraySize;
typedef struct Il2CppString
{
    Il2CppObject object;
    int32_t length;
    Il2CppChar chars[32];
} Il2CppString;
typedef struct Il2CppReflectionType
{
    Il2CppObject object;
    const Il2CppType* type;
} Il2CppReflectionType;
typedef struct Il2CppReflectionRuntimeType
{
    Il2CppReflectionType type;
    Il2CppObject* type_info;
    Il2CppObject* genericCache;
    Il2CppObject* serializationCtor;
} Il2CppReflectionRuntimeType;
typedef struct Il2CppReflectionMonoType
{
    Il2CppReflectionRuntimeType type;
} Il2CppReflectionMonoType;
typedef struct Il2CppReflectionEvent
{
    Il2CppObject object;
    Il2CppObject* cached_add_event;
} Il2CppReflectionEvent;
typedef struct Il2CppReflectionMonoEvent
{
    Il2CppReflectionEvent event;
    Il2CppReflectionType* reflectedType;
    const EventInfo* eventInfo;
} Il2CppReflectionMonoEvent;
typedef struct Il2CppReflectionMonoEventInfo
{
    Il2CppReflectionType* declaringType;
    Il2CppReflectionType* reflectedType;
    Il2CppString* name;
    Il2CppReflectionMethod* addMethod;
    Il2CppReflectionMethod* removeMethod;
    Il2CppReflectionMethod* raiseMethod;
    uint32_t eventAttributes;
    Il2CppArray* otherMethods;
} Il2CppReflectionMonoEventInfo;
typedef struct Il2CppReflectionField
{
    Il2CppObject object;
    Il2CppClass* klass;
    FieldInfo* field;
    Il2CppString* name;
    Il2CppReflectionType* type;
    uint32_t attrs;
} Il2CppReflectionField;
typedef struct Il2CppReflectionProperty
{
    Il2CppObject object;
    Il2CppClass* klass;
    const PropertyInfo* property;
} Il2CppReflectionProperty;
typedef struct Il2CppReflectionMethod
{
    Il2CppObject object;
    const MethodInfo* method;
    Il2CppString* name;
    Il2CppReflectionType* reftype;
} Il2CppReflectionMethod;
typedef struct Il2CppReflectionGenericMethod
{
    Il2CppReflectionMethod base;
} Il2CppReflectionGenericMethod;
typedef struct Il2CppMethodInfo
{
    Il2CppReflectionType* parent;
    Il2CppReflectionType* ret;
    uint32_t attrs;
    uint32_t implattrs;
    uint32_t callconv;
} Il2CppMethodInfo;
typedef struct Il2CppPropertyInfo
{
    Il2CppReflectionType* parent;
    Il2CppReflectionType* declaringType;
    Il2CppString* name;
    Il2CppReflectionMethod* get;
    Il2CppReflectionMethod* set;
    uint32_t attrs;
} Il2CppPropertyInfo;
typedef struct Il2CppReflectionParameter
{
    Il2CppObject object;
    Il2CppReflectionType* ClassImpl;
    Il2CppObject* DefaultValueImpl;
    Il2CppObject* MemberImpl;
    Il2CppString* NameImpl;
    int32_t PositionImpl;
    uint32_t AttrsImpl;
    Il2CppObject* MarshalAsImpl;
} Il2CppReflectionParameter;
typedef struct Il2CppReflectionModule
{
    Il2CppObject obj;
    const Il2CppImage* image;
    Il2CppReflectionAssembly* assembly;
    Il2CppString* fqname;
    Il2CppString* name;
    Il2CppString* scopename;
    bool is_resource;
    uint32_t token;
} Il2CppReflectionModule;
typedef struct Il2CppReflectionAssemblyName
{
    Il2CppObject obj;
    Il2CppString* name;
    Il2CppString* codebase;
    int32_t major, minor, build, revision;
    Il2CppObject* cultureInfo;
    uint32_t flags;
    uint32_t hashalg;
    Il2CppObject* keypair;
    Il2CppArray* publicKey;
    Il2CppArray* keyToken;
    uint32_t versioncompat;
    Il2CppObject* version;
    uint32_t processor_architecture;
    uint32_t contentType;
} Il2CppReflectionAssemblyName;
typedef struct Il2CppReflectionAssembly
{
    Il2CppObject object;
    const Il2CppAssembly* assembly;
    Il2CppObject* resolve_event_holder;
    Il2CppObject* evidence;
    Il2CppObject* minimum;
    Il2CppObject* optional;
    Il2CppObject* refuse;
    Il2CppObject* granted;
    Il2CppObject* denied;
    bool from_byte_array;
    Il2CppString* name;
} Il2CppReflectionAssembly;
typedef struct Il2CppReflectionMarshal
{
    Il2CppObject object;
    int32_t count;
    int32_t type;
    int32_t eltype;
    Il2CppString* guid;
    Il2CppString* mcookie;
    Il2CppString* marshaltype;
    Il2CppObject* marshaltyperef;
    int32_t param_num;
    bool has_size;
} Il2CppReflectionMarshal;
typedef struct Il2CppReflectionPointer
{
    Il2CppObject object;
    void* data;
    Il2CppReflectionType* type;
} Il2CppReflectionPointer;
typedef struct Il2CppInternalThread
{
    Il2CppObject obj;
    int lock_thread_id;
    Thread* handle;
    void* native_handle;
    Il2CppArray* cached_culture_info;
    Il2CppChar* name;
    int name_len;
    uint32_t state;
    Il2CppObject* abort_exc;
    int abort_state_handle;
    uint64_t tid;
    void* stack_ptr;
    void** static_data;
    void* runtime_thread_info;
    Il2CppObject* current_appcontext;
    Il2CppObject* root_domain_thread;
    Il2CppArray* _serialized_principal;
    int _serialized_principal_version;
    void* appdomain_refs;
    int32_t interruption_requested;
    FastMutex* synch_cs;
    bool threadpool_thread;
    bool thread_interrupt_requested;
    int stack_size;
    uint8_t apartment_state;
    int critical_region_level;
    int managed_id;
    uint32_t small_id;
    void* manage_callback;
    void* interrupt_on_stop;
    void* flags;
    void* thread_pinning_ref;
    void* abort_protected_block_count;
    int32_t priority;
    void* owned_mutexes;
    void* suspended;
    int32_t self_suspended;
    size_t thread_state;
    size_t unused2;
    void* last;
} Il2CppInternalThread;
typedef struct Il2CppIOSelectorJob
{
    Il2CppObject object;
    int32_t operation;
    Il2CppObject* callback;
    Il2CppObject* state;
} Il2CppIOSelectorJob;
typedef enum
{
    Il2Cpp_CallType_Sync = 0,
    Il2Cpp_CallType_BeginInvoke = 1,
    Il2Cpp_CallType_EndInvoke = 2,
    Il2Cpp_CallType_OneWay = 3
} Il2CppCallType;
typedef struct Il2CppMethodMessage
{
    Il2CppObject obj;
    Il2CppReflectionMethod* method;
    Il2CppArray* args;
    Il2CppArray* names;
    Il2CppArray* arg_types;
    Il2CppObject* ctx;
    Il2CppObject* rval;
    Il2CppObject* exc;
    Il2CppAsyncResult* async_result;
    uint32_t call_type;
} Il2CppMethodMessage;
typedef struct Il2CppAppDomainSetup
{
    Il2CppObject object;
    Il2CppString* application_base;
    Il2CppString* application_name;
    Il2CppString* cache_path;
    Il2CppString* configuration_file;
    Il2CppString* dynamic_base;
    Il2CppString* license_file;
    Il2CppString* private_bin_path;
    Il2CppString* private_bin_path_probe;
    Il2CppString* shadow_copy_directories;
    Il2CppString* shadow_copy_files;
    uint8_t publisher_policy;
    uint8_t path_changed;
    int loader_optimization;
    uint8_t disallow_binding_redirects;
    uint8_t disallow_code_downloads;
    Il2CppObject* activation_arguments;
    Il2CppObject* domain_initializer;
    Il2CppObject* application_trust;
    Il2CppArray* domain_initializer_args;
    uint8_t disallow_appbase_probe;
    Il2CppArray* configuration_bytes;
    Il2CppArray* serialized_non_primitives;
} Il2CppAppDomainSetup;
typedef struct Il2CppThread
{
    Il2CppObject obj;
    Il2CppInternalThread* internal_thread;
    Il2CppObject* start_obj;
    Il2CppException* pending_exception;
    Il2CppObject* principal;
    int32_t principal_version;
    Il2CppDelegate* delegate;
    Il2CppObject* executionContext;
    bool executionContextBelongsToOuterScope;
} Il2CppThread;
typedef struct Il2CppException
{
    Il2CppObject Object;
    Il2CppString* className;
    Il2CppString* message;
    Il2CppObject* _data;
    Il2CppException* inner_ex;
    Il2CppString* _helpURL;
    Il2CppArray* trace_ips;
    Il2CppString* stack_trace;
    Il2CppString* remote_stack_trace;
    int remote_stack_index;
    Il2CppObject* _dynamicMethods;
    il2cpp_hresult_t hresult;
    Il2CppString* source;
    Il2CppObject* safeSerializationManager;
    Il2CppArray* captured_traces;
    Il2CppArray* native_trace_ips;
} Il2CppException;
typedef struct Il2CppSystemException
{
    Il2CppException base;
} Il2CppSystemException;
typedef struct Il2CppArgumentException
{
    Il2CppException base;
    Il2CppString* argName;
} Il2CppArgumentException;
typedef struct Il2CppTypedRef
{
    Il2CppType* type;
    void* value;
    Il2CppClass* klass;
} Il2CppTypedRef;
typedef struct Il2CppDelegate
{
    Il2CppObject object;
    Il2CppMethodPointer method_ptr;
    InvokerMethod invoke_impl;
    Il2CppObject* target;
    const MethodInfo* method;
    void* delegate_trampoline;
    intptr_t extraArg;
    uint8_t** method_code;
    Il2CppReflectionMethod* method_info;
    Il2CppReflectionMethod* original_method_info;
    Il2CppObject* data;
    bool method_is_virtual;
} Il2CppDelegate;
typedef struct Il2CppMulticastDelegate
{
    Il2CppDelegate delegate;
    Il2CppArray* delegates;
} Il2CppMulticastDelegate;
typedef struct Il2CppMarshalByRefObject
{
    Il2CppObject obj;
    Il2CppObject* identity;
} Il2CppMarshalByRefObject;
typedef struct Il2CppComObject
{
    Il2CppObject Object;
    Il2CppIUnknown* identity;
    volatile int32_t refCount;
} Il2CppComObject;
typedef struct Il2CppAppDomain
{
    Il2CppMarshalByRefObject mbr;
    Il2CppDomain* data;
} Il2CppAppDomain;
typedef struct Il2CppStackFrame
{
    Il2CppObject obj;
    int32_t il_offset;
    int32_t native_offset;
    uint64_t methodAddress;
    uint32_t methodIndex;
    Il2CppReflectionMethod* method;
    Il2CppString* filename;
    int32_t line;
    int32_t column;
    Il2CppString* internal_method_name;
} Il2CppStackFrame;
typedef struct Il2CppDateTimeFormatInfo
{
    Il2CppObject obj;
    Il2CppObject* CultureData;
    Il2CppString* Name;
    Il2CppString* LangName;
    Il2CppObject* CompareInfo;
    Il2CppObject* CultureInfo;
    Il2CppString* AMDesignator;
    Il2CppString* PMDesignator;
    Il2CppString* DateSeparator;
    Il2CppString* GeneralShortTimePattern;
    Il2CppString* GeneralLongTimePattern;
    Il2CppString* TimeSeparator;
    Il2CppString* MonthDayPattern;
    Il2CppString* DateTimeOffsetPattern;
    Il2CppObject* Calendar;
    uint32_t FirstDayOfWeek;
    uint32_t CalendarWeekRule;
    Il2CppString* FullDateTimePattern;
    Il2CppArray* AbbreviatedDayNames;
    Il2CppArray* ShortDayNames;
    Il2CppArray* DayNames;
    Il2CppArray* AbbreviatedMonthNames;
    Il2CppArray* MonthNames;
    Il2CppArray* GenitiveMonthNames;
    Il2CppArray* GenitiveAbbreviatedMonthNames;
    Il2CppArray* LeapYearMonthNames;
    Il2CppString* LongDatePattern;
    Il2CppString* ShortDatePattern;
    Il2CppString* YearMonthPattern;
    Il2CppString* LongTimePattern;
    Il2CppString* ShortTimePattern;
    Il2CppArray* YearMonthPatterns;
    Il2CppArray* ShortDatePatterns;
    Il2CppArray* LongDatePatterns;
    Il2CppArray* ShortTimePatterns;
    Il2CppArray* LongTimePatterns;
    Il2CppArray* EraNames;
    Il2CppArray* AbbrevEraNames;
    Il2CppArray* AbbrevEnglishEraNames;
    Il2CppArray* OptionalCalendars;
    bool readOnly;
    int32_t FormatFlags;
    int32_t CultureID;
    bool UseUserOverride;
    bool UseCalendarInfo;
    int32_t DataItem;
    bool IsDefaultCalendar;
    Il2CppArray* DateWords;
    Il2CppString* FullTimeSpanPositivePattern;
    Il2CppString* FullTimeSpanNegativePattern;
    Il2CppArray* dtfiTokenHash;
} Il2CppDateTimeFormatInfo;
typedef struct Il2CppNumberFormatInfo
{
    Il2CppObject obj;
    Il2CppArray* numberGroupSizes;
    Il2CppArray* currencyGroupSizes;
    Il2CppArray* percentGroupSizes;
    Il2CppString* positiveSign;
    Il2CppString* negativeSign;
    Il2CppString* numberDecimalSeparator;
    Il2CppString* numberGroupSeparator;
    Il2CppString* currencyGroupSeparator;
    Il2CppString* currencyDecimalSeparator;
    Il2CppString* currencySymbol;
    Il2CppString* ansiCurrencySymbol;
    Il2CppString* naNSymbol;
    Il2CppString* positiveInfinitySymbol;
    Il2CppString* negativeInfinitySymbol;
    Il2CppString* percentDecimalSeparator;
    Il2CppString* percentGroupSeparator;
    Il2CppString* percentSymbol;
    Il2CppString* perMilleSymbol;
    Il2CppArray* nativeDigits;
    int dataItem;
    int numberDecimalDigits;
    int currencyDecimalDigits;
    int currencyPositivePattern;
    int currencyNegativePattern;
    int numberNegativePattern;
    int percentPositivePattern;
    int percentNegativePattern;
    int percentDecimalDigits;
    int digitSubstitution;
    bool readOnly;
    bool useUserOverride;
    bool isInvariant;
    bool validForParseAsNumber;
    bool validForParseAsCurrency;
} Il2CppNumberFormatInfo;
typedef struct Il2CppCultureData
{
    Il2CppObject obj;
    Il2CppString* AMDesignator;
    Il2CppString* PMDesignator;
    Il2CppString* TimeSeparator;
    Il2CppArray* LongTimePatterns;
    Il2CppArray* ShortTimePatterns;
    uint32_t FirstDayOfWeek;
    uint32_t CalendarWeekRule;
} Il2CppCultureData;
typedef struct Il2CppCalendarData
{
    Il2CppObject obj;
    Il2CppString* NativeName;
    Il2CppArray* ShortDatePatterns;
    Il2CppArray* YearMonthPatterns;
    Il2CppArray* LongDatePatterns;
    Il2CppString* MonthDayPattern;
    Il2CppArray* EraNames;
    Il2CppArray* AbbreviatedEraNames;
    Il2CppArray* AbbreviatedEnglishEraNames;
    Il2CppArray* DayNames;
    Il2CppArray* AbbreviatedDayNames;
    Il2CppArray* SuperShortDayNames;
    Il2CppArray* MonthNames;
    Il2CppArray* AbbreviatedMonthNames;
    Il2CppArray* GenitiveMonthNames;
    Il2CppArray* GenitiveAbbreviatedMonthNames;
} Il2CppCalendarData;
typedef struct Il2CppCultureInfo
{
    Il2CppObject obj;
    bool is_read_only;
    int32_t lcid;
    int32_t parent_lcid;
    int32_t datetime_index;
    int32_t number_index;
    int32_t default_calendar_type;
    bool use_user_override;
    Il2CppNumberFormatInfo* number_format;
    Il2CppDateTimeFormatInfo* datetime_format;
    Il2CppObject* textinfo;
    Il2CppString* name;
    Il2CppString* englishname;
    Il2CppString* nativename;
    Il2CppString* iso3lang;
    Il2CppString* iso2lang;
    Il2CppString* win3lang;
    Il2CppString* territory;
    Il2CppArray* native_calendar_names;
    Il2CppString* compareinfo;
    const void* text_info_data;
    int dataItem;
    Il2CppObject* calendar;
    Il2CppObject* parent_culture;
    bool constructed;
    Il2CppArray* cached_serialized_form;
    Il2CppObject* cultureData;
    bool isInherited;
} Il2CppCultureInfo;
typedef struct Il2CppRegionInfo
{
    Il2CppObject obj;
    int32_t geo_id;
    Il2CppString* iso2name;
    Il2CppString* iso3name;
    Il2CppString* win3name;
    Il2CppString* english_name;
    Il2CppString* currency_symbol;
    Il2CppString* iso_currency_symbol;
    Il2CppString* currency_english_name;
} Il2CppRegionInfo;
typedef struct Il2CppSafeHandle
{
    Il2CppObject base;
    void* handle;
    int state;
    bool owns_handle;
    bool fullyInitialized;
} Il2CppSafeHandle;
typedef struct Il2CppStringBuilder
{
    Il2CppObject object;
    Il2CppArray* chunkChars;
    Il2CppStringBuilder* chunkPrevious;
    int chunkLength;
    int chunkOffset;
    int maxCapacity;
} Il2CppStringBuilder;
typedef struct Il2CppSocketAddress
{
    Il2CppObject base;
    int m_Size;
    Il2CppArray* data;
    bool m_changed;
    int m_hash;
} Il2CppSocketAddress;
typedef struct Il2CppSortKey
{
    Il2CppObject base;
    Il2CppString* str;
    Il2CppArray* key;
    int32_t options;
    int32_t lcid;
} Il2CppSortKey;
typedef struct Il2CppErrorWrapper
{
    Il2CppObject base;
    int32_t errorCode;
} Il2CppErrorWrapper;
typedef struct Il2CppAsyncResult
{
    Il2CppObject base;
    Il2CppObject* async_state;
    Il2CppWaitHandle* handle;
    Il2CppDelegate* async_delegate;
    void* data;
    Il2CppAsyncCall* object_data;
    bool sync_completed;
    bool completed;
    bool endinvoke_called;
    Il2CppObject* async_callback;
    Il2CppObject* execution_context;
    Il2CppObject* original_context;
} Il2CppAsyncResult;
typedef struct Il2CppAsyncCall
{
    Il2CppObject base;
    Il2CppMethodMessage* msg;
    MethodInfo* cb_method;
    Il2CppDelegate* cb_target;
    Il2CppObject* state;
    Il2CppObject* res;
    Il2CppArray* out_args;
} Il2CppAsyncCall;
typedef struct Il2CppExceptionWrapper
{
    Il2CppException* ex;
} Il2CppExceptionWrapper;
typedef struct Il2CppIOAsyncResult
{
    Il2CppObject base;
    Il2CppDelegate* callback;
    Il2CppObject* state;
    Il2CppWaitHandle* wait_handle;
    bool completed_synchronously;
    bool completed;
} Il2CppIOAsyncResult;
typedef struct Il2CppSocketAsyncResult
{
    Il2CppIOAsyncResult base;
    Il2CppObject* socket;
    int32_t operation;
    Il2CppException* delayedException;
    Il2CppObject* endPoint;
    Il2CppArray* buffer;
    int32_t offset;
    int32_t size;
    int32_t socket_flags;
    Il2CppObject* acceptSocket;
    Il2CppArray* addresses;
    int32_t port;
    Il2CppObject* buffers;
    bool reuseSocket;
    int32_t currentAddress;
    Il2CppObject* acceptedSocket;
    int32_t total;
    int32_t error;
    int32_t endCalled;
} Il2CppSocketAsyncResult;
typedef enum Il2CppResourceLocation
{
    IL2CPP_RESOURCE_LOCATION_EMBEDDED = 1,
    IL2CPP_RESOURCE_LOCATION_ANOTHER_ASSEMBLY = 2,
    IL2CPP_RESOURCE_LOCATION_IN_MANIFEST = 4
} Il2CppResourceLocation;
typedef struct Il2CppManifestResourceInfo
{
    Il2CppObject object;
    Il2CppReflectionAssembly* assembly;
    Il2CppString* filename;
    uint32_t location;
} Il2CppManifestResourceInfo;
typedef struct Il2CppAppContext
{
    Il2CppObject obj;
    int32_t domain_id;
    int32_t context_id;
    void* static_data;
} Il2CppAppContext;
struct Il2CppDecimal
{
    uint16_t reserved;
    union
    {
        struct
        {
            uint8_t scale;
            uint8_t sign;
        } u;
        uint16_t signscale;
    } u;
    uint32_t Hi32;
    union
    {
        struct
        {
            uint32_t Lo32;
            uint32_t Mid32;
        } v;
        uint64_t Lo64;
    } v;
};
typedef struct Il2CppDouble
{
    uint32_t mantLo : 32;
    uint32_t mantHi : 20;
    uint32_t exp : 11;
    uint32_t sign : 1;
} Il2CppDouble;
typedef union
{
    Il2CppDouble s;
    double d;
} Il2CppDouble_double;
typedef enum
{
    IL2CPP_DECIMAL_CMP_LT = -1,
    IL2CPP_DECIMAL_CMP_EQ,
    IL2CPP_DECIMAL_CMP_GT
} Il2CppDecimalCompareResult;
typedef struct Il2CppSingle
{
    uint32_t mant : 23;
    uint32_t exp : 8;
    uint32_t sign : 1;
} Il2CppSingle;
typedef union
{
    Il2CppSingle s;
    float f;
} Il2CppSingle_float;
typedef struct Il2CppGuid
{
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t data4[8];
} Il2CppGuid;
typedef struct Il2CppSafeArrayBound
{
    uint32_t element_count;
    int32_t lower_bound;
} Il2CppSafeArrayBound;
typedef struct Il2CppSafeArray
{
    uint16_t dimension_count;
    uint16_t features;
    uint32_t element_size;
    uint32_t lock_count;
    void* data;
    Il2CppSafeArrayBound bounds[1];
} Il2CppSafeArray;
struct Il2CppWin32Decimal
{
    uint16_t reserved;
    union
    {
        struct
        {
            uint8_t scale;
            uint8_t sign;
        } s;
        uint16_t signscale;
    } u;
    uint32_t hi32;
    union
    {
        struct
        {
            uint32_t lo32;
            uint32_t mid32;
        } s2;
        uint64_t lo64;
    } u2;
};
typedef int16_t IL2CPP_VARIANT_BOOL;
typedef enum Il2CppVarType
{
    IL2CPP_VT_EMPTY = 0,
    IL2CPP_VT_NULL = 1,
    IL2CPP_VT_I2 = 2,
    IL2CPP_VT_I4 = 3,
    IL2CPP_VT_R4 = 4,
    IL2CPP_VT_R8 = 5,
    IL2CPP_VT_CY = 6,
    IL2CPP_VT_DATE = 7,
    IL2CPP_VT_BSTR = 8,
    IL2CPP_VT_DISPATCH = 9,
    IL2CPP_VT_ERROR = 10,
    IL2CPP_VT_BOOL = 11,
    IL2CPP_VT_VARIANT = 12,
    IL2CPP_VT_UNKNOWN = 13,
    IL2CPP_VT_DECIMAL = 14,
    IL2CPP_VT_I1 = 16,
    IL2CPP_VT_UI1 = 17,
    IL2CPP_VT_UI2 = 18,
    IL2CPP_VT_UI4 = 19,
    IL2CPP_VT_I8 = 20,
    IL2CPP_VT_UI8 = 21,
    IL2CPP_VT_INT = 22,
    IL2CPP_VT_UINT = 23,
    IL2CPP_VT_VOID = 24,
    IL2CPP_VT_HRESULT = 25,
    IL2CPP_VT_PTR = 26,
    IL2CPP_VT_SAFEARRAY = 27,
    IL2CPP_VT_CARRAY = 28,
    IL2CPP_VT_USERDEFINED = 29,
    IL2CPP_VT_LPSTR = 30,
    IL2CPP_VT_LPWSTR = 31,
    IL2CPP_VT_RECORD = 36,
    IL2CPP_VT_INT_PTR = 37,
    IL2CPP_VT_UINT_PTR = 38,
    IL2CPP_VT_FILETIME = 64,
    IL2CPP_VT_BLOB = 65,
    IL2CPP_VT_STREAM = 66,
    IL2CPP_VT_STORAGE = 67,
    IL2CPP_VT_STREAMED_OBJECT = 68,
    IL2CPP_VT_STORED_OBJECT = 69,
    IL2CPP_VT_BLOB_OBJECT = 70,
    IL2CPP_VT_CF = 71,
    IL2CPP_VT_CLSID = 72,
    IL2CPP_VT_VERSIONED_STREAM = 73,
    IL2CPP_VT_BSTR_BLOB = 0xfff,
    IL2CPP_VT_VECTOR = 0x1000,
    IL2CPP_VT_ARRAY = 0x2000,
    IL2CPP_VT_BYREF = 0x4000,
    IL2CPP_VT_RESERVED = 0x8000,
    IL2CPP_VT_ILLEGAL = 0xffff,
    IL2CPP_VT_ILLEGALMASKED = 0xfff,
    IL2CPP_VT_TYPEMASK = 0xfff,
} Il2CppVarType;
typedef struct Il2CppVariant
{
    union
    {
        struct __tagVARIANT
        {
            uint16_t type;
            uint16_t reserved1;
            uint16_t reserved2;
            uint16_t reserved3;
            union
            {
                int64_t llVal;
                int32_t lVal;
                uint8_t bVal;
                int16_t iVal;
                float fltVal;
                double dblVal;
                IL2CPP_VARIANT_BOOL boolVal;
                int32_t scode;
                int64_t cyVal;
                double date;
                Il2CppChar* bstrVal;
                Il2CppIUnknown* punkVal;
                void* pdispVal;
                Il2CppSafeArray* parray;
                uint8_t* pbVal;
                int16_t* piVal;
                int32_t* plVal;
                int64_t* pllVal;
                float* pfltVal;
                double* pdblVal;
                IL2CPP_VARIANT_BOOL* pboolVal;
                int32_t* pscode;
                int64_t* pcyVal;
                double* pdate;
                Il2CppChar* pbstrVal;
                Il2CppIUnknown** ppunkVal;
                void** ppdispVal;
                Il2CppSafeArray** pparray;
                struct Il2CppVariant* pvarVal;
                void* byref;
                char cVal;
                uint16_t uiVal;
                uint32_t ulVal;
                uint64_t ullVal;
                int intVal;
                unsigned int uintVal;
                Il2CppWin32Decimal* pdecVal;
                char* pcVal;
                uint16_t* puiVal;
                uint32_t* pulVal;
                uint64_t* pullVal;
                int* pintVal;
                unsigned int* puintVal;
                struct __tagBRECORD
                {
                    void* pvRecord;
                    void* pRecInfo;
                } n4;
            } n3;
        } n2;
        Il2CppWin32Decimal decVal;
    } n1;
} Il2CppVariant;
typedef struct Il2CppFileTime
{
    uint32_t low;
    uint32_t high;
} Il2CppFileTime;
typedef struct Il2CppStatStg
{
    Il2CppChar* name;
    uint32_t type;
    uint64_t size;
    Il2CppFileTime mtime;
    Il2CppFileTime ctime;
    Il2CppFileTime atime;
    uint32_t mode;
    uint32_t locks;
    Il2CppGuid clsid;
    uint32_t state;
    uint32_t reserved;
} Il2CppStatStg;
typedef struct Il2CppHString__
{
    int unused;
} Il2CppHString__;
typedef Il2CppHString__* Il2CppHString;
typedef struct Il2CppHStringHeader
{
    union
    {
        void* Reserved1;
        char Reserved2[24];
    } Reserved;
} Il2CppHStringHeader;
typedef struct Il2CppIUnknown
{
    static const Il2CppGuid IID;
} Il2CppIUnknown;
typedef struct Il2CppISequentialStream
{
    Il2CppIUnknown IUnknown;
    static const Il2CppGuid IID;
} Il2CppISequentialStream;
typedef struct Il2CppIStream
{
    Il2CppISequentialStream ISequentialStream;
    static const Il2CppGuid IID;
} Il2CppIStream;
typedef struct Il2CppIMarshal
{
    Il2CppIUnknown IUnknown;
    static const Il2CppGuid IID;
} Il2CppIMarshal;
typedef struct Il2CppIManagedObject
{
    Il2CppIUnknown IUnknown;
    static const Il2CppGuid IID;
} Il2CppIManagedObject;
typedef struct Il2CppIManagedObjectHolder
{
    Il2CppIUnknown IUnknown;
    static const Il2CppGuid IID;
} Il2CppIManagedObjectHolder;
typedef struct Il2CppIInspectable
{
    Il2CppIUnknown IUnknown;
    static const Il2CppGuid IID;
} Il2CppIInspectable;
typedef struct Il2CppIActivationFactory
{
    Il2CppIInspectable IInspectable;
    static const Il2CppGuid IID;
} Il2CppIActivationFactory;
typedef struct Il2CppIRestrictedErrorInfo
{
    Il2CppIUnknown IUnknown;
    static const Il2CppGuid IID;
} Il2CppIRestrictedErrorInfo;
typedef struct Il2CppILanguageExceptionErrorInfo
{
    Il2CppIUnknown IUnknown;
    static const Il2CppGuid IID;
} Il2CppILanguageExceptionErrorInfo;
typedef struct Il2CppIAgileObject
{
    Il2CppIUnknown IUnknown;
    static const Il2CppGuid IID;
} Il2CppIAgileObject;

#pragma warning(disable : 4369)
#pragma warning(disable : 4309)
#pragma warning(disable : 4359)
#if !defined(_GHIDRA_) && !defined(_IDA_)
namespace app {
#endif

    // ******************************************************************************
    // * Application types from method calls
    // ******************************************************************************

    struct Object__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct Object__StaticFields {
    };

    struct Object__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Object__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Object__VTable vtable;
    };
    
    struct Type__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData GetCustomAttributes;
        VirtualInvokeData GetCustomAttributes_1;
        VirtualInvokeData IsDefined;
        VirtualInvokeData get_DeclaringType;
        VirtualInvokeData get_MemberType;
        VirtualInvokeData __unknown;
        VirtualInvokeData get_ReflectedType;
        VirtualInvokeData __unknown_1;
        VirtualInvokeData __unknown_2;
        VirtualInvokeData __unknown_3;
        VirtualInvokeData __unknown_4;
        VirtualInvokeData get_MetadataToken;
        VirtualInvokeData __unknown_5;
        VirtualInvokeData __unknown_6;
        VirtualInvokeData get_Attributes;
        VirtualInvokeData __unknown_7;
        VirtualInvokeData __unknown_8;
        VirtualInvokeData __unknown_9;
        VirtualInvokeData get_HasElementType;
        VirtualInvokeData get_IsAbstract;
        VirtualInvokeData get_IsArray;
        VirtualInvokeData get_IsByRef;
        VirtualInvokeData get_IsClass;
        VirtualInvokeData get_IsContextful;
        VirtualInvokeData get_IsEnum;
        VirtualInvokeData get_IsExplicitLayout;
        VirtualInvokeData get_IsInterface;
        VirtualInvokeData get_IsMarshalByRef;
        VirtualInvokeData get_IsNestedPublic;
        VirtualInvokeData get_IsPointer;
        VirtualInvokeData get_IsPrimitive;
        VirtualInvokeData get_IsPublic;
        VirtualInvokeData get_IsSealed;
        VirtualInvokeData get_IsSerializable;
        VirtualInvokeData get_IsValueType;
        VirtualInvokeData __unknown_10;
        VirtualInvokeData get_TypeHandle;
        VirtualInvokeData __unknown_11;
        VirtualInvokeData Equals_1;
        VirtualInvokeData GetType;
        VirtualInvokeData IsSubclassOf;
        VirtualInvokeData GetInterfaceMap;
        VirtualInvokeData __unknown_12;
        VirtualInvokeData IsAssignableFrom;
        VirtualInvokeData IsInstanceOfType;
        VirtualInvokeData GetArrayRank;
        VirtualInvokeData __unknown_13;
        VirtualInvokeData GetEvent;
        VirtualInvokeData __unknown_14;
        VirtualInvokeData __unknown_15;
        VirtualInvokeData GetField;
        VirtualInvokeData __unknown_16;
        VirtualInvokeData GetFields;
        VirtualInvokeData __unknown_17;
        VirtualInvokeData GetMember;
        VirtualInvokeData GetMember_1;
        VirtualInvokeData GetMember_2;
        VirtualInvokeData __unknown_18;
        VirtualInvokeData GetMethod;
        VirtualInvokeData GetMethod_1;
        VirtualInvokeData GetMethod_2;
        VirtualInvokeData GetMethod_3;
        VirtualInvokeData GetMethod_4;
        VirtualInvokeData __unknown_19;
        VirtualInvokeData GetMethods;
        VirtualInvokeData __unknown_20;
        VirtualInvokeData __unknown_21;
        VirtualInvokeData GetProperties;
        VirtualInvokeData __unknown_22;
        VirtualInvokeData GetProperty;
        VirtualInvokeData GetProperty_1;
        VirtualInvokeData GetProperty_2;
        VirtualInvokeData GetProperty_3;
        VirtualInvokeData GetProperty_4;
        VirtualInvokeData __unknown_23;
        VirtualInvokeData __unknown_24;
        VirtualInvokeData __unknown_25;
        VirtualInvokeData __unknown_26;
        VirtualInvokeData __unknown_27;
        VirtualInvokeData __unknown_28;
        VirtualInvokeData __unknown_29;
        VirtualInvokeData __unknown_30;
        VirtualInvokeData IsValueTypeImpl;
        VirtualInvokeData IsContextfulImpl;
        VirtualInvokeData IsMarshalByRefImpl;
        VirtualInvokeData GetConstructor;
        VirtualInvokeData GetConstructor_1;
        VirtualInvokeData GetConstructor_2;
        VirtualInvokeData GetConstructors;
        VirtualInvokeData __unknown_31;
        VirtualInvokeData FindMembers;
        VirtualInvokeData InvokeMember;
        VirtualInvokeData __unknown_32;
        VirtualInvokeData GetGenericArguments;
        VirtualInvokeData get_ContainsGenericParameters;
        VirtualInvokeData get_IsGenericTypeDefinition;
        VirtualInvokeData GetGenericTypeDefinition;
        VirtualInvokeData get_IsGenericType;
        VirtualInvokeData MakeGenericType;
        VirtualInvokeData get_IsGenericParameter;
        VirtualInvokeData GetGenericParameterConstraints;
        VirtualInvokeData MakeByRefType;
    };

    struct Type__StaticFields {
        uint16_t Delimiter;
        struct Type__Array* EmptyTypes;
        struct MemberFilter* FilterAttribute;
        struct MemberFilter* FilterName;
        struct MemberFilter* FilterNameIgnoreCase;
        struct Object* Missing;
    };

    struct Type__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Type__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Type__VTable vtable;
    };

    struct Object {
        struct Object__Class* klass;
        MonitorData* monitor;
    };

    struct RuntimeTypeHandle__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData GetObjectData;
    };

    struct RuntimeTypeHandle__StaticFields {
    };

    struct RuntimeTypeHandle__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct RuntimeTypeHandle__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct RuntimeTypeHandle__VTable vtable;
    };

    struct Char__Array__VTable {
    };

    struct Char__Array__StaticFields {
    };

    struct Char__Array__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Char__Array__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Char__Array__VTable vtable;
    };

    struct __declspec(align(8)) Encoding__Fields {
        int32_t codePage;
        int32_t windows_code_page;
        bool is_readonly;
        struct DecoderFallback* decoder_fallback;
        struct EncoderFallback* encoder_fallback;
        struct String* body_name;
        struct String* encoding_name;
        struct String* header_name;
        bool is_mail_news_display;
        bool is_mail_news_save;
        bool is_browser_save;
        bool is_browser_display;
        struct String* web_name;
    };

    struct Encoding__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData Clone;
        VirtualInvokeData __unknown;
        VirtualInvokeData GetByteCount;
        VirtualInvokeData GetByteCount_1;
        VirtualInvokeData __unknown_1;
        VirtualInvokeData GetBytes;
        VirtualInvokeData GetBytes_1;
        VirtualInvokeData GetBytes_2;
        VirtualInvokeData GetBytes_3;
        VirtualInvokeData __unknown_2;
        VirtualInvokeData __unknown_3;
        VirtualInvokeData GetChars;
        VirtualInvokeData GetChars_1;
        VirtualInvokeData GetDecoder;
        VirtualInvokeData Clone_1;
        VirtualInvokeData __unknown_4;
        VirtualInvokeData __unknown_5;
        VirtualInvokeData GetPreamble;
        VirtualInvokeData GetString;
        VirtualInvokeData GetString_1;
        VirtualInvokeData get_HeaderName;
        VirtualInvokeData get_WebName;
        VirtualInvokeData GetByteCount_2;
        VirtualInvokeData GetBytes_4;
    };

    struct Encoding__StaticFields {
        struct Assembly* i18nAssembly;
        bool i18nDisabled;
        struct EncodingInfo__Array* encoding_infos;
        struct Object__Array* encodings;
        struct Encoding* asciiEncoding;
        struct Encoding* bigEndianEncoding;
        struct Encoding* defaultEncoding;
        struct Encoding* utf7Encoding;
        struct Encoding* utf8EncodingWithMarkers;
        struct Encoding* utf8EncodingWithoutMarkers;
        struct Encoding* unicodeEncoding;
        struct Encoding* isoLatin1Encoding;
        struct Encoding* utf8EncodingUnsafe;
        struct Encoding* utf32Encoding;
        struct Encoding* bigEndianUTF32Encoding;
        struct Object* lockobj;
    };

    struct Encoding {
        struct Encoding__Class* klass;
        MonitorData* monitor;
        struct Encoding__Fields fields;
    };

    struct Encoding__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Encoding__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Encoding__VTable vtable;
    };

    struct Char__Array {
        struct Char__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        uint16_t vector[32];
    };

    struct RuntimeTypeHandle {
        void* value;
    };

    struct RuntimeTypeHandle__Boxed {
        struct RuntimeTypeHandle__Class* klass;
        MonitorData* monitor;
        struct RuntimeTypeHandle fields;
    };



    struct __declspec(align(8)) Type__Fields {
        struct RuntimeTypeHandle _impl;
    };

    struct Type {
        struct Type__Class* klass;
        MonitorData* monitor;
        struct Type__Fields fields;
    };

    struct String__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData GetTypeCode;
        VirtualInvokeData System_IConvertible_ToBoolean;
        VirtualInvokeData System_IConvertible_ToByte;
        VirtualInvokeData System_IConvertible_ToChar;
        VirtualInvokeData System_IConvertible_ToDateTime;
        VirtualInvokeData System_IConvertible_ToDecimal;
        VirtualInvokeData System_IConvertible_ToDouble;
        VirtualInvokeData System_IConvertible_ToInt16;
        VirtualInvokeData System_IConvertible_ToInt32;
        VirtualInvokeData System_IConvertible_ToInt64;
        VirtualInvokeData System_IConvertible_ToSByte;
        VirtualInvokeData System_IConvertible_ToSingle;
        VirtualInvokeData ToString_1;
        VirtualInvokeData System_IConvertible_ToType;
        VirtualInvokeData System_IConvertible_ToUInt16;
        VirtualInvokeData System_IConvertible_ToUInt32;
        VirtualInvokeData System_IConvertible_ToUInt64;
        VirtualInvokeData CompareTo;
        VirtualInvokeData System_Collections_IEnumerable_GetEnumerator;
        VirtualInvokeData Clone;
        VirtualInvokeData CompareTo_1;
        VirtualInvokeData Equals_1;
        VirtualInvokeData System_Collections_Generic_IEnumerable_char__GetEnumerator;
    };

    struct String__StaticFields {
        struct String* Empty;
        struct Char__Array* WhiteChars;
    };

    struct String__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct String__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct String__VTable vtable;
    };

    struct __declspec(align(8)) String__Fields {
        int32_t length;
        uint16_t start_char;
    };

    struct String {
        struct String__Class* klass;
        MonitorData* monitor;
        struct String__Fields fields;
    };

    struct IFormatProvider {
        struct IFormatProvider__Class* klass;
        MonitorData* monitor;
    };

    struct IFormatProvider__VTable {
        VirtualInvokeData GetFormat;
    };

    struct IFormatProvider__StaticFields {
    };

    struct IFormatProvider__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct IFormatProvider__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct IFormatProvider__VTable vtable;
    };

    struct Byte__Array__VTable {
    };

    struct Byte__Array__StaticFields {
    };

    struct Byte__Array__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Byte__Array__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Byte__Array__VTable vtable;
    };

    struct Byte__Array {
        struct Byte__Array__Class* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        uint8_t vector[32];
    };

    struct __declspec(align(8)) LuaBaseManager__Fields {
        struct LuaEnv* _luaenv;
    };

    struct LuaManager_ILuaReload__VTable {
        VirtualInvokeData Reload;
        VirtualInvokeData GetHotfixFuncs;
    };

    struct LuaManager_ILuaReload__StaticFields {
    };

    struct LuaManager_ILuaReload__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct LuaManager_ILuaReload__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct LuaManager_ILuaReload__VTable vtable;
    };

    struct LuaBaseManager__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData Init;
        VirtualInvokeData Tick;
        VirtualInvokeData PostTick;
        VirtualInvokeData LateTick;
        VirtualInvokeData LatePreTick;
        VirtualInvokeData LatePreTickEnd;
        VirtualInvokeData LatePostTick;
        VirtualInvokeData LatePostTickEnd;
        VirtualInvokeData Dump;
        VirtualInvokeData Destroy;
        VirtualInvokeData ClearOnLevelDestroy;
        VirtualInvokeData InitOnConnect;
        VirtualInvokeData ClearOnDisconnect;
        VirtualInvokeData ClearOnBackHome;
        VirtualInvokeData ReloadRes;
        VirtualInvokeData InitByLocalData;
        VirtualInvokeData InitLua;
        VirtualInvokeData Require;
        VirtualInvokeData OnLoadLuaFinish;
    };

    struct LuaBaseManager__StaticFields {
        struct DelegateBridge* _c__Hotfix0_ctor;
        struct DelegateBridge* __Hotfix0_Init;
        struct DelegateBridge* __Hotfix0_InitLua;
        struct DelegateBridge* __Hotfix0_DoLua;
        struct DelegateBridge* __Hotfix0_Require;
        struct DelegateBridge* __Hotfix0_OnLoadLuaFinish;
        struct DelegateBridge* __Hotfix0_ReloadRes;
        struct DelegateBridge* __Hotfix0_Tick;
        struct DelegateBridge* __Hotfix0_Destroy;
        struct DelegateBridge* __Hotfix0_ClearOnLevelDestroy;
        struct DelegateBridge* __Hotfix0_WaitForSeconds;
        struct DelegateBridge* __Hotfix0_WaitForSecondsImp;
        struct DelegateBridge* __Hotfix0_WaitForSeveralFrames;
        struct DelegateBridge* __Hotfix0_WaitForSeveralFramesImp;
        struct DelegateBridge* __Hotfix0_WaitForEndOfFrame;
        struct DelegateBridge* __Hotfix0_WaitForEndOfFrameImp;
        struct DelegateBridge* __Hotfix0_WaitForFixedUpdate;
        struct DelegateBridge* __Hotfix0_WaitForFixedUpdateImp;
        struct DelegateBridge* __Hotfix0_IsIOS;
        struct DelegateBridge* __Hotfix0_IsAndroid;
        struct DelegateBridge* __Hotfix0_ModifySafeFloat;
        struct DelegateBridge* __Hotfix0_ModifySafeInt;
        struct DelegateBridge* __Hotfix0_ModifySafeBool;
        struct DelegateBridge* __Hotfix0_GetActorPlugin;
        struct DelegateBridge* __Hotfix0_GetNetPacketV1Data;
        struct DelegateBridge* __Hotfix0_CreateLuaTable;
        struct DelegateBridge* __Hotfix0_ConvertDictionaryToLuaTable;
        struct DelegateBridge* __Hotfix0_ConvertDictionaryKeysToList;
        struct DelegateBridge* __Hotfix0_CreateLuaDelegate;
        struct DelegateBridge* __Hotfix0_CreateLuaAction;
        struct DelegateBridge* __Hotfix0_CreateLuaActionWithOneArg;
        struct DelegateBridge* __Hotfix0_CreateLuaActionWithTwoArgs;
        struct DelegateBridge* __Hotfix0_CreateLuaActionWithThreeArgs;
        struct DelegateBridge* __Hotfix0_CreateLuaActionWithFourArgs;
        struct DelegateBridge* __Hotfix0_CreateDelegate;
        struct DelegateBridge* __Hotfix0_CreateAction;
        struct DelegateBridge* __Hotfix0_CreateActionWithOneArg;
        struct DelegateBridge* __Hotfix0_CreateActionWithTwoArgs;
        struct DelegateBridge* __Hotfix0_CreateActionWithMultiArgs;
        struct DelegateBridge* __Hotfix0_CreateStaticClassDelegate;
        struct DelegateBridge* __Hotfix0_CreateStaticClassAction;
        struct DelegateBridge* __Hotfix0_CreateStaticClassActionWithOneArg;
        struct DelegateBridge* __Hotfix0_CreateStaticClassActionWithTwoArgs;
        struct DelegateBridge* __Hotfix0_CreateStaticClassActionWithMultiArgs;
        struct DelegateBridge* __Hotfix0_CreateInstance;
        struct DelegateBridge* __Hotfix0_CreateGenericInstance;
        struct DelegateBridge* __Hotfix0_CreateGenericInstanceWithTwoArgs;
        struct DelegateBridge* __Hotfix0_CreateGenericInstanceWithMultiArgs;
        struct DelegateBridge* __Hotfix0_GetObjectField;
        struct DelegateBridge* __Hotfix0_GetObjectFieldValue;
        struct DelegateBridge* __Hotfix0_SetObjectFieldValue;
        struct DelegateBridge* __Hotfix0_GetStaticClassField;
        struct DelegateBridge* __Hotfix0_GetStaticClassFieldValue;
        struct DelegateBridge* __Hotfix0_SetStaticClassFieldValue;
        struct DelegateBridge* __Hotfix0_InvokeObjectMethod;
        struct DelegateBridge* __Hotfix0_InvokeObjectMethodWithMultiArgs;
        struct DelegateBridge* __Hotfix0_InvokeStaticClassMethod;
        struct DelegateBridge* __Hotfix0_InvokeStaticClassMethodWithMultiArgs;
        struct DelegateBridge* __Hotfix0_ConvertLuaArgToCSharpArg;
        struct DelegateBridge* __Hotfix0_ChangeType;
        struct DelegateBridge* __Hotfix1_ChangeType;
        struct DelegateBridge* __Hotfix0_GetClassType;
        struct DelegateBridge* __Hotfix1_GetClassType;
        struct DelegateBridge* __Hotfix0_GetTypeArray;
        struct DelegateBridge* __Hotfix1_GetTypeArray;
        struct DelegateBridge* __Hotfix2_GetTypeArray;
        struct DelegateBridge* __Hotfix3_GetTypeArray;
        struct DelegateBridge* __Hotfix0_InvokeMethodImp;
        struct DelegateBridge* __Hotfix1_InvokeMethodImp;
    };

    struct LuaBaseManager__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct LuaBaseManager__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct LuaBaseManager__VTable vtable;
    };

    struct LuaBaseManager {
        struct LuaBaseManager__Class* klass;
        MonitorData* monitor;
        struct LuaBaseManager__Fields fields;
    };

    struct LuaManager_ILuaReload {
        struct LuaManager_ILuaReload__Class* klass;
        MonitorData* monitor;
    };

    struct LuaManager_ILuaHotFix {
        struct LuaManager_ILuaHotFix__Class* klass;
        MonitorData* monitor;
    };

    struct LuaManager_ILuaMain {
        struct LuaManager_ILuaMain__Class* klass;
        MonitorData* monitor;
    };

    struct LuaManager__Fields {
        struct LuaBaseManager__Fields _;
        struct LuaManager_ILuaReload* _luaReload;
        struct LuaManager_ILuaHotFix* _luaHotfix;
        struct LuaManager_ILuaMain* _luaMain;
        struct ActorManager_ILuaActorManager* _luaActorMgr;
        struct Action* reloadCallback;
        struct LuaEnv_CustomLoader* _customLoader;
        uint32_t _gcCnt;
        bool gcEnabled;
        bool _isStarted;
        bool _hotfixInited;
        struct LuaTable* _patchTable;
    };

    struct LuaManager {
        struct LuaManager__Class* klass;
        MonitorData* monitor;
        struct LuaManager__Fields fields;
    };


    enum class DateTimeKind__Enum : int32_t {
        Unspecified = 0x00000000,
        Utc = 0x00000001,
        Local = 0x00000002,
    };

    struct TimeSpan {
        int64_t _ticks;
    };

    struct DateTime {
        struct TimeSpan ticks;
        DateTimeKind__Enum kind;
    };

    struct DateTime__Boxed {
        struct DateTime__Class* klass;
        MonitorData* monitor;
        struct DateTime fields;
    };
    
    struct __declspec(align(8)) LuaBase__Fields {
        bool disposed;
        int32_t luaReference;
        void* luaEnv;
    };

    struct DelegateBridgeBase__Fields {
        struct LuaBase__Fields _;
        void* firstKey;
        void* firstValue;
        void* bindTo;
        int32_t errorFuncRef;
    };


    struct DelegateBridge__Fields {
        struct DelegateBridgeBase__Fields _;
        int32_t _oldTop;
        void* _stack;
    };

    struct DelegateBridge {
        void* klass;
        MonitorData* monitor;
        struct DelegateBridge__Fields fields;
    };

    struct MMLHJDIKHGO__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct MMLHJDIKHGO__StaticFields {
        struct DelegateBridge* FBPNECEFLOE;
        struct DelegateBridge* PHCOGNGOLIB;
        struct DelegateBridge* OMMFGIEPLNB;
        struct DelegateBridge* DNGLBOAIJHH;
        struct DelegateBridge* NCLIEEPFHDL;
        struct DelegateBridge* KKOMKIEGPDO;
        struct DelegateBridge* FKBGMOOHCEA;
        struct DelegateBridge* DLBNKFCNNPF;
        struct DelegateBridge* ENEPELNLPFO;
        struct DelegateBridge* MPAKCCMDCIJ;
        struct DelegateBridge* OPGPJFEHPHA;
        struct DelegateBridge* KJEDMNINANM;
        struct DelegateBridge* EKCDCMOHEII;
        struct DelegateBridge* DGOPGFKLHCK;
        struct DelegateBridge* GNFJCLOPBJA;
        struct DelegateBridge* ECOIAFKEILB;
        struct DelegateBridge* BMONDEPLGNK;
        struct DelegateBridge* EODKGEBKPEI;
        struct DelegateBridge* IGGNFLOEKIA;
        struct DelegateBridge* FGKFHJNKCKN;
        struct DelegateBridge* JCAEBEECFNM;
        struct DelegateBridge* NDEKDPHIEMI;
        struct DelegateBridge* DMGCMECPIAF;
        struct DelegateBridge* FMLKIDOAAGM;
    };

    struct MMLHJDIKHGO__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct MMLHJDIKHGO__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct MMLHJDIKHGO__VTable vtable;
    };

    enum class MMLHJDIKHGO_PJOIODIAPNK__Enum : int32_t {
        UDP = 0x00000000,
        TCP = 0x00000001,
    };

    struct MMLHJDIKHGO_PJOIODIAPNK__Enum__Boxed {
        struct MMLHJDIKHGO_PJOIODIAPNK__Enum__Class* klass;
        MonitorData* monitor;
        MMLHJDIKHGO_PJOIODIAPNK__Enum value;
    };

    struct __declspec(align(8)) MMLHJDIKHGO__Fields {
        void* MEOGCAMBLHJ;
        MMLHJDIKHGO_PJOIODIAPNK__Enum JAAAEGMMPIF;
    };

    struct MMLHJDIKHGO {
        struct MMLHJDIKHGO__Class* klass;
        MonitorData* monitor;
        struct MMLHJDIKHGO__Fields fields;
    };

    struct ConfigChannel__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct ConfigChannel__StaticFields {
        struct DelegateBridge* _c__Hotfix0_ctor;
        struct DelegateBridge* __Hotfix0_IsOversea;
        struct DelegateBridge* __Hotfix0_IsPreGMPackage;
        struct DelegateBridge* __Hotfix0_IsRelPackage;
    };

    struct ConfigChannel__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct ConfigChannel__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct ConfigChannel__VTable vtable;
    };

    enum class AccountBranches__Enum : int32_t {
        Original = 0x00000000,
        UC = 0x00000001,
        QIHOO = 0x00000002,
        OPPO = 0x00000003,
        VIVO = 0x00000004,
        HUAWEI = 0x00000005,
        XIAOMI = 0x00000006,
        TENCENT = 0x00000007,
        GIONEE = 0x00000008,
        LENOVO = 0x00000009,
        BAIDU = 0x0000000a,
        COOLPAD = 0x0000000b,
        WANDOUJIA = 0x0000000c,
        MEIZU = 0x0000000d,
        BILIBILI = 0x0000000e,
        LESHI = 0x0000000f,
        JAPAN = 0x00000010,
        TAIWAN = 0x00000011,
        KOREA = 0x00000012,
        OVERSEAS = 0x00000013,
        GLOBAL = 0x00000014,
    };

    enum class PaymentBranches__Enum : int32_t {
        DEFAULT = 0x00000000,
        APPSTORE_CN = 0x00000001,
        ORIGINAL_ANDROID_PAY = 0x00000002,
        GOOGLE_ANDROID_PAY = 0x00000003,
    };

    struct __declspec(align(8)) ConfigChannel__Fields {
        struct String* ChannelName;
        struct String* BundleIdentifier;
        struct String* PS4ClientID;
        struct String* PS5ClientID;
        struct String* ProductName;
        struct String* PreDefines;
        struct String* TimeZones;
        void* DispatchConfigs;
        int32_t VersionCode;
        bool Obb;
        bool DataUseAssetBundle;
        bool EventUseAssetBundle;
        bool BetaMark;
        struct String* CVDefault;
        struct String* FAQUrl;
        struct String* ExceptionReportUrl;
        struct String* NetworkErrReportUrl;
        struct String* MediumReportUrl;
        struct String* CrashReportUrl;
        struct String* LogRecorderUrl;
        AccountBranches__Enum AccountBranch;
        PaymentBranches__Enum PaymentBranch;
        struct String* GVoiceAppID;
        struct String* GVoiceAppKey;
        struct String* GVoiceServerInfo;
        struct String* BaseTextLang;
        struct String* BaseAudioLang;
    };

    struct ConfigChannel {
        struct ConfigChannel__Class* klass;
        MonitorData* monitor;
        struct ConfigChannel__Fields fields;
    };

    struct UInt16__Array {
        void* klass;
        MonitorData* monitor;
        Il2CppArrayBounds* bounds;
        il2cpp_array_size_t max_length;
        uint16_t vector[32];
    };

    struct IPAddress__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
    };

    struct IPAddress__StaticFields {
        struct IPAddress* Any;
        struct IPAddress* Broadcast;
        struct IPAddress* Loopback;
        struct IPAddress* None;
        struct IPAddress* IPv6Any;
        struct IPAddress* IPv6Loopback;
        struct IPAddress* IPv6None;
    };

    struct IPAddress__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct IPAddress__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct IPAddress__VTable vtable;
    };

    enum class AddressFamily__Enum : int32_t {
        Unknown = -1,
        Unspecified = 0x00000000,
        Unix = 0x00000001,
        InterNetwork = 0x00000002,
        ImpLink = 0x00000003,
        Pup = 0x00000004,
        Chaos = 0x00000005,
        NS = 0x00000006,
        Ipx = 0x00000006,
        Iso = 0x00000007,
        Osi = 0x00000007,
        Ecma = 0x00000008,
        DataKit = 0x00000009,
        Ccitt = 0x0000000a,
        Sna = 0x0000000b,
        DecNet = 0x0000000c,
        DataLink = 0x0000000d,
        Lat = 0x0000000e,
        HyperChannel = 0x0000000f,
        AppleTalk = 0x00000010,
        NetBios = 0x00000011,
        VoiceView = 0x00000012,
        FireFox = 0x00000013,
        Banyan = 0x00000015,
        Atm = 0x00000016,
        InterNetworkV6 = 0x00000017,
        Cluster = 0x00000018,
        Ieee12844 = 0x00000019,
        Irda = 0x0000001a,
        NetworkDesigners = 0x0000001c,
        Max = 0x0000001d,
    };

    struct __declspec(align(8)) IPAddress__Fields {
        int64_t m_Address;
        AddressFamily__Enum m_Family;
        struct UInt16__Array* m_Numbers;
        int64_t m_ScopeId;
        int32_t m_HashCode;
    };

    struct IPAddress {
        struct IPAddress__Class* klass;
        MonitorData* monitor;
        struct IPAddress__Fields fields;
    };

    struct GameLogin__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData Init;
        VirtualInvokeData Tick;
        VirtualInvokeData PostTick;
        VirtualInvokeData LateTick;
        VirtualInvokeData LatePreTick;
        VirtualInvokeData LatePreTickEnd;
        VirtualInvokeData LatePostTick;
        VirtualInvokeData LatePostTickEnd;
        VirtualInvokeData Dump;
        VirtualInvokeData Destroy;
        VirtualInvokeData ClearOnLevelDestroy;
        VirtualInvokeData InitOnConnect;
        VirtualInvokeData ClearOnDisconnect;
        VirtualInvokeData ClearOnBackHome;
        VirtualInvokeData ReloadRes;
        VirtualInvokeData InitByLocalData;
        VirtualInvokeData OnNotify;
    };

    struct GameLogin__StaticFields {
        float MLDLNMIPKPC;
        struct Action_1_Boolean_* CILACBNHEJJ;
        struct Action_1_Boolean_* CMLLGAMAOGJ;
        struct Action_1_Boolean_* KLCMHGNLIDA;
        struct Action_1_Boolean_* KHCJGGHLPJB;
        struct DelegateBridge* FBPNECEFLOE;
        struct DelegateBridge* DJGJOAIGMLD;
        struct DelegateBridge* GHBMOCNLBEP;
        struct DelegateBridge* HAOJOAIJDLC;
        struct DelegateBridge* BNPHMIAKMLH;
        struct DelegateBridge* POHLKBNMAKN;
        struct DelegateBridge* ACKIAAPPOCM;
        struct DelegateBridge* NGBIKKCFAMM;
        struct DelegateBridge* INCKMHOGFFM;
        struct DelegateBridge* NCKBEMGGAFG;
        struct DelegateBridge* LBBMGIBJGKK;
        struct DelegateBridge* BGCCHJCOMCA;
        struct DelegateBridge* IGGNFLOEKIA;
        struct DelegateBridge* FGKFHJNKCKN;
        struct DelegateBridge* NDEKDPHIEMI;
        struct DelegateBridge* DMGCMECPIAF;
        struct DelegateBridge* OPIAFCKIIMH;
        struct DelegateBridge* MCMBGKDLJDP;
        struct DelegateBridge* PKKEJMCEFMN;
        struct DelegateBridge* CKFHNMFEGDH;
        struct DelegateBridge* ENDBLDDKOJM;
        struct DelegateBridge* AJIAHCGPFAM;
        struct DelegateBridge* MJFEOEEDIOM;
        struct DelegateBridge* ADLFHGAEGGP;
        struct DelegateBridge* BDDLFNOHNPL;
        struct DelegateBridge* DHPBOABCJCA;
        struct DelegateBridge* FGLFGLOCDAI;
        struct DelegateBridge* EBCBEEKJDAG;
        struct DelegateBridge* PGDPLBMLIOB;
        struct DelegateBridge* BIDFGAAMEIF;
        struct DelegateBridge* OJKLMMNGCCE;
        struct DelegateBridge* JLEKLKBLABP;
        struct DelegateBridge* AGGGLDBEDFC;
        struct DelegateBridge* DNGLBOAIJHH;
        struct DelegateBridge* GNFJCLOPBJA;
        struct DelegateBridge* DPBNGBNHHKM;
        struct DelegateBridge* FOLCPIBPFHC;
        struct DelegateBridge* IIFHAOOAAAN;
        struct DelegateBridge* FNODFDBIEGF;
        struct DelegateBridge* BMLDOAJDEJN;
        struct DelegateBridge* PAIMJJBFPOE;
        struct DelegateBridge* EEFPHGIJLFA;
        struct DelegateBridge* ENJJEODKEDM;
        struct DelegateBridge* NCLIEEPFHDL;
        struct DelegateBridge* ICIBJOEFHIB;
        struct DelegateBridge* PGELDOHIPEO;
        struct DelegateBridge* LNKHMBAGMPM;
        struct DelegateBridge* BMOFMEKMKKB;
        struct DelegateBridge* FMBPAMABPAN;
        struct DelegateBridge* JOIDODGIKPF;
        struct DelegateBridge* HKCBNNKMBLK;
        struct DelegateBridge* AJKLPKIBLFO;
        struct DelegateBridge* IEHIFOMCEMC;
        struct DelegateBridge* MNFIFFECNIB;
        struct DelegateBridge* PDACKOLBBAD;
        struct DelegateBridge* NOOBGJMNHHK;
        struct DelegateBridge* NNNBPLNLFJA;
        struct DelegateBridge* CNIBMCFKIGE;
        struct DelegateBridge* MOKNHGMODIF;
        struct DelegateBridge* DJGADCOHAHL;
        struct DelegateBridge* ANBGMAFNKBM;
        struct DelegateBridge* KLEBJFCFALN;
        struct DelegateBridge* FACBONJJDGK;
        struct DelegateBridge* GCAOJPKPHBI;
        struct DelegateBridge* LNJDKPPGIHI;
        struct DelegateBridge* LHJKPKHDFBJ;
        struct DelegateBridge* ONLNGOLFEGA;
        struct DelegateBridge* MPEPFPBGPED;
        struct DelegateBridge* EOLNJIBIOOI;
        struct DelegateBridge* HIKIICODOHG;
        struct DelegateBridge* HFNFADFGFNL;
        struct DelegateBridge* BEDLIIGCPPB;
        struct DelegateBridge* BOGFANIJHNG;
        struct DelegateBridge* JCMMIJINFHM;
        struct DelegateBridge* PIBDEAPDMCN;
        struct DelegateBridge* HHOHNDMOIDG;
        struct DelegateBridge* OJPHGKMIPFO;
        struct DelegateBridge* LCCJIFBKFGP;
        struct DelegateBridge* KLCMEPIDAFN;
        struct DelegateBridge* EPICONADDGN;
        struct DelegateBridge* FIADEEKPMIN;
        struct DelegateBridge* AMLNCFFHMMH;
        struct DelegateBridge* BGBACPBFBJA;
        struct DelegateBridge* FPFJEGLIGKF;
        struct DelegateBridge* NEBMEFPPFHM;
        struct DelegateBridge* CDCALMACEIP;
        struct DelegateBridge* IGNFNPLNEBA;
        struct DelegateBridge* OJBBNCGKILF;
        struct DelegateBridge* FLNMAACDBHM;
        struct DelegateBridge* HMNCCPODJGF;
        struct DelegateBridge* CGGCJLLEENH;
        struct DelegateBridge* LHJKHFBCIDE;
        struct DelegateBridge* PDMFMEFDHMP;
        struct DelegateBridge* MBMHIBGNIKC;
        struct DelegateBridge* KFNKKPLIIKF;
        struct DelegateBridge* EPLNCJFPCNG;
        struct DelegateBridge* CKDMDIFBFMO;
        struct DelegateBridge* APKIONCDHNO;
        struct DelegateBridge* GLBKPNPOPLF;
        struct DelegateBridge* JNOMMDNINDF;
        struct DelegateBridge* JNBKEEAIEGD;
        struct DelegateBridge* PJGIPHAPLHJ;
        struct DelegateBridge* EFCAJLBLGHG;
        struct DelegateBridge* IMDDIJKJBFJ;
        struct DelegateBridge* IDLKNOKFEEG;
        struct DelegateBridge* CIPKGBECGCO;
        struct DelegateBridge* GLOOBCCHAAO;
        struct DelegateBridge* KMNLELOIKCA;
        struct DelegateBridge* GDHONGOIBHA;
        struct DelegateBridge* FKIGDKPILPF;
        struct DelegateBridge* EDOBLDBKOBI;
        struct DelegateBridge* NGEPNKNJCON;
        struct DelegateBridge* CCAAIBGMMJJ;
        struct DelegateBridge* FMFMJABGOPO;
        struct DelegateBridge* MANGFJHPNFG;
        struct DelegateBridge* BHHNILKLEOB;
        struct DelegateBridge* JACGFJLFOPN;
        struct DelegateBridge* OLDOMPNPJKD;
        struct DelegateBridge* OAOLKAIKNEO;
        struct DelegateBridge* IFLMKHFDPEN;
        struct DelegateBridge* DEJIGJPCNJL;
        struct DelegateBridge* BDEDCJFGFMB;
        struct DelegateBridge* AKGNLGBKMJH;
        struct DelegateBridge* LIDLNAGEELP;
        struct DelegateBridge* HDMNGHAJLKO;
        struct DelegateBridge* OHPMGIJHACJ;
        struct DelegateBridge* JLJJNOEPOOP;
        struct DelegateBridge* HDDALELIOOB;
        struct DelegateBridge* HFNDDDAPAHM;
        struct DelegateBridge* OLFOHKMOMLE;
        struct DelegateBridge* FPNDMIOONDK;
        struct DelegateBridge* KBCBMIBDPCE;
        struct DelegateBridge* DJOJBKNPCNM;
        struct DelegateBridge* NIJAAMDNELA;
        struct DelegateBridge* NINDPFAFIDN;
        struct DelegateBridge* NEKKIGGEEEE;
        struct DelegateBridge* EAMDPBHJOOH;
        struct DelegateBridge* LHMKOMMHCNJ;
        struct DelegateBridge* NBOOIECOMOL;
        struct DelegateBridge* BJHLCNJMGCO;
        struct DelegateBridge* PIOBJAHPLBJ;
        struct DelegateBridge* DKPBBLPHGKA;
        struct DelegateBridge* HKCIKDAPFDF;
        struct DelegateBridge* GAJAKCFJFFG;
        struct DelegateBridge* CFJMPGGFPFO;
    };

    struct GameLogin__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct GameLogin__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct GameLogin__VTable vtable;
    };

    struct __declspec(align(8)) GameLogin__Fields {
        struct MMLHJDIKHGO* SocketInfo;
        bool FHAFGBAEEOH;
        struct ConfigChannel* configChannel;
        void* _KLFJDIDIFDO_k__BackingField;
        void* CHJMOFIOEEN;
        void* MLOFGBOKJHB;
        bool _PMMICLMAANC_k__BackingField;
        bool HGPFHBDKCPL;
        bool PIGHNIAKIMF;
        struct IPAddress* ip_backing;
        struct IPAddress* ip;
        struct String* someString;
        uint16_t MIJHJILHMCD;
        bool PKGHNCCBAGD;
        bool CEOEBONMNKB;
        struct DateTime datetime_1;
        struct DateTime datetime_2;
        int32_t EDHEJDIHOEC;
        uint32_t AIOJOKHHMDH;
        void* JLFPPAAJBJH;
        void* LAMGEEIPKJN;
        void* KELHMKAPLCF;
        bool NKKGJMMCINF;
        uint32_t IOIAKODGJAL;
        uint32_t GOGAODGGJJB;
        void* IACEIKHNJAN;
        struct DateTime datetime_3;
        void* OKGJIGGJNOH;
        float FNOLDKFPBLL;
        float PJHHBBICHPD;
        void* coroutine;
        void* coroutines;
        bool NLMICBAEFBO;
        int32_t HBDAKIADBDH;
        bool DPMDLKFJNGJ;
        uint32_t FGKMCOPPLAK;
        int32_t MDIMAAHFFHF;
        void* coroutine_1;
        void* GANBFGNLLDD;
        void* DFFDCKODHEN;
    };

    struct GameLogin {
        struct GameLogin__Class* klass;
        MonitorData* monitor;
        struct GameLogin__Fields fields;
    };

    struct __declspec(align(8)) MAKEGCIBGMD__Fields {
        int32_t OHALFFMCMLN;
        uint8_t CEOMEKMKCDG;
        int32_t JABMLLBAOLE;
    };

    struct GKOJAICIOPA__Fields {
        struct MAKEGCIBGMD__Fields _;
        struct String* string_1;
        struct String* string_2;
        struct String* string_3;
        struct String* string_4;
        struct String* string_5;
        uint32_t DCDMCEEGPHO;
        uint64_t HNNPGFOOOGF;
        bool GJEGPDCKHKC;
        uint32_t OHILLNPMGOG;
        uint32_t PJCAONOLKME;
        struct String* string_6;
        struct String* string_7;
        struct String* string_8;
        uint32_t GLALNAFJNPI;
        bool GFDJDACPNEF;
        uint32_t HGMCFPBHFIP;
        uint32_t MHOMEBNKBMB;
        struct String* string_16;
        struct String* string_9;
        uint32_t IJKANMFMBID;
        void* CJDKDCIPBPF;
        void* EOIAHBHLOOP;
        struct String* string_10;
        uint32_t LIDAFJHHONJ;
        uint32_t PMGDOOKBJND;
        struct String* string_11;
        uint32_t NFNAILJKHNB;
        void* HBMOHKNKCDH;
        struct String* string_12;
        uint32_t BEAOKGHFDLP;
        struct NHHMPCAAKGF* COALKJGFLEJ;
        uint32_t NDJHCJFIKGH;
        struct String* string_13;
        struct String* string_14;
        bool OKOOABLDFNB;
        uint32_t FCOKNAHMKMD;
        uint32_t KOHNHBDBAGH;
        void* HAJNHPHHBJH;
        struct String* string_15;
    };

    struct GKOJAICIOPA {
        void* klass;
        MonitorData* monitor;
        struct GKOJAICIOPA__Fields fields;
    };

    struct Array__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData GetEnumerator;
        VirtualInvokeData Clone;
        VirtualInvokeData System_Collections_ICollection_get_Count;
        VirtualInvokeData get_IsSynchronized;
        VirtualInvokeData get_SyncRoot;
        VirtualInvokeData CopyTo;
        VirtualInvokeData get_IsFixedSize;
        VirtualInvokeData get_IsReadOnly;
        VirtualInvokeData System_Collections_IList_get_Item;
        VirtualInvokeData System_Collections_IList_set_Item;
        VirtualInvokeData System_Collections_IList_Add;
        VirtualInvokeData System_Collections_IList_Clear;
        VirtualInvokeData System_Collections_IList_Contains;
        VirtualInvokeData System_Collections_IList_IndexOf;
        VirtualInvokeData System_Collections_IList_Insert;
        VirtualInvokeData System_Collections_IList_Remove;
        VirtualInvokeData System_Collections_IList_RemoveAt;
    };

    struct Array__StaticFields {
    };

    struct Array__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Array__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Array__VTable vtable;
    };

    struct Array {
        struct Array__Class* klass;
        MonitorData* monitor;
    };

    struct Byte__VTable {
        VirtualInvokeData Equals;
        VirtualInvokeData Finalize;
        VirtualInvokeData GetHashCode;
        VirtualInvokeData ToString;
        VirtualInvokeData ToString_1;
        VirtualInvokeData GetTypeCode;
        VirtualInvokeData System_IConvertible_ToBoolean;
        VirtualInvokeData System_IConvertible_ToByte;
        VirtualInvokeData System_IConvertible_ToChar;
        VirtualInvokeData System_IConvertible_ToDateTime;
        VirtualInvokeData System_IConvertible_ToDecimal;
        VirtualInvokeData System_IConvertible_ToDouble;
        VirtualInvokeData System_IConvertible_ToInt16;
        VirtualInvokeData System_IConvertible_ToInt32;
        VirtualInvokeData System_IConvertible_ToInt64;
        VirtualInvokeData System_IConvertible_ToSByte;
        VirtualInvokeData System_IConvertible_ToSingle;
        VirtualInvokeData ToString_2;
        VirtualInvokeData System_IConvertible_ToType;
        VirtualInvokeData System_IConvertible_ToUInt16;
        VirtualInvokeData System_IConvertible_ToUInt32;
        VirtualInvokeData System_IConvertible_ToUInt64;
        VirtualInvokeData CompareTo;
        VirtualInvokeData CompareTo_1;
        VirtualInvokeData Equals_1;
    };

    struct Byte__StaticFields {
    };

    struct Byte__Class {
        Il2CppClass_0 _0;
        Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
        struct Byte__StaticFields* static_fields;
        const Il2CppRGCTXData* rgctx_data;
        Il2CppClass_1 _1;
        struct Byte__VTable vtable;
    };
#if !defined(_GHIDRA_) && !defined(_IDA_)
}
#endif
