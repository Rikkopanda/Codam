/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydidenko <ydidenko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 15:34:20 by ydidenko      #+#    #+#                 */
/*   Updated: 2023/07/22 22:40:24 by ydidenko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	validate_col(int validation, int **numbers, int col_i, int direction)
{
	int	i;
	int	max_num;
	int	sky_num;

	max_num = 0;
	sky_num = 0;
	if (direction == 0)
	{
		i = 0;
		while (i < 4)
		{
			if (numbers[i][col_i] > max_num)
			{
				max_num = numbers[i][col_i];
				sky_num++;
			}
			i++;
		}
	}
	else
	{
		i = 3;
		while (i >= 0)
		{
			if (numbers[i][col_i] > max_num)
			{
				max_num = numbers[i][col_i];
				sky_num++;
			}
			i--;
		}
	}
	return (sky_num == validation);
}


int	validate_row(int validation, int **numbers, int row_i, int direction)
{
	int	i;
	int	max_num;
	int	sky_num;

	max_num = 0;
	sky_num = 0;
	if (direction == 0)
	{
		i = 0;
		while (i < 4)
		{
			if (numbers[row_i][i] > max_num)
			{
				max_num = numbers[row_i][i];
				sky_num++;
			}
			i++;
		}
	}
	else
	{
		i = 3;
		while (i >= 0)
		{
			if (numbers[row_i][i] > max_num)
			{
				max_num = numbers[row_i][i];
				sky_num++;
			}
			i--;
		}
	}
	return (sky_num == validation);
}


int	validate(int **params, int **numbers)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (y < 2)
			{
				if (!validate_col(params[y][x], numbers, x, y % 2))
					return (0);
			}
			else
			{
				if (!validate_row(params[y][x], numbers, x, y % 2))
					return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
