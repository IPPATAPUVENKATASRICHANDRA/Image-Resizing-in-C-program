#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image/stb_image_resize.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main() {
int width, height, original_no_of_channels;
unsigned char *img = stbi_load("walk.jpg", &width, &height, &original_no_of_channels, 0);
if(img == NULL) {
printf("Error in loading the image\n");
exit(1);
}
printf("Loaded image with a width of %dpx, a height of %dpx and %d original_no_of_channels\n", width, height, original_no_of_channels);
float scalefactor;
printf("Enter the scale factor: ");
scanf("%f",&scalefactor);
int new_width = width  * scalefactor;
int new_height = height *scalefactor;
unsigned char *resized_img = malloc(new_width * new_height *original_no_of_channels);

stbir_resize_uint8(img, width, height, 0, resized_img, new_width, new_height, 0, original_no_of_channels);

stbi_write_png("walk_resized1.png", new_width, new_height, original_no_of_channels, resized_img, new_width * original_no_of_channels);
stbi_write_jpg("walk_resized1.jpg", new_width, new_height, original_no_of_channels, resized_img, 100);
printf("Output image with a width of %dpx, a height of %dpx",new_width,new_height);
stbi_image_free(img);
free(resized_img);
return 0;
}

