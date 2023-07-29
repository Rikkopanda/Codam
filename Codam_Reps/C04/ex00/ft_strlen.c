/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:07:39 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/29 11:23:20 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int main(void)
{
	int len;
	char str[] = "Hello";
	len = 48 + ft_strlen(str);
	write(1,&len,1);
}
