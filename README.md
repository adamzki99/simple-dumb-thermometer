# Simple dumb thermometer
This project is a solution for a dumb problem...

If you are a poor student, you might find yourself in a situation where you don't have any money. But! You might have an old Arduino, an OLED screen, and a DHT11/22. Then you can clone this repo and build yourself a thermo-hygrometer to figure out if you are cold because the temperature in your living quarters is too low, or if your diet is solely comprised of nuddles and Monster Energy &trade; drinks might not be good enough.

## Development container

The dev. container is based on the [platformio-vscode-devcontainer](https://github.com/prenone/platformio-vscode-devcontainer/tree/master) project made by pernone

### Prerequisites

On Linux (the correct operating system), you need to follow these [instuctions](https://docs.platformio.org/en/latest/core/installation/udev-rules.html) to allow get access so you can flash the device.

**Note:** The instructions should be performed on the host machine, not in the container.

### Instructions

*These instructions are copied from the original repository*

After following these steps the contents of the `.devcontainer` folder in your project can be adapted to meet your needs.

1. Finally open the **Command Palette** and run **Remote-Containers: Reopen Folder in Container** to start using the definition.

**Notes:** This container runs in `--privileged` mode.

## Todo

- [x] Print the temperature and humidity to serial.
- [x] Print the values to the display.
- [ ] Implement a "DVD logo bounce"-animation to avoid OLED burn in.
- [ ] Port to ESP32 to be able to view the value on a website
- [ ] Change sensors to someting more reliable, maybe a [100K 3950 GLASS Thermistor](https://www.trianglelab.net/products/100k-3950-glass-thermistor)