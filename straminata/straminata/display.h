#include <string>
#include <GLFW\glfw3.h>

class Display
{
public:
	Display(int width, int height, std::string title, const bool windowType);

	void Clear(float r, float g, float b, float a);
	void Update();
	bool IsClosed();
	void Close();

	virtual ~Display();
private:
	Display(const Display& other) {}
	Display& operator=(const Display& other) {}

	const GLFWvidmode* m_monitorInfo;
	GLFWwindow* m_window;
	bool m_isClosed;
};