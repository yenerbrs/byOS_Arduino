/*
 Name:		BasicTasking.ino
 Created:	6/5/2019 11:52:36 PM
 Author:	Barış Yener
*/

#include "byOS.h"

#define timerCount 1
uint16_t messageCount = 0;

by_TaskManager myTaskManager = by_TaskManager();

void myTask1(uint16_t message) {
  Serial.println("Task 1");
  by_Message messageToSend = { myTask2,messageCount };
  myTaskManager.sendMessage(&messageToSend);
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

by_BasicTimer timers[] =
{
	by_BasicTimer(1000,0,myTask1,true),
};

void setup()
{
	Serial.begin(115200);
	for (uint8_t a = 0; a < 10; a++) {
		pinMode(a, OUTPUT);
		digitalWrite(a, LOW);
	}
	digitalWrite(2, HIGH);
}

void loop()
{
	for (uint8_t a = 0; a < timerCount; a++)
		timers[a].check();
	myTaskManager.runTasks();
}



