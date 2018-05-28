function [ outputFrame ] = FindFace( videoFrame )

    % Create a cascade detector object.
    faceDetector = vision.CascadeObjectDetector();

%     % Read a video frame and run the detector.
%     videoFileReader = vision.VideoFileReader('visionface.avi');
%     videoFrame      = step(videoFileReader);
    bbox            = step(faceDetector, videoFrame);

    % Draw the returned bounding box around the detected face.
    outputFrame = insertObjectAnnotation(videoFrame,'rectangle',bbox,'Face');
%     figure, imshow(videoOut), title('Detected face');


end

