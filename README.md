# Applied-AI-Robot
Self-driving robot with AI controls

File sturcture:
motors.py - manages the motors for movement of the robot

L298N motor controller

Input1	Input2	Spinning Direction
Low(0)	Low(0)	Motor OFF
High(1)	Low(0)	Forward
Low(0)	High(1)	Backward
High(1)	High(1)	Motor OFF