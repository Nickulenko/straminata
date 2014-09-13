#include <iostream>
#include <Windows.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "timer.h"

#define FRAMERATE 30

int main(int argc, const char** argv)
{
	// Main ingame settings
	const int m_width = 800;
	const int m_height = 600;
	const char* m_title = "Straminata"; // game title
	const bool m_windowType = 0; // 0 - windowed, 1 - fullscreen
	const bool m_debugMode = 1; // 0 - release, 1 - debug

	// Initialization
	Timer loopTimer;

	Display display(m_width, m_height, m_title, m_windowType); // create a window

	if (!m_debugMode) ShowWindow(GetConsoleWindow(), SW_HIDE);
	/* Error text here
	MessageBox(0, L"Заголовок", L"Текст", MB_OK);
	*/

	Vertex vertices[] = {	Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
							Vertex(glm::vec3(0.0, 0.5, 0.0), glm::vec2(0.5, 1.0)),
							Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)) };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");

	// Maint Loop
	while (!display.IsClosed())
	{
		// update parameters
		loopTimer.Start(); // start timer

		display.Clear(1.0f, 1.0f, 1.0f, 1.0f);

		shader.Bind();
		texture.Bind();
		mesh.Draw();

		display.Update();
				
		loopTimer.Stop(); // stop timer
		Sleep((1 / FRAMERATE) - (loopTimer.GetDelta()));// // count delta sleep for delta
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