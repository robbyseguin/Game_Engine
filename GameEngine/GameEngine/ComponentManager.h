#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "EntityManager.h"


class ComponentManager
{
public:
	template <typename T>
	void AddComponent(Entity entity, T& component)
	{
		entityComponents[typeid(T)][entity] = std::make_shared<std::remove_const_t<T>>(component);
	}

	template <typename... T>
	void AddComponents(Entity entity, const T&... components) {
		(AddComponent(entity, components), ...);
	}

	template <typename T>
	T* GetComponent(Entity entity)
	{
		auto typeIt = entityComponents.find(typeid(T));
		if (typeIt != entityComponents.end()) {
			auto entityIt = typeIt->second.find(entity);
			if (entityIt != typeIt->second.end()) {
				return static_cast<T*>(entityIt->second.get());
			}
		}
		return nullptr;
	}

	template <typename T>
	void RemoveComponent(Entity entity) {
		entityComponents[typeid(T)].erase(entity);
	}

private: 
	std::unordered_map<std::type_index, std::unordered_map<Entity, std::shared_ptr<void>>> entityComponents;
};

