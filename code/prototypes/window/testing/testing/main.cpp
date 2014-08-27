#include <iostream>
#include <Windows.h> // sleep()
//#include "input.cpp"

void startup();
void update();
void draw();
void shutdown();

bool quit;
const int m_SleepTime = 100;

int main()
{
	startup();
	int count = 1;
	while (quit != true)
	{
		std::cout << count << " tick\n";
		update();
		draw();
		count++;
		Sleep(m_SleepTime);
	}
	shutdown();
	return 0;
}
void startup()
{
	std::cout << "starting up the system!\n";
	Sleep(m_SleepTime);
}
void update()
{
	std::cout << "updating frame\n";
}
void draw()
{
	std::cout << "drawing frame\n";
}
void shutdown()
{
	std::cout << "shutting down the system!\n";
	Sleep(m_SleepTime);
}