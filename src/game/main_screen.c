#include <raylib.h>
#include <core/app.h>
#include <core/screen.h>
#include <game/main_screen.h>

typedef struct _mainScreen {
	Screen base;
	float time;
} MainScreen;

void _main_screen_update(Screen* s, float dt) {
	if (s == nullptr) return;
	MainScreen* self = (MainScreen*)s;
	self->time += dt;
	if (IsKeyPressed(KEY_SPACE)) {
		AppSetScreen(MainScreenNew());
	}
}
void _main_screen_draw(Screen* s) {
	if (s == nullptr) return;
	MainScreen* self = (MainScreen*)s;
	DrawText(TextFormat("%.2f", self->time), 10, 10, 20, RED);
}

Screen* MainScreenNew() {
	MainScreen* self = (MainScreen*)MemAlloc(sizeof(MainScreen));
	self->base = ScreenNew();
	self->base.draw = _main_screen_draw;
	self->base.update = _main_screen_update;
	self->time = 0.f;
	return (Screen*)self;
}
