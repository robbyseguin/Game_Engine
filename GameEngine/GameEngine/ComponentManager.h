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
		entityComponents[typeid(T)][entity] = new T(component);
	}

	template <typename T>
	T* GetComponent(Entity entity)
	{
		auto it = entityComponents[typeid(T)].find(entity);
		return (it != entityComponents[typeid(T)].end()) ? static_cast<T*>(it->second.get()) : nullptr;
	}


private:
	std::unordered_map<Entity, std::unordered_map<std::type_index, std::shared_ptr<void>>> entityComponents;
};

