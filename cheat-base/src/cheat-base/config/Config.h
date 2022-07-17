#pragma once

#include "Field.h"
#include <vector>
#include <string>
#include "fields/Toggle.h"
#include "fields/Enum.h"

#define SNFEX(field, friendName, name, section, defaultValue, shared) config::CreateField<decltype(##field##)::_ValueType>(friendName, name, section, shared, defaultValue)
#define SNFB(field, name, section, defaultValue, shared) SNFEX(field, name, config::internal::FixFieldName(#field), section, defaultValue, shared)
#define SNF(field, name, section, defaultValue) SNFB(field, name, section, defaultValue, false)

#define NFEX(field, friendName, name, section, defaultValue, shared) field##(SNFEX(field, friendName, name, section, defaultValue, shared))
#define NFEXUP(field, friendName, name, section, shared, ...) field##(config::CreateField<decltype(##field##)::_ValueType>(friendName, name, section, shared, __VA_ARGS__))

#define NFB(field, name, section, defaultValue, shared) NFEX(field, name, config::internal::FixFieldName(#field), section, defaultValue, shared)
#define NFS(field, name, section, defaultValue) NFB(field, name, section, defaultValue, true)
#define NF(field, name, section, defaultValue) NFB(field, name, section, defaultValue, false)

#define NFPB(field, name, section, shared, ...) NFEXUP(field, name, config::internal::FixFieldName(#field), section, shared, __VA_ARGS__)
#define NFPS(field, name, section, ...) NFPB(field, name, section, true, __VA_ARGS__)
#define NFP(field, name, section, ...) NFPB(field, name, section, false, __VA_ARGS__)

namespace config
{
	namespace internal
	{
		template<typename T>
		std::vector<T> s_Fields;

		void AddField(std::shared_ptr<FieldEntry> field);

		inline std::string FixFieldName(const std::string& fieldName)
		{
			if (fieldName.substr(1, 1) == "_")
				return fieldName.substr(2);
			return fieldName;
		}
	}

	template<typename T, typename... Args>
	Field<T> CreateField(const std::string& friendName, const std::string& name, const std::string& section, bool multiProfile, Args... args)
	{
		auto newField = Field<T>(friendName, name, section, T(args...), multiProfile);
		internal::s_Fields<Field<T>>.push_back(newField);
		internal::AddField(newField.entry());
		return newField;
	}

	template<typename T>
	std::vector<Field<T>>& GetFields()
	{
		return internal::s_Fields<Field<T>>;
	}

	void Initialize(const std::string& filePath);
	void SetupUpdate(TEvent<>*);

	void Refresh();
	void Save();

	void CreateProfile(const std::string& profileName, bool moveAfterCreate = true);
	void RemoveProfile(const std::string& profileName);
	void RenameProfile(const std::string& oldProfileName, const std::string& newProfileName);
	void ChangeProfile(const std::string& profileName);
	void DuplicateProfile(const std::string& profileName);
	std::vector<std::string> const& GetProfiles();
	std::string const& CurrentProfileName();

	extern TEvent<> ProfileChanged;
}