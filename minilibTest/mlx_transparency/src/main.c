/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by you-              #+#    #+#             */
/*   Updated: 2023/11/16 19:19:48 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include "../include/utils.h"

int stop_serv = 0;

void sig_handler() {
	stop_serv = 42;
	ft_putendl_fd("Signal recieved, for now... exit without free\n", 2);
	exit(1);
}

int main(void)
{
 	t_win	tutorial;
	t_img	base_image;
	t_img	bg;
	t_img	ring;

	signal(SIGINT, sig_handler);
	tutorial = new_window(1000, 650, "transparency");
	if (!tutorial.win_ptr)
		return (2);
	base_image = new_img(1000, 650, tutorial);

	{
		bg = new_file_img("sky3.xpm", tutorial);
		if (!bg.img_ptr)
			return (2);
		put_img_to_img(base_image, bg, 0, 0);
	}
	{
		ring = new_file_img("monkey01.xpm", tutorial);
		if (!ring.img_ptr)
			return (2);
		put_img_to_img(base_image, ring, 50, 100);
	}
	mlx_put_image_to_window (base_image.win.mlx_ptr, base_image.win.win_ptr, base_image.img_ptr, 0, 0);
	mlx_loop(tutorial.mlx_ptr);
	mlx_destroy_window(tutorial.mlx_ptr, tutorial.win_ptr);
	return (0);
}
