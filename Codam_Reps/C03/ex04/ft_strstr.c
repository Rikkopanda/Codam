/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/29 13:37:03 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && to_find[j] != '\0')
			{
				j++;
			}
		}
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
when needle and hay char is ==, start = 1
start = 1 when ==
start = 0 when !=
first time all characters match, return	
	i		0	1	2	3	4	5	6	7	8	9
	j							0	1	2	3	4
	start						1	1	
	elke enra tot \0
	niet match punt				0	0	1	2				
	hay		c	h	e	c	k	p	o	i	n	t
	needle						P	o	n	t	
// */
int main(void)
{
	char haystack[20] = "TutorialsPPoint";
	char needle[] = "Point";
	char *ret;

	ret = strstr(haystack, needle);
	printf("The substring is: %s\n", ret);
	ret = ft_strstr(haystack, needle);
	printf("The substring is: %s\n", ret);
}
