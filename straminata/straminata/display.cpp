#include <iostream>
#include <GL/glew.h>
#include "display.h"

Display::Display(int width, int height, const char* title, const bool windowType)
{
	// Initialization GLFW + OpenGL
	if (!glfwInit()) exit(EXIT_FAILURE);
	// Setting window parameters
	m_monitorInfo = glfwGetVideoMode(glfwGetPrimaryMonitor());
	// Setting OpenGL parameters
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // ������������ ������� ������ opengl 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // ����������� ������� ������ opengl 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // ������������ ������� ������� opengl
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE); // ����������� ������ ������� ����
	// Colour depth
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	glfwWindowHint(GLFW_AUX_BUFFERS, 32);
	// Creating window
	if (windowType == 0) m_window = glfwCreateWindow(width, height, title, NULL, NULL); // Windowed
	else m_window = glfwCreateWindow(m_monitorInfo->width, m_monitorInfo->height, title, glfwGetPrimaryMonitor(), nullptr); // Fullscreen
	// Preparing window
	glfwMakeContextCurrent(m_window);

	glewExperimental = GL_TRUE;

	GLenum status = glewInit();

	if (status != GLEW_OK)
	{
		std::cerr << "GLEW failed to initialize" << std::endl;
		exit(1);
	}

	// Window is not closed
	m_isClosed = false;
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a); // ��������� ����� �������
	glClear(GL_COLOR_BUFFER_BIT); // ������ 
}

void Display::Update()
{
	glfwSwapBuffers(m_window); // ������ ������ ����� � �������� �������
	glfwPollEvents();
	if (glfwWindowShouldClose(m_window))
		m_isClosed = true;
}

bool Display::IsClosed()
{
	return m_isClosed;
}

void Display::Close()
{
	m_isClosed = true;
}

Display::~Display()
{
	glfwDestroyWindow(m_window); // and context too
	glfwTerminate();
}