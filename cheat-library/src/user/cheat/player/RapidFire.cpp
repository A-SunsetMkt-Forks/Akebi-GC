#include "pch-il2cpp.h"
#include "RapidFire.h"

#include <helpers.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/util.h>
#include <cheat/game/filters.h>

namespace cheat::feature
{
	//static void LCBaseCombat_DoHitEntity_Hook(app::LCBaseCombat* __this, uint32_t targetID, app::AttackResult* attackResult, bool ignoreCheckCanBeHitInMP, MethodInfo* method);
	static void VCAnimatorEvent_HandleProcessItem_Hook(app::MoleMole_VCAnimatorEvent* __this,
		app::MoleMole_VCAnimatorEvent_MoleMole_VCAnimatorEvent_AnimatorEventPatternProcessItem* processItem,
		app::AnimatorStateInfo processStateInfo, app::MoleMole_VCAnimatorEvent_MoleMole_VCAnimatorEvent_TriggerMode__Enum mode, MethodInfo* method);
	static void LCBaseCombat_FireBeingHitEvent_Hook(app::LCBaseCombat* __this, uint32_t attackeeRuntimeID, app::AttackResult* attackResult, MethodInfo* method);

	static int32_t attackTags[] = {
		1638193991, // Normal and Charged
		1498431743, // Plunge
		-584054938, 0, // Skill, Burst and Charged Bow Release
	};

	RapidFire::RapidFire() : Feature(),
		NF(f_Enabled, "Attack Multiplier", "RapidFire", false),
		NF(f_MultiHit, "Multi-hit", "RapidFire", false),
		NF(f_Multiplier, "Hit Multiplier", "RapidFire", 2),
		NF(f_OnePunch, "One Punch Mode", "RapidFire", false),
		NF(f_Randomize, "Randomize", "RapidFire", false),
		NF(f_minMultiplier, "Min Multiplier", "RapidFire", 1),
		NF(f_maxMultiplier, "Max Multiplier", "RapidFire", 3),
		NF(f_MultiTarget, "Multi-target", "RapidFire", false),
		NF(f_MultiTargetRadius, "Multi-target Radius", "RapidFire", 20.0f),
		NF(f_MultiAnimation, "Multi-animation", "RapidFire", false),
		NF(f_AnimationMultiplier, "Animation Multiplier", "RapidFire", 100),
		NF(f_AnimationState, "Animation State", "RapidFire", 0.5f),
		NF(f_AttackSpeed, "Attack Speed", "RapidFire", false),
		NF(f_SpeedMultiplier, "Speed Multiplier", "RapidFire", 1.5f),
		animationCounter(1)
	{
		// HookManager::install(app::MoleMole_LCBaseCombat_DoHitEntity, LCBaseCombat_DoHitEntity_Hook); -- Looks like FireBeingHitEvent is superior to this.
		HookManager::install(app::MoleMole_VCAnimatorEvent_HandleProcessItem, VCAnimatorEvent_HandleProcessItem_Hook);
		HookManager::install(app::MoleMole_LCBaseCombat_FireBeingHitEvent, LCBaseCombat_FireBeingHitEvent_Hook);
	}

	const FeatureGUIInfo& RapidFire::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Attack Effects", "Player", true };
		return info;
	}

	void RapidFire::DrawMain()
	{
		ConfigWidget("Enabled", f_Enabled, "Enables attack multipliers. Need to choose a mode to work.");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), "Choose any or both modes below.");

		ConfigWidget("Multi-hit Mode", f_MultiHit, "Enables multi-hit.\n" \
			"Multiplies your attack count.\n" \
			"This is not well tested, and can be detected by anticheat.\n" \
			"Not recommended to be used with main accounts or used with high values.\n");

		ImGui::Indent();

		ConfigWidget("One-Punch Mode", f_OnePunch, "Calculate how many attacks needed to kill an enemy based on their HP\n" \
			"and uses that to set the multiplier accordingly.\n" \
			"May be safer, but multiplier calculation may not be on-point.");

		ConfigWidget("Randomize Multiplier", f_Randomize, "Randomize multiplier between min and max multiplier.");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), "This will override One-Punch Mode!");

		if (!f_OnePunch) {
			if (!f_Randomize)
			{
				ConfigWidget("Multiplier", f_Multiplier, 1, 2, 1000, "Attack count multiplier.");
			}
			else
			{
				ConfigWidget("Min Multiplier", f_minMultiplier, 1, 1, 1000, "Attack count minimum multiplier.");
				ConfigWidget("Max Multiplier", f_maxMultiplier, 1, 2, 1000, "Attack count maximum multiplier.");
			}
		}

		ImGui::Unindent();

		ConfigWidget("Multi-target", f_MultiTarget, "Enables multi-target attacks within specified radius of target.\n" \
			"All valid targets around initial target will be hit based on setting.\n" \
			"Damage numbers will only appear on initial target but all valid targets are damaged.\n" \
			"If multi-hit is off and there are still multiple numbers on a single target, check the Entity Manager in the Debug section to see if there are invisible entities.\n" \
			"This can cause EXTREME lag and quick bans if used with multi-hit. You are warned."
		);

		ImGui::Indent();
		ConfigWidget("Radius (m)", f_MultiTargetRadius, 0.1f, 5.0f, 50.0f, "Radius to check for valid targets.");
		ImGui::Unindent();

		ConfigWidget("Multi-animation", f_MultiAnimation, "Enables multi-animation attacks.\n" \
			"Do keep in mind that the character's audio will also be spammed.");
		ConfigWidget("Animation Multiplier", f_AnimationMultiplier, 1, 1, 150, "Configure to how many times it will update the animation state.\n" \
			"Results can vary alongside Animation State");
		ConfigWidget("Animation State", f_AnimationState, 0.01f, 0.f, 2.f, "Animation state to replay.\n"\
			"Results can vary alongside Animation Multiplier");
		ConfigWidget("Attack Speed", f_AttackSpeed, "Enables fast animation attacks.\n");
		ConfigWidget("Speed Multiplier", f_SpeedMultiplier, 0.1f, 1.0f, 5.0f, "Attack speed multiplier.");
	}

	bool RapidFire::NeedStatusDraw() const
	{
		return (f_Enabled && (f_MultiHit || f_MultiTarget)) || f_MultiAnimation || f_AttackSpeed;
	}

	void RapidFire::DrawStatus()
	{
		if (f_Enabled) {
			ImGui::Text("Rapid Fire:");
			if (f_MultiHit)
			{
				if (f_Randomize)
					ImGui::Text("Multi-Hit Random[%d|%d]", f_minMultiplier.value(), f_maxMultiplier.value());
				else if (f_OnePunch)
					ImGui::Text("Multi-Hit [OnePunch]");
				else
					ImGui::Text("Multi-Hit [%d]", f_Multiplier.value());
			}
			if (f_MultiTarget)
				ImGui::Text("Multi-Target [%.01fm]", f_MultiTargetRadius.value());
		}

		if (f_MultiAnimation)
			ImGui::Text("Multi-Animation [%d|%0.2f]", f_AnimationMultiplier.value(), f_AnimationState.value());
		if(f_AttackSpeed)
			ImGui::Text("Attack Speed [%0.1f]", f_SpeedMultiplier.value());
	}

	RapidFire& RapidFire::GetInstance()
	{
		static RapidFire instance;
		return instance;
	}

	int RapidFire::CalcCountToKill(float attackDamage, uint32_t targetID)
	{
		if (attackDamage == 0)
			return f_Multiplier;

		auto& manager = game::EntityManager::instance();
		auto targetEntity = manager.entity(targetID);
		if (targetEntity == nullptr)
			return f_Multiplier;

		auto baseCombat = targetEntity->combat();
		if (baseCombat == nullptr)
			return f_Multiplier;

		auto safeHP = baseCombat->fields._combatProperty_k__BackingField->fields.HP;
		auto HP = app::MoleMole_SafeFloat_get_Value(safeHP, nullptr);
		int attackCount = (int)ceil(HP / attackDamage);
		return std::clamp(attackCount, 1, 200);
	}

	int RapidFire::GetAttackCount(app::LCBaseCombat* combat, uint32_t targetID, app::AttackResult* attackResult)
	{
		if (!f_MultiHit)
			return 1;

		auto& manager = game::EntityManager::instance();
		auto targetEntity = manager.entity(targetID);
		auto baseCombat = targetEntity->combat();
		if (baseCombat == nullptr)
			return 1;

		int countOfAttacks = f_Multiplier;
		if (f_OnePunch)
		{
			app::MoleMole_Formula_CalcAttackResult(combat->fields._combatProperty_k__BackingField,
				baseCombat->fields._combatProperty_k__BackingField,
				attackResult, manager.avatar()->raw(), targetEntity->raw(), nullptr);
			countOfAttacks = CalcCountToKill(attackResult->fields.damage, targetID);
		}
		if (f_Randomize)
		{
			if (f_minMultiplier.value() >= f_maxMultiplier.value()) 
				countOfAttacks = f_minMultiplier.value();
			else
				countOfAttacks = rand() % (f_maxMultiplier.value() - f_minMultiplier.value()) + f_minMultiplier.value();
			return countOfAttacks;
		}

		return countOfAttacks;
	}

	bool IsAvatarOwner(game::Entity entity)
	{
		auto& manager = game::EntityManager::instance();
		auto avatarID = manager.avatar()->runtimeID();

		while (entity.isGadget())
		{
			game::Entity temp = entity;
			entity = game::Entity(app::MoleMole_GadgetEntity_GetOwnerEntity(reinterpret_cast<app::GadgetEntity*>(entity.raw()), nullptr));
			if (entity.runtimeID() == avatarID)
				return true;
		}

		return false;

	}

	bool IsAttackByAvatar(game::Entity& attacker)
	{
		if (attacker.raw() == nullptr)
			return false;

		auto& manager = game::EntityManager::instance();
		auto avatarID = manager.avatar()->runtimeID();
		auto attackerID = attacker.runtimeID();

		return attackerID == avatarID || IsAvatarOwner(attacker);
	}

	bool IsConfigByAvatar(game::Entity& attacker)
	{
		if (attacker.raw() == nullptr)
			return false;

		auto& manager = game::EntityManager::instance();
		auto patterID = manager.avatar()->combat()->monitor;
		auto avatarID = manager.avatar()->raw()->fields._configID_k__BackingField;
		auto attackerID = attacker.raw()->fields._configID_k__BackingField;
		// LOG_DEBUG("configID = %d", attackerID);
		// Taiga#5555: IDs can be found in ConfigAbility_Avatar_*.json or GadgetExcelConfigData.json
		bool bulletID = attackerID >= 40000160 && attackerID <= 41079999;

		return avatarID == attackerID || bulletID || attacker.type() == app::EntityType__Enum_1::Bullet;
	}

	bool IsValidByFilter(game::Entity* entity)
	{
		if (game::filters::combined::OrganicTargets.IsValid(entity) ||
			game::filters::monster::SentryTurrets.IsValid(entity) ||
			game::filters::combined::Ores.IsValid(entity) ||
			game::filters::puzzle::Geogranum.IsValid(entity) ||
			game::filters::puzzle::LargeRockPile.IsValid(entity) ||
			game::filters::puzzle::SmallRockPile.IsValid(entity))
			return true;
		return false;
	}

	// Raises when any entity do hit event.
	// Just recall attack few times (regulating by combatProp)
	// It's not tested well, so, I think, anticheat can detect it.
	/*static void LCBaseCombat_DoHitEntity_Hook(app::LCBaseCombat* __this, uint32_t targetID, app::AttackResult* attackResult, bool ignoreCheckCanBeHitInMP, MethodInfo* method)
	{
		auto attacker = game::Entity(__this->fields._._._entity);
		RapidFire& rapidFire = RapidFire::GetInstance();
		if (!IsConfigByAvatar(attacker) || !IsAttackByAvatar(attacker) || !rapidFire.f_Enabled)
			return CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, targetID, attackResult, ignoreCheckCanBeHitInMP, method);

		auto& manager = game::EntityManager::instance();
		auto originalTarget = manager.entity(targetID);

		if (!IsValidByFilter(originalTarget))
			return CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, targetID, attackResult, ignoreCheckCanBeHitInMP, method);

		std::vector<cheat::game::Entity*> validEntities;
		validEntities.push_back(originalTarget);

		if (rapidFire.f_MultiTarget)
		{
			auto filteredEntities = manager.entities();
			for (const auto& entity : filteredEntities) {
				auto distance = originalTarget->distance(entity);

				if (entity->runtimeID() == manager.avatar()->runtimeID())
					continue;

				if (entity->runtimeID() == targetID)
					continue;

				if (distance > rapidFire.f_MultiTargetRadius)
					continue;

				if (!IsValidByFilter(entity))
					continue;

				validEntities.push_back(entity);
			}
		}

		for (const auto& entity : validEntities) {

			if (rapidFire.f_MultiHit) {
				int attackCount = rapidFire.GetAttackCount(__this, entity->runtimeID(), attackResult);
				for (int i = 0; i < attackCount; i++)
					app::MoleMole_LCBaseCombat_FireBeingHitEvent(__this, entity->runtimeID(), attackResult, method);
			}
			else CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, entity->runtimeID(), attackResult, ignoreCheckCanBeHitInMP, method);
		}

		CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, targetID, attackResult, ignoreCheckCanBeHitInMP, method);
	}*/

	static void LCBaseCombat_FireBeingHitEvent_Hook(app::LCBaseCombat* __this, uint32_t attackeeRuntimeID, app::AttackResult* attackResult, MethodInfo* method)
	{
		auto attacker = game::Entity(__this->fields._._._entity);
		RapidFire& rapidFire = RapidFire::GetInstance();
		if (!IsConfigByAvatar(attacker) || !IsAttackByAvatar(attacker) || !rapidFire.f_Enabled)
			return CALL_ORIGIN(LCBaseCombat_FireBeingHitEvent_Hook, __this, attackeeRuntimeID, attackResult, method);

		auto& manager = game::EntityManager::instance();
		auto originalTarget = manager.entity(attackeeRuntimeID);

		if (!IsValidByFilter(originalTarget))
			return CALL_ORIGIN(LCBaseCombat_FireBeingHitEvent_Hook, __this, attackeeRuntimeID, attackResult, method);

		std::vector<cheat::game::Entity*> validEntities;
		validEntities.push_back(originalTarget);

		if (rapidFire.f_MultiTarget)
		{
			auto filteredEntities = manager.entities();
			for (const auto& entity : filteredEntities) {
				auto distance = originalTarget->distance(entity);

				if (entity->runtimeID() == manager.avatar()->runtimeID())
					continue;

				if (entity->runtimeID() == attackeeRuntimeID)
					continue;

				if (distance > rapidFire.f_MultiTargetRadius)
					continue;

				if (!IsValidByFilter(entity))
					continue;

				validEntities.push_back(entity);
			}
		}

		for (const auto& entity : validEntities) {
			int attackCount = rapidFire.f_MultiHit ? rapidFire.GetAttackCount(__this, entity->runtimeID(), attackResult) : 1;
			for (int i = 0; i < attackCount; i++)
				CALL_ORIGIN(LCBaseCombat_FireBeingHitEvent_Hook, __this, entity->runtimeID(), attackResult, method);
		}
	}

	static void VCAnimatorEvent_HandleProcessItem_Hook(app::MoleMole_VCAnimatorEvent* __this,
		app::MoleMole_VCAnimatorEvent_MoleMole_VCAnimatorEvent_AnimatorEventPatternProcessItem* processItem,
		app::AnimatorStateInfo processStateInfo, app::MoleMole_VCAnimatorEvent_MoleMole_VCAnimatorEvent_TriggerMode__Enum mode, MethodInfo* method)
	{
		auto attacker = game::Entity(__this->fields._._._entity);
		RapidFire& rapidFire = RapidFire::GetInstance();
		bool isAttackAnimation = std::any_of(std::begin(attackTags), std::end(attackTags),
			[&](uint32_t tag) { return processStateInfo.m_Tag == tag; });
		bool isAttacking = IsAttackByAvatar(attacker) && isAttackAnimation;

		if (rapidFire.f_MultiAnimation && isAttacking)
		{
			// Set counter back to 1 when any new attack animation is invoked
			if (processStateInfo.m_NormalizedTime <= 0.01f)
				rapidFire.animationCounter = 1;

			if (rapidFire.animationCounter <= rapidFire.f_AnimationMultiplier)
			{
				// Can be configured up to 1.0 but 0.1 to 0.9 you can barely notice the difference
				// So 0 - 0.2 is enough.
				processItem->fields.lastTime = (rapidFire.f_AnimationState / 10);
				rapidFire.animationCounter++;
			}
		}

		static bool isFastSpeed = false;
		if (rapidFire.f_AttackSpeed && isAttacking)
		{
			if (!isinf(processStateInfo.m_Length))
				app::Animator_set_speed(attacker.animator(), rapidFire.f_SpeedMultiplier, nullptr);
			isFastSpeed = true;
		}
		else if (IsAttackByAvatar(attacker) && isFastSpeed) {
			//LOG_DEBUG("Speed Reverted");
			app::Animator_set_speed(attacker.animator(), processStateInfo.m_SpeedMultiplier, nullptr);
			isFastSpeed = false;
		}

		CALL_ORIGIN(VCAnimatorEvent_HandleProcessItem_Hook, __this, processItem, processStateInfo, mode, method);
	}
}