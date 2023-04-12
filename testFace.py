import cv2
import numpy as np
import mysql.connector
from mysql.connector import Error

# Load the cascade
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Connect to the database
try:
    conn = mysql.connector.connect(host='localhost',
                                   database='FaceReg',
                                   user='root',
                                   password='')
    if conn.is_connected():
        print('Connected to MySQL database')

except Error as e:
    print(e)

# Define a function to insert faceprints into the database


def insert_faceprint(name, faceprint):
    try:
        cursor = conn.cursor()
        query = "INSERT INTO Users (name, faceprint) VALUES (%s, %s)"
        cursor.execute(query, (name, faceprint))
        conn.commit()
        print("Faceprint for " + name + " added to database")

    except Error as e:
        print(e)

# Define a function to recognize faces


def recognize_faces(frame):
    if frame is None or frame.empty():
        print("Error: Empty frame")
        return

    # Convert the frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detect faces in the grayscale image
    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.cv.CV_HAAR_SCALE_IMAGE
    )

    # Iterate over each detected face
    for (x, y, w, h) in faces:
        # Extract the face ROI
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = frame[y:y+h, x:x+w]

        # Perform face recognition on the ROI
        label, confidence = face_recognizer.predict(roi_gray)

        # Draw a rectangle around the face
        color = (0, 255, 0)
        if confidence > 70:
            label = "unknown"
            color = (0, 0, 255)
        cv2.rectangle(frame, (x, y), (x+w, y+h), color, 2)

        # Add the predicted label and confidence to the image
        cv2.putText(frame, label, (x, y-10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.75, color, 2)

    # Display the resulting frame
    cv2.imshow('Video', frame)

cv2.destroyAllWindows()
