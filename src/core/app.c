#include <core/app.h>
#include <raylib.h>

typedef struct _app {
	bool running;
	// Screen* context;
	RenderTexture* canvas;
} App;

#define APP_WINDOW_START_W 720
#define APP_WINDOW_START_H 480

#define APP_CANVAS_STATIC_H 320

void _app_reloadCanvas(RenderTexture* canvas, 
		const int w, const int h) {
	if (canvas == nullptr) return;
	if (IsTextureValid(canvas->texture)) {
		UnloadRenderTexture(*canvas);
	}
	*canvas = LoadRenderTexture(w,h);
}

static App* instance = nullptr;

void AppInit(const char* title) {
	if (instance != nullptr) {
		return;
	}
	SetConfigFlags(FLAG_VSYNC_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(APP_WINDOW_START_W, APP_WINDOW_START_H, title);
	instance = (App*)MemAlloc(sizeof(App));
	instance->running = true;
	float scale = (float)APP_CANVAS_STATIC_H / 
				(float)APP_WINDOW_START_H;

	const int cw = (int)(APP_WINDOW_START_W * scale);
	const int ch = APP_CANVAS_STATIC_H;
	instance->canvas = MemAlloc(sizeof(RenderTexture));
	_app_reloadCanvas(instance->canvas, cw, ch);
}
void AppDispose() {
	if (instance == nullptr) return;
	// AppSetScreen(nullptr);
	UnloadRenderTexture(*instance->canvas);
	MemFree(instance->canvas);
	MemFree(instance);
	CloseWindow();
}

void _app_drawCanvas() {
	if (instance == nullptr) return;
	DrawFPS(10, 10);
}

void AppRun() {
	if (instance == nullptr) return;
	while(instance->running && !WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		_app_drawCanvas();
		EndDrawing();
	}
	AppDispose();
}
