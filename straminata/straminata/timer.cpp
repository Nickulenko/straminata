#include "timer.h"
#include <ctime>
#include <chrono>

#include <iostream>

Timer::Timer()
{
	tDelta = 0;
}

void Timer::Start()
{
	auto tBegin = std::chrono::steady_clock::now();
}

void Timer::Stop()
{
	auto tEnd = std::chrono::steady_clock::now();
}

unsigned int Timer::GetDelta()
{
	auto tDelta = (tEnd - tBegin);
	std::cout << tBegin << std::endl;
	return tDelta;
}