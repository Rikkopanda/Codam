/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:34:23 by ydidenko          #+#    #+#             */
/*   Updated: 2023/07/23 22:03:14 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validate(int **params, int **numbers);

int	check_row(int **square, int row, int num)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (square[row][j] == num)
			return (1);
		j++;
	}
	return (0);
}

int	check_col(int **square, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (square[i][col] == num)
			return (1);
		i++;
	}
	return (0);
}

int	fill(int **params, int **square, int row, int col)
{
	int	num;
	int	new_row;
	int	new_col;

	num = 1;
	if (row == 4)
	{
		return (validate(params, square));// if good return 1
	}
	while (num <= 4)
	{
		if (!check_row(square, row, num) && !check_col(square, col, num))
		{
			square[row][col] = num;
			new_row = row;
			new_col = col;
			if (col == 3)
			{
				new_row++;
				new_col = 0;
			}
			else
				new_col++;
			if (fill(params, square, new_row, new_col))
				return (1);
			else
				square[row][col] = 0;
		}
		num++;
	}
	return (0);// if(fill(.......) not good . previous fill func make value[][] = 0
}
