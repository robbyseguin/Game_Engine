#include "EntityManager.h"
#include <stdexcept>

EntityManager::EntityManager() {
    for (Entity i = 0; i < MAX_ENTITIES; i++) {
        availableEntities.push(i);
    }
}

Entity EntityManager::CreateEntity() {
	if (availableEntities.empty())
	{
		throw std::runtime_error("Max entities reached!");
	}
	Entity id = availableEntities.front();
	availableEntities.pop();
	activeEntities.set(id);
	return id;
}

void EntityManager::DestroyEntity(Entity entity) {
	activeEntities.reset(entity);
	availableEntities.push(entity);
}

bool EntityManager::IsActive(Entity entity) const {
    return activeEntities.test(entity);
}