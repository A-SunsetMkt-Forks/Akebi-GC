#include "pch-il2cpp.h"
#include "PacketSniffer.h"

#ifdef _PACKET_SNIFFER
#include "SnifferWindow.h"
#endif

#include <fstream>
#include <helpers.h>

namespace cheat::feature 
{
	PacketSniffer::PacketSniffer() : Feature(),
		NF(f_CaptureEnabled, "Capturing", "PacketSniffer", false),
		NF(f_ManipulationEnabled, "Manipulation", "PacketSniffer", false),
		NF(f_PipeName, "Pipe name", "PacketSniffer", "genshin_packet_pipe")

	{
		sniffer::MessageManager::Connect(f_PipeName.value());

		HookManager::install(app::Kcp_KcpNative_kcp_client_send_packet, KcpNative_kcp_client_send_packet_Hook);
		HookManager::install(app::MoleMole_KcpClient_TryDequeueEvent, KcpClient_TryDequeueEvent_Hook);
	}

	const FeatureGUIInfo& PacketSniffer::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Packet Sniffer", "Settings", true };
		return info;
	}

	void PacketSniffer::DrawMain()
	{
		ImGui::Text("Dev: for working needs server for named pipe with specified name.\nCheck 'packet-handler' project like example.");
		ConfigWidget(f_PipeName, "Pipe name for connecting. Changes will apply after next game launch.");
		ConfigWidget(f_CaptureEnabled, "Enable capturing of packet info and sending to pipe, if it exists.");
		ConfigWidget(f_ManipulationEnabled, "Enable blocking and modifying packets by sniffer, can cause network lags.");
	}
	
	PacketSniffer& PacketSniffer::GetInstance()
	{
		static PacketSniffer instance;
		return instance;
	}

	bool PacketSniffer::ProcessModifiedData(app::KcpPacket_1* packet)
	{
		auto modify_data = sniffer::MessageManager::WaitFor<ModifyData>();
		if (!modify_data)
			return false;

		switch (modify_data->modify_type)
		{
		case PacketModifyType::Blocked:
			return true;

		case PacketModifyType::Modified:
		{
			auto data_size = modify_data->modified_head.size() + modify_data->modified_message.size() + 12;
			char* data = new char[data_size];

			auto head_size = static_cast<uint16_t>(modify_data->modified_head.size());
			auto message_size = static_cast<uint32_t>(modify_data->modified_message.size());

			util::WriteMapped(data, 0, static_cast<uint16_t>(0x4567)); // Magic number
			util::WriteMapped(data, 2, modify_data->message_id); // Message id
			util::WriteMapped(data, 4, head_size); // Head size
			util::WriteMapped(data, 6, message_size); // Message size

			// Fill content
			char* ptr_head_content = data + 10;
			memcpy_s(ptr_head_content, head_size, modify_data->modified_head.data(), head_size);

			char* ptr_message_content = ptr_head_content + modify_data->modified_head.size();
			memcpy_s(ptr_message_content, message_size, modify_data->modified_message.data(), message_size);
			
			util::WriteMapped(ptr_message_content, message_size, static_cast<uint16_t>(0x89AB));

			EncryptXor(data, data_size);

			// Can be memory leak.
			auto new_packet = app::Kcp_KcpNative_kcp_packet_create(reinterpret_cast<uint8_t*>(data), static_cast<int32_t>(data_size), nullptr);
			delete[] data;

			// Will be deleted by KcpNative_kcp_client_network_thread
			// app::Kcp_KcpNative_kcp_packet_destroy(packet, nullptr);
			packet = new_packet;
		}
		break;
		case PacketModifyType::Unchanged:
		default:
			break;
		}
		return false;
	}

	bool PacketSniffer::OnPacketIO(app::KcpPacket_1* packet, PacketIOType type)
	{
		if (!sniffer::MessageManager::IsConnected())
			return true;

		if (!f_CaptureEnabled)
			return true;

		PacketData packetData = ParseRawPacketData((char*)packet->data, packet->dataLen);
		if (!packetData.valid)
			return true;

		packetData.ioType = type;
		packetData.blockModeEnabled = f_ManipulationEnabled;
		sniffer::MessageManager::Send(packetData);

		bool canceled = f_ManipulationEnabled && ProcessModifiedData(packet);

		return !canceled;
	}

	void PacketSniffer::EncryptXor(void* content, uint32_t length)
	{
		auto byteArray = reinterpret_cast<app::Byte__Array*>(new char[length + 0x20]);
		byteArray->max_length = length;
		memcpy_s(byteArray->vector, length, content, length);

		app::MoleMole_Packet_XorEncrypt(&byteArray, length, nullptr);

		memcpy_s(content, length, byteArray->vector, length);
		delete[] byteArray;
	}

	PacketData PacketSniffer::ParseRawPacketData(char* encryptedData, uint32_t length)
	{
		// Packet structure
		// * Magic word (0x4567) [2 bytes]
		// * message_id [2 bytes] 
		// * head_size [2 bytes]
		// * message_size [4 bytes]
		// * head_content [<head_size> bytes]
		// * message_content [<message_size> bytes]
		// * Magic word (0x89AB) [2 bytes]

		// Header size - 12 bytes
		
		PacketData packetData = sniffer::MessageManager::CreateMessage<PacketData>();
		// Decrypting packetData
		auto data = new char[length];
		memcpy_s(data, length, encryptedData, length);
		EncryptXor(data, length);

		uint16_t magicHead = util::ReadMapped<uint16_t>(data, 0);

		if (magicHead != 0x4567)
		{
			LOG_ERROR("Head magic value for packet is not valid.");
			return packetData;
		}

		uint16_t magicEnd = util::ReadMapped<uint16_t>(data, length - 2);
		if (magicEnd != 0x89AB)
		{
			LOG_ERROR("End magic value for packet is not valid.");
			return packetData;
		}

		uint16_t messageId = util::ReadMapped<uint16_t>(data, 2);
		uint16_t headSize = util::ReadMapped<uint16_t>(data, 4);
		uint32_t contenSize = util::ReadMapped<uint32_t>(data, 6);

		if (length < headSize + contenSize + 12)
		{
			LOG_ERROR("Packet size is not valid.");
			return packetData;
		}

		packetData.valid = true;
		packetData.messageID = messageId;

		packetData.headRawData = std::vector<byte>((size_t)headSize, 0);
		memcpy_s(packetData.headRawData.data(), headSize, data + 10, headSize);

		packetData.messageRawData = std::vector<byte>((size_t)contenSize, 0);
		memcpy_s(packetData.messageRawData.data(), contenSize, data + 10 + headSize, contenSize);

		delete[] data;

		return packetData;
	}

	bool PacketSniffer::KcpClient_TryDequeueEvent_Hook(void* __this, app::ClientKcpEvent* evt, MethodInfo* method)
	{
		auto result = CALL_ORIGIN(KcpClient_TryDequeueEvent_Hook, __this, evt, method);

		if (!result || evt->_evt.type != app::KcpEventType__Enum::EventRecvMsg ||
			evt->_evt.packet == nullptr || evt->_evt.packet->data == nullptr)
			return result;

		auto& sniffer = GetInstance();
		return sniffer.OnPacketIO(evt->_evt.packet, PacketIOType::Receive);
	}

	int32_t PacketSniffer::KcpNative_kcp_client_send_packet_Hook(void* kcp_client, app::KcpPacket_1* packet, MethodInfo* method)
	{
		auto& sniffer = GetInstance();
		if (!sniffer.OnPacketIO(packet, PacketIOType::Send))
			return 0;

		return CALL_ORIGIN(KcpNative_kcp_client_send_packet_Hook, kcp_client, packet, method);
	}
}

