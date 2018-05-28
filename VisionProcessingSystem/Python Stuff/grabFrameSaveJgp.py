import cv2
import os

# Only change the top two variables:
# Choose the amount of frame to play before caturing an image
#CAPTURE_EVERY_X_FRAME = 100

# Choose the folder that the video file is in
# (videos should be named 'Camera_<number>_capture.avi', and be inside this folder)
FOLDER = 'lanes_lights_6'
FILENAME = 'Camera_1_capture.avi'

#######################################################################################################################
#  Click lower case "c" to capture a screen shot as video plays, a printout will appear in the console if successful  #
#######################################################################################################################






#######################################################################################################################
# DO NOT MODIFY CODE BEYOND THIS LINE #
#######################################################################################################################
foldername = '\\' + FOLDER + '\\'

foldername = os.getcwd() + foldername

photo_dir = 'pictures_from_vid_' + FOLDER

cap1 = cv2.VideoCapture(foldername + FILENAME)
# cap2 = cv2.VideoCapture(foldername + 'Camera_2_capture.avi')

count = 0
file_num = 0

if not os.path.isdir(photo_dir):
    os.mkdir(photo_dir)

while(cap1.isOpened()): #and cap2.isOpened()):
    # Capture frame-by-frame

    ret1, frame1 = cap1.read()
    # ret2, frame2 = cap2.read()


    count += 1

    # if count is CAPTURE_EVERY_X_FRAME:

    if cv2.waitKey(10) & 0xFF == ord('c'):
        # save to a file
        cv2.imwrite(photo_dir + '\\' + FOLDER + '_' + 'camera_1-num_' + str(file_num) + '.jpg', frame1)
        # cv2.imwrite(photo_dir + '\\' + folder + '_' + 'camera_2-num_' + str(file_num) + '.jpg', frame2)
        print "Captured Screen Shot: " + str(file_num)
        file_num += 1
        count = 0
    try:
        # Display the resulting frame
        cv2.imshow('frame1', frame1)
        # cv2.imshow('frame2', frame2)
    except:
        break

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap1.release()
# cap2.release()
cv2.destroyAllWindows()