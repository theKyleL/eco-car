img = imread('transformed.png');

img1 = createMask_RGBTOPDOWNLINES(img);

BW1 = edge(img1,'Prewitt');


imshow(img)
imshow(img1)
imshow(BW1)
