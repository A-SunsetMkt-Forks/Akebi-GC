#include "pch-il2cpp.h"
#include "SimpleFilter.h"

namespace cheat::game
{

	bool SimpleFilter::IsValid(Entity* entity) const
	{
		if (entity == nullptr)
			return false;

		if (entity->type() != m_Type)
			return false;

		if (m_Names.size() == 0)
			return true;

		auto& name = entity->name();
		for (auto& pattern : m_Names)
		{
			if (name.find(pattern) != -1)
				return true;
		}

		return false;
	}

	SimpleFilter::SimpleFilter(app::EntityType__Enum_1 type, const std::vector<std::string>& names) : m_Names(names), m_Type(type)
	{

	}

	SimpleFilter operator+(SimpleFilter lFilter, const SimpleFilter& rFilter)
	{
		lFilter.m_Names.insert(lFilter.m_Names.end(), rFilter.m_Names.begin(), rFilter.m_Names.end());
		return lFilter;
	}
}