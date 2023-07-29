/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/26 16:08:50 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
// size to index -> 7 = 7(0123456) [6] = 7th
//			0	1	2	3
// i 		0	1	2	3	4
// SRC		a	b	c	
// dest		
// int main(void)
// {
// int size;
// size = 1;
// int i;

// i = 0;
// char src[] = "abc";
// while(src[i] != '\0')
// {
// 	i++;
// 	size++;
// }
// char dest[size];
// printf("%ld, %s\n", strlcpy(dest, src, size), dest);
// printf("%d, %s\n", ft_strlcpy(dest, src, size), dest);
// }