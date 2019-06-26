# byOS - Software Timer And Tasking System

byOS library includes software timers and tasking system.

Timers can be set, updated, paused. Also timers can be delayed from the power on and they can be both single mode use or repetitive mode.

## Installation

Make sure you are running at least 1.6.x of the Arduino IDE.

Download library as zip and extract on the library folder. 

## Usage - Timers

```c
// Variable declaration:
by_BasicTimer timer1 = by_BasicTimer(IntervalMs,DelayMs,runningFunction,RepetitiveMod);

//some function to running
void runningFunction(){
	// do some stuff
}

//loop function
void loop(){
   timer1.check();
}
```

## Usage - Task System

```c
// Variable declaration:
by_TaskManager myTaskManager = by_TaskManager(); // init task manager

// Basic Task1
void myTask1(uint16_t message) {  
   // message is data incoming
   
  switch(message){
     case 0:
        //do stuff
     break;
     case 1:
        //do stuff
     break;
  }
}

void Start(){
    // message package decleration
    by_Message messageToSend = { myTask1,dataToSend };

    // sending message to queue
    myTaskManager.sendMessage(&messageToSend);
}

void loop(){
    //task manager will handle the messages
    myTaskManager.runTasks();
}

```


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[GNU Lesser General Public License](https://www.gnu.org/licenses/lgpl-3.0.en.html)