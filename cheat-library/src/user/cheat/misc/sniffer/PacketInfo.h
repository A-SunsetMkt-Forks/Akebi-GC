#pragma once

#include <nlohmann/json.hpp>

#include "messages/PacketData.h"

namespace sniffer 
{
	class PacketInfo
	{
	public:
		PacketInfo(PacketData packetData);

		PacketIOType type() const;
		uint32_t id() const;
		size_t size() const;
		int64_t time() const;
		std::string name() const;
		nlohmann::json object() const;

		void Draw();

	private:
		nlohmann::json m_JObject;
		int64_t m_Time;

		bool m_DrawBeauty;
		std::string m_JsonMessageBeauty;
		std::string m_Header;

		PacketData m_Data;
	};
}


