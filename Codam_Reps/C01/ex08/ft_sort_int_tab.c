/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:15:17 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/27 09:22:57 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>

void	print_array(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf ("%d, ", tab[i]);
		i++;
	}
}*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	size;
	int	arr[] = {4, 1, 21, 12, 7, 2, 7, 12, 4, 10};
	
	size = sizeof(arr) / sizeof(arr[0]);
	ft_sort_int_tab(arr, size);
	//print_array(arr, size);
}
