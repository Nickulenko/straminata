#include <GLFW\glfw3.h>

class Display
{
public:
	Display(int width, int height, const char* title);

	void Clear(float r, float g, float b, float a);
	void Update();
	bool IsClosed();

	virtual ~Display();
private:
	Display(const Display& other) {}
	Display& operator=(const Display& other) {}

	GLFWvidmode m_windowInfo;
	GLFWmonitor *m_monitor;
	GLFWwindow* m_window;
	bool m_isClosed;
};