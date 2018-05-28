function [centers, radii, foundCircles] = FindCircle(frameBW)

    
    [centers, radii] = imfindcircles(frameBW,[15 30]);
    
    if (size(centers) > 0)
        foundCircles = 1;
    else
        foundCircles = 0;
    end
    
end

