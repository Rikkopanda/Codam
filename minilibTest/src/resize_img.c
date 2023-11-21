
#include "game.h"

struct resize_data
{
	int new_h;
	int new_w;
	int	del_xth_pixel;
	int	del_yth_pixel;
	double scale;
};

void calc_params(t_img original_img, struct resize_data *params)
{
	int cnt_to_delete;

	params->new_h = original_img.h * params->scale;
	params->new_w = original_img.w * params->scale;
	printf("\nold %d, new %d\n", original_img.h, params->new_h);
	printf("old %d, new %d\n", original_img.w, params->new_w);

	
	cnt_to_delete = (original_img.w - params->new_w);
	params->del_xth_pixel = original_img.w / cnt_to_delete;

	cnt_to_delete = (original_img.h - params->new_h);
	params->del_yth_pixel = original_img.h / cnt_to_delete;
	printf("every xth %d, every yth %d\n", params->del_xth_pixel, params->del_yth_pixel);
}

void new_resize_img(t_img original_img, double scale)
{
	struct resize_data params;

	params.scale = scale;
	calc_params(original_img, &params);
	printf(" * %d\n", *(original_img.addr + 1));
	unsigned int *dst;
	unsigned int *src;
	for(int j = 0; j < original_img.h; j++)
	{
		for(int i = 0; i * (params.del_xth_pixel) < original_img.w; i++)
		{
			if(i >= 1)
			{
				for(int shift_i = 0; (i * params.del_xth_pixel) + (shift_i) < original_img.w; shift_i++)
				{
					dst = (unsigned int *)(original_img.addr + (original_img.line_len * j) + (params.del_xth_pixel * 4 * i) + (shift_i * 4));
					src = (unsigned int *)(original_img.addr + (original_img.line_len * j) + (params.del_xth_pixel * 4 * i) + (shift_i * 4) + 4);
					*dst = *src;
				}
			}
		}
	}
	for(int j = 0; j < original_img.h; j++)
	{
		unsigned int *start_pos;
		if(j % params.del_yth_pixel == 0)
		{
			start_pos = (unsigned int *)(original_img.addr + (original_img.line_len * j));
			for(int shift_i = 0; shift_i < original_img.w; shift_i++)
			{
				for(int shift_j = 0; (j + shift_j) < params.new_h; shift_j++)
				{
					dst = (unsigned int *)start_pos + (shift_i) + (shift_j * original_img.line_len);
					src = (unsigned int *)start_pos + (shift_i) + (shift_j * original_img.line_len) + original_img.line_len;
					*dst = *src;
				}
			}
		}
	}
}