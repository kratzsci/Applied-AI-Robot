from machine import Pin
import time

#OUT1  and OUT2
LeftMotor1=Pin(6,Pin.OUT) 
LeftMotor2=Pin(7,Pin.OUT)  
EN_A=Pin(8,Pin.OUT)



#OUT3  and OUT4
RightMotor1=Pin(2,Pin.OUT)  
RightMotor2=Pin(3,Pin.OUT)  
EN_B=Pin(4,Pin.OUT)

EN_A.high()
EN_B.high()

def move(direction):
    #STOP
    if(direction == 0):
        LeftMotor1.low()
        LeftMotor2.low()
        RightMotor1.low()
        RightMotor2.low()
    
    #Forward
    if(direction == 1):
        LeftMotor1.high()
        LeftMotor2.low()
        RightMotor1.high()
        RightMotor2.low()
        
    #Backward
    if(direction == 1):
        LeftMotor1.low()
        LeftMotor2.high()
        RightMotor1.low()
        RightMotor2.high()