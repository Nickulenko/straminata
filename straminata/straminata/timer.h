#include <ctime>
#include <chrono>
#include <iostream>

class Timer
{
public:
	Timer() {}
	inline void Start(void)
	{
		tBegin = std::chrono::steady_clock::now();
	}
	inline void Stop(void)
	{
		tEnd = std::chrono::steady_clock::now();
	}
	double GetDelta()
	{
		tDelta = tEnd - tBegin;
		double Delta = double(tDelta.count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
		return Delta;
	}
protected:
private:
	std::chrono::steady_clock::time_point tBegin;
	std::chrono::steady_clock::time_point tEnd;
	std::chrono::steady_clock::duration  tDelta;
};

