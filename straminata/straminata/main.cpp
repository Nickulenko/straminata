#include <Windows.h>
#include <iostream>
#include "display.h";

int main(void)
{
	//read settings from file
	//...


	const int g_width = 800;
	const int g_height = 600;
	const char* g_title = "Straminata";

	Display display(800, 600, "Straminata"); //create a display

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
		display.Update();
	}

	return 0;
}