import numpy as np
import cv2

cap1 = cv2.VideoCapture(-1)
cap2 = cv2.VideoCapture(-1)

while(True):
    # Capture frame-by-frame
    ret1, frame1 = cap1.read()
    ret2, frame2 = cap2.read()

    cv2.VideoWriter("camera1.avi", -1, 20, (640, 480),True)
    cv2.VideoWriter("camera2.avi", -1, 20, (640, 480),True)

    # Display the resulting frame
    cv2.imshow('frame1',frame1)
    cv2.imshow('frame2',frame2)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap1.release()
cap2.release()
cv2.destroyAllWindows()