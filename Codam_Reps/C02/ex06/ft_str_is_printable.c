/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/26 14:16:22 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	contains_other;

	i = 0;
	contains_other = 0; 
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
			contains_other++;
		i++;
	}
	if ((str == 0) || contains_other == 0)
		return (1);
	else
		return (0);
}
//returns 1 when only printable characters
/*
int main(void)
{
char a[] = "HaLLO	";;

printf("%d",ft_str_is_printable(a));
}*/