#include <game/game.h>
#include <game/screen.h>
#include <raylib.h>

typedef struct _gameState {
	bool running;
	Screen *screen;
} GameState;

GameState *instance = nullptr;

void GameSetScreen(Screen* value) {
	if (instance->screen != nullptr) {
		ScreenUnload(instance->screen);
	}
	ScreenDispose(instance->screen);
	instance->screen = value;
	if (instance->screen != nullptr) {
		ScreenLoad(instance->screen);
	}
}
void GameStop() {
	instance->running = false;
}

void GameInit() {
	if (IsWindowReady()) return;
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitAudioDevice();
	InitWindow(720,480, "SHAR");
	SetTargetFPS(60);
	instance = MemAlloc(sizeof(GameState));
	instance->running = true;
}

void GameDestroy() {
	if (!IsWindowReady()) return;
	GameSetScreen(nullptr);
	MemFree(instance);
	CloseAudioDevice();
	CloseWindow();
}

void GameRun() {
	if (!IsWindowReady()) return;
	while(!WindowShouldClose() && instance->running) {
		ScreenUpdate(instance->screen);
		BeginDrawing();
		ClearBackground(BLACK);
		ScreenDraw(instance->screen);
		// DrawText("hi there", 10, 10, 20, WHITE);
		EndDrawing();
	}
	GameDestroy();
}
