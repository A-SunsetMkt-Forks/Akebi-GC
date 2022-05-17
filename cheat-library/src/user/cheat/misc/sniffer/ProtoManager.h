#pragma once

#include <string>
#include <filesystem>

#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/message.h>
#include <google/protobuf/util/json_util.h>

namespace sniffer 
{
	class ProtoManager
	{
	public:
		ProtoManager();

		std::optional<std::string> GetJson(uint32_t id, std::vector<byte>& data);
		std::optional<std::string> GetJson(const std::string& name, std::vector<byte>& byte);
		std::optional<std::string> GetName(uint32_t id);
		uint16_t GetId(const std::string& name);

		void Load(const std::string& idFilePath, const std::string& protoDir);
		void LoadIDFile(const std::string& filepath);
		void LoadProtoDir(const std::string& dirPath);

	private:
		std::mutex _mutex;
	    std::shared_ptr<google::protobuf::compiler::Importer> importer;
		std::shared_ptr<google::protobuf::DynamicMessageFactory> factory;
		std::shared_ptr<google::protobuf::compiler::DiskSourceTree> diskTree;

		std::map<uint16_t, std::string> nameMap;
		std::map<std::string, uint16_t> idMap;

		google::protobuf::Message* ParseMessage(const std::string& name, std::vector<byte> data);

	};
}


