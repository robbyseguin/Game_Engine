#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "EntityManager.h"


class ComponentManager
{
public:

	template <typename T>
	void AddComponent(Entity entity, T& component);

	template <typename T>
	T* GetComponent(Entity entity);

	template <typename T>
	void RemoveComponent(Entity entity);

private: 
	std::unordered_map<Entity, std::unordered_map<std::type_index, std::shared_ptr<void>>> entityComponents;
};

