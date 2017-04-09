#include <SFML\Graphics.hpp>

#include "game\game.h"

#ifdef SP_DEBUG
int main()
#else
#include <windows.h>
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
#endif
{
	Game game(1000, 1000, 100, false);
}