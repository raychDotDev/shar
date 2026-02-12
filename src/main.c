#include <core/app.h>
#include <game/main_screen.h>
int main(int argc, char**argv) {
	AppInit("shar");
	AppSetScreen(MainScreenNew());
	AppRun();
	return 0;
}
