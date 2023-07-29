/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:41:22 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/29 12:07:37 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);

int ft_ultimate_range(int **range, int min, int max)//recieve address of pointer to pointer
{
	int size;
	int i;

	size = max - min;
	*range = malloc(sizeof(int) * size);// returns addrres to newly made memo space
	if(range == NULL)
		return (0);
	printf("\n%d\n", size);
	
	i = 0;
	while(i < size)
	{
		range[0][i] = min;//deref range[0](int *) first, deref then [i](int) of that
		printf("%d ", range[0][i]);
		i++;
		min++;
	}
	printf("\n");
	return(size);
}

int main(void)
{
	int *bereik;
	
	int size;
	int i;

	i = 0;
	size = ft_ultimate_range(&bereik, -20, 40);
	// while(i < size)
	// {
	// 	printf("%d ", bereik[i]);
	// 	i++;
	// }
}
