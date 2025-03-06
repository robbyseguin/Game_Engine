#pragma once

#include <vector>
#include <queue>
#include <stdexcept>

using Entity = uint32_t;

const Entity MAX_ENTITIES = 5000;


class EntityManager
{
public:
	EntityManager()
	{
		for (Entity i = 0; i < MAX_ENTITIES; i++)
		{
			availableEntities.push(i);
			activeEntities.push_back(false);
		}
	}

	Entity CreateEntity()
	{
		if (availableEntities.empty())
		{
			throw std::runtime_error("Max entities reached!");
		}
		Entity id = availableEntities.front();
		availableEntities.pop();
		activeEntities[id] = true;	
		return id;
	}

	void DestroyEntity(Entity entity)
	{
		activeEntities[entity] = false;
		availableEntities.push(entity);
	}

	bool IsActive(Entity entity)
	{
		return activeEntities[entity];
	}

private:
	std::queue<Entity> availableEntities;
	std::vector<bool> activeEntities;

};

