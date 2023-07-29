/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:41:22 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/28 11:22:38 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);

int	*ft_range(int min, int max)
{
	int *range;
	int size;
	int i;
	///range = m
	
	size = max - min;
	range = (int *)malloc(sizeof(int) * size);
	printf("\n%d\n", size);
	i = 0;
	while(min < max)
	{
		range[i] = min;
		printf("%d ", range[i]);
		i++;
		min++;
	}
	printf("\n");
	return(range);
}

int main(void)
{
	int *bereik;

	bereik = ft_range(-20, 40);
	int i = 0;
	while(bereik[i] != '\0')
	{
		printf("%d ", bereik[i]);
		i++;
	}
}
