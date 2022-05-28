// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2017.4.15 - 2017.4.40

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************
using namespace app;


// Map hooks
DO_APP_FUNC(0x02E9F9E0, void, InLevelMapPageContext_OnMarkClicked, (InLevelMapPageContext* __this, MonoMapMark* mark, MethodInfo* method));
DO_APP_FUNC(0x02E85EC0, void, InLevelMapPageContext_OnMapClicked, (InLevelMapPageContext* __this, Vector2 screenPos, MethodInfo* method));
DO_APP_FUNC(0x00F0DCE0, bool, MapModule_IsAreaUnlock, (MapModule* __this, uint32_t sceneID, uint32_t areaID, MethodInfo* method));

// changed to:
// DO_APP_FUNC(0x01B0A910, uint16_t, MoleMole_SimpleSafeUInt16_DBDMOONJALD_1, (MoleMole_SimpleSafeUInt16 v, MethodInfo * method));
// DBDMOONJALD => op_Implicit
DO_APP_FUNC(0x01B0A910, uint16_t, SimpleSafeUInt16_get_Value, (SimpleSafeUInt16 v, MethodInfo* method));
DO_APP_FUNC(0x0400F280, uint32_t, SimpleSafeUInt32_get_Value, (SimpleSafeUInt32 v, MethodInfo* method));

// Map utility
DO_APP_FUNC(0x00E866B0, Rect, MonoInLevelMapPage_get_mapRect, (MonoInLevelMapPage* __this, MethodInfo* method));
DO_APP_FUNC(0x00E86680, Transform*, MonoInLevelMapPage_get_mapBackground, (MonoInLevelMapPage* __this, MethodInfo* method));


// Teleport hooks
DO_APP_FUNC(0x028AD260, void, GameManager_Update, (GameManager* __this, MethodInfo* method));
DO_APP_FUNC(0x01F54110, void, LoadingManager_SceneGoto, (LoadingManager* __this, PlayerEnterSceneNotify* notify, MethodInfo* method));
DO_APP_FUNC(0x01F55300, void, LoadingManager_PerformPlayerTransmit, (LoadingManager* __this, Vector3 targetPos, EnterType__Enum enterType, uint32_t token, EvtTransmitAvatar_EvtTransmitAvatar_TransmitType__Enum transType, uint32_t enterReason, MethodInfo* method));
DO_APP_FUNC(0x01F563C0, void, LoadingManager_RequestSceneTransToPoint, (LoadingManager* __this, uint32_t sceneId, uint32_t pointId, void* finishCallBackInForceDrag, MethodInfo* method));
DO_APP_FUNC(0x01F57E60, bool, LoadingManager_NeedTransByServer, (LoadingManager* __this, uint32_t sceneId, Vector3 position, MethodInfo* method));
DO_APP_FUNC(0x0104A6D0, Vector3, LocalEntityInfoData_get_initPos, (LocalEntityInfoData* __this, MethodInfo* method)); // shared offset


// Unlimited stamina
DO_APP_FUNC(0x01F17820, void, LevelSyncCombatPlugin_RequestSceneEntityMoveReq, (LevelSyncCombatPlugin* __this, uint32_t entityId, MotionInfo* syncInfo, bool isReliable, uint32_t HAOCOEMOMBG, MethodInfo* method));
DO_APP_FUNC(0x016189E0, void, DataItem_HandleNormalProp, (DataItem* __this, uint32_t type, int64_t value, DataPropOp__Enum state, MethodInfo* method));


// God mode
DO_APP_FUNC(0x027DB100, void, VCHumanoidMove_NotifyLandVelocity, (VCHumanoidMove* __this, Vector3 velocity, float reachMaxDownVelocityTime, MethodInfo* method));
DO_APP_FUNC(0x036889B0, bool, Miscs_CheckTargetAttackable, (void* __this, BaseEntity* attackerEntity, BaseEntity* targetEntity, MethodInfo* method));
// DO_APP_FUNC(0x00D0CA90, void, LCBaseCombat_FireBeingHitEvent, (LCBaseCombat* __this, uint32_t attackeeRuntimeID, AttackResult* attackResult, MethodInfo* method));


// Cooldown cheats
DO_APP_FUNC(0x00C69910, bool, HumanoidMoveFSM_CheckSprintCooldown, (/* HumanoidMoveFSM */void* __this, MethodInfo* method));
DO_APP_FUNC(0x01530C80, bool, LCAvatarCombat_IsEnergyMax, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x01530480, void, LCAvatarCombat_ChangeEnergy_1, (LCAvatarCombat* __this, ElementType__Enum type, float value, DataPropOp__Enum state, MethodInfo* method));
DO_APP_FUNC(0x0152DC10, bool, LCAvatarCombat_OnSkillStart, (LCAvatarCombat* __this, uint32_t skillID, float cdMultipler, MethodInfo* method));
DO_APP_FUNC(0x01530210, bool, LCAvatarCombat_IsSkillInCD_1, (LCAvatarCombat* __this, LCAvatarCombat_OMIIMOJOHIP* skillInfo, MethodInfo* method));

DO_APP_FUNC(0x02385800, void, ActorAbilityPlugin_AddDynamicFloatWithRange, (void* __this, String* key, float value, float min, float max, bool forceDoAtRemote, MethodInfo* method));

// Rapid fire
DO_APP_FUNC(0x00D12040, void, LCBaseCombat_DoHitEntity, (LCBaseCombat* __this, uint32_t targetID, AttackResult* attackResult, bool ignoreCheckCanBeHitInMP, MethodInfo* method));
DO_APP_FUNC(0x01F0D930, void, Formula_CalcAttackResult, (CombatProperty* attackCombatProperty, CombatProperty* defenseCombatProperty, AttackResult* attackResult, BaseEntity* attackerEntity, BaseEntity* attackeeEntity, MethodInfo* method));


// World cheats
DO_APP_FUNC(0x022C3450, void, VCMonsterAIController_TryDoSkill, (/* VCMonsterAIController */ void* __this, uint32_t skillID, MethodInfo* method)); // Manual
DO_APP_FUNC(0x020FA730, void, LCSelectPickup_AddInteeBtnByID, (void* __this, BaseEntity* entity, MethodInfo* method));
DO_APP_FUNC(0x020FA090, bool, LCSelectPickup_IsInPosition, (void* __this, BaseEntity* entity, MethodInfo* method));
DO_APP_FUNC(0x020FC120, bool, LCSelectPickup_IsOutPosition, (void* __this, BaseEntity* entity, MethodInfo* method));
DO_APP_FUNC(0x0219B8E0, void, ItemModule_PickItem, (ItemModule* __this, uint32_t entityID, MethodInfo* method));
DO_APP_FUNC(0x00C2F710, void, LevelSceneElementViewPlugin_Tick, (LevelSceneElementViewPlugin* __this, float inDeltaTime, MethodInfo* method));


// Dialog skipping
DO_APP_FUNC(0x00F95350, bool, TalkDialogContext_get_canClick, (TalkDialogContext* __this, MethodInfo* method)); // delete
DO_APP_FUNC(0x00F932D0, bool, TalkDialogContext_get_canAutoClick, (TalkDialogContext* __this, MethodInfo* method));
DO_APP_FUNC(0x00F97D70, void, TalkDialogContext_OnDialogSelectItem, (TalkDialogContext* __this, Notify* notify, MethodInfo* method));
DO_APP_FUNC(0x02BF0040, void, InLevelCutScenePageContext_OnFreeClick, (InLevelCutScenePageContext* __this, MethodInfo* method));
DO_APP_FUNC(0x02BF1AC0, void, InLevelCutScenePageContext_UpdateView, (InLevelCutScenePageContext* __this, MethodInfo* method));
DO_APP_FUNC(0x02BEF110, void, InLevelCutScenePageContext_ClearView, (InLevelCutScenePageContext* __this, MethodInfo* method));


// Protection bypass
DO_APP_FUNC(0x066218D0, Byte__Array*, Application_RecordUserData, (int32_t nType, MethodInfo* method));


// Networking
DO_APP_FUNC(0x012519C0, int32_t, KcpNative_kcp_client_send_packet, (void* kcp_client, KcpPacket_1* packet, MethodInfo* method));
DO_APP_FUNC(0x00BD08A0, bool, KcpClient_TryDequeueEvent, (void* __this, ClientKcpEvent* evt, MethodInfo* method));
DO_APP_FUNC(0x029C3D60, void, Packet_XorEncrypt, (Byte__Array** bytes, int32_t length, MethodInfo* method));


// Lua functions
DO_APP_FUNC(0x02D59730, Byte__Array*, LuaManager_LoadCustomLuaFile, (LuaManager* __this, String** filePath, bool* recycleBytes, MethodInfo* method));
DO_APP_FUNC(0x0655E850, void, Lua_xlua_pushasciistring, (void* L, String* str, MethodInfo* method));
DO_APP_FUNC(0x01D8D5D0, void, LuaShellManager_DoString, (void* __this, Byte__Array* byteArray, MethodInfo* method));
DO_APP_FUNC(0x0600AFF0, void*, LuaEnv_DoString, (void* __this, Byte__Array* chunk, String* chunkName, void* env, MethodInfo* method));
DO_APP_FUNC(0x01D8DCA0, void, LuaShellManager_ReportLuaShellResult, (void* __this, String* type, String* value, MethodInfo* method)); // Anticheat info


// Debug hooks
DO_APP_FUNC(0x02D3FA40, AttackResult_1*, AttackResult_FillProtoAttackResult, (AttackResult* __this, uint32_t attackerID, uint32_t defenseId, AttackResult_1* protoAttackResult, MethodInfo* method));
DO_APP_FUNC(0x01F16210, void, LevelSyncCombatPlugin_SendFaceToDir, (void* __this, uint32_t runtimeID, Vector3 forward, MethodInfo* method));
DO_APP_FUNC(0x035D4180, void, BaseEntity_FireEvent, (BaseEntity* __this, BaseEvent* e, bool immediately, MethodInfo* method));
DO_APP_FUNC(0x023D4A90, bool, ActorAbilityPlugin_OnEvent, (void* __this, BaseEvent* e, MethodInfo* method));


// Kill aura
DO_APP_FUNC(0x00B8EB30, void, EvtCrash_Init, (EvtCrash* __this, uint32_t targetID, MethodInfo* method)); // Manual offset
DO_APP_FUNC(0x00941E80, void, EventManager_FireEvent, (EventManager* __this, BaseEvent* e, bool immediately, MethodInfo* method));
DO_APP_FUNC(0x0167B1A0, bool, FixedBoolStack_get_value, (FixedBoolStack* __this, MethodInfo* method));

// cannot find actual function name: CreateCrashEvent
// shared offset
// possible:
// DO_APP_FUNC(0x039E2030, MoleMole_EvtCrash_1 *, JDGMIDCLFJK_CNCAIAIACLN_103, (MethodInfo * method));
DO_APP_FUNC(0x039E2030, EvtCrash*, CreateCrashEvent, (MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x0971A140, CreateCrashEvent__MethodInfo);

DO_APP_FUNC(0x034BC360, void, BaseMoveSyncPlugin_ConvertSyncTaskToMotionInfo, (BaseMoveSyncPlugin* __this, MethodInfo* method));


// Fishing
DO_APP_FUNC(0x0292F8D0, void, FishingModule_RequestFishCastRod, (void* __this, uint32_t baitId, uint32_t rodId, Vector3 pos, uint32_t rodEntityId, MethodInfo* method));

DO_APP_FUNC(0x0292D6D0, void, FishingModule_RequestFishBite, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x02930440, void, FishingModule_OnFishBiteRsp, (void* __this, FishBiteRsp* rsp, MethodInfo* method));

DO_APP_FUNC(0x0292F470, void, FishingModule_RequestFishBattleBegin, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x0292CAE0, void, FishingModule_OnFishBattleBeginRsp, (void* __this, FishBattleBeginRsp* rsp, MethodInfo* method));

DO_APP_FUNC(0x0292D090, void, FishingModule_RequestFishBattleEnd, (void* __this, FishBattleResult__Enum result, bool isAlwaysBonus, float mxBonusTime, MethodInfo* method));
DO_APP_FUNC(0x0292DBD0, void, FishingModule_OnFishBattleEndRsp, (void* __this, FishBattleEndRsp* rsp, MethodInfo* method));

DO_APP_FUNC(0x0292F190, void, FishingModule_OnExitFishingRsp, (void* __this, void* rsp, MethodInfo* method));
DO_APP_FUNC(0x0292C7F0, void, FishingModule_onFishChosenNotify, (void* __this, void* notify, MethodInfo* method));


// Visuals
DO_APP_FUNC(0x013FC090, void, SCameraModuleInitialize_SetWarningLocateRatio, (SCameraModuleInitialize* __this, double deltaTime, CameraShareData* data, MethodInfo* method));

// Chest Indicator | RyujinZX#6666
DO_APP_FUNC(0x04C9B450, bool, LCIndicatorPlugin_DoCheck, (LCIndicatorPlugin* __this, MethodInfo* method));
DO_APP_FUNC(0x04C9B830, void, LCIndicatorPlugin_ShowIcon, (LCIndicatorPlugin* __this, MethodInfo* method));
DO_APP_FUNC(0x04C9A750, void, LCIndicatorPlugin_HideIcon, (LCIndicatorPlugin* __this, MethodInfo* method));

// Auto Cooking | RyujinZX#6666
DO_APP_FUNC(0x02854E30, void, PlayerModule_RequestPlayerCook, (PlayerModule* __this, uint32_t recipeId, uint32_t avatarId, uint32_t qteQuality, uint32_t count, MethodInfo* method));
DO_APP_FUNC(0x02858180, void, PlayerModule_OnPlayerCookRsp, (PlayerModule* __this, PlayerCookRsp* rsp, MethodInfo* method));
DO_APP_FUNC(0x033F5820, void, CookingQtePageContext_UpdateProficiency, (CookingQtePageContext* __this, MethodInfo* method));
DO_APP_FUNC(0x0116AA10, uint32_t, CookRecipeExcelConfig_get_maxProficiency, (CookRecipeExcelConfig* __this, MethodInfo* method));


// Utility
DO_APP_FUNC(0x036865D0, float, Miscs_CalcCurrentGroundWaterHeight, (float x, float z, MethodInfo* method));
DO_APP_FUNC(0x03685E00, float, Miscs_CalcCurrentGroundHeight, (float x, float z, MethodInfo* method));
DO_APP_FUNC(0x03685F10, float, Miscs_CalcCurrentGroundHeight_1, (float x, float z, float rayStartHeight, float rayDetectLength, int32_t layer, MethodInfo* method));
DO_APP_FUNC(0x03686170, Vector3, Miscs_CalcCurrentGroundNorm, (Vector3 pos, MethodInfo* method));
DO_APP_FUNC(0x01A4E0E0, Vector3, Miscs_GenWorldPos, (Vector2 levelMapPos, MethodInfo* method));
DO_APP_FUNC(0x01A4DA90, Vector2, Miscs_GenLevelPos_1, (Vector3 worldPos, MethodInfo* method));
DO_APP_FUNC(0x0369D590, int32_t, Miscs_GetSceneGroundLayerMask, (MethodInfo* method));

DO_APP_FUNC(0x056202E0, Vector3, WorldShiftManager_GetRelativePosition, (Vector3 pos, MethodInfo* method));
DO_APP_FUNC(0x05620130, Vector3, WorldShiftManager_GetAbsolutePosition, (Vector3 pos, MethodInfo* method));

DO_APP_FUNC(0x02DAB410, Vector3, ActorUtils_GetAvatarPos, (MethodInfo* method));
DO_APP_FUNC(0x02DAF680, void, ActorUtils_SetAvatarPos, (Vector3 pos, MethodInfo* method));
DO_APP_FUNC(0x02DB0AF0, void, ActorUtils_SyncAvatarMotion, (int32_t state, MethodInfo* method));

DO_APP_FUNC(0x01AA5200, Notify, Notify_CreateNotify_1, (MoleMole_NotifyTypes__Enum type, Object* body, MethodInfo* method));

// DO_APP_FUNC(0x020C7AA0, float, MoleMole_SafeFloat_DBDMOONJALD_1, (MoleMole_SafeFloat v, MethodInfo * method));
// DBDMOONJALD => op_Implicit
DO_APP_FUNC(0x020C7AA0, float, SafeFloat_GetValue, (SafeFloat safeFloat, MethodInfo* method));
// DO_APP_FUNC(0x020C7920, MoleMole_SafeFloat, MoleMole_SafeFloat_DBDMOONJALD, (float IGFNEICJINB, MethodInfo * method));
DO_APP_FUNC(0x020C7920, SafeFloat, SafeFloat_SetValue, (float value, MethodInfo* method));

DO_APP_FUNC(0x035AC7B0, void, Entity_SetRelativePosition, (BaseEntity* __this, Vector3 position, bool forceSyncToRigidbody, MethodInfo* method));

//DO_APP_FUNC(0x039E2290, MoleMole_LCBaseCombat *, MoleMole_BaseEntity_GetLogicCombatComponent_1, (MoleMole_BaseEntity * __this, MethodInfo * method));
DO_APP_FUNC(0x039E2290, LCBaseCombat*, BaseEntity_GetBaseCombat, (BaseEntity* __this, MethodInfo* method));

DO_APP_FUNC(0x035CC430, String*, BaseEntity_ToStringRelease, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035AC7B0, void, BaseEntity_SetRelativePosition, (BaseEntity* __this, Vector3 position, bool forceSyncToRigidbody, MethodInfo* method));
DO_APP_FUNC(0x035C0AA0, void, BaseEntity_SetAbsolutePosition, (BaseEntity* __this, Vector3 abpos, bool forceSyncToRigidbody, MethodInfo* method));
DO_APP_FUNC(0x035C4B00, Vector3, BaseEntity_GetAbsolutePosition, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035C3950, Vector3, BaseEntity_GetRelativePosition, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035B1EF0, Vector3, BaseEntity_GetForward, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035D4BA0, Vector3, BaseEntity_GetForwardFast, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035C08A0, Vector3, BaseEntity_GetRight, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035CB210, Vector3, BaseEntity_GetUp, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035D5B30, bool, BaseEntity_IsActive, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035C7A50, Rigidbody*, BaseEntity_GetRigidbody, (BaseEntity* __this, MethodInfo* method));

//DO_APP_FUNC(0x039E22C0, MoleMole_VCBaseMove_1 *, MoleMole_BaseEntity_GetMoveComponent_1, (MoleMole_BaseEntity * __this, MethodInfo * method));
DO_APP_FUNC(0x039E22C0, VCBaseMove*, BaseEntity_GetMoveComponent_1, (BaseEntity* __this, MethodInfo* method)); // double check

DO_APP_FUNC(0x035C3850, List_1_MoleMole_BaseComponent_*, BaseEntity_GetAllLogicComponents, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x0187FDC0, GameObject*, BaseEntity_get_gameObject, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC(0x035ACC70, GameObject*, BaseEntity_get_rootGameObject, (BaseEntity* __this, MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x096EE7D8, BaseEntity_GetMoveComponent_1__MethodInfo);

//DO_APP_FUNC_METHODINFO(0x096EF950, MoleMole_BaseEntity_GetLogicCombatComponent_1__MethodInfo); // double check
DO_APP_FUNC_METHODINFO(0x096EF950, BaseEntity_GetBaseCombat__MethodInfo);

// check comparison from 2.2 & 2.6
// function type & name is wrong
// DO_APP_FUNC(0, MoleMole_AvatarEntity *, MoleMole_EntityManager_GetLocalAvatarEntity, (MoleMole_EntityManager * __this, MethodInfo * method));
DO_APP_FUNC(0x01BF68A0, BaseEntity*, EntityManager_GetCurrentAvatar, (EntityManager* __this, MethodInfo* method));

DO_APP_FUNC(0x01BF4E50, CameraEntity*, EntityManager_GetMainCameraEntity, (EntityManager* __this, MethodInfo* method));
DO_APP_FUNC(0x01BEB030, BaseEntity*, EntityManager_GetValidEntity, (EntityManager* __this, uint32_t runtimeID, MethodInfo* method));
DO_APP_FUNC(0x01C02920, bool, EntityManager_RemoveEntity, (EntityManager* __this, BaseEntity* entity, uint32_t specifiedRuntimeID, MethodInfo* method));
DO_APP_FUNC(0x01C02800, bool, EntityManager_IsCachedEntity, (EntityManager* __this, BaseEntity* entity, MethodInfo* method));
DO_APP_FUNC(0x01BF01F0, List_1_MoleMole_BaseEntity_*, EntityManager_GetEntities, (EntityManager* __this, MethodInfo* method));

// check comparison with 2.6
// function name changed to:
// DO_APP_FUNC(0, Bounds, Utils_4_GetBounds, (GameObject * go, MethodInfo * method));
DO_APP_FUNC(0x044B8970, Bounds, Utils_4_GetBounds, (GameObject* go, MethodInfo* method));

// Modify | RyujinZX#6666
DO_APP_FUNC(0x00C6C780, void, HumanoidMoveFSM_LateTick, (HumanoidMoveFSM* __this, float deltaTime, MethodInfo* method));

DO_APP_FUNC(0x01DD2070, bool, ScenePropManager_GetTreeTypeByPattern, (ScenePropManager* __this, String* pattern, MoleMole_Config_TreeType__Enum* treeType, MethodInfo* method));

DO_APP_FUNC(0x00C3F160, void, NetworkManager_1_RequestHitTreeDropNotify, (NetworkManager_1* __this, Vector3 position, Vector3 hitPostion, MoleMole_Config_TreeType__Enum treeType, MethodInfo* method));
DO_APP_FUNC(0x0291FEF0, uint64_t, TimeUtil_get_NowTimeStamp, (MethodInfo* method));

DO_APP_FUNC(0x01F5BA10, bool, LoadingManager_IsLoaded, (LoadingManager* __this, MethodInfo* method));

// Thanks to | RyujinZX
DO_APP_FUNC(0x01337F70, void, LCAbilityElement_ReduceModifierDurability, (LCAbilityElement* __this, int32_t modifierDurabilityIndex, float reduceDurability, Nullable_1_Single_ deltaTime, MethodInfo* method));

DO_APP_FUNC(0x01FF2880, BaseEntity*, GadgetEntity_GetOwnerEntity, (GadgetEntity* __this, MethodInfo* method));

DO_APP_FUNC(0x02E826A0, void, InLevelMapPageContext_ZoomMap, (InLevelMapPageContext* __this, float value, MethodInfo* method));
DO_APP_FUNC(0x02EC7730, void, InLevelMapPageContext_UpdateView, (InLevelMapPageContext* __this, MethodInfo* method));

DO_APP_FUNC(0x01A36960, bool, UIManager_HasEnableMapCamera, (UIManager* __this, MethodInfo* method));

DO_APP_FUNC(0x00E8E700, void, MonoMiniMap_Update, (MonoMiniMap* __this, MethodInfo* method));
DO_APP_FUNC(0x0635A470, MonoMiniMap*, MonoInLevelMainPage_get_miniMap, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x024A3570, void, GadgetModule_OnGadgetInteractRsp, (void* __this, GadgetInteractRsp* notify, MethodInfo* method));
DO_APP_FUNC(0x00A8D650, float, InLevelMainPageContext_get_miniMapScale, (InLevelMainPageContext* __this, MethodInfo* method));


// UnityEngine
DO_APP_FUNC(0x065ECB70, void, RenderSettings_set_fog, (void* __this, bool value, MethodInfo* method));
DO_APP_FUNC(0x06621FF0, void, Application_set_targetFrameRate, (void* __this, int32_t value, MethodInfo* method));
DO_APP_FUNC(0x06621D80, int32_t, Application_get_targetFrameRate, (void* __this, MethodInfo* method));

DO_APP_FUNC(0x06678780, bool, RectTransformUtility_ScreenPointToLocalPointInRectangle, (void* __this, void* rect, Vector2 screenPoint, void* cam, Vector2* localPoint, MethodInfo* method));

DO_APP_FUNC(0x06555BA0, Vector3, Transform_get_position, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x065548F0, void, Transform_set_position, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x0664E3A0, float, Vector3_Distance, (Vector3 a, Vector3 b, MethodInfo* method));
DO_APP_FUNC(0x06534FE0, float, Vector2_Distance, (Vector2 a, Vector2 b, MethodInfo* method));

DO_APP_FUNC(0x0658F980, void, Cursor_set_visible, (bool value, MethodInfo* method));
DO_APP_FUNC(0x0658F970, void, Cursor_set_lockState, (CursorLockMode__Enum value, MethodInfo* method));
DO_APP_FUNC(0x0658F960, bool, Cursor_get_visible, (MethodInfo* method));

DO_APP_FUNC(0x064B3A00, void, Rigidbody_set_detectCollisions, (Rigidbody* __this, bool value, MethodInfo* method));
DO_APP_FUNC(0x064B3A40, void, Rigidbody_set_isKinematic, (Rigidbody* __this, bool value, MethodInfo* method));
DO_APP_FUNC(0x064B3740, void, Rigidbody_set_velocity, (Rigidbody* __this, Vector3 value, MethodInfo* method));

DO_APP_FUNC(0x06631190, float, Time_get_timeScale, (MethodInfo* method));
DO_APP_FUNC(0x06631240, void, Time_set_timeScale, (float value, MethodInfo* method));
DO_APP_FUNC(0x066310B0, float, Time_get_deltaTime, (MethodInfo* method));

DO_APP_FUNC(0x06594F40, Vector3, Camera_WorldToScreenPoint, (Camera* __this, Vector3 position, MethodInfo* method));
DO_APP_FUNC(0x06595270, Camera*, Camera_get_main, (MethodInfo* method));
DO_APP_FUNC(0x065953B0, int32_t, Camera_get_pixelWidth, (Camera* __this, MethodInfo* method));
DO_APP_FUNC(0x06595360, int32_t, Camera_get_pixelHeight, (Camera* __this, MethodInfo* method));

DO_APP_FUNC(0x06533CA0, int32_t, Screen_get_width, (MethodInfo* method));
DO_APP_FUNC(0x06533C30, int32_t, Screen_get_height, (MethodInfo* method));

DO_APP_FUNC(0x0664CF50, bool, Behaviour_get_isActiveAndEnabled, (Behaviour* __this, MethodInfo* method));

DO_APP_FUNC(0x066309A0, Vector3, Quaternion_get_eulerAngles, (Quaternion__Boxed* __this, MethodInfo* method));
DO_APP_FUNC(0x06555C70, Quaternion, Transform_get_rotation, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x06552F50, Rect, RectTransform_get_rect, (RectTransform* __this, MethodInfo* method));
DO_APP_FUNC(0x06677BD0, float, Canvas_get_scaleFactor, (/*Canvas**/void* __this, MethodInfo* method));


// Singletons
DO_APP_FUNC(0x05189A90, void*, Singleton_GetInstance, (void* __this, MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x096EE180, Singleton_1_MapModule__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096EE1C0, Singleton_1_LoadingManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096EA380, Singleton_1_EntityManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096EB1E8, Singleton_1_InteractionManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096FAE70, Singleton_1_MessageInfo__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096EA278, Singleton_1_UIManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096ED720, Singleton_1_ItemModule__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096EB530, Singleton_1_EventManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096EA298, Singleton_1_PlayerModule__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096EA4F8, Singleton_1_MapManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096ECB80, Singleton_1_ScenePropManager__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x096EA9A8, Singleton_1_NetworkManager_1__get_Instance__MethodInfo);

