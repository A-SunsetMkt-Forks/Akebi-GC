#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <cheat/game/Entity.h>
#include <cheat/game/filters.h>
#include <il2cpp-appdata.h>
#include <cheat-base/thread-safe.h>

namespace cheat::feature
{
	class VacuumLoot : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<float> f_Distance;
		config::Field<float> f_Radius;
		config::Field<int> f_DelayTime;

		static VacuumLoot& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void OnGameUpdate();

	private:
		using FilterInfo = std::pair<config::Field<bool>, game::IEntityFilter*>;
		using Filters = std::vector<FilterInfo>;
		using Sections = std::map<std::string, Filters>;

		Sections m_Sections;
		SafeValue<int64_t> nextTime;

		VacuumLoot();
		void DrawSection(const std::string& section, const Filters& filters);
		void InstallFilters();
		void AddFilter(const std::string& section, const std::string& name, game::IEntityFilter* filter);
		bool IsEntityForVac(cheat::game::Entity* entity);
	};
}
