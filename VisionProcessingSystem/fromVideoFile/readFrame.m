function readFrame()

    % Create the webcam object.
   % cam = webcam();
    v = VideoReader('C:\Users\Austin Musser\Videos\Stereo Capture\stop signs 3\Camera_1_capture.avi');

    % Capture one frame to get its size.
    videoFrame = read(v,1);
    frameSize = size(videoFrame);
    
    % Create the video player object.
    videoPlayer = vision.VideoPlayer('Position', [10 100 [frameSize(2), frameSize(1)]+30]);
    videoPlayer2 = vision.VideoPlayer('Position', [650 100 [frameSize(2), frameSize(1)]+30]);
    videoPlayer3 = vision.VideoPlayer('Position', [1300 100 [frameSize(2), frameSize(1)]+30]);

    
    runLoop = 1;
    frameCount = 550;
    findCircleCount = 0;
    foundCircles = 0;
    while(runLoop)
        frameCount = frameCount +1;
        findCircleCount = findCircleCount + 1;
        videoFrame = read(v,frameCount);

        %imwrite(videoFrame, 'DNESign.png');

        videoFrameMasked = redHSVmask1(videoFrame);
        videoFrameMasked2 = testMask(videoFrame);

        if (findCircleCount > 2)
            [centers, radii, foundCircles] = FindCircle(videoFrameMasked2);
            findCircleCount = 0;
        end

        if (foundCircles == 1)
            for i = 1:(size(centers))
                percentRed = findPercentWhite(videoFrameMasked, centers(i,:), radii(i));
                if percentRed > 57.00000
                    videoFrame = insertShape(videoFrame,'circle',[centers(i,1) centers(i,2) radii(i)],'LineWidth',5,'Color', 'green');
                end
            end
        end
        
       % houghTest2(videoFrame);

        step(videoPlayer, videoFrame)
        step(videoPlayer2, videoFrameMasked)
        step(videoPlayer3, videoFrameMasked2)
       

        runLoop = isOpen(videoPlayer);
        
        pause(0.01)
        close all
    end

end

