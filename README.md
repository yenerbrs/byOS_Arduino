# byOS - Software Timer And Tasking System

byOS library includes software timers and tasking system.

Timers can be set, updated, paused. Also timers can be delayed from the power on and they can be both single mode use or repetitive mode.

## Installation

Make sure you are running at least 1.6.x of the Arduino IDE.

Download library as zip and extract on the library folder. 

## Usage - Timers

```c
// Variable declaration:
<div class="text-red">
  by_BasicTimer
</div> timer1 = <div class="text-red">by_BasicTimer</div>(IntervalMs,DelayMs,runningFunction,RepetitiveMod);

// in loop
timer1.check();
```

## Usage - Task System

```c

```


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[GNU Lesser General Public License](https://www.gnu.org/licenses/lgpl-3.0.en.html)