#include <Windows.h>
#include <iostream>
#include <GLFW\glfw3.h>
#include "display.h";

int main(int argc, const char** argv)
{
	// Main ingame settings
	const int m_width = 800;
	const int m_height = 600;
	const char* m_title = "Straminata"; // game title
	const bool m_windowType = 0; // 0 - windowed, 1 - fullscreen
	const bool m_debugMode = 1; // 0 - release, 1 - debug

	Display display(m_width, m_height, m_title, m_windowType); //create a window

	if (!m_debugMode) ShowWindow(GetConsoleWindow(), SW_HIDE);

	while (!display.IsClosed())
	{
		display.Clear(1.0f, 1.0f, 1.0f, 1.0f);

		glBegin(GL_QUADS); // рисуем четырехугольник
		glColor3f(1.0f, 0.0f, 0.0f); // установка цвета рисования
			glVertex3f(0.0f, 0.0f, -4.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, -2.0f, -4.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(3.0f, -2.0f, -4.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(3.0f, 0.0f, -4.0f);
		glEnd();

		display.Update();

		// выход из цикла при нажатии esc или когда закрыли окно
		/*
		if (glfwGetKey(m_window, GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED)) 
			display.Close();
		*/

		// timer here
		// sleep for delta


	}

	return 0;
}