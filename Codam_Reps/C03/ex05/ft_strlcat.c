/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/29 13:37:23 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	size -= 2;
	i = 0;
	j = 0;
	
	while (dest[j] != '\0')
		j++;
	if(!(j > size))
		size = j;
	while (src[i] != '\0' && (i + j) <= size)
	{
		dest[j + i] = src[i];
		i++;
	}
	while (src[i] != '\0')
		i++;
	size += i + 2;
	return (size);
}
//concatenates s2 (until n chars)onto s1 when s1 hits '\0' a
/*
	n		0	1	3	4				
	i		0	1	2	3	3	4	5	6
	j						0	1	2	3
	dest	h	o	i	d	a	g	\0
	src						d	a	g	\0
	appends most size - strlen(dst) - 1. off source. 
	
	nul terminate unles size  = 0 or strlen(dst) is bigger than size

	given size argument must always be bigger than dest[size]
*/
int main(void)
{
char desti[12] = "aass";
char desti2[12] = "aass";
char srcs[] = "test";
// int i = 9;
unsigned int copychars = 2;
unsigned int totallenght = ft_strlcat(desti, srcs, copychars);
printf("ft_strlcat; (len=%u)\n", totallenght);
printf("%s\n", desti);
unsigned int totallenght2 = strlcat(desti2, srcs, copychars);
printf("strlcat; (len=%u)\n", totallenght2);
printf("%s\n", desti2);
}
// int	ft_strlen(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }