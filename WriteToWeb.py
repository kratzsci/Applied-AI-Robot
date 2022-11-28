from selenium import webdriver
import webbrowser

driver = webdriver.Chrome()
driver.get("http://192.168.4.1/")
button = driver.find_element("id","DRIVE")
button.click()