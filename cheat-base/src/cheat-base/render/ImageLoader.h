#pragma once

#include <string>
#include <map>
#include <optional>

#include <Windows.h>

#include <imgui.h>

class ImageLoader
{
public:
	struct ImageData
	{
		ImTextureID textureID;
		ImVec2 size;
	};

	static std::optional<ImageData> GetImage(const std::string& imageName, const char* imageType = "PNG");

private:
	inline static std::map<std::string, ImageData> s_Textures {};
};