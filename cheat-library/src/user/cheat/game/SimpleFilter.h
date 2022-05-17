#pragma once

#include "IEntityFilter.h"
#include <vector>
#include <il2cpp-appdata.h>

namespace cheat::game
{
    class SimpleFilter :
        public IEntityFilter
    {
	public:

        SimpleFilter(app::EntityType__Enum_1 type, const std::vector<std::string>& names = {});
        SimpleFilter(app::EntityType__Enum_1 type, const std::string name) : SimpleFilter(type, std::vector<std::string>{name}) {}
        bool IsValid(Entity* entity) const override;
        friend SimpleFilter operator+(SimpleFilter lFilter, const SimpleFilter& rFilter);
    private:
		app::EntityType__Enum_1 m_Type;
        std::vector<std::string> m_Names;
    };
}
