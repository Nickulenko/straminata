#include <Windows.h>
#include <iostream>
#include <GLFW\glfw3.h>
#include "display.h";

int main(int argc, const char** argv)
{
	const int m_width = 800;
	const int m_height = 600;
	const char* m_title = "Straminata"; // game title
	const bool m_windowType = 0; // 0 - windowed, 1 - fullscreen

	Display display(m_width, m_height, m_title, m_windowType); //create a window

	while (!display.IsClosed())
	{
		display.Clear(1.0f, 1.0f, 1.0f, 1.0f);

		glMatrixMode(GL_PROJECTION); // ������ ������� ������� ��������������
		glLoadIdentity(); // �������� ��������� �������

		glMatrixMode(GL_MODELVIEW); // ������ ������� ��������� �������
		glLoadIdentity(); // ��������� ��������� �������

		glBegin(GL_QUADS); // ������ ���������������
		glColor3f(1.0f, 0.0f, 0.0f); // ��������� ����� ���������
		// ������� ������� ������� ������
			glVertex3f(0.0f, 0.0f, -4.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0f, -2.0f, -4.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(3.0f, -2.0f, -4.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(3.0f, 0.0f, -4.0f);
		glEnd();

		display.Update();

		// ����� �� ����� ��� ������� esc ��� ����� ������� ����
		/*
		if (glfwGetKey(m_window, GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED)) 
			display.Close();
		*/

		// timer here
		// sleep for delta


	}

	return 0;
}