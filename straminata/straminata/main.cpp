#include <Windows.h>
#include <iostream>
#include "display.h";

int main(void)
{
	const int m_width = 800;
	const int m_height = 600;
	const char* m_title = "Straminata";
	const bool m_windowType = 1;

	Display display(m_width, m_height, m_title, m_windowType); //create a window

	while (!display.IsClosed())
	{
		display.Clear(0.5f, 0.15f, 0.3f, 1.0f);
		display.Update();
	}

	return 0;
}