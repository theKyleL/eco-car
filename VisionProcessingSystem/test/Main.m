function Main
    
    takePicture = 0;
    fileNameOfPic = 'picture.jpeg';
    
    findFace = 0;
    findStopSign = 0;
    
    maskAnImage = 1;
    



    % Create the webcam object.
    cam = webcam();

    % Capture one frame to get its size.
    videoFrame = snapshot(cam);
    frameSize = size(videoFrame);
    
    % Create the video player object.
    videoPlayer = vision.VideoPlayer('Position', [100 100 [frameSize(2), frameSize(1)]+30]);

    if (findStopSign)
        stopSignDetector = FindStopSignSetUp();
    end
    
    
    runLoop = 0;
    
    
    videoFrame = snapshot(cam);
    %houghTest(stopSignMask3(videoFrame));
    houghTest2(stopSignMask3(videoFrame));

    while(runLoop)
        videoFrame = snapshot(cam);

        %Give the videoFrame to other functions for image processing.
        if (takePicture)
            imwrite(videoFrame, fileNameOfPic)
        end
        
        if (findFace)
            videoFrame = FindFace(videoFrame);
        end
        if (findStopSign)
            videoFrame = FindStopSign(stopSignDetector, videoFrame);
        end
        
        if (maskAnImage)
            videoFrame = stopSignMask3(videoFrame);
        end
        
        


        % Display frame from web cam
        step(videoPlayer, videoFrame)

        runLoop = isOpen(videoPlayer);
        
        pause(0.1)
    end


end

