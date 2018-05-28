import cv2
import os

# Only change the top two variables:
# Choose the amount of frame to play before caturing an image
CAPTURE_EVERY_X_FRAME = 100

cap1 = cv2.VideoCapture(-1)
#cap2 = cv2.VideoCapture(foldername + 'Camera_2_capture.avi')

while cap1.isOpened():# and cap2.isOpened()):
    # Capture frame-by-frame

    ret1, frame1 = cap1.read()
    #ret2, frame2 = cap2.read()

    print frame1.shape

    # Display the resulting frame
    cv2.imshow('frame1', frame1)
   #cv2.imshow('frame2', frame2)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap1.release()
#cap2.release()
cv2.destroyAllWindows()