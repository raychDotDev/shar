#pragma once

typedef struct _screen Screen;
typedef struct _screen {
	void (*onLoad)(Screen*self);
	void (*onUnload)(Screen*self);
	void (*onDraw)(Screen*self);
	void (*onUpdate)(Screen*self);
} Screen;

Screen ScreenNew();
void ScreenDispose(Screen* self);

void ScreenLoad(Screen* self);
void ScreenUnload(Screen* self);
void ScreenDraw(Screen* self);
void ScreenUpdate(Screen* self);
