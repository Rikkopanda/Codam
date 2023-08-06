/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydidenko <ydidenko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 15:46:01 by ydidenko      #+#    #+#                 */
/*   Updated: 2023/07/23 13:48:06 by ydidenko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int **numbers)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		write(1, " ", 1);
		while (j < 4)
		{
			c = numbers[i][j] + '0';
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
