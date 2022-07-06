#pragma once
#include <Windows.h>
#include <cheat-base/events/event.hpp>
#include <imgui.h>

namespace renderer
{
	enum class DXVersion
	{
		D3D9,
		D3D10,
		D3D11,
		D3D12
	};

	void Init(LPBYTE pFontData, DWORD dFontDataSize, DXVersion version = DXVersion::D3D11);

	// Font sizing
	ImFont* GetFontBySize(float fontSize);
	float GetScaleByFontSize(float fontSize);

	void SetGlobalFontSize(float globalFontSize);
	float GetGlobalFontSize();

	// Input lock
	void SetInputLock(void* id, bool value);
	void AddInputLocker(void* id);
	void RemoveInputLocker(void* id);
	bool IsInputLocked();
}
