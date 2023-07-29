/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:15:17 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/17 08:52:51 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	temp;

	a = 0;
	while (a < --size)
	{
		temp = tab[a];
		tab[a++] = tab[size];
		tab[size] = temp;
	}
}
/*
int main(void)
{
int arr[] ={49,50,51,52};

ft_rev_int_tab(arr, 4);
printf("%d,%d,%d,%d,",arr[0],arr[1],arr[2],arr[3]);
}*/