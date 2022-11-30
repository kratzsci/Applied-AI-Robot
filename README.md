# Applied-AI-Robot                                                             

Self-driving robot with AI controls

File sturcture:
motors.py - manages the motors for movement of the robot

# L298N motor controller

| Input1  | Input2  | Spinning Direction |
| ------- | ------- | ------------------ |
| Low(0)	| Low(0)	| Motor OFF          |
| High(1) |	Low(0)  | Forward            |
| Low(0)  |	High(1) | Backward           |
| High(1) |	High(1) | Motor OFF          |

# Parts List
- Raspberry Pi Pico RP2040
- ESP32 Development board
- Teensy 4.0
- NRF24L01 RF Transceiver
- TT Motor 200RPM
- L298N Motor Driver

# Controls
A -> Stop
B -> Forward
C -> Backward
Y -> Right
L -> Left

# Trainer
https://teachablemachine.withgoogle.com/train/image

# Possible implementation on Pi
https://stackoverflow.com/questions/55585515/how-to-load-keras-model-onto-raspberry-pi

# References
RF library and code:
https://github.com/BLavery/lib_nrf24
