#include <game/world.h>
#include <game/entity.h>

World* WorldNew(Vector2 size) {
	World* self = MemAlloc(sizeof(World));
	self->size = size;
	return self;
}

int _world_entities_sort(const void* a, const void* b) {
}

void WorldEntityPush(World* self, Entity value) {
	if (self == nullptr) 
		return;
	//TODO: Implement
}

void WorldDispose(World* self) {
	if (self == nullptr)
		return;
	MemFree(self);
}
