#include <Windows.h>
#include <iostream>
#include "display.h";

int main(void)
{
	const int m_width = 800;
	const int m_height = 600;
	const char* g_title = "Straminata";

	Display display(m_width, m_height, g_title); //create a window

	while (!display.IsClosed())
	{
		display.Clear(0.5f, 0.15f, 0.3f, 1.0f);
		display.Update();
	}

	return 0;
}