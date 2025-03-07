#include <iostream>
#include "EntityManager.h"
#include "ComponentManager.h"
#include "Components.h"


int main()
{
	EntityManager entityManager;
	ComponentManager componentManager;

	Entity player = entityManager.CreateEntity();

	Position pos = { 0.0f, 0.0f };
	Velocity vel = { 1.0f, 1.5f };
	Health health = { 100 };

	componentManager.AddComponents(player, pos, vel, health);

	Position* posPtr = componentManager.GetComponent<Position>(player);
	Velocity* velPtr = componentManager.GetComponent<Velocity>(player);
	Health* healthPtr = componentManager.GetComponent<Health>(player);
	
	std::cout << "Position: " << posPtr->x << ", " << posPtr->y << std::endl;
	std::cout << "Velocity: " << velPtr->x << ", " << velPtr->y << std::endl;
	std::cout << "Health: " << healthPtr->value << std::endl;

	entityManager.DestroyEntity(player);

	return 0;
}
