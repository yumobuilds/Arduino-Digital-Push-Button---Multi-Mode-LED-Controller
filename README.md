# Arduino Digital Push Button - Multi-Mode LED Controller

A simple Arduino project that uses a digital push button module to cycle through multiple LED lighting modes. Each button press changes the active mode, making this a great beginner project for learning button input, state changes, debouncing, and non-blocking timing with `millis()`.

 ✨ Features

* 5 LED operating modes
* Button press detection
* Software debouncing
* Non-blocking LED animations using `millis()`
* Easy to customize and expand

---

 📦 Hardware Required

| Component                  |    Quantity |
| -------------------------- | ----------: |
| Arduino UNO                |           1 |
| Digital Push Button Module |           1 |
| White LED                  |           1 |
| Blue LED                   |           1 |
| 220Ω Resistors             |           2 |
| Breadboard                 |           1 |
| USB Cable                  |           1 |
| Jumper Wires               | As Required |

---
 🔌 Wiring

Digital Push Button Module

| Module Pin | Arduino Pin |
| ---------- | ----------- |
| S (Signal) | Digital 3   |
| + (VCC)    | 5V          |
| – (GND)    | GND         |

LEDs

| LED           | Arduino Pin                 |
| ------------- | --------------------------- |
| White LED (+) | Digital 12                  |
| Blue LED (+)  | Digital 13                  |
| Both LED (-)  | GND (through 220Ω resistor) |


 🎮 LED Modes

| Button Press | White LED                 | Blue LED                  |
| ------------ | ------------------------- | ------------------------- |
| Start        | OFF                       | OFF                       |
| 1            | ON                        | OFF                       |
| 2            | OFF                       | ON                        |
| 3            | Flash Together            | Flash Together            |
| 4            | Alternate (Police Effect) | Alternate (Police Effect) |
| 5            | OFF                       | OFF                       |
| Repeat       | Starts Again              | Starts Again              |

---

## ⚙️ How It Works

The digital push button module is connected to **Digital Pin 3** and is configured as an **active LOW** input. Every time the button is pressed, the Arduino increments a mode counter.

A `switch` statement selects the current lighting mode:

* **Mode 0** — Both LEDs OFF
* **Mode 1** — White LED ON
* **Mode 2** — Blue LED ON
* **Mode 3** — Both LEDs flash together
* **Mode 4** — Alternate flashing to create a police light effect

The flashing animations use Arduino's `millis()` function instead of `delay()`, allowing smooth, non-blocking timing that can easily be expanded for larger projects.

---

⚡ Customizing the Effects

Adjust these values to change the flashing speed:

```cpp
const unsigned long flashInterval = 100;   // Faster both-flash
const unsigned long policeInterval = 250;  // Faster police lights
```

Increase the values for slower animations or decrease them for faster effects.

---

📋 Specifications

| Property        | Value                 |
| --------------- | --------------------- |
| Working Voltage | 3.3V – 5V             |
| Interface       | Digital               |
| Button Type     | Momentary Push Button |
| Logic Level     | Active LOW            |
| Operating Mode  | Digital Input         |

---

📝 Notes

* No external libraries are required.
* Uses software debouncing for reliable button presses.
* Uses `millis()` for non-blocking LED animations.
* Great beginner project for learning digital inputs, state machines, and LED control.
* Easily expandable with additional LEDs, buzzers, relays, or other outputs.

---

📄 License

This project is open source and available under the MIT License.

Feel free to modify, improve, and share it.
