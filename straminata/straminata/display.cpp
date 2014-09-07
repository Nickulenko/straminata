#include "display.h"
#include <iostream>
#include <GLFW/glfw3.h>

Display::Display(int width, int height, const char* title, const bool windowType)
{
	// Initialization GLFW + OpenGL
	if (!glfwInit())
		exit(EXIT_FAILURE);
	// Setting window parameters
	m_monitorInfo = glfwGetVideoMode(glfwGetPrimaryMonitor());

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); //изменение размера окна

	// Creating window
	if (windowType == 0) m_window = glfwCreateWindow(width, height, title, NULL, NULL); // Windowed
	else m_window = glfwCreateWindow(m_monitorInfo->width, m_monitorInfo->height, title, glfwGetPrimaryMonitor(), nullptr); // Fullscreen

	//preparing it
	glfwMakeContextCurrent(m_window);
	//window is not closed
	m_isClosed = false;
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::Update()
{
	glfwSwapBuffers(m_window);
	if (glfwWindowShouldClose(m_window))
		m_isClosed = true;
}

bool Display::IsClosed()
{
	return m_isClosed;
}

Display::~Display()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}