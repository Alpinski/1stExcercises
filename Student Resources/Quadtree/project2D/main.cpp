#include "Application2D.h"
#include "HelperFunctions.h"

int main() 
{
	Application2D* app = new Application2D();
	app->run("AIE", SCREEN_WIDTH, SCREEN_HEIGHT, false);
	delete app;

	return 0;
}