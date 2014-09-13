class Timer
{
public:
	Timer();
	void Start(void);
	void Stop(void);
	unsigned int GetDelta();
protected:
private:
	unsigned int tBegin;
	unsigned int tEnd;
	unsigned int tDelta;
};

