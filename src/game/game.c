#include <game/game.h>
#include <raylib.h>

typedef struct _gameState {
	bool running;
	// Screen screen;
} GameState;

GameState *instance = nullptr;

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
	MemFree(instance);
	// TODO: Add something else
	CloseAudioDevice();
	CloseWindow();
}

void GameRun() {
	if (!IsWindowReady()) return;
	while(!WindowShouldClose() && instance->running) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("hi there", 10, 10, 20, WHITE);
		EndDrawing();
	}
	GameDestroy();
}
