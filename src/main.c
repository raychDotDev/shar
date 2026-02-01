#include <game/game.h>
#include <data/mainScreen.h>

int main(int argc, char**argv) {
	GameInit();
	GameSetScreen(MainScreenNew());
	GameRun();
	return 0;
}
