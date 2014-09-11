#include <Windows.h>
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"

int main(int argc, const char** argv)
{
	// Main ingame settings
	const int m_width = 800;
	const int m_height = 600;
	const char* m_title = "Straminata"; // game title
	const bool m_windowType = 0; // 0 - windowed, 1 - fullscreen
	const bool m_debugMode = 1; // 0 - release, 1 - debug

	Display display(m_width, m_height, m_title, m_windowType); // create a window

	if (!m_debugMode) ShowWindow(GetConsoleWindow(), SW_HIDE);
	/* Error text here
	MessageBox(0, L"Заголовок", L"Текст", MB_OK);
	*/

	Vertex vertices[] = {	Vertex(glm::vec3(-0.5, -0.5, 0)),
							Vertex(glm::vec3(0, 0.5, 0)),
							Vertex(glm::vec3(0.5, -0.5, 0)) };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");

	while (!display.IsClosed())
	{
		display.Clear(1.0f, 1.0f, 1.0f, 1.0f);

		shader.Bind();
		mesh.Draw();

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

/*
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
*/