#pragma once

#include <raymath.h>

typedef struct _entity Entity;
typedef struct _entity {
	int tag;
	Vector2 pos, vel;
	float rad;
	void (*update)(Entity* self);
} Entity;

Entity EntityNew();
