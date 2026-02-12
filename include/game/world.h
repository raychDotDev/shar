#pragma once

#include <raylib.h>
#include <raymath.h>

typedef struct _entity Entity;
typedef struct _world {
	Vector2 size;
	Entity * entities;
	unsigned int entitiesCount;
	unsigned int entitiesCapacity;
} World;

World* WorldNew(Vector2 size);

void WorldEntityPush(World* self, Entity value);
Entity WorldEntityPop(World* self, int index);

void WorldDispose(World* self);
