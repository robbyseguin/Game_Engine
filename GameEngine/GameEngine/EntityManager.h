#pragma once

#include <vector>
#include <queue>
#include <bitset>

using Entity = uint32_t;
const Entity MAX_ENTITIES = 5000;

class EntityManager
{
public:
	EntityManager();
	Entity CreateEntity();
	void DestroyEntity(Entity entity);
	bool IsActive(Entity entity) const;
private:
	std::queue<Entity> availableEntities;
	std::bitset<MAX_ENTITIES> activeEntities;
};

