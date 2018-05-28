function [ percentWhite ] = findPercentWhite(frame, center, radious)
    center = round(center,0);
    radious = round(radious,0);

    white = 0;
    for i = (center(1)-radious):(center(1)+radious)
        for j = (center(2)-radious):(center(2)+radious)

            if i < 1
                col = 1;
%             elseif i > size(frame(1))
%                 col = size(frame(1))
            else
                col = i;
            end

            if j < 1
                row = 1;
%             elseif j > size(frame(2))
%                 row = size(frame(2))
            else
                row = j;
            end

            if (frame(row,col) == 1)
                white = white + 1;
            end
        end
    end


    percentWhite = 100 * (white / (2*radious)^2);

end

