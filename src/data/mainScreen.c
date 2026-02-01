#include <game/game.h>
#include <game/screen.h>
#include <data/mainScreen.h>
#include <raylib.h>

typedef struct _mainScreen {
	Screen base;
	float testValue;
} MainScreen;

void _mainScreen_draw(Screen* s) {
	MainScreen* self = (MainScreen*)s;
	DrawText(TextFormat("%.2f", self->testValue), 10, 10, 20, WHITE);
}

void _mainScreen_update(Screen* s) {
	MainScreen* self = (MainScreen*)s;
	self->testValue += GetFrameTime();
	if (IsKeyPressed(KEY_SPACE)) {
		GameSetScreen(MainScreenNew());
	}
}

Screen* MainScreenNew() {
	MainScreen* self = MemAlloc(sizeof(MainScreen));
	self->base = ScreenNew();
	self->testValue = 0.f;
	self->base.onDraw = _mainScreen_draw;
	self->base.onUpdate = _mainScreen_update;
	return (Screen*)self;
}
