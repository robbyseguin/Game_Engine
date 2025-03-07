#include "ComponentManager.h"

template <typename T>
void ComponentManager::AddComponent(Entity entity, T& component)
{
	entityComponents[typeid(T)][entity] = new T(component);
}

template <typename T>
T* ComponentManager::GetComponent(Entity entity)
{
	auto it = entityComponents[typeid(T)].find(entity);
	return (it != entityComponents[typeid(T)].end()) ? static_cast<T*>(it->second.get()) : nullptr;
}

template <typename T>
void ComponentManager::RemoveComponent(Entity entity) {
	entityComponents[typeid(T)].erase(entity);
}