#include <raylib.h>
#include <game/screen.h>

Screen ScreenNew() {
	Screen self = {};
	self.onLoad = nullptr;
	self.onUnload = nullptr;
	self.onDraw = nullptr;
	self.onUpdate = nullptr;
	return self;
}
void ScreenDispose(Screen* self) {
	if (self == nullptr) return;
	MemFree(self);
}

void ScreenLoad(Screen* self) {
	if (self == nullptr) return;
	if (self->onLoad != nullptr) {
		self->onLoad(self);
	}
}
void ScreenUnload(Screen* self) {
	if (self == nullptr) return;
	if (self->onUnload != nullptr) {
		self->onUnload(self);
	}
}
void ScreenDraw(Screen* self) {
	if (self == nullptr) return;
	if (self->onDraw != nullptr) {
		self->onDraw(self);
	}
}
void ScreenUpdate(Screen* self) {
	if (self == nullptr) return;
	if (self->onUpdate != nullptr) {
		self->onUpdate(self);
	}
}
