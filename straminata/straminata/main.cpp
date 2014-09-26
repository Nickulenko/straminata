/*
	Straminata project
	JustBear
	In development by Matthew Poletin
	All rights reserved
*/

#include <iostream>
#include <Windows.h>
#include "main_display.h"
#include "timer.h"

// Main ingame settings
const int width = 800;
const int height = 600;
const std::string title = "Straminata"; // game title
const bool windowType = 0; // 0 - windowed, 1 - fullscreen
const bool debugMode = 1; // 0 - release, 1 - debug

int main(int argc, const char** argv)
{
	Vertex vertices[] = {	Vertex(glm::vec3(-0.5, -0.5, 0.0),	glm::vec2(0.0, 0.0)),
							Vertex(glm::vec3(0.0, 0.5, 0.0),	glm::vec2(0.5, 1.0)),
							Vertex(glm::vec3(0.5, -0.5, 0.0),	glm::vec2(1.0, 0.0)) };

	// Initialization
	Timer loopTimer;
	Timer frameTimer;

	Display display(width, height, title, windowType); // create a window

	if (!debugMode) ShowWindow(GetConsoleWindow(), SW_HIDE);
	/* Error text here
	MessageBox(0, L"Заголовок", L"Текст", MB_OK);
	*/

	// initialize actor
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Shader shader("./res/basicShader");
	Texture texture("./res/bricks.jpg");
	Camera camera(glm::vec3(0, 0, -2), 70.0f, (float)width/(float)height, 0.01f, 1000.0f);
	Transform transform;
	//-----
	
	float counter = 0.0f;

	// Maint Loop
	while (!display.IsClosed())
	{
		frameTimer.Start();
		loopTimer.Start();

		display.Clear(1.0f, 1.0f, 1.0f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPos().x = sinf(counter);
		transform.GetPos().z = cosf(counter);
		transform.GetRot().x = counter * 50;
		transform.GetRot().y = counter * 50;
		transform.GetRot().z = counter * 50;
		//transform.SetScale(glm::vec3(cosCounter, sinCounter, cosCounter));

		shader.Bind();
		texture.Bind();
		shader.Update(transform, camera);
		mesh.Draw();
		
		display.Update();
		counter += 0.001f;

		loopTimer.Stop(); // stop timer
		double sleepTime = (double)33.33 - 1000 * loopTimer.GetDelta();
		std::cout << 1000 * loopTimer.GetDelta() << std::endl;
		//WaitMS((int)sleepTime);

		frameTimer.Stop();
		std::cout << frameTimer.GetDelta() << std::endl;
	}
	// Deinitialize
	texture.~Texture();
	shader.~Shader();
	mesh.~Mesh();

	return 0;
}