/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/26 13:51:47 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	contains_other;

	i = 0;
	contains_other = 0; 
	while (str[i] != '\0')
	{
		if (!(str[i] >= 65 && str[i] <= 90))
			contains_other++;
		i++;
	}
	if ((str == 0) || contains_other == 0)
		return (1);
	else
		return (0);
}
/*
int main(void)
{
char a[] = "HaLLO";;

printf("%d",ft_str_is_uppercase(a));
}*/