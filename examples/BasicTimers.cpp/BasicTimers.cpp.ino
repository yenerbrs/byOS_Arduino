
/*
 * byOS Example 
 * Basic Timer Usage
 * In this example shows how to use software timers in byOS.
 * After power on, LED on the arduino (PIN13) will start blinking 1100ms when the timer2 calls myTimerTask2
 * Then every time led blinks it will update its interval time and slows blibking down when the timer1 calls myTimerTask1
 */


#include "byOS.h"

unsigned long interval = 100; // interval value for timer1

// timer1 - 5000ms interval, 0ms starting delay, runnig function is myTimerTask1,  repeating timer
by_BasicTimer timer1 = by_BasicTimer(5000,0,myTimerTask1,true);

// timer2 - 1000ms interval, 100ms starting delay, runnig function is myTimerTask2,not  repeating timer
by_BasicTimer timer2 = by_BasicTimer(1000,100,myTimerTask2,false);

// timer1 
// toggles the pin2
// increases and updates interval of timer2             
void myTimerTask1(){
  Serial.println("task1");
  digitalWrite(13,!digitalRead(13));
  interval+= 10;
  timer1.updateInterval(interval);
}

// timer2
// only runs one
void myTimerTask2(){
    Serial.println("task2");
    timer1.runNow(false); // run timer2 now with changing the normal timing
  // timer1.runNow(true); //run timer2 now without changing the normal timing
}

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
}

void loop() {
  // check the timers
  timer1.check();
  timer2.check();
}
