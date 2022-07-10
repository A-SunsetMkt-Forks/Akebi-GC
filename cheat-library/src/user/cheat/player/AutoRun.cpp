#include "pch-il2cpp.h"
#include "AutoRun.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/util.h>
#include <cheat-base/render/renderer.h>

namespace cheat::feature
{
	//bool isAutoRunEnabled = false;

	AutoRun::AutoRun() : Feature(),
		NF(f_Enabled, "Auto Run", "Player::AutoRun", false),
		NF(f_Speed,	"Speed", "Player::AutoRun",1.0f),
		NF(f_CameraRelative, "Relative to camera", "Player::AutoRun" , false)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(AutoRun::OnGameUpdate);
	}

	const FeatureGUIInfo& AutoRun::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Auto Run", "Player", true };
		return info;
	}

	void AutoRun::DrawMain()
	{
		ConfigWidget("Enable", f_Enabled);
		ConfigWidget("Auto Run speed", f_Speed, 0.01f, 0.01f, 1000.0f, "Speed of character \n Not recommended going above 5");
		ConfigWidget("Movement relative to camera", f_CameraRelative);
	}

	bool AutoRun::NeedStatusDraw() const
	{
		return f_Enabled;
	}
	void AutoRun::DrawStatus()
	{
		ImGui::Text("Auto Run[%.01f]",f_Speed.value());
	}

	AutoRun& AutoRun::GetInstance()
	{
		static AutoRun instance;
		return instance;
	}

	void enableAutoRun(float speed, bool cameraRelative) {
		
		auto& manager = game::EntityManager::instance();
		auto avatarEntity = manager.avatar();

		auto baseMove = avatarEntity->moveComponent();
		auto rigidBody = avatarEntity->rigidbody();

		app::Rigidbody_set_detectCollisions(rigidBody, true, nullptr);

		auto cameraEntity = game::Entity(reinterpret_cast<app::BaseEntity*>(manager.mainCamera()));
		auto relativeEntity = cameraRelative ? &cameraEntity : avatarEntity;

		if (baseMove == nullptr)
			return;

		if (rigidBody == nullptr)
			return;

		if (renderer::IsInputLocked())
			return;

		app::Vector3 dir = {};
		dir = dir + relativeEntity->forward();

		app::Vector3 prevPos = avatarEntity->relativePosition();
		if (IsVectorZero(prevPos))
			return;

		float deltaTime = app::Time_get_deltaTime(nullptr);

		app::Vector3 newPos = prevPos + dir * speed * deltaTime;

		avatarEntity->setRelativePosition(newPos);
	}

	void AutoRun::OnGameUpdate() {
		if (f_Enabled) {
			float speed = f_Speed.value();
			bool cameraRelative = f_CameraRelative.value();
			enableAutoRun(speed, cameraRelative);
		}
	}
}