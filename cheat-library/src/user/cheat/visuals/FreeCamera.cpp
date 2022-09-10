#include "pch-il2cpp.h"
#include "FreeCamera.h"

#include <math.h>
#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature
{
	app::GameObject* freeCam = nullptr;
	app::GameObject* mainCam = nullptr;
	app::Object_1* freeCamObj = nullptr;
	app::Object_1* mainCamObj = nullptr;
	app::GameObject* damageOverlay = nullptr;
	app::GameObject* hpOverlay = nullptr;
	app::Transform* freeCam_Transform;
	app::Component_1* freeCam_Camera;
	app::Component_1* mainCam_Camera;
	app::Vector3 targetPosition;
	app::Vector3 smoothPosition;
	float smoothFOV, focalLength = 0;
	bool isEnabled = false;

	FreeCamera::FreeCamera() : Feature(),
		NF(f_Enabled, "Free Camera", "Visuals::FreeCamera", false),
		NF(f_FreezeAnimation, "Freeze Character Animation", "Visuals::FreeCamera", false),
		NF(f_BlockInput, "Block Input", "Visuals::FreeCamera", false),
		NF(f_DamageOverlay, "Damage Overlay", "Visuals::FreeCamera", false),
		NF(f_HpOverlay, "Enemy HP Overlay", "Visuals::FreeCamera", false),
		NF(f_Speed, "Speed", "Visuals::FreeCamera", 1.0f),
		NF(f_LookSens, "Look Sensitivity", "Visuals::FreeCamera", 1.0f),
		NF(f_RollSpeed, "Roll Speed", "Visuals::FreeCamera", 1.0f),
		NF(f_FOVSpeed, "FOV Speed", "Visuals::FreeCamera", 0.1f),
		NF(f_FOV, "Field of View", "Visuals::FreeCamera", 45.0f),
		NF(f_MovSmoothing, "Movement Smoothing", "Visuals::FreeCamera", 1.0f),
		NF(f_LookSmoothing, "Look Smoothing", "Visuals::FreeCamera", 1.0f),
		NF(f_RollSmoothing, "Roll Smoothing", "Visuals::FreeCamera", 1.0f),
		NF(f_FovSmoothing, "FOV Smoothing", "Visuals::FreeCamera", 1.0f),
		NF(f_Forward, "Forward", "Visuals::FreeCamera", Hotkey('W')),
		NF(f_Backward, "Backward", "Visuals::FreeCamera", Hotkey('S')),
		NF(f_Left, "Left", "Visuals::FreeCamera", Hotkey('A')),
		NF(f_Right, "Right", "Visuals::FreeCamera", Hotkey('D')),
		NF(f_Up, "Up", "Visuals::FreeCamera", Hotkey(VK_SPACE)),
		NF(f_Down, "Down", "Visuals::FreeCamera", Hotkey(VK_LCONTROL)),
		NF(f_LeftRoll, "Roll Left", "Visuals::FreeCamera", Hotkey('Z')),
		NF(f_RightRoll, "Roll Right", "Visuals::FreeCamera", Hotkey('X')),
		NF(f_ResetRoll, "Reset Roll", "Visuals::FreeCamera", Hotkey('C')),
		NF(f_IncFOV, "Increase FOV", "Visuals::FreeCamera", Hotkey('3')),
		NF(f_DecFOV, "Decrease FOV", "Visuals::FreeCamera", Hotkey('1'))
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(FreeCamera::OnGameUpdate);
	}

	const FeatureGUIInfo& FreeCamera::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Free Camera", "Visuals", true };
		return info;
	}

	void FreeCamera::DrawMain()
	{
		ConfigWidget("Enable", f_Enabled);
		ConfigWidget("Freeze Character Animation", f_FreezeAnimation, "Freezes the active character's animation.");
		ConfigWidget("Block User Input", f_BlockInput, "If enabled, any input will be blocked.");
		if (f_Enabled)
		{
			ConfigWidget("Toggle Damage Overlay", f_DamageOverlay, "Remove damage output overlay");
			ConfigWidget("Toggle Enemy HP Overlay", f_HpOverlay, "Remove enemy HP overlay");
		}

		if (ImGui::BeginTable("FreeCameraDrawTable", 1, ImGuiTableFlags_NoBordersInBody))
		{
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);

			ImGui::BeginGroupPanel("Settings");
			{
				ConfigWidget("Movement Speed", f_Speed, 0.01f, 0.01f, 1000.0f);
				ConfigWidget("Look Sensitivity", f_LookSens, 0.01f, 0.01f, 100.0f);
				ConfigWidget("Roll Speed", f_RollSpeed, 0.01f, 0.01f, 100.0f);
				ConfigWidget("FOV Speed", f_FOVSpeed, 0.01f, 0.01f, 100.0f);
				ConfigWidget("Field of View", f_FOV, 0.1f, 0.01f, 200.0f, "Changes Vertical FoV. Horizontal FoV depends on the viewport's aspect ratio");
				if (ImGui::Button("Convert FoV to 35mm FF focal length"))
					focalLength = 24 / (2 * tan((f_FOV * 3.14159265) / (2 * 180))); // FocalLength = (vertical) sensor size / 2 * tan( 2*(vertical) FoV * Pi / 180)  Remember to convert degree to radian.  
				ImGui::Text("Focal length: %f", focalLength);
				ImGui::Spacing();
				ConfigWidget("Movement Smoothing", f_MovSmoothing, 0.01f, 0.001f, 1.0f, "Lower = Smoother");
				ConfigWidget("Look Smoothing", f_LookSmoothing, 0.01f, 0.001f, 1.0f, "Lower = Smoother");
				ConfigWidget("Roll Smoothing", f_RollSmoothing, 0.01f, 0.001f, 1.0f, "Lower = Smoother");
				ConfigWidget("FOV Smoothing", f_FovSmoothing, 0.01f, 0.001f, 1.0f, "Lower = Smoother");
			}
			ImGui::EndGroupPanel();

			ImGui::BeginGroupPanel("Hotkeys");
			{
				ConfigWidget("Forward", f_Forward, true);
				ConfigWidget("Backward", f_Backward, true);
				ConfigWidget("Left", f_Left, true);
				ConfigWidget("Right", f_Right, true);
				ConfigWidget("Up", f_Up, true);
				ConfigWidget("Down", f_Down, true);
				ConfigWidget("Roll Left", f_LeftRoll, true);
				ConfigWidget("Roll Right", f_RightRoll, true);
				ConfigWidget("Reset Roll", f_ResetRoll, true);
				ConfigWidget("Increase FOV", f_IncFOV, true);
				ConfigWidget("Decrease FOV", f_DecFOV, true);
			}
			ImGui::EndGroupPanel();
			ImGui::EndTable();
		}
	}

	bool FreeCamera::NeedStatusDraw() const
	{
		return f_Enabled;
	}

	void FreeCamera::DrawStatus()
	{
		ImGui::Text("Free Camera");
	}

	FreeCamera& FreeCamera::GetInstance()
	{
		static FreeCamera instance;
		return instance;
	}

	class CameraRotation
	{
	public:
		float pitch, yaw, roll;

		void InitializeFromTransform(app::Transform* t)
		{
			auto t_eulerAngles = app::Transform_get_eulerAngles(t, nullptr);
			pitch = t_eulerAngles.x;
			yaw = t_eulerAngles.y;
			roll = t_eulerAngles.z;
		}

		void LerpTowards(CameraRotation target, float lookRotationLerpPct, float rollRotationLerpPct)
		{
			yaw = app::Mathf_Lerp(yaw, target.yaw, lookRotationLerpPct, nullptr);
			pitch = app::Mathf_Lerp(pitch, target.pitch, lookRotationLerpPct, nullptr);
			roll = app::Mathf_Lerp(roll, target.roll, rollRotationLerpPct, nullptr);
		}

		void UpdateTransform(app::Transform* t)
		{
			app::Transform_set_eulerAngles(t, app::Vector3{ pitch, yaw, roll }, nullptr);
		}
	};

	auto targetRotation = CameraRotation();
	auto currentRotation = CameraRotation();

	void EnableFreeCam()
	{
		auto& settings = FreeCamera::GetInstance();
		freeCam = reinterpret_cast<app::GameObject*>(freeCamObj);

		freeCam_Transform = app::GameObject_get_transform(freeCam, nullptr);
		auto freeCam_Transform_position = app::Transform_get_position(freeCam_Transform, nullptr);

		freeCam_Camera = app::GameObject_GetComponentByName(freeCam, string_to_il2cppi("Camera"), nullptr);
		mainCam_Camera = app::GameObject_GetComponentByName(mainCam, string_to_il2cppi("Camera"), nullptr);

		if (isEnabled == false)
		{
			targetRotation.InitializeFromTransform(freeCam_Transform);
			currentRotation.InitializeFromTransform(freeCam_Transform);
			app::Camera_CopyFrom(reinterpret_cast<app::Camera*>(freeCam_Camera), reinterpret_cast<app::Camera*>(mainCam_Camera), nullptr);

			targetPosition = freeCam_Transform_position;
			isEnabled = true;
		}

		app::GameObject_set_active(mainCam, false, nullptr);
		app::GameObject_set_active(freeCam, true, nullptr);

		// MOVEMENT
		if (settings.f_Forward.value().IsPressed())
			targetPosition = targetPosition + app::Transform_get_forward(freeCam_Transform, nullptr) * settings.f_Speed;
		if (settings.f_Backward.value().IsPressed())
			targetPosition = targetPosition - app::Transform_get_forward(freeCam_Transform, nullptr) * settings.f_Speed;
		if (settings.f_Right.value().IsPressed())
			targetPosition = targetPosition + app::Transform_get_right(freeCam_Transform, nullptr) * settings.f_Speed;
		if (settings.f_Left.value().IsPressed())
			targetPosition = targetPosition - app::Transform_get_right(freeCam_Transform, nullptr) * settings.f_Speed;

		if (settings.f_LeftRoll.value().IsPressed())
			targetRotation.roll += settings.f_RollSpeed;
		if (settings.f_RightRoll.value().IsPressed())
			targetRotation.roll -= settings.f_RollSpeed;
		if (settings.f_ResetRoll.value().IsPressed())
			targetRotation.roll = 0.0f;

		if (settings.f_Up.value().IsPressed())
			targetPosition = targetPosition + app::Transform_get_up(freeCam_Transform, nullptr) * settings.f_Speed;
		if (settings.f_Down.value().IsPressed())
			targetPosition = targetPosition - app::Transform_get_up(freeCam_Transform, nullptr) * settings.f_Speed;

		if (settings.f_DecFOV.value().IsPressed())
			settings.f_FOV -= settings.f_FOVSpeed;
		if (settings.f_IncFOV.value().IsPressed())
			settings.f_FOV += settings.f_FOVSpeed;

		// Update the target rotation based on mouse input
		auto mouseX = app::Input_GetAxis(string_to_il2cppi("Mouse X"), nullptr);
		auto mouseY = app::Input_GetAxis(string_to_il2cppi("Mouse Y"), nullptr);
		auto mouseInput = app::Vector2{ mouseX, mouseY * -1.0f };
		targetRotation.yaw += mouseInput.x * settings.f_LookSens;
		targetRotation.pitch += mouseInput.y * settings.f_LookSens;

		// Commit the rotation changes to the transform
		currentRotation.UpdateTransform(freeCam_Transform);

		smoothPosition = app::Vector3_Lerp(freeCam_Transform_position, targetPosition, settings.f_MovSmoothing, nullptr);
		app::Transform_set_position(freeCam_Transform, smoothPosition, nullptr);
		smoothFOV = app::Mathf_Lerp(app::Camera_get_fieldOfView(reinterpret_cast<app::Camera*>(freeCam_Camera), nullptr), settings.f_FOV, settings.f_FovSmoothing, nullptr);
		app::Camera_set_fieldOfView(reinterpret_cast<app::Camera*>(freeCam_Camera), smoothFOV, nullptr);
		currentRotation.LerpTowards(targetRotation, settings.f_LookSmoothing, settings.f_RollSmoothing);
	}

	void DisableFreeCam()
	{
		if (!isEnabled)
			return;

		if (mainCam)
		{
			app::GameObject_set_active(mainCam, true, nullptr);
			mainCam = nullptr;
		}
		if (freeCamObj)
		{
			app::Object_1_Destroy_1(freeCamObj, nullptr);
			freeCamObj = nullptr;
		}
		isEnabled = false;
	}

	void FreeCamera::OnGameUpdate()
	{
		auto uiManager = GET_SINGLETON(MoleMole_UIManager);
		if (uiManager == nullptr)
			return;

		static bool isBlock = false;

		if (f_Enabled)
		{
			if (mainCam == nullptr)
				mainCam = app::GameObject_Find(string_to_il2cppi("/EntityRoot/MainCamera(Clone)"), nullptr);
			if (freeCamObj == nullptr && mainCam)
			{
				freeCamObj = app::Object_1_Instantiate_2(reinterpret_cast<app::Object_1*>(mainCam), nullptr);

				auto mainCamTransform = app::GameObject_get_transform(mainCam, nullptr);
				auto mainCamPos = app::Transform_get_position(mainCamTransform, nullptr);
				auto freeCamObjTransform = app::GameObject_get_transform(reinterpret_cast<app::GameObject*>(freeCamObj), nullptr);
				app::Transform_set_position(freeCamObjTransform, mainCamPos, nullptr);

				auto CinemachineBrain = app::GameObject_GetComponentByName(reinterpret_cast<app::GameObject*>(freeCamObj), string_to_il2cppi("CinemachineBrain"), nullptr);
				auto CinemachineExternalCamera = app::GameObject_GetComponentByName(reinterpret_cast<app::GameObject*>(freeCamObj), string_to_il2cppi("CinemachineExternalCamera"), nullptr);
				app::Object_1_Destroy_1(reinterpret_cast<app::Object_1*>(CinemachineBrain), nullptr);
				app::Object_1_Destroy_1(reinterpret_cast<app::Object_1*>(CinemachineExternalCamera), nullptr);

				app::GameObject_set_active(mainCam, false, nullptr);
				app::GameObject_set_active(mainCam, true, nullptr);
				app::GameObject_set_active(reinterpret_cast<app::GameObject*>(freeCamObj), false, nullptr);
			}
			if (freeCamObj)
				EnableFreeCam();

			if (damageOverlay == nullptr)
				damageOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/ParticleDamageTextContainer"), nullptr);
			else
				app::GameObject_SetActive(damageOverlay, !f_DamageOverlay, nullptr);

			if (hpOverlay == nullptr)
				hpOverlay = app::GameObject_Find(string_to_il2cppi("AvatarBoardCanvasV2(Clone)"), nullptr);
			else
				app::GameObject_SetActive(hpOverlay, !f_DamageOverlay, nullptr);
		}
		else
		{
			DisableFreeCam();
			damageOverlay = nullptr;
			hpOverlay = nullptr;
		}

		if (f_BlockInput)
		{
			if (!isBlock)
			{
				app::MoleMole_UIManager_EnableInput(uiManager, false, false, false, nullptr);
				isBlock = true;
			}
		}
		else
		{
			if (isBlock)
			{
				app::MoleMole_UIManager_EnableInput(uiManager, true, false, false, nullptr);
				isBlock = false;
			}
		}

		// Taiga#5555: There's probably be a better way of implementing this. But for now, this is just what I came up with.
		auto& manager = game::EntityManager::instance();
		auto animator = manager.avatar()->animator();
		auto rigidBody = manager.avatar()->rigidbody();
		if (animator == nullptr && rigidBody == nullptr)
			return;

		static bool changed = false;

		if (f_FreezeAnimation)
		{
			//auto constraints = app::Rigidbody_get_constraints(rigidBody, nullptr);
			//LOG_DEBUG("%s", magic_enum::enum_name(constraints).data());
			app::Rigidbody_set_constraints(rigidBody, app::RigidbodyConstraints__Enum::FreezePosition, nullptr);
			app::Animator_set_speed(animator, 0.f, nullptr);
			changed = false;
		}
		else
		{
			app::Rigidbody_set_constraints(rigidBody, app::RigidbodyConstraints__Enum::FreezeRotation, nullptr);
			if (!changed)
			{
				app::Animator_set_speed(animator, 1.f, nullptr);
				changed = true;
			}
		}
	}
}