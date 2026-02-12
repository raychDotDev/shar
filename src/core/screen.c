#include <raylib.h>
#include <core/screen.h>

Screen ScreenNew() {
	Screen res;
	res = (Screen){
		.load = nullptr,
		.unload = nullptr,
		.draw = nullptr,
		.update = nullptr,
	};
	return res;
}

void ScreenDestroy(Screen* self) {
	if (self == nullptr) {
		return;
	}
	MemFree(self);
}

void ScreenLoad(Screen* self) {
	if (self == nullptr) return;
	if (self->load != nullptr) {
		self->load(self);
	}
}
void ScreenUnload(Screen* self) {
	if (self == nullptr) return;
	if (self->unload != nullptr) {
		self->unload(self);
	}
}
void ScreenDraw(Screen* self) {
	if (self == nullptr) return;
	if (self->draw != nullptr) {
		self->draw(self);
	}
}
void ScreenUpdate(Screen* self, float dt) {
	if (self == nullptr) return;
	if (self->update != nullptr) {
		self->update(self, dt);
	}
}
