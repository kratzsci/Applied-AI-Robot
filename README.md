
  _____       _     _     _        _____       _           _   
 |  __ \     | |   | |   (_)      |  __ \     | |         | |  
 | |__) |___ | |__ | |__  _  ___  | |__) |___ | |__   ___ | |_ 
 |  _  // _ \| '_ \| '_ \| |/ _ \ |  _  // _ \| '_ \ / _ \| __|
 | | \ \ (_) | |_) | |_) | |  __/ | | \ \ (_) | |_) | (_) | |_ 
 |_|  \_\___/|_.__/|_.__/|_|\___| |_|  \_\___/|_.__/ \___/ \__|
                                                               
                                                               

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
