#pragma once
#include "messages/PacketData.h"
#include "ProtoManager.h"

namespace sniffer
{
	class PacketParser
	{
	public:
		PacketParser(const std::string& protoDirPath, const std::string& protoIDPath);

		void SetProtoDir(const std::string& protoDir);
		void SetProtoIDPath(const std::string& protoIDPath);

		bool Parse(PacketData& data);
		bool IsUnionPacket(const PacketData& data);
		std::vector<PacketData> ParseUnionPacket(const PacketData& data);

	private:
		PacketData CreateNestedPacket(const PacketData& parent, std::string bodyEncoded, int16_t packetID = 0);
		std::vector<PacketData> ParseUnionCmdNotify(const PacketData& data);

		std::optional<PacketData> ParseAbilityInvokeEntry(const PacketData& parent, const nlohmann::json& entry);
		std::vector<PacketData> ParseAbilityInvocationsNotify(const PacketData& data);

		std::optional<PacketData> ParseCombatInvokeEntry(const PacketData& parent, const nlohmann::json& entry);
		std::vector<PacketData> ParseCombatInvocationsNotify(const PacketData& data);

		using UnionPacketParserFunc = std::vector<PacketData>(PacketParser::*)(const PacketData& data);
		inline static std::map<std::string, UnionPacketParserFunc> s_UnionPacketNames =
		{
			{ "UnionCmdNotify", &ParseUnionCmdNotify},

			{ "EntityAbilityInvokeEntry",      &ParseAbilityInvocationsNotify },
			{ "ClientAbilityInitFinishNotify", &ParseAbilityInvocationsNotify },
			{ "ClientAbilityChangeNotify",     &ParseAbilityInvocationsNotify },
			{ "AbilityInvocationsNotify",      &ParseAbilityInvocationsNotify },

			{ "CombatInvocationsNotify", &ParseCombatInvocationsNotify}
		};

		sniffer::ProtoManager m_ProtoManager;
		std::map<uint32_t, UnionPacketParserFunc> m_UnionPacketIds;

		void UpdateUnionPacketIDs();
	};
}


