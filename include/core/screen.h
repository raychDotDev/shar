#pragma once

typedef struct _screen Screen;
typedef struct _screen {
	void (*load)(Screen* self);
	void (*unload)(Screen* self);
	void (*draw)(Screen* self);
	void (*update)(Screen* self, float dt);
} Screen;

Screen ScreenNew();

void ScreenDestroy(Screen* self);

void ScreenLoad(Screen* self);
void ScreenUnload(Screen* self);
void ScreenDraw(Screen* self);
void ScreenUpdate(Screen* self, float dt);
