#include "display.h"
#include <iostream>
#include <GLFW/glfw3.h>

Display::Display(int width, int height, const char* title)
{
	//initialization GLFW + OpenGL
	if (!glfwInit())
		exit(EXIT_FAILURE);
	//setting window parameters
	//glfwWindowHint();
	//creating window
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	//preparing it
	glfwMakeContextCurrent(m_window);
	//window is not closed
	m_isClosed = false;

	//GLFW_FULLSCREEN
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