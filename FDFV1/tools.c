
#include "fdf.h"


void clear_img(mlx_image_t *img, int width, int height)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			mlx_put_pixel(img, j, i, (int)black);
			j++;
		}
	i++;
	j = 0;
	}
}

void init_rgbs(point *A)
{
	A->r = (A->color >> 24) & 255;
	A->g = (A->color >> 16) & 255;
	A->b = (A->color >> 8) & 255;
	printf("color: %u. RGB = %d, %d, %d\n", A->color, A->r, A->g, A->b);
}


int32_t ft_pixel_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}