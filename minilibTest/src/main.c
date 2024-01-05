/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rik <rik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by you-              #+#    #+#             */
/*   Updated: 2024/01/01 19:46:14 by rik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include "utils.h"
#include "game.h"

int stop_serv = 0;

void sig_handler() {
	stop_serv = 42;
	ft_putendl_fd("Signal recieved, for now... exit without free\n", 2);
	exit(1);
}

int putpixel(int r, int g, int b, int a)
{
	int ret_int;

	ret_int = (r << 24 | g << 16 | b << 8 | a);
	return (ret_int);
}

void new_resize_img(t_img original_img, double scale);

void init_ptrs1(ptrs	*ptrs, t_img *img_backgr, t_img *img_monkey, t_img *img_base)
{
	(*ptrs).img_backgr = img_backgr;
	(*ptrs).img_ptr = img_monkey;
	(*ptrs).img_base = img_base;
}

void init_ptrs2(ptrs	*ptrs, void *win_ptr, void *mlx_ptr)
{
	(*ptrs).win_ptr = win_ptr;
	(*ptrs).mlx_ptr = mlx_ptr;
}

void init_pos(ptrs	*ptrs, int pos_x, int pos_y)
{
	(*ptrs).x_pos_block = pos_x;
	(*ptrs).y_pos_block = pos_y;
}

void destroys_and_free(ptrs *ptrs)
{
	mlx_destroy_image((*ptrs).mlx_ptr, (*ptrs).img_ptr->img_ptr);
	mlx_destroy_image((*ptrs).mlx_ptr, (*ptrs).img_base->img_ptr);
	mlx_destroy_image((*ptrs).mlx_ptr, (*ptrs).img_backgr->img_ptr);
	mlx_destroy_display((*ptrs).mlx_ptr);
	free((*ptrs).mlx_ptr);
}

int main(void)
{
 	t_win	mlx;
	t_img	base_image;
	t_img	img_bg;
	t_img	img_monkey;
	ptrs	ptrs;

	init_pos(&ptrs, 50, 50);
	init_ptrs1(&ptrs, &img_bg, &img_monkey, &base_image);
	signal(SIGINT, sig_handler);
	mlx = new_window(1000, 650, "transparency test");
	if (!mlx.win_ptr)
		return (2);
	init_ptrs2(&ptrs, mlx.win_ptr, mlx.mlx_ptr);
	base_image = new_img(1000, 650, mlx);
	{
		img_bg = new_file_img("sky3.xpm", mlx);
		if (!img_bg.img_ptr)
			return (2);
		put_img_to_img(base_image, img_bg, 0, 0);
	}
	{
		img_monkey = new_file_img("monkey01.xpm", mlx);
		if (!img_monkey.img_ptr)
			return (2);
		put_img_to_img(base_image, img_monkey, ptrs.x_pos_block, ptrs.y_pos_block);
	}
	mlx_put_image_to_window(base_image.win.mlx_ptr, base_image.win.win_ptr, base_image.img_ptr, 0, 0);
	mlx_hook(base_image.win.win_ptr, 2, 1L<<0, key_pressed, &ptrs);
	mlx_loop(mlx.mlx_ptr);
	destroys_and_free(&ptrs);
	return (0);
}
