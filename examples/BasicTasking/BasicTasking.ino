#include "byOS.h"

uint16_t messageCount = 0; // message count sent by tasks

by_TaskManager myTaskManager = by_TaskManager(); // init task manager

void myTask1(uint16_t message) {  // basic task. use "message" variable to pass variables or states
  Serial.println("Task 1");
  by_Message messageToSend = { myTask2,messageCount }; // preparing message 
  myTaskManager.sendMessage(&messageToSend); // sending message
  messageCount++;
}

void myTask2(uint16_t message) {
  Serial.println("Task 2");
  by_Message messageToSend = { myTask3,messageCount };
  myTaskManager.sendMessage(&messageToSend);
  messageCount++;
}

void myTask3(uint16_t message) {
  Serial.println("Task 3");
  by_Message messageToSend = { myTask4,messageCount };
  myTaskManager.sendMessage(&messageToSend);
  messageCount++;
}

void myTask4(uint16_t message) {
  Serial.println("Task 4");
  Serial.println(messageCount);
  Serial.println("function in mess" + message);
}

// timerCount will be used in the loop function. 
#define timerCount 1
// timer holder array. You can use timers without the array. 
by_BasicTimer timers[] =
{
	// Software Timer. Calls the "myTask1" function for every 1000 ms with 0 starting delay.
	// If you want to use single shot timer you can use "by_BasicTimer(1000,0,myTask1,false)"
	by_BasicTimer(1000,0,myTask1,true),  
};

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	// check timers
	for (uint8_t a = 0; a < timerCount; a++)
		timers[a].check();
	// run taskmanager
	myTaskManager.runTasks();
}
