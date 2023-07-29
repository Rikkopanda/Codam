/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:43:13 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/27 08:25:50 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}
//&dest == strcpy[0]
//*strcpy[0] == *dest
//*strcpy[1] == *src
// int main(void)
// {
// int size;
// size = 6;
// char srcstring[] = "";
// char dest[size];
// ft_strcpy(dest, srcstring);
// printf("%s, %d", dest, 6);
// }
// int main(void)
// {
// int size;
// size = 1;
// int i = 0;
// char srcstring[] = "Hallo";
// while(srcstring[i] != '\0')
// {
// i++;
// size++;
// }
// i = 0;
// char src[size];
// while(src[i] != '\0')
// {
// src[i] = srcstring[i];
// i++;
// }
// src[i] = '\0';
// char dest[size];
// ft_strcpy(dest, src);
// printf("%s, %d", dest, size);
// }
