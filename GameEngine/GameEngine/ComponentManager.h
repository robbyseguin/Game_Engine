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
		entity
	}

private:
	std::unordered_map<Entity, std::unordered_map<std::type_index, std::shared_ptr<void>>> entityComponents;
};

