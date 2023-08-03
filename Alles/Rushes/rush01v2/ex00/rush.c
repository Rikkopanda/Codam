/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydidenko <ydidenko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 15:11:33 by ydidenko      #+#    #+#                 */
/*   Updated: 2023/07/23 13:51:55 by ydidenko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int		**fill(int **params, int **square, int x, int y);
void	print(int **numbers);

int	**zero_fill(int **square)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		square[j] = malloc(sizeof(int) * 4);
		while (i < 4)
		{
			square[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
	return (square);
}

void	rush(int **params)
{
	int	**square;

	square = malloc(sizeof(int *) * 4);
	square = zero_fill(square);
	if (fill(params, square, 0, 0))
		print(square);
	else
		write(1, "No solution found\n", 19);
}
