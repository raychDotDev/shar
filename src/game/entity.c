#include <game/entity.h>

Entity EntityNew() {
	Entity self = {};
	self.tag = -1;
	self.pos = (Vector2){0.f,0.f};
	self.vel = (Vector2){0.f,0.f};
	self.rad = 0.f;
	self.update = nullptr;
}
