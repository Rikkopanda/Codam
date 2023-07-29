/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:24:20 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/27 10:11:48 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
// int main(void)
// {
// int sizedestindex;
// char src[] = "bb";
// char dest[] = "aaaaa";

// sizedestindex = (sizeof(dest) / sizeof(dest[0])) - 0;
// //strncpy(dest, src, sizedestindex);

// ft_strncpy(dest, src, sizedestindex);
// printf ("%s", dest);
// }
