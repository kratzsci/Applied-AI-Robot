from selenium import webdriver
import webbrowser

driver = webdriver.Chrome()
driver.get("http://192.168.4.1/")


def Motors(direction):
    if(direction == 0):
        print("STOP")
        button = driver.find_element("id", "STOP")
    elif(direction == 1):
        print("FORWARD")
        button = driver.find_element("id", "DRIVE")
    elif(direction == 2):
        print("BACKWARD")
        button = driver.find_element("id", "BACK")
    elif(direction == 3):
        print("OTHER")
        button = driver.find_element("id", "OTHER")
    elif(direction == 4):
        print("RIGHT")
        button = driver.find_element("id", "RIGHT")
    elif(direction == 5):
        print("LEFT")
        button = driver.find_element("id", "LEFT")

    button.click()


while True:
    direction = int(input())
    Motors(direction)


# button = driver.find_element("id","DRIVE")
# button.click()
