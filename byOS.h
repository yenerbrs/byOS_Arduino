// byOS.h

#ifndef _BYOS_h
#define _BYOS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class by_BasicTimer{
public:
	by_BasicTimer(unsigned long intervalMs,unsigned long startDelayMs, void *basicTask,bool repeat);
	void check();
	void pause();
	void resume();
	void updateInterval(unsigned long intervalMs);
	void runNow(bool dontDisruptTiming);

private:
	unsigned long intervalMs, lastRun;
	bool repeat;
	void (*basicTask)();
	bool isTimerRunning;
};

typedef void(*basicTaskPtr)(uint16_t message);

typedef struct  {
	basicTaskPtr target;
	uint16_t message;
	//uint32_t timeSent;
}by_Message;



class by_TaskManager {
public:
	by_TaskManager();
	void runTasks();
	void sendMessage(by_Message *message);
private:
	uint16_t messagePutNext;
	uint16_t messageReadNext;
	by_Message messageBuffer[50];
};


#endif

