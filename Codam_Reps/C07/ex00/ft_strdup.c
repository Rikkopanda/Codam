/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:41:22 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/28 10:56:22 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	int	i;
	char *dest;
	int size;

	size = ft_strlen(src);
	dest = (char *)malloc(size);
	if(dest == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(void)
{
char srcstring[] = "hoi";
char *desti;

desti = ft_strdup(srcstring);
printf("%s", desti);
}
//free(desti) happens at the end of program silently

int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}