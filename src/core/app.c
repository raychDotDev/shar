#include <core/app.h>
#include <core/screen.h>
#include <raylib.h>
typedef struct _app {
	bool running;
	Screen* context;
	RenderTexture* canvas;
	int oldAppW;
	int oldAppH;
} App;

#define APP_WINDOW_START_W 720
#define APP_WINDOW_START_H 480

#define APP_CANVAS_STATIC_H 320

void _app_reloadCanvas(RenderTexture* canvas, 
		const int w, const int h) {
	if (canvas == nullptr) {
		TraceLog(LOG_ERROR, "APP: NO CANVAS INSTANCE!");
		return;
	}
	if (IsTextureValid(canvas->texture)) {
		TraceLog(LOG_INFO, "APP: Unloading old canvas...");
		UnloadRenderTexture(*canvas);
	}
	TraceLog(LOG_INFO, "APP: Loading new canvas...");
	*canvas = LoadRenderTexture(w,h);
	TraceLog(LOG_INFO, "APP: Finished loading new canvas");
}

static App* instance = nullptr;

void AppInit(const char* title) {
	if (instance != nullptr) {
		TraceLog(LOG_ERROR, "APP: App already initialized");
		return;
	}
	
	SetConfigFlags(FLAG_VSYNC_HINT);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(APP_WINDOW_START_W, APP_WINDOW_START_H, title);
	
	SetWindowMinSize(APP_WINDOW_START_W, APP_WINDOW_START_H);
	instance = (App*)MemAlloc(sizeof(App));
	instance->running = true;

	instance->canvas = MemAlloc(sizeof(RenderTexture));
	instance->oldAppW = 0;
	instance->oldAppH = 0;
}
void AppDispose() {
	if (instance == nullptr) {
		TraceLog(LOG_ERROR, "APP: NO APP INSTANCE!");
		return;
	}
	AppSetScreen(nullptr);
	UnloadRenderTexture(*instance->canvas);
	MemFree(instance->canvas);
	MemFree(instance);
	CloseWindow();
}

void _app_updateCanvas() {
	if (instance == nullptr) {
		TraceLog(LOG_ERROR, "APP: NO APP INSTANCE!");
		return;
	}
	const int w = GetScreenWidth();
	const int h = GetScreenHeight();
	if (w != instance->oldAppW || h != instance->oldAppH) {
		float scale = (float)APP_CANVAS_STATIC_H / 
			(float)h;
		const int cw = (int)(w * scale);
		TraceLog(LOG_INFO, "%d", cw);
		const int ch = APP_CANVAS_STATIC_H;
		_app_reloadCanvas(instance->canvas, cw, ch);
		instance->oldAppW = w;
		instance->oldAppH = h;
	}
}
void _app_drawCanvas() {
	if (instance == nullptr) {
		TraceLog(LOG_ERROR, "APP: NO APP INSTANCE!");
		return;
	}

	const float cw = instance->canvas->texture.width;
	const float ch = instance->canvas->texture.height;
	
	const float h = GetScreenHeight();
	const float scale = (h/ch);
	float dw = cw * scale;
	float dh = ch * scale;
	Rectangle src = {
		0,
		0, 
		cw,
		-ch
	};

	Rectangle dest = {
		0,
		0, 
		dw,
		dh
	};

	DrawTexturePro(
			instance->canvas->texture, 
			src, dest, 
			(Vector2){0,0},
			0.f, 
			WHITE);
}

void AppRun() {
	if (instance == nullptr) {
		TraceLog(LOG_ERROR, "APP: NO APP INSTANCE!");
		return;
	}
	while(instance->running && !WindowShouldClose()) {
		_app_updateCanvas();
		ScreenUpdate(instance->context, GetFrameTime());

		BeginTextureMode(*instance->canvas);
		ClearBackground(WHITE);
		ScreenDraw(instance->context);
		EndTextureMode();

		BeginDrawing();
		ClearBackground(BLACK);
		_app_drawCanvas();
		EndDrawing();
	}
	AppDispose();
}

void AppSetScreen(Screen *value) {
	if (instance == nullptr) {
		TraceLog(LOG_WARNING, "APP: NO APP INSTANCE!");
		return;
	}
	TraceLog(LOG_INFO, "APP: Unloading current screen...");
	ScreenUnload(instance->context);
	if (instance->context != nullptr) {
		ScreenDestroy(instance->context);
	}
	TraceLog(LOG_INFO, "APP: Setting new value to instance->screen");
	instance->context= value;
	TraceLog(LOG_INFO, "APP: Loading current screen...");
	ScreenLoad(instance->context);
	TraceLog(LOG_INFO, "APP: Finished screen setting");
}
