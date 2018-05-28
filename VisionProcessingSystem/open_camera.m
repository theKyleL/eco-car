function [ output_args ] = open_camera( input_args )
%OPEN_CAMERA Summary of this function goes here
%   Detailed explanation goes here
%cvCapture = createCameraCapture(1) ;
cam = webcam();

while(1)
    imShow(getFrame(cvCapture)) 
end


end

