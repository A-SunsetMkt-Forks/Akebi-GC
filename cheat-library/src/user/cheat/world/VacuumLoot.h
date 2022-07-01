#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <cheat/game/Entity.h>
#include <cheat/game/filters.h>
#include <il2cpp-appdata.h>

namespace cheat::feature
{

	class VacuumLoot : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;

		static VacuumLoot& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void OnGameUpdate();
	private:

		std::vector<game::IEntityFilter*> m_Filters;
		VacuumLoot();
		int nextTime{};
		bool IsEntityForVac(cheat::game::Entity* entity);
	};
}
