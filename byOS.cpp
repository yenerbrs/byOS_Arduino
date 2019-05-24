// 
// 
// 

#include "byOS.h"


by_BasicTimer::by_BasicTimer(unsigned long intervalMs, unsigned long startDelayMs, void *basicTask, bool repeat) {
	this->intervalMs = intervalMs;
	this->repeat = repeat;
	this->basicTask = basicTask;
	this->isTimerRunning = true;
	this->lastRun = millis() + startDelayMs;
}

void by_BasicTimer::check() {

	if (isTimerRunning) {
		if (millis() >= (this->lastRun + this->intervalMs)) {
			this->runNow(false);
		}
	}
	else {

	}
}

void by_BasicTimer::pause() {
	this->isTimerRunning = false;
}

void by_BasicTimer::resume() {
	this->isTimerRunning = true;
}

void by_BasicTimer::updateInterval(unsigned long intervalMs) {
	this->intervalMs = intervalMs;
}

void by_BasicTimer::runNow(bool dontDisruptTiming) {

	if (!dontDisruptTiming) {
		this->lastRun = millis();
	}
	basicTask();
	if (!this->repeat)
		this->pause();
}

by_TaskManager::by_TaskManager() {
	this->messagePutNext = 0;
	this->messageReadNext = 0;
}

void by_TaskManager::runTasks() {
	while (messageReadNext != messagePutNext) {
		basicTaskPtr basicTask = (messageBuffer[messageReadNext].target);
		basicTask(messageBuffer[messagePutNext].message);
		messageReadNext++;
		if (messageReadNext >= 50)
			messageReadNext = 0;
	}
}

void by_TaskManager::sendMessage(by_Message *message) {
	if (this->messagePutNext >= 50)
		this->messagePutNext = 0;
	//message->timeSent = millis();
	messageBuffer[messagePutNext] = *message;
	messagePutNext++;
}


