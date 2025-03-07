#pragma once

#include <vector>
#include <queue>
#include <stdexcept>
#include <bitset>

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
		activeEntities.set(id);	
		return id;
	}

	void DestroyEntity(Entity entity)
	{
		activeEntities.reset(entity);
		availableEntities.push(entity);
	}

	bool IsActive(Entity entity)
	{
		return activeEntities.test(entity);
	}

private:
	std::queue<Entity> availableEntities;
	std::bitset<MAX_ENTITIES> activeEntities;

};

