function [detectedImg] = FindStopSign(detector, videoFrame )


% Detect a stop sign.
bbox = step(detector,videoFrame); 
%%
% Insert bounding box rectangles and return the marked image.
 detectedImg = insertObjectAnnotation(videoFrame,'rectangle',bbox,'stop sign');
%%
% Display the detected stop sign.
% figure; imshow(detectedImg);

end

