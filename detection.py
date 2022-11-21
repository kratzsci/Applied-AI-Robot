from keras.models import load_model
import cv2
import numpy as np

REV_CLASS_MAP = { 0: "A", 1: "B", 2: "C", 3: "D", 4: "E", 5: "F", 6: "G", 7: "H", 8: "I", 9: "J", 10: "K", 11: "L", 12: "M", 13: "N", 14: "O", 15: "P", 16: "Q", 17: "R", 18: "S", 19: "T", 20: "U", 21: "V", 22: "W", 23: "X", 24: "Y", 25: "Z", 26: "Nothing", 27: "Space", 28: "del"}
def mapper(val):
    return REV_CLASS_MAP[val]

model = load_model("C:/Users/User/Applied-AI/Project-1/Model/keras_model.h5")
cap = cv2.VideoCapture(0)

cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()
    if not ret:
        continue
    cv2.rectangle(frame, (10, 70), (300, 340), (0, 255, 0), 2)
    cv2.rectangle(frame, (330, 70), (630, 370), (255, 0, 0), 2)
    # extract the region of image within the user rectangle
    roi = frame[70:300, 10:340]
    img = cv2.cvtColor(roi, cv2.COLOR_BGR2RGB)
    img = cv2.resize(img, (224, 224)) # for pc
    # img = cv2.resize(img, (277, 277)) # for pi
    # predict the model
    pred = model.predict(np.array([img]))
    move_code = np.argmax(pred[0])
    user_move_name = mapper(move_code)
    print(user_move_name)