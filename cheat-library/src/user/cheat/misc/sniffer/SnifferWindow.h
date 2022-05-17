#pragma once
#include "PacketInfo.h"

namespace sniffer
{

	class IFilter
	{
	public:
		virtual bool Draw(bool canBeRemoved = true)  = 0;
		virtual bool Execute(const sniffer::PacketInfo& info) = 0;
		virtual nlohmann::json Serialize() = 0;
	};


	class Filter : public IFilter
	{
	public:
		enum class CompareType
		{
			Regex, Equal, Contains, Less, LessEqual, More, MoreEqual
		};

		enum class ObjectType
		{
			KeyValue, AnyKey, AnyValue, Name, PacketId
		};

		virtual bool Draw(bool canBeRemoved = true) override;
		virtual bool Execute(const sniffer::PacketInfo& info) override;

		virtual nlohmann::json Serialize() override;
		
		Filter();
		Filter(nlohmann::json& object);
	private:

		bool FindAnyValue(const sniffer::PacketInfo& info);
		bool FindAnyKey(const sniffer::PacketInfo& info);
		bool FindKeyValue(const sniffer::PacketInfo& info);
		std::vector<nlohmann::json> FindKeys(const sniffer::PacketInfo& info, bool onlyFirst = false);

		CompareType m_CompareType;
		ObjectType m_ObjectType;

		std::string m_KeyPattern;
		std::string m_ObjectPattern;
	};

	class FilterGroup : public IFilter
	{
	public:

		enum class Rule
		{
			AND, OR, NOT
		};

		virtual bool Draw(bool canBeRemoved = true) override;
		virtual bool Execute(const sniffer::PacketInfo& info) override;

		virtual nlohmann::json Serialize() override;

		FilterGroup();
		FilterGroup(nlohmann::json& object);

	private:
		Rule m_Rule;
		std::list<IFilter*> m_Filters;

	};

	class SnifferWindow
	{
	public:
		config::Field<bool> m_Show;

		SnifferWindow(SnifferWindow const&) = delete;
		void operator=(SnifferWindow const&) = delete;

		static SnifferWindow& GetInstance();
		void OnPacketIO(const PacketInfo& info);
		void Draw();

	private:
		enum class SortValue
		{
			Time, Name, Size, Id, Type
		};

		enum class SortType
		{
			Desc, Asc
		};

		SortValue m_SortValue;
		SortType m_SortType;

		std::list<sniffer::PacketInfo> m_CapturedPackets;
		std::list<sniffer::PacketInfo> m_CachedPackets;

		std::mutex m_CapturePacketLock;

		FilterGroup m_FilterGroup;

		SnifferWindow();
	};
}

