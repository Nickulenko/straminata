#include <iostream>
#include <Windows.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "timer.h"

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
	Transform transform;

	float counter = 0.0f;

	// Maint Loop
	while (!display.IsClosed())
	{
		// update parameters
//		loopTimer.Start(); // Start timer

		display.Clear(1.0f, 1.0f, 1.0f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPos().x = sinf(counter);
		transform.GetRot().z = counter * 50;
		transform.SetScale(glm::vec3(cosCounter, sinCounter, cosCounter));

		shader.Bind();
		texture.Bind();
		shader.Update(transform);
		mesh.Draw();
		
		display.Update();
		counter += 0.001f;
				
//		loopTimer.Stop(); // stop timer
		//double sleepTime = double(0.33) - loopTimer.GetDelta();
		//std::cout << double(0.33) - loopTimer.GetDelta() << std::endl;
	//	Sleep(sleepTime); // Count delta and sleep
	}
	// Deinitialize

	return 0;
}