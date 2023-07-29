/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/26 14:20:08 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	contains_other;

	i = 0;
	contains_other = 0; 
	while (str[i] != '\0')
	{
		if (!(str[i] >= 97 && str[i] <= 122))
			contains_other++;
		i++;
	}
	if (str == 0 || contains_other == 0)
		return (1);
	else
		return (0);
}
// int main(void)
// {
// char a[] = "";

// printf("%d",ft_str_is_lowercase(a));
// }
