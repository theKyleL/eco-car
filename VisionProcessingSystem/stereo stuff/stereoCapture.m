function stereoCapture()


cam1 = webcam(2);
cam2 = webcam(3);

videoFrame1 = snapshot(cam1);
videoFrame2 = snapshot(cam2);

 imwrite(videoFrame1, 'cam1.png');
 imwrite(videoFrame2, 'cam2.png');
end

