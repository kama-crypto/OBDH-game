SkyPatrol OBDH

A small Arduino UNO project that simulates a satellite **On-Board Data Handling (OBDH)** console. You send text commands over the serial port; the board responds by driving an LED, a piezo buzzer and a 16x2 LCD. It also hides a little password-guessing game.

## Features

- Serial command interface at 9600 baud
- LED control (`On`, `Off`) and state report (`STATUS`)
- Distinct buzzer tones for each command
- Status messages on a 16x2 LCD
- Hidden password game (`game` or `???`)

## Hardware

| Qty | Component |
|-----|-----------|
| 1 | Arduino UNO |
| 1 | 16x2 character LCD (HD44780, parallel) |
| 1 | 10 kΩ potentiometer (LCD contrast) |
| 1 | Passive piezo buzzer |
| 1 | LED (red) |
| 2 | Resistors for LED and LCD backlight (typically 220 Ω) |
| 1 | Resistor for the buzzer line, as in the diagram |
| 1 | Breadboard and jumper wires |

## Wiring

| Arduino pin | Connected to |
|-------------|--------------|
| D12 | LCD RS |
| D11 | LCD E |
| D5 | LCD D4 |
| D4 | LCD D5 |
| D3 | LCD D6 |
| D2 | LCD D7 |
| D8 | LED (through resistor) |
| D6 | Buzzer + |
| 5V / GND | Power rails |

LCD notes: RW goes to GND, VO to the potentiometer wiper, and the backlight LED+ pin to 5V through a resistor (LED- to GND). See [docs/wiring.md](docs/wiring.md) for details.

## Getting started

1. Install the [Arduino IDE](https://www.arduino.cc/en/software) (the `LiquidCrystal` library is bundled).
2. Open `SkyPatrol_OBDH/SkyPatrol_OBDH.ino`.
3. Select **Arduino Uno** and your port, then upload.
4. Open the Serial Monitor at **9600 baud** with line ending set to **Newline**.

## Commands

| Command | Action |
|---------|--------|
| `On` | LED on, two beeps |
| `Off` | LED off, one beep |
| `STATUS` | Shows whether the LED is on or off |
| `game` / `???` | Starts the password game |
| anything else | "Unknown Command." |

Commands are case-sensitive.

## The game

Send `game` and try to guess the password. Wrong guesses play a low tone; the right one lights the LED and ends the game. Hint: it is related to the project name.

## Known limitations

- The password is hardcoded in the source, so this is a toy, not real security.
- The game loop blocks until the correct password is entered; the board must be reset to leave it.
- `delay()` is used for timing, so the board ignores input during sounds and animations.


```


