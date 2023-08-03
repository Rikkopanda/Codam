/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:12:58 by ydidenko          #+#    #+#             */
/*   Updated: 2023/07/25 09:49:31 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void	rush(int **params);

int	*get_params(char *arr, int start)
{
	int		i;
	int		param_i;
	int	*param;

	param = malloc(sizeof(int) * 4);
	i = start * 2;
	param_i = 0;
	while (param_i < 4)
	{
		if (arr[i] >= '1' && arr[i] <= '4')
		{
			param[param_i] = arr[i] - '0';
			param_i++;
		}
		i++;
	}
	return (param);
}

void	finish(int **params)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(params[i]);
		i++;
	}
	free(params);
}

int	is_valid(char *arr)
{
	int	i;
	int	num;
	int	space;

	i = 0;
	num = 0;
	space = 0;
	while (arr[i])
	{
		if (arr[i] >= '1' && arr[i] <= '4')
			num++;
		else if (arr[i] == ' ')
			space++;
		else
			return (0);
		i++;
	}
	if (num == 16 && space == 15)
		return (1);
	return (0);
}

int	*allocate_and_get_params(char *arr, int start)
{
	int	*param;

	param = malloc(sizeof(int) * 4);
	param = get_params(arr, param, start);
	return (param);
}

int	main(int argc, char **argv)
{
	int	**params;

	if (argc != 2 || !argv[1] || !is_valid(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	params = malloc(sizeof(int *) * 4);
	params[0] = allocate_and_get_params(argv[1], 0);
	params[1] = allocate_and_get_params(argv[1], 4);
	params[2] = allocate_and_get_params(argv[1], 8);
	params[3] = allocate_and_get_params(argv[1], 12);
	rush(params);
	finish(params);
}
